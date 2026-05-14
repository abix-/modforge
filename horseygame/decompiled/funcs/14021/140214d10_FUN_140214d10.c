// Address: 0x140214d10
// Ghidra name: FUN_140214d10
// ============ 0x140214d10 FUN_140214d10 (size=61) ============


ulonglong FUN_140214d10(longlong param_1)



{

  longlong lVar1;

  char cVar2;

  ulonglong uVar3;

  

  FUN_140214e00();

  cVar2 = FUN_1402148d0(param_1);

  if (cVar2 == '\0') {

    uVar3 = FUN_140214fb0(param_1);

    return uVar3 & 0xffffffffffffff00;

  }

  lVar1 = *(longlong *)(param_1 + 200);

  *(undefined1 *)(lVar1 + 0x44) = 0;

  return CONCAT71((int7)((ulonglong)lVar1 >> 8),1);

}




