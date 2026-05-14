// Address: 0x14015da30
// Ghidra name: FUN_14015da30
// ============ 0x14015da30 FUN_14015da30 (size=89) ============


ulonglong FUN_14015da30(uint *param_1,uint *param_2,void *param_3,void *param_4)



{

  int iVar1;

  ulonglong uVar2;

  undefined4 extraout_var;

  

  uVar2 = (ulonglong)*param_2;

  if ((((*param_1 == *param_2) && (param_1[1] == param_2[1])) &&

      (uVar2 = (ulonglong)param_2[2], param_1[2] == param_2[2])) &&

     (uVar2 = 0, (param_3 != (void *)0x0) == (param_4 != (void *)0x0))) {

    if (param_3 != (void *)0x0) {

      iVar1 = memcmp(param_3,param_4,(longlong)(int)param_1[1] << 2);

      uVar2 = CONCAT44(extraout_var,iVar1);

      if (iVar1 != 0) goto LAB_14015da82;

    }

    return CONCAT71((int7)(uVar2 >> 8),1);

  }

LAB_14015da82:

  return uVar2 & 0xffffffffffffff00;

}




