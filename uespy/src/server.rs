//! HTTP listener that dispatches POSTs at a single endpoint to a
//! caller-supplied handler. Synchronous (`tiny_http`), one worker
//! thread, no async runtime.
//!
//! The handler is opaque: it receives the raw request body string and
//! returns the JSON bytes to ship back. This keeps `uespy` neutral
//! about snapshot type, op set, and error shape — all of which live
//! in the embedding crate.

use std::io::Cursor;
use std::sync::Arc;
use std::thread;

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

/// Spawn the listener thread. Returns immediately. If bind fails the
/// error is reported via `on_log` and the thread is not started.
pub fn spawn<H, L>(cfg: Config, handler: H, on_log: L)
where
    H: Fn(&str) -> Vec<u8> + Send + Sync + 'static,
    L: Fn(&str) + Send + 'static,
{
    let addr = format!("127.0.0.1:{}", cfg.port);
    let server = match Server::http(&addr) {
        Ok(s) => Arc::new(s),
        Err(e) => {
            on_log(&format!("uespy: bind {addr} failed: {e}"));
            return;
        }
    };
    on_log(&format!("uespy: listening on {addr}{}", cfg.endpoint));

    let handler = Arc::new(handler);
    let _ = thread::Builder::new()
        .name(cfg.thread_name.into())
        .spawn(move || run(server, cfg.endpoint, handler));
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
