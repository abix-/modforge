// Address: 0x140137800
// Ghidra name: FUN_140137800
// ============ 0x140137800 FUN_140137800 (size=69) ============


undefined8 FUN_140137800(int param_1)



{

  int iVar1;

  

  if (-1 < param_1) {

    iVar1 = FUN_140131d40();

    if (param_1 < iVar1) {

      return *(undefined8 *)(&PTR_PTR_1403ded10)[param_1];

    }

  }

  FUN_14012e850("Parameter \'%s\' is invalid","index");

  return 0;

}




