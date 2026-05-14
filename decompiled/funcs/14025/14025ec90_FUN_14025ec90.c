// Address: 0x14025ec90
// Ghidra name: FUN_14025ec90
// ============ 0x14025ec90 FUN_14025ec90 (size=852) ============


void FUN_14025ec90(longlong param_1,int param_2,int param_3,int param_4,int param_5,

                  undefined4 param_6,char param_7)



{

  bool bVar1;

  uint uVar2;

  longlong lVar3;

  int iVar4;

  int iVar5;

  uint uVar6;

  undefined1 *puVar7;

  int iVar8;

  longlong lVar9;

  uint uVar10;

  int iVar11;

  uint uVar12;

  ulonglong uVar13;

  longlong lVar14;

  uint uVar15;

  

  lVar14 = (longlong)param_2;

  if (param_3 == param_5) {

    lVar9 = (longlong)

            ((*(int *)(param_1 + 0x10) / (int)(uint)*(byte *)(*(longlong *)(param_1 + 0x38) + 5)) *

            param_3);

    if (param_4 < param_2) {

      lVar9 = lVar9 + *(longlong *)(param_1 + 0x18) + (longlong)param_4;

      lVar14 = lVar9 + 1;

      if (param_7 != '\0') {

        lVar14 = lVar9;

      }

      param_2 = param_2 - param_4;

      if (param_7 != '\0') {

        param_2 = param_2 + 1;

      }

      FUN_1402f94c0(lVar14,param_6,(longlong)param_2);

      return;

    }

    iVar5 = (param_4 - param_2) + 1;

    if (param_7 == '\0') {

      iVar5 = param_4 - param_2;

    }

    FUN_1402f94c0(*(longlong *)(param_1 + 0x18) + lVar14 + lVar9,param_6,(longlong)iVar5);

    return;

  }

  if (param_2 == param_4) {

    iVar5 = *(int *)(param_1 + 0x10) / (int)(uint)*(byte *)(*(longlong *)(param_1 + 0x38) + 5);

    if (param_5 < param_3) {

      puVar7 = (undefined1 *)((longlong)(iVar5 * param_5) + *(longlong *)(param_1 + 0x18) + lVar14);

      if (param_7 == '\0') {

        puVar7 = puVar7 + iVar5;

        iVar11 = param_3 - param_5;

      }

      else {

        iVar11 = (param_3 - param_5) + 1;

      }

    }

    else {

      puVar7 = (undefined1 *)((longlong)(iVar5 * param_3) + *(longlong *)(param_1 + 0x18) + lVar14);

      iVar11 = (param_5 - param_3) + 1;

      if (param_7 == '\0') {

        iVar11 = param_5 - param_3;

      }

    }

    if (iVar11 != 0) {

      do {

        *puVar7 = (undefined1)param_6;

        puVar7 = puVar7 + iVar5;

        iVar11 = iVar11 + -1;

      } while (iVar11 != 0);

      return;

    }

  }

  else {

    iVar11 = param_3 - param_5;

    iVar5 = -(param_2 - param_4);

    if (iVar5 < 0) {

      iVar5 = param_2 - param_4;

    }

    iVar8 = -iVar11;

    if (-iVar11 < 0) {

      iVar8 = iVar11;

    }

    if (iVar5 == iVar8) {

      iVar5 = *(int *)(param_1 + 0x10) / (int)(uint)*(byte *)(*(longlong *)(param_1 + 0x38) + 5);

      if (param_5 < param_3) {

        puVar7 = (undefined1 *)

                 ((longlong)(iVar5 * param_5) + *(longlong *)(param_1 + 0x18) + (longlong)param_4);

        iVar8 = 1;

        if (param_2 < param_4) {

          iVar8 = -1;

        }

        iVar8 = iVar8 + iVar5;

        if (param_7 == '\0') {

          puVar7 = puVar7 + iVar8;

        }

      }

      else {

        iVar11 = param_5 - param_3;

        puVar7 = (undefined1 *)

                 ((longlong)(iVar5 * param_3) + *(longlong *)(param_1 + 0x18) + lVar14);

        iVar8 = 1;

        if (param_4 < param_2) {

          iVar8 = -1;

        }

        iVar8 = iVar8 + iVar5;

      }

      iVar5 = iVar11 + 1;

      if (param_7 == '\0') {

        iVar5 = iVar11;

      }

      if (iVar5 != 0) {

        do {

          *puVar7 = (undefined1)param_6;

          puVar7 = puVar7 + iVar8;

          iVar5 = iVar5 + -1;

        } while (iVar5 != 0);

      }

    }

    else {

      uVar10 = -(param_4 - param_2);

      if ((int)uVar10 < 0) {

        uVar10 = param_4 - param_2;

      }

      uVar12 = -(param_5 - param_3);

      if ((int)uVar12 < 0) {

        uVar12 = param_5 - param_3;

      }

      bVar1 = (int)uVar10 < (int)uVar12;

      if (bVar1) {

        iVar5 = uVar10 * 2;

        iVar11 = iVar5 - uVar12;

        iVar8 = uVar10 - uVar12;

      }

      else {

        iVar5 = uVar12 * 2;

        iVar11 = iVar5 - uVar10;

        iVar8 = uVar12 - uVar10;

        uVar12 = uVar10;

      }

      lVar9 = -1;

      uVar10 = -(uint)!bVar1;

      if (param_2 <= param_4) {

        uVar10 = (uint)!bVar1;

      }

      uVar2 = -(uint)bVar1;

      if (param_3 <= param_5) {

        uVar2 = (uint)bVar1;

      }

      uVar15 = 0xffffffff;

      if (param_3 <= param_5) {

        uVar15 = 1;

      }

      uVar6 = uVar12 + 1;

      if (param_7 == '\0') {

        uVar6 = uVar12;

      }

      if (0 < (int)uVar6) {

        uVar13 = (ulonglong)uVar6;

        if (param_2 <= param_4) {

          lVar9 = 1;

        }

        do {

          *(undefined1 *)

           ((longlong)(param_3 * *(int *)(param_1 + 0x10)) + *(longlong *)(param_1 + 0x18) + lVar14)

               = (undefined1)param_6;

          lVar3 = lVar9;

          uVar12 = uVar15;

          iVar4 = iVar8 * 2;

          if (iVar11 < 0) {

            lVar3 = (longlong)(int)uVar10;

            uVar12 = uVar2;

            iVar4 = iVar5;

          }

          iVar11 = iVar11 + iVar4;

          param_3 = param_3 + uVar12;

          lVar14 = lVar14 + lVar3;

          uVar13 = uVar13 - 1;

        } while (uVar13 != 0);

      }

    }

  }

  return;

}




