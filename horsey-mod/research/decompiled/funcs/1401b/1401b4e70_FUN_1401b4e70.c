// Address: 0x1401b4e70
// Ghidra name: FUN_1401b4e70
// ============ 0x1401b4e70 FUN_1401b4e70 (size=470) ============


void FUN_1401b4e70(longlong param_1,longlong param_2,int param_3,int param_4,longlong param_5)



{

  undefined8 uVar1;

  char *pcVar2;

  undefined4 uVar3;

  undefined4 local_48 [2];

  undefined8 local_40;

  undefined4 local_38;

  undefined4 local_34;

  undefined8 local_30;

  undefined8 local_28;

  undefined8 local_20;

  undefined8 local_18;

  

  local_48[0] = 0x2c;

  local_40 = 0;

  local_30 = 0xffffffffffffffff;

  uVar3 = 0x1000;

  local_28 = *(undefined8 *)(param_5 + 0x10);

  local_18 = *(undefined8 *)(param_5 + 0x28);

  local_20 = 0;

  if (param_3 == 0) {

    uVar1 = 0x1000;

    local_38 = 0x800;

  }

  else if (param_3 == 1) {

    uVar1 = 0x1000;

    local_38 = 0x1000;

  }

  else if (param_3 == 2) {

    uVar1 = 4;

    local_38 = 4;

  }

  else if (param_3 == 3) {

    uVar1 = 4;

    local_38 = 2;

  }

  else if (param_3 == 4) {

    uVar1 = 2;

    local_38 = 1;

  }

  else if (param_3 == 5) {

    uVar1 = 0x88;

    local_38 = 0x20;

  }

  else {

    if (param_3 == 6) {

      local_38 = 0x20;

    }

    else {

      if (param_3 != 7) {

        pcVar2 = "Unrecognized buffer source barrier type!";

        goto LAB_1401b5027;

      }

      local_38 = 0x60;

    }

    uVar1 = 0x800;

  }

  if (param_4 == 0) {

    local_34 = 0x800;

  }

  else {

    local_34 = uVar3;

    if (param_4 != 1) {

      if (param_4 == 2) {

        local_34 = 4;

        uVar3 = local_34;

      }

      else if (param_4 == 3) {

        local_34 = 2;

        uVar3 = 4;

      }

      else if (param_4 == 4) {

        local_34 = 1;

        uVar3 = 2;

      }

      else if (param_4 == 5) {

        local_34 = 0x20;

        uVar3 = 0x88;

      }

      else {

        if (param_4 == 6) {

          local_34 = 0x20;

        }

        else {

          if (param_4 != 7) {

            pcVar2 = "Unrecognized buffer destination barrier type!";

LAB_1401b5027:

                    /* WARNING: Subroutine does not return */

            FUN_14012e0b0(9,pcVar2);

          }

          local_34 = 0x60;

        }

        uVar3 = 0x800;

      }

    }

  }

  (**(code **)(param_1 + 0xab8))(*(undefined8 *)(param_2 + 0x118),uVar1,uVar3,0,0,0,1,local_48,0,0);

  *(undefined1 *)(param_5 + 0x34) = 1;

  return;

}




