// Better Backpack DLL injector.
//
// Walks the process list, finds Grounded 2 (Steam or Xbox Game Pass build),
// opens it, and pokes LoadLibraryA via CreateRemoteThread to map our DLL.
//
// Pattern lifted from x0reaxeax/Grounded2Minimal Injector/main.c (MIT) -- the
// canonical pattern for this game family. We add: dual-build detection, an
// optional argv[1] DLL path, slightly clearer errors.
//
// Default DLL path: <inject.exe directory>\BetterBackpack.dll.
//
// Usage:
//   inject.exe                       (default DLL next to the injector)
//   inject.exe path\to\Other.dll     (override)

#include <Windows.h>
#include <TlHelp32.h>

#include <stdio.h>
#include <string.h>

static const char* const TARGET_PROCESSES[] = {
    "Grounded2-WinGRTS-Shipping.exe",   // Steam
    "Grounded2-WinGDK-Shipping.exe",    // Xbox Game Pass
    NULL,
};

static DWORD FindTargetPid(const char** outMatchedName) {
    HANDLE hSnap = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
    if (hSnap == INVALID_HANDLE_VALUE) {
        fprintf(stderr, "[-] CreateToolhelp32Snapshot failed: E%lu\n", GetLastError());
        return 0;
    }
    PROCESSENTRY32 entry = { .dwSize = sizeof(entry) };
    if (!Process32First(hSnap, &entry)) {
        fprintf(stderr, "[-] Process32First failed: E%lu\n", GetLastError());
        CloseHandle(hSnap);
        return 0;
    }
    DWORD pid = 0;
    do {
        for (int i = 0; TARGET_PROCESSES[i]; ++i) {
            if (_stricmp(entry.szExeFile, TARGET_PROCESSES[i]) == 0) {
                pid = entry.th32ProcessID;
                if (outMatchedName) *outMatchedName = TARGET_PROCESSES[i];
                goto done;
            }
        }
    } while (Process32Next(hSnap, &entry));
done:
    CloseHandle(hSnap);
    return pid;
}

