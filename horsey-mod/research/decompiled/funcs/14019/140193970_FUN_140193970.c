// Address: 0x140193970
// Ghidra name: FUN_140193970
// ============ 0x140193970 FUN_140193970 (size=7594) ============


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



ulonglong FUN_140193970(void *param_1,undefined8 param_2,undefined8 param_3)



{

  ushort *puVar1;

  longlong *plVar2;

  longlong *plVar3;

  char cVar4;

  uint uVar5;

  longlong lVar6;

  uint uVar7;

  undefined8 uVar8;

  int iVar9;

  uint uVar10;

  longlong lVar11;

  undefined8 uVar12;

  longlong lVar13;

  ulonglong uVar14;

  ulonglong uVar15;

  ushort *puVar16;

  longlong lVar17;

  ulonglong uVar18;

  uint *puVar19;

  undefined8 *puVar20;

  undefined8 *puVar21;

  uint *puVar22;

  uint uVar23;

  uint *puVar24;

  byte bVar25;

  ushort uVar26;

  undefined2 uVar27;

  short sVar28;

  char cVar29;

  ushort uVar30;

  uint *puVar31;

  longlong lVar32;

  int *piVar33;

  undefined1 uVar34;

  int iVar35;

  int iVar36;

  int iVar37;

  uint *puVar38;

  void *pvVar39;

  longlong lVar40;

  longlong lVar41;

  short sVar42;

  undefined4 uVar43;

  uint *puVar44;

  uint *puVar45;

  ulonglong uVar46;

  ushort uVar47;

  ushort uVar48;

  bool bVar49;

  undefined8 local_res20;

  char local_108;

  uint *local_100;

  undefined8 local_f8;

  undefined8 local_f0;

  ulonglong local_e8;

  ulonglong local_e0;

  uint *local_d8;

  uint *local_d0;

  undefined8 *local_c8;

  longlong local_c0;

  longlong local_b8;

  byte *local_b0;

  ushort *local_a8;

  uint *local_a0;

  longlong local_98;

  longlong local_90;

  longlong local_88;

  longlong local_80;

  longlong local_78;

  longlong alStack_70 [7];

  

  iVar9 = memcmp(param_1,"HidP KDR",8);

  if (iVar9 != 0) {

    return 0xffffffff;

  }

  lVar40 = (ulonglong)*(ushort *)((longlong)param_1 + 0x28) + 0x2c + (longlong)param_1;

  local_e8 = 0;

  local_f8 = param_2;

  local_f0 = param_3;

  local_98 = lVar40;

  lVar11 = FUN_1401841f0((ulonglong)*(ushort *)((longlong)param_1 + 0x2a) << 3);

  uVar18 = 0;

  local_80 = lVar11;

  if (*(short *)((longlong)param_1 + 0x2a) != 0) {

    do {

      plVar2 = (longlong *)(lVar11 + uVar18 * 8);

      lVar40 = FUN_1401841f0(0x800);

      *plVar2 = lVar40;

      lVar40 = 0;

      do {

        lVar13 = *plVar2;

        uVar12 = FUN_1401841f0(0x18);

        *(undefined8 *)(lVar13 + lVar40) = uVar12;

        puVar21 = *(undefined8 **)(lVar40 + *plVar2);

        uVar12 = FUN_1401841f0(8);

        *puVar21 = uVar12;

        *(undefined4 *)**(undefined8 **)(lVar40 + *plVar2) = 0xffffffff;

        *(undefined4 *)(**(longlong **)(lVar40 + *plVar2) + 4) = 0xffffffff;

        lVar13 = *(longlong *)(lVar40 + *plVar2);

        uVar12 = FUN_1401841f0(8);

        *(undefined8 *)(lVar13 + 8) = uVar12;

        **(undefined4 **)(*(longlong *)(lVar40 + *plVar2) + 8) = 0xffffffff;

        *(undefined4 *)(*(longlong *)(*(longlong *)(lVar40 + *plVar2) + 8) + 4) = 0xffffffff;

        lVar13 = *(longlong *)(lVar40 + *plVar2);

        uVar12 = FUN_1401841f0(8);

        *(undefined8 *)(lVar13 + 0x10) = uVar12;

        **(undefined4 **)(*(longlong *)(lVar40 + *plVar2) + 0x10) = 0xffffffff;

        plVar3 = (longlong *)(lVar40 + *plVar2);

        lVar40 = lVar40 + 8;

        *(undefined4 *)(*(longlong *)(*plVar3 + 0x10) + 4) = 0xffffffff;

      } while (lVar40 < 0x800);

      uVar47 = (short)uVar18 + 1;

      uVar18 = (ulonglong)uVar47;

      lVar40 = local_98;

    } while (uVar47 < *(ushort *)((longlong)param_1 + 0x2a));

  }

  uVar47 = *(ushort *)((longlong)param_1 + 0x10);

  if (uVar47 < *(ushort *)((longlong)param_1 + 0x14)) {

    do {

      iVar9 = (uint)*(byte *)((longlong)param_1 + (ulonglong)uVar47 * 0x68 + 0x2f) +

              (*(ushort *)((longlong)param_1 + (ulonglong)uVar47 * 0x68 + 0x34) - 1) * 8;

      iVar37 = (uint)*(ushort *)((longlong)param_1 + (ulonglong)uVar47 * 0x68 + 0x32) *

               (uint)*(ushort *)((longlong)param_1 + (ulonglong)uVar47 * 0x68 + 0x30) + -1 + iVar9;

      piVar33 = (int *)**(undefined8 **)

                         (*(longlong *)

                           (lVar11 + (ulonglong)

                                     *(ushort *)

                                      ((longlong)param_1 + (ulonglong)uVar47 * 0x68 + 0x3e) * 8) +

                         (ulonglong)*(byte *)((longlong)param_1 + (ulonglong)uVar47 * 0x68 + 0x2e) *

                         8);

      iVar36 = *piVar33;

      if ((iVar36 == -1) || (iVar9 < iVar36)) {

        *piVar33 = iVar9;

      }

      lVar13 = **(longlong **)

                 (*(longlong *)

                   (lVar11 + (ulonglong)

                             *(ushort *)((longlong)param_1 + (ulonglong)uVar47 * 0x68 + 0x3e) * 8) +

                 (ulonglong)*(byte *)((longlong)param_1 + (ulonglong)uVar47 * 0x68 + 0x2e) * 8);

      if (*(int *)(lVar13 + 4) < iVar37) {

        *(int *)(lVar13 + 4) = iVar37;

      }

      uVar47 = uVar47 + 1;

    } while (uVar47 < *(ushort *)((longlong)param_1 + 0x14));

  }

  uVar47 = *(ushort *)((longlong)param_1 + 0x18);

  if (uVar47 < *(ushort *)((longlong)param_1 + 0x1c)) {

    do {

      iVar9 = (uint)*(byte *)((longlong)param_1 + (ulonglong)uVar47 * 0x68 + 0x2f) +

              (*(ushort *)((longlong)param_1 + (ulonglong)uVar47 * 0x68 + 0x34) - 1) * 8;

      iVar37 = (uint)*(ushort *)((longlong)param_1 + (ulonglong)uVar47 * 0x68 + 0x32) *

               (uint)*(ushort *)((longlong)param_1 + (ulonglong)uVar47 * 0x68 + 0x30) + -1 + iVar9;

      piVar33 = *(int **)(*(longlong *)

                           (*(longlong *)

                             (lVar11 + (ulonglong)

                                       *(ushort *)

                                        ((longlong)param_1 + (ulonglong)uVar47 * 0x68 + 0x3e) * 8) +

                           (ulonglong)*(byte *)((longlong)param_1 + (ulonglong)uVar47 * 0x68 + 0x2e)

                           * 8) + 8);

      iVar36 = *piVar33;

      if ((iVar36 == -1) || (iVar9 < iVar36)) {

        *piVar33 = iVar9;

      }

      lVar13 = *(longlong *)

                (*(longlong *)

                  (*(longlong *)

                    (lVar11 + (ulonglong)

                              *(ushort *)((longlong)param_1 + (ulonglong)uVar47 * 0x68 + 0x3e) * 8)

                  + (ulonglong)*(byte *)((longlong)param_1 + (ulonglong)uVar47 * 0x68 + 0x2e) * 8) +

                8);

      if (*(int *)(lVar13 + 4) < iVar37) {

        *(int *)(lVar13 + 4) = iVar37;

      }

      uVar47 = uVar47 + 1;

    } while (uVar47 < *(ushort *)((longlong)param_1 + 0x1c));

  }

  uVar47 = *(ushort *)((longlong)param_1 + 0x20);

  if (uVar47 < *(ushort *)((longlong)param_1 + 0x24)) {

    do {

      iVar9 = (uint)*(byte *)((longlong)param_1 + (ulonglong)uVar47 * 0x68 + 0x2f) +

              (*(ushort *)((longlong)param_1 + (ulonglong)uVar47 * 0x68 + 0x34) - 1) * 8;

      iVar37 = (uint)*(ushort *)((longlong)param_1 + (ulonglong)uVar47 * 0x68 + 0x32) *

               (uint)*(ushort *)((longlong)param_1 + (ulonglong)uVar47 * 0x68 + 0x30) + -1 + iVar9;

      piVar33 = *(int **)(*(longlong *)

                           (*(longlong *)

                             (lVar11 + (ulonglong)

                                       *(ushort *)

                                        ((longlong)param_1 + (ulonglong)uVar47 * 0x68 + 0x3e) * 8) +

                           (ulonglong)*(byte *)((longlong)param_1 + (ulonglong)uVar47 * 0x68 + 0x2e)

                           * 8) + 0x10);

      iVar36 = *piVar33;

      if ((iVar36 == -1) || (iVar9 < iVar36)) {

        *piVar33 = iVar9;

      }

      lVar13 = *(longlong *)

                (*(longlong *)

                  (*(longlong *)

                    (lVar11 + (ulonglong)

                              *(ushort *)((longlong)param_1 + (ulonglong)uVar47 * 0x68 + 0x3e) * 8)

                  + (ulonglong)*(byte *)((longlong)param_1 + (ulonglong)uVar47 * 0x68 + 0x2e) * 8) +

                0x10);

      if (*(int *)(lVar13 + 4) < iVar37) {

        *(int *)(lVar13 + 4) = iVar37;

      }

      uVar47 = uVar47 + 1;

    } while (uVar47 < *(ushort *)((longlong)param_1 + 0x24));

  }

  uVar46 = 0;

  lVar13 = FUN_1401841f0((ulonglong)*(ushort *)((longlong)param_1 + 0x2a) << 2);

  local_78 = lVar13;

  local_b8 = FUN_1401841f0((ulonglong)*(ushort *)((longlong)param_1 + 0x2a) << 2);

  uVar48 = 0;

  uVar18 = uVar46;

  uVar15 = uVar46;

  uVar30 = uVar48;

  uVar47 = uVar48;

  if (*(short *)((longlong)param_1 + 0x2a) != 0) {

    do {

      uVar26 = uVar30 + 1;

      *(undefined4 *)(lVar13 + (ulonglong)uVar30 * 4) = 0xffffffff;

      *(undefined4 *)(local_b8 + (ulonglong)uVar30 * 4) = 0;

      uVar30 = uVar26;

    } while (uVar26 < *(ushort *)((longlong)param_1 + 0x2a));

  }

LAB_140193d30:

  do {

    iVar9 = (int)uVar15;

    uVar14 = (ulonglong)uVar47;

    lVar41 = uVar14 * 4;

    iVar36 = (int)uVar18;

    *(int *)(lVar41 + lVar13) = iVar36;

    lVar32 = lVar40 + uVar14 * 0x10;

    if ((*(short *)(lVar40 + 6 + uVar14 * 0x10) == 0) ||

       (*(int *)(lVar13 + (ulonglong)*(ushort *)(lVar32 + 10) * 4) != -1)) {

      if (*(short *)(lVar32 + 8) == 0) {

        if ((int)(iVar36 - 1U) < 0) break;

        uVar18 = (ulonglong)(iVar36 - 1U);

        uVar47 = *(ushort *)(lVar32 + 4);

        goto LAB_140193d30;

      }

      piVar33 = (int *)(local_b8 + (ulonglong)*(ushort *)(lVar32 + 4) * 4);

      *piVar33 = *piVar33 + 1;

      uVar47 = *(ushort *)(lVar32 + 8);

    }

    else {

      uVar23 = iVar36 + 1;

      uVar18 = (ulonglong)uVar23;

      *(uint *)(lVar41 + lVar13) = uVar23;

      if (iVar9 < (int)uVar23) {

        uVar15 = (ulonglong)uVar23;

      }

      *(int *)(lVar41 + local_b8) = *(int *)(lVar41 + local_b8) + 1;

      uVar47 = *(ushort *)(lVar32 + 10);

    }

    iVar9 = (int)uVar15;

  } while (-1 < (int)uVar18);

  uVar47 = *(ushort *)((longlong)param_1 + 0x2a);

  while (iVar9 = iVar9 + -1, -1 < iVar9) {

    bVar49 = uVar47 != 0;

    uVar47 = 0;

    uVar30 = uVar48;

    if (bVar49) {

      do {

        uVar18 = (ulonglong)uVar30;

        if (*(int *)(lVar13 + uVar18 * 4) == iVar9) {

          uVar47 = *(ushort *)(lVar40 + 10 + uVar18 * 0x10);

          while (uVar15 = uVar46, uVar47 != 0) {

            do {

              uVar14 = (ulonglong)uVar47;

              iVar36 = *(int *)**(undefined8 **)(uVar15 + *(longlong *)(lVar11 + uVar14 * 8));

              if ((iVar36 != -1) &&

                 (piVar33 = (int *)**(undefined8 **)(uVar15 + *(longlong *)(lVar11 + uVar18 * 8)),

                 iVar36 < *piVar33)) {

                *piVar33 = iVar36;

              }

              lVar32 = *(longlong *)(lVar11 + uVar18 * 8);

              iVar36 = *(int *)(**(longlong **)(uVar15 + *(longlong *)(lVar11 + uVar14 * 8)) + 4);

              if (*(int *)(**(longlong **)(uVar15 + lVar32) + 4) < iVar36) {

                *(int *)(**(longlong **)(uVar15 + lVar32) + 4) = iVar36;

                lVar32 = *(longlong *)(lVar11 + uVar18 * 8);

              }

              uVar14 = (ulonglong)*(ushort *)(lVar40 + 8 + uVar14 * 0x10);

              iVar36 = **(int **)(*(longlong *)(uVar15 + *(longlong *)(lVar11 + uVar14 * 8)) + 8);

              if ((iVar36 != -1) &&

                 (piVar33 = *(int **)(*(longlong *)(uVar15 + lVar32) + 8), iVar36 < *piVar33)) {

                *piVar33 = iVar36;

              }

              lVar32 = *(longlong *)(lVar11 + uVar18 * 8);

              iVar36 = *(int *)(*(longlong *)

                                 (*(longlong *)(uVar15 + *(longlong *)(lVar11 + uVar14 * 8)) + 8) +

                               4);

              lVar41 = *(longlong *)(*(longlong *)(uVar15 + lVar32) + 8);

              if (*(int *)(lVar41 + 4) < iVar36) {

                *(int *)(lVar41 + 4) = iVar36;

                lVar32 = *(longlong *)(lVar11 + uVar18 * 8);

              }

              uVar14 = (ulonglong)*(ushort *)(lVar40 + 8 + uVar14 * 0x10);

              iVar36 = **(int **)(*(longlong *)(uVar15 + *(longlong *)(lVar11 + uVar14 * 8)) + 0x10)

              ;

              if ((iVar36 != -1) &&

                 (piVar33 = *(int **)(*(longlong *)(uVar15 + lVar32) + 0x10), iVar36 < *piVar33)) {

                *piVar33 = iVar36;

              }

              iVar36 = *(int *)(*(longlong *)

                                 (*(longlong *)(uVar15 + *(longlong *)(lVar11 + uVar14 * 8)) + 0x10)

                               + 4);

              lVar32 = *(longlong *)

                        (*(longlong *)(uVar15 + *(longlong *)(lVar11 + uVar18 * 8)) + 0x10);

              if (*(int *)(lVar32 + 4) < iVar36) {

                *(int *)(lVar32 + 4) = iVar36;

              }

              uVar15 = uVar15 + 8;

              uVar47 = *(ushort *)(lVar40 + 8 + uVar14 * 0x10);

            } while ((longlong)uVar15 < 0x800);

          }

        }

        uVar47 = *(ushort *)((longlong)param_1 + 0x2a);

        uVar30 = uVar30 + 1;

      } while (uVar30 < uVar47);

    }

  }

  lVar13 = FUN_1401841f0((ulonglong)uVar47 << 3);

  local_c0 = lVar13;

  puVar16 = (ushort *)FUN_1401841f0(*(undefined2 *)((longlong)param_1 + 0x2a));

  iVar9 = 0;

  uVar47 = 0;

  uVar18 = 0;

  if (*(short *)((longlong)param_1 + 0x2a) != 0) {

    do {

      uVar30 = (short)uVar18 + 1;

      *(undefined1 *)(uVar18 + (longlong)puVar16) = 0;

      uVar18 = (ulonglong)uVar30;

    } while (uVar30 < *(ushort *)((longlong)param_1 + 0x2a));

  }

  local_e0._0_4_ = 0;

  local_res20 = (uint *)((ulonglong)local_res20 & 0xffffffffffff0000);

  lVar32 = local_b8;

  local_a8 = puVar16;

LAB_140193f90:

  do {

    uVar18 = (ulonglong)uVar47;

    if (*(int *)(lVar32 + uVar18 * 4) == 0) {

LAB_140194130:

      uVar47 = *(ushort *)(lVar40 + 8 + uVar18 * 0x10);

      local_res20 = (uint *)CONCAT62(local_res20._2_6_,uVar47);

      if (uVar47 == 0) {

        iVar9 = iVar9 + -1;

        local_e0._0_4_ = iVar9;

        if (iVar9 < 0) break;

        uVar47 = *(ushort *)(lVar40 + uVar18 * 0x10 + 4);

        local_res20 = (uint *)CONCAT62(local_res20._2_6_,uVar47);

        goto LAB_140193f90;

      }

    }

    else {

      uVar15 = (ulonglong)*(ushort *)(lVar40 + 10 + uVar18 * 0x10);

      iVar9 = (int)local_e0;

      if (*(char *)(uVar15 + (longlong)puVar16) != '\0') goto LAB_140194130;

      *(undefined1 *)(uVar15 + (longlong)puVar16) = 1;

      lVar17 = FUN_1401841f0((longlong)*(int *)(lVar32 + uVar18 * 4) * 2);

      *(longlong *)(lVar13 + uVar18 * 8) = lVar17;

      uVar30 = *(ushort *)(lVar40 + uVar18 * 0x10 + 10);

      lVar41 = (longlong)(*(int *)(lVar32 + uVar18 * 4) + -1) * 2;

      *(ushort *)(lVar17 + lVar41) = uVar30;

      for (uVar30 = *(ushort *)(lVar40 + 8 + (ulonglong)uVar30 * 0x10); uVar30 != 0;

          uVar30 = *(ushort *)(lVar40 + 8 + (ulonglong)uVar30 * 0x10)) {

        lVar41 = lVar41 + -2;

        *(ushort *)(lVar41 + *(longlong *)(lVar13 + uVar18 * 8)) = uVar30;

      }

      iVar9 = *(int *)(lVar32 + (ulonglong)uVar47 * 4);

      if (1 < iVar9) {

        lVar41 = 0;

        plVar2 = (longlong *)(lVar13 + (ulonglong)uVar47 * 8);

        lVar40 = lVar41;

        lVar13 = lVar41;

        do {

          iVar36 = 1;

          if (1 < iVar9) {

            lVar17 = 2;

            do {

              lVar6 = *plVar2;

              uVar30 = *(ushort *)(lVar6 + -2 + lVar17);

              iVar9 = **(int **)(lVar13 + *(longlong *)

                                           (*(longlong *)(lVar11 + (ulonglong)uVar30 * 8) + lVar40))

              ;

              if (((iVar9 != -1) &&

                  (iVar37 = **(int **)(lVar13 + *(longlong *)

                                                 (*(longlong *)

                                                   (lVar11 + (ulonglong)*(ushort *)(lVar6 + lVar17)

                                                             * 8) + lVar40)), iVar37 != -1)) &&

                 (iVar37 < iVar9)) {

                *(ushort *)(lVar6 + -2 + lVar17) = *(ushort *)(lVar6 + lVar17);

                *(ushort *)(lVar17 + *plVar2) = uVar30;

              }

              iVar9 = *(int *)(lVar32 + (ulonglong)uVar47 * 4);

              iVar36 = iVar36 + 1;

              lVar17 = lVar17 + 2;

            } while (iVar36 < iVar9);

          }

          lVar40 = lVar40 + 8;

        } while ((lVar40 < 0x800) || (lVar13 = lVar13 + 8, lVar40 = lVar41, lVar13 < 0x18));

        lVar40 = local_98;

        lVar32 = local_b8;

        lVar13 = local_c0;

        uVar47 = (ushort)local_res20;

      }

      iVar9 = (int)local_e0 + 1;

      uVar47 = *(ushort *)(lVar40 + 10 + (ulonglong)uVar47 * 0x10);

      local_res20 = (uint *)CONCAT62(local_res20._2_6_,uVar47);

      puVar16 = local_a8;

      local_e0._0_4_ = iVar9;

    }

  } while (-1 < iVar9);

  FUN_1401841e0(puVar16);

  puVar31 = (uint *)0x0;

  local_res20 = (uint *)0x0;

  local_c8 = (undefined8 *)FUN_1401841f0((ulonglong)*(ushort *)((longlong)param_1 + 0x2a) << 3);

  local_90 = FUN_1401841f0((ulonglong)*(ushort *)((longlong)param_1 + 0x2a) << 3);

  uVar18 = FUN_1401841f0((ulonglong)*(ushort *)((longlong)param_1 + 0x2a) << 2);

  puVar24 = puVar31;

  if (*(short *)((longlong)param_1 + 0x2a) != 0) {

    do {

      uVar47 = (short)puVar24 + 1;

      *(undefined4 *)(uVar18 + (longlong)puVar24 * 4) = 0xffffffff;

      puVar24 = (uint *)(ulonglong)uVar47;

    } while (uVar47 < *(ushort *)((longlong)param_1 + 0x2a));

  }

  local_100 = (uint *)0x0;

  local_e0 = uVar18;

  uVar12 = FUN_140196850(0,0,2,0,0,3,0,&local_res20);

  local_d0 = local_res20;

  *local_c8 = uVar12;

  puVar24 = puVar31;

  puVar19 = local_res20;

  puVar44 = puVar31;

  puVar45 = puVar31;

  do {

    puVar21 = local_c8;

    iVar9 = *(int *)(local_b8 + (longlong)puVar31 * 4);

    iVar36 = (int)puVar44;

    if ((iVar9 == 0) || (*(int *)(uVar18 + (longlong)puVar31 * 4) != -1)) {

      puVar22 = puVar24;

      if (1 < iVar9) {

        uVar23 = *(uint *)(uVar18 + (longlong)puVar31 * 4);

        puVar16 = *(ushort **)(local_c0 + (longlong)puVar31 * 8);

        if (uVar23 != puVar16[(longlong)iVar9 + -1]) {

          lVar11 = 1;

          uVar47 = *puVar16;

          while (uVar23 != uVar47) {

            puVar1 = puVar16 + 1;

            puVar16 = puVar16 + 1;

            lVar11 = lVar11 + 1;

            uVar47 = *puVar1;

          }

          *(uint *)(uVar18 + (longlong)puVar31 * 4) =

               (uint)*(ushort *)(*(longlong *)(local_c0 + (longlong)puVar31 * 8) + lVar11 * 2);

          uVar47 = *(ushort *)(*(longlong *)(local_c0 + (longlong)puVar31 * 8) + lVar11 * 2);

          uVar15 = (ulonglong)uVar47;

          puVar31 = (uint *)(ulonglong)uVar47;

          local_d8 = (uint *)(uVar15 * 0x10 + 0xc + lVar40);

          if ((*local_d8 & 0x100) == 0) {

            puVar38 = puVar19;

            if (puVar45 != (uint *)0x0) {

              uVar12 = FUN_1401968f0(0,0,2,0,uVar47,6,0,&local_100);

              puVar21 = local_c8;

              local_c8[uVar15] = uVar12;

              uVar12 = FUN_1401968f0(0,0,2,0,uVar47,5,0,&local_100);

              puVar21[uVar15] = uVar12;

              puVar22 = (uint *)0x0;

              puVar45 = (uint *)0x0;

              local_100 = (uint *)0x0;

              puVar38 = puVar24;

              local_res20 = puVar24;

              local_d0 = puVar24;

            }

          }

          else if (puVar45 == (uint *)0x0) {

            local_100 = puVar19;

            uVar12 = FUN_140196850(0,0,2,0,uVar47,6,0,&local_res20);

            puVar21 = local_c8;

            local_c8[uVar15] = uVar12;

            uVar12 = FUN_140196850(0,0,2,0,uVar47,7,0,&local_res20);

            puVar21[uVar15] = uVar12;

            local_d0 = local_res20;

            puVar22 = local_res20;

            puVar38 = local_res20;

            puVar45 = puVar19;

          }

          else {

            uVar12 = FUN_1401968f0(0,0,2,0,uVar47,6,0,&local_100);

            local_c8[uVar15] = uVar12;

            puVar38 = local_d0;

            puVar45 = local_100;

          }

          uVar18 = local_e0;

          if ((*local_d8 & 0x100) == 0) {

            uVar12 = FUN_140196850(0,0,2,0,uVar47,3,0,&local_res20);

            puVar44 = (uint *)(ulonglong)(iVar36 + 1);

            local_d0 = local_res20;

            local_c8[uVar15] = uVar12;

            puVar38 = local_res20;

            uVar18 = local_e0;

          }

          goto LAB_14019433c;

        }

      }

      puVar44 = (uint *)(ulonglong)(iVar36 - 1);

      uVar12 = FUN_140196850(0,0,2,0,(int)puVar31,4,0,&local_res20);

      local_d0 = local_res20;

      *(undefined8 *)(local_90 + (longlong)puVar31 * 8) = uVar12;

      puVar31 = (uint *)(ulonglong)*(ushort *)(lVar40 + 4 + (longlong)puVar31 * 0x10);

      puVar38 = local_res20;

    }

    else {

      *(uint *)(uVar18 + (longlong)puVar31 * 4) =

           (uint)**(ushort **)(local_c0 + (longlong)puVar31 * 8);

      uVar47 = **(ushort **)(local_c0 + (longlong)puVar31 * 8);

      puVar31 = (uint *)(ulonglong)uVar47;

      if (((*(uint *)(lVar40 + 0xc + (longlong)puVar31 * 0x10) & 0x100) == 0) ||

         (puVar45 != (uint *)0x0)) {

        puVar44 = (uint *)(ulonglong)(iVar36 + 1);

        uVar12 = FUN_140196850(0,0,2,0,uVar47,3,0,&local_res20);

      }

      else {

        puVar20 = local_c8 + (longlong)puVar31;

        local_100 = puVar19;

        uVar12 = FUN_140196850(0,0,2,0,uVar47,6,0,&local_res20);

        *puVar20 = uVar12;

        uVar12 = FUN_140196850(0,0,2,0,uVar47,7,0,&local_res20);

        puVar24 = local_res20;

        puVar45 = puVar19;

      }

      local_d0 = local_res20;

      puVar21[(longlong)puVar31] = uVar12;

      puVar22 = puVar24;

      puVar38 = local_res20;

      uVar18 = local_e0;

    }

LAB_14019433c:

    puVar24 = puVar22;

    puVar19 = puVar38;

  } while (-1 < (int)puVar44);

  FUN_1401841e0(uVar18);

  lVar40 = local_80;

  iVar9 = 0;

  lVar11 = -0x14 - (longlong)param_1;

  local_e0 = local_e0 & 0xffffffff00000000;

  local_a8 = (ushort *)((longlong)param_1 + 0x14);

  local_88 = lVar11;

  do {

    puVar24 = (uint *)0x0;

    uVar47 = local_a8[-2];

    local_100 = (uint *)0x0;

    local_a0 = (uint *)0x0;

    if (uVar47 < *local_a8) {

      do {

        iVar35 = 0;

        lVar13 = (ulonglong)uVar47 * 0x68;

        uVar18 = (ulonglong)*(ushort *)(lVar13 + 0x3e + (longlong)param_1);

        local_b0 = (byte *)local_c8[uVar18];

        iVar36 = (uint)*(byte *)(lVar13 + 0x2f + (longlong)param_1) +

                 (*(ushort *)(lVar13 + 0x34 + (longlong)param_1) - 1) * 8;

        local_res20 = (uint *)CONCAT44(local_res20._4_4_,

                                       iVar36 + -1 +

                                       (uint)*(ushort *)(lVar13 + 0x32 + (longlong)param_1) *

                                       (uint)*(ushort *)(lVar13 + 0x30 + (longlong)param_1));

        iVar37 = *(int *)(local_b8 + uVar18 * 4);

        if (0 < iVar37) {

          puVar16 = *(ushort **)

                     (local_c0 + (ulonglong)*(ushort *)(lVar13 + 0x3e + (longlong)param_1) * 8);

          do {

            puVar24 = local_100;

            if (iVar36 < **(int **)((longlong)local_a8 +

                                   *(longlong *)

                                    (*(longlong *)((ulonglong)*puVar16 * 8 + lVar40) +

                                    (ulonglong)*(byte *)(lVar13 + 0x2e + (longlong)param_1) * 8) +

                                   lVar11)) break;

            local_b0 = *(byte **)((ulonglong)*puVar16 * 8 + local_90);

            iVar35 = iVar35 + 1;

            puVar16 = puVar16 + 1;

          } while (iVar35 < iVar37);

        }

        uVar18 = (ulonglong)uVar47;

        uVar34 = *(undefined1 *)((longlong)param_1 + uVar18 * 0x68 + 0x2e);

        puVar19 = (uint *)FUN_140196960(iVar36,iVar9,uVar34,&local_b0);

        puVar31 = local_res20;

        local_b0 = (byte *)((longlong)param_1 + uVar18 * 0x68 + 0x44);

        uVar43 = (undefined4)local_res20;

        local_d8 = puVar19;

        if ((*local_b0 & 0x20) == 0) {

          if (local_100 == (uint *)0x0) goto LAB_140194536;

          FUN_1401968f0(iVar36,(ulonglong)local_res20 & 0xffffffff,0,uVar47,

                        *(undefined2 *)((ulonglong)uVar47 * 0x68 + 0x3e + (longlong)param_1),6,

                        uVar34,&local_d8);

          FUN_1401968f0(iVar36,(ulonglong)puVar31 & 0xffffffff,0,uVar47,

                        *(undefined2 *)((ulonglong)uVar47 * 0x68 + 0x3e + (longlong)param_1),5,

                        *(undefined1 *)((longlong)param_1 + uVar18 * 0x68 + 0x2e),&local_d8);

          local_d8 = local_a0;

          puVar24 = (uint *)0x0;

          local_100 = (uint *)0x0;

          local_a0 = (uint *)0x0;

        }

        else {

          uVar27 = *(undefined2 *)((ulonglong)uVar47 * 0x68 + 0x3e + (longlong)param_1);

          if (puVar24 == (uint *)0x0) {

            FUN_1401968f0(iVar36,(ulonglong)local_res20 & 0xffffffff,0,uVar47,uVar27,6,uVar34,

                          &local_d8);

            FUN_1401968f0(iVar36,(ulonglong)local_res20 & 0xffffffff,0,uVar47,

                          *(undefined2 *)((ulonglong)uVar47 * 0x68 + 0x3e + (longlong)param_1),7,

                          *(undefined1 *)((longlong)param_1 + uVar18 * 0x68 + 0x2e),&local_d8);

            local_a0 = local_d8;

            local_100 = puVar19;

LAB_140194536:

            puVar24 = local_100;

            uVar43 = (undefined4)local_res20;

          }

          else {

            FUN_1401968f0(iVar36,(ulonglong)local_res20 & 0xffffffff,0,uVar47,uVar27,6,uVar34,

                          &local_d8);

          }

        }

        if ((*local_b0 & 0x20) == 0) {

          FUN_1401968f0(iVar36,uVar43,0,uVar47,

                        *(undefined2 *)((ulonglong)uVar47 * 0x68 + 0x3e + (longlong)param_1),

                        (int)local_e0,*(undefined1 *)((longlong)param_1 + uVar18 * 0x68 + 0x2e),

                        &local_d8);

        }

        uVar47 = uVar47 + 1;

        lVar11 = local_88;

        iVar9 = (int)local_e0;

      } while (uVar47 < *local_a8);

    }

    lVar13 = local_98;

    lVar41 = 0;

    iVar9 = iVar9 + 1;

    local_a8 = local_a8 + 4;

    local_e0 = CONCAT44(local_e0._4_4_,iVar9);

    lVar32 = lVar41;

  } while (iVar9 < 3);

  do {

    puVar20 = (undefined8 *)FUN_1401841f0(0x400);

    *(undefined8 **)((longlong)alStack_70 + lVar32) = puVar20;

    puVar21 = (undefined8 *)FUN_1401841f0(0x800);

    uVar8 = _UNK_14033ad68;

    uVar12 = _DAT_14033ad60;

    *(undefined8 **)((longlong)alStack_70 + lVar32 + 0x18) = puVar21;

    if (((undefined8 *)((longlong)puVar20 + 0x3fc) < puVar21) ||

       (lVar40 = lVar41, lVar11 = lVar41, puVar21 + 0xff < puVar20)) {

      lVar40 = 8;

      do {

        *puVar20 = uVar12;

        puVar20[1] = uVar8;

        puVar20[2] = uVar12;

        puVar20[3] = uVar8;

        puVar20[4] = uVar12;

        puVar20[5] = uVar8;

        puVar20[6] = uVar12;

        puVar20[7] = uVar8;

        puVar20[8] = uVar12;

        puVar20[9] = uVar8;

        puVar20[10] = uVar12;

        puVar20[0xb] = uVar8;

        puVar20[0xc] = uVar12;

        puVar20[0xd] = uVar8;

        puVar20[0xe] = uVar12;

        puVar20[0xf] = uVar8;

        lVar40 = lVar40 + -1;

        puVar20 = puVar20 + 0x10;

      } while (lVar40 != 0);

      lVar40 = 0x20;

      do {

        *puVar21 = 0;

        puVar21[1] = 0;

        puVar21[2] = 0;

        puVar21[3] = 0;

        puVar21[4] = 0;

        puVar21[5] = 0;

        puVar21[6] = 0;

        puVar21[7] = 0;

        lVar40 = lVar40 + -1;

        puVar21 = puVar21 + 8;

      } while (lVar40 != 0);

    }

    else {

      do {

        *(undefined4 *)((longlong)puVar20 + lVar40) = 0xffffffff;

        lVar40 = lVar40 + 4;

        *(undefined8 *)((longlong)puVar21 + lVar11) = 0;

        lVar11 = lVar11 + 8;

      } while (lVar40 < 0x400);

    }

    lVar32 = lVar32 + 8;

  } while (lVar32 < 0x18);

  lVar40 = *(longlong *)(local_d0 + 8);

  puVar24 = local_d0;

  while (lVar40 != 0) {

    uVar23 = puVar24[5];

    if (((-1 < (int)uVar23) && ((int)uVar23 < 3)) && (uVar5 = *puVar24, uVar5 != 0xffffffff)) {

      uVar7 = puVar24[6];

      uVar18 = (ulonglong)(byte)uVar7;

      iVar9 = *(int *)(alStack_70[(int)uVar23] + uVar18 * 4);

      uVar10 = iVar9 + 1;

      local_res20._4_4_ = (undefined4)((ulonglong)local_res20 >> 0x20);

      local_res20 = (uint *)CONCAT44(local_res20._4_4_,uVar10);

      if (uVar10 != uVar5) {

        puVar31 = *(uint **)(alStack_70[(longlong)(int)uVar23 + 3] + uVar18 * 8);

        if ((puVar31 != (uint *)0x0) && (*puVar31 != uVar5)) {

          local_a8 = (ushort *)

                     FUN_140196960(iVar9,uVar23,uVar18,

                                   alStack_70[(longlong)(int)uVar23 + 3] + uVar18 * 8);

          FUN_1401968f0((ulonglong)local_res20 & 0xffffffff,uVar5 - 1,1,0xffffffff,0,uVar23,

                        (byte)uVar7,&local_a8);

        }

      }

      *(uint *)(alStack_70[(int)puVar24[5]] + (ulonglong)(byte)puVar24[6] * 4) = puVar24[1];

      *(uint **)(alStack_70[(longlong)(int)puVar24[5] + 3] + (ulonglong)(byte)puVar24[6] * 8) =

           puVar24;

    }

    puVar24 = *(uint **)(puVar24 + 8);

    lVar40 = *(longlong *)(puVar24 + 8);

  }

  uVar15 = 0;

  uVar18 = uVar15;

  do {

    uVar14 = 0;

    piVar33 = *(int **)((longlong)alStack_70 + uVar15);

    uVar46 = uVar14;

    do {

      iVar9 = *piVar33;

      if (iVar9 != -1) {

        uVar23 = iVar9 + 1U & 0x80000007;

        if ((int)uVar23 < 0) {

          uVar23 = (uVar23 - 1 | 0xfffffff8) + 1;

        }

        if ((int)(8 - uVar23) < 8) {

          FUN_1401968f0(iVar9 + 1U,(8 - uVar23) + iVar9,1,0xffffffff,0,(int)uVar18,(char)uVar14,

                        *(longlong *)((longlong)alStack_70 + uVar15 + 0x18) + uVar46);

        }

      }

      uVar23 = (int)uVar14 + 1;

      uVar14 = (ulonglong)uVar23;

      piVar33 = piVar33 + 1;

      uVar46 = uVar46 + 8;

    } while ((int)uVar23 < 0x100);

    FUN_1401841e0(*(undefined8 *)((longlong)alStack_70 + uVar15));

    FUN_1401841e0();

    uVar23 = (int)uVar18 + 1;

    uVar18 = (ulonglong)uVar23;

    uVar15 = uVar15 + 8;

  } while ((int)uVar23 < 3);

  local_e0 = local_e0 & 0xffffffff00000000;

  cVar29 = '\0';

  local_108 = '\0';

  local_res20._0_1_ = '\0';

  sVar42 = 0;

  local_d8 = (uint *)((ulonglong)local_d8 & 0xffffffff00000000);

  iVar9 = 0;

  local_100 = (uint *)((ulonglong)local_100 & 0xffffffff00000000);

  iVar36 = 0;

  do {

    uVar23 = local_d0[5];

    lVar40 = (longlong)(int)local_d0[3];

    if (uVar23 == 3) {

      uVar23 = local_d0[4];

      sVar28 = *(short *)(lVar13 + 2 + (longlong)(int)uVar23 * 0x10);

      puVar24 = local_d0;

      if (sVar42 != sVar28) {

        FUN_1401969b0(4,sVar28,&local_f8);

        uVar23 = puVar24[4];

        sVar42 = *(short *)(lVar13 + 2 + (longlong)(int)uVar23 * 0x10);

      }

      if (cVar29 == '\0') {

        FUN_1401969b0(8,*(undefined2 *)(lVar13 + (longlong)(int)uVar23 * 0x10),&local_f8);

      }

      else {

        cVar29 = '\0';

        local_res20._0_1_ = '\0';

      }

      uVar12 = 0xa0;

      uVar47 = (ushort)*(byte *)(lVar13 + 0xc + (longlong)(int)puVar24[4] * 0x10);

LAB_140194c53:

      FUN_1401969b0(uVar12,uVar47,&local_f8);

    }

    else {

      if (uVar23 == 4) {

        uVar47 = 0;

        uVar12 = 0xc0;

        goto LAB_140194c53;

      }

      if (uVar23 == 5) {

        if (local_d0[4] == 0xffffffff) {

          if (local_d0[3] != 0) {

            pvVar39 = (void *)(lVar40 * 0x68 + (longlong)param_1);

            if (*(short *)((longlong)pvVar39 + 0x2c) != sVar42) {

              FUN_1401969b0(4,*(short *)((longlong)pvVar39 + 0x2c),&local_f8);

              sVar42 = *(short *)((longlong)pvVar39 + 0x2c);

            }

          }

        }

        else {

          sVar28 = *(short *)(lVar13 + 2 + (longlong)(int)local_d0[4] * 0x10);

          if (sVar42 != sVar28) {

            puVar24 = local_d0;

            FUN_1401969b0(4,sVar28,&local_f8);

            sVar42 = *(short *)(lVar13 + 2 + (longlong)(int)puVar24[4] * 0x10);

          }

        }

        uVar47 = 1;

        uVar12 = 0xa8;

        goto LAB_140194c53;

      }

      if (uVar23 == 6) {

        puVar24 = local_d0;

        if (local_d0[4] != 0xffffffff) {

          FUN_1401969b0(8,*(undefined2 *)(lVar13 + (longlong)(int)local_d0[4] * 0x10),&local_f8);

        }

        if (puVar24[3] != 0) {

          pvVar39 = (void *)(lVar40 * 0x68 + (longlong)param_1);

          uVar47 = *(ushort *)((longlong)pvVar39 + 0x68);

          if ((*(byte *)((longlong)pvVar39 + 0x44) & 0x10) == 0) {

            uVar12 = 8;

          }

          else {

            FUN_1401969b0(0x18,uVar47,&local_f8);

            uVar47 = *(ushort *)((longlong)pvVar39 + 0x6a);

            uVar12 = 0x28;

          }

          goto LAB_140194c53;

        }

      }

      else if (uVar23 == 7) {

        FUN_1401969b0(0xa8,0,&local_f8);

        local_res20._0_1_ = '\x01';

        cVar29 = '\x01';

      }

      else if (local_d0[2] == 1) {

        FUN_1401969b0(0x74,(longlong)(int)((local_d0[1] - *local_d0) + 1),&local_f8);

        FUN_1401969b0(0x94,1,&local_f8);

        if (uVar23 == 0) {

          uVar12 = 0x80;

LAB_140194ef8:

          FUN_1401969b0(uVar12,3,&local_f8);

        }

        else {

          if (uVar23 == 1) {

            uVar12 = 0x90;

            goto LAB_140194ef8;

          }

          if (uVar23 == 2) {

            uVar12 = 0xb0;

            goto LAB_140194ef8;

          }

        }

LAB_140194f07:

        iVar36 = 0;

      }

      else {

        lVar11 = lVar40 * 0x68;

        cVar4 = *(char *)(lVar11 + 0x2e + (longlong)param_1);

        if ((*(byte *)(lVar11 + 0x44 + (longlong)param_1) & 4) != 0) {

          if (local_108 != cVar4) {

            FUN_1401969b0(0x84,cVar4,&local_f8);

            local_108 = *(char *)(lVar11 + 0x2e + (longlong)param_1);

          }

          sVar28 = *(short *)(lVar11 + 0x2c + (longlong)param_1);

          if (sVar28 != sVar42) {

            FUN_1401969b0(4,sVar28,&local_f8);

            sVar42 = *(short *)(lVar11 + 0x2c + (longlong)param_1);

          }

          bVar25 = *(byte *)(lVar11 + 0x44 + (longlong)param_1) & 0x10;

          if (bVar25 != 0) {

            iVar36 = iVar36 + ((uint)*(ushort *)(lVar11 + 0x76 + (longlong)param_1) -

                              (uint)*(ushort *)(lVar11 + 0x74 + (longlong)param_1));

          }

          pvVar39 = param_1;

          if (cVar29 == '\0') {

            uVar27 = *(undefined2 *)((lVar40 + 1) * 0x68 + (longlong)param_1);

            if (bVar25 == 0) {

              uVar12 = 8;

            }

            else {

              FUN_1401969b0(0x18,uVar27,&local_f8);

              uVar12 = 0x28;

              uVar27 = *(undefined2 *)(lVar40 * 0x68 + 0x6a + (longlong)param_1);

            }

            FUN_1401969b0(uVar12,uVar27,&local_f8);

          }

          else {

            cVar29 = '\0';

            local_res20._0_1_ = cVar29;

          }

          sVar28 = *(short *)(lVar40 * 0x68 + 0x70 + (longlong)pvVar39);

          if (*(char *)(lVar40 * 0x68 + 0x44 + (longlong)pvVar39) < '\0') {

            FUN_1401969b0(0x48,sVar28,&local_f8);

            uVar12 = 0x58;

            sVar28 = *(short *)(lVar40 * 0x68 + 0x72 + (longlong)param_1);

            pvVar39 = param_1;

LAB_14019502a:

            FUN_1401969b0(uVar12,sVar28,&local_f8);

          }

          else if (sVar28 != 0) {

            uVar12 = 0x38;

            goto LAB_14019502a;

          }

          sVar28 = *(short *)(lVar40 * 0x68 + 0x6c + (longlong)pvVar39);

          if ((*(byte *)(lVar40 * 0x68 + 0x44 + (longlong)pvVar39) & 0x40) == 0) {

            if (sVar28 != 0) {

              uVar12 = 0x78;

              goto LAB_140195078;

            }

          }

          else {

            FUN_1401969b0(0x88,sVar28,&local_f8);

            uVar12 = 0x98;

            sVar28 = *(short *)(lVar40 * 0x68 + 0x6e + (longlong)param_1);

            pvVar39 = param_1;

LAB_140195078:

            FUN_1401969b0(uVar12,sVar28,&local_f8);

          }

          puVar24 = *(uint **)(local_d0 + 8);

          if (((puVar24 != (uint *)0x0) && (puVar24[5] == uVar23)) && (puVar24[2] == 0)) {

            uVar5 = puVar24[3];

            bVar25 = *(byte *)((longlong)pvVar39 + (longlong)(int)uVar5 * 0x68 + 0x44);

            if ((((((bVar25 & 4) != 0) &&

                  ((*(byte *)(lVar40 * 0x68 + 0x44 + (longlong)pvVar39) & 0x10) == 0)) &&

                 ((bVar25 & 0x10) == 0)) &&

                ((*(short *)((longlong)pvVar39 + (longlong)(int)uVar5 * 0x68 + 0x2c) ==

                  *(short *)(lVar40 * 0x68 + 0x2c + (longlong)pvVar39) &&

                 (*(char *)((longlong)pvVar39 + (longlong)(int)uVar5 * 0x68 + 0x2e) ==

                  *(char *)(lVar40 * 0x68 + 0x2e + (longlong)pvVar39))))) &&

               (*(int *)((longlong)pvVar39 + (longlong)(int)uVar5 * 0x68 + 0x38) ==

                *(int *)(lVar40 * 0x68 + 0x38 + (longlong)pvVar39))) {

              if (*puVar24 != *local_d0) {

                iVar36 = iVar36 + 1;

              }

              goto LAB_140194c5a;

            }

          }

          iVar37 = *(int *)(lVar40 * 0x68 + 0x78 + (longlong)pvVar39);

          if ((iVar37 == 0) && (*(int *)(lVar40 * 0x68 + 0x7c + (longlong)pvVar39) == 0)) {

            FUN_1401969b0(0x14,0,&local_f8);

            lVar11 = 1;

          }

          else {

            FUN_1401969b0(0x14,(longlong)iVar37,&local_f8);

            lVar11 = (longlong)*(int *)(lVar40 * 0x68 + 0x7c + (longlong)param_1);

            pvVar39 = param_1;

          }

          FUN_1401969b0(0x24,lVar11,&local_f8);

          FUN_1401969b0(0x74,*(undefined2 *)(lVar40 * 0x68 + 0x30 + (longlong)pvVar39),&local_f8);

          uVar47 = *(ushort *)(lVar40 * 0x68 + 0x32 + (longlong)param_1);

          uVar18 = (ulonglong)uVar47;

          if ((*(byte *)(lVar40 * 0x68 + 0x44 + (longlong)param_1) & 0x10) == 0) {

            uVar18 = (ulonglong)(int)(iVar36 + (uint)uVar47);

          }

          pvVar39 = param_1;

          FUN_1401969b0(0x94,uVar18,&local_f8);

          if ((int)local_e0 != 0) {

            local_e0 = local_e0 & 0xffffffff00000000;

            FUN_1401969b0(0x34,0,&local_f8);

          }

          if ((int)local_d8 != 0) {

            local_d8 = (uint *)((ulonglong)local_d8 & 0xffffffff00000000);

            FUN_1401969b0(0x44,0,&local_f8);

          }

          if (iVar9 != 0) {

            iVar9 = 0;

            FUN_1401969b0(0x54,0,&local_f8);

          }

          if ((int)local_100 != 0) {

            local_100 = (uint *)((ulonglong)local_100 & 0xffffffff00000000);

            FUN_1401969b0(100,0,&local_f8);

          }

          if (uVar23 == 0) {

            FUN_1401969b0(0x80,*(undefined4 *)(lVar40 * 0x68 + 0x38 + (longlong)pvVar39),&local_f8);

            iVar36 = 0;

            cVar29 = (char)local_res20;

          }

          else if (uVar23 == 1) {

            FUN_1401969b0(0x90,*(undefined4 *)(lVar40 * 0x68 + 0x38 + (longlong)pvVar39),&local_f8);

            iVar36 = 0;

            cVar29 = (char)local_res20;

          }

          else {

            if (uVar23 == 2) {

              FUN_1401969b0(0xb0,*(undefined4 *)(lVar40 * 0x68 + 0x38 + (longlong)pvVar39),&local_f8

                           );

            }

            iVar36 = 0;

            cVar29 = (char)local_res20;

          }

          goto LAB_140194c5a;

        }

        if (local_108 != cVar4) {

          FUN_1401969b0(0x84,cVar4,&local_f8);

          local_108 = *(char *)(lVar11 + 0x2e + (longlong)param_1);

        }

        sVar28 = *(short *)(lVar11 + 0x2c + (longlong)param_1);

        if (sVar28 != sVar42) {

          FUN_1401969b0(4,sVar28,&local_f8);

          sVar42 = *(short *)(lVar11 + 0x2c + (longlong)param_1);

        }

        if (cVar29 == '\0') {

          uVar27 = *(undefined2 *)(lVar11 + 0x68 + (longlong)param_1);

          if ((*(byte *)(lVar11 + 0x44 + (longlong)param_1) & 0x10) == 0) {

            uVar12 = 8;

          }

          else {

            FUN_1401969b0(0x18,uVar27,&local_f8);

            uVar12 = 0x28;

            uVar27 = *(undefined2 *)(lVar11 + 0x6a + (longlong)param_1);

          }

          FUN_1401969b0(uVar12,uVar27,&local_f8);

        }

        else {

          cVar29 = '\0';

          local_res20._0_1_ = cVar29;

        }

        sVar28 = *(short *)(lVar40 * 0x68 + 0x70 + (longlong)param_1);

        pvVar39 = param_1;

        if (*(char *)(lVar40 * 0x68 + 0x44 + (longlong)param_1) < '\0') {

          FUN_1401969b0(0x48,sVar28,&local_f8);

          uVar12 = 0x58;

          sVar28 = *(short *)(lVar40 * 0x68 + 0x72 + (longlong)pvVar39);

LAB_140195370:

          FUN_1401969b0(uVar12,sVar28,&local_f8);

        }

        else if (sVar28 != 0) {

          uVar12 = 0x38;

          goto LAB_140195370;

        }

        sVar28 = *(short *)(lVar40 * 0x68 + 0x6c + (longlong)pvVar39);

        if ((*(byte *)(lVar40 * 0x68 + 0x44 + (longlong)pvVar39) & 0x40) == 0) {

          if (sVar28 != 0) {

            uVar12 = 0x78;

            goto LAB_1401953be;

          }

        }

        else {

          FUN_1401969b0(0x88,sVar28,&local_f8);

          uVar12 = 0x98;

          sVar28 = *(short *)(lVar40 * 0x68 + 0x6e + (longlong)param_1);

          pvVar39 = param_1;

LAB_1401953be:

          FUN_1401969b0(uVar12,sVar28,&local_f8);

        }

        if ((*(byte *)(lVar40 * 0x68 + 0x38 + (longlong)pvVar39) & 2) == 0) {

          *(short *)(lVar40 * 0x68 + 0x32 + (longlong)pvVar39) =

               (*(short *)(lVar40 * 0x68 + 0x76 + (longlong)pvVar39) -

               *(short *)(lVar40 * 0x68 + 0x74 + (longlong)pvVar39)) + 1;

        }

        lVar11 = *(longlong *)(local_d0 + 8);

        if (((lVar11 != 0) && (*(uint *)(lVar11 + 0x14) == uVar23)) && (*(int *)(lVar11 + 8) == 0))

        {

          lVar11 = (longlong)*(int *)(lVar11 + 0xc);

          lVar32 = lVar11 * 0x68;

          bVar25 = *(byte *)(lVar32 + 0x44 + (longlong)pvVar39);

          if (((((bVar25 & 4) == 0) &&

               ((*(byte *)(lVar40 * 0x68 + 0x44 + (longlong)pvVar39) & 0x10) == 0)) &&

              (((((bVar25 & 0x10) == 0 &&

                 ((*(short *)(lVar32 + 0x2c + (longlong)pvVar39) ==

                   *(short *)(lVar40 * 0x68 + 0x2c + (longlong)pvVar39) &&

                  (*(int *)(lVar32 + 0x7c + (longlong)pvVar39) ==

                   *(int *)(lVar40 * 0x68 + 0x7c + (longlong)pvVar39))))) &&

                (*(int *)(lVar32 + 0x80 + (longlong)pvVar39) ==

                 *(int *)(lVar40 * 0x68 + 0x80 + (longlong)pvVar39))) &&

               ((((*(int *)(lVar32 + 0x84 + (longlong)pvVar39) ==

                   *(int *)(lVar40 * 0x68 + 0x84 + (longlong)pvVar39) &&

                  (*(int *)(lVar32 + 0x88 + (longlong)pvVar39) ==

                   *(int *)(lVar40 * 0x68 + 0x88 + (longlong)pvVar39))) &&

                 (*(int *)(lVar11 * 0x68 + 0x90 + (longlong)pvVar39) ==

                  *(int *)(lVar40 * 0x68 + 0x90 + (longlong)pvVar39))) &&

                (((*(int *)(lVar11 * 0x68 + 0x8c + (longlong)pvVar39) ==

                   *(int *)(lVar40 * 0x68 + 0x8c + (longlong)pvVar39) &&

                  (*(short *)(lVar11 * 0x68 + 0x30 + (longlong)pvVar39) ==

                   *(short *)(lVar40 * 0x68 + 0x30 + (longlong)pvVar39))) &&

                 ((lVar11 = (longlong)*(int *)(*(longlong *)(local_d0 + 8) + 0xc),

                  *(char *)(lVar11 * 0x68 + 0x2e + (longlong)pvVar39) ==

                  *(char *)(lVar40 * 0x68 + 0x2e + (longlong)pvVar39) &&

                  ((*(int *)(lVar11 * 0x68 + 0x38 + (longlong)pvVar39) ==

                    *(int *)(lVar40 * 0x68 + 0x38 + (longlong)pvVar39) &&

                   (*(short *)(lVar11 * 0x68 + 0x32 + (longlong)pvVar39) == 1)))))))))))) &&

             (*(short *)(lVar40 * 0x68 + 0x32 + (longlong)pvVar39) == 1)) {

            iVar36 = iVar36 + 1;

            goto LAB_140194c5a;

          }

        }

        FUN_1401969b0(0x14,(longlong)*(int *)(lVar40 * 0x68 + 0x7c + (longlong)pvVar39),&local_f8);

        FUN_1401969b0(0x24,(longlong)*(int *)(lVar40 * 0x68 + 0x80 + (longlong)param_1),&local_f8);

        pvVar39 = (void *)(lVar40 * 0x68 + (longlong)param_1);

        if (((int)local_e0 != *(int *)((longlong)pvVar39 + 0x84)) ||

           ((int)local_d8 != *(int *)(lVar40 * 0x68 + 0x88 + (longlong)param_1))) {

          FUN_1401969b0(0x34,(longlong)*(int *)((longlong)pvVar39 + 0x84),&local_f8);

          local_e0 = CONCAT44(local_e0._4_4_,*(undefined4 *)((longlong)pvVar39 + 0x84));

          pvVar39 = (void *)(lVar40 * 0x68 + (longlong)param_1);

          FUN_1401969b0(0x44,(longlong)*(int *)((longlong)pvVar39 + 0x88),&local_f8);

          local_d8 = (uint *)CONCAT44(local_d8._4_4_,*(undefined4 *)((longlong)pvVar39 + 0x88));

        }

        pvVar39 = (void *)(lVar40 * 0x68 + (longlong)param_1);

        if (iVar9 != *(int *)((longlong)pvVar39 + 0x90)) {

          FUN_1401969b0(0x54,*(int *)((longlong)pvVar39 + 0x90),&local_f8);

          iVar9 = *(int *)((longlong)pvVar39 + 0x90);

        }

        pvVar39 = (void *)(lVar40 * 0x68 + (longlong)param_1);

        if ((int)local_100 != *(int *)((longlong)pvVar39 + 0x8c)) {

          FUN_1401969b0(100,*(int *)((longlong)pvVar39 + 0x8c),&local_f8);

          local_100 = (uint *)CONCAT44(local_100._4_4_,*(undefined4 *)((longlong)pvVar39 + 0x8c));

        }

        FUN_1401969b0(0x74,*(undefined2 *)(lVar40 * 0x68 + 0x30 + (longlong)param_1),&local_f8);

        pvVar39 = param_1;

        FUN_1401969b0(0x94,(longlong)

                           (int)((uint)*(ushort *)(lVar40 * 0x68 + 0x32 + (longlong)param_1) +

                                iVar36),&local_f8);

        if (uVar23 == 0) {

          FUN_1401969b0(0x80,*(undefined4 *)(lVar40 * 0x68 + 0x38 + (longlong)pvVar39),&local_f8);

          iVar36 = 0;

        }

        else if (uVar23 == 1) {

          FUN_1401969b0(0x90,*(undefined4 *)(lVar40 * 0x68 + 0x38 + (longlong)pvVar39),&local_f8);

          iVar36 = 0;

        }

        else {

          if (uVar23 != 2) goto LAB_140194f07;

          FUN_1401969b0(0xb0,*(undefined4 *)(lVar40 * 0x68 + 0x38 + (longlong)pvVar39),&local_f8);

          iVar36 = 0;

        }

      }

    }

LAB_140194c5a:

    local_d0 = *(uint **)(local_d0 + 8);

    FUN_1401841e0();

    lVar40 = local_80;

    if (local_d0 == (uint *)0x0) {

      uVar47 = 0;

      if (*(short *)((longlong)param_1 + 0x2a) != 0) {

        do {

          lVar32 = 0;

          uVar18 = (ulonglong)uVar47;

          lVar11 = lVar32;

          lVar13 = lVar32;

          do {

            do {

              FUN_1401841e0(*(undefined8 *)

                             (*(longlong *)(*(longlong *)(lVar40 + uVar18 * 8) + lVar13) + lVar11));

              lVar11 = lVar11 + 8;

            } while (lVar11 < 0x18);

            FUN_1401841e0(*(undefined8 *)(*(longlong *)(lVar40 + uVar18 * 8) + lVar13));

            lVar13 = lVar13 + 8;

            lVar11 = lVar32;

          } while (lVar13 < 0x800);

          FUN_1401841e0(*(undefined8 *)(lVar40 + uVar18 * 8));

          if (*(int *)(local_b8 + uVar18 * 4) != 0) {

            FUN_1401841e0(*(undefined8 *)(local_c0 + uVar18 * 8));

          }

          uVar47 = uVar47 + 1;

        } while (uVar47 < *(ushort *)((longlong)param_1 + 0x2a));

      }

      FUN_1401841e0(lVar40);

      FUN_1401841e0(local_c0);

      FUN_1401841e0(local_c8);

      FUN_1401841e0(local_90);

      FUN_1401841e0(local_78);

      FUN_1401841e0(local_b8);

      return local_e8 & 0xffffffff;

    }

  } while( true );

}




