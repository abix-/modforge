"""Decompile every function in Horsey.exe using pyghidra. Dump to files."""
import os
import sys
import time
from pathlib import Path

os.environ.setdefault("GHIDRA_INSTALL_DIR", r"C:\code\ghidra_12.1_PUBLIC")
os.environ.setdefault("JAVA_HOME", r"C:\Program Files\Microsoft\jdk-21.0.11.10-hotspot")

import pyghidra

EXE = Path(r"C:/Games/Steam/steamapps/common/Horsey Game/Horsey.exe")
OUT_DIR = Path(r"C:/code/horsey-mods/decompiled")
PROJECT_DIR = Path(r"C:/code/horsey-mods/ghidra-project")

OUT_DIR.mkdir(exist_ok=True)
PROJECT_DIR.mkdir(exist_ok=True)


def main():
    print(f"Starting pyghidra. exe={EXE} project={PROJECT_DIR}")
    print(f"GHIDRA_INSTALL_DIR={os.environ.get('GHIDRA_INSTALL_DIR')}")
    print(f"JAVA_HOME={os.environ.get('JAVA_HOME')}")
    print()

    t0 = time.time()
    pyghidra.start()
    print(f"pyghidra.start() took {time.time()-t0:.1f}s")

    from ghidra.app.decompiler import DecompInterface
    from ghidra.util.task import ConsoleTaskMonitor

    with pyghidra.open_program(
        str(EXE),
        project_location=str(PROJECT_DIR),
        project_name="horsey",
        analyze=True,
    ) as flat_api:
        program = flat_api.getCurrentProgram()
        print(f"Program: {program.getName()}")
        print(f"Architecture: {program.getLanguage().getProcessor()}")
        print(f"Image base: 0x{program.getImageBase().getOffset():x}")
        print(f"Memory size: {program.getMemory().getSize()} bytes")

        funcs = list(program.getFunctionManager().getFunctions(True))
        print(f"Total functions: {len(funcs)}")

        # Set up decompiler
        decomp = DecompInterface()
        decomp.openProgram(program)
        monitor = ConsoleTaskMonitor()

        # Index file: function name, address, size, signature
        index_path = OUT_DIR / "INDEX.md"
        index_lines = ["# Horsey.exe function index", ""]
        index_lines.append(f"Total functions: {len(funcs)}")
        index_lines.append(f"Generated: {time.strftime('%Y-%m-%d %H:%M:%S')}")
        index_lines.append("")
        index_lines.append("| Address | Name | Body size | Signature |")
        index_lines.append("|---|---|---|---|")

        n_decomp = 0
        n_skipped = 0
        n_failed = 0
        t1 = time.time()

        # Write all decompiled functions to one big file (sorted by address) + the index
        all_decomp_path = OUT_DIR / "all_functions.c"
        with all_decomp_path.open("w", encoding="utf-8") as outf:
            outf.write(f"// Decompiled from Horsey.exe by pyghidra-{pyghidra.__version__}\n")
            outf.write(f"// {len(funcs)} functions\n\n")

            for i, func in enumerate(funcs):
                addr = func.getEntryPoint().getOffset()
                name = func.getName()
                body_size = func.getBody().getNumAddresses()
                sig = str(func.getSignature())

                index_lines.append(f"| 0x{addr:x} | `{name}` | {body_size} | `{sig}` |")

                # Decompile with 30s timeout
                result = decomp.decompileFunction(func, 30, monitor)
                if result is None or not result.decompileCompleted():
                    err = result.getErrorMessage() if result else "no result"
                    outf.write(f"\n// ============ 0x{addr:x} {name} ============\n")
                    outf.write(f"// DECOMPILATION FAILED: {err}\n")
                    n_failed += 1
                else:
                    code = result.getDecompiledFunction().getC()
                    outf.write(f"\n// ============ 0x{addr:x} {name} (size={body_size}) ============\n")
                    outf.write(code)
                    n_decomp += 1

                if (i + 1) % 50 == 0:
                    elapsed = time.time() - t1
                    rate = (i + 1) / elapsed
                    eta = (len(funcs) - i - 1) / rate
                    print(f"  [{i+1}/{len(funcs)}] decomp={n_decomp} fail={n_failed}  "
                          f"rate={rate:.1f}/s  eta={eta:.0f}s")

        with index_path.open("w", encoding="utf-8") as f:
            f.write("\n".join(index_lines))

        elapsed = time.time() - t1
        print()
        print(f"DONE. Decompiled {n_decomp}/{len(funcs)} functions in {elapsed:.0f}s")
        print(f"  successful: {n_decomp}")
        print(f"  failed: {n_failed}")
        print(f"  output: {all_decomp_path}")
        print(f"  index: {index_path}")


if __name__ == "__main__":
    main()
