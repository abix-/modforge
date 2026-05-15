// Address: 0x1401d1440
// Ghidra name: FUN_1401d1440
// ============ 0x1401d1440 FUN_1401d1440 (size=5361) ============


/* WARNING: Removing unreachable block (ram,0x0001401d1916) */

/* WARNING: Removing unreachable block (ram,0x0001401d1b20) */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



undefined1 FUN_1401d1440(longlong param_1,int *param_2,byte *param_3,int *param_4)



{

  byte bVar1;

  byte bVar2;

  byte bVar3;

  ushort uVar4;

  undefined2 uVar5;

  int iVar6;

  longlong lVar7;

  uint uVar8;

  uint uVar9;

  uint uVar10;

  uint uVar11;

  uint *puVar12;

  uint *puVar13;

  uint uVar14;

  uint uVar15;

  uint uVar16;

  char cVar17;

  uint uVar18;

  uint uVar19;

  longlong lVar20;

  int iVar21;

  int iVar22;

  int iVar23;

  uint uVar24;

  longlong lVar25;

  uint *puVar26;

  uint uVar27;

  int iVar28;

  ulonglong uVar29;

  undefined1 *puVar30;

  int iVar31;

  uint uVar32;

  int iVar33;

  uint *puVar34;

  uint *puVar35;

  ushort *puVar36;

  ushort *puVar37;

  uint uVar38;

  uint uVar39;

  uint uVar40;

  ulonglong uVar41;

  uint *puVar42;

  undefined1 auVar43 [16];

  uint uVar44;

  uint uVar45;

  uint uVar46;

  uint uVar47;

  uint uVar48;

  uint uVar49;

  uint uVar50;

  uint uVar51;

  uint uVar52;

  undefined1 auVar53 [16];

  undefined1 auVar54 [16];

  undefined1 auVar55 [16];

  undefined1 auVar56 [16];

  longlong local_b8;

  int local_b0;

  ulonglong local_80;

  ulonglong local_78;

  ulonglong local_68;

  

  iVar6 = *(int *)(param_1 + 8);

  if (((*param_3 & 2) != 0) && (cVar17 = FUN_140146f20(param_3), cVar17 == '\0')) {

    return 0;

  }

  iVar28 = DAT_1403e8ad0;

  uVar44 = _UNK_14034a94c;

  uVar16 = _UNK_14034a948;

  uVar15 = _UNK_14034a944;

  uVar14 = _DAT_14034a940;

  uVar24 = _UNK_14034a93c;

  uVar45 = _UNK_14034a938;

  uVar40 = _UNK_14034a934;

  uVar39 = _DAT_14034a930;

  uVar11 = _UNK_14034a92c;

  uVar10 = _UNK_14034a928;

  uVar9 = _UNK_14034a924;

  uVar8 = _DAT_14034a920;

  uVar18 = _UNK_14033c2bc;

  uVar32 = _UNK_14033c2b8;

  uVar38 = _UNK_14033c2b4;

  uVar19 = _DAT_14033c2b0;

  iVar31 = 0;

  iVar33 = param_2[1];

  bVar1 = *(byte *)(*(longlong *)(param_1 + 0x38) + 5);

  puVar26 = (uint *)(*(longlong *)(param_1 + 0x88) + 4);

  lVar25 = (longlong)(*(int *)(param_3 + 0x10) * param_4[1]) +

           (longlong)(int)((uint)bVar1 * *param_4) + *(longlong *)(param_3 + 0x18);

  if (iVar33 != 0) {

    if (bVar1 == 1) {

      do {

        do {

          bVar1 = *(byte *)((longlong)puVar26 + 1);

          iVar31 = iVar31 + (uint)(byte)*puVar26;

          puVar26 = (uint *)((longlong)puVar26 + 2);

          if (bVar1 == 0) {

            if (iVar31 == 0) goto LAB_1401d2920;

          }

          else {

            puVar26 = (uint *)((longlong)puVar26 + (ulonglong)bVar1);

            iVar31 = iVar31 + (uint)bVar1;

          }

        } while (iVar31 != iVar6);

        iVar31 = 0;

        iVar33 = iVar33 + -1;

      } while (iVar33 != 0);

    }

    else if (bVar1 == 2) {

      do {

        do {

          bVar1 = *(byte *)((longlong)puVar26 + 1);

          iVar31 = iVar31 + (uint)(byte)*puVar26;

          puVar26 = (uint *)((longlong)puVar26 + 2);

          if (bVar1 == 0) {

            if (iVar31 == 0) goto LAB_1401d2920;

          }

          else {

            puVar26 = (uint *)((longlong)puVar26 + (ulonglong)((uint)bVar1 + (uint)bVar1));

            iVar31 = iVar31 + (uint)bVar1;

          }

        } while (iVar31 != iVar6);

        iVar31 = 0;

        iVar33 = iVar33 + -1;

      } while (iVar33 != 0);

    }

    else if (bVar1 == 3) {

      do {

        do {

          bVar1 = *(byte *)((longlong)puVar26 + 1);

          iVar31 = iVar31 + (uint)(byte)*puVar26;

          puVar26 = (uint *)((longlong)puVar26 + 2);

          if (bVar1 == 0) {

            if (iVar31 == 0) goto LAB_1401d2920;

          }

          else {

            puVar26 = (uint *)((longlong)puVar26 + (ulonglong)((uint)bVar1 + (uint)bVar1 * 2));

            iVar31 = iVar31 + (uint)bVar1;

          }

        } while (iVar31 != iVar6);

        iVar31 = 0;

        iVar33 = iVar33 + -1;

      } while (iVar33 != 0);

    }

    else if (bVar1 == 4) {

      do {

        do {

          uVar4 = *(ushort *)((longlong)puVar26 + 2);

          iVar31 = iVar31 + (uint)(ushort)*puVar26;

          puVar26 = puVar26 + 1;

          if (uVar4 == 0) {

            if (iVar31 == 0) goto LAB_1401d2920;

          }

          else {

            puVar26 = (uint *)((longlong)puVar26 + (ulonglong)((uint)uVar4 * 4));

            iVar31 = iVar31 + (uint)uVar4;

          }

        } while (iVar31 != iVar6);

        iVar31 = 0;

        iVar33 = iVar33 + -1;

      } while (iVar33 != 0);

    }

  }

  bVar1 = *(byte *)(param_1 + 0x113);

  uVar46 = CONCAT31(0,bVar1);

  auVar56[4] = bVar1;

  auVar56._0_4_ = uVar46;

  auVar56._5_3_ = 0;

  auVar56[8] = bVar1;

  auVar56._9_3_ = 0;

  auVar56[0xc] = bVar1;

  auVar56._13_3_ = 0;

  if ((*param_2 == 0) && (param_2[2] == *(int *)(param_1 + 8))) {

    lVar7 = *(longlong *)(param_1 + 0x38);

    cVar17 = *(char *)(lVar7 + 5);

    uVar27 = (uint)bVar1;

    local_b8 = lVar25;

    if (uVar27 == 0xff) {

      if (cVar17 == '\x01') {

        iVar33 = param_2[3];

        iVar28 = 0;

        do {

          do {

            bVar1 = *(byte *)((longlong)puVar26 + 1);

            iVar28 = iVar28 + (uint)(byte)*puVar26;

            puVar26 = (uint *)((longlong)puVar26 + 2);

            if (bVar1 == 0) {

              if (iVar28 == 0) goto LAB_1401d2920;

            }

            else {

              FUN_1402f8e20(iVar28 + lVar25,puVar26,(ulonglong)bVar1);

              puVar26 = (uint *)((longlong)puVar26 + (ulonglong)bVar1);

              iVar28 = iVar28 + (uint)bVar1;

              lVar25 = local_b8;

            }

          } while (iVar28 != iVar6);

          iVar28 = 0;

          lVar25 = lVar25 + *(int *)(param_3 + 0x10);

          iVar33 = iVar33 + -1;

          local_b8 = lVar25;

        } while (iVar33 != 0);

      }

      else if (cVar17 == '\x02') {

        iVar33 = param_2[3];

        iVar28 = 0;

        do {

          do {

            bVar1 = *(byte *)((longlong)puVar26 + 1);

            iVar28 = iVar28 + (uint)(byte)*puVar26;

            puVar26 = (uint *)((longlong)puVar26 + 2);

            if (bVar1 == 0) {

              if (iVar28 == 0) goto LAB_1401d2920;

            }

            else {

              FUN_1402f8e20(iVar28 * 2 + lVar25,puVar26,(ulonglong)bVar1 * 2);

              puVar26 = (uint *)((longlong)puVar26 + (ulonglong)((uint)bVar1 + (uint)bVar1));

              iVar28 = iVar28 + (uint)bVar1;

              lVar25 = local_b8;

            }

          } while (iVar28 != iVar6);

          iVar28 = 0;

          lVar25 = lVar25 + *(int *)(param_3 + 0x10);

          iVar33 = iVar33 + -1;

          local_b8 = lVar25;

        } while (iVar33 != 0);

      }

      else if (cVar17 == '\x03') {

        iVar33 = param_2[3];

        iVar28 = 0;

        do {

          do {

            bVar1 = *(byte *)((longlong)puVar26 + 1);

            iVar28 = iVar28 + (uint)(byte)*puVar26;

            puVar26 = (uint *)((longlong)puVar26 + 2);

            if (bVar1 == 0) {

              if (iVar28 == 0) goto LAB_1401d2920;

            }

            else {

              FUN_1402f8e20(iVar28 * 3 + lVar25,puVar26,(ulonglong)bVar1 * 3);

              puVar26 = (uint *)((longlong)puVar26 + (ulonglong)((uint)bVar1 + (uint)bVar1 * 2));

              iVar28 = iVar28 + (uint)bVar1;

              lVar25 = local_b8;

            }

          } while (iVar28 != iVar6);

          iVar28 = 0;

          lVar25 = lVar25 + *(int *)(param_3 + 0x10);

          iVar33 = iVar33 + -1;

          local_b8 = lVar25;

        } while (iVar33 != 0);

      }

      else if (cVar17 == '\x04') {

        iVar33 = param_2[3];

        iVar28 = 0;

        do {

          do {

            uVar4 = *(ushort *)((longlong)puVar26 + 2);

            iVar28 = iVar28 + (uint)(ushort)*puVar26;

            puVar26 = puVar26 + 1;

            if (uVar4 == 0) {

              if (iVar28 == 0) goto LAB_1401d2920;

            }

            else {

              FUN_1402f8e20(iVar28 * 4 + lVar25,puVar26,(ulonglong)uVar4 << 2);

              puVar26 = (uint *)((longlong)puVar26 + (ulonglong)((uint)uVar4 * 4));

              iVar28 = iVar28 + (uint)uVar4;

              lVar25 = local_b8;

            }

          } while (iVar28 != iVar6);

          iVar28 = 0;

          lVar25 = lVar25 + *(int *)(param_3 + 0x10);

          iVar33 = iVar33 + -1;

          local_b8 = lVar25;

        } while (iVar33 != 0);

      }

    }

    else if (cVar17 == '\x02') {

      uVar19 = *(uint *)(lVar7 + 0x10);

      uVar38 = *(uint *)(lVar7 + 0xc);

      uVar32 = *(uint *)(lVar7 + 8);

      uVar18 = uVar19 | uVar38 | uVar32;

      if (uVar18 == 0x7fff) {

        if (((uVar38 == 0x3e0) || (uVar32 == 0x3e0)) || (uVar19 == 0x3e0)) {

          iVar33 = param_2[3];

          if (uVar27 == 0x80) {

            iVar28 = 0;

            do {

              do {

                bVar1 = *(byte *)((longlong)puVar26 + 1);

                uVar19 = (uint)bVar1;

                iVar28 = iVar28 + (uint)(byte)*puVar26;

                puVar42 = (uint *)((longlong)puVar26 + 2);

                if (bVar1 == 0) {

                  if (iVar28 == 0) goto LAB_1401d2920;

                }

                else {

                  puVar34 = (uint *)(iVar28 * 2 + lVar25);

                  lVar25 = local_b8;

                  if ((((byte)puVar34 ^ (byte)puVar42) & 3) == 0) {

                    puVar35 = puVar42;

                    uVar38 = uVar19;

                    if (((ulonglong)puVar42 & 3) != 0) {

                      puVar35 = puVar26 + 1;

                      uVar38 = uVar19 - 1;

                      *(ushort *)puVar34 =

                           (short)((*(ushort *)puVar42 & 0xfbde) + ((ushort)*puVar34 & 0xfbde) >> 1)

                           + (*(ushort *)puVar42 & (ushort)*puVar34 & 0x421);

                      puVar34 = (uint *)((longlong)puVar34 + 2);

                    }

                    if (1 < uVar38) {

                      uVar29 = (ulonglong)((uVar38 - 2 >> 1) + 1);

                      do {

                        uVar32 = *puVar35;

                        uVar38 = uVar38 - 2;

                        puVar35 = puVar35 + 1;

                        *puVar34 = (*puVar34 >> 1 & 0x7def7def) + (uVar32 >> 1 & 0x7def7def) +

                                   (*puVar34 & uVar32 & 0x4210421);

                        puVar34 = puVar34 + 1;

                        uVar29 = uVar29 - 1;

                      } while (uVar29 != 0);

                    }

                    if (uVar38 != 0) {

                      *(ushort *)puVar34 =

                           (short)(((ushort)*puVar34 & 0xfbde) + ((ushort)*puVar35 & 0xfbde) >> 1) +

                           ((ushort)*puVar34 & (ushort)*puVar35 & 0x421);

                    }

                    puVar42 = (uint *)((longlong)puVar42 + (ulonglong)(uVar19 * 2));

                    iVar28 = iVar28 + (uint)bVar1;

                  }

                  else {

                    puVar26 = puVar34;

                    uVar38 = uVar19;

                    do {

                      uVar4 = *(ushort *)

                               ((longlong)puVar26 + ((longlong)puVar42 - (longlong)puVar34));

                      *(ushort *)puVar26 =

                           (short)(((ushort)*puVar26 & 0xfbde) + (uVar4 & 0xfbde) >> 1) +

                           ((ushort)*puVar26 & uVar4 & 0x421);

                      uVar38 = uVar38 - 1;

                      puVar26 = (uint *)((longlong)puVar26 + 2);

                    } while (uVar38 != 0);

                    puVar42 = (uint *)((longlong)puVar42 + (ulonglong)(uVar19 * 2));

                    iVar28 = iVar28 + (uint)bVar1;

                  }

                }

                puVar26 = puVar42;

              } while (iVar28 != iVar6);

              iVar28 = 0;

              lVar25 = lVar25 + *(int *)(param_3 + 0x10);

              iVar33 = iVar33 + -1;

              local_b8 = lVar25;

            } while (iVar33 != 0);

          }

          else {

            iVar28 = 0;

            do {

              do {

                bVar2 = *(byte *)((longlong)puVar26 + 1);

                iVar28 = iVar28 + (uint)(byte)*puVar26;

                puVar26 = (uint *)((longlong)puVar26 + 2);

                if (bVar2 == 0) {

                  if (iVar28 == 0) goto LAB_1401d2920;

                }

                else {

                  puVar36 = (ushort *)(iVar28 * 2 + lVar25);

                  uVar19 = (uint)bVar2;

                  if (uVar19 != 0) {

                    uVar29 = (ulonglong)uVar19;

                    puVar37 = puVar36;

                    do {

                      uVar5 = *(undefined2 *)

                               ((longlong)puVar37 + ((longlong)puVar26 - (longlong)puVar36));

                      uVar38 = CONCAT22(*puVar37,*puVar37) & 0x3e07c1f;

                      uVar38 = (((CONCAT22(uVar5,uVar5) & 0x3e07c1f) - uVar38) * (uint)(bVar1 >> 3)

                               >> 5) + uVar38 & 0x3e07c1f;

                      *puVar37 = (ushort)(uVar38 >> 0x10) | (ushort)uVar38;

                      uVar29 = uVar29 - 1;

                      lVar25 = local_b8;

                      puVar37 = puVar37 + 1;

                    } while (uVar29 != 0);

                  }

                  puVar26 = (uint *)((longlong)puVar26 + (ulonglong)((uint)bVar2 + (uint)bVar2));

                  iVar28 = iVar28 + uVar19;

                }

              } while (iVar28 != iVar6);

              iVar28 = 0;

              lVar25 = lVar25 + *(int *)(param_3 + 0x10);

              iVar33 = iVar33 + -1;

              local_b8 = lVar25;

            } while (iVar33 != 0);

          }

          goto LAB_1401d2920;

        }

      }

      else if ((uVar18 == 0xffff) && (((uVar38 == 0x7e0 || (uVar32 == 0x7e0)) || (uVar19 == 0x7e0)))

              ) {

        iVar33 = param_2[3];

        if (bVar1 == 0x80) {

          iVar28 = 0;

          do {

            do {

              bVar1 = *(byte *)((longlong)puVar26 + 1);

              uVar19 = (uint)bVar1;

              iVar28 = iVar28 + (uint)(byte)*puVar26;

              puVar42 = (uint *)((longlong)puVar26 + 2);

              if (bVar1 == 0) {

                if (iVar28 == 0) goto LAB_1401d2920;

              }

              else {

                puVar34 = (uint *)(iVar28 * 2 + lVar25);

                lVar25 = local_b8;

                if ((((byte)puVar34 ^ (byte)puVar42) & 3) == 0) {

                  puVar35 = puVar42;

                  uVar38 = uVar19;

                  if (((ulonglong)puVar42 & 3) != 0) {

                    puVar35 = puVar26 + 1;

                    uVar38 = uVar19 - 1;

                    *(ushort *)puVar34 =

                         (short)((*(ushort *)puVar42 & 0xf7de) + ((ushort)*puVar34 & 0xf7de) >> 1) +

                         (*(ushort *)puVar42 & (ushort)*puVar34 & 0x821);

                    puVar34 = (uint *)((longlong)puVar34 + 2);

                  }

                  if (1 < uVar38) {

                    uVar29 = (ulonglong)((uVar38 - 2 >> 1) + 1);

                    do {

                      uVar38 = uVar38 - 2;

                      uVar32 = *puVar35;

                      puVar35 = puVar35 + 1;

                      *puVar34 = (*puVar34 & uVar32 & 0x8210821) + (*puVar34 >> 1 & 0x7bef7bef) +

                                 (uVar32 >> 1 & 0x7bef7bef);

                      puVar34 = puVar34 + 1;

                      uVar29 = uVar29 - 1;

                    } while (uVar29 != 0);

                  }

                  if (uVar38 != 0) {

                    *(ushort *)puVar34 =

                         (short)(((ushort)*puVar34 & 0xf7de) + ((ushort)*puVar35 & 0xf7de) >> 1) +

                         ((ushort)*puVar34 & (ushort)*puVar35 & 0x821);

                  }

                  puVar42 = (uint *)((longlong)puVar42 + (ulonglong)(uVar19 * 2));

                  iVar28 = iVar28 + (uint)bVar1;

                }

                else {

                  puVar26 = puVar34;

                  uVar38 = uVar19;

                  do {

                    uVar4 = *(ushort *)((longlong)puVar26 + ((longlong)puVar42 - (longlong)puVar34))

                    ;

                    *(ushort *)puVar26 =

                         (short)((uVar4 & 0xf7de) + ((ushort)*puVar26 & 0xf7de) >> 1) +

                         (uVar4 & (ushort)*puVar26 & 0x821);

                    uVar38 = uVar38 - 1;

                    puVar26 = (uint *)((longlong)puVar26 + 2);

                  } while (uVar38 != 0);

                  puVar42 = (uint *)((longlong)puVar42 + (ulonglong)(uVar19 * 2));

                  iVar28 = iVar28 + (uint)bVar1;

                }

              }

              puVar26 = puVar42;

            } while (iVar28 != iVar6);

            iVar28 = 0;

            lVar25 = lVar25 + *(int *)(param_3 + 0x10);

            iVar33 = iVar33 + -1;

            local_b8 = lVar25;

          } while (iVar33 != 0);

        }

        else {

          iVar28 = 0;

          do {

            do {

              bVar2 = *(byte *)((longlong)puVar26 + 1);

              iVar28 = iVar28 + (uint)(byte)*puVar26;

              puVar26 = (uint *)((longlong)puVar26 + 2);

              if (bVar2 == 0) {

                if (iVar28 == 0) goto LAB_1401d2920;

              }

              else {

                puVar36 = (ushort *)(iVar28 * 2 + lVar25);

                uVar19 = (uint)bVar2;

                if (uVar19 != 0) {

                  uVar29 = (ulonglong)uVar19;

                  puVar37 = puVar36;

                  do {

                    uVar5 = *(undefined2 *)

                             (((longlong)puVar26 - (longlong)puVar36) + (longlong)puVar37);

                    uVar38 = CONCAT22(*puVar37,*puVar37) & 0x7e0f81f;

                    uVar38 = (((CONCAT22(uVar5,uVar5) & 0x7e0f81f) - uVar38) * (uint)(bVar1 >> 3) >>

                             5) + uVar38 & 0x7e0f81f;

                    *puVar37 = (ushort)(uVar38 >> 0x10) | (ushort)uVar38;

                    uVar29 = uVar29 - 1;

                    lVar25 = local_b8;

                    puVar37 = puVar37 + 1;

                  } while (uVar29 != 0);

                }

                puVar26 = (uint *)((longlong)puVar26 + (ulonglong)((uint)bVar2 + (uint)bVar2));

                iVar28 = iVar28 + uVar19;

              }

            } while (iVar28 != iVar6);

            iVar28 = 0;

            lVar25 = lVar25 + *(int *)(param_3 + 0x10);

            iVar33 = iVar33 + -1;

            local_b8 = lVar25;

          } while (iVar33 != 0);

        }

        goto LAB_1401d2920;

      }

      iVar33 = param_2[3];

      iVar28 = 0;

      local_b0 = iVar33;

      do {

        do {

          bVar1 = *(byte *)((longlong)puVar26 + 1);

          local_78 = (ulonglong)bVar1;

          uVar19 = *puVar26;

          puVar26 = (uint *)((longlong)puVar26 + 2);

          iVar28 = iVar28 + (uint)(byte)uVar19;

          if (bVar1 == 0) {

            if (iVar28 == 0) goto LAB_1401d2920;

          }

          else {

            puVar36 = (ushort *)(iVar28 * 2 + lVar25);

            if (bVar1 != 0) {

              lVar20 = (longlong)puVar26 - (longlong)puVar36;

              do {

                uVar29 = (ulonglong)*puVar36;

                bVar2 = *(byte *)(lVar7 + 0x1c);

                bVar3 = *(byte *)(lVar7 + 0x1e);

                uVar19 = (uint)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar7 + 0x19)]

                                     [(*(uint *)(lVar7 + 0xc) & uVar29) >>

                                      (*(byte *)(lVar7 + 0x1d) & 0x3f)];

                uVar41 = (ulonglong)*(ushort *)(lVar20 + (longlong)puVar36);

                uVar32 = (uint)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar7 + 0x18)]

                                     [(uVar29 & *(uint *)(lVar7 + 8)) >> (bVar2 & 0x3f)];

                uVar38 = (uint)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar7 + 0x1a)]

                                     [(*(uint *)(lVar7 + 0x10) & uVar29) >> (bVar3 & 0x3f)];

                *puVar36 = (short)((((byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar7 + 0x18)]

                                           [(*(uint *)(lVar7 + 8) & uVar41) >> (bVar2 & 0x3f)] -

                                    uVar32) * uVar46 >> 8) + uVar32 >>

                                  (8 - *(byte *)(lVar7 + 0x18) & 0x1f)) << (bVar2 & 0x1f) |

                           (short)((((byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar7 + 0x1a)]

                                           [(*(uint *)(lVar7 + 0x10) & uVar41) >> (bVar3 & 0x3f)] -

                                    uVar38) * uVar46 >> 8) + uVar38 >>

                                  (8 - *(byte *)(lVar7 + 0x1a) & 0x1f)) << (bVar3 & 0x1f) |

                           (short)((((byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar7 + 0x19)]

                                           [(*(uint *)(lVar7 + 0xc) & uVar41) >>

                                            (*(byte *)(lVar7 + 0x1d) & 0x3f)] - uVar19) * uVar46 >>

                                   8) + uVar19 >> (8U - *(char *)(lVar7 + 0x19) & 0x1f)) <<

                           (*(byte *)(lVar7 + 0x1d) & 0x1f) | *(ushort *)(lVar7 + 0x14);

                puVar36 = puVar36 + 1;

                local_78 = local_78 - 1;

                lVar25 = local_b8;

              } while (local_78 != 0);

            }

            puVar26 = (uint *)((longlong)puVar26 + (ulonglong)((uint)bVar1 * 2));

            iVar28 = iVar28 + (uint)bVar1;

            iVar33 = local_b0;

          }

        } while (iVar28 != iVar6);

        iVar28 = 0;

        lVar25 = lVar25 + *(int *)(param_3 + 0x10);

        iVar33 = iVar33 + -1;

        local_b8 = lVar25;

        local_b0 = iVar33;

      } while (iVar33 != 0);

    }

    else if (cVar17 == '\x03') {

      iVar33 = param_2[3];

      iVar28 = 0;

      local_b0 = iVar33;

      do {

        do {

          local_68 = (ulonglong)*(byte *)((longlong)puVar26 + 1);

          puVar42 = (uint *)((longlong)puVar26 + 2);

          iVar28 = iVar28 + (uint)(byte)*puVar26;

          uVar19 = (uint)*(byte *)((longlong)puVar26 + 1);

          if (uVar19 == 0) {

            if (iVar28 == 0) goto LAB_1401d2920;

          }

          else {

            puVar30 = (undefined1 *)(iVar28 * 3 + lVar25);

            lVar25 = ((longlong)(iVar28 * 3) - (longlong)puVar42) + lVar25;

            do {

              puVar34 = (uint *)((longlong)puVar26 + 3);

              bVar1 = *(byte *)(lVar7 + 0x1c);

              bVar2 = *(byte *)(lVar7 + 0x1e);

              uVar29 = (ulonglong)

                       CONCAT21(CONCAT11(*(byte *)((longlong)puVar26 + lVar25 + 4),

                                         *(byte *)((longlong)puVar34 + lVar25)),*puVar30);

              uVar38 = (uint)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar7 + 0x19)]

                                   [(uVar29 & *(uint *)(lVar7 + 0xc)) >>

                                    (*(byte *)(lVar7 + 0x1d) & 0x3f)];

              uVar41 = (ulonglong)*(uint3 *)((longlong)puVar26 + 2);

              uVar18 = (uint)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar7 + 0x18)]

                                   [(uVar29 & *(uint *)(lVar7 + 8)) >> (bVar1 & 0x3f)];

              uVar32 = (uint)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar7 + 0x1a)]

                                   [(uVar29 & *(uint *)(lVar7 + 0x10)) >> (bVar2 & 0x3f)];

              uVar38 = ((((byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar7 + 0x18)]

                                [(uVar41 & *(uint *)(lVar7 + 8)) >> (bVar1 & 0x3f)] - uVar18) *

                         uVar46 >> 8) + uVar18 >> (8 - *(byte *)(lVar7 + 0x18) & 0x1f)) <<

                       (bVar1 & 0x1f) |

                       ((((byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar7 + 0x1a)]

                                [(uVar41 & *(uint *)(lVar7 + 0x10)) >> (bVar2 & 0x3f)] - uVar32) *

                         uVar46 >> 8) + uVar32 >> (8 - *(byte *)(lVar7 + 0x1a) & 0x1f)) <<

                       (bVar2 & 0x1f) |

                       ((((byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar7 + 0x19)]

                                [(uVar41 & *(uint *)(lVar7 + 0xc)) >>

                                 (*(byte *)(lVar7 + 0x1d) & 0x3f)] - uVar38) * uVar46 >> 8) + uVar38

                       >> (8U - *(char *)(lVar7 + 0x19) & 0x1f)) << (*(byte *)(lVar7 + 0x1d) & 0x1f)

                       | *(uint *)(lVar7 + 0x14);

              *puVar30 = (char)uVar38;

              puVar30 = puVar30 + 3;

              *(byte *)((longlong)puVar34 + lVar25) = (byte)(uVar38 >> 8);

              *(byte *)((longlong)puVar26 + lVar25 + 4) = (byte)(uVar38 >> 0x10);

              local_68 = local_68 - 1;

              puVar26 = puVar34;

            } while (local_68 != 0);

            puVar42 = (uint *)((longlong)puVar42 + (ulonglong)(uVar19 * 3));

            iVar28 = iVar28 + uVar19;

            lVar25 = local_b8;

            iVar33 = local_b0;

          }

          puVar26 = puVar42;

        } while (iVar28 != iVar6);

        iVar28 = 0;

        lVar25 = lVar25 + *(int *)(param_3 + 0x10);

        iVar33 = iVar33 + -1;

        local_b8 = lVar25;

        local_b0 = iVar33;

      } while (iVar33 != 0);

    }

    else if (cVar17 == '\x04') {

      if (((*(uint *)(lVar7 + 0x10) | *(uint *)(lVar7 + 0xc) | *(uint *)(lVar7 + 8)) == 0xffffff) &&

         (((*(uint *)(lVar7 + 0xc) == 0xff00 || (*(uint *)(lVar7 + 8) == 0xff00)) ||

          (*(uint *)(lVar7 + 0x10) == 0xff00)))) {

        iVar33 = param_2[3];

        if (bVar1 == 0x80) {

          iVar28 = 0;

          do {

            do {

              uVar4 = *(ushort *)((longlong)puVar26 + 2);

              iVar28 = iVar28 + (uint)(ushort)*puVar26;

              puVar26 = puVar26 + 1;

              if (uVar4 == 0) {

                if (iVar28 == 0) goto LAB_1401d2920;

              }

              else {

                iVar21 = 0;

                puVar34 = (uint *)(iVar28 * 4 + lVar25);

                uVar19 = (uint)uVar4;

                uVar38 = (uint)uVar4;

                puVar42 = puVar26;

                iVar31 = iVar21;

                if (((uVar19 != 0) && (iVar31 = 0, 0xf < uVar19)) &&

                   ((puVar26 + ((ulonglong)uVar4 - 1) < puVar34 ||

                    (puVar34 + ((ulonglong)uVar4 - 1) < puVar26)))) {

                  do {

                    iVar21 = iVar21 + 0x10;

                    uVar32 = puVar42[1];

                    uVar18 = puVar42[2];

                    uVar8 = puVar42[3];

                    uVar9 = puVar42[4];

                    uVar10 = puVar42[5];

                    uVar11 = puVar42[6];

                    uVar46 = puVar42[7];

                    *puVar34 = ((uVar14 & *puVar34) + (uVar14 & *puVar42) >> 1) +

                               (*puVar34 & *puVar42 & uVar39);

                    puVar34[1] = ((uVar15 & puVar34[1]) + (uVar15 & uVar32) >> 1) +

                                 (puVar34[1] & uVar32 & uVar40);

                    puVar34[2] = ((uVar16 & puVar34[2]) + (uVar16 & uVar18) >> 1) +

                                 (puVar34[2] & uVar18 & uVar45);

                    puVar34[3] = ((uVar44 & puVar34[3]) + (uVar44 & uVar8) >> 1) +

                                 (puVar34[3] & uVar8 & uVar24);

                    uVar32 = puVar42[8];

                    uVar18 = puVar42[9];

                    uVar8 = puVar42[10];

                    uVar27 = puVar42[0xb];

                    puVar34[4] = ((uVar14 & puVar34[4]) + (uVar14 & uVar9) >> 1) +

                                 (puVar34[4] & uVar9 & uVar39);

                    puVar34[5] = ((uVar15 & puVar34[5]) + (uVar15 & uVar10) >> 1) +

                                 (puVar34[5] & uVar10 & uVar40);

                    puVar34[6] = ((uVar16 & puVar34[6]) + (uVar16 & uVar11) >> 1) +

                                 (puVar34[6] & uVar11 & uVar45);

                    puVar34[7] = ((uVar44 & puVar34[7]) + (uVar44 & uVar46) >> 1) +

                                 (puVar34[7] & uVar46 & uVar24);

                    uVar9 = puVar42[0xc];

                    uVar10 = puVar42[0xd];

                    uVar11 = puVar42[0xe];

                    uVar46 = puVar42[0xf];

                    puVar42 = puVar42 + 0x10;

                    puVar34[8] = ((uVar14 & puVar34[8]) + (uVar14 & uVar32) >> 1) +

                                 (puVar34[8] & uVar32 & uVar39);

                    puVar34[9] = ((uVar15 & puVar34[9]) + (uVar15 & uVar18) >> 1) +

                                 (puVar34[9] & uVar18 & uVar40);

                    puVar34[10] = ((uVar16 & puVar34[10]) + (uVar16 & uVar8) >> 1) +

                                  (puVar34[10] & uVar8 & uVar45);

                    puVar34[0xb] = ((uVar44 & puVar34[0xb]) + (uVar44 & uVar27) >> 1) +

                                   (puVar34[0xb] & uVar27 & uVar24);

                    puVar34[0xc] = ((uVar14 & puVar34[0xc]) + (uVar14 & uVar9) >> 1) +

                                   (puVar34[0xc] & uVar9 & uVar39);

                    puVar34[0xd] = ((uVar15 & puVar34[0xd]) + (uVar15 & uVar10) >> 1) +

                                   (puVar34[0xd] & uVar10 & uVar40);

                    puVar34[0xe] = ((uVar16 & puVar34[0xe]) + (uVar16 & uVar11) >> 1) +

                                   (puVar34[0xe] & uVar11 & uVar45);

                    puVar34[0xf] = ((uVar44 & puVar34[0xf]) + (uVar44 & uVar46) >> 1) +

                                   (puVar34[0xf] & uVar46 & uVar24);

                    puVar34 = puVar34 + 0x10;

                    iVar31 = iVar21;

                  } while (iVar21 < (int)(uVar38 - (uVar19 & 0x8000000f)));

                }

                if (iVar31 < (int)uVar38) {

                  uVar29 = (ulonglong)(uVar38 - iVar31);

                  puVar35 = puVar34;

                  do {

                    uVar19 = *(uint *)((longlong)puVar35 + ((longlong)puVar42 - (longlong)puVar34));

                    *puVar35 = ((uVar19 & 0xfefefe) + (*puVar35 & 0xfefefe) >> 1) +

                               (uVar19 & *puVar35 & 0x10101);

                    uVar29 = uVar29 - 1;

                    lVar25 = local_b8;

                    puVar35 = puVar35 + 1;

                  } while (uVar29 != 0);

                }

                puVar26 = (uint *)((longlong)puVar26 + (ulonglong)((uint)uVar4 * 4));

                iVar28 = iVar28 + uVar38;

              }

            } while (iVar28 != iVar6);

            iVar28 = 0;

            lVar25 = lVar25 + *(int *)(param_3 + 0x10);

            iVar33 = iVar33 + -1;

            local_b8 = lVar25;

          } while (iVar33 != 0);

        }

        else {

          iVar31 = 0;

          do {

            do {

              uVar4 = *(ushort *)((longlong)puVar26 + 2);

              iVar31 = iVar31 + (uint)(ushort)*puVar26;

              puVar26 = puVar26 + 1;

              if (uVar4 == 0) {

                if (iVar31 == 0) goto LAB_1401d2920;

              }

              else {

                iVar23 = 0;

                iVar22 = 0;

                puVar34 = (uint *)(iVar31 * 4 + lVar25);

                uVar39 = (uint)uVar4;

                uVar40 = (uint)uVar4;

                puVar42 = puVar26;

                iVar21 = iVar23;

                if ((((uVar39 != 0) && (iVar21 = iVar22, 7 < uVar39)) && (1 < iVar28)) &&

                   ((puVar26 + ((ulonglong)uVar4 - 1) < puVar34 ||

                    (puVar34 + ((ulonglong)uVar4 - 1) < puVar26)))) {

                  do {

                    iVar23 = iVar23 + 8;

                    uVar45 = *puVar42;

                    puVar35 = puVar42 + 1;

                    puVar12 = puVar42 + 2;

                    puVar13 = puVar42 + 3;

                    uVar44 = uVar8 & *puVar34;

                    uVar46 = uVar9 & puVar34[1];

                    uVar47 = uVar10 & puVar34[2];

                    uVar48 = uVar11 & puVar34[3];

                    uVar49 = uVar19 & *puVar34;

                    uVar50 = uVar38 & puVar34[1];

                    uVar51 = uVar32 & puVar34[2];

                    uVar52 = uVar18 & puVar34[3];

                    uVar24 = puVar42[4];

                    uVar14 = puVar42[5];

                    uVar15 = puVar42[6];

                    uVar16 = puVar42[7];

                    puVar42 = puVar42 + 8;

                    auVar55._0_4_ = (uVar8 & uVar45) - uVar44;

                    auVar55._4_4_ = (uVar9 & *puVar35) - uVar46;

                    auVar55._8_4_ = (uVar10 & *puVar12) - uVar47;

                    auVar55._12_4_ = (uVar11 & *puVar13) - uVar48;

                    auVar43._0_4_ = (uVar19 & uVar45) - uVar49;

                    auVar43._4_4_ = (uVar38 & *puVar35) - uVar50;

                    auVar43._8_4_ = (uVar32 & *puVar12) - uVar51;

                    auVar43._12_4_ = (uVar18 & *puVar13) - uVar52;

                    auVar53 = pmulld(auVar55,auVar56);

                    auVar43 = pmulld(auVar43,auVar56);

                    *puVar34 = (auVar53._0_4_ >> 8) + uVar44 & uVar8 |

                               (auVar43._0_4_ >> 8) + uVar49 & uVar19;

                    puVar34[1] = (auVar53._4_4_ >> 8) + uVar46 & uVar9 |

                                 (auVar43._4_4_ >> 8) + uVar50 & uVar38;

                    puVar34[2] = (auVar53._8_4_ >> 8) + uVar47 & uVar10 |

                                 (auVar43._8_4_ >> 8) + uVar51 & uVar32;

                    puVar34[3] = (auVar53._12_4_ >> 8) + uVar48 & uVar11 |

                                 (auVar43._12_4_ >> 8) + uVar52 & uVar18;

                    uVar45 = uVar8 & puVar34[4];

                    uVar44 = uVar9 & puVar34[5];

                    uVar46 = uVar10 & puVar34[6];

                    uVar47 = uVar11 & puVar34[7];

                    uVar48 = uVar19 & puVar34[4];

                    uVar49 = uVar38 & puVar34[5];

                    uVar50 = uVar32 & puVar34[6];

                    uVar51 = uVar18 & puVar34[7];

                    auVar54._0_4_ = (uVar8 & uVar24) - uVar45;

                    auVar54._4_4_ = (uVar9 & uVar14) - uVar44;

                    auVar54._8_4_ = (uVar10 & uVar15) - uVar46;

                    auVar54._12_4_ = (uVar11 & uVar16) - uVar47;

                    auVar53._0_4_ = (uVar19 & uVar24) - uVar48;

                    auVar53._4_4_ = (uVar38 & uVar14) - uVar49;

                    auVar53._8_4_ = (uVar32 & uVar15) - uVar50;

                    auVar53._12_4_ = (uVar18 & uVar16) - uVar51;

                    auVar55 = pmulld(auVar54,auVar56);

                    auVar43 = pmulld(auVar53,auVar56);

                    puVar34[4] = (auVar55._0_4_ >> 8) + uVar45 & uVar8 |

                                 (auVar43._0_4_ >> 8) + uVar48 & uVar19;

                    puVar34[5] = (auVar55._4_4_ >> 8) + uVar44 & uVar9 |

                                 (auVar43._4_4_ >> 8) + uVar49 & uVar38;

                    puVar34[6] = (auVar55._8_4_ >> 8) + uVar46 & uVar10 |

                                 (auVar43._8_4_ >> 8) + uVar50 & uVar32;

                    puVar34[7] = (auVar55._12_4_ >> 8) + uVar47 & uVar11 |

                                 (auVar43._12_4_ >> 8) + uVar51 & uVar18;

                    puVar34 = puVar34 + 8;

                    iVar21 = iVar23;

                  } while (iVar23 < (int)(uVar40 - (uVar39 & 0x80000007)));

                }

                if (iVar21 < (int)uVar40) {

                  uVar29 = (ulonglong)(uVar40 - iVar21);

                  puVar35 = puVar34;

                  do {

                    uVar39 = *(uint *)(((longlong)puVar42 - (longlong)puVar34) + (longlong)puVar35);

                    uVar24 = *puVar35 & 0xff00;

                    uVar45 = *puVar35 & 0xff00ff;

                    *puVar35 = (((uVar39 & 0xff00ff) - uVar45) * uVar27 >> 8) + uVar45 & 0xff00ff |

                               (((uVar39 & 0xff00) - uVar24) * uVar27 >> 8) + uVar24 & 0xff00;

                    uVar29 = uVar29 - 1;

                    lVar25 = local_b8;

                    puVar35 = puVar35 + 1;

                  } while (uVar29 != 0);

                }

                puVar26 = (uint *)((longlong)puVar26 + (ulonglong)((uint)uVar4 * 4));

                iVar31 = iVar31 + uVar40;

              }

            } while (iVar31 != iVar6);

            iVar31 = 0;

            lVar25 = lVar25 + *(int *)(param_3 + 0x10);

            iVar33 = iVar33 + -1;

            local_b8 = lVar25;

          } while (iVar33 != 0);

        }

      }

      else {

        iVar33 = param_2[3];

        iVar28 = 0;

        local_b0 = iVar33;

        do {

          do {

            uVar4 = *(ushort *)((longlong)puVar26 + 2);

            local_80 = (ulonglong)uVar4;

            uVar19 = *puVar26;

            puVar26 = puVar26 + 1;

            iVar28 = iVar28 + (uint)(ushort)uVar19;

            if (uVar4 == 0) {

              if (iVar28 == 0) goto LAB_1401d2920;

            }

            else {

              puVar42 = (uint *)(iVar28 * 4 + lVar25);

              if (uVar4 != 0) {

                lVar20 = (longlong)puVar26 - (longlong)puVar42;

                do {

                  uVar19 = *puVar42;

                  bVar1 = *(byte *)(lVar7 + 0x1c);

                  bVar2 = *(byte *)(lVar7 + 0x1e);

                  uVar18 = (uint)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar7 + 0x18)]

                                       [(*(uint *)(lVar7 + 8) & uVar19) >> (bVar1 & 0x3f)];

                  uVar38 = *(uint *)(lVar20 + (longlong)puVar42);

                  uVar32 = (uint)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar7 + 0x1a)]

                                       [(*(uint *)(lVar7 + 0x10) & uVar19) >> (bVar2 & 0x3f)];

                  uVar19 = (uint)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar7 + 0x19)]

                                       [(*(uint *)(lVar7 + 0xc) & uVar19) >>

                                        (*(byte *)(lVar7 + 0x1d) & 0x3f)];

                  *puVar42 = ((((byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar7 + 0x18)]

                                      [(*(uint *)(lVar20 + (longlong)puVar42) & *(uint *)(lVar7 + 8)

                                       ) >> (bVar1 & 0x3f)] - uVar18) * uVar46 >> 8) + uVar18 >>

                             (8 - *(byte *)(lVar7 + 0x18) & 0x1f)) << (bVar1 & 0x1f) |

                             ((((byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar7 + 0x1a)]

                                      [(*(uint *)(lVar7 + 0x10) & uVar38) >> (bVar2 & 0x3f)] -

                               uVar32) * uVar46 >> 8) + uVar32 >>

                             (8 - *(byte *)(lVar7 + 0x1a) & 0x1f)) << (bVar2 & 0x1f) |

                             ((((byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar7 + 0x19)]

                                      [(uVar38 & *(uint *)(lVar7 + 0xc)) >>

                                       (*(byte *)(lVar7 + 0x1d) & 0x3f)] - uVar19) * uVar46 >> 8) +

                              uVar19 >> (8U - *(char *)(lVar7 + 0x19) & 0x1f)) <<

                             (*(byte *)(lVar7 + 0x1d) & 0x1f) | *(uint *)(lVar7 + 0x14);

                  puVar42 = puVar42 + 1;

                  local_80 = local_80 - 1;

                  lVar25 = local_b8;

                } while (local_80 != 0);

              }

              puVar26 = (uint *)((longlong)puVar26 + (ulonglong)((uint)uVar4 * 4));

              iVar28 = iVar28 + (uint)uVar4;

              iVar33 = local_b0;

            }

          } while (iVar28 != iVar6);

          iVar28 = 0;

          lVar25 = lVar25 + *(int *)(param_3 + 0x10);

          iVar33 = iVar33 + -1;

          local_b8 = lVar25;

          local_b0 = iVar33;

        } while (iVar33 != 0);

      }

    }

  }

  else {

    FUN_1401cf1a0(iVar6,puVar26,param_3,lVar25,param_2,bVar1);

  }

LAB_1401d2920:

  if ((*param_3 & 2) != 0) {

    FUN_1401489e0(param_3);

  }

  return 1;

}




