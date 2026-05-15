// Address: 0x1401318e0
// Ghidra name: FUN_1401318e0
// ============ 0x1401318e0 FUN_1401318e0 (size=69) ============


undefined8 FUN_1401318e0(int param_1)



{

  int iVar1;

  

  if (-1 < param_1) {

    iVar1 = FUN_140131d40();

    if (param_1 < iVar1) {

      return *(undefined8 *)(&PTR_PTR_140317600)[param_1];

    }

  }

  FUN_14012e850("Parameter \'%s\' is invalid","index");

  return 0;

}




