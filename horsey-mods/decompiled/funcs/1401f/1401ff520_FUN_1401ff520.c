// Address: 0x1401ff520
// Ghidra name: FUN_1401ff520
// ============ 0x1401ff520 FUN_1401ff520 (size=653) ============


undefined8

FUN_1401ff520(longlong param_1,undefined8 param_2,ulonglong param_3,undefined4 param_4,

             undefined4 param_5,undefined4 param_6,int param_7,int param_8,longlong param_9,

             int param_10,undefined4 *param_11)



{

  int *piVar1;

  int iVar2;

  int iVar3;

  longlong lVar4;

  longlong lVar5;

  longlong lVar6;

  ulonglong uVar7;

  ulonglong uVar8;

  ulonglong uVar9;

  longlong lVar10;

  undefined8 local_70;

  undefined8 local_68;

  int local_60;

  undefined4 local_5c;

  undefined4 local_58;

  undefined4 local_54;

  undefined4 local_50;

  undefined4 local_4c;

  undefined4 local_48;

  int local_44;

  int local_40;

  undefined4 local_3c;

  undefined4 uVar11;

  

  lVar4 = FUN_1401fa4f0(param_3 & 0xffffffff,param_4);

  uVar8 = lVar4 * param_7;

  iVar2 = FUN_140200040(param_3 & 0xffffffff);

  FUN_1401f9dc0(param_1);

  lVar4 = (longlong)param_8;

  lVar5 = *(longlong *)(*(longlong *)(param_1 + 0x27d8) + (ulonglong)*(uint *)(param_1 + 0x690) * 8)

          + (longlong)

            *(int *)(*(longlong *)(param_1 + 0x27e0) + (ulonglong)*(uint *)(param_1 + 0x690) * 4) *

            0x20;

  lVar10 = lVar5;

  iVar3 = FUN_1401f58a0(param_1,lVar4 * uVar8,1,6,1,lVar5);

  uVar11 = (undefined4)((ulonglong)lVar10 >> 0x20);

  if (iVar3 == 0) {

    lVar6 = *(longlong *)(lVar5 + 0x18);

    uVar9 = (ulonglong)param_10;

    if (uVar8 - uVar9 == 0) {

      FUN_1402f8e20(lVar6,param_9,lVar4 * uVar8);

    }

    else {

      uVar7 = uVar9;

      if (uVar8 < uVar9) {

        uVar7 = uVar8;

      }

      for (; lVar4 != 0; lVar4 = lVar4 + -1) {

        FUN_1402f8e20(lVar6,param_9,uVar7);

        uVar11 = (undefined4)((ulonglong)lVar10 >> 0x20);

        param_9 = param_9 + uVar9;

        lVar6 = lVar6 + uVar7;

      }

    }

    FUN_1401fd560(param_1,0x19a0,0x1000,0x1480,0x1000,CONCAT44(uVar11,7),param_2,param_11);

    local_70 = 0;

    local_68 = 0;

    local_58 = 0;

    local_54 = 1;

    local_5c = 0;

    if (iVar2 < 2) {

      local_60 = 1;

    }

    else {

      local_60 = 0x10 << ((byte)param_4 & 0x1f);

    }

    local_50 = param_5;

    local_4c = param_6;

    local_44 = param_7;

    local_48 = 0;

    local_40 = param_8;

    local_3c = 1;

    (*DAT_1403fcef8)(*(undefined8 *)(param_1 + 0x698),*(undefined8 *)(lVar5 + 8),param_2,*param_11,1

                     ,&local_70);

    FUN_1401fd560(param_1,0x1000,0x20,0x1000,0x80,5,param_2,param_11);

    piVar1 = (int *)(*(longlong *)(param_1 + 0x27e0) + (ulonglong)*(uint *)(param_1 + 0x690) * 4);

    *piVar1 = *piVar1 + 1;

    if (*(int *)(*(longlong *)(param_1 + 0x27e0) + (ulonglong)*(uint *)(param_1 + 0x690) * 4) ==

        0x20) {

      FUN_1401fabf0(param_1);

    }

    return 1;

  }

  return 0;

}




