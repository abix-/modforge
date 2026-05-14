// Address: 0x14021dad0
// Ghidra name: FUN_14021dad0
// ============ 0x14021dad0 FUN_14021dad0 (size=2317) ============


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



ulonglong FUN_14021dad0(longlong param_1,undefined4 param_2)



{

  bool bVar1;

  char cVar2;

  int iVar3;

  int iVar4;

  int iVar5;

  BOOL BVar6;

  char *pcVar7;

  undefined8 uVar8;

  char *_Str;

  LPPROCESS_INFORMATION lpProcessInformation;

  ulonglong uVar9;

  size_t sVar10;

  HANDLE pvVar11;

  HANDLE pvVar12;

  HANDLE pvVar13;

  HANDLE pvVar14;

  HANDLE pvVar15;

  LPWSTR pWVar16;

  byte bVar17;

  DWORD local_res20 [2];

  LPWSTR local_138;

  HANDLE local_130;

  HANDLE pvStack_128;

  HANDLE local_120;

  HANDLE pvStack_118;

  HANDLE local_110;

  HANDLE pvStack_108;

  DWORD local_100;

  longlong local_f8;

  LPVOID local_f0;

  LPCWSTR local_e8;

  _SECURITY_ATTRIBUTES local_e0;

  _STARTUPINFOW local_c8;

  undefined8 local_58;

  

  local_58 = FUN_140174d30(param_2,"SDL.process.create.args",0);

  pcVar7 = (char *)FUN_140174e70(param_2,"SDL.process.create.cmdline",0);

  uVar8 = FUN_140179430();

  local_f8 = FUN_140174d30(param_2,"SDL.process.create.environment",uVar8);

  _Str = (char *)FUN_140174e70(param_2,"SDL.process.create.working_directory",0);

  iVar3 = FUN_140174c40(param_2,"SDL.process.create.stdin_option",1);

  iVar4 = FUN_140174c40(param_2,"SDL.process.create.stdout_option",0);

  iVar5 = FUN_140174c40(param_2,"SDL.process.create.stderr_option",0);

  cVar2 = FUN_1401749e0(param_2,"SDL.process.create.stderr_to_stdout",0);

  if (cVar2 == '\0') {

LAB_14021dbcb:

    bVar1 = false;

  }

  else {

    cVar2 = FUN_140174fc0(param_2,"SDL.process.create.stderr_option");

    bVar1 = true;

    if (cVar2 != '\0') goto LAB_14021dbcb;

  }

  pvVar12 = _UNK_14033ad68;

  pvVar11 = _DAT_14033ad60;

  local_138 = (LPWSTR)0x0;

  local_f0 = (LPVOID)0x0;

  local_e8 = (LPCWSTR)0x0;

  local_130 = _DAT_14033ad60;

  pvStack_128 = _UNK_14033ad68;

  local_res20[0] = 1;

  local_120 = _DAT_14033ad60;

  pvStack_118 = _UNK_14033ad68;

  local_110 = _DAT_14033ad60;

  pvStack_108 = _UNK_14033ad68;

  local_f8 = FUN_140179360(local_f8);

  uVar9 = 0;

  if (local_f8 == 0) {

LAB_14021dc38:

    return uVar9 & 0xffffffffffffff00;

  }

  lpProcessInformation = (LPPROCESS_INFORMATION)FUN_1401841a0(1,0x18);

  if (lpProcessInformation == (LPPROCESS_INFORMATION)0x0) {

    uVar9 = FUN_1401841e0(local_f8);

    goto LAB_14021dc38;

  }

  *(LPPROCESS_INFORMATION *)(param_1 + 0x10) = lpProcessInformation;

  lpProcessInformation->hProcess = (HANDLE)0xffffffffffffffff;

  lpProcessInformation->hThread = (HANDLE)0xffffffffffffffff;

  local_c8._68_8_ = 0;

  local_c8.lpReserved2._4_4_ = 0;

  local_c8.dwYCountChars = 0;

  local_c8.dwFillAttribute = 0;

  local_100 = 0x400;

  local_c8._4_8_ = 0;

  local_c8._12_8_ = 0;

  local_c8.cb = 0x68;

  local_c8._20_8_ = 0;

  local_c8._28_8_ = 0;

  local_c8.hStdError = (HANDLE)0xffffffffffffffff;

  local_c8.dwY = 0;

  local_c8.dwXSize = 0;

  local_c8.dwYSize = 0;

  local_c8.dwXCountChars = 0;

  local_e0.nLength = 0x18;

  local_e0._4_4_ = 0;

  local_c8.hStdInput = pvVar11;

  local_c8.hStdOutput = pvVar12;

  local_e0.bInheritHandle = 1;

  local_e0._20_4_ = 0;

  local_c8.dwFlags = 0x100;

  local_c8.wShowWindow = 0;

  local_c8.cbReserved2 = 0;

  local_e0.lpSecurityDescriptor = (LPVOID)0x0;

  if (pcVar7 == (char *)0x0) {

    cVar2 = FUN_14021e800(local_58,&local_138);

    pWVar16 = local_138;

    if (cVar2 != '\0') goto LAB_14021dd06;

  }

  else {

    sVar10 = strlen(pcVar7);

    local_138 = (LPWSTR)FUN_140197820("UTF-16LE",&DAT_14039c6f0,pcVar7,sVar10 + 1);

    pWVar16 = local_138;

    if (local_138 != (LPWSTR)0x0) {

LAB_14021dd06:

      cVar2 = FUN_14021eb50(local_f8,&local_f0);

      pWVar16 = local_138;

      if (cVar2 != '\0') {

        if (_Str != (char *)0x0) {

          sVar10 = strlen(_Str);

          local_e8 = (LPCWSTR)FUN_140197820("UTF-16LE",&DAT_14039c6f0,_Str,sVar10 + 1);

          pWVar16 = local_138;

          if (local_e8 == (LPCWSTR)0x0) goto LAB_14021e2e2;

        }

        if (*(char *)(param_1 + 1) != '\0') {

          local_100 = 0x8000400;

          if (iVar3 == 0) {

            iVar3 = 1;

          }

          if (iVar4 == 0) {

            iVar4 = 1;

          }

          if (iVar5 == 0) {

            iVar5 = 1;

          }

        }

        if (iVar3 == 0) {

LAB_14021df16:

          pvVar15 = GetStdHandle(0xfffffff6);

          if (pvVar15 == (HANDLE)0x0) {

            pvVar15 = (HANDLE)0x0;

LAB_14021de2d:

            local_c8.hStdInput = pvVar15;

            if (iVar4 == 0) {

LAB_14021e03b:

              pvVar15 = GetStdHandle(0xfffffff5);

              if (pvVar15 == (HANDLE)0x0) {

                local_c8.hStdOutput = (HANDLE)0x0;

              }

              else {

                pvVar13 = GetCurrentProcess();

                pvVar14 = GetCurrentProcess();

                BVar6 = DuplicateHandle(pvVar14,pvVar15,pvVar13,&local_c8.hStdOutput,0,1,2);

                if (BVar6 == 0) {

                  local_c8.hStdOutput = (HANDLE)0xffffffffffffffff;

                  pcVar7 = "DuplicateHandle()";

                  goto LAB_14021e2d8;

                }

              }

            }

            else {

              if (iVar4 != 1) {

                if (iVar4 == 2) {

                  BVar6 = CreatePipe(&local_120,&pvStack_118,&local_e0,0);

                  if (BVar6 != 0) {

                    BVar6 = SetNamedPipeHandleState(local_120,local_res20,(LPDWORD)0x0,(LPDWORD)0x0)

                    ;

                    if (BVar6 == 0) goto LAB_14021e2d1;

                    BVar6 = SetHandleInformation(local_120,1,0);

                    if (BVar6 == 0) {

                      pcVar7 = "SetHandleInformation()";

                      goto LAB_14021e2d8;

                    }

                    local_c8.hStdOutput = pvStack_118;

                    goto LAB_14021de75;

                  }

                  local_120 = pvVar11;

                  pvStack_118 = pvVar12;

                  pWVar16 = local_138;

                }

                else {

                  if (iVar4 != 3) goto LAB_14021e03b;

                  cVar2 = FUN_14021e5d0(param_2,"SDL.process.create.stdout_source",

                                        &local_c8.hStdOutput);

                  pWVar16 = local_138;

                  if (cVar2 != '\0') goto LAB_14021de75;

                }

                goto LAB_14021e2e2;

              }

              local_c8.hStdOutput =

                   CreateFileW(L"\\\\.\\NUL",0xc0000000,0,&local_e0,3,0,(HANDLE)0x0);

            }

LAB_14021de75:

            pvVar15 = local_c8.hStdOutput;

            if (bVar1) {

joined_r0x00014021e1fe:

              if (pvVar15 == (HANDLE)0x0) {

                local_c8.hStdError = (HANDLE)0x0;

                pvVar11 = local_c8.hStdError;

              }

              else {

                pvVar11 = GetCurrentProcess();

                pvVar12 = GetCurrentProcess();

                BVar6 = DuplicateHandle(pvVar12,pvVar15,pvVar11,&local_c8.hStdError,0,1,2);

                pvVar11 = local_c8.hStdError;

                if (BVar6 == 0) {

                  local_c8.hStdError = (HANDLE)0xffffffffffffffff;

                  pcVar7 = "DuplicateHandle()";

                  goto LAB_14021e2d8;

                }

              }

            }

            else {

              if (iVar5 == 0) {

LAB_14021e1ed:

                pvVar15 = GetStdHandle(0xfffffff4);

                goto joined_r0x00014021e1fe;

              }

              if (iVar5 != 1) {

                if (iVar5 == 2) {

                  BVar6 = CreatePipe(&local_110,&pvStack_108,&local_e0,0);

                  if (BVar6 != 0) {

                    BVar6 = SetNamedPipeHandleState(local_110,local_res20,(LPDWORD)0x0,(LPDWORD)0x0)

                    ;

                    if (BVar6 == 0) goto LAB_14021e2d1;

                    BVar6 = SetHandleInformation(local_110,1,0);

                    pvVar11 = pvStack_108;

                    if (BVar6 == 0) {

                      pcVar7 = "SetHandleInformation()";

                      goto LAB_14021e2d8;

                    }

                    goto LAB_14021e164;

                  }

                  local_110 = pvVar11;

                  pvStack_108 = pvVar12;

                  pWVar16 = local_138;

                }

                else {

                  if (iVar5 != 3) goto LAB_14021e1ed;

                  cVar2 = FUN_14021e5d0(param_2,"SDL.process.create.stderr_source",

                                        &local_c8.hStdError);

                  pWVar16 = local_138;

                  pvVar11 = local_c8.hStdError;

                  if (cVar2 != '\0') goto LAB_14021e164;

                }

                goto LAB_14021e2e2;

              }

              pvVar11 = CreateFileW(L"\\\\.\\NUL",0xc0000000,0,&local_e0,3,0,(HANDLE)0x0);

            }

LAB_14021e164:

            local_c8.hStdError = pvVar11;

            pWVar16 = local_138;

            BVar6 = CreateProcessW((LPCWSTR)0x0,local_138,(LPSECURITY_ATTRIBUTES)0x0,

                                   (LPSECURITY_ATTRIBUTES)0x0,1,local_100,local_f0,local_e8,

                                   &local_c8,lpProcessInformation);

            if (BVar6 != 0) {

              FUN_140175360(*(undefined4 *)(param_1 + 8),"SDL.process.pid",

                            lpProcessInformation->dwProcessId);

              if ((iVar3 == 2) &&

                 (cVar2 = FUN_14021e710(param_1,pvStack_128,&DAT_14030a390,"SDL.process.stdin"),

                 cVar2 == '\0')) {

                CloseHandle(pvStack_128);

                pvStack_128 = (HANDLE)0xffffffffffffffff;

              }

              if ((iVar4 == 2) &&

                 (cVar2 = FUN_14021e710(param_1,local_120,&DAT_14039be7c,"SDL.process.stdout"),

                 cVar2 == '\0')) {

                CloseHandle(local_120);

                local_120 = (HANDLE)0xffffffffffffffff;

              }

              if ((iVar5 == 2) &&

                 (cVar2 = FUN_14021e710(param_1,local_110,&DAT_14039be7c,"SDL.process.stderr"),

                 cVar2 == '\0')) {

                CloseHandle(local_110);

                local_110 = (HANDLE)0xffffffffffffffff;

              }

              bVar17 = 1;

              goto LAB_14021e2e5;

            }

            FUN_1401a9ed0("CreateProcess");

            goto LAB_14021e2e2;

          }

          pvVar13 = GetCurrentProcess();

          pvVar14 = GetCurrentProcess();

          BVar6 = DuplicateHandle(pvVar14,pvVar15,pvVar13,&local_c8.hStdInput,0,1,2);

          pvVar15 = local_c8.hStdInput;

          if (BVar6 != 0) goto LAB_14021de2d;

          local_c8.hStdInput = (HANDLE)0xffffffffffffffff;

          pcVar7 = "DuplicateHandle()";

        }

        else {

          if (iVar3 == 1) {

            pvVar15 = CreateFileW(L"\\\\.\\NUL",0xc0000000,0,&local_e0,3,0,(HANDLE)0x0);

            goto LAB_14021de2d;

          }

          if (iVar3 != 2) {

            if (iVar3 != 3) goto LAB_14021df16;

            cVar2 = FUN_14021e5d0(param_2,"SDL.process.create.stdin_source",&local_c8.hStdInput);

            pWVar16 = local_138;

            pvVar15 = local_c8.hStdInput;

            if (cVar2 != '\0') goto LAB_14021de2d;

            goto LAB_14021e2e2;

          }

          BVar6 = CreatePipe(&local_130,&pvStack_128,&local_e0,0);

          if (BVar6 == 0) {

            local_130 = pvVar11;

            pvStack_128 = pvVar12;

            pWVar16 = local_138;

            goto LAB_14021e2e2;

          }

          BVar6 = SetNamedPipeHandleState(pvStack_128,local_res20,(LPDWORD)0x0,(LPDWORD)0x0);

          if (BVar6 != 0) {

            BVar6 = SetHandleInformation(pvStack_128,1,0);

            pvVar15 = local_130;

            if (BVar6 != 0) goto LAB_14021de2d;

            pcVar7 = "SetHandleInformation()";

            goto LAB_14021e2d8;

          }

LAB_14021e2d1:

          pcVar7 = "SetNamedPipeHandleState()";

        }

LAB_14021e2d8:

        FUN_1401a9ed0(pcVar7);

        pWVar16 = local_138;

      }

    }

  }

LAB_14021e2e2:

  bVar17 = 0;

LAB_14021e2e5:

  if ((local_c8.hStdInput != (HANDLE)0xffffffffffffffff) && (local_c8.hStdInput != local_130)) {

    CloseHandle(local_c8.hStdInput);

  }

  if ((local_c8.hStdOutput != (HANDLE)0xffffffffffffffff) && (local_c8.hStdOutput != pvStack_118)) {

    CloseHandle(local_c8.hStdOutput);

  }

  if ((local_c8.hStdError != (HANDLE)0xffffffffffffffff) && (local_c8.hStdError != pvStack_108)) {

    CloseHandle(local_c8.hStdError);

  }

  if (local_130 != (HANDLE)0xffffffffffffffff) {

    CloseHandle(local_130);

  }

  if (pvStack_118 != (HANDLE)0xffffffffffffffff) {

    CloseHandle(pvStack_118);

  }

  if (pvStack_108 != (HANDLE)0xffffffffffffffff) {

    CloseHandle(pvStack_108);

  }

  FUN_1401841e0(pWVar16);

  FUN_1401841e0(local_f0);

  FUN_1401841e0(local_e8);

  FUN_1401841e0(local_f8);

  if (bVar17 == 0) {

    if (pvStack_128 != (HANDLE)0xffffffffffffffff) {

      CloseHandle(pvStack_128);

    }

    if (local_120 != (HANDLE)0xffffffffffffffff) {

      CloseHandle(local_120);

    }

    if (local_110 != (HANDLE)0xffffffffffffffff) {

      CloseHandle(local_110);

    }

  }

  return (ulonglong)bVar17;

}




