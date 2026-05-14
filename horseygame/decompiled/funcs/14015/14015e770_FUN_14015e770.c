// Address: 0x14015e770
// Ghidra name: FUN_14015e770
// ============ 0x14015e770 FUN_14015e770 (size=1157) ============


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



undefined8 FUN_14015e770(char *param_1)



{

  undefined *puVar1;

  bool bVar2;

  bool bVar3;

  char cVar4;

  int iVar5;

  longlong lVar6;

  longlong lVar7;

  longlong lVar8;

  char *_Str1;

  undefined1 *puVar9;

  undefined8 *puVar10;

  longlong lVar11;

  char *pcVar12;

  undefined **ppuVar13;

  longlong local_res20;

  longlong local_58;

  char *local_50;

  

  lVar6 = FUN_14015e610();

  if (lVar6 != 0) {

    FUN_14015f4a0();

  }

  FUN_140138fc0(&DAT_1403fc198,0,2);

  FUN_140211380();

  FUN_140214580();

  lVar6 = FUN_14017c930();

  if (lVar6 == 0) {

    return 0;

  }

  lVar7 = FUN_1401aaee0(0,0,&LAB_14015cae0,&LAB_1401aa9c0,0,0);

  if (lVar7 == 0) {

    FUN_14017ca90(lVar6);

    return 0;

  }

  lVar8 = FUN_1401aaee0(0,0,&LAB_14015cae0,&LAB_1401aa9c0,0,0);

  if (lVar8 == 0) {

    FUN_1401aafa0(lVar7);

    FUN_14017ca90(lVar6);

    return 0;

  }

  if (param_1 == (char *)0x0) {

    param_1 = (char *)FUN_140142960("SDL_AUDIO_DRIVER");

  }

  bVar3 = false;

  bVar2 = false;

  if ((param_1 == (char *)0x0) || (*param_1 == '\0')) {

    for (ppuVar13 = &PTR_PTR_140333660; puVar1 = *ppuVar13, puVar1 != (undefined *)0x0;

        ppuVar13 = ppuVar13 + 1) {

      if (puVar1[0x18] == '\0') {

        bVar3 = true;

        FUN_1402f94c0(&DAT_1403fc0a0,0,0xd8);

        DAT_1403fc160 = &DAT_1403fc150;

        DAT_1403fc128 = lVar6;

        DAT_1403fc130 = lVar7;

        DAT_1403fc138 = lVar8;

        cVar4 = (**(code **)(puVar1 + 0x10))(&DAT_1403fc0b0);

        if (cVar4 != '\0') {

          DAT_1403fc0a0 = *(undefined8 *)*ppuVar13;

          _DAT_1403fc0a8 = *(undefined8 *)((longlong)*ppuVar13 + 8);

          goto LAB_14015eac4;

        }

      }

    }

  }

  else {

    _Str1 = (char *)FUN_14012f0d0(param_1);

    local_50 = _Str1;

    bVar3 = false;

    if (_Str1 == (char *)0x0) {

      FUN_14017ca90(lVar6);

      FUN_1401aafa0(lVar7);

      FUN_1401aafa0(lVar8);

      return 0;

    }

    do {

      if ((*_Str1 == '\0') || (bVar2)) break;

      puVar9 = (undefined1 *)thunk_FUN_1402c9190(_Str1,0x2c);

      if (puVar9 != (undefined1 *)0x0) {

        *puVar9 = 0;

      }

      iVar5 = strcmp(_Str1,"dsound");

      if (iVar5 == 0) {

        pcVar12 = "directsound";

      }

      else {

        iVar5 = strcmp(_Str1,"pulse");

        pcVar12 = "pulseaudio";

        if (iVar5 != 0) {

          pcVar12 = _Str1;

        }

      }

      lVar11 = 0;

      if (PTR_PTR_140333660 != (undefined *)0x0) {

        ppuVar13 = &PTR_PTR_140333660;

        puVar10 = (undefined8 *)PTR_PTR_140333660;

        do {

          if ((*(char *)((longlong)puVar10 + 0x19) == '\0') &&

             (iVar5 = FUN_14012ef60(*puVar10,pcVar12), iVar5 == 0)) {

            bVar3 = true;

            FUN_1402f94c0(&DAT_1403fc0a0,0,0xd8);

            DAT_1403fc160 = &DAT_1403fc150;

            DAT_1403fc128 = lVar6;

            DAT_1403fc130 = lVar7;

            DAT_1403fc138 = lVar8;

            cVar4 = (**(code **)(*ppuVar13 + 0x10))(&DAT_1403fc0b0);

            if (cVar4 != '\0') {

              bVar2 = true;

              DAT_1403fc0a0 = *(undefined8 *)(&PTR_PTR_140333660)[lVar11];

              _DAT_1403fc0a8 = *(undefined8 *)((longlong)(&PTR_PTR_140333660)[lVar11] + 8);

              break;

            }

          }

          lVar11 = lVar11 + 1;

          puVar10 = (undefined8 *)(&PTR_PTR_140333660)[lVar11];

          ppuVar13 = &PTR_PTR_140333660 + lVar11;

        } while (puVar10 != (undefined8 *)0x0);

      }

      _Str1 = puVar9 + 1;

      if (puVar9 == (undefined1 *)0x0) {

        _Str1 = (char *)0x0;

      }

    } while (_Str1 != (char *)0x0);

    FUN_1401841e0(local_50);

    if (bVar2) {

LAB_14015eac4:

      FUN_1401aa7a0("audio",DAT_1403fc0a0);

      FUN_14015c3e0();

      local_res20 = 0;

      local_58 = 0;

      (*DAT_1403fc0b0)(&local_res20,&local_58);

      if (local_res20 == 0) {

        local_res20 = FUN_14015ca80(0);

      }

      if (local_58 == 0) {

        local_58 = FUN_14015ca80(1);

      }

      if (local_res20 != 0) {

        DAT_1403fc148 = *(undefined4 *)(local_res20 + 0x50);

        FUN_14015d3d0(local_res20);

      }

      if (local_58 != 0) {

        DAT_1403fc14c = *(undefined4 *)(local_58 + 0x50);

        FUN_14015d3d0();

      }

      return 1;

    }

  }

  if (!bVar3) {

    if (param_1 == (char *)0x0) {

      FUN_14012e850("No available audio device");

    }

    else {

      FUN_14012e850("Audio target \'%s\' not available",param_1);

    }

  }

  FUN_14017ca90(lVar6);

  FUN_1401aafa0(lVar7);

  FUN_1401aafa0(lVar8);

  FUN_1402f94c0(&DAT_1403fc0a0,0,0xd8);

  return 0;

}




