//! r2sleigh-spike: Phase 1-3 validation per
//! falcon-printer/docs/strategy.md.
//!
//! Pipeline:
//!   PE file (goblin)
//!     -> raw bytes for one function
//!     -> r2sleigh-lift              (Sleigh-based x86-64 lift)
//!     -> R2ILBlock
//!     -> r2ssa SSAFunction          (SSA + analyses)
//!     -> r2dec Decompiler::build_function -> CFunction (AST)
//!     -> our Rust emitter walks CFunction -> Rust pseudocode
//!
//! Goal: end-to-end proof that consuming r2sleigh as a library
//! and emitting our own Rust syntax produces output meaningfully
//! better than falcon-printer's current output.

use goblin::pe::PE;
use r2dec::ast::{BinaryOp, CExpr, CFunction, CStmt, CType, SwitchCase, UnaryOp};
use r2dec::{Decompiler, DecompilerConfig};
use r2sleigh_lift::disasm::Disassembler;
use r2sleigh_lift::sleigh::build_arch_spec;
use r2ssa::SSAFunction;
use std::env;
use std::fs;
use std::process::ExitCode;

fn main() -> ExitCode {
    let bin = env::args().nth(1).unwrap_or_else(|| {
        "/mnt/c/Games/Steam/steamapps/common/Horsey Game/Horsey.exe".to_string()
    });
    let addr_hex = env::args().nth(2).unwrap_or_else(|| "0x140089510".into());
    let size: usize = env::args()
        .nth(3)
        .and_then(|s| s.parse().ok())
        .unwrap_or(4096);
    // emit: "c" (default, r2dec output) or "rust"
    let emit = env::args().nth(4).unwrap_or_else(|| "rust".into());

    let addr = match u64::from_str_radix(addr_hex.trim_start_matches("0x"), 16) {
        Ok(a) => a,
        Err(e) => {
            eprintln!("bad addr {addr_hex}: {e}");
            return ExitCode::FAILURE;
        }
    };

    let result: Result<(), Box<dyn std::error::Error>> = (|| {
        let data = fs::read(&bin)?;
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
        let bytes = &data[file_offset..file_offset + size];

        eprintln!(
            "[spike] {} bytes @ 0x{addr:x} (file_offset 0x{file_offset:x}, section {})",
            bytes.len(),
            std::str::from_utf8(&section.name).unwrap_or("?"),
        );

        let arch_spec = build_arch_spec(
            sleigh_config::processor_x86::SLA_X86_64,
            sleigh_config::processor_x86::PSPEC_X86_64,
            "x86-64",
        )?;
        let disasm = Disassembler::from_sla(
            sleigh_config::processor_x86::SLA_X86_64,
            sleigh_config::processor_x86::PSPEC_X86_64,
            "x86-64",
        )?;

        let block = disasm.lift_block(bytes, addr, bytes.len())?;
        eprintln!("[spike] r2il block: {} ops", block.ops.len());

        let ssa = SSAFunction::from_blocks_for_decompile(&[block], Some(&arch_spec))
            .ok_or("SSAFunction::from_blocks_for_decompile returned None")?;
        eprintln!("[spike] SSA function: {} blocks", ssa.num_blocks());

        let dec = Decompiler::new(DecompilerConfig::default());
        let c_func = dec.build_function(&ssa);

        match emit.as_str() {
            "c" => println!("{}", r2dec::codegen::generate(&c_func)),
            "rust" => println!("{}", emit_rust(&c_func, addr)),
            other => return Err(format!("unknown emit mode: {other}").into()),
        }
        Ok(())
    })();

    match result {
        Ok(()) => ExitCode::SUCCESS,
        Err(e) => {
            eprintln!("error: {e}");
            ExitCode::FAILURE
        }
    }
}

// ---------------------------------------------------------------- Rust emitter

fn emit_rust(func: &CFunction, addr: u64) -> String {
    let mut out = String::new();
    out.push_str(&format!("// Decompiled from Horsey.exe @ 0x{addr:x}\n"));
    out.push_str("// Pipeline: r2sleigh (Sleigh lift -> SSA -> structurer) -> our Rust printer\n");
    out.push_str("\n");
    out.push_str("#[allow(non_snake_case, unused_assignments, unused_variables, unused_mut, dead_code, unused_parens)]\n");
    out.push_str(&format!("pub unsafe fn {}(", sanitize_ident(&func.name)));
    for (i, p) in func.params.iter().enumerate() {
        if i > 0 {
            out.push_str(", ");
        }
        out.push_str(&format!("{}: {}", sanitize_ident(&p.name), rust_ty(&p.ty)));
    }
    out.push_str(") {\n");

    // Locals (declared up front; the structurer hoists them).
    for local in &func.locals {
        out.push_str(&format!(
            "    let mut {}: {};\n",
            sanitize_ident(&local.name),
            rust_ty(&local.ty)
        ));
    }
    if !func.locals.is_empty() {
        out.push_str("\n");
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
            // Rust doesn't have do-while; emit as loop+break.
            out.push_str(&format!("{pad}loop {{  // do-while\n"));
            emit_stmt_body(out, body, indent + 1);
            out.push_str(&format!(
                "{pad}    if !({}) {{ break; }}\n",
                as_bool(cond)
            ));
            out.push_str(&format!("{pad}}}\n"));
        }
        CStmt::For { init, cond, update, body } => {
            // Rust for-loop expects iterator; emit as init+while.
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
                out.push_str(&format!(
                    "{}    {};\n",
                    pad,
                    emit_expr(u, 0)
                ));
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
                UnaryOp::BitNot => format!("!{inner}"),  // Rust uses ! for bitwise NOT on integers
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
        CExpr::Member { base, member } => format!("{}.{}", emit_expr(base, p), sanitize_ident(member)),
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
    // r2dec emits names like "ram:1400ca670" for direct addresses.
    // Map them to fn_<addr>-style identifiers.
    if let Some(rest) = s.strip_prefix("ram:") {
        if rest.chars().all(|c| c.is_ascii_hexdigit()) {
            return format!("fn_{rest}");
        }
    }
    // sub_140089510 -> fn_140089510
    if let Some(rest) = s.strip_prefix("sub_") {
        if rest.chars().all(|c| c.is_ascii_hexdigit()) {
            return format!("fn_{rest}");
        }
    }
    // Replace : and other non-ident chars.
    s.replace(':', "_").replace('.', "_").replace('-', "_")
}
