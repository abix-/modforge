// Address: 0x1401bd2d0
// Ghidra name: FUN_1401bd2d0
// ============ 0x1401bd2d0 FUN_1401bd2d0 (size=693) ============


void FUN_1401bd2d0(longlong param_1,longlong param_2,int param_3,int param_4,longlong *param_5)



{

  undefined8 uVar1;

  char *pcVar2;

  undefined8 uVar3;

  undefined4 local_58 [2];

  undefined8 local_50;

  undefined4 local_48;

  undefined4 local_44;

  undefined4 local_40;

  undefined4 local_3c;

  undefined8 local_38;

  undefined8 local_30;

  undefined4 local_28;

  undefined4 local_24;

  undefined4 local_20;

  undefined4 local_1c;

  undefined4 local_18;

  

  local_58[0] = 0x2d;

  local_50 = 0;

  local_38 = 0xffffffffffffffff;

  uVar3 = 0x1000;

  local_30 = *(undefined8 *)(*param_5 + 0x18);

  local_28 = *(undefined4 *)(*param_5 + 0x38);

  local_1c = (undefined4)param_5[1];

  local_24 = *(undefined4 *)((longlong)param_5 + 0xc);

  local_18 = 1;

  local_20 = 1;

  if (param_3 == 0) {

    uVar1 = 1;

    local_48 = 0;

    local_40 = 0;

  }

  else if (param_3 == 1) {

    uVar1 = 0x1000;

    local_48 = 0x800;

    local_40 = 6;

  }

  else if (param_3 == 2) {

    uVar1 = 0x1000;

    local_48 = 0x1000;

    local_40 = 7;

  }

  else if (param_3 == 3) {

    uVar1 = 0x88;

    local_48 = 0x20;

    local_40 = 5;

  }

  else if (param_3 == 4) {

    uVar1 = 0x88;

    local_48 = 0x20;

    local_40 = 1;

  }

  else if (param_3 == 5) {

    uVar1 = 0x800;

    local_48 = 0x20;

    local_40 = 1;

  }

  else if (param_3 == 6) {

    uVar1 = 0x800;

    local_48 = 0x60;

    local_40 = 1;

  }

  else if (param_3 == 7) {

    uVar1 = 0x400;

    local_48 = 0x100;

    local_40 = 2;

  }

  else {

    if (param_3 != 8) {

      pcVar2 = "Unrecognized texture source barrier type!";

      goto LAB_1401bd562;

    }

    uVar1 = 0x300;

    local_48 = 0x400;

    local_40 = 3;

  }

  if (param_4 == 1) {

    local_44 = 0x800;

    local_3c = 6;

  }

  else if (param_4 == 2) {

    local_44 = 0x1000;

    local_3c = 7;

  }

  else if (param_4 == 3) {

    uVar3 = 0x88;

    local_44 = 0x20;

    local_3c = 5;

  }

  else if (param_4 == 4) {

    uVar3 = 0x88;

    local_44 = 0x20;

    local_3c = 1;

  }

  else if (param_4 == 5) {

    uVar3 = 0x800;

    local_44 = 0x20;

    local_3c = 1;

  }

  else if (param_4 == 6) {

    uVar3 = 0x800;

    local_44 = 0x60;

    local_3c = 1;

  }

  else if (param_4 == 7) {

    uVar3 = 0x400;

    local_44 = 0x180;

    local_3c = 2;

  }

  else if (param_4 == 8) {

    uVar3 = 0x300;

    local_44 = 0x600;

    local_3c = 3;

  }

  else {

    if (param_4 != 9) {

      pcVar2 = "Unrecognized texture destination barrier type!";

LAB_1401bd562:

                    /* WARNING: Subroutine does not return */

      FUN_14012e0b0(9,pcVar2);

    }

    uVar3 = 0x2000;

    local_44 = 0;

    local_3c = 0x3b9acdea;

  }

  (**(code **)(param_1 + 0xab8))(*(undefined8 *)(param_2 + 0x118),uVar1,uVar3,0,0,0,0,0,1,local_58);

  return;

}




