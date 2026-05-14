// Hint: settings_xml_handler_2
// Address: 0x1400777c0
// Ghidra name: FUN_1400777c0
// ============ 0x1400777c0 FUN_1400777c0 (size=795) ============


void FUN_1400777c0(void)



{

  ulonglong uVar1;

  bool bVar2;

  undefined8 uVar3;

  longlong lVar4;

  undefined8 *puVar5;

  undefined8 ****ppppuVar6;

  ulonglong uVar7;

  undefined8 ***local_d8;

  undefined8 uStack_d0;

  ulonglong local_c8;

  ulonglong uStack_c0;

  undefined **local_b8 [14];

  undefined1 local_48 [48];

  

  if (DAT_1403d9522 != '\0') {

    if (DAT_1403eada8 != '\0') {

      uVar3 = FUN_140025e00(local_b8);

      FUN_140025ea0(&DAT_1403ead40,uVar3);

      local_b8[0] = TiXmlDocument::vftable;

      FUN_140027900(local_48);

      FUN_140024a60(local_b8);

    }

    lVar4 = FUN_140025320(&DAT_1403ead40);

    bVar2 = false;

    if (lVar4 == 0) {

      lVar4 = FUN_1402c704c(0xd8);

      if (lVar4 == 0) {

        lVar4 = 0;

      }

      else {

        lVar4 = FUN_140025490(lVar4,"settings");

      }

      bVar2 = true;

    }

    FUN_1400258d0(lVar4,"sound",DAT_1403d9500 != '\0');

    FUN_1400258d0(lVar4,"volume",DAT_1403d9504);

    FUN_1400258d0(lVar4,"music",DAT_1403d9508);

    FUN_1400258d0(lVar4,"fullscreen",DAT_1403d950c != '\0');

    FUN_1400258d0(lVar4,&DAT_14030a3dc,DAT_1403d9510);

    FUN_1400258d0(lVar4,&DAT_14030a3e4,DAT_1403d9514);

    FUN_1400258d0(lVar4,&DAT_14030a3ec,DAT_1403d9518);

    FUN_1400258d0(lVar4,&DAT_14030a3f4,DAT_1403d951c);

    FUN_1400258d0(lVar4,"vsync",DAT_1403d9521 != '\0');

    FUN_1400258d0(lVar4,"background_draw",DAT_1403d952a != '\0');

    FUN_1400258d0(lVar4,"background_sim",DAT_1403d952b != '\0');

    if (bVar2) {

      FUN_140025120(&DAT_1403ead40,lVar4);

    }

    puVar5 = (undefined8 *)FUN_1400c4df0();

    lVar4 = puVar5[2];

    if (0x7fffffffffffffffU - lVar4 < 0xc) {

                    /* WARNING: Subroutine does not return */

      FUN_140024130();

    }

    if (0xf < (ulonglong)puVar5[3]) {

      puVar5 = (undefined8 *)*puVar5;

    }

    local_d8 = (undefined8 ****)0x0;

    uStack_d0 = 0;

    local_c8 = 0;

    uStack_c0 = 0;

    uVar1 = lVar4 + 0xc;

    uVar7 = 0xf;

    ppppuVar6 = &local_d8;

    if (0xf < uVar1) {

      uVar7 = uVar1 | 0xf;

      if (uVar7 < 0x8000000000000000) {

        if (uVar7 < 0x16) {

          uVar7 = 0x16;

        }

      }

      else {

        uVar7 = 0x7fffffffffffffff;

      }

      ppppuVar6 = (undefined8 ****)FUN_1400285e0(uVar7 + 1);

      local_d8 = ppppuVar6;

    }

    local_c8 = uVar1;

    uStack_c0 = uVar7;

    FUN_1402f8e20(ppppuVar6,puVar5);

    *(undefined8 *)((longlong)ppppuVar6 + lVar4) = s_settings_xml_14030a3a8._0_8_;

    *(undefined4 *)((longlong)ppppuVar6 + lVar4 + 8) = s_settings_xml_14030a3a8._8_4_;

    *(undefined1 *)((longlong)ppppuVar6 + uVar1) = 0;

    ppppuVar6 = &local_d8;

    if (0xf < uStack_c0) {

      ppppuVar6 = (undefined8 ****)local_d8;

    }

    FUN_1400262c0(&DAT_1403ead40,ppppuVar6);

    if (0xf < uStack_c0) {

      if (0xfff < uStack_c0 + 1) {

        if (0x1f < (ulonglong)((longlong)local_d8 + (-8 - (longlong)local_d8[-1]))) {

                    /* WARNING: Subroutine does not return */

          _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

        }

      }

      FUN_1402c7088();

    }

  }

  return;

}




