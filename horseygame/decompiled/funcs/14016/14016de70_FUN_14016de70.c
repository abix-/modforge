// Address: 0x14016de70
// Ghidra name: FUN_14016de70
// ============ 0x14016de70 FUN_14016de70 (size=69) ============


undefined8 FUN_14016de70(int param_1)



{

  int iVar1;

  

  if (-1 < param_1) {

    iVar1 = FUN_14016dad0();

    if (param_1 < iVar1) {

      return *(undefined8 *)(&DAT_1403fc420)[param_1];

    }

  }

  FUN_14012e850("Parameter \'%s\' is invalid","index");

  return 0;

}




