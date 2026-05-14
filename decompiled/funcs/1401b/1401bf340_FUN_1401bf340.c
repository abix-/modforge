// Address: 0x1401bf340
// Ghidra name: FUN_1401bf340
// ============ 0x1401bf340 FUN_1401bf340 (size=33) ============


ulonglong FUN_1401bf340(int param_1,int param_2,longlong param_3,uint param_4)



{

  uint uVar1;

  ulonglong uVar2;

  

  uVar2 = 0;

  if (param_4 != 0) {

    do {

      if ((*(int *)(param_3 + uVar2 * 8) == param_1) &&

         (*(int *)(param_3 + 4 + uVar2 * 8) == param_2)) {

        return CONCAT71((int7)(uVar2 >> 8),1);

      }

      uVar1 = (int)uVar2 + 1;

      uVar2 = (ulonglong)uVar1;

    } while (uVar1 < param_4);

  }

  return uVar2 & 0xffffffffffffff00;

}




