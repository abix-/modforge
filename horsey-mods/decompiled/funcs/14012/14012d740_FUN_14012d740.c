// Address: 0x14012d740
// Ghidra name: FUN_14012d740
// ============ 0x14012d740 FUN_14012d740 (size=563) ============


/* WARNING: Function: __chkstk replaced with injection: alloca_probe */



void FUN_14012d740(undefined8 param_1,undefined8 param_2,undefined4 param_3,char *param_4)



{

  BOOL BVar1;

  DWORD DVar2;

  char *pcVar3;

  size_t sVar4;

  size_t sVar5;

  ulonglong uVar6;

  undefined8 uVar7;

  LPCWSTR lpOutputString;

  wchar_t *pwVar8;

  undefined1 *puVar9;

  ulonglong uVar10;

  undefined1 auStack_48 [48];

  DWORD local_18;

  DWORD aDStack_14 [3];

  

  puVar9 = auStack_48;

  if (DAT_1403fb4f0 == 0) {

    BVar1 = AttachConsole(0xffffffff);

    if (BVar1 == 0) {

      DVar2 = GetLastError();

      if (DVar2 == 6) {

LAB_14012d7af:

        DAT_1403fb4f0 = -1;

      }

      else {

        if (DVar2 == 0x1f) {

          pwVar8 = L"Could not attach to console of parent process\r\n";

LAB_14012d7a9:

          OutputDebugStringW(pwVar8);

          goto LAB_14012d7af;

        }

        if (DVar2 != 5) {

          pwVar8 = L"Error attaching console\r\n";

          goto LAB_14012d7a9;

        }

        DAT_1403fb4f0 = 1;

      }

      if (DAT_1403fb4f0 != 1) goto LAB_14012d7f9;

    }

    else {

      DAT_1403fb4f0 = 1;

    }

    DAT_1403fb5c0 = GetStdHandle(0xfffffff4);

    BVar1 = GetConsoleMode(DAT_1403fb5c0,aDStack_14);

    if (BVar1 == 0) {

      DAT_1403fb4f0 = 2;

    }

  }

LAB_14012d7f9:

  pcVar3 = (char *)FUN_14012da90(param_3);

  sVar4 = strlen(pcVar3);

  sVar5 = strlen(param_4);

  uVar10 = sVar5 + 3 + sVar4;

  if (uVar10 < 0x80) {

    uVar6 = uVar10 + 0xf;

    if (uVar6 <= uVar10) {

      uVar6 = 0xffffffffffffff0;

    }

    puVar9 = auStack_48 + -(uVar6 & 0xfffffffffffffff0);

    pcVar3 = (char *)((longlong)&local_18 + -(uVar6 & 0xfffffffffffffff0));

  }

  else {

    pcVar3 = (char *)FUN_1401841f0(uVar10);

  }

  if (pcVar3 == (char *)0x0) {

    return;

  }

  *(undefined8 *)(puVar9 + -8) = 0x14012d866;

  uVar7 = FUN_14012da90(param_3);

  *(char **)(puVar9 + 0x20) = param_4;

  *(undefined8 *)(puVar9 + -8) = 0x14012d880;

  FUN_14012ef10(pcVar3,uVar10,"%s%s\r\n",uVar7);

  *(undefined8 *)(puVar9 + -8) = 0x14012d888;

  sVar4 = strlen(pcVar3);

  *(undefined8 *)(puVar9 + -8) = 0x14012d8a2;

  lpOutputString = (LPCWSTR)FUN_140197820("UTF-16LE",&DAT_14039c6f0,pcVar3,sVar4 + 1);

  *(undefined8 *)(puVar9 + -8) = 0x14012d8ae;

  OutputDebugStringW(lpOutputString);

  if (DAT_1403fb4f0 == 1) {

    *(undefined8 *)(puVar9 + -8) = 0x14012d8c1;

    DVar2 = FUN_14012fd40(lpOutputString);

    *(undefined8 *)(puVar9 + 0x20) = 0;

    *(undefined8 *)(puVar9 + -8) = 0x14012d8e1;

    BVar1 = WriteConsoleW(DAT_1403fb5c0,lpOutputString,DVar2,&local_18,*(LPVOID *)(puVar9 + 0x20));

    if (BVar1 != 0) goto LAB_14012d944;

    *(undefined8 *)(puVar9 + -8) = 0x14012d8f2;

    OutputDebugStringW(L"Error calling WriteConsole\r\n");

    *(undefined8 *)(puVar9 + -8) = 0x14012d8f8;

    DVar2 = GetLastError();

    if (DVar2 != 8) goto LAB_14012d944;

    pwVar8 = L"Insufficient heap memory to write message\r\n";

  }

  else {

    if (DAT_1403fb4f0 != 2) goto LAB_14012d944;

    *(undefined8 *)(puVar9 + -8) = 0x14012d913;

    sVar4 = strlen(pcVar3);

    *(undefined8 *)(puVar9 + 0x20) = 0;

    *(undefined8 *)(puVar9 + -8) = 0x14012d933;

    BVar1 = WriteFile(DAT_1403fb5c0,pcVar3,(DWORD)sVar4,&local_18,*(LPOVERLAPPED *)(puVar9 + 0x20));

    if (BVar1 != 0) goto LAB_14012d944;

    pwVar8 = L"Error calling WriteFile\r\n";

  }

  *(undefined8 *)(puVar9 + -8) = 0x14012d944;

  OutputDebugStringW(pwVar8);

LAB_14012d944:

  *(undefined8 *)(puVar9 + -8) = 0x14012d94c;

  FUN_1401841e0(lpOutputString);

  if (0x7f < uVar10) {

    *(undefined8 *)(puVar9 + -8) = 0x14012d95d;

    FUN_1401841e0(pcVar3);

  }

  return;

}




