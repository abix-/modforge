// Address: 0x14022bff0
// Ghidra name: FUN_14022bff0
// ============ 0x14022bff0 FUN_14022bff0 (size=455) ============


/* WARNING: Function: __chkstk replaced with injection: alloca_probe */



undefined8 FUN_14022bff0(undefined8 param_1,longlong param_2,longlong param_3)



{

  int iVar1;

  longlong lVar2;

  HWND hWnd;

  longlong lVar3;

  HICON hIcon;

  int iVar4;

  DWORD DVar5;

  ulonglong uVar6;

  PBYTE presbits;

  HICON lParam;

  undefined8 uVar7;

  int iVar8;

  undefined1 *puVar9;

  PBYTE pBVar10;

  ulonglong uVar11;

  longlong lVar12;

  undefined1 auStack_58 [32];

  

  puVar9 = auStack_58;

  lVar2 = *(longlong *)(param_2 + 0x188);

  hWnd = *(HWND *)(lVar2 + 8);

  iVar4 = (*(int *)(param_3 + 8) + 7) * *(int *)(param_3 + 0xc);

  iVar4 = (int)(iVar4 + (iVar4 >> 0x1f & 7U)) >> 3;

  DVar5 = iVar4 + *(int *)(param_3 + 8) * *(int *)(param_3 + 0xc) * 4 + 0x28;

  uVar11 = (ulonglong)(int)DVar5;

  if (uVar11 < 0x80) {

    uVar6 = uVar11 + 0xf;

    if (uVar6 <= uVar11) {

      uVar6 = 0xffffffffffffff0;

    }

    puVar9 = auStack_58 + -(uVar6 & 0xfffffffffffffff0);

    presbits = &stack0xffffffffffffffc8 + -(uVar6 & 0xfffffffffffffff0);

  }

  else {

    presbits = (PBYTE)FUN_1401841f0();

  }

  if (presbits == (PBYTE)0x0) {

    uVar7 = 0;

  }

  else {

    presbits[0] = '(';

    presbits[1] = '\0';

    presbits[2] = '\0';

    presbits[3] = '\0';

    pBVar10 = presbits + 0x28;

    *(undefined4 *)(presbits + 4) = *(undefined4 *)(param_3 + 8);

    iVar8 = *(int *)(param_3 + 0xc);

    presbits[0xc] = '\x01';

    presbits[0xd] = '\0';

    presbits[0xe] = ' ';

    presbits[0xf] = '\0';

    presbits[0x10] = '\0';

    presbits[0x11] = '\0';

    presbits[0x12] = '\0';

    presbits[0x13] = '\0';

    *(int *)(presbits + 8) = iVar8 * 2;

    iVar8 = *(int *)(param_3 + 0xc);

    iVar1 = *(int *)(param_3 + 8);

    presbits[0x18] = '\0';

    presbits[0x19] = '\0';

    presbits[0x1a] = '\0';

    presbits[0x1b] = '\0';

    presbits[0x1c] = '\0';

    presbits[0x1d] = '\0';

    presbits[0x1e] = '\0';

    presbits[0x1f] = '\0';

    presbits[0x20] = '\0';

    presbits[0x21] = '\0';

    presbits[0x22] = '\0';

    presbits[0x23] = '\0';

    presbits[0x24] = '\0';

    presbits[0x25] = '\0';

    presbits[0x26] = '\0';

    presbits[0x27] = '\0';

    *(int *)(presbits + 0x14) = iVar8 * iVar1 * 4;

    iVar8 = *(int *)(param_3 + 0xc);

    if (iVar8 != 0) {

      lVar12 = (longlong)(*(int *)(param_3 + 8) << 2);

      do {

        iVar8 = iVar8 + -1;

        iVar1 = *(int *)(param_3 + 0x10);

        lVar3 = *(longlong *)(param_3 + 0x18);

        *(undefined8 *)(puVar9 + -8) = 0x14022c0fb;

        FUN_1402f8e20(pBVar10,iVar8 * iVar1 + lVar3,lVar12);

        pBVar10 = pBVar10 + lVar12;

      } while (iVar8 != 0);

    }

    *(undefined8 *)(puVar9 + -8) = 0x14022c11d;

    FUN_1402f94c0(presbits + (uVar11 - (longlong)iVar4),0xff);

    *(undefined8 *)(puVar9 + -8) = 0x14022c135;

    lParam = CreateIconFromResource(presbits,DVar5,1,0x30000);

    if (0x7f < uVar11) {

      *(undefined8 *)(puVar9 + -8) = 0x14022c149;

      FUN_1401841e0(presbits);

    }

    if (lParam == (HICON)0x0) {

      *(undefined8 *)(puVar9 + -8) = 0x14022c154;

      DVar5 = GetLastError();

      *(undefined8 *)(puVar9 + -8) = 0x14022c162;

      uVar7 = FUN_14012e850("SetWindowIcon() failed, error %08X",DVar5);

    }

    else {

      hIcon = *(HICON *)(lVar2 + 0x38);

      if (hIcon != (HICON)0x0) {

        *(undefined8 *)(puVar9 + -8) = 0x14022c173;

        DestroyIcon(hIcon);

      }

      *(HICON *)(lVar2 + 0x38) = lParam;

      *(undefined8 *)(puVar9 + -8) = 0x14022c18b;

      SendMessageW(hWnd,0x80,0,(LPARAM)lParam);

      *(undefined8 *)(puVar9 + -8) = 0x14022c1a2;

      SendMessageW(hWnd,0x80,1,(LPARAM)lParam);

      uVar7 = 1;

    }

  }

  return uVar7;

}




