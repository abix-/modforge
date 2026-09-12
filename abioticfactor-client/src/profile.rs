//! Persistent bot identity and an append-only local memory journal.
use serde::{Deserialize, Serialize};
use std::fs::{self, OpenOptions};
use std::io::{self, Write};
use std::path::{Path, PathBuf};
use std::time::{SystemTime, UNIX_EPOCH};

#[derive(Serialize, Deserialize)]
pub struct Profile {
    pub name: String,
    pub bot_id: String,
    pub appearance: String,
}

impl Profile {
    pub fn load_or_create(directory: &Path) -> io::Result<Self> {
        fs::create_dir_all(directory)?;
        let path = directory.join("profile.json");
        match fs::read(&path) {
            Ok(bytes) => {
                let profile: Self = serde_json::from_slice(&bytes)?;
                crate::identity::PlayerId::new(&profile.bot_id)?;
                Ok(profile)
            }
            Err(error) if error.kind() == io::ErrorKind::NotFound => {
                let profile = Self {
                    name: "Sophia".into(),
                    // Preserve the identity used for the user's first visible bot.
                    bot_id: "6d6f64666f7267654149506c61796572".into(),
                    appearance: "female".into(),
                };
                let mut file = OpenOptions::new().write(true).create_new(true).open(path)?;
                file.write_all(&serde_json::to_vec_pretty(&profile)?)?;
                file.sync_all()?;
                Ok(profile)
            }
            Err(error) => Err(error),
        }
    }
}

/// Stored outside the build directory so rebuilds do not erase Sophia.
pub fn directory() -> io::Result<PathBuf> {
    if let Some(path) = std::env::var_os("SOPHIA_HOME") { return Ok(path.into()); }
    std::env::var_os("LOCALAPPDATA")
        .map(|path| PathBuf::from(path).join("Modforge/Sophia"))
        .ok_or_else(|| io::Error::new(io::ErrorKind::NotFound, "set SOPHIA_HOME or LOCALAPPDATA"))
}

/// Journal only facts observed by the UDP client, never credentials or raw packets.
pub fn remember(directory: &Path, event: &str, server: &str) -> io::Result<()> {
    let seconds = SystemTime::now().duration_since(UNIX_EPOCH).map_err(io::Error::other)?.as_secs();
    let entry = serde_json::json!({"time":seconds,"event":event,"server":server});
    let mut file = OpenOptions::new().create(true).append(true).open(directory.join("memory.jsonl"))?;
    writeln!(file, "{entry}")?;
    file.sync_data()
}

pub fn recall(directory: &Path) -> io::Result<Vec<serde_json::Value>> {
    let text = match fs::read_to_string(directory.join("memory.jsonl")) {
        Ok(text) => text,
        Err(error) if error.kind() == io::ErrorKind::NotFound => return Ok(Vec::new()),
        Err(error) => return Err(error),
    };
    text.lines().map(|line| serde_json::from_str(line).map_err(io::Error::from)).collect()
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn identity_and_memory_survive_reopening() {
        let directory = std::env::temp_dir().join(format!("sophia-profile-{:016x}", fastrand::u64(..)));
        let first = Profile::load_or_create(&directory).unwrap();
        remember(&directory, "server_welcomed_me", "127.0.0.1:7777").unwrap();
        let second = Profile::load_or_create(&directory).unwrap();
        assert_eq!(first.bot_id, second.bot_id);
        assert_eq!(second.name, "Sophia");
        assert_eq!(second.appearance, "female");
        assert_eq!(recall(&directory).unwrap()[0]["event"], "server_welcomed_me");
        fs::remove_file(directory.join("profile.json")).unwrap();
        fs::remove_file(directory.join("memory.jsonl")).unwrap();
        fs::remove_dir(directory).unwrap();
    }
}
