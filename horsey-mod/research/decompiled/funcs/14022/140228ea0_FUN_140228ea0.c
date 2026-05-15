// Address: 0x140228ea0
// Ghidra name: FUN_140228ea0
// ============ 0x140228ea0 FUN_140228ea0 (size=151) ============


undefined8 FUN_140228ea0(longlong param_1,undefined8 param_2,longlong *param_3)



{

  int iVar1;

  

  if (param_3 == (longlong *)0x0) {

    return 0x80070057;

  }

  *param_3 = 0;

  iVar1 = FUN_1401a98e0(param_2,&DAT_140398d48);

  if (iVar1 == 0) {

    iVar1 = FUN_1401a98e0(param_2,&DAT_140398d78);

    if (iVar1 == 0) goto LAB_140228f02;

  }

  *param_3 = param_1;

LAB_140228f02:

  if (*param_3 != 0) {

    FUN_140228e70(param_1);

    return 0;

  }

  return 0x80004002;

}




