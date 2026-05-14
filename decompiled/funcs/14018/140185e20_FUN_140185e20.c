// Address: 0x140185e20
// Ghidra name: FUN_140185e20
// ============ 0x140185e20 FUN_140185e20 (size=52) ============


ulonglong FUN_140185e20(int *param_1)



{

  uint uVar1;

  ulonglong uVar2;

  

  uVar2 = (ulonglong)(*param_1 + 0x3fffffffU);

  if (*param_1 + 0x3fffffffU < 0x7ffffffe) {

    uVar1 = param_1[1] + 0x3fffffff;

    uVar2 = (ulonglong)uVar1;

    if ((uVar1 < 0x7ffffffe) && (param_1[2] < 0x3fffffff)) {

      return (ulonglong)CONCAT31((int3)(uVar1 >> 8),0x3ffffffe < param_1[3]);

    }

  }

  return CONCAT71((int7)(uVar2 >> 8),1);

}




