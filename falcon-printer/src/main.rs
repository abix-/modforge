//! falcon-printer: Rust output backend for Falcon.
//!
//! Subcommands:
//!   print     lift one function, print Rust to stdout
//!   batch     read addresses from stdin, write one .rs per fn to a dir
//!   sweep     lift many addresses, report pass/fail breakdown
//!   dump-il   print raw Falcon IL for one function (debug aid)
//!
//! See docs/usage.md for examples. Pipeline:
//!   1. Falcon lifts bytes -> il::Function
//!   2. Falcon dead-code-elimination prunes never-used scalars
//!   3. Lower il::Function -> RustIr (one Stmt per IL op)
//!   4. Pass: fold single-use temps into their use site
//!   5. Pass: recognize x86 flag-set patterns, rewrite flag reads as bool exprs
//!   6. Pass: recognize x86 call pattern (push retaddr; branch target) -> Call
//!   7. Pass: recognize x86 ret pattern (pop into temp; branch temp)  -> Return
//!   8. Print RustIr with Ghidra-derived function names when available

use clap::{Parser, Subcommand};
use falcon::analysis::dead_code_elimination;
use falcon::il;
use falcon::loader::{Loader, Pe};
use falcon::translator::Options;
use std::collections::{HashMap, HashSet};
use std::fs;
use std::io::{self, BufRead, Write};
use std::path::{Path, PathBuf};
use std::process::ExitCode;

const DEFAULT_BINARY: &str =
    "C:/Games/Steam/steamapps/common/Horsey Game/Horsey.exe";

#[derive(Parser)]
#[command(
    name = "falcon-printer",
    about = "Rust output backend for Falcon. Lifts PE binaries to readable Rust pseudocode.",
)]
struct Cli {
    /// Path to the target binary. Defaults to Horsey.exe.
    #[arg(long, global = true)]
    bin: Option<PathBuf>,

    #[command(subcommand)]
    cmd: Cmd,
}

#[derive(Subcommand)]
enum Cmd {
    /// Lift one function and print Rust to stdout.
    Print {
        /// Function address (hex, with or without 0x).
        #[arg(long, short = 'a')]
        addr: String,
    },

    /// Read addresses from stdin (one per line, hex). Write one
    /// `fn_<addr>.rs` per function to the output directory.
    Batch {
        /// Output directory.
        #[arg(
            long,
            short = 'o',
            default_value = "C:/code/grounded2mods/horseygame/decompiled/rust"
        )]
        out: PathBuf,
    },

    /// Sweep many addresses; report pass/fail counts and failure
    /// breakdown. By default reads `ghidra_addrs.txt`; pass
    /// `--falcon-entries` to use Falcon's PE-table entries instead.
    Sweep {
        /// Address-list file (one hex per line).
        #[arg(long, default_value = "ghidra_addrs.txt")]
        addrs: PathBuf,

        /// Use Falcon's PE function-entry table instead of `--addrs`.
        #[arg(long)]
        falcon_entries: bool,
    },

    /// Dump raw Falcon IL for one function (pre-printer, debug aid).
    DumpIl {
        #[arg(long, short = 'a')]
        addr: String,
    },
}

fn parse_addr(s: &str) -> Result<u64, std::num::ParseIntError> {
    u64::from_str_radix(s.trim().trim_start_matches("0x"), 16)
}

fn main() -> ExitCode {
    let cli = Cli::parse();
    let binary = cli.bin.unwrap_or_else(|| PathBuf::from(DEFAULT_BINARY));

    let result: Result<(), Box<dyn std::error::Error>> = match cli.cmd {
        Cmd::Print { addr } => cmd_print(&binary, &addr),
        Cmd::Batch { out } => cmd_batch(&binary, &out),
        Cmd::Sweep { addrs, falcon_entries } => {
            cmd_sweep(&binary, &addrs, falcon_entries)
        }
        Cmd::DumpIl { addr } => cmd_dump_il(&binary, &addr),
    };

    match result {
        Ok(()) => ExitCode::SUCCESS,
        Err(e) => {
            eprintln!("error: {e}");
            ExitCode::FAILURE
        }
    }
}

fn cmd_print(binary: &Path, addr: &str) -> Result<(), Box<dyn std::error::Error>> {
    let addr = parse_addr(addr)?;
    let names = load_name_table()?;
    let pe = Pe::from_file(binary)?;
    let opts = build_opts();
    let ir = lift_and_pass(&pe, &opts, addr, &names)?;
    print_rust_to(&mut io::stdout().lock(), &ir, &names)?;
    Ok(())
}

fn cmd_batch(binary: &Path, out_dir: &Path) -> Result<(), Box<dyn std::error::Error>> {
    fs::create_dir_all(out_dir)?;
    let names = load_name_table()?;
    let pe = Pe::from_file(binary)?;
    let opts = build_opts();

    let stdin = io::stdin();
    let addrs: Vec<u64> = stdin
        .lock()
        .lines()
        .filter_map(|l| l.ok())
        .map(|l| l.trim().to_string())
        .filter(|s| !s.is_empty() && !s.starts_with('#'))
        .filter_map(|s| parse_addr(&s).ok())
        .collect();

    let mut ok = 0usize;
    let mut err = 0usize;
    for &addr in &addrs {
        let path = out_dir.join(format!("fn_{:x}.rs", addr));
        match lift_and_pass(&pe, &opts, addr, &names) {
            Ok(ir) => {
                let mut buf = Vec::new();
                print_rust_to(&mut buf, &ir, &names)?;
                fs::write(&path, &buf)?;
                ok += 1;
            }
            Err(_) => err += 1,
        }
    }
    eprintln!("[batch] {ok} ok, {err} err, {} total", addrs.len());
    Ok(())
}

