// Address: 0x14019b6c0
// Ghidra name: FUN_14019b6c0
// ============ 0x14019b6c0 FUN_14019b6c0 (size=739) ============


bool FUN_14019b6c0(longlong param_1,longlong param_2,char param_3)



{

  bool bVar1;

  char cVar2;

  byte bVar3;

  uint uVar4;

  longlong lVar5;

  undefined1 *puVar6;

  longlong lVar7;

  longlong lVar8;

  undefined1 *puVar9;

  undefined1 *puVar10;

  int iVar11;

  undefined1 *puVar12;

  int iVar13;

  uint uVar14;

  int iVar15;

  bool bVar16;

  undefined8 local_res10;

  char local_res18;

  

  bVar16 = false;

  lVar5 = 0;

  puVar6 = (undefined1 *)0x0;

  bVar1 = false;

  local_res18 = param_3;

  cVar2 = FUN_1401489c0();

  if (cVar2 == '\0') {

    FUN_14012e850("Parameter \'%s\' is invalid","surface");

  }

  else {

    if (param_2 == 0) {

      FUN_14012e850("Parameter \'%s\' is invalid",&DAT_140331e9c);

      FUN_1401841e0(0);

      FUN_1401841e0(0);

      return false;

    }

    uVar14 = *(uint *)(param_1 + 4);

    iVar11 = 0;

    if (((uVar14 == 0) || ((uVar14 & 0xf0000000) == 0x10000000)) &&

       ((uVar4 = uVar14 & 0xf000000, uVar4 == 0x1000000 ||

        (((uVar4 == 0xc000000 || (uVar4 == 0x2000000)) || (uVar4 == 0x3000000)))))) {

      if (*(longlong *)(param_1 + 0x48) == 0) {

        FUN_14012e850("Indexed surfaces must have a palette");

        FUN_1401841e0(0);

        FUN_1401841e0(0);

        goto LAB_14019b71a;

      }

      if (uVar14 != 0x13000801) {

        param_1 = FUN_140145bb0(param_1,0x13000801);

        if (param_1 == 0) goto LAB_14019b705;

        bVar1 = true;

      }

      iVar11 = **(int **)(param_1 + 0x48);

      iVar15 = iVar11 * 3;

      lVar5 = FUN_1401841f0((longlong)iVar15);

      puVar6 = (undefined1 *)FUN_1401841f0((longlong)iVar11);

      if ((lVar5 != 0) && (puVar6 != (undefined1 *)0x0)) {

        iVar13 = 0;

        if (0 < **(int **)(param_1 + 0x48)) {

          puVar9 = (undefined1 *)(*(longlong *)(*(int **)(param_1 + 0x48) + 2) + 2);

          puVar10 = (undefined1 *)(lVar5 + 2);

          puVar12 = puVar6;

          do {

            iVar13 = iVar13 + 1;

            puVar10[-2] = puVar9[-2];

            puVar10[-1] = puVar9[-1];

            *puVar10 = *puVar9;

            *puVar12 = puVar9[1];

            puVar9 = puVar9 + 4;

            puVar10 = puVar10 + 3;

            puVar12 = puVar12 + 1;

          } while (iVar13 < **(int **)(param_1 + 0x48));

        }

        goto LAB_14019b8a7;

      }

    }

    else {

      iVar15 = 0;

      if (uVar14 != 0x16762004) {

        param_1 = FUN_140145bb0(param_1,0x16762004);

        if (param_1 == 0) goto LAB_14019b705;

        bVar1 = true;

        iVar15 = 0;

      }

LAB_14019b8a7:

      uVar14 = *(uint *)(param_1 + 4);

      local_res10 = 0;

      if ((uVar14 == 0) || ((uVar14 & 0xf0000000) == 0x10000000)) {

        uVar14 = uVar14 & 0xff;

      }

      else if ((((uVar14 == 0x32595559) || (uVar14 == 0x59565955)) || (uVar14 == 0x55595659)) ||

              (uVar14 == 0x30313050)) {

        uVar14 = 2;

      }

      else {

        uVar14 = 1;

      }

      lVar7 = FUN_1401a7b60(*(undefined8 *)(param_1 + 0x18),*(undefined4 *)(param_1 + 8),

                            *(undefined4 *)(param_1 + 0xc),uVar14,*(undefined4 *)(param_1 + 0x10),

                            &local_res10,6,0,lVar5,iVar15,puVar6,iVar11);

      if (lVar7 == 0) {

        FUN_14012e850("Failed to convert and save image");

      }

      else {

        lVar8 = FUN_14012cbb0(param_2,lVar7,local_res10);

        FUN_140160120(lVar7);

        bVar16 = lVar8 != 0;

      }

    }

    if (bVar1) {

      FUN_140146010(param_1);

      FUN_1401841e0(lVar5);

      FUN_1401841e0(puVar6);

      goto LAB_14019b71a;

    }

  }

LAB_14019b705:

  FUN_1401841e0(lVar5);

  FUN_1401841e0(puVar6);

  if (param_2 == 0) {

    return bVar16;

  }

LAB_14019b71a:

  if (local_res18 == '\0') {

    return bVar16;

  }

  bVar3 = FUN_14012bd50(param_2);

  return (bool)(bVar3 & bVar16);

}




