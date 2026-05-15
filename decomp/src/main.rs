//! decomp / r2sleigh-spike.
//!
//! r2sleigh-substrate Rust-output decompiler. Subcommands match
//! falcon-printer's CLI surface so the workflow is identical
//! regardless of which crate is driving the lift.
//!
//! Pipeline:
//!   PE file (goblin)
//!     -> raw bytes for one function
//!     -> r2sleigh-lift              (Sleigh-based x86-64 lift)
//!     -> R2ILBlock
//!     -> r2ssa SSAFunction          (SSA + analyses)
//!     -> r2dec Decompiler::build_function -> CFunction (AST)
//!     -> our Rust emitter walks CFunction -> Rust pseudocode

use clap::{Parser, Subcommand};
use goblin::pe::PE;
use r2dec::ast::{BinaryOp, CExpr, CFunction, CStmt, CType, SwitchCase, UnaryOp};
use r2dec::{Decompiler, DecompilerConfig};
use r2sleigh_lift::disasm::Disassembler;
use r2sleigh_lift::sleigh::build_arch_spec;
use r2il::ArchSpec;
use r2ssa::SSAFunction;
use std::collections::HashMap;
use std::fs;
use std::io::{self, BufRead, Write};
use std::path::{Path, PathBuf};
use std::process::ExitCode;

const DEFAULT_BINARY: &str =
    "/mnt/c/Games/Steam/steamapps/common/Horsey Game/Horsey.exe";
const DEFAULT_INDEX_MD: &str =
    "/mnt/c/code/grounded2mods/horsey-mod/research/decompiled/INDEX.md";
const DEFAULT_KEY_FUNCS_DIR: &str =
    "/mnt/c/code/grounded2mods/horsey-mod/research/decompiled/key-funcs";
const DEFAULT_OUT_DIR: &str =
    "/mnt/c/code/grounded2mods/horsey-mod/research/decompiled/rust-r2sleigh";

#[derive(Parser)]
#[command(
    name = "decomp",
    about = "r2sleigh-based binary-to-Rust decompiler. Lifts PE binaries to readable Rust pseudocode."
)]
struct Cli {
    /// Path to the target binary. Defaults to Horsey.exe.
    #[arg(long, global = true)]
    bin: Option<PathBuf>,

    /// Function size to lift in bytes (default 4096).
    #[arg(long, global = true, default_value_t = 4096)]
    size: usize,

    #[command(subcommand)]
    cmd: Cmd,
}

#[derive(Subcommand)]
enum Cmd {
    /// Lift one function and print Rust to stdout.
    Print {
        #[arg(long, short = 'a')]
        addr: String,
        /// Output mode: rust (default) or c (raw r2dec output).
        #[arg(long, default_value = "rust")]
        emit: String,
    },

    /// Read addresses from stdin (one per line, hex). Write
    /// one `fn_<addr>.rs` per function to the output directory.
    Batch {
        #[arg(long, short = 'o', default_value = DEFAULT_OUT_DIR)]
        out: PathBuf,
    },

    /// Dump raw r2il for one function (pre-AST, debug aid).
    DumpIl {
        #[arg(long, short = 'a')]
        addr: String,
    },
}

fn main() -> ExitCode {
    let cli = Cli::parse();
    let binary = cli.bin.unwrap_or_else(|| PathBuf::from(DEFAULT_BINARY));
    let size = cli.size;

    let result: Result<(), Box<dyn std::error::Error>> = match cli.cmd {
        Cmd::Print { addr, emit } => cmd_print(&binary, &addr, size, &emit),
        Cmd::Batch { out } => cmd_batch(&binary, &out, size),
        Cmd::DumpIl { addr } => cmd_dump_il(&binary, &addr, size),
    };
    match result {
        Ok(()) => ExitCode::SUCCESS,
        Err(e) => {
            eprintln!("error: {e}");
            ExitCode::FAILURE
        }
    }
}

fn parse_addr(s: &str) -> Result<u64, std::num::ParseIntError> {
    u64::from_str_radix(s.trim().trim_start_matches("0x"), 16)
}

// ---------------------------------------------------------------- subcommands

fn cmd_print(
    binary: &Path,
    addr: &str,
    size: usize,
    emit: &str,
) -> Result<(), Box<dyn std::error::Error>> {
    let addr = parse_addr(addr)?;
    let names = load_name_table();
    let ctx = SleighCtx::new()?;
    let func = decompile_one(binary, &ctx, addr, size, &names)?;
    match emit {
        "c" => println!("{}", r2dec::codegen::generate(&func)),
        "rust" | _ => println!("{}", emit_rust(&func, addr)),
    }
    Ok(())
}

