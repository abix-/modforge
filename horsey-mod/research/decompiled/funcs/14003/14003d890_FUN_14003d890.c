// Address: 0x14003d890
// Ghidra name: FUN_14003d890
// ============ 0x14003d890 FUN_14003d890 (size=3290) ============


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void FUN_14003d890(longlong param_1)



{

  int *piVar1;

  undefined8 *puVar2;

  float fVar3;

  short sVar4;

  longlong lVar5;

  longlong lVar6;

  undefined8 uVar7;

  byte bVar8;

  char cVar9;

  undefined4 uVar10;

  int iVar11;

  int iVar12;

  uint uVar13;

  uint uVar14;

  int *piVar15;

  float fVar16;

  float local_res10;

  float local_res14;

  ulonglong in_stack_ffffffffffffffb8;

  uint7 uVar17;

  undefined8 local_38;

  undefined8 uStack_30;

  undefined8 local_28;

  ulonglong uStack_20;

  

  piVar1 = (int *)(param_1 + 0x25c);

  if (DAT_1403ed558 != '\0') {

    *(undefined4 *)(param_1 + 0xe0) = 0xffffffff;

    *piVar1 = 8;

    *(undefined4 *)(param_1 + 0x250) = 0;

    return;

  }

  if (((*piVar1 == 3) && (*(int *)(param_1 + 0x254) < 4)) && (*(int *)(param_1 + 0x250) == 0x78)) {

    local_28 = 0xd;

    uStack_20 = 0xf;

    local_38 = s_CircusTimpani_140304ad8._0_8_;

    uStack_30 = (ulonglong)CONCAT14(s_CircusTimpani_140304ad8[0xc],s_CircusTimpani_140304ad8._8_4_);

    FUN_14003f340(&local_38,1);

  }

  piVar15 = (int *)(param_1 + 0x25c);

  iVar11 = *(int *)(param_1 + 0x254);

  if (iVar11 == 0) {

    iVar11 = *piVar1;

    if (iVar11 == 3) {

      if ((*(int *)(param_1 + 0x250) == 0x1e) &&

         (cVar9 = FUN_1400b7730(*(undefined8 *)(param_1 + 0x260)), cVar9 != '\0')) {

        uVar10 = FUN_1400d1dd0(param_1,*(undefined8 *)(param_1 + 0x260));

        FUN_1400d1e10(param_1,uVar10,0x14);

      }

      if (*(int *)(param_1 + 0x250) == 0x78) {

        cVar9 = FUN_1400b7730(*(undefined8 *)(param_1 + 0x260));

        if (cVar9 == '\0') {

          uVar10 = FUN_1400d1dd0(param_1,*(undefined8 *)(param_1 + 0x260));

          FUN_1400d1e10(param_1,uVar10,0x1e);

        }

        else {

          FUN_1400b7fe0(*(undefined8 *)(param_1 + 0x260),0);

        }

      }

      if (*(int *)(param_1 + 0x250) == 600) {

        *piVar1 = 7;

        *(undefined4 *)(param_1 + 0x250) = 0;

      }

      FUN_1400b4a10(*(undefined8 *)(param_1 + 0x260),&local_res10);

      if (local_res14 <= DAT_140304c9c) {

        return;

      }

      FUN_1400b8420(*(undefined8 *)(param_1 + 0x260));

      DAT_1403ea218 = '\0';

      *piVar1 = 4;

    }

    else if (iVar11 == 4) {

      if (DAT_1403ea218 == '\0') {

        lVar5 = *(longlong *)

                 (*(longlong *)(param_1 + 0x2b0) + -0x28 +

                 (*(longlong *)(param_1 + 0x2b8) - *(longlong *)(param_1 + 0x2b0) >> 3) * 8);

        fVar16 = *(float *)(lVar5 + 0x40);

        fVar3 = *(float *)(lVar5 + 0x44);

        fVar16 = fVar3 * fVar3 + fVar16 * fVar16;

        if (fVar16 < 0.0) {

          fVar16 = (float)FUN_1402cdfa0(fVar16);

        }

        else {

          fVar16 = SQRT(fVar16);

        }

        if (DAT_14039ca44 < fVar16) {

          DAT_1403ea218 = '\x01';

          uStack_30 = 0;

          local_28 = _DAT_1403033d0;

          uStack_20 = _UNK_1403033d8;

          local_38._0_6_ = CONCAT24(s_Splash_140304ae8._4_2_,s_Splash_140304ae8._0_4_);

          local_38 = (ulonglong)(uint6)local_38;

          FUN_140040ca0(&local_38,100,0,DAT_14039ca44,in_stack_ffffffffffffffb8 & 0xffffffffffffff00

                       );

          if (0xf < uStack_20) {

            if ((0xfff < uStack_20 + 1) && (0x1f < (local_38 - *(longlong *)(local_38 - 8)) - 8)) {

                    /* WARNING: Subroutine does not return */

              _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

            }

            FUN_1402c7088();

          }

        }

      }

      lVar5 = *(longlong *)(*(longlong *)(param_1 + 0x298) + 0x88);

      while ((lVar5 != 0 && (*piVar1 != 5))) {

        lVar6 = *(longlong *)(lVar5 + 8);

        if (((*(byte *)(lVar6 + 8) & 2) != 0) &&

           (((sVar4 = *(short *)(*(longlong *)(lVar6 + 0x60) + 0x34), sVar4 == 2 &&

             (*(short *)(*(longlong *)(lVar6 + 0x68) + 0x34) == 1)) ||

            ((*(short *)(*(longlong *)(lVar6 + 0x68) + 0x34) == 2 && (sVar4 == 1)))))) {

          *piVar1 = 5;

          *(undefined4 *)(param_1 + 0x250) = 0;

        }

        lVar5 = *(longlong *)(lVar5 + 0x18);

      }

      if ((double)*(float *)(*(longlong *)(param_1 + 0x2a0) + 0x18) < DAT_140304b68) {

        *(undefined4 *)(param_1 + 0x25c) = 5;

        *(undefined4 *)(param_1 + 0x250) = 0x5a;

      }

      bVar8 = 0;

      for (lVar5 = *(longlong *)(*(longlong *)(param_1 + 0x2a0) + 0x88); lVar5 != 0;

          lVar5 = *(longlong *)(lVar5 + 0x18)) {

        lVar6 = *(longlong *)(lVar5 + 8);

        if (((lVar6 != 0) && ((*(byte *)(lVar6 + 8) & 2) != 0)) &&

           ((*(longlong *)(lVar6 + 0x60) == *(longlong *)(param_1 + 0x2d8) ||

            (*(longlong *)(lVar6 + 0x68) == *(longlong *)(param_1 + 0x2d8))))) {

          bVar8 = 1;

        }

      }

      if (*(int *)(param_1 + 0x250) < 0xf0) {

        return;

      }

      *(uint *)(param_1 + 0x25c) = bVar8 + 5;

    }

    else {

      if (iVar11 != 5) {

        return;

      }

      if (*(int *)(param_1 + 0x250) != 0x78) {

        return;

      }

      *(undefined4 *)(param_1 + 0x25c) = 7;

    }

    goto LAB_14003e4e6;

  }

  if (iVar11 != 1) {

    if (iVar11 != 2) {

      if (iVar11 != 3) {

        if (iVar11 != 5) {

          return;

        }

        if (*piVar15 != 3) {

          return;

        }

        iVar11 = *(int *)(param_1 + 0x250);

        uVar17 = (uint7)(in_stack_ffffffffffffffb8 >> 8);

        if (iVar11 == 0x96) {

          local_28 = _DAT_140304cc0;

          uStack_20 = _UNK_140304cc8;

          local_38._0_1_ = s_CurtainOpen_140304b00[0];

          local_38._1_1_ = s_CurtainOpen_140304b00[1];

          local_38._2_1_ = s_CurtainOpen_140304b00[2];

          local_38._3_1_ = s_CurtainOpen_140304b00[3];

          local_38._4_1_ = s_CurtainOpen_140304b00[4];

          local_38._5_1_ = s_CurtainOpen_140304b00[5];

          local_38._6_1_ = s_CurtainOpen_140304b00[6];

          local_38._7_1_ = s_CurtainOpen_140304b00[7];

          uStack_30 = (ulonglong)CONCAT12(s_CurtainOpen_140304b00[10],s_CurtainOpen_140304b00._8_2_)

          ;

          FUN_140040ca0(&local_38,100,0,DAT_14039ca44,(ulonglong)uVar17 << 8);

          if (uStack_20 < 0x10) {

            return;

          }

          if ((0xfff < uStack_20 + 1) && (0x1f < (local_38 - *(longlong *)(local_38 + -8)) - 8)) {

                    /* WARNING: Subroutine does not return */

            _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

          }

        }

        else {

          if (iVar11 == 0xe1) {

            FUN_1400b87e0(*(undefined8 *)(param_1 + 0x268));

            return;

          }

          if (iVar11 != 0x1c2) {

            if (iVar11 != 0x1e0) {

              return;

            }

            *(undefined4 *)(param_1 + 0x25c) = 8;

            goto LAB_14003e4e6;

          }

          local_28 = _DAT_1403040b0;

          uStack_20 = _UNK_1403040b8;

          local_38._0_1_ = s_CurtainClose_140304b10[0];

          local_38._1_1_ = s_CurtainClose_140304b10[1];

          local_38._2_1_ = s_CurtainClose_140304b10[2];

          local_38._3_1_ = s_CurtainClose_140304b10[3];

          local_38._4_1_ = s_CurtainClose_140304b10[4];

          local_38._5_1_ = s_CurtainClose_140304b10[5];

          local_38._6_1_ = s_CurtainClose_140304b10[6];

          local_38._7_1_ = s_CurtainClose_140304b10[7];

          uStack_30 = (ulonglong)(uint)s_CurtainClose_140304b10._8_4_;

          FUN_140040ca0(&local_38,100,0,DAT_14039ca44,(ulonglong)uVar17 << 8);

          if (uStack_20 < 0x10) {

            return;

          }

          if ((0xfff < uStack_20 + 1) && (0x1f < (local_38 - *(longlong *)(local_38 + -8)) - 8)) {

                    /* WARNING: Subroutine does not return */

            _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

          }

        }

        FUN_1402c7088();

        return;

      }

      uVar7 = *(undefined8 *)(*(longlong *)(param_1 + 0x138) + -8);

      if (*piVar15 == 3) {

        if (*(int *)(param_1 + 0x250) == 0xf) {

          FUN_1400b8720(uVar7);

        }

        if ((*(int *)(param_1 + 0x250) == 0x1e) &&

           (cVar9 = FUN_1400b7730(*(undefined8 *)(param_1 + 0x260)), cVar9 != '\0')) {

          uVar10 = FUN_1400d1dd0(param_1,*(undefined8 *)(param_1 + 0x260));

          FUN_1400d1e10(param_1,uVar10,0x17);

        }

        if (*(int *)(param_1 + 0x250) != 0x78) {

          return;

        }

        FUN_1400b87e0(uVar7);

        cVar9 = FUN_1400b7730(*(undefined8 *)(param_1 + 0x260));

        if (cVar9 == '\0') {

          uVar10 = FUN_1400d1dd0(param_1,*(undefined8 *)(param_1 + 0x260));

          FUN_1400d1e10(param_1,uVar10,0x1e);

          *(undefined4 *)(param_1 + 0x25c) = 4;

        }

        else {

          FUN_1400b7fe0(*(undefined8 *)(param_1 + 0x260),0);

          *(undefined4 *)(param_1 + 0x25c) = 4;

        }

      }

      else {

        if (*piVar15 != 4) {

          return;

        }

        if (*(int *)(param_1 + 0x250) < 0x3d) {

          return;

        }

        lVar5 = *(longlong *)(*(longlong *)(param_1 + 0x298) + 0x88);

        iVar11 = 4;

        while ((uVar10 = (undefined4)(in_stack_ffffffffffffffb8 >> 0x20), lVar5 != 0 &&

               (iVar11 != 7))) {

          lVar6 = *(longlong *)(lVar5 + 8);

          if (((*(byte *)(lVar6 + 8) & 2) != 0) &&

             ((*(short *)(*(longlong *)(lVar6 + 0x68) + 0x34) == 4 ||

              (*(short *)(*(longlong *)(lVar6 + 0x60) + 0x34) == 4)))) {

            FUN_1400b8420(*(undefined8 *)(param_1 + 0x260));

            *(undefined4 *)(param_1 + 0x25c) = 7;

            *(undefined4 *)(param_1 + 0x250) = 0;

            iVar11 = 7;

          }

          lVar5 = *(longlong *)(lVar5 + 0x18);

        }

        fVar16 = (float)FUN_1400b5fe0(*(undefined8 *)(param_1 + 0x260));

        if ((DAT_140303fcc <= fVar16) &&

           (fVar16 = (float)FUN_1400b5fe0(uVar7), DAT_140303fcc <= fVar16)) {

          uStack_30 = 0;

          local_28 = _DAT_1403033d0;

          uStack_20 = _UNK_1403033d8;

          local_38._0_6_ = CONCAT24(DAT_140304afc,DAT_140304af8);

          local_38 = (ulonglong)(uint6)local_38;

          FUN_1400d0c80(param_1,uVar7,&local_38,0,CONCAT44(uVar10,DAT_140303758));

          if (0xf < uStack_20) {

            if ((0xfff < uStack_20 + 1) && (0x1f < (local_38 - *(longlong *)(local_38 - 8)) - 8)) {

                    /* WARNING: Subroutine does not return */

              _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

            }

            FUN_1402c7088();

          }

          FUN_1400b8420(*(undefined8 *)(param_1 + 0x260));

          *(undefined4 *)(param_1 + 0x25c) = 6;

          *(undefined4 *)(param_1 + 0x250) = 0;

        }

        fVar16 = (float)FUN_1400b5fe0(*(undefined8 *)(param_1 + 0x260));

        iVar11 = *(int *)(param_1 + 0x250);

        if ((iVar11 < 0xe11) && ((DAT_140304bf8 <= fVar16 || (iVar11 < 0x709)))) {

          if (DAT_140304bf4 <= fVar16) {

            return;

          }

          if (iVar11 < 0x169) {

            return;

          }

        }

        *(undefined4 *)(param_1 + 0x25c) = 7;

      }

      goto LAB_14003e4e6;

    }

    if (*piVar15 == 3) {

      if ((*(int *)(param_1 + 0x250) == 0x1e) &&

         (cVar9 = FUN_1400b7730(*(undefined8 *)(param_1 + 0x260)), cVar9 != '\0')) {

        uVar10 = FUN_1400d1dd0(param_1,*(undefined8 *)(param_1 + 0x260));

        FUN_1400d1e10(param_1,uVar10,0x16);

      }

      if (*(int *)(param_1 + 0x250) == 0x78) {

        FUN_140009e60(*(undefined8 *)(param_1 + 0x2a8));

      }

      if (*(int *)(param_1 + 0x250) != 0x96) {

        return;

      }

      cVar9 = FUN_1400b7730(*(undefined8 *)(param_1 + 0x260));

      if (cVar9 == '\0') {

        uVar10 = FUN_1400d1dd0(param_1,*(undefined8 *)(param_1 + 0x260));

        FUN_1400d1e10(param_1,uVar10,0x1e);

      }

      else {

        FUN_1400b7fe0(*(undefined8 *)(param_1 + 0x260),0);

      }

      FUN_140009e60(*(undefined8 *)(param_1 + 0x2a8));

      *(undefined4 *)(param_1 + 0x25c) = 4;

      goto LAB_14003e4e6;

    }

    fVar16 = (float)FUN_140009ca0(*(undefined8 *)(param_1 + 0x2a8));

    if (DAT_1403ea219 == '\0') {

      if (DAT_140304b88 < (double)fVar16) {

        DAT_1403ea219 = '\x01';

        uStack_30 = 0;

        local_28 = _DAT_1403033d0;

        uStack_20 = _UNK_1403033d8;

        local_38._0_6_ = CONCAT24(s_Bounce_140304af0._4_2_,s_Bounce_140304af0._0_4_);

        local_38 = (ulonglong)(uint6)local_38;

        FUN_140040ca0(&local_38,100,0,DAT_14039ca44,in_stack_ffffffffffffffb8 & 0xffffffffffffff00);

        if (0xf < uStack_20) {

          if ((0xfff < uStack_20 + 1) && (0x1f < (local_38 - *(longlong *)(local_38 - 8)) - 8)) {

                    /* WARNING: Subroutine does not return */

            _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

          }

          FUN_1402c7088();

        }

      }

    }

    else if ((double)fVar16 < DAT_140304b40) {

      DAT_1403ea219 = '\0';

    }

    fVar16 = (float)FUN_140009ca0(*(undefined8 *)(param_1 + 0x2a8));

    DAT_1403ea21c =

         (float)((double)fVar16 * _DAT_140304bd8 + _DAT_140304bb0) * DAT_14039ca34 +

         DAT_1403ea21c * DAT_14039ca34;

    FUN_140009eb0(*(undefined8 *)(param_1 + 0x2a8));

    FUN_1400b4a10(*(undefined8 *)(param_1 + 0x260),&local_res10);

    uVar14 = *(uint *)(param_1 + 0x2238);

    uVar13 = uVar14 & 0x80000001;

    if ((int)uVar13 < 0) {

      uVar13 = (uVar13 - 1 | 0xfffffffe) + 1;

    }

    if ((uVar13 != 0) || (DAT_140304c90 <= local_res14)) {

      if ((uVar13 == 1) && (_DAT_140304c80 < (double)local_res14)) goto LAB_14003e064;

    }

    else {

      *(undefined4 *)(param_1 + 0x250) = 0;

LAB_14003e064:

      uVar14 = uVar14 + 1;

      *(uint *)(param_1 + 0x2238) = uVar14;

    }

    if ((int)uVar14 < 8) {

      if (((*(int *)(param_1 + 0x250) < 0xf0) && (DAT_14030374c <= local_res10)) &&

         (local_res10 <= DAT_140304c08)) {

        return;

      }

      FUN_1400b8420(*(undefined8 *)(param_1 + 0x260));

      *(undefined4 *)(param_1 + 0x25c) = 7;

    }

    else {

      FUN_1400b8420(*(undefined8 *)(param_1 + 0x260));

      *(undefined4 *)(param_1 + 0x25c) = 6;

    }

    goto LAB_14003e4e6;

  }

  if (*piVar15 != 3) {

    return;

  }

  if ((*(int *)(param_1 + 0x250) == 0x1e) &&

     (cVar9 = FUN_1400b7730(*(undefined8 *)(param_1 + 0x260)), cVar9 != '\0')) {

    uVar10 = FUN_1400d1dd0(param_1,*(undefined8 *)(param_1 + 0x260));

    FUN_1400d1e10(param_1,uVar10,0x15);

  }

  if (*(int *)(param_1 + 0x250) == 0x78) {

    cVar9 = FUN_1400b7730(*(undefined8 *)(param_1 + 0x260));

    if (cVar9 == '\0') {

      uVar10 = FUN_1400d1dd0(param_1,*(undefined8 *)(param_1 + 0x260));

      FUN_1400d1e10(param_1,uVar10,0x1e);

    }

    else {

      FUN_1400b7fe0(*(undefined8 *)(param_1 + 0x260),0);

    }

  }

  puVar2 = (undefined8 *)(param_1 + 0x260);

  fVar16 = (float)FUN_1400b5fe0(*puVar2);

  iVar11 = *(int *)(param_1 + 0x250);

  if ((fVar16 < *(float *)(param_1 + 0x2244)) || (0x1c20 < iVar11)) {

    *(int *)(param_1 + 0x2248) = *(int *)(param_1 + 0x2248) + 1;

    iVar12 = 0x168;

    if (DAT_140304c00 < fVar16) {

      iVar12 = 0x1e0;

    }

    if (*(int *)(param_1 + 0x2248) <= iVar12) goto LAB_14003dd0c;

    FUN_1400b8420(*puVar2);

    *(undefined4 *)(param_1 + 0x25c) = 7;

    *(undefined4 *)(param_1 + 0x250) = 0;

  }

  else {

    *(undefined4 *)(param_1 + 0x2248) = 0;

    *(float *)(param_1 + 0x2244) = fVar16;

LAB_14003dd0c:

    if (((0xb3 < iVar11) && (iVar11 == (iVar11 / 0x1e) * 0x1e)) &&

       (iVar11 = FUN_1400c6580(4), iVar11 == 0)) {

      FUN_1400b8d90(*puVar2);

    }

  }

  iVar11 = *(int *)(param_1 + 0x250);

  if (((0xef < iVar11) && (iVar11 == (iVar11 / 0x96) * 0x96)) &&

     (iVar11 = FUN_1400c6580(4), iVar11 == 0)) {

    FUN_1400b87e0(*(undefined8 *)(param_1 + 0x260));

  }

  if (*(float *)(*(longlong *)

                  (*(longlong *)(*(longlong *)(*(longlong *)(param_1 + 0x138) + -8) + 0x40) + 0x30)

                + 0xc) <= _DAT_140304bfc) {

    return;

  }

  FUN_1400b8420(*(undefined8 *)(param_1 + 0x260));

  *(undefined4 *)(param_1 + 0x25c) = 6;

LAB_14003e4e6:

  *(undefined4 *)(param_1 + 0x250) = 0;

  return;

}




