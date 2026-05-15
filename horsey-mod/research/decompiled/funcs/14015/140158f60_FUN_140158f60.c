// Address: 0x140158f60
// Ghidra name: FUN_140158f60
// ============ 0x140158f60 FUN_140158f60 (size=226) ============


longlong FUN_140158f60(int *param_1)



{

  int iVar1;

  undefined4 uVar2;

  longlong lVar3;

  uint uVar4;

  int iVar5;

  undefined **ppuVar6;

  undefined **ppuVar7;

  longlong lVar8;

  int iVar9;

  

  iVar9 = 0;

  iVar5 = 0;

  FUN_140159d30();

  ppuVar6 = &PTR_PTR_1403e2380;

  uVar4 = 0;

  ppuVar7 = &PTR_PTR_1403e2380;

  do {

    iVar1 = (**(code **)(*ppuVar7 + 8))();

    uVar4 = uVar4 + 1;

    ppuVar7 = ppuVar7 + 1;

    iVar5 = iVar5 + iVar1;

  } while (uVar4 < 6);

  lVar3 = FUN_1401841f0((longlong)iVar5 * 4 + 4);

  if (lVar3 == 0) {

    if (param_1 != (int *)0x0) {

      *param_1 = 0;

    }

  }

  else {

    if (param_1 != (int *)0x0) {

      *param_1 = iVar5;

    }

    uVar4 = 0;

    lVar8 = 0;

    do {

      iVar5 = (**(code **)(*ppuVar6 + 8))();

      iVar1 = 0;

      if (0 < iVar5) {

        iVar9 = iVar9 + iVar5;

        do {

          uVar2 = (**(code **)(*ppuVar6 + 0x50))(iVar1);

          *(undefined4 *)(lVar3 + lVar8 * 4) = uVar2;

          iVar1 = iVar1 + 1;

          lVar8 = lVar8 + 1;

        } while (iVar1 < iVar5);

      }

      uVar4 = uVar4 + 1;

      ppuVar6 = ppuVar6 + 1;

    } while (uVar4 < 6);

    *(undefined4 *)(lVar3 + (longlong)iVar9 * 4) = 0;

  }

  FUN_14015bb10();

  return lVar3;

}




