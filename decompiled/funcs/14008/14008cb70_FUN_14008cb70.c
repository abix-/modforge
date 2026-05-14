// Address: 0x14008cb70
// Ghidra name: FUN_14008cb70
// ============ 0x14008cb70 FUN_14008cb70 (size=94) ============


void FUN_14008cb70(longlong param_1)



{

  int iVar1;

  

  FUN_140075e80(param_1 + 0x492);

  FUN_140075e80(param_1 + 0x491);

  FUN_140075e80(param_1 + 0x490);

  FUN_140075b80(param_1 + 0x25c);

  iVar1 = FUN_140075da0();

  if (iVar1 != -1) {

    *(undefined8 *)(param_1 + 0x270) =

         *(undefined8 *)(*(longlong *)(param_1 + 0xb8) + (longlong)iVar1 * 8);

  }

  return;

}