fn cmd_sweep(
    binary: &Path,
    addr_file: &Path,
    falcon_entries: bool,
) -> Result<(), Box<dyn std::error::Error>> {
    let pe = Pe::from_file(binary)?;
    let opts = build_opts();

    let addrs: Vec<u64> = if falcon_entries {
        pe.function_entries()?.iter().map(|e| e.address()).collect()
    } else {
        fs::read_to_string(addr_file)?
            .lines()
            .filter_map(|s| parse_addr(s).ok())
            .collect()
    };

    let total = addrs.len();
    let source = if falcon_entries {
        "Falcon PE entries".to_string()
    } else {
        addr_file.display().to_string()
    };
    println!("[sweep] {total} addresses from {source}");

    let mut ok = 0usize;
    let mut fail_by_reason: HashMap<String, usize> = HashMap::new();
    let mut sample_failures: HashMap<String, u64> = HashMap::new();

    for (i, &addr) in addrs.iter().enumerate() {
        match pe.function_extended(addr, &opts) {
            Ok(_) => ok += 1,
            Err(e) => {
                let key = classify_err(&e.to_string());
                *fail_by_reason.entry(key.clone()).or_insert(0) += 1;
                sample_failures.entry(key).or_insert(addr);
            }
        }
        if (i + 1) % 1000 == 0 {
            eprintln!("[sweep] {} / {total}  (ok={ok})", i + 1);
        }
    }

    println!();
    println!(
        "[sweep] DONE: {ok}/{total} lifted ({:.1}%)",
        100.0 * ok as f64 / total as f64
    );
    println!();
    println!("[sweep] top failure reasons:");
    let mut sorted: Vec<_> = fail_by_reason.iter().collect();
    sorted.sort_by_key(|(_, n)| std::cmp::Reverse(**n));
    for (reason, count) in sorted.iter().take(25) {
        let sample = sample_failures.get(*reason).copied().unwrap_or(0);
        println!("  {count:>5}  {reason:<60}  (sample: 0x{sample:x})");
    }
    if sorted.len() > 25 {
        let rest: usize = sorted.iter().skip(25).map(|(_, n)| **n).sum();
        println!("  {rest:>5}  ...(other {} reasons)", sorted.len() - 25);
    }
    Ok(())
}

fn classify_err(msg: &str) -> String {
    if let Some(pos) = msg.find("Unhandled instruction ") {
        let rest = &msg[pos + "Unhandled instruction ".len()..];
        if let Some(end) = rest.find(|c: char| c == ' ' || c == ',' || c == '"') {
            return format!("unhandled: {}", &rest[..end]);
        }
        return format!("unhandled: {}", &rest[..rest.len().min(20)]);
    }
    if msg.contains("DisassemblyFailure") {
        return "DisassemblyFailure".into();
    }
    if msg.contains("Unrecoverable error during disassembly") {
        return "DisasmFailureUnrecoverable".into();
    }
    msg.lines().next().unwrap_or(msg).chars().take(80).collect()
}

fn cmd_dump_il(binary: &Path, addr: &str) -> Result<(), Box<dyn std::error::Error>> {
    let addr = parse_addr(addr)?;
    let pe = Pe::from_file(binary)?;
    let opts = build_opts();
    let func = pe.function_extended(addr, &opts)?;
    let cfg = func.control_flow_graph();

    println!("# Function 0x{addr:x}");
    println!("# blocks: {}, edges: {}", cfg.blocks().len(), cfg.edges().len());
    println!();

    let block_list = cfg.blocks();
    let mut blocks: Vec<_> = block_list.iter().collect();
    blocks.sort_by_key(|b| (b.address().unwrap_or(u64::MAX), b.index()));

    for block in &blocks {
        println!(
            "## Block @ 0x{:x}  (index {})",
            block.address().unwrap_or(0),
            block.index()
        );
        for instr in block.instructions() {
            println!("  {}", instr);
        }
        let succs: Vec<_> = cfg
            .edges()
            .iter()
            .filter(|e| e.head() == block.index())
            .map(|e| {
                let cond = e
                    .condition()
                    .map(|c| format!(" if {c}"))
                    .unwrap_or_default();
                format!("block#{}{}", e.tail(), cond)
            })
            .collect();
        if !succs.is_empty() {
            println!("  -> {}", succs.join(", "));
        }
        println!();
    }
    Ok(())
}

fn build_opts() -> Options {
    let mut opts = Options::new();
    opts.set_unsupported_are_intrinsics(true);
    opts
}

fn lift_and_pass(
    pe: &Pe,
    opts: &Options,
    addr: u64,
    names: &HashMap<u64, String>,
) -> Result<RustIr, Box<dyn std::error::Error>> {
    let raw = pe.function_extended(addr, opts)?;
    let cleaned = dead_code_elimination(&raw).unwrap_or(raw);
    let mut ir = lower_to_rust_ir(&cleaned, addr, names);
    pass_fold_temps(&mut ir);
    pass_flag_recognition(&mut ir);
    pass_propagate_flags_across_blocks(&mut ir);
    pass_collapse_synth_blocks(&mut ir);
    pass_simplify_conditions(&mut ir);
    pass_call_recovery(&mut ir, names);
    pass_ret_recovery(&mut ir);
    pass_drop_dead_flags(&mut ir);
    Ok(ir)
}

// ---------------------------------------------------------------- name table

fn load_name_table() -> std::io::Result<HashMap<u64, String>> {
    let path = "C:/code/grounded2mods/horseygame/decompiled/INDEX.md";
    let text = match fs::read_to_string(path) {
        Ok(t) => t,
        Err(_) => return Ok(HashMap::new()),
    };
    let mut map = HashMap::new();
    for line in text.lines() {
        let line = line.trim();
        if !line.starts_with("| 0x") {
            continue;
        }
        let cols: Vec<&str> = line.split('|').map(str::trim).collect();
        if cols.len() < 3 {
            continue;
        }
        let addr_str = cols[1].trim_start_matches("0x");
        let Ok(addr) = u64::from_str_radix(addr_str, 16) else {
            continue;
        };
        let raw_name = cols[2].trim_matches('`').to_string();
        map.insert(addr, raw_name);
    }
    // Pull friendlier names from key-funcs/<addr>_<slug>.c filenames.
    if let Ok(entries) = fs::read_dir("C:/code/grounded2mods/horseygame/decompiled/key-funcs") {
        for entry in entries.flatten() {
            let name = entry.file_name().to_string_lossy().to_string();
            if let Some(rest) = name.strip_prefix("0x") {
                if let Some(end) = rest.find('_') {
                    let addr_str = &rest[..end];
                    if let Ok(addr) = u64::from_str_radix(addr_str, 16) {
                        let slug = rest[end + 1..]
                            .trim_end_matches(".c")
                            .to_string();
                        map.insert(addr, slug);
                    }
                }
            }
        }
    }
    Ok(map)
}

