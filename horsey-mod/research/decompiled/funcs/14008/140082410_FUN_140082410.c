// Address: 0x140082410
// Ghidra name: FUN_140082410
// ============ 0x140082410 FUN_140082410 (size=23) ============


longlong FUN_140082410(longlong param_1)



{

  int iVar1;

  uint7 uVar2;

  

  iVar1 = *(int *)(param_1 + 0x70);

  uVar2 = (uint7)(uint3)((uint)iVar1 >> 8);

  if (((iVar1 != 0) && (iVar1 != 1)) && (iVar1 != 0xb)) {

    return (ulonglong)uVar2 << 8;

  }

  return CONCAT71(uVar2,1);

}




