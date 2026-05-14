// Address: 0x140082640
// Ghidra name: FUN_140082640
// ============ 0x140082640 FUN_140082640 (size=2966) ============


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void FUN_140082640(longlong param_1)



{

  longlong *plVar1;

  undefined4 uVar2;

  int iVar3;

  longlong lVar4;

  char cVar5;

  int iVar6;

  int *piVar7;

  uint uVar8;

  uint uVar9;

  int iVar10;

  int iVar11;

  int iVar12;

  bool bVar13;

  float fVar14;

  undefined8 in_stack_ffffffffffffff88;

  undefined4 uVar15;

  undefined8 local_58;

  undefined8 uStack_50;

  undefined8 local_48;

  ulonglong uStack_40;

  

  *(int *)(param_1 + 0x18) = *(int *)(param_1 + 0x18) + 1;

  fVar14 = DAT_140303fb4;

  iVar12 = *(int *)(param_1 + 0x18) % 0x3c;

  if (iVar12 == 0) {

    uVar8 = 0xe;

    *(undefined4 *)(param_1 + 0x48) = 0xe;

    lVar4 = *(longlong *)(param_1 + 0x80);

    if (*(char *)(lVar4 + 0x161) == '\0') {

      uVar9 = 0xf;

      uVar8 = 0xf;

      *(undefined4 *)(param_1 + 0x48) = 0xf;

      if ((*(char *)(lVar4 + 0x161) != '\0') || (*(char *)(param_1 + 0xb0) == '\0'))

      goto LAB_1400826cd;

    }

    else {

LAB_1400826cd:

      uVar9 = uVar8 | 0x10;

      *(uint *)(param_1 + 0x48) = uVar9;

    }

    iVar6 = *(int *)(param_1 + 0x74);

    iVar3 = *(int *)(param_1 + 0x8c);

    if (((iVar6 < iVar3 / 3 + (iVar3 >> 0x1f) +

                  (int)(((longlong)iVar3 / 3 + ((longlong)iVar3 >> 0x3f) & 0xffffffffU) >> 0x1f)) &&

        (*(char *)(lVar4 + 0x163) != '\0')) && (0 < *(int *)(lVar4 + 0x1fc))) {

      *(uint *)(param_1 + 0x48) = uVar9 & 0xfffffffb;

    }

    iVar10 = *(int *)(param_1 + 0x78) + 1;

    *(int *)(param_1 + 0x78) = iVar10;

    iVar11 = *(int *)(param_1 + 0x7c) + 1;

    *(int *)(param_1 + 0x7c) = iVar11;

    iVar3 = *(int *)(param_1 + 0x70);

    if (((iVar3 == 0) || (iVar3 == 0xb)) || (iVar3 == 0xc)) {

      if (iVar3 == 0xd) goto LAB_14008276c;

    }

    else {

      if (iVar3 == 0xd) {

LAB_14008276c:

        if (iVar10 != 0x1e) {

          return;

        }

        FUN_140082330(param_1);

        *(undefined1 *)(param_1 + 0x11) = 1;

        return;

      }

      iVar6 = iVar6 + -1;

      *(int *)(param_1 + 0x74) = iVar6;

    }

    if (iVar6 < 1) {

      FUN_140080cc0(param_1,0xd,0);

      if (*(char *)(param_1 + 0xc4) == '\0') {

        return;

      }

      DAT_1403eaec4 = DAT_1403eaec4 + 1;

      return;

    }

    if (iVar11 == (iVar11 / 0x78) * 0x78) {

      *(int *)(lVar4 + 0x1fc) = *(int *)(lVar4 + 0x1fc) + 1;

      iVar6 = *(int *)(*(longlong *)(param_1 + 0x80) + 0x1c);

      if ((iVar6 == 2) || (iVar6 == 1)) {

        FUN_1400b8f90(*(longlong *)(param_1 + 0x80),0);

      }

    }

    if ((*(int *)(*(longlong *)(param_1 + 0x80) + 0x200) <=

         *(int *)(*(longlong *)(param_1 + 0x80) + 0x1fc)) &&

       (((*(int *)(param_1 + 0x70) == 0 || (*(int *)(param_1 + 0x70) == 1)) &&

        (FUN_140080cc0(param_1,0xd,0), *(char *)(param_1 + 0xc4) != '\0')))) {

      DAT_1403eaec0 = DAT_1403eaec0 + 1;

    }

    if (*(char *)(*(longlong *)(param_1 + 0x80) + 0x161) == '\0') {

      piVar7 = (int *)FUN_1401010d0(DAT_1403fb0d8,(int)(*(float *)(param_1 + 0x28) * fVar14));

      uVar15 = (undefined4)((ulonglong)in_stack_ffffffffffffff88 >> 0x20);

      if ((*piVar7 == 6) || (*piVar7 == 0x14)) {

        if (*(char *)(*(longlong *)(param_1 + 0x80) + 0x162) == '\0') {

LAB_140082872:

          fVar14 = *(float *)(param_1 + 0x34) * DAT_14039ca34 + *(float *)(param_1 + 0x2c);

          uStack_50 = 0;

          local_48 = _DAT_1403033d0;

          uStack_40 = _UNK_1403033d8;

          local_58 = (ulonglong)CONCAT24(s_Splash_140304ae8._4_2_,s_Splash_140304ae8._0_4_);

          uVar2 = *(undefined4 *)(param_1 + 0x28);

          FUN_14010de70(DAT_1403fb0d8,&local_58,0,CONCAT44(fVar14,uVar2),CONCAT44(uVar15,6),100,

                        DAT_14039ca44);

          if (0xf < uStack_40) {

            if ((0xfff < uStack_40 + 1) && (0x1f < (local_58 - *(longlong *)(local_58 - 8)) - 8)) {

                    /* WARNING: Subroutine does not return */

              _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

            }

            FUN_1402c7088();

          }

          FUN_14010d7e0(DAT_1403fb0d8,CONCAT44(fVar14,uVar2));

          FUN_140082550(param_1);

          *(undefined4 *)(param_1 + 0x70) = 0xd;

          *(undefined1 *)(param_1 + 0x11) = 1;

          return;

        }

        iVar6 = FUN_1400c6580(4);

        uVar15 = (undefined4)((ulonglong)in_stack_ffffffffffffff88 >> 0x20);

        if (iVar6 == 0) goto LAB_140082872;

      }

    }

    if (*(char *)(*(longlong *)(param_1 + 0x80) + 0x162) != '\0') {

      piVar7 = (int *)FUN_1401010d0(DAT_1403fb0d8,(int)(*(float *)(param_1 + 0x28) * fVar14),

                                    (int)(*(float *)(param_1 + 0x2c) * fVar14));

      if ((*piVar7 != 6) && (*piVar7 != 0x14)) {

        *(int *)(param_1 + 0x74) = *(int *)(param_1 + 0x74) + -10;

        return;

      }

    }

  }

  iVar6 = *(int *)(param_1 + 0x70);

  if ((iVar6 == 2) || (iVar6 == 4)) {

    cVar5 = FUN_1400a8a70(param_1,0);

    if (cVar5 == '\0') goto LAB_14008312a;

    goto LAB_140083122;

  }

  if (iVar6 == 3) {

LAB_140082cbd:

    cVar5 = FUN_1400a8a70(param_1,0);

joined_r0x000140082a88:

    if (cVar5 != '\0') goto LAB_140083122;

  }

  else {

    if (iVar6 == 5) {

      lVar4 = *(longlong *)(param_1 + 0x50);

      if ((lVar4 != 0) && (*(int *)(lVar4 + 0x70) == 7)) {

        if ((float)((uint)(*(float *)(param_1 + 0x28) - *(float *)(lVar4 + 0x28)) & _DAT_14039cab0)

            < *(float *)(param_1 + 0x30) * DAT_14039ca34) {

          fVar14 = *(float *)(param_1 + 0x34) * DAT_14039ca34;

          if ((float)((uint)(*(float *)(param_1 + 0x2c) - *(float *)(lVar4 + 0x2c)) & _DAT_14039cab0

                     ) < fVar14) {

            FUN_14010cc50(DAT_1403fb0d8,

                          CONCAT44((*(float *)(param_1 + 0x2c) - fVar14) - DAT_14030374c,

                                   *(float *)(param_1 + 0x28)),0);

            FUN_140080cc0(param_1,6,2);

            goto LAB_14008312a;

          }

        }

        FUN_140080b80(param_1);

        cVar5 = FUN_1400a8aa0(param_1);

        goto joined_r0x000140082a88;

      }

    }

    else {

      if (iVar6 != 6) {

        if (iVar6 == 7) {

          if (iVar12 != 0) {

            return;

          }

          if ((*(longlong *)(param_1 + 0x50) != 0) &&

             ((iVar12 = *(int *)(*(longlong *)(param_1 + 0x50) + 0x70), iVar12 == 5 || (iVar12 == 6)

              ))) goto LAB_14008312f;

LAB_1400830cc:

          FUN_140080e40(param_1);

          goto LAB_14008312f;

        }

        if (iVar6 == 8) {

          if (*(char *)(*(longlong *)(param_1 + 0x80) + 0x163) != '\0') {

            *(uint *)(param_1 + 0x48) = *(uint *)(param_1 + 0x48) & 0xfffffffb;

          }

          if ((*(longlong *)(param_1 + 0x50) == 0) ||

             (cVar5 = FUN_1400a8aa0(param_1), cVar5 != '\0')) goto LAB_140083122;

          lVar4 = *(longlong *)(param_1 + 0x50);

          if (*(int *)(lVar4 + 0x70) == 0xd) {

            *(int *)(lVar4 + 0x18) = *(int *)(lVar4 + 0x18) + -1;

          }

          if ((*(float *)(param_1 + 0x34) + *(float *)(param_1 + 0x30)) * DAT_14039ca34 <=

              (float)((uint)(*(float *)(param_1 + 0x2c) -

                            *(float *)(*(longlong *)(param_1 + 0x50) + 0x2c)) & _DAT_14039cab0) +

              (float)((uint)(*(float *)(param_1 + 0x28) -

                            *(float *)(*(longlong *)(param_1 + 0x50) + 0x28)) & _DAT_14039cab0)) {

            FUN_140080ab0(param_1);

            FUN_140102860(DAT_1403fb0d8);

          }

          else {

            *(undefined1 *)(param_1 + 0xb8) = 1;

            FUN_1400820a0(lVar4);

            FUN_140080ab0(param_1);

            FUN_140102860(DAT_1403fb0d8);

            if (*(char *)(lVar4 + 0xc4) != '\0') {

              DAT_1403eaec8 = DAT_1403eaec8 + 1;

            }

            FUN_140080cc0(param_1,0,1);

          }

        }

        else {

          if (iVar6 == 9) {

            if ((*(char *)(*(longlong *)(param_1 + 0x80) + 0x163) != '\0') &&

               (0 < *(int *)(*(longlong *)(param_1 + 0x80) + 0x1fc))) {

              *(uint *)(param_1 + 0x48) = *(uint *)(param_1 + 0x48) & 0xfffffffb;

            }

            goto LAB_140082cbd;

          }

          if (iVar6 == 1) {

            if (iVar12 != 0) {

              return;

            }

            if (*(int *)(param_1 + 0x78) != *(int *)(param_1 + 0x98)) goto LAB_14008312f;

            piVar7 = (int *)FUN_1401010d0(DAT_1403fb0d8,(int)(*(float *)(param_1 + 0x28) * fVar14),

                                          (int)(*(float *)(param_1 + 0x2c) * fVar14));

            for (lVar4 = *(longlong *)(piVar7 + 4);

                uVar15 = (undefined4)((ulonglong)in_stack_ffffffffffffff88 >> 0x20), lVar4 != 0;

                lVar4 = *(longlong *)(lVar4 + 0x58)) {

              if ((*(char *)(lVar4 + 0x11) == '\0') && (*(int *)(lVar4 + 8) == 3)) {

                iVar12 = FUN_14005cda0(lVar4);

                iVar6 = FUN_14005e250(*(undefined4 *)(lVar4 + 0xc));

                plVar1 = (longlong *)(param_1 + 0x80);

                if (0 < iVar6) {

                  FUN_1400b7770(*plVar1,*(undefined4 *)(lVar4 + 0xc));

                  *(undefined1 *)(lVar4 + 0x11) = 1;

                }

                uVar15 = (undefined4)((ulonglong)in_stack_ffffffffffffff88 >> 0x20);

                if (*(char *)(*plVar1 + 0x250) == '\0') {

                  iVar6 = *(int *)(*plVar1 + 0x24c);

                  if (iVar6 == 2) {

                    bVar13 = iVar12 == 1;

                  }

                  else {

                    if (iVar6 != 1) goto LAB_140082edc;

                    bVar13 = iVar12 == 2;

                  }

                  if (bVar13) goto LAB_140082d95;

                }

LAB_140082edc:

                iVar6 = FUN_1400c5c20(*(undefined4 *)(param_1 + 0x9c),*(undefined4 *)(lVar4 + 0x44))

                ;

                *(int *)(param_1 + 0x74) = *(int *)(param_1 + 0x74) + iVar6;

                *(int *)(lVar4 + 0x44) = *(int *)(lVar4 + 0x44) - iVar6;

                if (*(int *)(lVar4 + 0x44) < 1) {

                  *(undefined1 *)(lVar4 + 0x11) = 1;

                }

                if (*(int *)(lVar4 + 0xc) == 7) {

                  FUN_14010cef0(DAT_1403fb0d8,*(undefined8 *)(lVar4 + 0x28));

                }

                FUN_1400b9250(*plVar1,lVar4);

                if (iVar12 == 2) {

                  local_48 = _DAT_1403040c0;

                  uStack_40 = _UNK_1403040c8;

                  local_58._0_1_ = s_WildChompMeat_14030ad30[0];

                  local_58._1_1_ = s_WildChompMeat_14030ad30[1];

                  local_58._2_1_ = s_WildChompMeat_14030ad30[2];

                  local_58._3_1_ = s_WildChompMeat_14030ad30[3];

                  local_58._4_1_ = s_WildChompMeat_14030ad30[4];

                  local_58._5_1_ = s_WildChompMeat_14030ad30[5];

                  local_58._6_1_ = s_WildChompMeat_14030ad30[6];

                  local_58._7_1_ = s_WildChompMeat_14030ad30[7];

                  uStack_50 = (ulonglong)

                              CONCAT14(s_WildChompMeat_14030ad30[0xc],

                                       s_WildChompMeat_14030ad30._8_4_);

                  FUN_14010de70(DAT_1403fb0d8,&local_58,0,*(undefined8 *)(param_1 + 0x28),

                                CONCAT44(uVar15,4),100,DAT_14039ca44);

                  if (uStack_40 < 0x10) goto LAB_14008309b;

                  if ((0xfff < uStack_40 + 1) &&

                     (0x1f < (local_58 - *(longlong *)(local_58 + -8)) - 8)) {

                    /* WARNING: Subroutine does not return */

                    _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

                  }

                }

                else {

                  local_48 = _DAT_1403040b0;

                  uStack_40 = _UNK_1403040b8;

                  local_58._0_1_ = s_WildChompVeg_14030ad40[0];

                  local_58._1_1_ = s_WildChompVeg_14030ad40[1];

                  local_58._2_1_ = s_WildChompVeg_14030ad40[2];

                  local_58._3_1_ = s_WildChompVeg_14030ad40[3];

                  local_58._4_1_ = s_WildChompVeg_14030ad40[4];

                  local_58._5_1_ = s_WildChompVeg_14030ad40[5];

                  local_58._6_1_ = s_WildChompVeg_14030ad40[6];

                  local_58._7_1_ = s_WildChompVeg_14030ad40[7];

                  uStack_50 = (ulonglong)(uint)s_WildChompVeg_14030ad40._8_4_;

                  FUN_14010de70(DAT_1403fb0d8,&local_58,0,*(undefined8 *)(param_1 + 0x28),

                                CONCAT44(uVar15,4),100,DAT_14039ca44);

                  if (uStack_40 < 0x10) goto LAB_14008309b;

                  if ((0xfff < uStack_40 + 1) &&

                     (0x1f < (local_58 - *(longlong *)(local_58 + -8)) - 8)) {

                    /* WARNING: Subroutine does not return */

                    _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

                  }

                }

                goto LAB_140083096;

              }

LAB_140082d95:

            }

            if (((*(int *)(*(longlong *)(param_1 + 0x80) + 0x24c) == 1) ||

                (*(char *)(*(longlong *)(param_1 + 0x80) + 0x250) != '\0')) && (0 < piVar7[1])) {

              iVar12 = FUN_1400c5c20(*(undefined4 *)(param_1 + 0x9c));

              piVar7[1] = piVar7[1] - iVar12;

              *(int *)(param_1 + 0x74) = *(int *)(param_1 + 0x74) + iVar12;

              if (0 < iVar12) {

                iVar12 = FUN_1400c6580(2);

                if (iVar12 == 0) {

                  FUN_14010d260(DAT_1403fb0d8,(int)(*(float *)(param_1 + 0x28) * fVar14),

                                (int)(*(float *)(param_1 + 0x2c) * fVar14),*piVar7 - 9U < 4);

                  local_48 = _DAT_1403040b0;

                  uStack_40 = _UNK_1403040b8;

                  local_58._0_1_ = s_WildChompVeg_14030ad40[0];

                  local_58._1_1_ = s_WildChompVeg_14030ad40[1];

                  local_58._2_1_ = s_WildChompVeg_14030ad40[2];

                  local_58._3_1_ = s_WildChompVeg_14030ad40[3];

                  local_58._4_1_ = s_WildChompVeg_14030ad40[4];

                  local_58._5_1_ = s_WildChompVeg_14030ad40[5];

                  local_58._6_1_ = s_WildChompVeg_14030ad40[6];

                  local_58._7_1_ = s_WildChompVeg_14030ad40[7];

                  uStack_50 = (ulonglong)(uint)s_WildChompVeg_14030ad40._8_4_;

                  FUN_14010de70(DAT_1403fb0d8,&local_58,0,*(undefined8 *)(param_1 + 0x28),

                                CONCAT44(uVar15,4),100,DAT_14039ca44);

                  if (0xf < uStack_40) {

                    if ((0xfff < uStack_40 + 1) &&

                       (0x1f < (local_58 - *(longlong *)(local_58 + -8)) - 8)) {

                    /* WARNING: Subroutine does not return */

                      _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

                    }

LAB_140083096:

                    FUN_1402c7088();

                  }

                }

LAB_14008309b:

                iVar12 = FUN_1400c6580(10);

                if ((iVar12 == 0) && (*piVar7 == 2)) {

                  FUN_1400b35d0(*(undefined8 *)(param_1 + 0x80),4);

                  FUN_1400b3070(*(undefined8 *)(param_1 + 0x80));

                }

              }

            }

            goto LAB_1400830cc;

          }

          if ((iVar6 == 0) || (iVar6 == 0xb)) {

            if (iVar12 != 0) {

              return;

            }

            if (*(int *)(param_1 + 0xb4) <= *(int *)(param_1 + 0x78)) {

              FUN_140080e40(param_1);

            }

            goto LAB_14008312f;

          }

          if ((*(int *)(param_1 + 0x70) == 0xc) && (0x1e < *(int *)(param_1 + 0x78))) {

            FUN_140080cc0(param_1,0,0);

          }

        }

        goto LAB_14008312a;

      }

      if ((*(longlong *)(param_1 + 0x50) != 0) &&

         (*(int *)(*(longlong *)(param_1 + 0x50) + 0x70) == 7)) {

        if (iVar12 != 0) {

          return;

        }

        if (*(int *)(param_1 + 0xb4) <= *(int *)(param_1 + 0x78)) {

          FUN_1400816b0(param_1);

          *(undefined8 *)(param_1 + 0x50) = 0;

          FUN_140080cc0(param_1,0,1);

        }

        goto LAB_14008312f;

      }

    }

LAB_140083122:

    FUN_140080e40(param_1);

  }

LAB_14008312a:

  if (iVar12 != 0) {

    return;

  }

LAB_14008312f:

  if (((*(char *)(param_1 + 0xc4) != '\0') && (*(int *)(param_1 + 0x70) != 0)) &&

     ((*(int *)(param_1 + 0x70) - 3U & 0xfffffff7) != 0)) {

    *(int *)(param_1 + 0xc0) = *(int *)(param_1 + 0xc0) + 1;

  }

  return;

}




