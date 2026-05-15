// Address: 0x1401904f0
// Ghidra name: thunk_FUN_14022fe50
// ============ 0x1401904f0 thunk_FUN_14022fe50 (size=5) ============


double thunk_FUN_14022fe50(double param_1,double *param_2)



{

  uint uVar1;

  int iVar2;

  uint uVar3;

  uint uVar4;

  undefined8 uStackX_8;

  

  uVar4 = (uint)((ulonglong)param_1 >> 0x20);

  iVar2 = ((int)uVar4 >> 0x14 & 0x7ffU) - 0x3ff;

  uVar1 = SUB84(param_1,0);

  if (0x13 < iVar2) {

    if (iVar2 < 0x34) {

      uVar3 = 0xffffffff >> ((byte)iVar2 - 0x14 & 0x1f);

      if ((uVar1 & uVar3) != 0) {

        uStackX_8 = (double)CONCAT44(uVar4,~uVar3 & uVar1);

        *param_2 = uStackX_8;

        return param_1 - uStackX_8;

      }

      *param_2 = param_1;

    }

    else {

      *param_2 = param_1;

      if ((iVar2 == 0x400) && (((ulonglong)param_1 & 0xfffff00000000) != 0 || uVar1 != 0)) {

        return param_1;

      }

    }

    return 0.0;

  }

  if (iVar2 < 0) {

    uStackX_8 = (double)(((ulonglong)uVar4 & 0x80000000) << 0x20);

    *param_2 = uStackX_8;

    return param_1;

  }

  uVar3 = 0xfffff >> ((byte)iVar2 & 0x1f);

  if ((uVar3 & uVar4) != 0 || uVar1 != 0) {

    uStackX_8 = (double)((ulonglong)(~uVar3 & uVar4) << 0x20);

    *param_2 = uStackX_8;

    return param_1 - uStackX_8;

  }

  *param_2 = param_1;

  return 0.0;

}




