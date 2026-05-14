// Address: 0x140205530
// Ghidra name: FUN_140205530
// ============ 0x140205530 FUN_140205530 (size=324) ============


longlong FUN_140205530(longlong param_1,int param_2,int param_3,int param_4,int param_5)



{

  longlong lVar1;

  ulonglong uVar2;

  ulonglong uVar3;

  longlong lVar4;

  int iVar5;

  undefined8 local_48;

  undefined8 uStack_40;

  undefined8 local_38;

  undefined8 uStack_30;

  undefined8 local_28;

  undefined8 uStack_20;

  undefined4 local_18;

  

  iVar5 = 0;

  if (param_2 != 0x13000801) {

    iVar5 = param_3;

  }

  uVar2 = 0;

  if (param_4 == 2) {

    uVar2 = 2;

  }

  uVar3 = 0;

  if (param_5 == 2) {

    uVar3 = 4;

  }

  lVar1 = param_1 + (iVar5 == 0 | uVar2 | uVar3) * 8;

  lVar4 = *(longlong *)(lVar1 + 0x118);

  if (lVar4 == 0) {

    local_18 = 0;

    local_48 = 0;

    uStack_40 = 0;

    local_38 = 0;

    uStack_30 = 0;

    local_28 = 0;

    uStack_20 = 0;

    if (iVar5 != 0) {

      if ((iVar5 != 1) && (iVar5 != 2)) {

        FUN_14012e850("Unknown scale mode: %d",iVar5);

        return 0;

      }

      local_48 = 0x100000001;

      uStack_40 = 1;

    }

    if (param_4 == 1) {

      uStack_40 = CONCAT44(2,(undefined4)uStack_40);

    }

    else if (param_4 != 2) {

      FUN_14012e850("Unknown texture address mode: %d",param_4);

      return 0;

    }

    if (param_5 == 1) {

      local_38._0_4_ = 2;

    }

    else {

      if (param_5 != 2) {

        FUN_14012e850("Unknown texture address mode: %d",param_5);

        return 0;

      }

      local_38._0_4_ = 0;

    }

    local_38 = CONCAT44(2,(undefined4)local_38);

    lVar4 = FUN_140135380(*(undefined8 *)(param_1 + 8),&local_48);

    *(longlong *)(lVar1 + 0x118) = lVar4;

  }

  return lVar4;

}




