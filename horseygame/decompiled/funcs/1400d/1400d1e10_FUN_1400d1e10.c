// Address: 0x1400d1e10
// Ghidra name: FUN_1400d1e10
// ============ 0x1400d1e10 FUN_1400d1e10 (size=259) ============


void FUN_1400d1e10(longlong param_1,int param_2,int param_3)



{

  longlong lVar1;

  char cVar2;

  bool bVar3;

  float fVar4;

  float local_res20 [2];

  

  if ((((param_2 != -1) &&

       (lVar1 = *(longlong *)(*(longlong *)(param_1 + 0x130) + (longlong)param_2 * 8), param_3 != -1

       )) && (cVar2 = FUN_1400b7720(lVar1), cVar2 != '\0')) &&

     ((cVar2 = FUN_1400b7650(lVar1), cVar2 != '\0' && (cVar2 = FUN_1400b4af0(lVar1), cVar2 != '\0'))

     )) {

    FUN_1400b4b10(lVar1,local_res20);

    if (*(char *)(lVar1 + 0x1a) == '\0') {

      fVar4 = ((float)(DAT_14030b680 + DAT_1403eda00) / *(float *)(param_1 + 0x114) +

              *(float *)(param_1 + 0x10c)) - DAT_14030374c;

      bVar3 = local_res20[0] < fVar4;

    }

    else {

      fVar4 = (*(float *)(param_1 + 0x10c) - (float)DAT_1403eda00 / *(float *)(param_1 + 0x114)) +

              DAT_14030374c;

      bVar3 = fVar4 < local_res20[0];

    }

    if (bVar3 || fVar4 == local_res20[0]) {

      *(int *)(param_1 + 0x230) = param_2;

      *(int *)(param_1 + 0x22c) = param_3;

    }

  }

  return;

}




