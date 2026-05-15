// Address: 0x1401bf320
// Ghidra name: FUN_1401bf320
// ============ 0x1401bf320 FUN_1401bf320 (size=28) ============


ulonglong FUN_1401bf320(int param_1,int *param_2,uint param_3)



{

  uint uVar1;

  ulonglong uVar2;

  

  uVar2 = 0;

  if (param_3 != 0) {

    do {

      if (*param_2 == param_1) {

        return CONCAT71((int7)(uVar2 >> 8),1);

      }

      uVar1 = (int)uVar2 + 1;

      uVar2 = (ulonglong)uVar1;

      param_2 = param_2 + 1;

    } while (uVar1 < param_3);

  }

  return uVar2 & 0xffffffffffffff00;

}




