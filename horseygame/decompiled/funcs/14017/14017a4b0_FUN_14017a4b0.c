// Address: 0x14017a4b0
// Ghidra name: FUN_14017a4b0
// ============ 0x14017a4b0 FUN_14017a4b0 (size=135) ============


undefined8 FUN_14017a4b0(uint param_1)



{

  undefined8 uVar1;

  uint uVar2;

  uint uVar3;

  

  uVar2 = (int)param_1 >> 0x1c & 0xf;

  if (param_1 == 0) {

    uVar3 = 0;

  }

  else {

    if (uVar2 != 1) {

      if (param_1 == 0x47504a4d) {

        return 0x120005a0;

      }

      if (param_1 == 0x30313050) {

        return 0x12002600;

      }

      return 0x211018c6;

    }

    uVar3 = (int)param_1 >> 0x18 & 0xf;

    if (uVar3 == 10) {

      return 0x12000500;

    }

  }

  if (uVar3 == 0xb) {

    return 0x12000500;

  }

  if (((param_1 == 0) || (uVar2 == 1)) && (((byte)(param_1 >> 0x18) & 0xf) == 6)) {

    uVar1 = 0x120005a0;

    if ((param_1 & 0xf0000) == 0x70000) {

      uVar1 = 0x12002600;

    }

    return uVar1;

  }

  return 0x120005a0;

}




