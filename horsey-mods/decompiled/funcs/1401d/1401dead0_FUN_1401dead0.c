// Address: 0x1401dead0
// Ghidra name: FUN_1401dead0
// ============ 0x1401dead0 FUN_1401dead0 (size=1874) ============


undefined1 FUN_1401dead0(longlong param_1,int *param_2,longlong param_3,ulonglong param_4)



{

  int *piVar1;

  int *piVar2;

  int *piVar3;

  float *pfVar4;

  float *pfVar5;

  float fVar6;

  float fVar7;

  float fVar8;

  float fVar9;

  float fVar10;

  longlong lVar11;

  int *piVar12;

  int *piVar13;

  longlong *plVar14;

  undefined8 uVar15;

  bool bVar16;

  float fVar17;

  char cVar18;

  int iVar19;

  undefined8 uVar20;

  ulonglong uVar21;

  int iVar22;

  longlong lVar23;

  ulonglong uVar24;

  ulonglong uVar25;

  longlong lVar26;

  longlong **in_stack_ffffffffffffff60;

  ulonglong in_stack_ffffffffffffff68;

  longlong *local_88;

  longlong local_80;

  undefined8 local_78;

  undefined8 local_70;

  int local_68;

  int local_64;

  undefined4 local_60;

  undefined4 local_5c;

  

  lVar11 = *(longlong *)(param_1 + 0x2e0);

  lVar26 = *(longlong *)(param_1 + 0x1f0);

  lVar23 = (longlong)*(int *)(lVar11 + 0x140);

  local_88 = (longlong *)0x0;

  local_80 = lVar26;

  cVar18 = FUN_1401dcdf0();

  if (cVar18 == '\0') {

    return 0;

  }

  if (param_4 == 0) goto LAB_1401dec95;

  local_88 = *(longlong **)(lVar11 + 0xc0 + lVar23 * 8);

  if (*(ulonglong *)(lVar11 + 0x100 + lVar23 * 8) < param_4) {

    if (local_88 != (longlong *)0x0) {

      (**(code **)(*local_88 + 0x10))(local_88);

    }

    in_stack_ffffffffffffff68 = 0;

    in_stack_ffffffffffffff60 = &local_88;

    iVar19 = (**(code **)(**(longlong **)(lVar11 + 0x10) + 0xd0))

                       (*(longlong **)(lVar11 + 0x10),param_4 & 0xffffffff,0x208,0x142,0,

                        in_stack_ffffffffffffff60,0);

    if (iVar19 < 0) {

      local_88 = (longlong *)0x0;

    }

    *(longlong **)(lVar11 + 0xc0 + lVar23 * 8) = local_88;

    uVar24 = 0;

    if (local_88 != (longlong *)0x0) {

      uVar24 = param_4;

    }

    *(ulonglong *)(lVar11 + 0x100 + lVar23 * 8) = uVar24;

  }

  if (local_88 != (longlong *)0x0) {

    iVar19 = (**(code **)(*local_88 + 0x58))(local_88,0,param_4 & 0xffffffff,&local_78,0x2000);

    if (-1 < iVar19) {

      FUN_1402f8e20(local_78,param_3,param_4);

      iVar19 = (**(code **)(*local_88 + 0x60))();

      if (-1 < iVar19) {

        if (local_88 != (longlong *)0x0) {

          *(int *)(lVar11 + 0x140) = *(int *)(lVar11 + 0x140) + 1;

          if (7 < *(uint *)(lVar11 + 0x140)) {

            *(undefined4 *)(lVar11 + 0x140) = 0;

          }

          goto LAB_1401dec95;

        }

        goto LAB_1401dec3b;

      }

    }

    local_88 = (longlong *)0x0;

  }

LAB_1401dec3b:

  if (*(char *)(lVar11 + 0x144) == '\0') {

                    /* WARNING: Subroutine does not return */

    FUN_14012e0b0(6,"SDL failed to get a vertex buffer for this Direct3D 9 rendering batch!");

  }

LAB_1401dec95:

  (**(code **)(**(longlong **)(lVar11 + 0x10) + 800))

            (*(longlong **)(lVar11 + 0x10),0,local_88,0,0x18);

  fVar17 = DAT_14030a2d0;

  do {

    if (param_2 == (int *)0x0) {

      return 1;

    }

    iVar19 = *param_2;

    switch(iVar19 + -1) {

    case 0:

      iVar19 = memcmp((void *)(lVar11 + 0x148),param_2 + 4,0x10);

      if (iVar19 != 0) {

        uVar20 = *(undefined8 *)(param_2 + 6);

        *(undefined8 *)(lVar11 + 0x148) = *(undefined8 *)(param_2 + 4);

        *(undefined8 *)(lVar11 + 0x150) = uVar20;

        *(undefined1 *)(lVar11 + 0x158) = 1;

        *(undefined1 *)(lVar11 + 0x180) = 1;

      }

      break;

    case 1:

      if (*(char *)(lVar11 + 0x16c) != (char)param_2[2]) {

        *(char *)(lVar11 + 0x16c) = (char)param_2[2];

        *(undefined1 *)(lVar11 + 0x16d) = 1;

      }

      iVar19 = memcmp((void *)(lVar11 + 0x170),param_2 + 3,0x10);

      if (iVar19 != 0) {

        uVar20 = *(undefined8 *)(param_2 + 3);

        uVar15 = *(undefined8 *)(param_2 + 5);

        *(undefined1 *)(lVar11 + 0x180) = 1;

        *(undefined8 *)(lVar11 + 0x170) = uVar20;

        *(undefined8 *)(lVar11 + 0x178) = uVar15;

      }

      break;

    case 3:

      fVar6 = (float)param_2[4];

      fVar7 = (float)param_2[5];

      fVar8 = (float)param_2[8];

      fVar9 = (float)param_2[7];

      fVar10 = (float)param_2[6];

      if (lVar26 == 0) {

        iVar19 = *(int *)(lVar11 + 0x20);

        iVar22 = *(int *)(lVar11 + 0x24);

      }

      else {

        iVar19 = *(int *)(*(longlong *)(param_1 + 0x1f0) + 4);

        iVar22 = *(int *)(*(longlong *)(param_1 + 0x1f0) + 8);

      }

      if ((((*(int *)(lVar11 + 0x148) == 0) && (*(int *)(lVar11 + 0x14c) == 0)) &&

          (*(int *)(lVar11 + 0x150) == iVar19)) && (*(int *)(lVar11 + 0x154) == iVar22)) {

        bVar16 = true;

      }

      else {

        bVar16 = false;

      }

      if ((*(char *)(lVar11 + 0x16c) != '\0') || (*(char *)(lVar11 + 0x16d) != '\0')) {

        (**(code **)(**(longlong **)(lVar11 + 0x10) + 0x1c8))(*(longlong **)(lVar11 + 0x10),0xae,0);

        *(undefined1 *)(lVar11 + 0x16d) = *(undefined1 *)(lVar11 + 0x16c);

      }

      if ((*(char *)(lVar11 + 0x158) != '\0') || (!bVar16)) {

        local_5c = 0x3f800000;

        local_70 = 0;

        local_60 = 0;

        local_68 = iVar19;

        local_64 = iVar22;

        (**(code **)(**(longlong **)(lVar11 + 0x10) + 0x178))

                  (*(longlong **)(lVar11 + 0x10),&local_70);

        *(undefined1 *)(lVar11 + 0x158) = 1;

      }

      in_stack_ffffffffffffff68 = in_stack_ffffffffffffff68 & 0xffffffff00000000;

      in_stack_ffffffffffffff60 =

           (longlong **)((ulonglong)in_stack_ffffffffffffff60 & 0xffffffff00000000);

      (**(code **)(**(longlong **)(lVar11 + 0x10) + 0x158))

                (*(longlong **)(lVar11 + 0x10),0,0,1,

                 (((uint)(longlong)(fVar6 * fVar7 * fVar17) & 0xff |

                  (int)(longlong)(fVar8 * fVar17) << 8) << 8 |

                 (uint)(longlong)(fVar6 * fVar10 * fVar17) & 0xff) << 8 |

                 (uint)(longlong)(fVar6 * fVar9 * fVar17) & 0xff,in_stack_ffffffffffffff60,

                 in_stack_ffffffffffffff68);

      break;

    case 4:

    case 9:

      uVar24 = *(ulonglong *)(param_2 + 2);

      plVar14 = (longlong *)(param_2 + 0xc);

      piVar12 = param_2 + 0xb;

      piVar1 = param_2 + 0xe;

      piVar2 = param_2 + 0xf;

      piVar3 = param_2 + 0x10;

      uVar21 = *(ulonglong *)(param_2 + 4);

      uVar25 = uVar24 / 0x18;

      for (piVar13 = *(int **)(param_2 + 0x14); piVar13 != (int *)0x0;

          piVar13 = *(int **)(piVar13 + 0x14)) {

        if (*piVar13 == iVar19) {

          if (((*(longlong *)(piVar13 + 0xc) != *plVar14) || (piVar13[0xe] != *piVar1)) ||

             ((piVar13[0xf] != *piVar2 || ((piVar13[0x10] != *piVar3 || (piVar13[0xb] != *piVar12)))

              ))) break;

          uVar21 = uVar21 + *(longlong *)(piVar13 + 4);

          param_2 = piVar13;

        }

        else if (*piVar13 != 3) break;

      }

      FUN_1401e0170(lVar11);

      plVar14 = *(longlong **)(lVar11 + 0x10);

      lVar26 = *plVar14;

      if (iVar19 == 10) {

        uVar21 = (uVar21 & 0xffffffff) / 3;

        if (local_88 == (longlong *)0x0) {

          uVar20 = 4;

LAB_1401df1ee:

          (**(code **)(lVar26 + 0x298))(plVar14,uVar20,uVar21,param_3 + uVar24,0x18);

          lVar26 = local_80;

        }

        else {

          (**(code **)(lVar26 + 0x288))(plVar14,4,uVar25 & 0xffffffff,uVar21);

          lVar26 = local_80;

        }

      }

      else {

        uVar20 = 1;

        if (local_88 == (longlong *)0x0) {

          uVar21 = uVar21 & 0xffffffff;

          goto LAB_1401df1ee;

        }

        (**(code **)(lVar26 + 0x288))(plVar14,1,uVar25 & 0xffffffff,uVar21 & 0xffffffff);

        lVar26 = local_80;

      }

      break;

    case 5:

      uVar24 = *(ulonglong *)(param_2 + 4);

      pfVar4 = (float *)(*(ulonglong *)(param_2 + 2) + param_3);

      uVar21 = *(ulonglong *)(param_2 + 2) / 0x18;

      FUN_1401e0170(lVar11,param_2);

      if (((uVar24 == 2) || (*pfVar4 != pfVar4[uVar24 * 6 + -6])) ||

         (pfVar4[1] != pfVar4[uVar24 * 6 + -5])) {

        plVar14 = *(longlong **)(lVar11 + 0x10);

        if (local_88 == (longlong *)0x0) {

          (**(code **)(*plVar14 + 0x298))(plVar14,1,1,pfVar4 + (uVar24 - 1) * 6,0x18);

        }

        else {

          (**(code **)(*plVar14 + 0x288))(plVar14,1,(int)uVar24 + (int)uVar21 + -1,1);

        }

      }

      if (uVar24 < 3) {

        iVar19 = param_2[0xb];

        for (piVar12 = *(int **)(param_2 + 0x14); piVar12 != (int *)0x0;

            piVar12 = *(int **)(piVar12 + 0x14)) {

          if (*piVar12 == 6) {

            if ((*(longlong *)(piVar12 + 4) != 2) || (piVar12[0xb] != iVar19)) break;

            pfVar5 = pfVar4 + (uVar24 + 1) * 6;

            if ((pfVar4[uVar24 * 6] != *pfVar5) || (pfVar4[uVar24 * 6 + 1] != pfVar5[1])) {

              plVar14 = *(longlong **)(lVar11 + 0x10);

              if (local_88 == (longlong *)0x0) {

                (**(code **)(*plVar14 + 0x298))(plVar14,1,1,pfVar5,0x18);

              }

              else {

                (**(code **)(*plVar14 + 0x288))(plVar14,1,(int)uVar24 + (int)uVar21 + 1,1);

              }

            }

            uVar24 = uVar24 + *(longlong *)(piVar12 + 4);

            param_2 = piVar12;

          }

          else if (*piVar12 != 3) break;

        }

        iVar19 = (int)uVar24 + -1;

        plVar14 = *(longlong **)(lVar11 + 0x10);

        if (local_88 == (longlong *)0x0) {

          (**(code **)(*plVar14 + 0x298))(plVar14,2,iVar19,pfVar4,0x18);

          lVar26 = local_80;

        }

        else {

          (**(code **)(*plVar14 + 0x288))(plVar14,2,uVar21 & 0xffffffff,iVar19);

          lVar26 = local_80;

        }

      }

      else {

        iVar19 = (int)uVar24 + -1;

        plVar14 = *(longlong **)(lVar11 + 0x10);

        if (local_88 == (longlong *)0x0) {

          (**(code **)(*plVar14 + 0x298))(plVar14,3,iVar19,pfVar4,0x18);

          lVar26 = local_80;

        }

        else {

          (**(code **)(*plVar14 + 0x288))(plVar14,3,uVar21 & 0xffffffff,iVar19);

          lVar26 = local_80;

        }

      }

    }

    param_2 = *(int **)(param_2 + 0x14);

  } while( true );

}




