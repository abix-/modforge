// Address: 0x1401610b0
// Ghidra name: FUN_1401610b0
// ============ 0x1401610b0 FUN_1401610b0 (size=232) ============


ulonglong FUN_1401610b0(uint *param_1)



{

  uint uVar1;

  ulonglong uVar2;

  ulonglong uVar3;

  undefined4 *puVar4;

  ulonglong uVar5;

  int iVar6;

  int iVar7;

  longlong lVar8;

  

  uVar3 = FUN_1401841f0((longlong)(int)(DAT_1403fc328 + 1) << 2);

  uVar1 = DAT_1403fc328;

  if (uVar3 == 0) {

    if (param_1 != (uint *)0x0) {

      *param_1 = 0;

    }

    return 0;

  }

  lVar8 = (longlong)(int)DAT_1403fc328;

  if (param_1 != (uint *)0x0) {

    *param_1 = DAT_1403fc328;

  }

  uVar2 = DAT_1403fc330;

  iVar6 = 0;

  iVar7 = iVar6;

  if (0 < (int)uVar1) {

    if ((3 < uVar1) &&

       ((DAT_1403fc330 + (longlong)(int)(uVar1 - 1) * 4 < uVar3 ||

        (iVar7 = 0, uVar3 + (longlong)(int)(uVar1 - 1) * 4 < DAT_1403fc330)))) {

      FUN_1402f8e20(uVar3,DAT_1403fc330,lVar8 << 2);

      do {

        iVar6 = iVar6 + 1;

        iVar7 = iVar6;

      } while (iVar6 < (int)uVar1);

    }

    if (iVar7 < (int)uVar1) {

      lVar8 = (longlong)iVar7;

      uVar5 = (ulonglong)(uVar1 - iVar7);

      iVar7 = iVar7 + (uVar1 - iVar7);

      puVar4 = (undefined4 *)(uVar3 + lVar8 * 4);

      do {

        *puVar4 = *(undefined4 *)((longlong)puVar4 + (uVar2 - uVar3));

        puVar4 = puVar4 + 1;

        uVar5 = uVar5 - 1;

      } while (uVar5 != 0);

    }

  }

  *(undefined4 *)(uVar3 + (longlong)iVar7 * 4) = 0;

  return uVar3;

}




