// Address: 0x1402f8380
// Ghidra name: FUN_1402f8380
// ============ 0x1402f8380 FUN_1402f8380 (size=398) ============


undefined4 FUN_1402f8380(ulonglong param_1,longlong param_2,longlong param_3)



{

  undefined4 uVar1;

  int iVar2;

  BOOL BVar3;

  DWORD DVar4;

  longlong lVar5;

  longlong lVar6;

  HANDLE hFile;

  ulonglong uVar7;

  undefined4 uVar8;

  ulonglong uVar9;

  ulonglong uVar10;

  

  uVar10 = param_1 & 0xffffffff;

  lVar5 = FUN_1402eb16c(param_1,0,1);

  lVar6 = FUN_1402eb16c(uVar10,0,2);

  uVar7 = param_2 - lVar6;

  if ((lVar5 == -1) || (lVar6 == -1)) {

    if (*(char *)(param_3 + 0x30) == '\0') {

      uVar1 = 0x16;

      goto LAB_1402f84df;

    }

  }

  else {

    uVar8 = 0;

    if (0 < (longlong)uVar7) {

      lVar6 = _calloc_base(0x1000,1);

      if (lVar6 == 0) {

        uVar8 = 0xc;

        *(undefined1 *)(param_3 + 0x30) = 1;

        *(undefined4 *)(param_3 + 0x2c) = 0xc;

      }

      else {

        uVar1 = FUN_1402e7f2c(param_1 & 0xffffffff,0x8000);

        do {

          uVar9 = uVar7 & 0xffffffff;

          if (0xfff < (longlong)uVar7) {

            uVar9 = 0x1000;

          }

          iVar2 = FUN_1402ee62c(uVar10,lVar6,uVar9,param_3);

          if (iVar2 == -1) {

            if ((*(char *)(param_3 + 0x38) != '\0') && (*(int *)(param_3 + 0x34) == 5)) {

              *(undefined1 *)(param_3 + 0x30) = 1;

              *(undefined4 *)(param_3 + 0x2c) = 0xd;

            }

            if (*(char *)(param_3 + 0x30) != '\0') {

              uVar8 = *(undefined4 *)(param_3 + 0x2c);

            }

            goto LAB_1402f8471;

          }

          uVar7 = uVar7 - (longlong)iVar2;

        } while (0 < (longlong)uVar7);

        FUN_1402e7f2c(uVar10,uVar1);

      }

LAB_1402f8471:

      FUN_1402e9a80(lVar6);

      uVar1 = uVar8;

      goto LAB_1402f84df;

    }

    uVar1 = 0;

    if (-1 < (longlong)uVar7) goto LAB_1402f84df;

    lVar6 = FUN_1402eb16c(param_1 & 0xffffffff,param_2,0);

    uVar1 = uVar8;

    if (lVar6 != -1) {

      hFile = (HANDLE)FUN_1402f4f90(param_1 & 0xffffffff);

      BVar3 = SetEndOfFile(hFile);

      if (BVar3 == 0) {

        DVar4 = GetLastError();

        *(undefined1 *)(param_3 + 0x38) = 1;

        uVar1 = 0xd;

        *(DWORD *)(param_3 + 0x34) = DVar4;

        *(undefined1 *)(param_3 + 0x30) = 1;

        *(undefined4 *)(param_3 + 0x2c) = 0xd;

      }

      goto LAB_1402f84df;

    }

    if (*(char *)(param_3 + 0x30) == '\0') goto LAB_1402f84df;

  }

  uVar1 = *(undefined4 *)(param_3 + 0x2c);

LAB_1402f84df:

  FUN_1402eb16c(uVar10,lVar5,0);

  return uVar1;

}




