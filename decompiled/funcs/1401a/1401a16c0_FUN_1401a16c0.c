// Address: 0x1401a16c0
// Ghidra name: FUN_1401a16c0
// ============ 0x1401a16c0 FUN_1401a16c0 (size=135) ============


ulonglong FUN_1401a16c0(undefined8 param_1)



{

  uint uVar1;

  undefined8 *puVar2;

  ulonglong uVar3;

  

  puVar2 = (undefined8 *)thunk_FUN_1401841f0(0x4888);

  if (puVar2 == (undefined8 *)0x0) {

    uVar3 = FUN_14019f050("Out of memory");

    return uVar3;

  }

  FUN_1402f94c0(puVar2 + 1,0,0x4880);

  *puVar2 = param_1;

  FUN_1401a4a60(puVar2);

  uVar1 = FUN_14019ec00(puVar2,1);

  FUN_1401a4a40(param_1);

  FUN_1401841e0(puVar2);

  return (ulonglong)uVar1;

}




