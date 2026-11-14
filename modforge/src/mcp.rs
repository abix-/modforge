//! A Model Context Protocol server over the op registry, so an agent such
//! as Claude Code calls a running game's ops as its own tools. Two tools,
//! the ones jbot's MCP server (rmcp) gives over its registry: `ops` lists
//! every op, `op` runs one by name with its JSON arguments.
//!
//! Streamable HTTP, stateless (MCP 2025-06-18 "Streamable HTTP"): every
//! POST is one JSON-RPC message, answered with one JSON body, and a
//! notification with 202 and no body. No session is kept, so a client
//! keeps working across a restart of the game, as jbot's does.
//! Synchronous over [`crate::server::spawn`], its own listener thread, no
//! async runtime. Connect with
//! `claude mcp add --transport http <name> http://127.0.0.1:<port>/mcp`.

use serde_json::{Value as Json, json};

use crate::ops::OP_REGISTRY;

/// Serve the op registry as MCP tools on `127.0.0.1:<port>/mcp`. `name`
/// is the server's name the client shows.
pub fn serve<L>(port: u16, name: &'static str, thread_name: &'static str, on_log: L)
where
    L: Fn(&str) + Send + 'static,
{
    crate::server::spawn(
        crate::server::Config { port, endpoint: "/mcp", thread_name, auth_token: None },
        move |body| answer(body, name),
        on_log,
    );
}

/// The answer to one POSTed JSON-RPC message: its response's bytes, or no
/// bytes for a notification (the listener answers 202).
pub fn answer(body: &str, name: &str) -> Vec<u8> {
    let message: Json = match serde_json::from_str(body) {
        Ok(m) => m,
        Err(e) => return reply(&Json::Null, Err((-32700, format!("parse error: {e}")))),
    };
    // A notification (no id) is not answered.
    let Some(id) = message.get("id").cloned() else {
        return Vec::new();
    };
    let params = message.get("params").cloned().unwrap_or(Json::Null);
    let result = match message.get("method").and_then(Json::as_str).unwrap_or_default() {
        "initialize" => Ok(json!({
            "protocolVersion": params.get("protocolVersion").cloned().unwrap_or(json!("2025-06-18")),
            "capabilities": {"tools": {}},
            "serverInfo": {"name": name, "version": env!("CARGO_PKG_VERSION")},
            "instructions": "ops lists every op the game has registered with its arguments and what it does; op runs one by name with its arguments as a JSON object.",
        })),
        "ping" => Ok(json!({})),
        "tools/list" => Ok(json!({"tools": tools()})),
        "tools/call" => Ok(call(&params)),
        other => Err((-32601, format!("no method {other}"))),
    };
    reply(&id, result)
}

/// The two tools and their arguments.
fn tools() -> Json {
    json!([
        {
            "name": "ops",
            "description": "Every op the game has registered: its name, what it does, and an example of its arguments.",
            "inputSchema": {"type": "object", "properties": {
                "name": {"type": "string", "description": "only the ops whose name holds this"}
            }},
        },
        {
            "name": "op",
            "description": "Run one registered op by name with its JSON arguments, as the game's control plane does, and give its result.",
            "inputSchema": {"type": "object", "properties": {
                "name": {"type": "string", "description": "the op's name, as ops gives it"},
                "args": {"type": "object", "description": "the op's arguments; leave out for none"}
            }, "required": ["name"]},
        },
    ])
}

/// A tool called: its result as text, or its error marked as one.
fn call(params: &Json) -> Json {
    let args = params.get("arguments").cloned().unwrap_or(Json::Null);
    let found = match params.get("name").and_then(Json::as_str).unwrap_or_default() {
        "ops" => {
            let filter = args.get("name").and_then(Json::as_str).unwrap_or_default();
            let mut list = OP_REGISTRY.list_json();
            if let Some(ops) = list["ops"].as_array_mut() {
                ops.retain(|o| o["name"].as_str().is_some_and(|n| n.contains(filter)));
            }
            Ok(list)
        }
        "op" => match args.get("name").and_then(Json::as_str) {
            Some(op) => OP_REGISTRY
                .dispatch(op, &args.get("args").cloned().unwrap_or(Json::Null))
                .unwrap_or_else(|| Err(format!("no op named {op}; ops lists them"))),
            None => Err("name: the op's name".to_string()),
        },
        other => Err(format!("no tool {other}")),
    };
    let (text, is_error) = match found {
        Ok(value) => (serde_json::to_string_pretty(&value).unwrap_or_default(), false),
        Err(e) => (e, true),
    };
    json!({"content": [{"type": "text", "text": text}], "isError": is_error})
}

/// A JSON-RPC response's bytes.
fn reply(id: &Json, result: Result<Json, (i64, String)>) -> Vec<u8> {
    let message = match result {
        Ok(result) => json!({"jsonrpc": "2.0", "id": id, "result": result}),
        Err((code, message)) => json!({"jsonrpc": "2.0", "id": id, "error": {"code": code, "message": message}}),
    };
    serde_json::to_vec(&message).unwrap_or_default()
}

#[cfg(test)]
mod tests {
    use super::*;

    fn asked(body: Json) -> Json {
        serde_json::from_slice(&answer(&body.to_string(), "test")).unwrap()
    }

    #[test]
    fn a_notification_is_not_answered() {
        assert!(answer(r#"{"jsonrpc":"2.0","method":"notifications/initialized"}"#, "test").is_empty());
    }

    #[test]
    fn op_runs_a_registered_op() {
        OP_REGISTRY.register(crate::ops::OpDef::new("mcp_echo", "echo", "{}", |args| Ok(args.clone())));
        let r = asked(json!({"jsonrpc": "2.0", "id": 1, "method": "tools/call",
            "params": {"name": "op", "arguments": {"name": "mcp_echo", "args": {"a": 1}}}}));
        assert_eq!(r["id"], 1);
        assert_eq!(r["result"]["isError"], false);
        assert_eq!(serde_json::from_str::<Json>(r["result"]["content"][0]["text"].as_str().unwrap()).unwrap(), json!({"a": 1}));
        let r = asked(json!({"jsonrpc": "2.0", "id": 2, "method": "tools/call",
            "params": {"name": "op", "arguments": {"name": "no_such_op"}}}));
        assert_eq!(r["result"]["isError"], true);
    }
}
