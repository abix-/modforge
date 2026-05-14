// Address: 0x14013f3b0
// Ghidra name: FUN_14013f3b0
// ============ 0x14013f3b0 FUN_14013f3b0 (size=73) ============


void FUN_14013f3b0(void)



{

  longlong lVar1;

  undefined4 *puVar2;

  undefined8 uVar3;

  undefined4 local_28;

  undefined4 uStack_24;

  undefined4 uStack_20;

  undefined4 uStack_1c;

  undefined1 local_18 [16];

  

  lVar1 = FUN_14013e670();

  if (lVar1 == 0) {

    return;

  }

  puVar2 = (undefined4 *)FUN_1401585d0(local_18,lVar1);

  local_28 = *puVar2;

  uStack_24 = puVar2[1];

  uStack_20 = puVar2[2];

  uStack_1c = puVar2[3];

  uVar3 = FUN_1401587b0(lVar1);

  FUN_140157ac0(&local_28,uVar3);

  return;

}




