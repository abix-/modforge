// Address: 0x1400faf70
// Ghidra name: FUN_1400faf70
// ============ 0x1400faf70 FUN_1400faf70 (size=204) ============


undefined8 FUN_1400faf70(longlong param_1,int param_2,int param_3)



{

  longlong lVar1;

  char cVar2;

  float *pfVar3;

  float fVar4;

  undefined1 local_res8 [8];

  

  lVar1 = *(longlong *)(*(longlong *)(param_1 + 0x130) + (longlong)param_2 * 8);

  if (param_3 != -1) {

    return 1;

  }

  if (*(int *)(lVar1 + 0x234) != -1) {

    return 1;

  }

  pfVar3 = (float *)FUN_1400b4a10(lVar1,local_res8);

  fVar4 = *(float *)(param_1 + 0x10c) + DAT_14039ca58;

  if ((((fVar4 < *pfVar3 || fVar4 == *pfVar3) || (cVar2 = FUN_1400b7650(lVar1), cVar2 == '\0')) ||

      (*(char *)(lVar1 + 0x206) != '\0')) || (*(char *)(lVar1 + 0x205) != '\0')) {

    if (*(char *)(lVar1 + 0x1a) == '\0') goto LAB_1400fb013;

    FUN_1400b47e0(lVar1);

    *(undefined1 *)(lVar1 + 0x1a) = 0;

  }

  else {

    if (*(char *)(lVar1 + 0x1a) != '\0') goto LAB_1400fb013;

    FUN_1400b47e0(lVar1);

    *(undefined1 *)(lVar1 + 0x1a) = 1;

  }

  FUN_1400cead0(param_1,lVar1);

LAB_1400fb013:

  FUN_1400b87e0(lVar1);

  FUN_1400b7fe0(lVar1,0x3c);

  *(undefined1 *)(param_1 + 0x261) = 1;

  return 1;

}




