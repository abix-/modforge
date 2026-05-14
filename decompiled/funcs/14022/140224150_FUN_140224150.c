// Address: 0x140224150
// Ghidra name: FUN_140224150
// ============ 0x140224150 FUN_140224150 (size=504) ============


void FUN_140224150(longlong param_1,HIMC param_2,DWORD param_3)



{

  undefined2 *puVar1;

  ushort uVar2;

  int iVar3;

  uint uVar4;

  LONG LVar5;

  DWORD dwBufLen;

  undefined8 uVar6;

  LPVOID lpBuf;

  longlong lVar7;

  ulonglong uVar8;

  longlong lVar9;

  ulonglong uVar10;

  int iVar11;

  

  uVar2 = *(ushort *)(param_1 + 0x248);

  uVar4 = ImmGetCompositionStringW(param_2,0x80,(LPVOID)0x0,0);

  uVar8 = 0;

  *(uint *)(param_1 + 0x194) = uVar4 & 0xffff;

  *(undefined8 *)(param_1 + 0x198) = 0;

  LVar5 = ImmGetCompositionStringW(param_2,param_3,(LPVOID)0x0,0);

  if ((0 < LVar5) && (*(int *)(param_1 + 0x170) < LVar5)) {

    FUN_1401841e0(*(undefined8 *)(param_1 + 0x168));

    uVar6 = FUN_1401841f0((longlong)LVar5 + 2);

    *(undefined8 *)(param_1 + 0x168) = uVar6;

    *(LONG *)(param_1 + 0x170) = LVar5;

  }

  LVar5 = ImmGetCompositionStringW

                    (param_2,param_3,*(LPVOID *)(param_1 + 0x168),*(DWORD *)(param_1 + 0x170));

  iVar11 = 0;

  if (-1 < LVar5) {

    iVar11 = LVar5;

  }

  iVar11 = (int)((ulonglong)(longlong)iVar11 >> 1);

  if (((((uVar2 - 0x404 & 0xfffffbff) == 0) && (iVar3 = *(int *)(param_1 + 0x194), 0 < iVar3)) &&

      (iVar3 < (int)((ulonglong)(longlong)*(int *)(param_1 + 0x170) >> 1))) &&

     ((**(short **)(param_1 + 0x168) == 0x3000 || (**(short **)(param_1 + 0x168) == 0x20)))) {

    for (lVar9 = (longlong)(iVar3 + 1); lVar9 < iVar11; lVar9 = lVar9 + 1) {

      puVar1 = (undefined2 *)(*(longlong *)(param_1 + 0x168) + lVar9 * 2);

      puVar1[-1] = *puVar1;

    }

    iVar11 = iVar11 + -1;

  }

  *(undefined2 *)(*(longlong *)(param_1 + 0x168) + (longlong)iVar11 * 2) = 0;

  dwBufLen = ImmGetCompositionStringW(param_2,0x10,(LPVOID)0x0,0);

  if ((0 < (int)dwBufLen) &&

     (lpBuf = (LPVOID)FUN_1401841f0((longlong)(int)dwBufLen), lpBuf != (LPVOID)0x0)) {

    LVar5 = ImmGetCompositionStringW(param_2,0x10,lpBuf,dwBufLen);

    iVar11 = 0;

    if (-1 < LVar5) {

      iVar11 = LVar5;

    }

    lVar9 = (longlong)iVar11;

    uVar10 = uVar8;

    if (0 < iVar11) {

      do {

        if ((*(char *)((longlong)lpBuf + uVar8) - 1U & 0xfd) == 0) break;

        uVar10 = (ulonglong)((int)uVar10 + 1);

        uVar8 = uVar8 + 1;

      } while ((longlong)uVar8 < lVar9);

    }

    iVar11 = (int)uVar10;

    lVar7 = (longlong)iVar11;

    if (lVar7 < lVar9) {

      do {

        uVar4 = (uint)uVar10;

        if ((*(char *)((longlong)lpBuf + lVar7) - 1U & 0xfd) != 0) break;

        uVar4 = uVar4 + 1;

        uVar10 = (ulonglong)uVar4;

        lVar7 = lVar7 + 1;

      } while (lVar7 < lVar9);

      if (iVar11 < (int)uVar4) {

        *(int *)(param_1 + 0x198) = iVar11;

        *(uint *)(param_1 + 0x19c) = uVar4 - iVar11;

      }

    }

    FUN_1401841e0(lpBuf);

  }

  return;

}