// ---------------------------------------------------------------- RustIr

#[derive(Debug, Clone)]
struct RustIr {
    addr: u64,
    blocks: Vec<RustBlock>,
}

#[derive(Debug, Clone)]
struct RustBlock {
    index: usize,
    addr: Option<u64>,
    stmts: Vec<Stmt>,
    /// (cond, target_index)  --  cond=None means unconditional.
    succs: Vec<(Option<Expr>, usize)>,
    /// (lhs, rhs) of the cmp/sub that set this block's flags, if recognized.
    flag_src: Option<(Expr, Expr)>,
}

#[derive(Debug, Clone)]
enum Stmt {
    /// `let mut <name>: <ty> = <expr>;`
    Let { name: String, bits: usize, expr: Expr, ip: Option<u64> },
    /// `<name> = <expr>;`  (re-assignment of an already-declared var)
    Reassign { name: String, expr: Expr, ip: Option<u64> },
    /// `*(<addr> as *mut u<bits>) = <expr>;`
    Store { addr: Expr, bits: usize, src: Expr, ip: Option<u64> },
    /// Marker emitted by call-recovery; printed as `<callee>();`.
    Call { callee: CallTarget, ip: Option<u64> },
    /// Marker emitted by ret-recovery; printed as `return;`.
    Return { ip: Option<u64> },
    /// Raw branch (target is dynamic / not recognized as call/ret).
    Branch { target: Expr, ip: Option<u64> },
    /// Pass-through comment line.
    Comment(String),
}

#[derive(Debug, Clone)]
enum CallTarget {
    Direct(u64),
    Indirect(Expr),
}

#[derive(Debug, Clone)]
enum Expr {
    Scalar(String, usize),
    Const(u64, usize),
    /// Load from memory, value bits.
    Load { addr: Box<Expr>, bits: usize },
    /// Binary op rendered as infix in Rust output. `wrap=true` -> wrapping_<op>.
    Bin { op: BinOp, l: Box<Expr>, r: Box<Expr>, wrap: bool },
    /// Unary cast / extension.
    Cast { kind: CastKind, bits: usize, inner: Box<Expr> },
    /// Boolean expression that came out of flag-pattern recognition.
    Bool(Box<Expr>),
}

#[derive(Debug, Clone, Copy, PartialEq, Eq)]
enum BinOp {
    Add, Sub, Mul, DivU, DivS, ModU, ModS,
    And, Or, Xor, Shl, ShrU, ShrS,
    Eq, Ne, LtU, LtS,
}

impl BinOp {
    fn rust(&self) -> &'static str {
        match self {
            BinOp::Add => "+", BinOp::Sub => "-", BinOp::Mul => "*",
            BinOp::DivU | BinOp::DivS => "/",
            BinOp::ModU | BinOp::ModS => "%",
            BinOp::And => "&", BinOp::Or => "|", BinOp::Xor => "^",
            BinOp::Shl => "<<", BinOp::ShrU | BinOp::ShrS => ">>",
            BinOp::Eq => "==", BinOp::Ne => "!=",
            BinOp::LtU | BinOp::LtS => "<",
        }
    }
    fn signed(&self) -> bool {
        matches!(self, BinOp::DivS | BinOp::ModS | BinOp::ShrS | BinOp::LtS)
    }
    fn boolean(&self) -> bool {
        matches!(self, BinOp::Eq | BinOp::Ne | BinOp::LtU | BinOp::LtS)
    }
}

#[derive(Debug, Clone, Copy)]
enum CastKind {
    Zext,
    Sext,
    Trunc,
}

// ---------------------------------------------------------------- lowering

fn lower_to_rust_ir(
    func: &il::Function,
    addr: u64,
    _names: &HashMap<u64, String>,
) -> RustIr {
    let cfg = func.control_flow_graph();
    let mut blocks = Vec::new();
    let block_list = cfg.blocks();
    let mut indices: Vec<_> = block_list.iter().collect();
    indices.sort_by_key(|b| (b.address().unwrap_or(u64::MAX), b.index()));

    let mut declared: HashSet<String> = HashSet::new();
    for block in &indices {
        let mut stmts = Vec::new();
        for instr in block.instructions() {
            let ip = instr.address();
            match instr.operation() {
                il::Operation::Nop { .. } => {}
                il::Operation::Assign { dst, src } => {
                    let name = sanitize(dst.name());
                    let expr = lower_expr(src);
                    if declared.insert(name.clone()) {
                        stmts.push(Stmt::Let { name, bits: dst.bits(), expr, ip });
                    } else {
                        stmts.push(Stmt::Reassign { name, expr, ip });
                    }
                }
                il::Operation::Load { dst, index } => {
                    let name = sanitize(dst.name());
                    let load = Expr::Load { addr: Box::new(lower_expr(index)), bits: dst.bits() };
                    if declared.insert(name.clone()) {
                        stmts.push(Stmt::Let { name, bits: dst.bits(), expr: load, ip });
                    } else {
                        stmts.push(Stmt::Reassign { name, expr: load, ip });
                    }
                }
                il::Operation::Store { index, src } => {
                    stmts.push(Stmt::Store {
                        addr: lower_expr(index),
                        bits: src.bits(),
                        src: lower_expr(src),
                        ip,
                    });
                }
                il::Operation::Branch { target } => {
                    stmts.push(Stmt::Branch { target: lower_expr(target), ip });
                }
                il::Operation::Intrinsic { intrinsic } => {
                    stmts.push(Stmt::Comment(format!("intrinsic: {}", intrinsic)));
                }
            }
        }
        let edges = cfg.edges();
        let succs: Vec<_> = edges
            .iter()
            .filter(|e| e.head() == block.index())
            .map(|e| (e.condition().map(lower_expr), e.tail()))
            .collect();

        blocks.push(RustBlock {
            index: block.index(),
            addr: block.address(),
            stmts,
            succs,
            flag_src: None,
        });
    }
    RustIr { addr, blocks }
}