static int ResolveDllPath(int argc, char** argv, char* out, DWORD outSize) {
    if (argc >= 2) {
        DWORD n = GetFullPathNameA(argv[1], outSize, out, NULL);
        if (n == 0 || n >= outSize) {
            fprintf(stderr, "[-] GetFullPathNameA failed for '%s': E%lu\n",
                    argv[1], GetLastError());
            return 0;
        }
    } else {
        // Default to BetterBackpack.dll in the injector's own directory.
        char exePath[MAX_PATH];
        DWORD n = GetModuleFileNameA(NULL, exePath, sizeof(exePath));
        if (n == 0 || n >= sizeof(exePath)) {
            fprintf(stderr, "[-] GetModuleFileNameA failed: E%lu\n", GetLastError());
            return 0;
        }
        char* lastSlash = strrchr(exePath, '\\');
        if (!lastSlash) {
            fprintf(stderr, "[-] could not parse exe path: %s\n", exePath);
            return 0;
        }
        *lastSlash = 0;
        if (_snprintf_s(out, outSize, _TRUNCATE,
                        "%s\\BetterBackpack.dll", exePath) < 0) {
            fprintf(stderr, "[-] DLL path too long\n");
            return 0;
        }
    }
    HANDLE h = CreateFileA(out, GENERIC_READ, FILE_SHARE_READ, NULL,
                           OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
    if (h == INVALID_HANDLE_VALUE) {
        fprintf(stderr, "[-] DLL not found: '%s' (E%lu)\n", out, GetLastError());
        return 0;
    }
    CloseHandle(h);
    return 1;
}

int main(int argc, char** argv) {
    char dllPath[MAX_PATH * 2] = { 0 };
    if (!ResolveDllPath(argc, argv, dllPath, sizeof(dllPath))) {
        return 1;
    }
    printf("[+] DLL: %s\n", dllPath);

    const char* matched = NULL;
    DWORD pid = FindTargetPid(&matched);
    if (pid == 0) {
        fprintf(stderr, "[-] Grounded 2 not running. Looking for:\n");
        for (int i = 0; TARGET_PROCESSES[i]; ++i) {
            fprintf(stderr, "      %s\n", TARGET_PROCESSES[i]);
        }
        fprintf(stderr, "    Launch the game and load a save first.\n");
        return 2;
    }
    printf("[+] target: %s (PID %lu)\n", matched, pid);

    HANDLE hProc = OpenProcess(
        PROCESS_VM_OPERATION | PROCESS_VM_READ | PROCESS_VM_WRITE | PROCESS_CREATE_THREAD,
        FALSE, pid);
    if (!hProc) {
        DWORD err = GetLastError();
        fprintf(stderr, "[-] OpenProcess failed: E%lu", err);
        if (err == ERROR_ACCESS_DENIED) {
            fprintf(stderr, " (try running this exe as Administrator)");
        }
        fprintf(stderr, "\n");
        return 3;
    }

    SIZE_T pathLen = strlen(dllPath) + 1;
    LPVOID remoteBuf = VirtualAllocEx(hProc, NULL, pathLen,
                                      MEM_COMMIT | MEM_RESERVE, PAGE_READWRITE);
    if (!remoteBuf) {
        fprintf(stderr, "[-] VirtualAllocEx failed: E%lu\n", GetLastError());
        CloseHandle(hProc);
        return 4;
    }

    SIZE_T written = 0;
    if (!WriteProcessMemory(hProc, remoteBuf, dllPath, pathLen, &written) ||
        written != pathLen) {
        fprintf(stderr, "[-] WriteProcessMemory failed: E%lu (wrote %zu/%zu)\n",
                GetLastError(), written, pathLen);
        VirtualFreeEx(hProc, remoteBuf, 0, MEM_RELEASE);
        CloseHandle(hProc);
        return 5;
    }

    HMODULE k32 = GetModuleHandleA("kernel32.dll");
    FARPROC pLoadLibrary = k32 ? GetProcAddress(k32, "LoadLibraryA") : NULL;
    if (!pLoadLibrary) {
        fprintf(stderr, "[-] GetProcAddress(LoadLibraryA) failed: E%lu\n", GetLastError());
        VirtualFreeEx(hProc, remoteBuf, 0, MEM_RELEASE);
        CloseHandle(hProc);
        return 6;
    }

    HANDLE hThread = CreateRemoteThread(
        hProc, NULL, 0,
        (LPTHREAD_START_ROUTINE)pLoadLibrary, remoteBuf, 0, NULL);
    if (!hThread) {
        fprintf(stderr, "[-] CreateRemoteThread failed: E%lu\n", GetLastError());
        VirtualFreeEx(hProc, remoteBuf, 0, MEM_RELEASE);
        CloseHandle(hProc);
        return 7;
    }

    printf("[+] LoadLibraryA fired in target process; waiting...\n");
    WaitForSingleObject(hThread, 5000);

    DWORD threadExit = 0;
    GetExitCodeThread(hThread, &threadExit);
    if (threadExit == 0) {
        fprintf(stderr, "[!] LoadLibraryA returned 0 in target process.\n");
        fprintf(stderr, "    The DLL probably failed to load -- bitness mismatch,\n");
        fprintf(stderr, "    missing dependency, or unhandled exception in DllMain.\n");
    } else {
        printf("[+] DLL mapped at HMODULE 0x%lx in target process.\n", threadExit);
        printf("    Look for the new console window or %%TEMP%%\\BetterBackpack.log\n");
    }

    CloseHandle(hThread);
    VirtualFreeEx(hProc, remoteBuf, 0, MEM_RELEASE);
    CloseHandle(hProc);
    return threadExit == 0 ? 8 : 0;
}
