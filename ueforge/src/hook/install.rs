//! Hook-install retry/backoff helper.
//!
//! UE classes show up in GObjects on the engine's schedule, not
//! ours. `on_unreal_init` fires before most blueprint-generated
//! classes load (the inventory widget class isn't there until the
//! player opens the inventory the first time). Every UE4SS-Rust mod
//! ends up with the same retry-with-exponential-backoff loop around
//! its hook installs.
//!
//! ```ignore
//! match ueforge::hook::install_with_backoff(
//!     "inv hook",
//!     ueforge::hook::RetryPolicy::default_install(),
//!     || inv_hook::install(slot_count),
//! ) {
//!     Some(h) => { ueforge::log!("inv hook: installed"); std::mem::forget(h); }
//!     None    => { ueforge::log!("inv hook: gave up"); }
//! }
//! ```
//!
//! Logs "pending" lines as the install attempt errors change so the
//! mod log shows the engine-load progression. Logs once on timeout.

use std::time::{Duration, Instant};

#[derive(Debug, Clone, Copy)]
pub struct RetryPolicy {
    pub base: Duration,
    pub max: Duration,
    pub timeout: Duration,
}

impl RetryPolicy {
    pub const fn new(base: Duration, max: Duration, timeout: Duration) -> Self {
        Self { base, max, timeout }
    }

    /// 500ms base, 5s cap, 10min timeout. Matches bbp's tuning,
    /// which has held across both inventory and damage hooks.
    pub const fn default_install() -> Self {
        Self::new(
            Duration::from_millis(500),
            Duration::from_secs(5),
            Duration::from_secs(600),
        )
    }
}

/// Repeatedly call `try_install` with exponential backoff (capped
/// by `policy.max`) until it returns `Ok` or `policy.timeout`
/// elapses. Returns `Some(h)` on success, `None` after timeout.
///
/// `name` is used for log lines only.
pub fn install_with_backoff<H, F>(
    name: &str,
    policy: RetryPolicy,
    mut try_install: F,
) -> Option<H>
where
    F: FnMut() -> Result<H, &'static str>,
{
    let mut delay = policy.base;
    let deadline = Instant::now() + policy.timeout;
    let mut last_err: Option<&str> = None;
    loop {
        match try_install() {
            Ok(h) => return Some(h),
            Err(e) => {
                if last_err != Some(e) {
                    crate::log!("{name}: pending ({e}), will retry");
                    last_err = Some(e);
                }
            }
        }
        if Instant::now() >= deadline {
            crate::log!("{name}: gave up after {:?}", policy.timeout);
            return None;
        }
        std::thread::sleep(delay);
        delay = (delay * 2).min(policy.max);
    }
}

#[cfg(test)]
mod tests {
    use super::*;
    use std::sync::atomic::{AtomicU32, Ordering};

    #[test]
    fn succeeds_on_first_try() {
        let policy = RetryPolicy::new(
            Duration::from_millis(1),
            Duration::from_millis(10),
            Duration::from_millis(100),
        );
        let result: Option<&'static str> =
            install_with_backoff("test", policy, || Ok("hook"));
        assert_eq!(result, Some("hook"));
    }

    #[test]
    fn retries_then_succeeds() {
        let attempts = AtomicU32::new(0);
        let policy = RetryPolicy::new(
            Duration::from_millis(1),
            Duration::from_millis(10),
            Duration::from_millis(500),
        );
        let result: Option<u32> = install_with_backoff("test", policy, || {
            let n = attempts.fetch_add(1, Ordering::Relaxed);
            if n < 3 { Err("not ready") } else { Ok(n) }
        });
        assert_eq!(result, Some(3));
        assert_eq!(attempts.load(Ordering::Relaxed), 4);
    }

    #[test]
    fn times_out() {
        let policy = RetryPolicy::new(
            Duration::from_millis(1),
            Duration::from_millis(2),
            Duration::from_millis(20),
        );
        let result: Option<()> =
            install_with_backoff("test", policy, || Err("never"));
        assert_eq!(result, None);
    }

    #[test]
    fn default_policy_values() {
        let p = RetryPolicy::default_install();
        assert_eq!(p.base, Duration::from_millis(500));
        assert_eq!(p.max, Duration::from_secs(5));
        assert_eq!(p.timeout, Duration::from_secs(600));
    }
}
