// Time-series perf sampler: 1Hz snapshots over a window,
// per-tick deltas formatted as a table. All sampling +
// formatting lives in `ueforge::client::diff::SampleSeries`.
//
//   set BBP_DEBUG_PORT=17171
//   cargo test --release --test explore_perf_timeseries. --nocapture

mod common;

use std::io::Write;
use std::time::Duration;

use common::open_perf_log;
use ueforge::client::diff::MetricsSnapshot;

const SAMPLE_COUNT: usize = 60;
const SAMPLE_INTERVAL: Duration = Duration::from_secs(1);

#[test]
fn timeseries_60_seconds() {
    let api = common::Api::require();
    let mut out = open_perf_log("timeseries");

    writeln!(
        out,
        "\n=== Time-series perf sampler ({SAMPLE_COUNT}s, 1Hz) ==="
    )
    .unwrap();
    let series = MetricsSnapshot::sample_series(api.inner(), SAMPLE_COUNT, SAMPLE_INTERVAL);
    writeln!(out, "{series}").unwrap();
}
