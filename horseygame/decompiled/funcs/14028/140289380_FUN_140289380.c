// Address: 0x140289380
// Ghidra name: FUN_140289380
// ============ 0x140289380 FUN_140289380 (size=123) ============


undefined8 FUN_140289380(longlong *param_1,undefined8 param_2,undefined8 *param_3)



{

  int iVar1;

  

  iVar1 = FUN_1401a98e0(param_2,&DAT_140398d48);

  if (iVar1 == 0) {

    iVar1 = FUN_1401a98e0(param_2,&DAT_140380c78);

    if (iVar1 == 0) {

      *param_3 = 0;

      return 0x80004002;

    }

  }

  *param_3 = param_1;

  (**(code **)(*param_1 + 8))(param_1);

  return 0;

}