fn cmd_batch(
    binary: &Path,
    out_dir: &Path,
    size: usize,
) -> Result<(), Box<dyn std::error::Error>> {
    fs::create_dir_all(out_dir)?;
    let names = load_name_table();
    let ctx = SleighCtx::new()?;
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
    for addr in &addrs {
        let path = out_dir.join(format!("fn_{:x}.rs", addr));
        match decompile_one(binary, &ctx, *addr, size, &names) {
            Ok(func) => {
                let rust = emit_rust(&func, *addr);
                fs::write(&path, rust)?;
                ok += 1;
                eprintln!("[batch] ok 0x{addr:x} -> {}", path.display());
            }
            Err(e) => {
                err += 1;
                eprintln!("[batch] err 0x{addr:x}: {e}");
            }
        }
    }
    eprintln!("[batch] {ok} ok, {err} err, {} total", addrs.len());
    Ok(())
}

fn cmd_dump_il(
    binary: &Path,
    addr: &str,
    size: usize,
) -> Result<(), Box<dyn std::error::Error>> {
    let addr = parse_addr(addr)?;
    let ctx = SleighCtx::new()?;
    let bytes = read_function_bytes(binary, addr, size)?;
    eprintln!("[dump-il] {} bytes @ 0x{addr:x}", bytes.len());
    let block = ctx.disasm.lift_block(&bytes, addr, bytes.len())?;
    println!("# Function 0x{addr:x}");
    println!("# {} r2il ops", block.ops.len());
    println!();
    for (i, op) in block.ops.iter().enumerate() {
        println!("{i:4}  {op:?}");
    }
    Ok(())
}

// ---------------------------------------------------------------- shared helpers

struct SleighCtx {
    disasm: Disassembler,
    arch: ArchSpec,
}

impl SleighCtx {
    fn new() -> Result<Self, Box<dyn std::error::Error>> {
        let arch = build_arch_spec(
            sleigh_config::processor_x86::SLA_X86_64,
            sleigh_config::processor_x86::PSPEC_X86_64,
            "x86-64",
        )?;
        let disasm = Disassembler::from_sla(
            sleigh_config::processor_x86::SLA_X86_64,
            sleigh_config::processor_x86::PSPEC_X86_64,
            "x86-64",
        )?;
        Ok(Self { disasm, arch })
    }
}

fn read_function_bytes(
    binary: &Path,
    addr: u64,
    size: usize,
) -> Result<Vec<u8>, Box<dyn std::error::Error>> {
    let data = fs::read(binary)?;
    let pe = PE::parse(&data)?;
    let image_base = pe.image_base as u64;
    let rva = addr.checked_sub(image_base).ok_or("addr < image base")?;
    let section = pe
        .sections
        .iter()
        .find(|s| {
            let va = s.virtual_address as u64;
            rva >= va && rva < va + s.virtual_size as u64
        })
        .ok_or("addr not in any PE section")?;
    let file_offset =
        (rva - section.virtual_address as u64) + section.pointer_to_raw_data as u64;
    let file_offset = file_offset as usize;
    let avail = data.len().saturating_sub(file_offset);
    let size = size.min(avail);
    Ok(data[file_offset..file_offset + size].to_vec())
}

fn decompile_one(
    binary: &Path,
    _ctx: &SleighCtx,
    addr: u64,
    size: usize,
    names: &HashMap<u64, String>,
) -> Result<CFunction, Box<dyn std::error::Error>> {
    let bytes = read_function_bytes(binary, addr, size)?;
    let name_override = names.get(&addr).cloned();
    // Whole pipeline runs in a 1GB-stack thread. r2sleigh's internal
    // recursion (Sleigh lift through libsla, SSA construction, decompile
    // structurer) is deep enough that the default 8MB stack overflows
    // on dense float-math functions. Mirrors what the r2 plugin does
    // in run_full_decompile_on_large_stack.
    const STACK_SIZE: usize = 1024 * 1024 * 1024;
    let join = std::thread::Builder::new()
        .stack_size(STACK_SIZE)
        .spawn(move || -> Result<CFunction, String> {
            let ctx = SleighCtx::new().map_err(|e| e.to_string())?;
            let block = ctx
                .disasm
                .lift_block(&bytes, addr, bytes.len())
                .map_err(|e| e.to_string())?;
            let ssa = SSAFunction::from_blocks_for_decompile(&[block], Some(&ctx.arch))
                .ok_or("SSAFunction::from_blocks_for_decompile returned None".to_string())?;
            let dec = Decompiler::new(DecompilerConfig::default());
            let mut func = dec.build_function(&ssa);
            if let Some(name) = name_override {
                func.name = name;
            }
            Ok(func)
        })?;
    let func = join
        .join()
        .map_err(|_| "decompile thread panicked")?
        .map_err(|e| -> Box<dyn std::error::Error> { e.into() })?;
    Ok(func)
}

