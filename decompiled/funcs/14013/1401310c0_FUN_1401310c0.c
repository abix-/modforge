// Address: 0x1401310c0
// Ghidra name: FUN_1401310c0
// ============ 0x1401310c0 FUN_1401310c0 (size=935) ============


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



undefined8 FUN_1401310c0(char *param_1)



{

  undefined8 *puVar1;

  undefined *puVar2;

  bool bVar3;

  bool bVar4;

  char cVar5;

  int iVar6;

  longlong lVar7;

  longlong lVar8;

  char *pcVar9;

  undefined1 *puVar10;

  longlong lVar11;

  char *pcVar12;

  undefined **ppuVar13;

  

  lVar7 = FUN_140131d30();

  if (lVar7 != 0) {

    FUN_140132210();

  }

  lVar7 = FUN_14017c930();

  if (lVar7 == 0) {

    return 0;

  }

  lVar8 = FUN_1401aaee0(0,0,&LAB_1401aa980,&LAB_1401aa9c0,FUN_140130970,0);

  if (lVar8 == 0) {

    FUN_14017ca90(lVar7);

    return 0;

  }

  if (param_1 == (char *)0x0) {

    param_1 = (char *)FUN_140142960("SDL_CAMERA_DRIVER");

  }

  bVar4 = false;

  bVar3 = false;

  if ((param_1 == (char *)0x0) || (*param_1 == '\0')) {

    for (ppuVar13 = &PTR_PTR_140317600; puVar2 = *ppuVar13, puVar2 != (undefined *)0x0;

        ppuVar13 = ppuVar13 + 1) {

      if (puVar2[0x18] == '\0') {

        _DAT_1403fb620 = 0;

        bVar4 = true;

        _DAT_1403fb638 = 0;

        DAT_1403fb640 = 0;

        DAT_1403fb648 = &DAT_1403fb638;

        DAT_1403fb5d0 = 0;

        _DAT_1403fb5d8 = 0;

        _DAT_1403fb650 = 0;

        DAT_1403fb5e0 = (code *)0x0;

        DAT_1403fb5e8 = 0;

        DAT_1403fb5f0 = 0;

        DAT_1403fb5f8 = 0;

        DAT_1403fb600 = 0;

        DAT_1403fb608 = 0;

        DAT_1403fb610 = 0;

        DAT_1403fb618 = 0;

        DAT_1403fb628 = lVar7;

        DAT_1403fb630 = lVar8;

        cVar5 = (**(code **)(puVar2 + 0x10))(&DAT_1403fb5e0);

        if (cVar5 != '\0') {

          DAT_1403fb5d0 = *(undefined8 *)*ppuVar13;

          _DAT_1403fb5d8 = *(undefined8 *)((longlong)*ppuVar13 + 8);

          goto LAB_1401313a9;

        }

      }

    }

  }

  else {

    pcVar9 = (char *)FUN_14012f0d0(param_1);

    pcVar12 = pcVar9;

    bVar4 = false;

    if (pcVar9 == (char *)0x0) goto LAB_140131431;

    do {

      if ((*pcVar12 == '\0') || (bVar3)) break;

      puVar10 = (undefined1 *)thunk_FUN_1402c9190(pcVar12,0x2c);

      if (puVar10 != (undefined1 *)0x0) {

        *puVar10 = 0;

      }

      lVar11 = 0;

      puVar1 = (undefined8 *)PTR_PTR_140317600;

      while (puVar1 != (undefined8 *)0x0) {

        iVar6 = FUN_14012ef60(*puVar1,pcVar12);

        if (iVar6 == 0) {

          bVar4 = true;

          _DAT_1403fb650 = 0;

          _DAT_1403fb620 = 0;

          _DAT_1403fb638 = 0;

          DAT_1403fb640 = 0;

          DAT_1403fb648 = &DAT_1403fb638;

          DAT_1403fb5d0 = 0;

          _DAT_1403fb5d8 = 0;

          DAT_1403fb5e0 = (code *)0x0;

          DAT_1403fb5e8 = 0;

          DAT_1403fb5f0 = 0;

          DAT_1403fb5f8 = 0;

          DAT_1403fb600 = 0;

          DAT_1403fb608 = 0;

          DAT_1403fb610 = 0;

          DAT_1403fb618 = 0;

          DAT_1403fb628 = lVar7;

          DAT_1403fb630 = lVar8;

          cVar5 = (**(code **)((&PTR_PTR_140317600)[lVar11] + 0x10))(&DAT_1403fb5e0);

          if (cVar5 != '\0') {

            bVar3 = true;

            DAT_1403fb5d0 = *(undefined8 *)(&PTR_PTR_140317600)[lVar11];

            _DAT_1403fb5d8 = *(undefined8 *)((longlong)(&PTR_PTR_140317600)[lVar11] + 8);

          }

          break;

        }

        ppuVar13 = &PTR_PTR_140317608 + lVar11;

        lVar11 = lVar11 + 1;

        puVar1 = (undefined8 *)*ppuVar13;

      }

      pcVar12 = puVar10 + 1;

      if (puVar10 == (undefined1 *)0x0) {

        pcVar12 = (char *)0x0;

      }

    } while (pcVar12 != (char *)0x0);

    FUN_1401841e0(pcVar9);

    if (bVar3) {

LAB_1401313a9:

      FUN_1401aa7a0("camera",DAT_1403fb5d0);

      (*DAT_1403fb5e0)();

      return 1;

    }

  }

  if (!bVar4) {

    if (param_1 == (char *)0x0) {

      FUN_14012e850("No available camera driver");

    }

    else {

      FUN_14012e850("Camera driver \'%s\' not available",param_1);

    }

  }

  DAT_1403fb5d0 = 0;

  _DAT_1403fb5d8 = 0;

  _DAT_1403fb650 = 0;

  DAT_1403fb5e0 = (code *)0x0;

  DAT_1403fb5e8 = 0;

  DAT_1403fb5f0 = 0;

  DAT_1403fb5f8 = 0;

  DAT_1403fb600 = 0;

  DAT_1403fb608 = 0;

  DAT_1403fb610 = 0;

  DAT_1403fb618 = 0;

  _DAT_1403fb620 = 0;

  DAT_1403fb628 = 0;

  DAT_1403fb630 = 0;

  _DAT_1403fb638 = 0;

  DAT_1403fb640 = 0;

  DAT_1403fb648 = (undefined *)0x0;

LAB_140131431:

  FUN_14017ca90(lVar7);

  FUN_1401aafa0(lVar8);

  return 0;

}