fn lower_expr(expr: &il::Expression) -> Expr {
    match expr {
        il::Expression::Scalar(s) => Expr::Scalar(sanitize(s.name()), s.bits()),
        il::Expression::Constant(c) => {
            let v = c.value_u64().unwrap_or(0);
            Expr::Const(v, c.bits())
        }
        il::Expression::Add(l, r) => bin(BinOp::Add, l, r, true),
        il::Expression::Sub(l, r) => bin(BinOp::Sub, l, r, true),
        il::Expression::Mul(l, r) => bin(BinOp::Mul, l, r, true),
        il::Expression::Divu(l, r) => bin(BinOp::DivU, l, r, false),
        il::Expression::Divs(l, r) => bin(BinOp::DivS, l, r, false),
        il::Expression::Modu(l, r) => bin(BinOp::ModU, l, r, false),
        il::Expression::Mods(l, r) => bin(BinOp::ModS, l, r, false),
        il::Expression::And(l, r) => bin(BinOp::And, l, r, false),
        il::Expression::Or(l, r) => bin(BinOp::Or, l, r, false),
        il::Expression::Xor(l, r) => bin(BinOp::Xor, l, r, false),
        il::Expression::Shl(l, r) => bin(BinOp::Shl, l, r, false),
        il::Expression::Shr(l, r) => bin(BinOp::ShrU, l, r, false),
        il::Expression::AShr(l, r) => bin(BinOp::ShrS, l, r, false),
        il::Expression::Cmpeq(l, r) => bin(BinOp::Eq, l, r, false),
        il::Expression::Cmpneq(l, r) => bin(BinOp::Ne, l, r, false),
        il::Expression::Cmpltu(l, r) => bin(BinOp::LtU, l, r, false),
        il::Expression::Cmplts(l, r) => bin(BinOp::LtS, l, r, false),
        il::Expression::Zext(bits, e) => Expr::Cast { kind: CastKind::Zext, bits: *bits, inner: Box::new(lower_expr(e)) },
        il::Expression::Sext(bits, e) => Expr::Cast { kind: CastKind::Sext, bits: *bits, inner: Box::new(lower_expr(e)) },
        il::Expression::Trun(bits, e) => Expr::Cast { kind: CastKind::Trunc, bits: *bits, inner: Box::new(lower_expr(e)) },
        il::Expression::Ite(c, t, f) => {
            // No direct equivalent; render as a Rust if-expr inside Bool wrapper.
            // (Rare in lifted x86 output.)
            Expr::Bool(Box::new(Expr::Bin {
                op: BinOp::Eq,
                l: Box::new(lower_expr(c)),
                r: Box::new(Expr::Const(0, c.bits())),
                wrap: false,
            }))
            // Note: ITE collapses to its boolean condition for now;
            // a proper printer would emit `if cond { t } else { f }`.
            // Functions that exercise ITE will lose information.
            // (Logged in TODO follow-ups.)
            // (We keep the false case unused to avoid dead-code warnings.)
            // Suppress unused with let _ = lower_expr(t)/f if needed.
        }
    }
}

fn bin(op: BinOp, l: &il::Expression, r: &il::Expression, wrap: bool) -> Expr {
    Expr::Bin {
        op,
        l: Box::new(lower_expr(l)),
        r: Box::new(lower_expr(r)),
        wrap,
    }
}

fn sanitize(name: &str) -> String {
    let mut s = name.replace('.', "_").replace('-', "_");
    // Falcon uses `temp_0xADDR` and lowercase register names which are valid idents.
    if let Some(rest) = s.strip_prefix("temp_0x") {
        s = format!("t_{}", rest.to_ascii_lowercase());
    }
    s
}

// ---------------------------------------------------------------- pass: fold temps

/// Inline `let t = expr;` followed by a single use of `t` into the use site.
/// This kills the temp-then-assign noise Falcon emits per instruction.
fn pass_fold_temps(ir: &mut RustIr) {
    for block in &mut ir.blocks {
        fold_block(&mut block.stmts);
    }
}

fn fold_block(stmts: &mut Vec<Stmt>) {
    let mut i = 0;
    while i < stmts.len() {
        let (name, expr) = match &stmts[i] {
            Stmt::Let { name, expr, .. } if name.starts_with("t_") => {
                (name.clone(), expr.clone())
            }
            _ => { i += 1; continue; }
        };
        // Count uses of `name` in the rest of this block. If exactly 1, inline.
        let mut uses = 0usize;
        let mut redefined = false;
        for s in &stmts[i + 1..] {
            if uses > 1 || redefined {
                break;
            }
            stmt_visit_exprs(s, &mut |e| { uses += count_scalar(e, &name); });
            if let Stmt::Reassign { name: n, .. } | Stmt::Let { name: n, .. } = s {
                if n == &name { redefined = true; }
            }
        }
        if uses == 1 && !redefined {
            // Find the unique use site and inline.
            for s in &mut stmts[i + 1..] {
                let mut hit = false;
                stmt_modify_exprs(s, &mut |e| {
                    if let Expr::Scalar(n, _) = e {
                        if n == &name {
                            *e = expr.clone();
                            hit = true;
                        }
                    }
                });
                if hit { break; }
            }
            stmts.remove(i);
            continue;
        }
        i += 1;
    }
}

fn stmt_visit_exprs(s: &Stmt, f: &mut dyn FnMut(&Expr)) {
    match s {
        Stmt::Let { expr, .. } | Stmt::Reassign { expr, .. } => visit_expr(expr, f),
        Stmt::Store { addr, src, .. } => { visit_expr(addr, f); visit_expr(src, f); }
        Stmt::Branch { target, .. } => visit_expr(target, f),
        Stmt::Call { callee, .. } => if let CallTarget::Indirect(e) = callee { visit_expr(e, f); }
        Stmt::Return { .. } | Stmt::Comment(_) => {}
    }
}
fn visit_expr(e: &Expr, f: &mut dyn FnMut(&Expr)) {
    f(e);
    match e {
        Expr::Load { addr, .. } => visit_expr(addr, f),
        Expr::Bin { l, r, .. } => { visit_expr(l, f); visit_expr(r, f); }
        Expr::Cast { inner, .. } => visit_expr(inner, f),
        Expr::Bool(inner) => visit_expr(inner, f),
        _ => {}
    }
}
fn count_scalar(e: &Expr, name: &str) -> usize {
    let mut n = 0;
    visit_expr(e, &mut |x| {
        if let Expr::Scalar(s, _) = x { if s == name { n += 1; } }
    });
    n
}