// ---------------------------------------------------------------- name table

fn load_name_table() -> HashMap<u64, String> {
    let mut map = HashMap::new();
    if let Ok(text) = fs::read_to_string(DEFAULT_INDEX_MD) {
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
            // Skip FUN_ placeholder names; key-funcs filenames override below.
            if !raw_name.starts_with("FUN_") {
                map.insert(addr, raw_name);
            }
        }
    }
    if let Ok(entries) = fs::read_dir(DEFAULT_KEY_FUNCS_DIR) {
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
    map
}

// ---------------------------------------------------------------- Rust emitter

fn emit_rust(func: &CFunction, addr: u64) -> String {
    let mut out = String::new();
    out.push_str(&format!("// Decompiled from Horsey.exe @ 0x{addr:x}\n"));
    out.push_str("// Pipeline: r2sleigh (Sleigh lift -> SSA -> structurer) -> our Rust printer\n");
    out.push('\n');
    out.push_str("#[allow(non_snake_case, unused_assignments, unused_variables, unused_mut, dead_code, unused_parens)]\n");
    out.push_str(&format!("pub unsafe fn {}(", sanitize_ident(&func.name)));
    for (i, p) in func.params.iter().enumerate() {
        if i > 0 {
            out.push_str(", ");
        }
        out.push_str(&format!("{}: {}", sanitize_ident(&p.name), rust_ty(&p.ty)));
    }
    out.push_str(") {\n");

    for local in &func.locals {
        out.push_str(&format!(
            "    let mut {}: {};\n",
            sanitize_ident(&local.name),
            rust_ty(&local.ty)
        ));
    }
    if !func.locals.is_empty() {
        out.push('\n');
    }

    for stmt in &func.body {
        emit_stmt(&mut out, stmt, 1);
    }

    out.push_str("}\n");
    out
}

fn emit_stmt(out: &mut String, stmt: &CStmt, indent: usize) {
    let pad = "    ".repeat(indent);
    match stmt {
        CStmt::Empty => out.push_str(&format!("{pad};\n")),
        CStmt::Expr(e) => out.push_str(&format!("{pad}{};\n", emit_expr(e, 0))),
        CStmt::Decl { ty, name, init } => match init {
            Some(e) => out.push_str(&format!(
                "{pad}let mut {}: {} = {};\n",
                sanitize_ident(name),
                rust_ty(ty),
                emit_expr(e, 0)
            )),
            None => out.push_str(&format!(
                "{pad}let mut {}: {};\n",
                sanitize_ident(name),
                rust_ty(ty)
            )),
        },
        CStmt::Block(stmts) => {
            out.push_str(&format!("{pad}{{\n"));
            for s in stmts {
                emit_stmt(out, s, indent + 1);
            }
            out.push_str(&format!("{pad}}}\n"));
        }
        CStmt::If { cond, then_body, else_body } => {
            out.push_str(&format!("{pad}if {} {{\n", as_bool(cond)));
            emit_stmt_body(out, then_body, indent + 1);
            if let Some(eb) = else_body {
                out.push_str(&format!("{pad}}} else {{\n"));
                emit_stmt_body(out, eb, indent + 1);
            }
            out.push_str(&format!("{pad}}}\n"));
        }
        CStmt::While { cond, body } => {
            out.push_str(&format!("{pad}while {} {{\n", as_bool(cond)));
            emit_stmt_body(out, body, indent + 1);
            out.push_str(&format!("{pad}}}\n"));
        }
        CStmt::DoWhile { body, cond } => {
            out.push_str(&format!("{pad}loop {{  // do-while\n"));
            emit_stmt_body(out, body, indent + 1);
            out.push_str(&format!(
                "{pad}    if !({}) {{ break; }}\n",
                as_bool(cond)
            ));
            out.push_str(&format!("{pad}}}\n"));
        }
        CStmt::For { init, cond, update, body } => {
            if let Some(i) = init {
                emit_stmt(out, i, indent);
            }
            let cond_str = cond
                .as_ref()
                .map(|c| as_bool(c))
                .unwrap_or_else(|| "true".to_string());
            out.push_str(&format!("{pad}while {cond_str} {{\n"));
            emit_stmt_body(out, body, indent + 1);
            if let Some(u) = update {
                out.push_str(&format!("{}    {};\n", pad, emit_expr(u, 0)));
            }
            out.push_str(&format!("{pad}}}\n"));
        }
        CStmt::Switch { expr, cases, default } => {
            out.push_str(&format!("{pad}match {} {{\n", emit_expr(expr, 0)));
            emit_switch_cases(out, cases, indent + 1);
            if let Some(d) = default {
                out.push_str(&format!("{}    _ => {{\n", pad));
                for s in d {
                    emit_stmt(out, s, indent + 2);
                }
                out.push_str(&format!("{}    }},\n", pad));
            } else {
                out.push_str(&format!("{}    _ => {{}},\n", pad));
            }
            out.push_str(&format!("{pad}}}\n"));
        }
        // r2dec emits `return 0;` from void-style functions sometimes;
        // emit `return;` for the void case to avoid clutter.
        CStmt::Return(Some(CExpr::IntLit(0))) => out.push_str(&format!("{pad}return;\n")),
        CStmt::Return(None) => out.push_str(&format!("{pad}return;\n")),
        CStmt::Return(Some(e)) => out.push_str(&format!("{pad}return {};\n", emit_expr(e, 0))),
        CStmt::Break => out.push_str(&format!("{pad}break;\n")),
        CStmt::Continue => out.push_str(&format!("{pad}continue;\n")),
        CStmt::Goto(label) => out.push_str(&format!("{pad}/* goto {label} */ break '{label};\n")),
        CStmt::Label(label) => out.push_str(&format!("{pad}'{label}: {{ /* label */ }}\n")),
        CStmt::Comment(text) => {
            for line in text.lines() {
                out.push_str(&format!("{pad}// {line}\n"));
            }
        }
    }
}

