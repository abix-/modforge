// Address: 0x1401e2330
// Ghidra name: FUN_1401e2330
// ============ 0x1401e2330 FUN_1401e2330 (size=381) ============


undefined8 FUN_1401e2330(longlong param_1,int param_2,int param_3,int param_4,int param_5)



{

  longlong lVar1;

  int iVar2;

  ulonglong uVar3;

  ulonglong uVar4;

  undefined8 local_48;

  undefined4 local_40;

  undefined8 local_3c;

  undefined4 local_34;

  undefined4 local_30;

  undefined8 local_2c;

  undefined8 uStack_24;

  undefined4 local_1c;

  undefined4 local_18;

  

  iVar2 = 0;

  if (param_2 != 0x13000801) {

    iVar2 = param_3;

  }

  uVar3 = 0;

  if (param_4 == 2) {

    uVar3 = 2;

  }

  uVar4 = 0;

  if (param_5 == 2) {

    uVar4 = 4;

  }

  lVar1 = param_1 + (iVar2 == 0 | uVar3 | uVar4) * 8;

  if (*(longlong *)(lVar1 + 0x118) == 0) {

    local_48 = 0;

    local_40 = 0;

    local_3c = 3;

    local_34 = 1;

    local_30 = 8;

    local_1c = 0;

    local_18 = 0x7f7fffff;

    local_2c = 0;

    uStack_24 = 0;

    if (iVar2 != 0) {

      if ((iVar2 != 1) && (iVar2 != 2)) {

        FUN_14012e850("Unknown scale mode: %d",iVar2);

        return 0;

      }

      local_48 = 0x15;

    }

    if (param_4 == 1) {

      local_48 = CONCAT44(3,(undefined4)local_48);

    }

    else {

      if (param_4 != 2) {

        FUN_14012e850("Unknown texture address mode: %d",param_4);

        return 0;

      }

      local_48 = CONCAT44(1,(undefined4)local_48);

    }

    if (param_5 == 1) {

      local_40 = 3;

    }

    else {

      if (param_5 != 2) {

        FUN_14012e850("Unknown texture address mode: %d",param_5);

        return 0;

      }

      local_40 = 1;

    }

    iVar2 = (**(code **)(**(longlong **)(param_1 + 0x20) + 0xb8))

                      (*(longlong **)(param_1 + 0x20),&local_48,lVar1 + 0x118);

    if (iVar2 < 0) {

      FUN_1401a9ef0("ID3D11Device::CreateSamplerState",iVar2);

      return 0;

    }

  }

  return *(undefined8 *)(lVar1 + 0x118);

}




