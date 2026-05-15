// Address: 0x140265160
// Ghidra name: FUN_140265160
// ============ 0x140265160 FUN_140265160 (size=22) ============


longlong FUN_140265160(longlong param_1)



{

  int iVar1;

  uint7 uVar2;

  

  iVar1 = *(int *)(param_1 + 0x144);

  uVar2 = (uint7)(uint3)((uint)iVar1 >> 8);

  if ((iVar1 != 5) && (iVar1 != 6)) {

    return CONCAT71(uVar2,1);

  }

  return (ulonglong)uVar2 << 8;

}




