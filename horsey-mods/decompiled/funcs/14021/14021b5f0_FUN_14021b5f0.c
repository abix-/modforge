// Address: 0x14021b5f0
// Ghidra name: FUN_14021b5f0
// ============ 0x14021b5f0 FUN_14021b5f0 (size=137) ============


undefined8 FUN_14021b5f0(undefined8 param_1,undefined8 param_2,undefined8 *param_3)



{

  int iVar1;

  

  if (param_3 == (undefined8 *)0x0) {

    return 0x80070057;

  }

  *param_3 = 0;

  iVar1 = FUN_1401a98e0(param_2,&DAT_140398d48);

  if (iVar1 == 0) {

    iVar1 = FUN_1401a98e0(param_2,&DAT_1403552e8);

    if (iVar1 == 0) {

      return 0x80004002;

    }

  }

  *param_3 = param_1;

  return 0;

}




