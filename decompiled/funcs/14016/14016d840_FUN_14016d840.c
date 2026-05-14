// Address: 0x14016d840
// Ghidra name: FUN_14016d840
// ============ 0x14016d840 FUN_14016d840 (size=224) ============


longlong FUN_14016d840(undefined8 param_1,int *param_2)



{

  int iVar1;

  longlong lVar2;

  longlong lVar3;

  int iVar4;

  longlong lVar5;

  longlong lVar6;

  

  lVar2 = FUN_14016dd00();

  if (param_2 != (int *)0x0) {

    *param_2 = 0;

  }

  if (lVar2 == 0) {

    return 0;

  }

  FUN_140173170(lVar2);

  iVar1 = *(int *)(lVar2 + 0x14);

  lVar6 = (longlong)iVar1;

  lVar3 = FUN_1401841f0((lVar6 + 1 + lVar6 * 5) * 8);

  if (lVar3 == 0) {

    if (param_2 != (int *)0x0) {

      *param_2 = 0;

    }

  }

  else {

    lVar5 = lVar3 + (lVar6 + 1) * 8;

    FUN_1402f8e20(lVar5,*(undefined8 *)(lVar2 + 0x18),lVar6 * 0x28);

    iVar4 = 0;

    if (0 < iVar1) {

      lVar2 = 0;

      do {

        *(longlong *)(lVar3 + lVar2 * 8) = lVar5;

        iVar4 = iVar4 + 1;

        lVar5 = lVar5 + 0x28;

        lVar2 = lVar2 + 1;

      } while (lVar2 < lVar6);

    }

    *(undefined8 *)(lVar3 + (longlong)iVar4 * 8) = 0;

    if (param_2 != (int *)0x0) {

      *param_2 = iVar1;

    }

  }

  return lVar3;

}




