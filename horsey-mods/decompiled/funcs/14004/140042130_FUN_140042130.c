// Address: 0x140042130
// Ghidra name: FUN_140042130
// ============ 0x140042130 FUN_140042130 (size=1854) ============


undefined8 FUN_140042130(longlong param_1,uint param_2)



{

  int *piVar1;

  longlong lVar2;

  char *pcVar3;

  byte *pbVar4;

  char cVar5;

  int iVar6;

  undefined4 uVar7;

  int iVar8;

  int iVar9;

  uint uVar10;

  ulonglong uVar11;

  int iVar12;

  int iVar13;

  bool bVar14;

  int local_res8 [2];

  uint local_res10;

  int local_res18;

  undefined4 local_res20 [2];

  

  if (*(char *)(param_1 + 0x5c) == '\0') {

    local_res10 = param_2;

    iVar6 = FUN_14004f210();

    if (iVar6 != 0) {

      local_res18 = *(int *)(param_1 + 0xac) * 3 - *(int *)(param_1 + 0xa8) >> 2;

      bVar14 = *(uint *)(param_1 + 0x580) == param_2;

      if (*(uint *)(param_1 + 0x580) < param_2) {

        do {

          iVar6 = *(int *)(param_1 + 0x98);

          *(undefined8 *)(param_1 + 0x764) = 0;

          while( true ) {

            if (iVar6 != 0) goto LAB_14004272f;

            iVar6 = FUN_14004edb0(param_1);

            if (iVar6 == 0) goto LAB_14004272f;

            iVar6 = FUN_14004cb40(param_1,1);

            if (iVar6 == 0) break;

            if (*(char *)(param_1 + 0x5c) != '\0') goto LAB_14004272f;

            do {

              iVar6 = FUN_14004cab0(param_1);

              *(undefined4 *)(param_1 + 0x6f8) = 0;

            } while (iVar6 != -1);

            iVar6 = *(int *)(param_1 + 0x98);

          }

          uVar7 = FUN_14004cee0(*(int *)(param_1 + 0x1f0) + -1);

          iVar6 = FUN_14004cb40(param_1,uVar7);

          if ((iVar6 == -1) || (iVar12 = *(int *)(param_1 + 0x1f0), iVar12 <= iVar6))

          goto LAB_14004272f;

          lVar2 = param_1 + (longlong)iVar6 * 6;

          if (*(char *)(lVar2 + 500) == '\0') {

            iVar6 = *(int *)(param_1 + 0xa8);

            iVar9 = 0;

            iVar8 = 0;

          }

          else {

            iVar6 = *(int *)(param_1 + 0xac);

            iVar8 = FUN_14004cb40(param_1,1);

            iVar9 = FUN_14004cb40(param_1,1);

            iVar12 = *(int *)(param_1 + 0x1f0);

          }

          cVar5 = *(char *)(lVar2 + 500);

          iVar13 = iVar6 >> 1;

          if ((cVar5 == '\0') || (iVar8 != 0)) {

            iVar8 = 0;

            if (cVar5 != '\0') goto LAB_1400422be;

          }

          else {

            iVar8 = iVar6 - *(int *)(param_1 + 0xa8) >> 2;

LAB_1400422be:

            if (iVar9 == 0) {

              iVar13 = iVar6 * 3 - *(int *)(param_1 + 0xa8) >> 2;

            }

          }

          iVar9 = 0;

          iVar6 = FUN_14004cee0(iVar12 + -1);

          iVar12 = 10;

          if (cVar5 == '\0') {

            iVar12 = 8;

          }

          iVar6 = (int)((iVar6 + iVar12 >> 0x1f & 7U) + iVar6 + iVar12) >> 3;

          *(char *)(param_1 + 0x6e4) = *(char *)(param_1 + 0x6e4) + (char)iVar6;

          *(int *)(param_1 + 0x6fc) = *(int *)(param_1 + 0x6fc) - iVar6;

          if (*(longlong *)(param_1 + 0x40) == 0) {

            iVar12 = FUN_1402cf00c(*(undefined8 *)(param_1 + 0x30));

            FUN_1402cea4c(*(undefined8 *)(param_1 + 0x30),iVar12 + -iVar6,0);

          }

          else {

            uVar11 = *(longlong *)(param_1 + 0x40) + (longlong)-iVar6;

            *(ulonglong *)(param_1 + 0x40) = uVar11;

            if (*(ulonglong *)(param_1 + 0x50) <= uVar11) {

              *(undefined4 *)(param_1 + 0x98) = 1;

            }

          }

          iVar6 = *(int *)(param_1 + 0x6e8);

          if (iVar6 == -1) {

            iVar6 = *(int *)(param_1 + 0x5e0);

          }

          *(int *)(param_1 + 0x6e8) = iVar6 + -1;

          uVar10 = (*(int *)(param_1 + 0x580) - iVar8) + iVar13;

          *(undefined4 *)(param_1 + 0x6f8) = 0;

          if (param_2 < uVar10) {

            return 1;

          }

          if (local_res18 + uVar10 <= param_2) {

            *(uint *)(param_1 + 0x580) = uVar10;

            *(undefined4 *)(param_1 + 0x4f8) = 0;

            if (iVar6 + -1 == -1) {

              pcVar3 = *(char **)(param_1 + 0x40);

              if (pcVar3 == (char *)0x0) {

                iVar6 = FUN_1402ce36c(*(undefined8 *)(param_1 + 0x30));

                cVar5 = (char)iVar6;

                if (iVar6 == -1) goto LAB_14004277f;

              }

              else if (pcVar3 < *(char **)(param_1 + 0x50)) {

                cVar5 = *pcVar3;

                *(char **)(param_1 + 0x40) = pcVar3 + 1;

              }

              else {

LAB_14004277f:

                cVar5 = '\0';

                *(undefined4 *)(param_1 + 0x98) = 1;

              }

              if (*(int *)(param_1 + 0x98) != 0) goto LAB_140042800;

              if ((((cVar5 != 'O') || (cVar5 = FUN_14004ca60(param_1), cVar5 != 'g')) ||

                  (cVar5 = FUN_14004ca60(param_1), cVar5 != 'g')) ||

                 (cVar5 = FUN_14004ca60(param_1), cVar5 != 'S')) {

                *(undefined4 *)(param_1 + 0x9c) = 0x1e;

                goto LAB_140042800;

              }

              iVar6 = FUN_140053810(param_1);

              if (iVar6 == 0) goto LAB_140042800;

              if ((*(byte *)(param_1 + 0x6e3) & 1) != 0) {

                *(undefined4 *)(param_1 + 0x6ec) = 0;

                *(undefined1 *)(param_1 + 0x6e4) = 0;

                *(undefined4 *)(param_1 + 0x9c) = 0x20;

                goto LAB_140042800;

              }

            }

            FUN_1400535f0(param_1);

LAB_140042800:

            while ((*(char *)(param_1 + 0x6e4) != '\0' ||

                   ((*(int *)(param_1 + 0x6ec) == 0 && (iVar6 = FUN_14004eeb0(param_1), iVar6 != 0))

                   ))) {

              *(char *)(param_1 + 0x6e4) = *(char *)(param_1 + 0x6e4) + -1;

              *(int *)(param_1 + 0x6fc) = *(int *)(param_1 + 0x6fc) + 1;

              uVar11 = *(ulonglong *)(param_1 + 0x40);

              if (uVar11 == 0) goto LAB_14004284a;

              if (*(ulonglong *)(param_1 + 0x50) <= uVar11) goto LAB_140042858;

              *(ulonglong *)(param_1 + 0x40) = uVar11 + 1;

            }

            goto LAB_14004271a;

          }

          *(undefined8 *)(param_1 + 0x764) = 0;

          if (*(int *)(param_1 + 0x98) == 0) {

            piVar1 = (int *)(param_1 + 0x6f8);

LAB_1400423a0:

            if (*(int *)(param_1 + 0x6e8) == -1) {

              pcVar3 = *(char **)(param_1 + 0x40);

              if (pcVar3 == (char *)0x0) {

                iVar6 = FUN_1402ce36c(*(undefined8 *)(param_1 + 0x30));

                cVar5 = (char)iVar6;

                if (iVar6 == -1) goto LAB_1400423d8;

              }

              else if (pcVar3 < *(char **)(param_1 + 0x50)) {

                cVar5 = *pcVar3;

                *(char **)(param_1 + 0x40) = pcVar3 + 1;

              }

              else {

LAB_1400423d8:

                cVar5 = '\0';

                *(undefined4 *)(param_1 + 0x98) = 1;

              }

              if (*(int *)(param_1 + 0x98) != 0) goto LAB_14004271a;

              if (((cVar5 != 'O') || (cVar5 = FUN_14004ca60(param_1), cVar5 != 'g')) ||

                 ((cVar5 = FUN_14004ca60(param_1), cVar5 != 'g' ||

                  (cVar5 = FUN_14004ca60(param_1), cVar5 != 'S')))) {

                *(undefined4 *)(param_1 + 0x9c) = 0x1e;

                goto LAB_14004271a;

              }

              iVar6 = FUN_140053810(param_1);

              if (iVar6 == 0) goto LAB_14004271a;

              if ((*(byte *)(param_1 + 0x6e3) & 1) != 0) {

                *(undefined4 *)(param_1 + 0x6ec) = 0;

                *(undefined1 *)(param_1 + 0x6e4) = 0;

                *(undefined4 *)(param_1 + 0x9c) = 0x20;

                goto LAB_14004271a;

              }

            }

            iVar6 = FUN_1400535f0();

            if (iVar6 == 0) goto LAB_14004271a;

            iVar6 = *piVar1;

            if (-1 < iVar6) {

              if (iVar6 < 1) {

                *(undefined4 *)(param_1 + 0x6f4) = 0;

                do {

                  if ((*(char *)(param_1 + 0x6e4) == '\0') &&

                     ((*(int *)(param_1 + 0x6ec) != 0 || (iVar6 = FUN_14004eeb0(), iVar6 == 0)))) {

                    *(undefined4 *)(param_1 + 0x6f8) = 0xffffffff;

                    goto LAB_1400425d2;

                  }

                  *(char *)(param_1 + 0x6e4) = *(char *)(param_1 + 0x6e4) + -1;

                  *(int *)(param_1 + 0x6fc) = *(int *)(param_1 + 0x6fc) + 1;

                  pbVar4 = *(byte **)(param_1 + 0x40);

                  if (pbVar4 == (byte *)0x0) {

                    uVar10 = FUN_1402ce36c(*(undefined8 *)(param_1 + 0x30));

                    if (uVar10 == 0xffffffff) goto LAB_1400424ce;

                  }

                  else if (pbVar4 < *(byte **)(param_1 + 0x50)) {

                    uVar10 = (uint)*pbVar4;

                    *(byte **)(param_1 + 0x40) = pbVar4 + 1;

                  }

                  else {

LAB_1400424ce:

                    uVar10 = 0;

                    *(undefined4 *)(param_1 + 0x98) = 1;

                  }

                  *(int *)(param_1 + 0x6f4) =

                       *(int *)(param_1 + 0x6f4) + ((uVar10 & 0xff) << ((byte)*piVar1 & 0x1f));

                  iVar6 = *piVar1 + 8;

                  *piVar1 = iVar6;

                } while (iVar6 < 1);

              }

              uVar10 = *(uint *)(param_1 + 0x6f4);

              *(uint *)(param_1 + 0x6f4) = uVar10 >> 1;

              *piVar1 = iVar6 + -1;

              if ((uVar10 & 1) != 0) {

                if (*(char *)(param_1 + 0x5c) == '\0') {

LAB_140042520:

                  do {

                    if ((*(char *)(param_1 + 0x6e4) == '\0') &&

                       ((*(int *)(param_1 + 0x6ec) != 0 ||

                        (iVar6 = FUN_14004eeb0(param_1), iVar6 == 0)))) goto LAB_140042582;

                    *(char *)(param_1 + 0x6e4) = *(char *)(param_1 + 0x6e4) + -1;

                    *(int *)(param_1 + 0x6fc) = *(int *)(param_1 + 0x6fc) + 1;

                    uVar11 = *(ulonglong *)(param_1 + 0x40);

                    if (uVar11 == 0) {

                      iVar6 = FUN_1402ce36c(*(undefined8 *)(param_1 + 0x30));

                      if (iVar6 == -1) goto LAB_140042573;

                    }

                    else {

                      if (uVar11 < *(ulonglong *)(param_1 + 0x50)) {

                        *piVar1 = 0;

                        *(ulonglong *)(param_1 + 0x40) = uVar11 + 1;

                        goto LAB_140042520;

                      }

LAB_140042573:

                      *(undefined4 *)(param_1 + 0x98) = 1;

                    }

                    *piVar1 = 0;

                  } while( true );

                }

                *(undefined4 *)(param_1 + 0x9c) = 0x23;

                goto LAB_14004271a;

              }

            }

LAB_1400425d2:

            uVar7 = FUN_14004cee0(*(int *)(param_1 + 0x1f0) + -1);

            iVar6 = FUN_14004cb40(param_1,uVar7);

            if ((iVar6 != -1) && (iVar6 < *(int *)(param_1 + 0x1f0))) {

              lVar2 = param_1 + (longlong)iVar6 * 6;

              if (*(char *)(lVar2 + 500) == '\0') {

                iVar12 = *(int *)(param_1 + 0xa8);

                iVar8 = 0;

              }

              else {

                iVar12 = *(int *)(param_1 + 0xac);

                iVar9 = FUN_14004cb40(param_1,1);

                iVar8 = FUN_14004cb40(param_1,1);

              }

              cVar5 = *(char *)(lVar2 + 500);

              iVar13 = iVar12 >> 1;

              if ((cVar5 == '\0') || (iVar9 != 0)) {

                local_res8[0] = 0;

                iVar9 = iVar13;

                if (cVar5 != '\0') goto LAB_1400426a2;

              }

              else {

                local_res8[0] = iVar12 - *(int *)(param_1 + 0xa8) >> 2;

                iVar9 = iVar12 + *(int *)(param_1 + 0xa8) >> 2;

LAB_1400426a2:

                if (iVar8 == 0) {

                  iVar13 = iVar12 * 3 - *(int *)(param_1 + 0xa8) >> 2;

                  iVar12 = iVar12 * 3 + *(int *)(param_1 + 0xa8) >> 2;

                }

              }

              iVar6 = FUN_140053a40(param_1,local_res20,param_1 + ((longlong)iVar6 * 3 + 0xfa) * 2,

                                    local_res8[0],iVar9,iVar13,iVar12,local_res8);

              param_2 = local_res10;

              if (iVar6 != 0) {

                FUN_140055060(param_1,local_res20[0],local_res8[0],iVar13);

                param_2 = local_res10;

              }

            }

          }

LAB_14004271a:

          bVar14 = *(uint *)(param_1 + 0x580) == param_2;

        } while (*(uint *)(param_1 + 0x580) < param_2);

      }

      if (bVar14) {

        return 1;

      }

LAB_14004272f:

      *(undefined4 *)(param_1 + 0x9c) = 0x25;

    }

  }

  else {

    *(undefined4 *)(param_1 + 0x9c) = 2;

  }

  return 0;

LAB_14004284a:

  iVar6 = FUN_1402ce36c(*(undefined8 *)(param_1 + 0x30));

  if (iVar6 == -1) {

LAB_140042858:

    *(undefined4 *)(param_1 + 0x98) = 1;

  }

  goto LAB_140042800;

LAB_140042582:

  *piVar1 = 0;

  if (*(int *)(param_1 + 0x98) != 0) goto LAB_14004271a;

  goto LAB_1400423a0;

}




