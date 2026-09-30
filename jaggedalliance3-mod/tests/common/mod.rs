#![allow(dead_code)]

const ENV_PORT: &str = "JA3_DEBUG_PORT";

pub type Api = modforge::client::Api<serde_json::Value>;

pub fn api_or_skip() -> Option<Api> {
    let Some(api) = Api::try_connect(ENV_PORT, "/op") else {
        eprintln!(
            "SKIP: set {ENV_PORT}=33079, launch JA3.exe and run modforge-inject --process JA3.exe --dll <jaggedalliance3.dll> --port 33079"
        );
        return None;
    };
    match api.try_op("ping", serde_json::json!({})) {
        Ok(_) => Some(api),
        Err(e) => {
            eprintln!("SKIP: control plane not answering ({e})");
            None
        }
    }
}
