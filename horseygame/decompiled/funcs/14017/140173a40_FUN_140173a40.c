// Address: 0x140173a40
// Ghidra name: FUN_140173a40
// ============ 0x140173a40 FUN_140173a40 (size=739) ============


undefined8 FUN_140173a40(char *param_1)



{

  undefined *puVar1;

  char cVar2;

  int iVar3;

  longlong lVar4;

  size_t sVar5;

  undefined8 *puVar6;

  undefined8 uVar7;

  undefined8 *puVar8;

  undefined **ppuVar9;

  undefined8 *puVar10;

  char *_Str;

  size_t sVar11;

  undefined8 *puVar12;

  

  puVar6 = (undefined8 *)0x0;

  if (DAT_1403fc410 != (undefined8 *)0x0) {

    FUN_140173d30();

  }

  FUN_1401493a0();

  cVar2 = FUN_14017e460(0x4000);

  if (cVar2 != '\0') {

    cVar2 = FUN_140183480();

    if (cVar2 != '\0') {

      cVar2 = FUN_140161a20();

      if (cVar2 != '\0') {

        cVar2 = FUN_140186520();

        if (cVar2 != '\0') {

          cVar2 = FUN_1401a8370();

          if (cVar2 != '\0') {

            puVar12 = puVar6;

            if (((param_1 == (char *)0x0) &&

                (param_1 = (char *)FUN_140142960("SDL_VIDEO_DRIVER"), puVar1 = PTR_PTR_1403e2690,

                param_1 == (char *)0x0)) ||

               (_Str = param_1, puVar1 = PTR_PTR_1403e2690, *param_1 == '\0')) {

              while (puVar1 != (undefined *)0x0) {

                iVar3 = (int)puVar6;

                puVar6 = (undefined8 *)(**(code **)(puVar1 + 0x10))();

                if (puVar6 != (undefined8 *)0x0) goto LAB_140173bb8;

                ppuVar9 = &PTR_PTR_1403e2698 + (longlong)puVar12;

                puVar6 = (undefined8 *)(ulonglong)(iVar3 + 1);

                puVar12 = (undefined8 *)((longlong)puVar12 + 1);

                puVar1 = *ppuVar9;

              }

            }

            else {

              do {

                puVar10 = (undefined8 *)0x0;

                iVar3 = (int)puVar12;

                if (*_Str == '\0') break;

                if (puVar6 != (undefined8 *)0x0) goto LAB_140173bb8;

                lVar4 = thunk_FUN_1402c9190(_Str,0x2c);

                if (lVar4 == 0) {

                  sVar11 = strlen(_Str);

                }

                else {

                  sVar11 = lVar4 - (longlong)_Str;

                }

                puVar12 = puVar10;

                if (PTR_PTR_1403e2690 != (undefined *)0x0) {

                  ppuVar9 = &PTR_PTR_1403e2690;

                  puVar8 = (undefined8 *)PTR_PTR_1403e2690;

                  do {

                    if (((*(char *)(puVar8 + 4) == '\0') &&

                        (sVar5 = strlen((char *)*puVar8), sVar11 == sVar5)) &&

                       ((iVar3 = FUN_14012f260(*(undefined8 *)*ppuVar9,_Str,sVar11), iVar3 == 0 &&

                        (puVar6 = (undefined8 *)(**(code **)(*ppuVar9 + 0x10))(),

                        puVar6 != (undefined8 *)0x0)))) break;

                    puVar10 = (undefined8 *)((longlong)puVar10 + 1);

                    puVar12 = (undefined8 *)(ulonglong)((int)puVar12 + 1);

                    puVar8 = (undefined8 *)(&PTR_PTR_1403e2690)[(longlong)puVar10];

                    ppuVar9 = &PTR_PTR_1403e2690 + (longlong)puVar10;

                  } while (puVar8 != (undefined8 *)0x0);

                }

                iVar3 = (int)puVar12;

                _Str = (char *)(lVar4 + 1);

                if (lVar4 == 0) {

                  _Str = (char *)0x0;

                }

              } while (_Str != (char *)0x0);

              if (puVar6 != (undefined8 *)0x0) {

LAB_140173bb8:

                FUN_1401aa7a0("video",*(undefined8 *)(&PTR_PTR_1403e2690)[iVar3]);

                DAT_1403fc410 = puVar6;

                *puVar6 = *(undefined8 *)(&PTR_PTR_1403e2690)[iVar3];

                uVar7 = FUN_14017ffb0();

                puVar6[0x62] = uVar7;

                puVar6 = DAT_1403fc410;

                *(undefined4 *)(DAT_1403fc410 + 0x82) = 0;

                puVar6[0xa3] = 0;

                FUN_14016ca90();

                cVar2 = (*(code *)DAT_1403fc410[1])();

                if (cVar2 == '\0') {

                  FUN_140173d30();

                  return 0;

                }

                if (*(int *)(DAT_1403fc410 + 0x65) != 0) {

                  FUN_1401427d0("SDL_VIDEO_SYNC_WINDOW_OPERATIONS",FUN_140172f10,0);

                  cVar2 = FUN_140142940("SDL_VIDEO_ALLOW_SCREENSAVER",0);

                  if (cVar2 == '\0') {

                    FUN_14016b9e0();

                  }

                  FUN_1401619a0();

                  return 1;

                }

                FUN_140173d30();

                uVar7 = FUN_14012e850("The video driver did not add any displays");

                return uVar7;

              }

            }

            if (param_1 == (char *)0x0) {

              FUN_14012e850("No available video device");

            }

            else {

              FUN_14012e850("%s not available",param_1);

            }

            FUN_1401a8390();

          }

          FUN_140186560();

        }

        FUN_140162430();

      }

      FUN_1401835c0();

    }

    FUN_14017e880(0x4000);

  }

  return 0;

}




