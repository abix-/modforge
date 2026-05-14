// Address: 0x140148960
// Ghidra name: FUN_140148960
// ============ 0x140148960 FUN_140148960 (size=43) ============


ulonglong FUN_140148960(longlong param_1)



{

  ulonglong uVar1;

  

  uVar1 = FUN_1401489c0();

  if ((char)uVar1 != '\0') {

    return (ulonglong)(*(uint *)(param_1 + 0x108) >> 10) & 0xffffffffffffff01;

  }

  return uVar1 & 0xffffffffffffff00;

}




