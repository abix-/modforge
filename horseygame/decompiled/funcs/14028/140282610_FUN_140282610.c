// Address: 0x140282610
// Ghidra name: FUN_140282610
// ============ 0x140282610 FUN_140282610 (size=260) ============


undefined8 FUN_140282610(longlong param_1,longlong param_2)



{

  longlong lVar1;

  float fVar2;

  byte bVar3;

  

  lVar1 = *(longlong *)(param_1 + 0x70);

  _guard_check_icall();

  *(uint *)(param_2 + 0x70) = (uint)*(byte *)(lVar1 + 0x6d);

  *(undefined8 *)(lVar1 + 0x2c) = 0;

  *(undefined8 *)(lVar1 + 0x34) = 0;

  *(undefined8 *)(lVar1 + 0x3c) = 0;

  *(undefined8 *)(lVar1 + 0x44) = 0;

  *(undefined8 *)(lVar1 + 0x4c) = 0;

  *(undefined8 *)(lVar1 + 0x54) = 0;

  *(undefined8 *)(lVar1 + 0x5c) = 0;

  *(undefined8 *)(lVar1 + 100) = 0;

  *(uint *)(param_2 + 0x44) = (uint)*(byte *)(lVar1 + 0x6c);

  if (*(char *)(lVar1 + 0x17) != '\0') {

    *(undefined4 *)(param_2 + 0x60) = 1;

  }

  fVar2 = DAT_14037f68c;

  if (*(char *)(lVar1 + 0x12) != '\0') {

    FUN_14015a190(param_2,2,DAT_14037f68c / (float)*(ushort *)(lVar1 + 0x1c));

  }

  if (*(char *)(lVar1 + 0x11) != '\0') {

    FUN_14015a190(param_2,1,fVar2 / (float)*(ushort *)(lVar1 + 0x1c));

  }

  if (*(char *)(lVar1 + 0x18) == '\0') {

    return 1;

  }

  bVar3 = *(byte *)(lVar1 + 0x1a);

  if (bVar3 == 0) {

    bVar3 = 1;

    *(undefined1 *)(lVar1 + 0x1a) = 1;

LAB_1402826c6:

    if (bVar3 == 0) goto LAB_1402826d6;

  }

  else {

    if (2 < bVar3) {

      bVar3 = 2;

    }

    *(byte *)(lVar1 + 0x1a) = bVar3;

    if (bVar3 < 2) goto LAB_1402826c6;

    *(undefined1 *)(lVar1 + 0x1b) = 1;

  }

  FUN_14015a220(param_2,*(undefined1 *)(lVar1 + 0x1b));

LAB_1402826d6:

  if (1 < *(byte *)(lVar1 + 0x1a)) {

    FUN_14015a220(param_2,*(undefined1 *)(lVar1 + 0x1b));

  }

  return 1;

}




