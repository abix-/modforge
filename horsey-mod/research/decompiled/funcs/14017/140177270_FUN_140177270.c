// Address: 0x140177270
// Ghidra name: FUN_140177270
// ============ 0x140177270 FUN_140177270 (size=226) ============


longlong FUN_140177270(int *param_1)



{

  int iVar1;

  int iVar2;

  undefined4 uVar3;

  longlong lVar4;

  int iVar5;

  longlong lVar6;

  

  FUN_140177410();

  iVar1 = (**(code **)(PTR_PTR_1403e2870 + 8))();

  lVar4 = FUN_1401841f0((longlong)iVar1 * 4 + 4);

  if (lVar4 == 0) {

    if (param_1 != (int *)0x0) {

      *param_1 = 0;

    }

  }

  else {

    if (param_1 != (int *)0x0) {

      *param_1 = iVar1;

    }

    lVar6 = 0;

    iVar2 = (**(code **)(PTR_PTR_1403e2870 + 8))();

    iVar5 = 0;

    iVar1 = 0;

    if (0 < iVar2) {

      do {

        uVar3 = (**(code **)(PTR_PTR_1403e2870 + 0x30))(iVar5);

        *(undefined4 *)(lVar4 + lVar6 * 4) = uVar3;

        iVar5 = iVar5 + 1;

        lVar6 = lVar6 + 1;

        iVar1 = iVar2;

      } while (iVar5 < iVar2);

    }

    *(undefined4 *)(lVar4 + (longlong)iVar1 * 4) = 0;

  }

  FUN_140177750();

  return lVar4;

}




