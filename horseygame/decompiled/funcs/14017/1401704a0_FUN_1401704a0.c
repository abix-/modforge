// Address: 0x1401704a0
// Ghidra name: FUN_1401704a0
// ============ 0x1401704a0 FUN_1401704a0 (size=208) ============


void FUN_1401704a0(int *param_1,float *param_2)



{

  int iVar1;

  longlong lVar2;

  char cVar3;

  int iVar4;

  float fVar5;

  float fVar6;

  

  fVar5 = *param_2;

  if (*param_2 <= DAT_14039ca44) {

    fVar5 = DAT_14039ca44;

  }

  fVar6 = param_2[1];

  if (param_2[1] <= DAT_14039ca44) {

    fVar6 = DAT_14039ca44;

  }

  if ((fVar5 == (float)param_1[0x17]) && (fVar6 == (float)param_1[0x18])) {

    *(ulonglong *)(param_1 + 0x17) = CONCAT44(fVar6,fVar5);

    return;

  }

  *(ulonglong *)(param_1 + 0x17) = CONCAT44(fVar6,fVar5);

  cVar3 = FUN_14016ba40(DAT_1403fc410);

  if (cVar3 == '\0') {

    for (lVar2 = *(longlong *)(*(longlong *)(param_1 + 0x1c) + 0x348); lVar2 != 0;

        lVar2 = *(longlong *)(lVar2 + 0x1a0)) {

      iVar1 = *param_1;

      iVar4 = FUN_14016d540(lVar2);

      if (iVar4 == iVar1) {

        FUN_140170e10(lVar2,param_1 + 0x17,1);

      }

    }

  }

  return;

}




