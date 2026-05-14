// Address: 0x140164440
// Ghidra name: FUN_140164440
// ============ 0x140164440 FUN_140164440 (size=133) ============


longlong FUN_140164440(longlong param_1,ulonglong param_2)



{

  undefined8 uVar1;

  longlong lVar2;

  

  if (param_2 <= *(ulonglong *)(param_1 + 0xb0)) {

    return *(longlong *)(param_1 + 0xa8);

  }

  uVar1 = FUN_14017fc90();

  lVar2 = FUN_140190080(uVar1,param_2);

  if (lVar2 == 0) {

    return 0;

  }

  FUN_140190140(*(undefined8 *)(param_1 + 0xa8));

  *(longlong *)(param_1 + 0xa8) = lVar2;

  *(ulonglong *)(param_1 + 0xb0) = param_2;

  return lVar2;

}




