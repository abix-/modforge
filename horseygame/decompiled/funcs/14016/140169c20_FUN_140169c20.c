// Address: 0x140169c20
// Ghidra name: FUN_140169c20
// ============ 0x140169c20 FUN_140169c20 (size=98) ============


longlong FUN_140169c20(uint *param_1,uint *param_2)



{

  uint uVar1;

  ulonglong uVar2;

  

  uVar1 = *param_1;

  uVar2 = (ulonglong)uVar1;

  if ((uVar1 == 0) || (uVar1 == *param_2)) {

    uVar1 = param_1[1];

    uVar2 = (ulonglong)uVar1;

    if ((uVar1 == 0) || (uVar1 == param_2[1])) {

      uVar1 = param_1[2];

      uVar2 = (ulonglong)uVar1;

      if ((((uVar1 == 0) || (param_1[3] == 0)) ||

          ((uVar1 == param_2[2] && (param_1[3] == param_2[3])))) &&

         ((((float)param_1[4] == 0.0 || ((float)param_1[4] == (float)param_2[4])) &&

          (((float)param_1[5] == 0.0 || ((float)param_1[5] == (float)param_2[5])))))) {

        return (ulonglong)(uint3)(uVar1 >> 8) << 8;

      }

    }

  }

  return CONCAT71((int7)(uVar2 >> 8),1);

}




