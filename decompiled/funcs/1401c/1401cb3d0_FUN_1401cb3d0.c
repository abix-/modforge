// Address: 0x1401cb3d0
// Ghidra name: FUN_1401cb3d0
// ============ 0x1401cb3d0 FUN_1401cb3d0 (size=102) ============


void FUN_1401cb3d0(longlong param_1,longlong *param_2,char *param_3)



{

  size_t sVar1;

  undefined8 uVar2;

  

  if ((*(char *)(param_1 + 0x98) != '\0') && (param_3 != (char *)0x0)) {

    sVar1 = strlen(param_3);

    uVar2 = FUN_140197820("UTF-16LE",&DAT_14039c6f0,param_3,sVar1 + 1);

    (**(code **)(*param_2 + 0x30))(param_2,uVar2);

    FUN_1401841e0(uVar2);

  }

  return;

}




