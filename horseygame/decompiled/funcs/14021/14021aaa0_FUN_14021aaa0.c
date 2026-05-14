// Address: 0x14021aaa0
// Ghidra name: FUN_14021aaa0
// ============ 0x14021aaa0 FUN_14021aaa0 (size=37) ============


longlong FUN_14021aaa0(int *param_1)



{

  uint7 uVar1;

  

  uVar1 = (uint7)(uint3)((uint)(*param_1 + -0x101) >> 8);

  switch(*param_1 + -0x101) {

  case 0:

  case 1:

  case 2:

  case 3:

  case 4:

  case 5:

    return CONCAT71(uVar1,1);

  default:

    return (ulonglong)uVar1 << 8;

  }

}




