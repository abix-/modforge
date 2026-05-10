//! HTTP listener that dispatches POSTs at a single endpoint to a
//! caller-supplied handler. Synchronous (`tiny_http`), one worker
//! thread, no async runtime.
//!
//! The handler is opaque: it receives the raw request body string and
//! returns the JSON bytes to ship back. This keeps `ueforge` neutral
//! about snapshot type, op set, and error shape — all of which live
//! in the embedding crate.

use std::io::Cursor;
use std::sync::Arc;
use std::thread;

use parking_lot::Mutex;
use tiny_http::{Header, Method, Response, Server};

/// Configuration for the embedded server.
pub struct Config {
    /// Bind address suffix; the server binds `127.0.0.1:<port>`.
    pub port: u16,
    /// URL path that accepts POSTs. Anything else returns 404.
    pub endpoint: &'static str,
    /// Name applied to the listener thread (visible in tools / logs).
    pub thread_name: &'static str,
}

/// Handle to a spawned listener. Drop or call [`stop`](Self::stop)
/// to break the listener's `incoming_requests` loop and join the
/// thread. Required for hot-reload-safe shutdown -- the DLL can't
/// unload while the listener thread holds code on its stack.
pub struct SpawnHandle {
    server: Arc<Server>,
    join: Mutex<Option<thread::JoinHandle<()>>>,
}

impl SpawnHandle {
    /// Unblock the listener loop and join the thread. Idempotent.
    pub fn stop(&self) {
        // unblock() makes server.incoming_requests() return None
        // on its next iteration, breaking the for-loop in run().
        self.server.unblock();
        if let Some(j) = self.join.lock().take() {
            let _ = j.join();
        }
    }
}

impl Drop for SpawnHandle {
    fn drop(&mut self) {
        self.stop();
    }
}

/// Global registry of `SpawnHandle`s so `shutdown_all` can stop
/// listeners owned by call sites that don't hang on to the handle
/// (typical for `debug::spawn` callers that fire-and-forget).
static SERVER_REGISTRY: Mutex<Vec<SpawnHandle>> = Mutex::new(Vec::new());

/// Stop every server registered via [`spawn`]. Called from the
/// framework's hot-reload shutdown path.
pub fn shutdown_all() {
    let mut g = SERVER_REGISTRY.lock();
    let n = g.len();
    g.clear();
    drop(g);
    if n > 0 {
        crate::log!("server: shutdown_all stopped {n} listener(s)");
    }
}

/// Spawn the listener thread. Returns immediately. If bind fails the
/// error is reported via `on_log` and the thread is not started.
/// On success the handle is registered into the framework's
/// shutdown registry; pass `register: false` to opt out (e.g. tests
/// that own the handle directly).
pub fn spawn<H, L>(cfg: Config, handler: H, on_log: L)
where
    H: Fn(&str) -> Vec<u8> + Send + Sync + 'static,
    L: Fn(&str) + Send + 'static,
{
    let addr = format!("127.0.0.1:{}", cfg.port);
    let server = match Server::http(&addr) {
        Ok(s) => Arc::new(s),
        Err(e) => {
            on_log(&format!("ueforge: bind {addr} failed: {e}"));
            return;
        }
    };
    on_log(&format!("ueforge: listening on {addr}{}", cfg.endpoint));

    let handler = Arc::new(handler);
    let server_for_thread = server.clone();
    let join = thread::Builder::new()
        .name(cfg.thread_name.into())
        .spawn(move || run(server_for_thread, cfg.endpoint, handler))
        .expect("spawn listener thread");

    SERVER_REGISTRY.lock().push(SpawnHandle {
        server,
        join: Mutex::new(Some(join)),
    });
}

fn run<H>(server: Arc<Server>, endpoint: &'static str, handler: Arc<H>)
where
    H: Fn(&str) -> Vec<u8> + Send + Sync + 'static,
{
    for mut req in server.incoming_requests() {
        let url = req.url().to_string();
        let method = req.method().clone();

        if method != Method::Post || url != endpoint {
            let _ = req.respond(Response::from_string("not found").with_status_code(404));
            continue;
        }

        let mut body = String::new();
        if std::io::Read::read_to_string(req.as_reader(), &mut body).is_err() {
            let _ = req.respond(Response::from_string("bad body").with_status_code(400));
            continue;
        }

        let payload = handler(&body);
        let len = payload.len();
        let resp = Response::new(
            200.into(),
            vec![
                Header::from_bytes(&b"content-type"[..], &b"application/json"[..])
                    .expect("static header parse"),
            ],
            Cursor::new(payload),
            Some(len),
            None,
        );
        let _ = req.respond(resp);
    }
}
