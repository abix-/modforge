// Address: 0x140131b60
// Ghidra name: FUN_140131b60
// ============ 0x140131b60 FUN_140131b60 (size=204) ============


longlong FUN_140131b60(undefined8 param_1,int *param_2)



{

  int iVar1;

  longlong lVar2;

  longlong lVar3;

  longlong lVar4;

  int iVar5;

  longlong lVar6;

  longlong lVar7;

  

  if (param_2 != (int *)0x0) {

    *param_2 = 0;

  }

  lVar2 = FUN_140130ab0();

  if (lVar2 == 0) {

    return 0;

  }

  iVar1 = *(int *)(lVar2 + 0x38);

  lVar7 = (longlong)iVar1;

  lVar3 = FUN_1401841f0((lVar7 + 1 + lVar7 * 3) * 8);

  if (lVar3 != 0) {

    lVar6 = lVar3 + (lVar7 + 1) * 8;

    FUN_1402f8e20(lVar6,*(undefined8 *)(lVar2 + 0x30),lVar7 * 0x18);

    iVar5 = 0;

    if (0 < iVar1) {

      lVar4 = 0;

      do {

        *(longlong *)(lVar3 + lVar4 * 8) = lVar6;

        iVar5 = iVar5 + 1;

        lVar6 = lVar6 + 0x18;

        lVar4 = lVar4 + 1;

      } while (lVar4 < lVar7);

    }

    *(undefined8 *)(lVar3 + (longlong)iVar5 * 8) = 0;

    if (param_2 != (int *)0x0) {

      *param_2 = iVar1;

    }

  }

  FUN_140130b70(lVar2);

  return lVar3;

}




