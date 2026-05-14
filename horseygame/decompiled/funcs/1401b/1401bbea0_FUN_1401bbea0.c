// Address: 0x1401bbea0
// Ghidra name: FUN_1401bbea0
// ============ 0x1401bbea0 FUN_1401bbea0 (size=169) ============


undefined8

FUN_1401bbea0(undefined8 param_1,undefined8 param_2,longlong param_3,undefined4 param_4,

             undefined4 param_5,char param_6,undefined4 param_7)



{

  int iVar1;

  undefined8 uVar2;

  

  uVar2 = FUN_1401bac70(param_3,param_4,param_5);

  if ((param_6 != '\0') && (*(char *)(param_3 + 0x48) != '\0')) {

    iVar1 = FUN_140138fe0(*(longlong *)(param_3 + 0x28) + 0x54);

    if (0 < iVar1) {

      FUN_1401b8730(param_1,param_2,param_3);

      uVar2 = FUN_1401bac70(param_3,param_4,param_5);

    }

  }

  FUN_1401bd590(param_1,param_2,param_7,uVar2);

  return uVar2;

}