fn stmt_modify_exprs(s: &mut Stmt, f: &mut dyn FnMut(&mut Expr)) {
    match s {
        Stmt::Let { expr, .. } | Stmt::Reassign { expr, .. } => modify_expr(expr, f),
        Stmt::Store { addr, src, .. } => { modify_expr(addr, f); modify_expr(src, f); }
        Stmt::Branch { target, .. } => modify_expr(target, f),
        Stmt::Call { callee, .. } => if let CallTarget::Indirect(e) = callee { modify_expr(e, f); }
        Stmt::Return { .. } | Stmt::Comment(_) => {}
    }
}
fn modify_expr(e: &mut Expr, f: &mut dyn FnMut(&mut Expr)) {
    f(e);
    match e {
        Expr::Load { addr, .. } => modify_expr(addr, f),
        Expr::Bin { l, r, .. } => { modify_expr(l, f); modify_expr(r, f); }
        Expr::Cast { inner, .. } => modify_expr(inner, f),
        Expr::Bool(inner) => modify_expr(inner, f),
        _ => {}
    }
}

// ---------------------------------------------------------------- pass: flag recognition

/// x86 cmp lowers to ZF/SF/OF/CF assignments derived from a single
/// `(lhs - rhs)` computation. Then conditional edges read those flags.
/// Track the most recent flag-source operands and rewrite flag reads
/// in successor conditions as direct boolean exprs.
fn pass_flag_recognition(ir: &mut RustIr) {
    for block in &mut ir.blocks {
        // Recognize the canonical pattern:
        //   ZF = (X - Y) == 0
        //   SF = trun.1(((X - Y) >> 31))
        //   OF = ...
        //   CF = X <u (X - Y)
        // Extract X and Y, then drop those flag defs and rewrite succs.
        let mut flag_src: Option<(Expr, Expr)> = None;
        let mut to_remove: Vec<usize> = Vec::new();
        for (i, s) in block.stmts.iter().enumerate() {
            if let Stmt::Let { name, expr, .. } | Stmt::Reassign { name, expr, .. } = s {
                if matches!(name.as_str(), "ZF" | "SF" | "OF" | "CF" | "PF" | "AF") {
                    if name == "ZF" {
                        // ZF = ((X - Y) == 0)  ->  extract (X, Y)
                        if let Expr::Bin { op: BinOp::Eq, l, r, .. } = expr {
                            if let (Expr::Bin { op: BinOp::Sub, l: ll, r: rr, .. }, Expr::Const(0, _)) =
                                (l.as_ref(), r.as_ref())
                            {
                                flag_src = Some(((**ll).clone(), (**rr).clone()));
                            }
                        }
                    }
                    to_remove.push(i);
                }
            }
        }
        for i in to_remove.into_iter().rev() {
            block.stmts.remove(i);
        }
        if let Some(src) = flag_src.as_ref() {
            for (cond, _) in &mut block.succs {
                if let Some(c) = cond.as_mut() {
                    rewrite_flag_cond(c, &src.0, &src.1);
                }
            }
        }
        block.flag_src = flag_src;
    }
}

fn rewrite_flag_cond(c: &mut Expr, lhs: &Expr, rhs: &Expr) {
    // Walk the expression; when we encounter `ZF == 0` or `ZF == 1`, replace it
    // with `lhs != rhs` or `lhs == rhs` respectively. Higher-up wrappers like
    // `(ZF == 0) == 0` get simplified by the printer's print_expr_bool() pass.
    fn walk(e: &mut Expr, lhs: &Expr, rhs: &Expr) {
        if let Expr::Bin { op: BinOp::Eq, l, r, .. } = e {
            if let (Expr::Scalar(n, _), Expr::Const(v, _)) = (l.as_ref(), r.as_ref()) {
                if n == "ZF" {
                    let want_eq = *v == 1;
                    *e = Expr::Bin {
                        op: if want_eq { BinOp::Eq } else { BinOp::Ne },
                        l: Box::new(lhs.clone()),
                        r: Box::new(rhs.clone()),
                        wrap: false,
                    };
                    return;
                }
            }
        }
        // Recurse.
        match e {
            Expr::Bin { l, r, .. } => { walk(l, lhs, rhs); walk(r, lhs, rhs); }
            Expr::Cast { inner, .. } => walk(inner, lhs, rhs),
            Expr::Load { addr, .. } => walk(addr, lhs, rhs),
            Expr::Bool(inner) => walk(inner, lhs, rhs),
            _ => {}
        }
    }
    walk(c, lhs, rhs);
}

// ---------------------------------------------------------------- pass: cross-block flag propagation

/// After `pass_flag_recognition` ran inside each block, some synth-junction blocks
/// still have edge conditions that read `ZF` (the bit) instead of the recovered
/// `lhs == rhs` form. Track the source of the most recent ZF def reaching each
/// block (one-step predecessor walk; sufficient for Falcon's CFG shape) and
/// rewrite remaining ZF reads in successor conditions.
fn pass_propagate_flags_across_blocks(ir: &mut RustIr) {
    // Use flag_src captured by pass_flag_recognition.
    let block_flag_src: HashMap<usize, (Expr, Expr)> = ir
        .blocks
        .iter()
        .filter_map(|b| b.flag_src.clone().map(|s| (b.index, s)))
        .collect();
    let mut pred: HashMap<usize, Vec<usize>> = HashMap::new();
    for block in &ir.blocks {
        for (_, t) in &block.succs {
            pred.entry(*t).or_default().push(block.index);
        }
    }
    // For each block whose succs reference ZF in a condition, find the closest
    // predecessor with a known flag source and use it.
    let block_indices: Vec<usize> = ir.blocks.iter().map(|b| b.index).collect();
    let mut updates: Vec<(usize, Vec<(Option<Expr>, usize)>)> = Vec::new();
    for block in &ir.blocks {
        let needs = block.succs.iter().any(|(c, _)| {
            c.as_ref()
                .map(|e| expr_uses_scalar(e, "ZF"))
                .unwrap_or(false)
        });
        if !needs { continue; }
        // BFS over predecessors.
        let mut visited: HashSet<usize> = HashSet::new();
        let mut queue: Vec<usize> = pred.get(&block.index).cloned().unwrap_or_default();
        let mut src = None;
        while let Some(p) = queue.pop() {
            if !visited.insert(p) { continue; }
            if let Some(s) = block_flag_src.get(&p) {
                src = Some(s.clone());
                break;
            }
            if let Some(parents) = pred.get(&p) {
                queue.extend(parents.iter().copied());
            }
        }
        let Some((lhs, rhs)) = src else { continue };
        let mut new_succs = block.succs.clone();
        for (cond, _) in &mut new_succs {
            if let Some(c) = cond.as_mut() {
                rewrite_flag_cond(c, &lhs, &rhs);
            }
        }
        updates.push((block.index, new_succs));
    }
    // Apply.
    for (idx, succs) in updates {
        if let Some(block) = ir.blocks.iter_mut().find(|b| b.index == idx) {
            block.succs = succs;
        }
    }
    let _ = block_indices;
}

