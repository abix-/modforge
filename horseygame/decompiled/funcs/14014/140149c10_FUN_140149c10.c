// Address: 0x140149c10
// Ghidra name: FUN_140149c10
// ============ 0x140149c10 FUN_140149c10 (size=220) ============


undefined8 FUN_140149c10(longlong param_1,undefined4 param_2,undefined4 param_3,uint param_4)



{

  undefined8 uVar1;

  undefined4 local_28;

  undefined4 local_24;

  undefined4 local_20;

  undefined4 local_1c;

  float local_18;

  float local_14;

  undefined4 local_10;

  undefined4 local_c;

  

  if ((0x5d < param_4 - 0x21) && (param_4 < 0xa1)) {

    return CONCAT71((uint7)(uint3)(param_4 - 0x21 >> 8),1);

  }

  if (param_4 < 0xbe) {

    if (param_4 < 0x7f) {

      param_4 = param_4 - 0x21;

    }

    else {

      param_4 = param_4 - 0x43;

    }

  }

  else {

    param_4 = 0xbd;

  }

  local_10 = 0x41000000;

  local_c = 0x41000000;

  local_20 = 0x41000000;

  local_1c = 0x41000000;

  local_18 = (float)((param_4 % 0xe) * 10 + 1);

  local_14 = (float)((param_4 / 0xe) * 10 + 1);

  local_28 = param_2;

  local_24 = param_3;

  uVar1 = FUN_140153570(param_1,*(undefined8 *)(param_1 + 0x2d0),&local_18,&local_28);

  return uVar1;

}




