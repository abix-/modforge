// Address: 0x1400a5ee0
// Ghidra name: FUN_1400a5ee0
// ============ 0x1400a5ee0 FUN_1400a5ee0 (size=1765) ============


/* WARNING: Function: __chkstk replaced with injection: alloca_probe */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void FUN_1400a5ee0(undefined8 param_1,int *param_2,int param_3)



{

  char cVar1;

  ulonglong uVar2;

  ulonglong uVar3;

  undefined8 uVar4;

  undefined8 uVar5;

  undefined8 ****ppppuVar6;

  uint uVar7;

  longlong lVar8;

  longlong *plVar9;

  char *_Str;

  undefined8 *****pppppuVar10;

  longlong *plVar11;

  int *piVar12;

  int iVar13;

  longlong lVar14;

  int *piVar15;

  ulonglong uVar16;

  int *piVar17;

  undefined1 *puVar18;

  ulonglong uVar19;

  longlong lVar20;

  longlong *plVar21;

  ulonglong uVar22;

  ulonglong uVar23;

  undefined8 ****local_20c8;

  undefined8 uStack_20c0;

  ulonglong local_20b8;

  ulonglong uStack_20b0;

  undefined8 ****local_20a8;

  undefined8 uStack_20a0;

  undefined1 local_2098 [16];

  int local_2088;

  int local_2080;

  int local_207c;

  undefined1 local_2078 [32];

  undefined1 local_2058 [3840];

  undefined8 local_1158;

  undefined8 uStack_1150;

  undefined8 local_1148;

  undefined8 uStack_1140;

  undefined8 local_1138;

  undefined8 uStack_1130;

  undefined8 local_1128;

  undefined8 uStack_1120;

  undefined8 local_1118;

  undefined8 uStack_1110;

  undefined8 local_1108;

  undefined8 uStack_1100;

  undefined8 local_10f8;

  undefined8 uStack_10f0;

  undefined8 local_10e8;

  undefined8 uStack_10e0;

  undefined8 local_10d8;

  undefined8 uStack_10d0;

  undefined8 local_10c8;

  undefined8 uStack_10c0;

  undefined8 local_10b8;

  undefined8 uStack_10b0;

  undefined8 local_10a8;

  undefined8 uStack_10a0;

  undefined8 local_1098;

  undefined8 uStack_1090;

  int local_1088;

  int iStack_1084;

  int iStack_1080;

  int iStack_107c;

  undefined8 local_1078;

  undefined8 uStack_1070;

  undefined1 local_1068 [4144];

  

  FUN_140077ae0(param_1,&DAT_140304430,param_2 + 2);

  param_2[1] = param_3;

  iVar13 = (int)((DAT_1403f2fc8 - DAT_1403f2fc0) / 0x1018);

  *param_2 = iVar13;

  lVar8 = DAT_1403f2fc8;

  uVar19 = (ulonglong)(iVar13 + 1);

  uVar3 = (DAT_1403f2fc8 - DAT_1403f2fc0) / 0x1018;

  if (uVar19 < uVar3) {

    lVar14 = uVar19 * 0x1018 + DAT_1403f2fc0;

    for (lVar20 = lVar14; lVar20 != lVar8; lVar20 = lVar20 + 0x1018) {

      FUN_140027900(lVar20 + 8);

    }

  }

  else {

    lVar14 = DAT_1403f2fc8;

    if (uVar3 < uVar19) {

      if ((ulonglong)((DAT_1403f2fd0 - DAT_1403f2fc0) / 0x1018) < uVar19) {

        FUN_1400a6970(&DAT_1403f2fc0,uVar19);

        lVar14 = DAT_1403f2fc8;

      }

      else {

        lVar14 = FUN_1400a6c40(DAT_1403f2fc8,uVar19 - uVar3);

      }

    }

  }

  DAT_1403f2fc8 = lVar14;

  uVar5 = _UNK_14030cdd8;

  uVar4 = _DAT_14030cdd0;

  *(undefined8 *)(param_2 + 0x3ca) = _DAT_14030cdd0;

  *(undefined8 *)(param_2 + 0x3cc) = uVar5;

  *(undefined8 *)(param_2 + 0x3ce) = uVar4;

  *(undefined8 *)(param_2 + 0x3d0) = uVar5;

  *(undefined8 *)(param_2 + 0x3d2) = uVar4;

  *(undefined8 *)(param_2 + 0x3d4) = uVar5;

  *(undefined8 *)(param_2 + 0x3d6) = uVar4;

  *(undefined8 *)(param_2 + 0x3d8) = uVar5;

  *(undefined8 *)(param_2 + 0x3da) = uVar4;

  *(undefined8 *)(param_2 + 0x3dc) = uVar5;

  *(undefined8 *)(param_2 + 0x3de) = uVar4;

  *(undefined8 *)(param_2 + 0x3e0) = uVar5;

  *(undefined8 *)(param_2 + 0x3e2) = uVar4;

  *(undefined8 *)(param_2 + 0x3e4) = uVar5;

  *(undefined8 *)(param_2 + 0x3e6) = uVar4;

  *(undefined8 *)(param_2 + 1000) = uVar5;

  *(undefined8 *)(param_2 + 0x3ea) = uVar4;

  *(undefined8 *)(param_2 + 0x3ec) = uVar5;

  *(undefined8 *)(param_2 + 0x3ee) = uVar4;

  *(undefined8 *)(param_2 + 0x3f0) = uVar5;

  *(undefined8 *)(param_2 + 0x3f2) = uVar4;

  *(undefined8 *)(param_2 + 0x3f4) = uVar5;

  *(undefined8 *)(param_2 + 0x3f6) = uVar4;

  *(undefined8 *)(param_2 + 0x3f8) = uVar5;

  *(undefined8 *)(param_2 + 0x3fa) = uVar4;

  *(undefined8 *)(param_2 + 0x3fc) = uVar5;

  *(undefined8 *)(param_2 + 0x3fe) = uVar4;

  *(undefined8 *)(param_2 + 0x400) = uVar5;

  *(undefined8 *)(param_2 + 0x402) = uVar4;

  *(undefined8 *)(param_2 + 0x404) = uVar5;

  lVar8 = FUN_140025320(param_1);

  uVar19 = _UNK_14030cd48;

  uVar3 = _DAT_14030cd40;

  do {

    if (lVar8 == 0) {

      piVar15 = param_2 + 2;

      piVar17 = (int *)((longlong)*param_2 * 0x1018 + DAT_1403f2fc0);

      *piVar17 = *param_2;

      piVar17[1] = param_2[1];

      if (piVar17 + 2 != piVar15) {

        piVar12 = piVar15;

        if (0xf < *(ulonglong *)(param_2 + 8)) {

          piVar12 = *(int **)piVar15;

        }

        FUN_140027f50(piVar17 + 2,piVar12,*(undefined8 *)(param_2 + 6));

      }

      piVar12 = piVar17 + 10;

      lVar8 = (longlong)param_2 - (longlong)piVar17;

      lVar14 = 0x1e0;

      do {

        *piVar12 = *(int *)(lVar8 + (longlong)piVar12);

        piVar12[1] = *(int *)(lVar8 + 4 + (longlong)piVar12);

        piVar12 = piVar12 + 2;

        lVar14 = lVar14 + -1;

      } while (lVar14 != 0);

      piVar17 = piVar17 + 0x3ca;

      lVar14 = 0x78;

      do {

        *(undefined1 *)piVar17 = *(undefined1 *)(lVar8 + (longlong)piVar17);

        *(undefined1 *)((longlong)piVar17 + 1) = *(undefined1 *)(lVar8 + 1 + (longlong)piVar17);

        piVar17 = (int *)((longlong)piVar17 + 2);

        lVar14 = lVar14 + -1;

      } while (lVar14 != 0);

      FUN_1400279c0(&local_20a8,piVar15);

      local_2088 = *param_2;

      FUN_140074f80(&DAT_1403f2fb0,&local_20c8,&local_20a8);

      FUN_140027900(&local_20a8);

      FUN_140027900(piVar15);

      return;

    }

    plVar9 = (longlong *)(lVar8 + 0x38);

    if (0xf < *(ulonglong *)(lVar8 + 0x50)) {

      plVar9 = (longlong *)*plVar9;

    }

    if ((*(longlong *)(lVar8 + 0x48) == 4) && (*(int *)plVar9 == 0x656e6567)) {

      uStack_20a0 = 0;

      local_2098 = ZEXT816(0xf) << 0x40;

      local_20a8 = (undefined8 *****)0x0;

      _Str = (char *)FUN_1400256d0(lVar8,&DAT_140304430);

      uVar16 = 0;

      uVar23 = 0xf;

      if (_Str != (char *)0x0) {

        local_20c8 = (undefined8 *****)0x0;

        uStack_20c0 = 0;

        local_20b8 = 0;

        uStack_20b0 = 0;

        strlen(_Str);

        FUN_140027e30(&local_20c8,_Str);

        local_20a8 = local_20c8;

        uStack_20a0 = uStack_20c0;

        local_2098._8_8_ = uStack_20b0;

        local_2098._0_8_ = local_20b8;

        uVar16 = local_20b8;

        uVar23 = uStack_20b0;

      }

      ppppuVar6 = local_20a8;

      plVar9 = (longlong *)DAT_1403f2fd8[1];

      cVar1 = *(char *)((longlong)plVar9 + 0x19);

      plVar21 = DAT_1403f2fd8;

      plVar11 = DAT_1403f2fd8;

      while (DAT_1403f2fd8 = plVar11, cVar1 == '\0') {

        plVar11 = plVar9 + 4;

        pppppuVar10 = &local_20a8;

        if (0xf < uVar23) {

          pppppuVar10 = (undefined8 *****)ppppuVar6;

        }

        if (0xf < (ulonglong)plVar9[7]) {

          plVar11 = (longlong *)*plVar11;

        }

        uVar2 = plVar9[6];

        uVar22 = uVar2;

        if (uVar16 < uVar2) {

          uVar22 = uVar16;

        }

        uVar7 = memcmp(plVar11,pppppuVar10,uVar22);

        if (uVar7 == 0) {

          if (uVar2 < uVar16) {

            uVar7 = 0xffffffff;

          }

          else {

            uVar7 = (uint)(uVar16 < uVar2);

          }

        }

        plVar11 = plVar9 + 2;

        if (-1 < (int)uVar7) {

          plVar11 = plVar9;

          plVar21 = plVar9;

        }

        plVar9 = (longlong *)*plVar11;

        plVar11 = DAT_1403f2fd8;

        cVar1 = *(char *)((longlong)plVar9 + 0x19);

      }

      if (*(char *)((longlong)plVar21 + 0x19) == '\0') {

        plVar9 = plVar21 + 4;

        if (0xf < (ulonglong)plVar21[7]) {

          plVar9 = (longlong *)*plVar9;

        }

        pppppuVar10 = &local_20a8;

        if (0xf < uVar23) {

          pppppuVar10 = (undefined8 *****)ppppuVar6;

        }

        uVar2 = plVar21[6];

        uVar22 = uVar16;

        if (uVar2 < uVar16) {

          uVar22 = uVar2;

        }

        uVar7 = memcmp(pppppuVar10,plVar9,uVar22);

        if (uVar7 == 0) {

          if (uVar16 < uVar2) {

            uVar7 = 0xffffffff;

          }

          else {

            uVar7 = (uint)(uVar2 < uVar16);

          }

        }

        if ((int)uVar7 < 0) goto LAB_1400a6230;

      }

      else {

LAB_1400a6230:

        plVar21 = plVar11;

      }

      if ((plVar21 != plVar11) && (lVar14 = (longlong)(int)plVar21[8], (int)plVar21[8] != -1)) {

        *(undefined1 *)(lVar14 + 0xf28 + (longlong)param_2) = 0;

        uStack_20c0 = 0;

        local_20b8 = uVar3;

        uStack_20b0 = uVar19;

        local_20c8 = (undefined8 *****)0x3070;

        param_2[lVar14 * 4 + 10] = 0;

        FUN_1400257d0(lVar8,&local_20c8);

        pppppuVar10 = &local_20c8;

        if (0xf < uStack_20b0) {

          pppppuVar10 = (undefined8 *****)local_20c8;

        }

        *(undefined1 *)((longlong)pppppuVar10 + 1) = 0x31;

        param_2[lVar14 * 4 + 0xb] = 0;

        FUN_1400257d0(lVar8,&local_20c8);

        pppppuVar10 = &local_20c8;

        if (0xf < uStack_20b0) {

          pppppuVar10 = (undefined8 *****)local_20c8;

        }

        *(undefined1 *)((longlong)pppppuVar10 + 1) = 0x32;

        param_2[lVar14 * 4 + 0xc] = 0;

        FUN_1400257d0(lVar8,&local_20c8);

        pppppuVar10 = &local_20c8;

        if (0xf < uStack_20b0) {

          pppppuVar10 = (undefined8 *****)local_20c8;

        }

        *(undefined1 *)((longlong)pppppuVar10 + 1) = 0x33;

        param_2[lVar14 * 4 + 0xd] = 0;

        FUN_1400257d0(lVar8,&local_20c8);

        if (0xf < uStack_20b0) {

          if ((0xfff < uStack_20b0 + 1) &&

             (0x1f < (ulonglong)((longlong)local_20c8 + (-8 - (longlong)local_20c8[-1])))) {

                    /* WARNING: Subroutine does not return */

            _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

          }

          FUN_1402c7088();

        }

      }

      if (0xf < uVar23) {

        pppppuVar10 = (undefined8 *****)ppppuVar6;

        if ((0xfff < uVar23 + 1) &&

           (pppppuVar10 = (undefined8 *****)ppppuVar6[-1],

           0x1f < (ulonglong)((longlong)ppppuVar6 + (-8 - (longlong)pppppuVar10)))) {

                    /* WARNING: Subroutine does not return */

          _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

        }

        FUN_1402c7088(pppppuVar10);

      }

    }

    else {

      puVar18 = local_1068;

      piVar17 = &local_2080;

      for (lVar14 = 0x1018; lVar14 != 0; lVar14 = lVar14 + -1) {

        *(undefined1 *)piVar17 = *puVar18;

        puVar18 = puVar18 + 1;

        piVar17 = (int *)((longlong)piVar17 + 1);

      }

      local_2080 = *param_2;

      local_207c = param_2[1];

      FUN_1400279c0(local_2078,param_2 + 2);

      FUN_1402f8e20(local_2058,param_2 + 10,0xf00);

      local_1158 = *(undefined8 *)(param_2 + 0x3ca);

      uStack_1150 = *(undefined8 *)(param_2 + 0x3cc);

      local_1148 = *(undefined8 *)(param_2 + 0x3ce);

      uStack_1140 = *(undefined8 *)(param_2 + 0x3d0);

      local_1138 = *(undefined8 *)(param_2 + 0x3d2);

      uStack_1130 = *(undefined8 *)(param_2 + 0x3d4);

      local_1128 = *(undefined8 *)(param_2 + 0x3d6);

      uStack_1120 = *(undefined8 *)(param_2 + 0x3d8);

      local_1118 = *(undefined8 *)(param_2 + 0x3da);

      uStack_1110 = *(undefined8 *)(param_2 + 0x3dc);

      local_1108 = *(undefined8 *)(param_2 + 0x3de);

      uStack_1100 = *(undefined8 *)(param_2 + 0x3e0);

      local_10f8 = *(undefined8 *)(param_2 + 0x3e2);

      uStack_10f0 = *(undefined8 *)(param_2 + 0x3e4);

      local_10e8 = *(undefined8 *)(param_2 + 0x3e6);

      uStack_10e0 = *(undefined8 *)(param_2 + 1000);

      local_10d8 = *(undefined8 *)(param_2 + 0x3ea);

      uStack_10d0 = *(undefined8 *)(param_2 + 0x3ec);

      local_10c8 = *(undefined8 *)(param_2 + 0x3ee);

      uStack_10c0 = *(undefined8 *)(param_2 + 0x3f0);

      local_10b8 = *(undefined8 *)(param_2 + 0x3f2);

      uStack_10b0 = *(undefined8 *)(param_2 + 0x3f4);

      local_10a8 = *(undefined8 *)(param_2 + 0x3f6);

      uStack_10a0 = *(undefined8 *)(param_2 + 0x3f8);

      local_1098 = *(undefined8 *)(param_2 + 0x3fa);

      uStack_1090 = *(undefined8 *)(param_2 + 0x3fc);

      local_1088 = param_2[0x3fe];

      iStack_1084 = param_2[0x3ff];

      iStack_1080 = param_2[0x400];

      iStack_107c = param_2[0x401];

      local_1078 = *(undefined8 *)(param_2 + 0x402);

      uStack_1070 = *(undefined8 *)(param_2 + 0x404);

      FUN_1400a5ee0(lVar8,&local_2080);

    }

    lVar8 = FUN_140025450(lVar8);

  } while( true );

}




