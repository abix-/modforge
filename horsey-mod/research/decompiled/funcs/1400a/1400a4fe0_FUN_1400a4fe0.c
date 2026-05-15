// Address: 0x1400a4fe0
// Ghidra name: FUN_1400a4fe0
// ============ 0x1400a4fe0 FUN_1400a4fe0 (size=889) ============


/* WARNING: Function: __chkstk replaced with injection: alloca_probe */



void FUN_1400a4fe0(void)



{

  undefined4 uVar1;

  undefined8 ***pppuVar2;

  ulonglong uVar3;

  ulonglong uVar4;

  longlong lVar5;

  undefined8 uVar6;

  undefined4 *puVar7;

  undefined1 *puVar8;

  undefined8 ****ppppuVar9;

  longlong lVar10;

  ulonglong uVar11;

  undefined4 local_res8 [2];

  undefined4 *local_res10;

  undefined4 local_3148;

  undefined2 local_3144;

  undefined1 local_3142;

  undefined1 local_3141;

  undefined8 local_3140;

  undefined8 local_3138;

  undefined8 local_3130;

  undefined **local_3128 [14];

  undefined1 local_30b8 [48];

  undefined8 local_3088;

  undefined8 ***local_3080;

  undefined8 uStack_3078;

  ulonglong local_3070;

  ulonglong local_3068;

  undefined4 local_3060;

  undefined1 local_305c [3836];

  undefined8 local_2160;

  undefined8 uStack_2158;

  undefined8 local_2150;

  undefined8 uStack_2148;

  undefined8 local_2140;

  undefined8 uStack_2138;

  undefined8 local_2130;

  undefined8 uStack_2128;

  undefined8 local_2120;

  undefined8 uStack_2118;

  undefined8 local_2110;

  undefined8 uStack_2108;

  undefined8 local_2100;

  undefined8 uStack_20f8;

  undefined8 local_20f0;

  undefined8 uStack_20e8;

  undefined8 local_20e0;

  undefined8 uStack_20d8;

  undefined8 local_20d0;

  undefined8 uStack_20c8;

  undefined8 local_20c0;

  undefined8 uStack_20b8;

  undefined8 local_20b0;

  undefined8 uStack_20a8;

  undefined8 local_20a0;

  undefined8 uStack_2098;

  undefined4 local_2090;

  undefined4 uStack_208c;

  undefined4 uStack_2088;

  undefined4 uStack_2084;

  undefined4 local_2080;

  undefined4 uStack_207c;

  undefined4 uStack_2078;

  undefined4 uStack_2074;

  undefined4 local_2068;

  undefined4 local_2064;

  undefined8 **local_2060;

  undefined8 **ppuStack_2058;

  ulonglong local_2050;

  ulonglong local_2048;

  undefined1 local_2040 [3840];

  undefined8 local_1140;

  undefined8 uStack_1138;

  undefined8 local_1130;

  undefined8 uStack_1128;

  undefined8 local_1120;

  undefined8 uStack_1118;

  undefined8 local_1110;

  undefined8 uStack_1108;

  undefined8 local_1100;

  undefined8 uStack_10f8;

  undefined8 local_10f0;

  undefined8 uStack_10e8;

  undefined8 local_10e0;

  undefined8 uStack_10d8;

  undefined8 local_10d0;

  undefined8 uStack_10c8;

  undefined8 local_10c0;

  undefined8 uStack_10b8;

  undefined8 local_10b0;

  undefined8 uStack_10a8;

  undefined8 local_10a0;

  undefined8 uStack_1098;

  undefined8 local_1090;

  undefined8 uStack_1088;

  undefined8 local_1080;

  undefined8 uStack_1078;

  undefined4 local_1070;

  undefined4 uStack_106c;

  undefined4 uStack_1068;

  undefined4 uStack_1064;

  undefined4 local_1060;

  undefined4 uStack_105c;

  undefined4 uStack_1058;

  undefined4 uStack_1054;

  undefined1 local_1050 [4112];

  undefined8 uStack_40;

  

  uStack_40 = 0x1400a5002;

  FUN_140025e00(local_3128);

  local_res8[0] = 0;

  local_3140 = 0;

  local_3138 = 7;

  local_3130 = 0xf;

  local_3148 = (undefined4)DAT_14030cce0;

  local_3144 = DAT_14030cce0._4_2_;

  local_3142 = DAT_14030cce0._6_1_;

  local_3141 = 0;

  lVar5 = FUN_1400c43d0(&local_3148,local_res8);

  if (lVar5 == 0) {

    FUN_1400c4340("pop.xml load fail");

  }

  FUN_1400293d0(local_3128,lVar5,0);

  FUN_1400c4de0(lVar5);

  uVar6 = FUN_140025320(local_3128);

  lVar5 = FUN_140025320(uVar6);

  local_3088 = 0;

  uStack_3078 = 0;

  local_3070 = 0;

  local_3068 = 0xf;

  local_3080 = (undefined8 ****)0x0;

  FUN_1402f94c0(local_305c,0,0xefc);

  lVar10 = 0xf0;

  FUN_1402f94c0(&local_2160,0);

  uVar4 = local_3068;

  uVar3 = local_3070;

  pppuVar2 = local_3080;

  puVar7 = &local_3060;

  do {

    *puVar7 = 1;

    puVar7 = puVar7 + 4;

    lVar10 = lVar10 + -1;

  } while (lVar10 != 0);

  if (lVar5 != 0) {

    uVar1 = local_3088._4_4_;

    do {

      puVar8 = local_1050;

      puVar7 = &local_2068;

      for (lVar10 = 0x1018; lVar10 != 0; lVar10 = lVar10 + -1) {

        *(undefined1 *)puVar7 = *puVar8;

        puVar8 = puVar8 + 1;

        puVar7 = (undefined4 *)((longlong)puVar7 + 1);

      }

      local_res10 = &local_2068;

      local_2068 = (undefined4)local_3088;

      local_2064 = uVar1;

      local_2060 = (undefined8 **)0x0;

      ppuStack_2058 = (undefined8 ***)0x0;

      local_2050 = 0;

      local_2048 = 0;

      ppppuVar9 = &local_3080;

      if (0xf < uVar4) {

        ppppuVar9 = (undefined8 ****)pppuVar2;

      }

      if (0x7fffffffffffffff < uVar3) {

                    /* WARNING: Subroutine does not return */

        FUN_140024130();

      }

      if (uVar3 < 0x10) {

        local_2050 = uVar3;

        local_2048 = 0xf;

        local_2060 = *ppppuVar9;

        ppuStack_2058 = ppppuVar9[1];

      }

      else {

        uVar11 = uVar3 | 0xf;

        if (uVar11 < 0x8000000000000000) {

          if (uVar11 < 0x16) {

            uVar11 = 0x16;

          }

        }

        else {

          uVar11 = 0x7fffffffffffffff;

        }

        local_2060 = (undefined8 **)FUN_1400285e0(uVar11 + 1);

        local_2050 = uVar3;

        local_2048 = uVar11;

        FUN_1402f8e20(local_2060,ppppuVar9,uVar3 + 1);

      }

      FUN_1402f8e20(local_2040,&local_3060,0xf00);

      local_1140 = local_2160;

      uStack_1138 = uStack_2158;

      local_1130 = local_2150;

      uStack_1128 = uStack_2148;

      local_1120 = local_2140;

      uStack_1118 = uStack_2138;

      local_1110 = local_2130;

      uStack_1108 = uStack_2128;

      local_1100 = local_2120;

      uStack_10f8 = uStack_2118;

      local_10f0 = local_2110;

      uStack_10e8 = uStack_2108;

      local_10e0 = local_2100;

      uStack_10d8 = uStack_20f8;

      local_10d0 = local_20f0;

      uStack_10c8 = uStack_20e8;

      local_10c0 = local_20e0;

      uStack_10b8 = uStack_20d8;

      local_10b0 = local_20d0;

      uStack_10a8 = uStack_20c8;

      local_10a0 = local_20c0;

      uStack_1098 = uStack_20b8;

      local_1090 = local_20b0;

      uStack_1088 = uStack_20a8;

      local_1080 = local_20a0;

      uStack_1078 = uStack_2098;

      local_1070 = local_2090;

      uStack_106c = uStack_208c;

      uStack_1068 = uStack_2088;

      uStack_1064 = uStack_2084;

      local_1060 = local_2080;

      uStack_105c = uStack_207c;

      uStack_1058 = uStack_2078;

      uStack_1054 = uStack_2074;

      FUN_1400a5ee0(lVar5,&local_2068,0xffffffff);

      lVar5 = FUN_140025450();

    } while (lVar5 != 0);

  }

  if (0xf < uVar4) {

    ppppuVar9 = (undefined8 ****)pppuVar2;

    if ((0xfff < uVar4 + 1) &&

       (ppppuVar9 = (undefined8 ****)pppuVar2[-1],

       0x1f < (ulonglong)((longlong)pppuVar2 + (-8 - (longlong)ppppuVar9)))) {

                    /* WARNING: Subroutine does not return */

      _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

    }

    FUN_1402c7088(ppppuVar9);

  }

  local_3128[0] = TiXmlDocument::vftable;

  FUN_140027900(local_30b8);

  FUN_140024a60(local_3128);

  return;

}