fn emit_stmt_body(out: &mut String, stmt: &CStmt, indent: usize) {
    match stmt {
        CStmt::Block(stmts) => {
            for s in stmts {
                emit_stmt(out, s, indent);
            }
        }
        other => emit_stmt(out, other, indent),
    }
}

fn emit_switch_cases(out: &mut String, cases: &[SwitchCase], indent: usize) {
    let pad = "    ".repeat(indent);
    for case in cases {
        out.push_str(&format!("{pad}{} => {{\n", emit_expr(&case.value, 0)));
        for s in &case.body {
            emit_stmt(out, s, indent + 1);
        }
        out.push_str(&format!("{pad}}},\n"));
    }
}

fn emit_expr(e: &CExpr, parent_prec: u8) -> String {
    let p = e.precedence();
    let s = match e {
        CExpr::IntLit(v) => format!("{v}_i64"),
        CExpr::UIntLit(v) => format!("0x{v:x}_u64"),
        CExpr::FloatLit(v) => format!("{v}_f64"),
        CExpr::StringLit(s) => format!("{s:?}"),
        CExpr::CharLit(c) => format!("'{c}'"),
        CExpr::Var(n) => sanitize_ident(n),
        CExpr::Unary { op, operand } => {
            let inner = emit_expr(operand, p);
            match op {
                UnaryOp::Not => format!("!{inner}"),
                UnaryOp::BitNot => format!("!{inner}"),
                UnaryOp::Neg => format!("-{inner}"),
                UnaryOp::PreInc => format!("{{ {inner} += 1; {inner} }}"),
                UnaryOp::PreDec => format!("{{ {inner} -= 1; {inner} }}"),
                UnaryOp::PostInc => format!("{{ let __t = {inner}; {inner} += 1; __t }}"),
                UnaryOp::PostDec => format!("{{ let __t = {inner}; {inner} -= 1; __t }}"),
            }
        }
        CExpr::Binary { op, left, right } => {
            let l = emit_expr(left, p);
            let r = emit_expr(right, p);
            let op_str = bin_op_str(*op);
            format!("{l} {op_str} {r}")
        }
        CExpr::Ternary { cond, then_expr, else_expr } => format!(
            "(if {} != 0 {{ {} }} else {{ {} }})",
            emit_expr(cond, 0),
            emit_expr(then_expr, 0),
            emit_expr(else_expr, 0)
        ),
        CExpr::Cast { ty, expr } => format!("({} as {})", emit_expr(expr, p), rust_ty(ty)),
        CExpr::Call { func, args } => {
            let f = emit_expr(func, p);
            let a: Vec<_> = args.iter().map(|a| emit_expr(a, 0)).collect();
            format!("{f}({})", a.join(", "))
        }
        CExpr::Subscript { base, index } => {
            format!("{}[{}]", emit_expr(base, p), emit_expr(index, 0))
        }
        CExpr::Member { base, member } => {
            format!("{}.{}", emit_expr(base, p), sanitize_ident(member))
        }
        CExpr::PtrMember { base, member } => {
            format!("(*{}).{}", emit_expr(base, p), sanitize_ident(member))
        }
        CExpr::Sizeof(e) => format!("size_of_val(&{})", emit_expr(e, 0)),
        CExpr::SizeofType(ty) => format!("size_of::<{}>()", rust_ty(ty)),
        CExpr::AddrOf(e) => format!("&{}", emit_expr(e, p)),
        CExpr::Deref(e) => format!("*{}", emit_expr(e, p)),
        CExpr::Comma(es) => {
            let parts: Vec<_> = es.iter().map(|x| emit_expr(x, 0)).collect();
            format!("({})", parts.join(", "))
        }
        CExpr::Paren(inner) => format!("({})", emit_expr(inner, 0)),
    };
    if p < parent_prec {
        format!("({s})")
    } else {
        s
    }
}

