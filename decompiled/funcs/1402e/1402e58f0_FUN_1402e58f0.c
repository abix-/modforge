// Address: 0x1402e58f0
// Ghidra name: FUN_1402e58f0
// ============ 0x1402e58f0 FUN_1402e58f0 (size=472) ============


double FUN_1402e58f0(double param_1,double param_2,int param_3)



{

  int iVar1;

  double dVar2;

  double dVar3;

  

  iVar1 = 0;

  if (param_1 <= DAT_14038c6f0) {

    if (param_1 < DAT_14038c6f8) {

      iVar1 = -1;

      param_1 = param_1 + DAT_14038c680 + param_2 + DAT_14038c690;

      param_2 = 0.0;

    }

  }

  else {

    iVar1 = 1;

    param_1 = (DAT_14038c680 - param_1) + (DAT_14038c690 - param_2);

    param_2 = 0.0;

  }

  dVar2 = (param_1 + param_1) * param_2 + param_1 * param_1;

  param_2 = (((dVar2 * DAT_14038c620 + DAT_14038c610) * dVar2 + DAT_14038c600) * dVar2 * param_1) /

            (((DAT_14038c650 + dVar2 * DAT_14038c660) * dVar2 + DAT_14038c640) * dVar2 +

            DAT_14038c630) + param_2;

  if (iVar1 != 0) {

    param_2 = param_2 + param_1;

    if (param_3 != 0) {

      return ((param_2 + param_2) / (param_2 - DAT_14038c708) - DAT_14038c708) * (double)iVar1;

    }

    return (DAT_14038c708 - (param_2 + param_2) / (param_2 + DAT_14038c708)) * (double)iVar1;

  }

  if (param_3 != 0) {

    dVar3 = DAT_14038c710 / (param_2 + param_1);

    dVar2 = (double)((ulonglong)(param_2 + param_1) & 0xffffffff00000000);

    return ((double)((ulonglong)dVar3 & 0xffffffff00000000) * dVar2 + DAT_14038c708 +

           (param_2 - (dVar2 - param_1)) * (double)((ulonglong)dVar3 & 0xffffffff00000000)) * dVar3

           + (double)((ulonglong)dVar3 & 0xffffffff00000000);

  }

  return param_2 + param_1;

}




