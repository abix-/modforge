// Address: 0x14016ca90
// Ghidra name: FUN_14016ca90
// ============ 0x14016ca90 FUN_14016ca90 (size=278) ============


void FUN_14016ca90(void)



{

  undefined4 *puVar1;

  undefined4 *puVar2;

  code *pcVar3;

  longlong lVar4;

  

  lVar4 = DAT_1403fc410;

  if (DAT_1403fc410 != 0) {

    pcVar3 = *(code **)(DAT_1403fc410 + 0x1f0);

    puVar1 = (undefined4 *)(DAT_1403fc410 + 0x3e4);

    puVar2 = (undefined4 *)(DAT_1403fc410 + 1000);

    *(undefined4 *)(DAT_1403fc410 + 0x3a0) = 8;

    *(undefined8 *)(lVar4 + 0x520) = 0;

    *(undefined8 *)(lVar4 + 0x528) = 0;

    *(undefined8 *)(lVar4 + 0x530) = 0;

    *(undefined8 *)(lVar4 + 0x538) = 0;

    *(undefined4 *)(lVar4 + 0x3a4) = 8;

    *(undefined4 *)(lVar4 + 0x3a8) = 8;

    *(undefined4 *)(lVar4 + 0x3ac) = 8;

    *(undefined8 *)(lVar4 + 0x3b0) = 0x10;

    *(undefined4 *)(lVar4 + 0x3b8) = 0;

    *(undefined8 *)(lVar4 + 0x3bc) = 1;

    *(undefined8 *)(lVar4 + 0x3c4) = 0;

    *(undefined8 *)(lVar4 + 0x3cc) = 0;

    *(undefined8 *)(lVar4 + 0x3d4) = 0;

    *(undefined4 *)(lVar4 + 0x3dc) = 0;

    *(undefined4 *)(lVar4 + 0x408) = 1;

    *(undefined4 *)(lVar4 + 0x3e0) = 0xffffffff;

    *puVar1 = 2;

    *puVar2 = 1;

    *(undefined4 *)(lVar4 + 0x3f0) = 0;

    if (pcVar3 != (code *)0x0) {

      (*pcVar3)(lVar4);

      lVar4 = DAT_1403fc410;

    }

    *(undefined4 *)(lVar4 + 0x3ec) = 0;

    *(undefined8 *)(lVar4 + 0x400) = 0;

    *(undefined4 *)(lVar4 + 0x3f4) = 0;

    *(undefined4 *)(lVar4 + 0x40c) = 0;

    *(undefined8 *)(lVar4 + 0x3f8) = 1;

  }

  return;

}




