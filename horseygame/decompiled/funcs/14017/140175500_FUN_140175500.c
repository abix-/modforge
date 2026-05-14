// Address: 0x140175500
// Ghidra name: FUN_140175500
// ============ 0x140175500 FUN_140175500 (size=145) ============


undefined1 FUN_140175500(undefined4 param_1,undefined8 param_2,longlong param_3)



{

  undefined1 uVar1;

  undefined4 *puVar2;

  longlong lVar3;

  

  if (param_3 == 0) {

    uVar1 = FUN_1401745e0();

    return uVar1;

  }

  puVar2 = (undefined4 *)FUN_1401841a0(1,0x28);

  if (puVar2 != (undefined4 *)0x0) {

    *puVar2 = 2;

    lVar3 = FUN_14012f0d0(param_3);

    *(longlong *)(puVar2 + 2) = lVar3;

    if (lVar3 != 0) {

      uVar1 = FUN_1401750b0(param_1,param_2,puVar2);

      return uVar1;

    }

    FUN_1401841e0(puVar2);

  }

  return 0;

}




