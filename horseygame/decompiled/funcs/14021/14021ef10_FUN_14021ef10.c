// Address: 0x14021ef10
// Ghidra name: FUN_14021ef10
// ============ 0x14021ef10 FUN_14021ef10 (size=144) ============


void FUN_14021ef10(void)



{

  int iVar1;

  undefined4 uVar2;

  longlong lVar3;

  longlong lVar4;

  

  if ((DAT_1403fdba0 != 0) && (lVar3 = FUN_1401841f0((longlong)DAT_1403fdba0 << 3), lVar3 != 0)) {

    iVar1 = FUN_1401aa850(0xb,lVar3,DAT_1403fdba0);

    if (0 < iVar1) {

      lVar4 = 0;

      do {

        FUN_140198c40(*(undefined8 *)(lVar3 + lVar4 * 8));

        lVar4 = lVar4 + 1;

      } while (lVar4 < iVar1);

    }

    FUN_1401841e0(lVar3);

    uVar2 = FUN_140174be0();

    FUN_1401745e0(uVar2,"SDL.internal.tray.cleanup");

  }

  return;

}




