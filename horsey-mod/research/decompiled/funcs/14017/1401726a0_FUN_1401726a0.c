// Address: 0x1401726a0
// Ghidra name: FUN_1401726a0
// ============ 0x1401726a0 FUN_1401726a0 (size=1047) ============


/* WARNING: Function: __chkstk replaced with injection: alloca_probe */



ulonglong FUN_1401726a0(undefined8 *param_1,undefined1 *param_2)



{

  undefined8 uVar1;

  code *pcVar2;

  char *_Str;

  undefined *puVar3;

  char cVar4;

  byte bVar5;

  char cVar6;

  int iVar7;

  ulonglong uVar8;

  size_t sVar9;

  ulonglong uVar10;

  undefined1 *puVar11;

  longlong lVar12;

  size_t sVar13;

  char *pcVar14;

  undefined8 *puVar15;

  longlong lVar16;

  undefined1 *puVar17;

  undefined1 *puVar18;

  undefined **ppuVar19;

  byte bVar20;

  undefined1 *puVar21;

  undefined1 *puVar22;

  bool bVar23;

  bool bVar24;

  undefined1 auStack_b8 [32];

  undefined1 *local_98;

  undefined1 *local_90;

  undefined1 local_88 [8];

  undefined1 *local_80;

  longlong local_78;

  undefined8 local_70;

  undefined8 uStack_68;

  undefined1 *local_60;

  undefined1 *puStack_58;

  undefined4 local_50;

  undefined4 uStack_4c;

  undefined4 uStack_48;

  undefined4 uStack_44;

  undefined8 local_40;

  

  puVar17 = auStack_b8;

  bVar20 = 0;

  bVar5 = 0;

  if (param_1 == (undefined8 *)0x0) {

    uVar8 = FUN_14012e850("Parameter \'%s\' is invalid","messageboxdata");

    return uVar8;

  }

  if (*(int *)(param_1 + 4) < 0) {

    uVar8 = FUN_14012e850("Invalid number of buttons");

    return uVar8;

  }

  puVar18 = (undefined1 *)0x0;

  bVar23 = false;

  bVar24 = false;

  local_98 = (undefined1 *)0x0;

  local_90 = (undefined1 *)0x0;

  puVar21 = puVar18;

  if ((char *)param_1[2] != (char *)0x0) {

    sVar9 = strlen((char *)param_1[2]);

    uVar8 = sVar9 + 1;

    bVar23 = uVar8 < 0x80;

    if (bVar23) {

      uVar10 = sVar9 + 0x10;

      if (uVar10 <= uVar8) {

        uVar10 = 0xffffffffffffff0;

      }

      puVar11 = (undefined1 *)(uVar10 & 0xfffffffffffffff0);

      puVar17 = auStack_b8 + -(longlong)puVar11;

      puVar21 = (undefined1 *)((longlong)&local_98 + -(longlong)puVar11);

    }

    else {

      puVar11 = (undefined1 *)FUN_1401841f0(uVar8);

      puVar17 = auStack_b8;

      puVar21 = puVar11;

    }

    if (puVar21 == (undefined1 *)0x0) goto LAB_1401727fe;

    uVar1 = param_1[2];

    local_98 = puVar21;

    *(undefined8 *)(puVar17 + -8) = 0x14017278d;

    FUN_1402f8e20(puVar21,uVar1,uVar8);

  }

  pcVar14 = (char *)param_1[3];

  puVar22 = puVar18;

  if (pcVar14 != (char *)0x0) {

    *(undefined8 *)(puVar17 + -8) = 0x14017279b;

    sVar9 = strlen(pcVar14);

    uVar8 = sVar9 + 1;

    bVar24 = uVar8 < 0x80;

    if (bVar24) {

      uVar10 = sVar9 + 0x10;

      if (uVar10 <= uVar8) {

        uVar10 = 0xffffffffffffff0;

      }

      puVar11 = (undefined1 *)(uVar10 & 0xfffffffffffffff0);

      *(undefined8 *)(puVar17 + -8) = 0x1401727cb;

      puVar22 = puVar17 + -(longlong)puVar11 + 0x20;

      puVar17 = puVar17 + -(longlong)puVar11;

    }

    else {

      *(undefined8 *)(puVar17 + -8) = 0x1401727e1;

      puVar11 = (undefined1 *)FUN_1401841f0(uVar8);

      puVar22 = puVar11;

    }

    local_90 = puVar22;

    if (puVar22 == (undefined1 *)0x0) {

      if (!bVar23) {

        *(undefined8 *)(puVar17 + -8) = 0x1401727fe;

        puVar11 = (undefined1 *)FUN_1401841e0(puVar21);

      }

LAB_1401727fe:

      return (ulonglong)puVar11 & 0xffffffffffffff00;

    }

    uVar1 = param_1[3];

    *(undefined8 *)(puVar17 + -8) = 0x140172814;

    FUN_1402f8e20(puVar22,uVar1,uVar8);

  }

  *(undefined8 *)(puVar17 + -8) = 0x140172825;

  FUN_140138fb0(&DAT_1403fc418,1);

  *(undefined8 *)(puVar17 + -8) = 0x14017282a;

  local_78 = FUN_140183290();

  *(undefined8 *)(puVar17 + -8) = 0x140172835;

  FUN_140162f40(0);

  *(undefined8 *)(puVar17 + -8) = 0x14017283c;

  FUN_140162d10(0);

  *(undefined8 *)(puVar17 + -8) = 0x140172841;

  cVar4 = FUN_140160e10();

  *(undefined8 *)(puVar17 + -8) = 0x14017284c;

  FUN_140162e60();

  *(undefined8 *)(puVar17 + -8) = 0x140172851;

  FUN_1401837c0();

  local_70 = *param_1;

  uStack_68 = param_1[1];

  puVar11 = local_88;

  if (param_2 != (undefined1 *)0x0) {

    puVar11 = param_2;

  }

  local_60 = &DAT_14039bcb9;

  if (puVar21 != (undefined1 *)0x0) {

    local_60 = puVar21;

  }

  local_40 = param_1[6];

  puStack_58 = &DAT_14039bcb9;

  if (puVar22 != (undefined1 *)0x0) {

    puStack_58 = puVar22;

  }

  local_50 = *(undefined4 *)(param_1 + 4);

  uStack_4c = *(undefined4 *)((longlong)param_1 + 0x24);

  uStack_48 = *(undefined4 *)(param_1 + 5);

  uStack_44 = *(undefined4 *)((longlong)param_1 + 0x2c);

  local_80 = puVar11;

  *(undefined8 *)(puVar17 + -8) = 0x1401728a6;

  FUN_14012e710();

  if ((DAT_1403fc410 == 0) || (pcVar2 = *(code **)(DAT_1403fc410 + 0x2f0), pcVar2 == (code *)0x0)) {

    *(undefined8 *)(puVar17 + -8) = 0x1401728dc;

    pcVar14 = (char *)FUN_140142960("SDL_VIDEO_DRIVER");

    puVar3 = PTR_PTR_1403e2690;

    if ((pcVar14 != (char *)0x0) && (*pcVar14 != '\0')) {

      while (puVar21 = local_98, *pcVar14 != '\0') {

        if (bVar5 != 0) goto LAB_140172aad;

        *(undefined8 *)(puVar17 + -8) = 0x140172920;

        lVar12 = thunk_FUN_1402c9190(pcVar14,0x2c);

        if (lVar12 == 0) {

          *(undefined8 *)(puVar17 + -8) = 0x140172938;

          sVar9 = strlen(pcVar14);

        }

        else {

          sVar9 = lVar12 - (longlong)pcVar14;

        }

        lVar16 = 0;

        if (PTR_PTR_1403e2690 != (undefined *)0x0) {

          ppuVar19 = &PTR_PTR_1403e2690;

          puVar15 = (undefined8 *)PTR_PTR_1403e2690;

          do {

            if (puVar15[3] != 0) {

              _Str = (char *)*puVar15;

              *(undefined8 *)(puVar17 + -8) = 0x14017295f;

              sVar13 = strlen(_Str);

              if (sVar9 == sVar13) {

                uVar1 = *(undefined8 *)*ppuVar19;

                *(undefined8 *)(puVar17 + -8) = 0x140172975;

                iVar7 = FUN_14012f260(uVar1,pcVar14,sVar9);

                puVar18 = local_80;

                if (iVar7 == 0) {

                  pcVar2 = *(code **)((&PTR_PTR_1403e2690)[lVar16] + 0x18);

                  *(undefined8 *)(puVar17 + -8) = 0x14017299e;

                  cVar6 = (*pcVar2)(&local_70,puVar18);

                  bVar5 = bVar20;

                  if (cVar6 != '\0') {

                    bVar20 = 1;

                    bVar5 = 1;

                  }

                  break;

                }

              }

            }

            lVar16 = lVar16 + 1;

            puVar15 = (undefined8 *)(&PTR_PTR_1403e2690)[lVar16];

            ppuVar19 = &PTR_PTR_1403e2690 + lVar16;

          } while (puVar15 != (undefined8 *)0x0);

        }

        puVar21 = local_98;

        if ((lVar12 == 0) || (pcVar14 = (char *)(lVar12 + 1), pcVar14 == (char *)0x0)) break;

      }

      goto LAB_1401729c3;

    }

    while (puVar3 != (undefined *)0x0) {

      pcVar2 = *(code **)(puVar3 + 0x18);

      if (pcVar2 != (code *)0x0) {

        *(undefined8 *)(puVar17 + -8) = 0x140172a86;

        cVar6 = (*pcVar2)(&local_70,puVar11);

        if (cVar6 != '\0') {

          bVar5 = 1;

          *(undefined8 *)(puVar17 + -8) = 0x140172aa4;

          FUN_14012e710();

          goto LAB_1401729e2;

        }

      }

      ppuVar19 = &PTR_PTR_1403e2698 + (longlong)puVar18;

      puVar18 = puVar18 + 1;

      puVar3 = *ppuVar19;

    }

  }

  else {

    *(undefined8 *)(puVar17 + -8) = 0x1401728c7;

    bVar5 = (*pcVar2)(DAT_1403fc410,&local_70,puVar11);

LAB_1401729c3:

    if (bVar5 != 0) {

LAB_140172aad:

      *(undefined8 *)(puVar17 + -8) = 0x140172ab2;

      FUN_14012e710();

      goto LAB_1401729e2;

    }

  }

  *(undefined8 *)(puVar17 + -8) = 0x1401729d1;

  pcVar14 = (char *)FUN_14012e730();

  if (*pcVar14 == '\0') {

    *(undefined8 *)(puVar17 + -8) = 0x1401729e2;

    FUN_14012e850("No message system available");

  }

LAB_1401729e2:

  *(undefined8 *)(puVar17 + -8) = 0x1401729f3;

  FUN_140138fb0(&DAT_1403fc418,0xffffffff);

  lVar12 = local_78;

  if (local_78 != 0) {

    *(undefined8 *)(puVar17 + -8) = 0x140172a04;

    FUN_14016fa80(lVar12);

  }

  if (cVar4 == '\0') {

    *(undefined8 *)(puVar17 + -8) = 0x140172a12;

    FUN_140161390();

  }

  *(undefined8 *)(puVar17 + -8) = 0x140172a17;

  FUN_1401630f0();

  *(undefined8 *)(puVar17 + -8) = 0x140172a1e;

  FUN_140162f40(0);

  puVar18 = local_90;

  if (!bVar24) {

    *(undefined8 *)(puVar17 + -8) = 0x140172a30;

    FUN_1401841e0(puVar18);

  }

  if (!bVar23) {

    *(undefined8 *)(puVar17 + -8) = 0x140172a41;

    FUN_1401841e0(puVar21);

  }

  return (ulonglong)bVar5;

}




