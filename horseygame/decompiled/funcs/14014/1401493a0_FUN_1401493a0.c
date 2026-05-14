// Address: 0x1401493a0
// Ghidra name: FUN_1401493a0
// ============ 0x1401493a0 FUN_1401493a0 (size=178) ============


void FUN_1401493a0(void)



{

  undefined1 auVar1 [16];

  uint uVar2;

  ulonglong uVar3;

  ulonglong uVar4;

  

  if (DAT_1403fc030 == 0) {

    FUN_1401427d0("SDL_TIMER_RESOLUTION",FUN_1401497b0,0);

    uVar3 = FUN_1401842a0();

    uVar2 = FUN_1401aa450(1000000000);

    auVar1._8_8_ = 0;

    auVar1._0_8_ = CONCAT44(0,uVar2);

    DAT_1403fc038 = SUB164((ZEXT816(0) << 0x40 | ZEXT816(1000000000)) / auVar1,0);

    DAT_1403fc03c = (undefined4)(uVar3 / CONCAT44(0,uVar2));

    uVar2 = FUN_1401aa450(1000);

    uVar4 = (ulonglong)uVar2;

    DAT_1403fc040 = (undefined4)(1000 / uVar4);

    DAT_1403fc044 = (undefined4)(uVar3 / uVar4);

    DAT_1403fc030 = FUN_140184280(uVar4,uVar3 % uVar4);

    if (DAT_1403fc030 == 0) {

      DAT_1403fc030 = -1;

    }

  }

  return;

}




