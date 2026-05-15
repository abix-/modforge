// Address: 0x14020f7e0
// Ghidra name: FUN_14020f7e0
// ============ 0x14020f7e0 FUN_14020f7e0 (size=276) ============


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



undefined1 FUN_14020f7e0(void)



{

  undefined1 auVar1 [16];

  uint uVar2;

  char cVar3;

  undefined1 uVar4;

  int iVar5;

  ulonglong uVar6;

  uint uVar7;

  longlong lVar8;

  

  cVar3 = FUN_140142940("SDL_JOYSTICK_GAMEINPUT",0);

  if (cVar3 == '\0') {

    cVar3 = FUN_14000c9a0();

    if (cVar3 == '\0') {

      return 1;

    }

  }

  cVar3 = FUN_140289250(&DAT_1403fd3b0);

  if (cVar3 == '\0') {

    return 0;

  }

  cVar3 = FUN_140142940("SDL_JOYSTICK_GAMEINPUT",0);

  uVar7 = -(uint)(cVar3 != '\0') & 0xe;

  cVar3 = FUN_14000c9a0(uVar7);

  uVar2 = uVar7 | 1;

  if (cVar3 == '\0') {

    uVar2 = uVar7;

  }

  iVar5 = (**(code **)(*DAT_1403fd3b0 + 0x48))

                    (DAT_1403fd3b0,0,uVar2,1,2,0,FUN_140210790,&DAT_1403fd3b8);

  if (iVar5 < 0) {

    FUN_14020f770();

    uVar4 = FUN_1401a9ef0("IGameInput::RegisterDeviceCallback",iVar5);

    return uVar4;

  }

  uVar6 = FUN_140149300();

  _DAT_1403fd3c0 = (**(code **)(*DAT_1403fd3b0 + 0x18))();

  auVar1._8_8_ = 0;

  auVar1._0_8_ = uVar6;

  lVar8 = SUB168(ZEXT816(0x624dd2f1a9fbe77) * auVar1,8);

  _DAT_1403fd3c0 = ((uVar6 - lVar8 >> 1) + lVar8 >> 9) - _DAT_1403fd3c0;

  FUN_14020f6c0();

  return 1;

}




