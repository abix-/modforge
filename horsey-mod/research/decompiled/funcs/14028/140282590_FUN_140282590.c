// Address: 0x140282590
// Ghidra name: FUN_140282590
// ============ 0x140282590 FUN_140282590 (size=125) ============


void FUN_140282590(longlong param_1,undefined8 param_2,int param_3)



{

  int iVar1;

  undefined2 local_38;

  undefined1 local_36;

  undefined8 local_35;

  undefined8 uStack_2d;

  undefined8 local_25;

  undefined8 uStack_1d;

  undefined8 local_15;

  undefined4 local_d;

  undefined1 local_9;

  

  if (*(char *)(*(longlong *)(param_1 + 0x70) + 0xe) != '\0') {

    param_3 = param_3 + 1;

    if (param_3 < 0) {

      param_3 = 0;

    }

    else if (0xff < param_3) {

      param_3 = 0xff;

    }

    local_36 = (undefined1)param_3;

    *(undefined1 *)(*(longlong *)(param_1 + 0x70) + 0xd) = local_36;

    local_38 = 0x303;

    local_15 = 0;

    local_d = 0;

    local_9 = 0;

    local_35 = 0;

    uStack_2d = 0;

    local_25 = 0;

    uStack_1d = 0;

    iVar1 = FUN_140195730(*(undefined8 *)(param_1 + 0x80),&local_38,0x30);

    if (iVar1 < 0) {

      FUN_14012e850("SInput device player led command could not write");

    }

  }

  return;

}




