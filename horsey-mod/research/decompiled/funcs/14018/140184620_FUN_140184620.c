// Address: 0x140184620
// Ghidra name: FUN_140184620
// ============ 0x140184620 FUN_140184620 (size=131) ============


void FUN_140184620(undefined8 param_1)



{

  longlong lVar1;

  undefined8 local_88;

  undefined8 uStack_80;

  undefined8 local_78;

  undefined8 uStack_70;

  undefined8 local_68;

  undefined8 uStack_60;

  undefined8 local_58;

  undefined8 uStack_50;

  undefined8 local_48;

  undefined8 uStack_40;

  undefined8 local_38;

  undefined8 uStack_30;

  undefined8 local_28;

  undefined8 uStack_20;

  undefined8 local_18;

  undefined8 uStack_10;

  

  lVar1 = FUN_140142960("SDL_PREFERRED_LOCALES");

  if (lVar1 == 0) {

    local_88 = 0;

    uStack_80 = 0;

    local_78 = 0;

    uStack_70 = 0;

    local_68 = 0;

    uStack_60 = 0;

    local_58 = 0;

    uStack_50 = 0;

    local_48 = 0;

    uStack_40 = 0;

    local_38 = 0;

    uStack_30 = 0;

    local_28 = 0;

    uStack_20 = 0;

    local_18 = 0;

    uStack_10 = 0;

    FUN_14022da90(&local_88,0x80);

  }

  else {

    FUN_14012f1a0(&local_88,lVar1,0x80);

  }

  FUN_1401846b0(&local_88,param_1);

  return;

}