fn expr_uses_scalar(e: &Expr, name: &str) -> bool {
    let mut hit = false;
    visit_expr(e, &mut |x| {
        if let Expr::Scalar(n, _) = x { if n == name { hit = true; } }
    });
    hit
}

// ---------------------------------------------------------------- pass: collapse synth blocks

/// Falcon emits synthetic junction blocks (Block.address() == None) with no
/// instructions, only conditional successors. They route the same condition
/// to two destinations based on the flag bit. Collapse them: replace any edge
/// pointing INTO a synth block with two edges that mirror the synth's outgoing
/// edges (composing the conditions).
fn pass_collapse_synth_blocks(ir: &mut RustIr) {
    let synth_indices: HashSet<usize> = ir
        .blocks
        .iter()
        .filter(|b| b.addr.is_none() && b.stmts.is_empty())
        .map(|b| b.index)
        .collect();
    if synth_indices.is_empty() { return; }
    // Map: synth block idx -> its succs (copies).
    let synth_succs: HashMap<usize, Vec<(Option<Expr>, usize)>> = ir
        .blocks
        .iter()
        .filter(|b| synth_indices.contains(&b.index))
        .map(|b| (b.index, b.succs.clone()))
        .collect();

    for block in &mut ir.blocks {
        if synth_indices.contains(&block.index) { continue; }
        let mut new_succs: Vec<(Option<Expr>, usize)> = Vec::new();
        for (cond, t) in &block.succs {
            if let Some(synth) = synth_succs.get(t) {
                // Pick the synth-edge whose condition matches the parent's, if any.
                // Falcon's CFG splits the same boolean across the synth block twice
                // (true side and complement). Picking the matching arm collapses
                // both edges into one and drops the redundant other arm.
                let chosen = synth.iter().find(|(sc, _)| match (cond, sc) {
                    (Some(a), Some(b)) => exprs_equiv(a, b),
                    (None, _) | (_, None) => false,
                });
                if let Some((_, st)) = chosen {
                    new_succs.push((cond.clone(), *st));
                } else {
                    // Fallback: keep all synth arms with composed conditions.
                    for (scond, st) in synth {
                        let composed = match (cond.clone(), scond.clone()) {
                            (None, c) | (c, None) => c,
                            (Some(a), Some(b)) => Some(Expr::Bin {
                                op: BinOp::And,
                                l: Box::new(a),
                                r: Box::new(b),
                                wrap: false,
                            }),
                        };
                        new_succs.push((composed, *st));
                    }
                }
            } else {
                new_succs.push((cond.clone(), *t));
            }
        }
        // Dedupe identical (cond, target) entries.
        new_succs.dedup_by(|a, b| match (&a.0, &b.0) {
            (Some(x), Some(y)) => exprs_equiv(x, y) && a.1 == b.1,
            (None, None) => a.1 == b.1,
            _ => false,
        });
        block.succs = new_succs;
    }
    // Drop the synth blocks themselves.
    ir.blocks.retain(|b| !synth_indices.contains(&b.index));
}

/// Walk all successor conditions and apply `(X cmp Y) == 0` / `== 1` peephole
/// simplifications so downstream pattern matching sees normalized form.
fn pass_simplify_conditions(ir: &mut RustIr) {
    for block in &mut ir.blocks {
        for (cond, _) in &mut block.succs {
            if let Some(c) = cond.as_mut() {
                *c = simplify_bool(c);
            }
        }
    }
}

fn simplify_bool(e: &Expr) -> Expr {
    if let Expr::Bin { op, l, r, .. } = e {
        if let Expr::Const(v, 1) = r.as_ref() {
            let lhs = simplify_bool(l);
            return match (op, *v) {
                (BinOp::Eq, 0) => negate_bool(&lhs),
                (BinOp::Eq, 1) => lhs,
                (BinOp::Ne, 0) => lhs,
                (BinOp::Ne, 1) => negate_bool(&lhs),
                _ => Expr::Bin { op: *op, l: Box::new(lhs), r: r.clone(), wrap: false },
            };
        }
        return Expr::Bin {
            op: *op,
            l: Box::new(simplify_bool(l)),
            r: Box::new(simplify_bool(r)),
            wrap: false,
        };
    }
    e.clone()
}

fn negate_bool(e: &Expr) -> Expr {
    if let Expr::Bin { op, l, r, wrap } = e {
        let inv = match op {
            BinOp::Eq => Some(BinOp::Ne),
            BinOp::Ne => Some(BinOp::Eq),
            _ => None,
        };
        if let Some(op) = inv {
            return Expr::Bin { op, l: l.clone(), r: r.clone(), wrap: *wrap };
        }
    }
    Expr::Bin {
        op: BinOp::Eq,
        l: Box::new(e.clone()),
        r: Box::new(Expr::Const(0, 1)),
        wrap: false,
    }
}

fn exprs_equiv(a: &Expr, b: &Expr) -> bool {
    // Cheap structural equality; format-and-compare is simplest given enum size.
    format!("{:?}", a) == format!("{:?}", b)
}

