// Address: 0x140080a70
// Ghidra name: FUN_140080a70
// ============ 0x140080a70 FUN_140080a70 (size=47) ============


longlong FUN_140080a70(longlong param_1)



{

  longlong lVar1;

  uint7 uVar2;

  

  lVar1 = *(longlong *)(param_1 + 0x80);

  uVar2 = (uint7)((ulonglong)lVar1 >> 8);

  if (((-1 < *(int *)(lVar1 + 0x234)) || ((*(byte *)(lVar1 + 600) & 0x50) == 0)) &&

     (0.0 < *(float *)(param_1 + 0xa8))) {

    return CONCAT71(uVar2,1);

  }

  return (ulonglong)uVar2 << 8;

}




