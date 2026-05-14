// Address: 0x1401e56e0
// Ghidra name: FUN_1401e56e0
// ============ 0x1401e56e0 FUN_1401e56e0 (size=88) ============


undefined4 FUN_1401e56e0(undefined8 param_1,undefined8 param_2,undefined8 param_3)



{

  int iVar1;

  undefined4 uVar2;

  undefined8 *puVar3;

  

  puVar3 = (undefined8 *)FUN_140174d30(param_1,param_2,0);

  if (puVar3 != (undefined8 *)0x0) {

    iVar1 = (**(code **)*puVar3)(puVar3,&DAT_14034b3e8,param_3);

    if (iVar1 < 0) {

      uVar2 = FUN_1401a9ef0(param_2,iVar1);

      return uVar2;

    }

  }

  return 1;

}