/// Detect `a == X` vs `a != X` (or any boolean comparator pair that is the
/// strict inverse of each other). Used to recognize if/else branch arms.
fn conds_are_inverse(a: &Expr, b: &Expr) -> bool {
    if let (
        Expr::Bin { op: oa, l: la, r: ra, .. },
        Expr::Bin { op: ob, l: lb, r: rb, .. },
    ) = (a, b)
    {
        if !exprs_equiv(la, lb) || !exprs_equiv(ra, rb) {
            return false;
        }
        return matches!(
            (oa, ob),
            (BinOp::Eq, BinOp::Ne) | (BinOp::Ne, BinOp::Eq)
                | (BinOp::LtU, BinOp::LtU) // can't tell, give up
        ) && !matches!((oa, ob), (BinOp::LtU, BinOp::LtU));
    }
    false
}

// ---------------------------------------------------------------- pass: call recovery

/// x86 `call addr` lowers to:
///    rsp = rsp - 8
///    [rsp] = <return_addr_const>     (where const = address of NEXT instruction)
///    branch <target>
/// Detect this triple anywhere in a block (other code may interleave).
fn pass_call_recovery(ir: &mut RustIr, _names: &HashMap<u64, String>) {
    fn is_rsp_minus_8(s: &Stmt) -> bool {
        let (name, expr) = match s {
            Stmt::Let { name, expr, .. } | Stmt::Reassign { name, expr, .. } => (name, expr),
            _ => return false,
        };
        if name != "rsp" { return false; }
        matches!(expr,
            Expr::Bin { op: BinOp::Sub, l, r, .. }
            if matches!(l.as_ref(), Expr::Scalar(n, _) if n == "rsp")
               && matches!(r.as_ref(), Expr::Const(8, _)))
    }
    for block in &mut ir.blocks {
        loop {
            let mut found = None;
            for i in 0..block.stmts.len().saturating_sub(2) {
                let is_store_const = matches!(&block.stmts[i + 1], Stmt::Store { addr, bits: 64, src, .. }
                    if matches!(addr, Expr::Scalar(n, _) if n == "rsp")
                       && matches!(src, Expr::Const(_, 64)));
                let is_branch = matches!(&block.stmts[i + 2], Stmt::Branch { .. });
                if is_rsp_minus_8(&block.stmts[i]) && is_store_const && is_branch {
                    found = Some(i);
                    break;
                }
            }
            let Some(i) = found else { break };
            let (target, ip) = match &block.stmts[i + 2] {
                Stmt::Branch { target, ip } => (target.clone(), *ip),
                _ => unreachable!(),
            };
            let callee = match &target {
                Expr::Const(addr, _) => CallTarget::Direct(*addr),
                other => CallTarget::Indirect(other.clone()),
            };
            block.stmts.drain(i..i + 3);
            block.stmts.insert(i, Stmt::Call { callee, ip });
        }
    }
}

// ---------------------------------------------------------------- pass: ret recovery

/// x86 `ret` lowers to:
///    t_addr = [rsp]
///    rsp = rsp + 8
///    branch t_addr
/// Detect this triple at the end of a block (post-fold, the temp may be inlined
/// into the branch). Replace with Stmt::Return.
fn pass_ret_recovery(ir: &mut RustIr) {
    for block in &mut ir.blocks {
        let len = block.stmts.len();
        if len < 2 { continue; }
        let pre = &block.stmts[len - 2];
        let last = &block.stmts[len - 1];
        let is_ret_post_fold = matches!(pre, Stmt::Reassign { name, expr, .. }
            if name == "rsp"
                && matches!(expr,
                    Expr::Bin { op: BinOp::Add, l, r, .. }
                    if matches!(l.as_ref(), Expr::Scalar(n, _) if n == "rsp")
                       && matches!(r.as_ref(), Expr::Const(8, _))))
            && matches!(last, Stmt::Branch { target, .. }
                if matches!(target, Expr::Load { addr, .. }
                    if matches!(addr.as_ref(), Expr::Scalar(n, _) if n == "rsp")));

        if is_ret_post_fold {
            let ip = match last { Stmt::Branch { ip, .. } => *ip, _ => None };
            block.stmts.truncate(len - 2);
            block.stmts.push(Stmt::Return { ip });
        }
    }
}

// ---------------------------------------------------------------- pass: drop dead flag carriers

/// After flag recognition rewrote conditions, any leftover SF/OF/CF reads
/// (none expected, but be safe) are removed by Falcon's DCE. Also drop
/// flag let bindings that survived because flag recognition didn't trigger.
fn pass_drop_dead_flags(ir: &mut RustIr) {
    for block in &mut ir.blocks {
        block.stmts.retain(|s| match s {
            Stmt::Let { name, .. } | Stmt::Reassign { name, .. } => {
                !matches!(name.as_str(), "SF" | "OF" | "CF" | "PF" | "AF")
            }
            _ => true,
        });
    }
}

// ---------------------------------------------------------------- printer

fn print_rust_to<W: Write>(
    w: &mut W,
    ir: &RustIr,
    names: &HashMap<u64, String>,
) -> io::Result<()> {
    let fn_name = pretty_fn_name(ir.addr, names);
    writeln!(w, "// Decompiled from Horsey.exe @ 0x{:x}", ir.addr)?;
    writeln!(w, "// Pipeline: Falcon lift -> dce -> fold -> flag-recog -> call/ret-recov -> Rust print")?;
    writeln!(w, "// blocks: {}", ir.blocks.len())?;
    writeln!(w)?;
    writeln!(w, "#[allow(non_snake_case, unused_assignments, unused_variables, unused_mut, dead_code)]")?;
    writeln!(w, "pub unsafe fn {fn_name}() {{")?;

    for block in &ir.blocks {
        let label = block
            .addr
            .map(|a| format!("0x{a:x}"))
            .unwrap_or_else(|| format!("synth-{}", block.index));
        writeln!(w)?;
        writeln!(w, "    // ---- bb{} @ {label} ----", block.index)?;
        for s in &block.stmts {
            writeln!(w, "    {}", print_stmt(s, names))?;
        }
        match block.succs.as_slice() {
            [] => writeln!(w, "    // <no successors>")?,
            [(None, t)] => writeln!(w, "    /* fallthrough -> bb{t} */")?,
            [(Some(a), ta), (Some(b), tb)] if conds_are_inverse(a, b) => {
                writeln!(w, "    if {} {{", print_expr_bool(a))?;
                writeln!(w, "        /* -> bb{ta} */")?;
                writeln!(w, "    }} else {{")?;
                writeln!(w, "        /* -> bb{tb} */")?;
                writeln!(w, "    }}")?;
            }
            multi => {
                for (cond, t) in multi {
                    match cond {
                        Some(c) => writeln!(w, "    if {} {{ /* -> bb{t} */ }}", print_expr_bool(c))?,
                        None => writeln!(w, "    /* -> bb{t} */")?,
                    }
                }
            }
        }
    }

    writeln!(w, "}}")?;
    Ok(())
}

