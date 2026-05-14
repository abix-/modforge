// Address: 0x14027ead0
// Ghidra name: FUN_14027ead0
// ============ 0x14027ead0 FUN_14027ead0 (size=54) ============


undefined1 * FUN_14027ead0(int param_1)



{

  int *piVar1;

  uint uVar2;

  

  uVar2 = 0;

  piVar1 = &DAT_1403e66b8;

  do {

    if (*piVar1 == param_1) {

      return (&PTR_s_Logitech_G29_1403e66d0)[(int)uVar2];

    }

    uVar2 = uVar2 + 1;

    piVar1 = piVar1 + 1;

  } while (uVar2 < 6);

  return &DAT_14039bcb9;

}




