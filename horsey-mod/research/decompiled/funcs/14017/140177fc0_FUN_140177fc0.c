// Address: 0x140177fc0
// Ghidra name: FUN_140177fc0
// ============ 0x140177fc0 FUN_140177fc0 (size=450) ============


char * FUN_140177fc0(undefined8 param_1,undefined8 param_2,undefined4 param_3)



{

  longlong *plVar1;

  undefined *puVar2;

  int iVar3;

  char *pcVar4;

  longlong lVar5;

  undefined8 *puVar6;

  size_t sVar7;

  char *pcVar8;

  char *_Str;

  char *pcVar9;

  size_t sVar10;

  char *pcVar11;

  undefined **ppuVar12;

  char *pcVar13;

  

  pcVar13 = (char *)0x0;

  pcVar4 = (char *)FUN_140142960("SDL_STORAGE_USER_DRIVER");

  pcVar9 = pcVar13;

  puVar2 = PTR_PTR_1403e2888;

  if ((pcVar4 == (char *)0x0) || (_Str = pcVar4, pcVar8 = pcVar13, *pcVar4 == '\0')) {

    while (puVar2 != (undefined *)0x0) {

      iVar3 = (int)pcVar9;

      pcVar8 = (char *)(**(code **)(puVar2 + 0x10))(param_1,param_2,param_3);

      if (pcVar8 != (char *)0x0) goto LAB_1401780f6;

      plVar1 = &DAT_1403e2890 + (longlong)pcVar13;

      pcVar13 = pcVar13 + 1;

      pcVar9 = (char *)(ulonglong)(iVar3 + 1);

      puVar2 = (undefined *)*plVar1;

    }

    if (pcVar4 == (char *)0x0) {

      FUN_14012e850("No available user storage driver");

      return (char *)0x0;

    }

  }

  else {

    do {

      iVar3 = (int)pcVar9;

      if (*_Str == '\0') break;

      if (pcVar8 != (char *)0x0) goto LAB_1401780f6;

      lVar5 = thunk_FUN_1402c9190(_Str,0x2c);

      if (lVar5 == 0) {

        sVar10 = strlen(_Str);

      }

      else {

        sVar10 = lVar5 - (longlong)_Str;

      }

      pcVar9 = pcVar13;

      if (PTR_PTR_1403e2888 != (undefined *)0x0) {

        ppuVar12 = &PTR_PTR_1403e2888;

        puVar6 = (undefined8 *)PTR_PTR_1403e2888;

        pcVar11 = pcVar13;

        do {

          sVar7 = strlen((char *)*puVar6);

          if ((sVar10 == sVar7) &&

             (iVar3 = FUN_14012f260(*(undefined8 *)*ppuVar12,_Str,sVar10), iVar3 == 0)) {

            pcVar8 = (char *)(**(code **)((&PTR_PTR_1403e2888)[(longlong)pcVar11] + 0x10))

                                       (param_1,param_2,param_3);

            break;

          }

          pcVar11 = pcVar11 + 1;

          pcVar9 = (char *)(ulonglong)((int)pcVar9 + 1);

          puVar6 = (undefined8 *)(&PTR_PTR_1403e2888)[(longlong)pcVar11];

          ppuVar12 = &PTR_PTR_1403e2888 + (longlong)pcVar11;

        } while (puVar6 != (undefined8 *)0x0);

      }

      iVar3 = (int)pcVar9;

      _Str = (char *)(lVar5 + 1);

      if (lVar5 == 0) {

        _Str = pcVar13;

      }

    } while (_Str != (char *)0x0);

    if (pcVar8 != (char *)0x0) {

LAB_1401780f6:

      FUN_1401aa7a0("user_storage",*(undefined8 *)(&PTR_PTR_1403e2888)[iVar3]);

      return pcVar8;

    }

  }

  FUN_14012e850("%s not available",pcVar4);

  return (char *)0x0;

}




