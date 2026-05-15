// Address: 0x1401f6480
// Ghidra name: FUN_1401f6480
// ============ 0x1401f6480 FUN_1401f6480 (size=234) ============


void FUN_1401f6480(longlong param_1,int param_2,undefined4 *param_3)



{

  longlong lVar1;

  undefined4 local_58;

  undefined4 uStack_54;

  undefined4 uStack_50;

  undefined4 uStack_4c;

  undefined8 local_48;

  undefined8 local_40;

  undefined8 local_38;

  undefined8 local_30;

  undefined8 local_28;

  undefined4 local_20;

  undefined4 local_1c;

  uint local_18;

  undefined4 local_14;

  undefined4 *puStack_10;

  

  lVar1 = *(longlong *)(param_1 + 0x28f8);

  local_20 = *(undefined4 *)(param_1 + 0x2888);

  local_1c = *(undefined4 *)(param_1 + 0x288c);

  if (lVar1 != 0) {

    local_20 = *(undefined4 *)(lVar1 + 0x70);

    local_1c = *(undefined4 *)(lVar1 + 0x74);

  }

  if ((param_2 == 0) || (param_2 != 1)) {

    if (lVar1 == 0) {

      local_38 = *(undefined8 *)(param_1 + 0x700);

    }

    else {

      local_38 = *(undefined8 *)(lVar1 + 0x28);

    }

  }

  else if (lVar1 == 0) {

    local_38 = *(undefined8 *)(param_1 + 0x708);

  }

  else {

    local_38 = *(undefined8 *)(lVar1 + 0x30);

  }

  *(undefined8 *)(param_1 + 0x710) = local_38;

  if (lVar1 == 0) {

    local_30 = *(undefined8 *)

                (*(longlong *)(param_1 + 0x6f8) + (ulonglong)*(uint *)(param_1 + 0x28c8) * 8);

  }

  else {

    local_30 = *(undefined8 *)(lVar1 + 0x38);

  }

  local_48 = 0x2b;

  local_14 = 0;

  puStack_10 = (undefined4 *)0x0;

  local_40 = 0;

  local_28 = 0;

  local_18 = (uint)(param_3 != (undefined4 *)0x0);

  if (param_3 != (undefined4 *)0x0) {

    local_58 = *param_3;

    uStack_54 = param_3[1];

    uStack_50 = param_3[2];

    uStack_4c = param_3[3];

    puStack_10 = &local_58;

  }

  (*DAT_1403fced0)(*(undefined8 *)(param_1 + 0x698),&local_48,0);

  return;

}




