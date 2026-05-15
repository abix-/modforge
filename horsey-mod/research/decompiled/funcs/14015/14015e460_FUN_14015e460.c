// Address: 0x14015e460
// Ghidra name: FUN_14015e460
// ============ 0x14015e460 FUN_14015e460 (size=69) ============


undefined8 FUN_14015e460(int param_1)



{

  int iVar1;

  

  if (-1 < param_1) {

    iVar1 = FUN_14015e690();

    if (param_1 < iVar1) {

      return *(undefined8 *)(&DAT_1403fc178)[param_1];

    }

  }

  FUN_14012e850("Parameter \'%s\' is invalid","index");

  return 0;

}




