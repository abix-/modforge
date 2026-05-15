// Address: 0x1402300c0
// Ghidra name: FUN_1402300c0
// ============ 0x1402300c0 FUN_1402300c0 (size=94) ============


undefined8 FUN_1402300c0(longlong param_1)



{

  int iVar1;

  undefined8 uVar2;

  undefined1 local_28 [32];

  

  FUN_140179b40(*(undefined8 *)(param_1 + 8));

  iVar1 = (*DAT_1403fdd80)(*(undefined8 *)(param_1 + 0x18),local_28);

  FUN_140179b60(*(undefined8 *)(param_1 + 8));

  if ((-1 < iVar1) && (iVar1 != 1)) {

    uVar2 = FUN_140230760(param_1,local_28);

    return uVar2;

  }

  return 0;

}




