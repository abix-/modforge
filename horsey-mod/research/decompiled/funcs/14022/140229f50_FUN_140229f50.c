// Address: 0x140229f50
// Ghidra name: FUN_140229f50
// ============ 0x140229f50 FUN_140229f50 (size=46) ============


uint FUN_140229f50(longlong param_1)



{

  ulonglong uVar1;

  uint uVar2;

  

  uVar1 = *(ulonglong *)(param_1 + 0x48);

  uVar2 = 0;

  if (((((uVar1 & 0xc0000) != 0) || ((uVar1 >> 0x11 & 1) != 0)) &&

      (uVar2 = 0x80, (uVar1 & 0xc0000) != 0)) || ((uVar1 >> 0x1f & 1) != 0)) {

    uVar2 = uVar2 | 0x8000000;

  }

  return uVar2;

}




