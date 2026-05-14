// Address: 0x140163ac0
// Ghidra name: FUN_140163ac0
// ============ 0x140163ac0 FUN_140163ac0 (size=378) ============


ulonglong FUN_140163ac0(longlong param_1,undefined8 param_2,undefined8 param_3)



{

  uint uVar1;

  char cVar2;

  int iVar3;

  int iVar4;

  ulonglong uVar5;

  uint *puVar6;

  uint *puVar7;

  longlong lVar8;

  int iVar9;

  uint uVar10;

  

  if (param_1 == 0) {

    uVar5 = FUN_14012e850("Parameter \'%s\' is invalid",&DAT_140331fb4);

    return uVar5;

  }

  thunk_FUN_140217550();

  iVar3 = FUN_140138fe0(param_1);

  iVar9 = iVar3 + -1;

  if (iVar9 < 0) {

    iVar3 = FUN_140138fb0(&DAT_1403fc344,1);

    FUN_140138fc0(param_1,0,iVar3 + 1);

    iVar9 = FUN_140138fe0(param_1);

    iVar9 = iVar9 + -1;

  }

  else {

    iVar4 = FUN_140138fe0(&DAT_1403fc344);

    while ((iVar4 <= iVar9 && (cVar2 = FUN_140138fc0(&DAT_1403fc344,iVar4,iVar3), cVar2 == '\0'))) {

      iVar4 = FUN_140138fe0(&DAT_1403fc344);

    }

  }

  puVar6 = (uint *)FUN_140217520();

  if (puVar6 == (uint *)0x0) {

    uVar10 = 0;

LAB_140163b95:

    uVar1 = iVar9 + 4;

    puVar6 = (uint *)FUN_140184230(puVar6,(ulonglong)uVar1 * 0x10 + 8);

    uVar5 = 0;

    if (puVar6 != (uint *)0x0) {

      *puVar6 = uVar1;

      if (uVar10 < uVar1) {

        puVar7 = puVar6 + ((ulonglong)uVar10 + 1) * 4;

        uVar5 = (ulonglong)(uVar1 - uVar10);

        do {

          puVar7[-2] = 0;

          puVar7[-1] = 0;

          puVar7[0] = 0;

          puVar7[1] = 0;

          puVar7 = puVar7 + 4;

          uVar5 = uVar5 - 1;

        } while (uVar5 != 0);

      }

      cVar2 = FUN_1402175d0(puVar6);

      if (cVar2 != '\0') {

        FUN_140138fb0(&DAT_1403fc340,1);

        goto LAB_140163c0a;

      }

      uVar5 = FUN_1401841e0(puVar6);

    }

    uVar5 = uVar5 & 0xffffffffffffff00;

  }

  else {

    uVar10 = *puVar6;

    if ((int)uVar10 <= iVar9) goto LAB_140163b95;

LAB_140163c0a:

    lVar8 = (longlong)iVar9;

    *(undefined8 *)(puVar6 + lVar8 * 4 + 2) = param_2;

    *(undefined8 *)(puVar6 + lVar8 * 4 + 4) = param_3;

    uVar5 = CONCAT71((int7)((ulonglong)(lVar8 * 2) >> 8),1);

  }

  return uVar5;

}