fn bin_op_str(op: BinaryOp) -> &'static str {
    match op {
        BinaryOp::Add => "+",
        BinaryOp::Sub => "-",
        BinaryOp::Mul => "*",
        BinaryOp::Div => "/",
        BinaryOp::Mod => "%",
        BinaryOp::BitAnd => "&",
        BinaryOp::BitOr => "|",
        BinaryOp::BitXor => "^",
        BinaryOp::Shl => "<<",
        BinaryOp::Shr => ">>",
        BinaryOp::Eq => "==",
        BinaryOp::Ne => "!=",
        BinaryOp::Lt => "<",
        BinaryOp::Le => "<=",
        BinaryOp::Gt => ">",
        BinaryOp::Ge => ">=",
        BinaryOp::And => "&&",
        BinaryOp::Or => "||",
        BinaryOp::Assign => "=",
        BinaryOp::AddAssign => "+=",
        BinaryOp::SubAssign => "-=",
        BinaryOp::MulAssign => "*=",
        BinaryOp::DivAssign => "/=",
        BinaryOp::ModAssign => "%=",
        BinaryOp::BitAndAssign => "&=",
        BinaryOp::BitOrAssign => "|=",
        BinaryOp::BitXorAssign => "^=",
        BinaryOp::ShlAssign => "<<=",
        BinaryOp::ShrAssign => ">>=",
    }
}

fn as_bool(e: &CExpr) -> String {
    match e {
        CExpr::Binary { op, .. }
            if matches!(
                op,
                BinaryOp::Eq
                    | BinaryOp::Ne
                    | BinaryOp::Lt
                    | BinaryOp::Le
                    | BinaryOp::Gt
                    | BinaryOp::Ge
                    | BinaryOp::And
                    | BinaryOp::Or
            ) =>
        {
            emit_expr(e, 0)
        }
        _ => format!("({} != 0)", emit_expr(e, 0)),
    }
}

fn rust_ty(ty: &CType) -> String {
    match ty {
        CType::Void => "()".to_string(),
        CType::Bool => "bool".to_string(),
        CType::Int(bits) => format!("i{bits}"),
        CType::UInt(bits) => format!("u{bits}"),
        CType::Float(32) => "f32".to_string(),
        CType::Float(64) => "f64".to_string(),
        CType::Float(bits) => format!("f{bits}"),
        CType::Pointer(inner) => format!("*mut {}", rust_ty(inner)),
        CType::Array(inner, Some(size)) => format!("[{}; {size}]", rust_ty(inner)),
        CType::Array(inner, None) => format!("[{}]", rust_ty(inner)),
        CType::Function { ret, params } => {
            let p: Vec<_> = params.iter().map(rust_ty).collect();
            format!("fn({}) -> {}", p.join(", "), rust_ty(ret))
        }
        CType::Struct(n) => sanitize_ident(n),
        CType::Union(n) => sanitize_ident(n),
        CType::Enum(n) => sanitize_ident(n),
        CType::Typedef(n) => sanitize_ident(n),
        CType::Unknown => "/* ? */ u64".to_string(),
    }
}

fn sanitize_ident(s: &str) -> String {
    if let Some(rest) = s.strip_prefix("ram:") {
        if rest.chars().all(|c| c.is_ascii_hexdigit()) {
            return format!("fn_{rest}");
        }
    }
    if let Some(rest) = s.strip_prefix("sub_") {
        if rest.chars().all(|c| c.is_ascii_hexdigit()) {
            return format!("fn_{rest}");
        }
    }
    s.replace(':', "_").replace('.', "_").replace('-', "_")
}