fn pretty_fn_name(addr: u64, names: &HashMap<u64, String>) -> String {
    match names.get(&addr) {
        Some(n) if !n.starts_with("FUN_") => n.clone(),
        _ => format!("fn_{addr:x}"),
    }
}

fn print_stmt(s: &Stmt, names: &HashMap<u64, String>) -> String {
    let ip = match s {
        Stmt::Let { ip, .. } | Stmt::Reassign { ip, .. } | Stmt::Store { ip, .. }
        | Stmt::Branch { ip, .. } | Stmt::Call { ip, .. } | Stmt::Return { ip } => *ip,
        Stmt::Comment(_) => None,
    };
    let prefix = ip
        .map(|a| format!("/* {a:08x} */ "))
        .unwrap_or_default();
    match s {
        Stmt::Let { name, bits, expr, .. } => {
            format!("{prefix}let mut {name}: {} = {};", rust_ty(*bits), print_expr_typed(expr, *bits))
        }
        Stmt::Reassign { name, expr, .. } => {
            format!("{prefix}{name} = {};", print_expr(expr))
        }
        Stmt::Store { addr, bits, src, .. } => {
            format!(
                "{prefix}core::ptr::write({} as *mut {}, {});",
                print_expr(addr), rust_ty(*bits), print_expr_typed(src, *bits),
            )
        }
        Stmt::Branch { target, .. } => {
            format!("{prefix}/* branch */ goto({});", print_expr(target))
        }
        Stmt::Call { callee, .. } => {
            let s = match callee {
                CallTarget::Direct(a) => format!("{}()", pretty_fn_name(*a, names)),
                CallTarget::Indirect(e) => format!("(/* indirect */ {})()", print_expr(e)),
            };
            format!("{prefix}{s};")
        }
        Stmt::Return { .. } => format!("{prefix}return;"),
        Stmt::Comment(c) => format!("// {c}"),
    }
}

fn rust_ty(bits: usize) -> String {
    match bits {
        1 => "bool".into(),
        8 | 16 | 32 | 64 | 128 => format!("u{bits}"),
        n => format!("/*u{n}*/ u64"),
    }
}

fn print_expr_typed(e: &Expr, _target_bits: usize) -> String {
    print_expr(e)
}

fn print_expr(e: &Expr) -> String {
    match e {
        Expr::Scalar(n, _) => n.clone(),
        Expr::Const(v, 1) => if *v == 0 { "false".into() } else { "true".into() },
        Expr::Const(v, bits) => format!("0x{v:x}_{}", rust_ty(*bits)),
        Expr::Load { addr, bits } => format!(
            "core::ptr::read({} as *const {})",
            print_expr(addr), rust_ty(*bits),
        ),
        Expr::Bin { op, l, r, wrap } => {
            if *wrap {
                let method = match op {
                    BinOp::Add => "wrapping_add",
                    BinOp::Sub => "wrapping_sub",
                    BinOp::Mul => "wrapping_mul",
                    _ => return format!("({} {} {})", print_expr(l), op.rust(), print_expr(r)),
                };
                format!("({}).{method}({})", print_expr(l), print_expr(r))
            } else if op.boolean() {
                format!("({} {} {})", print_expr(l), op.rust(), print_expr(r))
            } else if op.signed() {
                format!(
                    "((({} as i64) {} ({} as i64)) as u64)",
                    print_expr(l), op.rust(), print_expr(r),
                )
            } else {
                format!("({} {} {})", print_expr(l), op.rust(), print_expr(r))
            }
        }
        Expr::Cast { kind, bits, inner } => match kind {
            CastKind::Zext | CastKind::Trunc => format!("({} as {})", print_expr(inner), rust_ty(*bits)),
            CastKind::Sext => format!("(({} as i{bits}) as {})", print_expr(inner), rust_ty(*bits)),
        },
        Expr::Bool(inner) => print_expr(inner),
    }
}

fn print_expr_bool(e: &Expr) -> String {
    // Strip outer `(X == false)` / `(X != false)` noise that flag rewriting introduces.
    fn simplify(e: &Expr) -> Expr {
        if let Expr::Bin { op, l, r, .. } = e {
            if let Expr::Const(v, 1) = r.as_ref() {
                let lhs = simplify(l);
                return match (op, *v) {
                    (BinOp::Eq, 0) => negate(&lhs),
                    (BinOp::Eq, 1) => lhs,
                    (BinOp::Ne, 0) => lhs,
                    (BinOp::Ne, 1) => negate(&lhs),
                    _ => Expr::Bin {
                        op: *op,
                        l: Box::new(lhs),
                        r: r.clone(),
                        wrap: false,
                    },
                };
            }
            return Expr::Bin {
                op: *op,
                l: Box::new(simplify(l)),
                r: Box::new(simplify(r)),
                wrap: false,
            };
        }
        e.clone()
    }
    fn negate(e: &Expr) -> Expr {
        if let Expr::Bin { op, l, r, wrap } = e {
            let inv = match op {
                BinOp::Eq => Some(BinOp::Ne),
                BinOp::Ne => Some(BinOp::Eq),
                _ => None,
            };
            if let Some(op) = inv {
                return Expr::Bin { op, l: l.clone(), r: r.clone(), wrap: *wrap };
            }
        }
        // Fallback: wrap with logical not via `== false`.
        Expr::Bin {
            op: BinOp::Eq,
            l: Box::new(e.clone()),
            r: Box::new(Expr::Const(0, 1)),
            wrap: false,
        }
    }
    let simplified = simplify(e);
    match &simplified {
        Expr::Bin { op, .. } if op.boolean() => print_expr(&simplified),
        Expr::Scalar(_, 1) | Expr::Const(_, 1) | Expr::Bool(_) => print_expr(&simplified),
        _ => format!("({} != 0)", print_expr(&simplified)),
    }
}
