// Address: 0x1401ac520
// Ghidra name: FUN_1401ac520
// ============ 0x1401ac520 FUN_1401ac520 (size=119) ============


undefined8 FUN_1401ac520(longlong param_1,longlong param_2,int param_3,undefined4 param_4)



{

  undefined8 uVar1;

  longlong lVar2;

  

  uVar1 = FUN_14017fc90();

  lVar2 = FUN_140190080(uVar1,param_4);

  *(longlong *)(param_1 + 0x18) = lVar2;

  uVar1 = 0;

  if (lVar2 != 0) {

    if (param_3 < 0) {

      param_2 = param_2 + (1 - *(int *)(param_1 + 0xc)) * param_3;

    }

    FUN_1402f8e20(lVar2,param_2,param_4);

    uVar1 = 2;

    *(int *)(param_1 + 0x10) = param_3;

  }

  return uVar1;

}




