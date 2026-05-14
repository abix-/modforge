// Address: 0x1401e7f40
// Ghidra name: FUN_1401e7f40
// ============ 0x1401e7f40 FUN_1401e7f40 (size=342) ============


longlong FUN_1401e7f40(longlong param_1,int param_2,int param_3,int param_4,int param_5)



{

  ulonglong uVar1;

  ulonglong uVar2;

  int iVar3;

  undefined8 local_48;

  undefined4 local_40;

  undefined8 local_3c;

  undefined8 local_34;

  undefined8 local_2c;

  undefined8 uStack_24;

  undefined4 local_1c;

  undefined4 local_18;

  

  uVar2 = 0;

  iVar3 = 0;

  if (param_2 != 0x13000801) {

    iVar3 = param_3;

  }

  uVar1 = uVar2;

  if (param_4 == 2) {

    uVar1 = 2;

  }

  if (param_5 == 2) {

    uVar2 = 4;

  }

  uVar2 = iVar3 == 0 | uVar1 | uVar2;

  if (*(char *)(uVar2 + 0x2150 + param_1) == '\0') {

    local_48 = 0;

    local_40 = 0;

    local_3c = 3;

    local_34 = 1;

    local_1c = 0;

    local_18 = 0x7f7fffff;

    local_2c = 0;

    uStack_24 = 0;

    if (iVar3 != 0) {

      if ((iVar3 != 1) && (iVar3 != 2)) {

        FUN_14012e850("Unknown scale mode: %d",iVar3);

        return 0;

      }

      local_48 = 0x15;

    }

    if (param_4 == 1) {

      local_48 = CONCAT44(3,(undefined4)local_48);

    }

    else {

      if (param_4 != 2) goto LAB_1401e8015;

      local_48 = CONCAT44(1,(undefined4)local_48);

    }

    if (param_5 == 1) {

      local_40 = 3;

    }

    else {

      param_4 = param_5;

      if (param_5 != 2) {

LAB_1401e8015:

        FUN_14012e850("Unknown texture address mode: %d",param_4);

        return 0;

      }

      local_40 = 1;

    }

    (**(code **)(**(longlong **)(param_1 + 0x30) + 0xb0))

              (*(longlong **)(param_1 + 0x30),&local_48,

               *(undefined8 *)(param_1 + 0x2110 + uVar2 * 8));

    *(undefined1 *)(uVar2 + 0x2150 + param_1) = 1;

  }

  return param_1 + 0x2110 + uVar2 * 8;

}




