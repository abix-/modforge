// Address: 0x140182d60
// Ghidra name: FUN_140182d60
// ============ 0x140182d60 FUN_140182d60 (size=201) ============


longlong FUN_140182d60(undefined8 *param_1,int param_2)



{

  size_t sVar1;

  longlong lVar2;

  longlong lVar3;

  int iVar4;

  longlong lVar5;

  longlong lVar6;

  

  lVar5 = (longlong)param_2;

  lVar6 = (longlong)(param_2 + 1) * 8;

  lVar3 = lVar6;

  if (0 < param_2) {

    lVar2 = 0;

    do {

      sVar1 = strlen((char *)param_1[lVar2]);

      lVar2 = lVar2 + 1;

      lVar3 = lVar3 + 1 + sVar1;

    } while (lVar2 < lVar5);

  }

  lVar3 = FUN_1401391c0(lVar3);

  if (lVar3 != 0) {

    lVar6 = lVar6 + lVar3;

    iVar4 = 0;

    if (0 < param_2) {

      lVar2 = lVar3 - (longlong)param_1;

      do {

        sVar1 = strlen((char *)*param_1);

        *(longlong *)((longlong)param_1 + lVar2) = lVar6;

        FUN_1402f8e20(lVar6,*param_1,sVar1 + 1);

        lVar6 = lVar6 + sVar1 + 1;

        param_1 = param_1 + 1;

        lVar5 = lVar5 + -1;

        iVar4 = param_2;

      } while (lVar5 != 0);

    }

    *(undefined8 *)(lVar3 + (longlong)iVar4 * 8) = 0;

  }

  return lVar3;

}




