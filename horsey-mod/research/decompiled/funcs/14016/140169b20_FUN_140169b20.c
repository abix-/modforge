// Address: 0x140169b20
// Ghidra name: FUN_140169b20
// ============ 0x140169b20 FUN_140169b20 (size=142) ============


void FUN_140169b20(longlong param_1,ulonglong param_2)



{

  if ((*(uint *)(param_1 + 0x48) & 0xc0000) == 0) {

    if ((param_2 & 0xc0) == 0) {

      FUN_140170180();

    }

    if ((char)param_2 < '\0') {

      FUN_14016f2a0(param_1);

    }

    FUN_140170cc0(param_1,param_2 & 1);

    if ((param_2 & 0x40) != 0) {

      FUN_14016f4f0(param_1);

    }

    if ((param_2 >> 0xc & 1) != 0) {

      FUN_1401714d0(param_1,1);

    }

    if ((param_2 >> 8 & 1) != 0) {

      FUN_140171600(param_1,1);

    }

    if ((param_2 >> 0x14 & 1) != 0) {

      FUN_1401710d0(param_1,1);

    }

  }

  return;

}




