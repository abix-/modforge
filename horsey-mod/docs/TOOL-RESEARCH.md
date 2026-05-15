# Decompilation tooling research
> **Authoritative on:** the decompilation toolchain selection (why Ghidra + pyghidra).

Goal: 100% decompile `Horsey.exe` (4.4 MB stripped PE x64) with behavior documented to file.

Researched 2026-05-13 via `gh search repos`. Below is what other people have already built. Picking from this list is much smarter than building from scratch.

## The landscape

### Decompiler engines

| Tool | License | Stars | Notes |
|---|---|---|---|
| **Ghidra 12.1** | Apache 2.0 (NSA) | 68,432 | Industry standard free decompiler. Just released today (2026-05-13). Supports x86_64 PE out of the box. Has scripting API. |
| Reko 0.12.2 | GPL | 2,563 | Active alternative decompiler. Last release Dec 2025. |
| IDA Free / Hex-Rays | Commercial / freeware | n/a | Best commercial decompiler. Free version is decompile-only with limits. |
| Binary Ninja | Commercial | n/a | Excellent decompiler. Cloud free tier exists. |

Ghidra is the obvious choice: free, mature, scripting, headless mode, huge community.

### LLM-assisted decompilation

| Tool | Stars | Notes |
|---|---|---|
| **albertan017/LLM4Decompile** | 6,639 | Models fine-tuned specifically to convert x86 assembly to C. Last update Feb 2026. Published at EMNLP 2024. |

This is interesting for cleaning up Ghidra output but not a replacement for Ghidra itself. Ghidra produces structured pseudocode; LLM4Decompile produces idiomatic C from raw asm. Could be a Stage 2 enhancement.

### Ghidra + MCP (AI-driven RE) - this is the killer

Multiple actively-developed projects expose Ghidra to MCP clients (which means Claude can drive Ghidra directly):

| Tool | Stars | Notes |
|---|---|---|
| **LaurieWired/GhidraMCP** | 8,863 | Most popular. GUI plugin + Python bridge. Needs Ghidra GUI running. |
| **clearbluejar/pyghidra-mcp** | 325 | Headless-first via `pyghidra`/`jpype`. Streamable-HTTP transport. ChromaDB for semantic search across decompiled functions. CI-friendly. |
| **mrphrazer/ghidra-headless-mcp** | 76 | 212 tools, fully headless, designed for agent-driven workflows. |
| LiteGhidraMCP, themixednuts/GhidraMCP, others | <100 | Various forks and alternatives. |

**These tools turn Ghidra into a backend that Claude controls via MCP.** I (Claude) get tools like "decompile this function", "rename this variable", "show xrefs", "run script". I can iterate on the binary the way a human RE would, but faster and at scale.

### Auxiliary tools

- **Ghidrathon** (mandiant, 784 stars): Python 3 scripting inside Ghidra. Useful for custom analysis scripts beyond MCP.
- **Decompiler Explorer** (2,583 stars): web tool to compare decompiler output side-by-side. Sanity-check tool.

## Recommended stack

**Best path: Ghidra 12.1 + pyghidra-mcp.**

Why this combo:
1. Ghidra gives us the actual decompiler engine.
2. pyghidra-mcp exposes Ghidra to me as MCP tools, headless. I drive the analysis.
3. Headless = no babysitting a GUI. Reproducible. Scriptable.
4. ChromaDB semantic search lets me ask "find functions related to fatigue" and get hits across the whole binary.
5. Active development, recent updates.

Alternative: LaurieWired/GhidraMCP is more popular and might have better tool coverage, but requires running the Ghidra GUI. Acceptable tradeoff if pyghidra-mcp has rough edges.

## Install plan (when user approves)

1. **Java 21 JDK** (Ghidra needs it). Adoptium Temurin via winget or direct download.
2. **Ghidra 12.1** from GitHub release. Unzip somewhere. Set `GHIDRA_INSTALL_DIR`.
3. **uv** Python tool runner via pip or winget.
4. **pyghidra-mcp** via `uvx pyghidra-mcp` (no install needed, uv handles it).
5. **Claude Code MCP config**: `claude mcp add ghidra -- uvx pyghidra-mcp ...`.
6. Create Ghidra project, import `Horsey.exe`, run auto-analysis.
7. Use MCP to drive function-by-function decompilation, documenting to repo files.

Total disk: ~1.5 GB (mostly Ghidra). Total time: ~30 min setup + Ghidra's first-pass analysis (15-30 min).

## What this changes for the goal

Before: I planned to disassemble with Python + capstone (assembly only, no C). That would produce raw instructions, not decompiled code, and would never realistically hit 100%.

After: Ghidra + MCP gives us the actual decompiled pseudocode for every function in the binary, accessible to me via tool calls. I can systematically work through every function, document it, and commit.

Realistic completion: still multi-day at minimum for a 4.4 MB binary, but with proper tooling instead of bespoke scripts.
