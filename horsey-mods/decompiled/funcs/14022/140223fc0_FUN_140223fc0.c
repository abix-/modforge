// Address: 0x140223fc0
// Ghidra name: FUN_140223fc0
// ============ 0x140223fc0 FUN_140223fc0 (size=395) ============


void FUN_140223fc0(longlong param_1,HWND param_2)



{

  bool bVar1;

  bool bVar2;

  char cVar3;

  DWORD DVar4;

  int iVar5;

  HIMC pHVar6;

  LPCANDIDATELIST lpCandList;

  longlong lVar7;

  uint uVar8;

  uint uVar9;

  uint uVar10;

  ulonglong uVar11;

  

  bVar2 = false;

  pHVar6 = ImmGetContext(param_2);

  if (pHVar6 != (HIMC)0x0) {

    DVar4 = ImmGetCandidateListW(pHVar6,0,(LPCANDIDATELIST)0x0,0);

    bVar1 = false;

    if ((DVar4 != 0) &&

       (lpCandList = (LPCANDIDATELIST)FUN_1401841f0(DVar4), bVar1 = bVar2,

       lpCandList != (LPCANDIDATELIST)0x0)) {

      DVar4 = ImmGetCandidateListW(pHVar6,0,lpCandList,DVar4);

      if ((DVar4 != 0) && (cVar3 = FUN_140224af0(param_1), cVar3 != '\0')) {

        *(DWORD *)(param_1 + 0x200) = lpCandList->dwSelection;

        uVar8 = 0;

        if ((*(short *)(param_1 + 0x248) == 0x804) && (iVar5 = FUN_140224350(), iVar5 != 0)) {

          uVar9 = 0;

          uVar11 = 0;

          if (lpCandList->dwCount != 0) {

            do {

              lVar7 = FUN_14012fd40((longlong)lpCandList->dwOffset +

                                    ((ulonglong)lpCandList->dwOffset[uVar9] - 0x18));

              uVar11 = lVar7 + 1U + uVar11;

              uVar10 = uVar8;

              if ((0x12 < uVar11) &&

                 (uVar11 = lVar7 + 1U, uVar10 = uVar9, lpCandList->dwSelection < uVar9)) break;

              uVar8 = uVar10;

              uVar9 = uVar9 + 1;

            } while (uVar9 < lpCandList->dwCount);

          }

          uVar9 = uVar9 - uVar8;

        }

        else {

          uVar9 = lpCandList->dwPageSize;

          if ((uVar9 == 0) || (9 < uVar9)) {

            uVar9 = 10;

          }

          uVar8 = lpCandList->dwSelection - lpCandList->dwSelection % uVar9;

        }

        uVar10 = uVar8;

        if (uVar8 < lpCandList->dwCount) {

          do {

            if (uVar9 <= uVar10 - uVar8) break;

            FUN_140223d00(param_1,uVar10 - uVar8,

                          (longlong)lpCandList->dwOffset +

                          ((ulonglong)lpCandList->dwOffset[uVar10] - 0x18));

            uVar10 = uVar10 + 1;

          } while (uVar10 < lpCandList->dwCount);

        }

        bVar1 = true;

        FUN_140224be0(param_1);

      }

      FUN_1401841e0(lpCandList);

    }

    ImmReleaseContext(param_2,pHVar6);

    if (bVar1) {

      return;

    }

  }

  FUN_140223e80(param_1);

  return;

}




