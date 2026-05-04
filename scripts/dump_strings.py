"""Extract readable strings from a UE .uasset/.uexp pair.

UE FName table strings are length-prefixed (int32 length followed by
the bytes). We don't parse the format strictly here -- we just scan
for runs of printable ASCII >= MIN_LEN, dedupe, and bucket them so
the user can read what's referenced in the asset.
"""
import re
import sys
from pathlib import Path

MIN_LEN = 4
PRINTABLE_RUN = re.compile(rb"[\x20-\x7e]{%d,}" % MIN_LEN)


def dump(path: Path) -> list[str]:
    data = path.read_bytes()
    raw = [m.decode("ascii") for m in PRINTABLE_RUN.findall(data)]
    seen = set()
    out = []
    for s in raw:
        if s not in seen:
            seen.add(s)
            out.append(s)
    return out


def is_ue_name(s: str) -> bool:
    return bool(re.fullmatch(r"[A-Za-z_][A-Za-z0-9_]{2,}", s))


def is_ue_path(s: str) -> bool:
    return s.startswith("/") and "/" in s[1:]


def is_pretty_text(s: str) -> bool:
    return any(c.isalpha() for c in s) and any(c.isspace() or c in ".,!?:" for c in s)


def main() -> int:
    if len(sys.argv) < 2:
        print("usage: dump_strings.py <file> [file ...]", file=sys.stderr)
        return 2

    for arg in sys.argv[1:]:
        path = Path(arg)
        if not path.exists():
            print(f"missing: {path}", file=sys.stderr)
            continue

        all_strings = dump(path)
        print(f"\n===== {path.name} ({path.stat().st_size:,} bytes) =====")
        print(f"total unique strings: {len(all_strings)}")

        names = [s for s in all_strings if is_ue_name(s)]
        paths = [s for s in all_strings if is_ue_path(s)]
        prose = [s for s in all_strings if is_pretty_text(s) and not is_ue_path(s)]
        other = [s for s in all_strings
                 if s not in names and s not in paths and s not in prose]

        print(f"  ue names (identifier-shaped): {len(names)}")
        print(f"  ue paths (/Game/... style):   {len(paths)}")
        print(f"  prose-shaped (sentences):     {len(prose)}")
        print(f"  other:                        {len(other)}")

        print("\n--- UE paths ---")
        for s in paths:
            print(s)

        print("\n--- prose ---")
        for s in prose[:200]:
            print(s)

        print("\n--- ue names sample (first 200) ---")
        for s in names[:200]:
            print(s)

    return 0


if __name__ == "__main__":
    sys.exit(main())
