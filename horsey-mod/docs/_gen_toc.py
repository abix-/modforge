"""Insert a Table of contents section into each horsey-mod doc.

Skips files that already have a "## Table of contents" heading.
Generates TOC from H2 (##) headings using GitHub-style slugs.
Inserts after the leading metadata (H1 + blockquote/intro paragraphs),
immediately before the first H2 heading.
"""

import re
from pathlib import Path

DOCS = Path(__file__).parent
SKIP = {"CONTENT-CREATION.md"}  # already has TOC


def slug(text: str) -> str:
    s = text.strip().lower()
    s = re.sub(r"[^\w\s-]", "", s)
    s = re.sub(r"\s+", "-", s)
    return s


def has_toc(lines: list[str]) -> bool:
    return any(re.match(r"^##\s+Table of contents\b", ln, re.I) for ln in lines)


def first_h2_index(lines: list[str]) -> int | None:
    for i, ln in enumerate(lines):
        if re.match(r"^##\s+\S", ln) and not re.match(r"^###", ln):
            return i
    return None


def collect_h2(lines: list[str]) -> list[str]:
    out = []
    for ln in lines:
        m = re.match(r"^##\s+(.+?)\s*$", ln)
        if m:
            title = m.group(1).strip()
            # strip leading numbering like "1. " from anchor display
            out.append(title)
    return out


def build_toc(headings: list[str]) -> list[str]:
    out = ["## Table of contents", ""]
    for h in headings:
        out.append(f"- [{h}](#{slug(h)})")
    out += ["", "---", ""]
    return out


def process(path: Path) -> bool:
    text = path.read_text(encoding="utf-8")
    lines = text.splitlines()
    if has_toc(lines):
        return False
    headings = collect_h2(lines)
    if len(headings) < 3:
        return False
    idx = first_h2_index(lines)
    if idx is None:
        return False
    # Walk back through blank lines to keep one blank before TOC.
    insert_at = idx
    while insert_at > 0 and lines[insert_at - 1].strip() == "":
        insert_at -= 1
    toc = build_toc(headings)
    new_lines = lines[:insert_at] + [""] + toc + lines[idx:]
    path.write_text("\n".join(new_lines) + ("\n" if text.endswith("\n") else ""), encoding="utf-8")
    return True


def main():
    changed = []
    skipped = []
    for p in sorted(DOCS.glob("*.md")):
        if p.name in SKIP:
            skipped.append((p.name, "already has TOC"))
            continue
        if process(p):
            changed.append(p.name)
        else:
            skipped.append((p.name, "no change"))
    print("Updated:")
    for n in changed:
        print(f"  {n}")
    print("Skipped:")
    for n, why in skipped:
        print(f"  {n} ({why})")


if __name__ == "__main__":
    main()
