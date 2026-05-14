// Address: 0x1401452e0
// Ghidra name: FUN_1401452e0
// ============ 0x1401452e0 FUN_1401452e0 (size=2243) ============


/* WARNING: Function: __chkstk replaced with injection: alloca_probe */



uint * FUN_1401452e0(byte *param_1,undefined8 *param_2,uint param_3,int *param_4,int param_5,

                    undefined4 param_6)



{

  undefined1 uVar1;

  void *_Buf2;

  void *_Buf1;

  undefined8 uVar2;

  bool bVar3;

  char cVar4;

  uint uVar5;

  uint uVar6;

  int iVar7;

  undefined4 uVar8;

  undefined4 uVar9;

  char *pcVar10;

  int *piVar11;

  uint *puVar12;

  ulonglong uVar13;

  longlong lVar14;

  longlong lVar15;

  ulonglong uVar16;

  undefined1 *puVar17;

  undefined1 *puVar18;

  ulonglong uVar19;

  int *local_res20;

  undefined1 auStack_c8 [32];

  undefined4 local_a8;

  undefined8 local_a0;

  undefined4 local_98;

  uint local_90;

  int local_88;

  undefined4 local_80;

  undefined8 local_78;

  uint local_70;

  char local_68 [4];

  uint local_64;

  char local_60;

  char local_5f;

  byte local_5e;

  byte local_5d;

  byte local_5c;

  byte local_5b;

  int local_58 [2];

  int *local_50;

  undefined8 local_48;

  undefined4 local_40;

  undefined4 local_3c;

  char *local_38;

  

  uVar19 = 0;

  local_50 = (int *)0x0;

  local_68[0] = '\0';

  local_68[1] = 0;

  local_38 = (char *)0x0;

  local_58[0] = 0;

  cVar4 = FUN_1401489c0();

  if (cVar4 == '\0') {

    FUN_14012e850("Parameter \'%s\' is invalid","surface");

    return (uint *)0x0;

  }

  if (param_3 == 0) {

    FUN_14012e850("Parameter \'%s\' is invalid","format");

    return (uint *)0x0;

  }

  local_40 = *(undefined4 *)(param_1 + 8);

  local_3c = *(undefined4 *)(param_1 + 0xc);

  local_48 = 0;

  if (param_2 == (undefined8 *)0x0) {

    param_2 = &local_48;

  }

  else {

    local_40 = *(undefined4 *)(param_2 + 1);

    local_3c = *(undefined4 *)((longlong)param_2 + 0xc);

  }

  if (param_4 == (int *)0x0) {

    local_res20 = param_4;

    if (((param_3 & 0xf0000000) == 0x10000000) &&

       (((((uVar5 = param_3 & 0xf000000, uVar5 == 0x1000000 || (uVar5 == 0xc000000)) ||

          (uVar5 == 0x2000000)) || (local_res20 = param_4, uVar5 == 0x3000000)) &&

        (piVar11 = (int *)FUN_14017a030(1 << ((byte)(param_3 >> 8) & 0x1f)), local_res20 = param_4,

        local_50 = piVar11, piVar11 != (int *)0x0)))) {

      FUN_14017a190(piVar11);

      local_res20 = piVar11;

    }

  }

  else {

    iVar7 = *param_4;

    uVar13 = uVar19;

    if (0 < iVar7) {

      pcVar10 = (char *)(*(longlong *)(param_4 + 2) + 2);

      uVar16 = uVar19;

      do {

        if (((pcVar10[-2] != -1) || (pcVar10[-1] != -1)) || (*pcVar10 != -1)) break;

        uVar13 = (ulonglong)((int)uVar13 + 1);

        uVar16 = uVar16 + 1;

        pcVar10 = pcVar10 + 4;

      } while ((longlong)uVar16 < (longlong)iVar7);

    }

    local_res20 = param_4;

    if ((int)uVar13 == iVar7) {

      FUN_14012e850("Empty destination palette");

      return (uint *)0x0;

    }

  }

  iVar7 = *(int *)(param_1 + 0x40);

  uVar9 = *(undefined4 *)(param_1 + 0x34);

  if ((*(longlong *)(param_1 + 0x18) == 0) && ((*param_1 & 2) == 0)) {

    local_a8 = 0;

    puVar12 = (uint *)FUN_140145bc0(*(undefined4 *)(param_2 + 1),

                                    *(undefined4 *)((longlong)param_2 + 0xc),param_3,0);

  }

  else {

    puVar12 = (uint *)FUN_140145e60(*(undefined4 *)(param_2 + 1),

                                    *(undefined4 *)((longlong)param_2 + 0xc),param_3);

  }

  puVar18 = auStack_c8;

  if (puVar12 == (uint *)0x0) goto LAB_140145a69;

  if (((param_3 & 0xf0000000) == 0x10000000) &&

     ((((uVar5 = param_3 & 0xf000000, uVar5 == 0x1000000 || (uVar5 == 0xc000000)) ||

       (uVar5 == 0x2000000)) || (uVar5 == 0x3000000)))) {

    FUN_1401487f0(puVar12,local_res20);

  }

  puVar17 = auStack_c8;

  puVar18 = auStack_c8;

  if (param_5 == 0) {

    param_5 = iVar7;

  }

  FUN_1401487a0(puVar12,param_5);

  if (((param_3 & 0xf0000000) == 0x10000000) &&

     ((*(uint *)(param_1 + 4) == 0 || ((*(uint *)(param_1 + 4) & 0xf0000000) == 0x10000000)))) {

    local_5e = param_1[0x110];

    uVar5 = *(uint *)(param_1 + 0x108);

    local_5d = param_1[0x111];

    local_5c = param_1[0x112];

    local_5b = param_1[0x113];

    *(uint *)(param_1 + 0x108) = uVar5 & 0x6000;

    param_1[0x110] = 0xff;

    param_1[0x111] = 0xff;

    param_1[0x112] = 0xff;

    param_1[0x113] = 0xff;

    local_64 = uVar5;

    FUN_14017ba60(param_1 + 0x78);

    puVar17 = auStack_c8;

    if (((*(longlong *)(param_1 + 0x48) != 0) &&

        (((((uVar6 = param_3 & 0xf000000, uVar6 == 0x4000000 || (uVar6 == 0x5000000)) ||

           (uVar6 == 0x6000000)) &&

          ((((uVar6 = param_3 & 0xf00000, uVar6 == 0x300000 || (uVar6 == 0x400000)) ||

            (uVar6 == 0x700000)) || (uVar6 == 0x800000)))) ||

         ((puVar17 = auStack_c8, (param_3 & 0xf000000) + 0xf9000000 < 0x4000001 &&

          (((uVar6 = param_3 & 0xf00000, uVar6 == 0x300000 || (uVar6 == 0x200000)) ||

           ((uVar6 == 0x600000 || (puVar17 = auStack_c8, uVar6 == 0x500000)))))))))) &&

       ((FUN_14017a120(*(undefined8 *)(param_1 + 0x48),&local_60,&local_5f), puVar17 = auStack_c8,

        local_60 != '\0' && (puVar17 = auStack_c8, local_5f == '\0')))) {

      local_58[0] = **(int **)(param_1 + 0x48);

      uVar13 = (ulonglong)local_58[0];

      puVar17 = auStack_c8;

      if (0 < local_58[0]) {

        uVar16 = uVar13 + 0xf;

        if (uVar16 <= uVar13) {

          uVar16 = 0xffffffffffffff0;

        }

        lVar14 = -(uVar16 & 0xfffffffffffffff0);

        pcVar10 = local_68 + lVar14;

        uVar16 = uVar19;

        puVar17 = auStack_c8 + lVar14;

        local_38 = pcVar10;

        if (0 < (longlong)uVar13) {

          do {

            pcVar10[uVar16] =

                 *(char *)(*(longlong *)(*(longlong *)(param_1 + 0x48) + 8) + 3 + uVar16 * 4);

            *(undefined1 *)(*(longlong *)(*(longlong *)(param_1 + 0x48) + 8) + 3 + uVar16 * 4) =

                 0xff;

            uVar16 = uVar16 + 1;

            puVar17 = auStack_c8 + lVar14;

          } while ((longlong)uVar16 < (longlong)uVar13);

        }

      }

    }

    if ((((uVar5 >> 10 & 1) != 0) && (*(longlong *)(param_1 + 0x48) != 0)) &&

       (local_res20 == (int *)0x0)) {

      lVar14 = *(longlong *)(*(longlong *)(param_1 + 0x48) + 8);

      local_68[0] = '\x01';

      local_68[1] = *(undefined1 *)(lVar14 + 3 + (ulonglong)*(uint *)(param_1 + 0x10c) * 4);

      *(undefined1 *)(lVar14 + 3 + (ulonglong)*(uint *)(param_1 + 0x10c) * 4) = 0;

    }

    if ((*(longlong *)(param_1 + 0x18) == 0) && ((*param_1 & 2) == 0)) {

      cVar4 = '\x01';

    }

    else {

      *(undefined8 *)(puVar17 + -8) = 0x1401456dc;

      cVar4 = FUN_140144330(param_1,param_2,puVar12,&local_48);

    }

    if (local_68[0] != '\0') {

      *(char *)(*(longlong *)(*(longlong *)(param_1 + 0x48) + 8) + 3 +

               (ulonglong)*(uint *)(param_1 + 0x10c) * 4) = local_68[1];

    }

    if ((local_38 != (char *)0x0) && (uVar13 = uVar19, 0 < (longlong)local_58[0])) {

      do {

        *(char *)(*(longlong *)(*(longlong *)(param_1 + 0x48) + 8) + 3 + uVar13 * 4) =

             local_38[uVar13];

        uVar13 = uVar13 + 1;

      } while ((longlong)uVar13 < (longlong)local_58[0]);

    }

    *(byte *)(puVar12 + 0x44) = local_5e;

    puVar12[0x42] = uVar5 & 0xffff8bef;

    *(byte *)((longlong)puVar12 + 0x111) = local_5d;

    *(byte *)((longlong)puVar12 + 0x112) = local_5c;

    *(byte *)((longlong)puVar12 + 0x113) = local_5b;

    param_1[0x110] = local_5e;

    param_1[0x111] = local_5d;

    param_1[0x112] = local_5c;

    param_1[0x113] = local_5b;

    *(uint *)(param_1 + 0x108) = uVar5;

    *(undefined8 *)(puVar17 + -8) = 0x140145790;

    FUN_14017ba60(param_1 + 0x78);

    puVar18 = puVar17;

    if (cVar4 == '\0') goto LAB_140145a69;

    if ((uVar5 >> 10 & 1) != 0) {

      piVar11 = *(int **)(param_1 + 0x48);

      bVar3 = true;

      if (piVar11 != (int *)0x0) {

        if (local_res20 == (int *)0x0) {

          uVar5 = local_64;

          if (((((param_3 & 0xf000000) == 0x4000000) ||

               (((param_3 & 0xf000000) + 0xfb000000 & 0xfeffffff) == 0)) &&

              ((uVar6 = param_3 & 0xf00000, uVar6 == 0x300000 ||

               (((uVar6 == 0x400000 || (uVar6 == 0x700000)) || (uVar6 == 0x800000)))))) ||

             ((((param_3 & 0xf000000) == 0x7000000 ||

               (((param_3 & 0xf000000) + 0xf8000000 & 0xfcffffff) == 0)) &&

              ((uVar6 = param_3 & 0xf00000, uVar6 == 0x300000 ||

               (((uVar6 == 0x200000 || (uVar6 == 0x600000)) || (uVar6 == 0x500000))))))))

          goto LAB_140145800;

          bVar3 = false;

        }

        else {

          iVar7 = *piVar11;

          if (iVar7 <= *local_res20) {

            _Buf2 = *(void **)(local_res20 + 2);

            _Buf1 = *(void **)(piVar11 + 2);

            *(undefined8 *)(puVar17 + -8) = 0x1401457e1;

            iVar7 = memcmp(_Buf1,_Buf2,(longlong)iVar7 << 2);

            if (iVar7 == 0) {

              uVar9 = *(undefined4 *)(param_1 + 0x10c);

              *(undefined8 *)(puVar17 + -8) = 0x1401457fc;

              FUN_140148630(puVar12,1,uVar9);

              uVar5 = local_64;

              goto LAB_140145800;

            }

          }

        }

      }

      uVar9 = *(undefined4 *)(param_1 + 4);

      local_58[0] = 0;

      *(undefined8 *)(puVar17 + -8) = 0x140145a06;

      lVar14 = FUN_140145e60(1,1,uVar9);

      if (lVar14 == 0) goto LAB_140145a69;

      if (*(longlong *)(param_1 + 0x48) != 0) {

        *(undefined8 *)(puVar17 + -8) = 0x140145a1f;

        FUN_1401487f0(lVar14);

      }

      uVar9 = *(undefined4 *)(param_1 + 0x10c);

      *(undefined8 *)(puVar17 + -8) = 0x140145a30;

      FUN_14017dc90(lVar14,0,uVar9);

      *(uint *)(lVar14 + 0x108) = *(uint *)(lVar14 + 0x108) & 0xfffffbff;

      *(undefined4 *)(puVar17 + 0x20) = param_6;

      *(undefined8 *)(puVar17 + -8) = 0x140145a59;

      lVar15 = FUN_140145220(lVar14,param_3,local_res20,param_5);

      if (lVar15 == 0) {

        *(undefined8 *)(puVar17 + -8) = 0x140145a69;

        FUN_140146010(lVar14);

        goto LAB_140145a69;

      }

      uVar2 = *(undefined8 *)(lVar15 + 0x18);

      uVar1 = *(undefined1 *)(*(longlong *)(lVar15 + 0x38) + 5);

      *(undefined8 *)(puVar17 + -8) = 0x140145abc;

      FUN_1402f8e20(local_58,uVar2,uVar1);

      *(undefined8 *)(puVar17 + -8) = 0x140145ac4;

      FUN_140146010(lVar14);

      *(undefined8 *)(puVar17 + -8) = 0x140145acc;

      FUN_140146010(lVar15);

      iVar7 = local_58[0];

      *(undefined8 *)(puVar17 + -8) = 0x140145ada;

      FUN_140148630(puVar12,1,iVar7);

      uVar5 = local_64;

      if (bVar3) {

        *(undefined8 *)(puVar17 + -8) = 0x140145aed;

        FUN_140144a40(puVar12,1);

        uVar5 = local_64;

      }

    }

  }

  else if ((*(int *)(param_1 + 4) == 0x47504a4d) && (param_3 == 0x47504a4d)) {

    iVar7 = *(int *)(param_1 + 0x10);

    lVar14 = FUN_1401841f0((longlong)iVar7);

    *(longlong *)(puVar12 + 6) = lVar14;

    puVar18 = auStack_c8;

    if (lVar14 == 0) goto LAB_140145a69;

    *puVar12 = *puVar12 & 0xfffffffe;

    puVar12[4] = *(uint *)(param_1 + 0x10);

    FUN_1402f8e20(lVar14,*(undefined8 *)(param_1 + 0x18),(longlong)iVar7);

    puVar17 = auStack_c8;

    uVar5 = *(uint *)(param_1 + 0x108);

  }

  else {

    local_70 = puVar12[4];

    local_78 = *(undefined8 *)(puVar12 + 6);

    local_80 = param_6;

    local_90 = puVar12[1];

    local_98 = *(undefined4 *)(param_1 + 0x10);

    local_a0 = *(undefined8 *)(param_1 + 0x18);

    local_a8 = uVar9;

    local_88 = param_5;

    cVar4 = FUN_140144d60(*(undefined4 *)(param_1 + 8),*(undefined4 *)(param_1 + 0xc),

                          *(int *)(param_1 + 4),iVar7);

    if (cVar4 == '\0') goto LAB_140145a69;

    uVar5 = *(uint *)(param_1 + 0x108);

  }

LAB_140145800:

  piVar11 = local_50;

  if (local_50 != (int *)0x0) {

    *(undefined8 *)(puVar17 + -8) = 0x140145811;

    FUN_14017a0f0(piVar11);

  }

  *(undefined8 *)(puVar17 + -8) = 0x14014581d;

  FUN_1401485c0(puVar12,param_1 + 100);

  if ((param_3 & 0xf0000000) == 0x10000000) {

    if (((param_3 & 0xf000000) != 0x4000000) &&

       (((param_3 & 0xf000000) + 0xfb000000 & 0xfeffffff) != 0)) goto LAB_140145876;

    uVar6 = param_3 & 0xf00000;

    if ((uVar6 != 0x300000) && (((uVar6 != 0x400000 && (uVar6 != 0x700000)) && (uVar6 != 0x800000)))

       ) goto LAB_140145868;

LAB_1401458bc:

    *(undefined8 *)(puVar17 + -8) = 0x1401458c9;

    FUN_140148450(puVar12,1);

  }

  else {

LAB_140145868:

    if ((param_3 & 0xf0000000) == 0x10000000) {

LAB_140145876:

      if ((((param_3 & 0xf000000) == 0x7000000) ||

          (((param_3 & 0xf000000) + 0xf8000000 & 0xfcffffff) == 0)) &&

         (((param_3 = param_3 & 0xf00000, param_3 == 0x300000 ||

           ((param_3 == 0x200000 || (param_3 == 0x600000)))) || (param_3 == 0x500000))))

      goto LAB_1401458bc;

    }

    if ((uVar5 & 2) != 0) goto LAB_1401458bc;

  }

  if ((uVar5 >> 0xc & 1) != 0) {

    *(undefined8 *)(puVar17 + -8) = 0x1401458da;

    FUN_1401488a0(puVar12,1);

  }

  uVar13 = uVar19;

  puVar18 = puVar17;

  if (0 < *(int *)(param_1 + 0x50)) {

    do {

      uVar2 = *(undefined8 *)(*(longlong *)(param_1 + 0x58) + uVar19);

      *(undefined8 *)(puVar17 + -8) = 0x140145900;

      cVar4 = FUN_140142ea0(puVar12,uVar2);

      if (cVar4 == '\0') goto LAB_140145a69;

      uVar5 = (int)uVar13 + 1;

      uVar19 = uVar19 + 8;

      uVar13 = (ulonglong)uVar5;

    } while ((int)uVar5 < *(int *)(param_1 + 0x50));

  }

  if (*(int *)(param_1 + 0x34) == 0) {

    return puVar12;

  }

  uVar9 = *(undefined4 *)(param_1 + 0x34);

  *(undefined8 *)(puVar17 + -8) = 0x140145926;

  uVar8 = FUN_140146bc0(puVar12);

  *(undefined8 *)(puVar17 + -8) = 0x14014592f;

  cVar4 = FUN_1401745f0(uVar9,uVar8);

  if (cVar4 != '\0') {

    *(undefined8 *)(puVar17 + -8) = 0x14014593f;

    uVar9 = FUN_140146bc0(puVar12);

    *(undefined8 *)(puVar17 + -8) = 0x14014594d;

    FUN_1401745e0(uVar9,"sdl2-compat.surface2");

    return puVar12;

  }

LAB_140145a69:

  piVar11 = local_50;

  if (local_50 != (int *)0x0) {

    *(undefined8 *)(puVar18 + -8) = 0x140145a7a;

    FUN_14017a0f0(piVar11);

  }

  if (puVar12 != (uint *)0x0) {

    *(undefined8 *)(puVar18 + -8) = 0x140145a87;

    FUN_140146010(puVar12);

  }

  return (uint *)0x0;

}




