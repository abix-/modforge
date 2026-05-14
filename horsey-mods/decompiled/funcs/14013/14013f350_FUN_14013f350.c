// Address: 0x14013f350
// Ghidra name: FUN_14013f350
// ============ 0x14013f350 FUN_14013f350 (size=96) ============


undefined4 FUN_14013f350(undefined4 param_1)



{

  undefined4 uVar1;

  longlong lVar2;

  undefined4 *puVar3;

  undefined8 uVar4;

  undefined4 local_28;

  undefined4 uStack_24;

  undefined4 uStack_20;

  undefined4 uStack_1c;

  undefined1 local_18 [16];

  

  FUN_140159d30();

  lVar2 = FUN_140158f10(param_1);

  if (lVar2 != 0) {

    uVar1 = *(undefined4 *)(lVar2 + 0x14);

    FUN_14015bb10();

    return uVar1;

  }

  puVar3 = (undefined4 *)FUN_140158250(local_18,param_1);

  local_28 = *puVar3;

  uStack_24 = puVar3[1];

  uStack_20 = puVar3[2];

  uStack_1c = puVar3[3];

  uVar4 = FUN_140158780(param_1);

  uVar1 = FUN_140157ac0(&local_28,uVar4);

  FUN_14015bb10();

  return uVar1;

}




