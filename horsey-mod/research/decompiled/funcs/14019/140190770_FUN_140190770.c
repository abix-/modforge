// Address: 0x140190770
// Ghidra name: FUN_140190770
// ============ 0x140190770 FUN_140190770 (size=475) ============


longlong FUN_140190770(longlong param_1,longlong param_2,longlong param_3,ulonglong param_4,

                      code *param_5,undefined8 param_6)



{

  int iVar1;

  longlong lVar2;

  longlong lVar3;

  longlong lVar4;

  longlong lVar5;

  longlong lVar6;

  

  lVar3 = ((ulonglong)(param_3 - param_1) / param_4 >> 3) * param_4;

  lVar6 = param_1 + lVar3;

  lVar5 = lVar3 * 2 + param_1;

  iVar1 = (*param_5)(param_6,param_1,lVar6);

  if (iVar1 < 0) {

    iVar1 = (*param_5)(param_6,lVar6);

    lVar4 = lVar6;

    if ((-1 < iVar1) && (iVar1 = (*param_5)(param_6,param_1,lVar5), lVar4 = param_1, iVar1 < 0)) {

      lVar4 = lVar5;

    }

  }

  else {

    iVar1 = (*param_5)(param_6,param_1,lVar5);

    lVar4 = param_1;

    if (-1 < iVar1) {

      iVar1 = (*param_5)(param_6,lVar6,lVar5);

      lVar6 = lVar3;

      if (iVar1 < 0) {

        lVar6 = lVar3 * 2;

      }

      lVar4 = lVar6 + param_1;

    }

  }

  lVar6 = param_2 + lVar3;

  lVar5 = param_2 - lVar3;

  iVar1 = (*param_5)(param_6,lVar5,param_2);

  if (iVar1 < 0) {

    iVar1 = (*param_5)(param_6,param_2);

    lVar2 = param_2;

    if (-1 < iVar1) {

      iVar1 = (*param_5)(param_6,lVar5,lVar6);

      param_2 = lVar5;

LAB_140190876:

      lVar2 = param_2;

      if (iVar1 < 0) {

        lVar2 = lVar6;

      }

    }

  }

  else {

    iVar1 = (*param_5)(param_6,lVar5,lVar6);

    lVar2 = lVar5;

    if (-1 < iVar1) {

      iVar1 = (*param_5)(param_6,param_2,lVar6);

      goto LAB_140190876;

    }

  }

  lVar6 = param_3 + lVar3 * -2;

  lVar3 = param_3 - lVar3;

  iVar1 = (*param_5)(param_6,lVar6,lVar3);

  if (iVar1 < 0) {

    iVar1 = (*param_5)(param_6,lVar3);

    lVar5 = lVar3;

    if (iVar1 < 0) goto LAB_1401908dd;

    iVar1 = (*param_5)(param_6,lVar6,param_3);

    lVar3 = lVar6;

  }

  else {

    iVar1 = (*param_5)(param_6,lVar6,param_3);

    lVar5 = lVar6;

    if (iVar1 < 0) goto LAB_1401908dd;

    iVar1 = (*param_5)(param_6,lVar3,param_3);

  }

  lVar5 = lVar3;

  if (iVar1 < 0) {

    lVar5 = param_3;

  }

LAB_1401908dd:

  iVar1 = (*param_5)(param_6,lVar4,lVar2);

  if (iVar1 < 0) {

    iVar1 = (*param_5)(param_6,lVar2);

    lVar6 = lVar2;

    if ((-1 < iVar1) && (iVar1 = (*param_5)(param_6,lVar4,lVar5), lVar6 = lVar4, iVar1 < 0)) {

      lVar6 = lVar5;

    }

  }

  else {

    iVar1 = (*param_5)(param_6,lVar4,lVar5);

    lVar6 = lVar4;

    if ((-1 < iVar1) && (iVar1 = (*param_5)(param_6,lVar2,lVar5), lVar6 = lVar2, iVar1 < 0)) {

      lVar6 = lVar5;

    }

  }

  return lVar6;

}




