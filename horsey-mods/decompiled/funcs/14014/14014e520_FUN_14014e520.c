// Address: 0x14014e520
// Ghidra name: FUN_14014e520
// ============ 0x14014e520 FUN_14014e520 (size=70) ============


undefined8 FUN_14014e520(int param_1)



{

  int iVar1;

  

  if (-1 < param_1) {

    iVar1 = FUN_14014e160();

    if (param_1 < iVar1) {

      return *(undefined8 *)((&PTR_PTR_1403e1d60)[param_1] + 8);

    }

  }

  FUN_14012e850("Parameter \'%s\' is invalid","index");

  return 0;

}




