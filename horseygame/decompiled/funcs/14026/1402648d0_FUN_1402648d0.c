// Address: 0x1402648d0
// Ghidra name: FUN_1402648d0
// ============ 0x1402648d0 FUN_1402648d0 (size=311) ============


undefined8 FUN_1402648d0(longlong param_1,longlong param_2)



{

  uint uVar1;

  longlong lVar2;

  undefined8 uVar3;

  ulonglong uVar4;

  

  lVar2 = FUN_140268130();

  if (lVar2 != 0) {

    _guard_check_icall();

    *(undefined4 *)(lVar2 + 0xf1) = 0;

    *(undefined4 *)(lVar2 + 0xe4) = 0;

    *(undefined8 *)(lVar2 + 0xe8) = 0;

    *(undefined1 *)(lVar2 + 0xf0) = 0;

    *(undefined8 *)(lVar2 + 0xf5) = 0;

    *(undefined8 *)(lVar2 + 0xfd) = 0;

    *(undefined8 *)(lVar2 + 0x105) = 0;

    *(undefined8 *)(lVar2 + 0x10d) = 0;

    *(undefined8 *)(lVar2 + 0x115) = 0;

    *(undefined8 *)(lVar2 + 0x11d) = 0;

    *(undefined8 *)(lVar2 + 0x125) = 0;

    *(undefined8 *)(lVar2 + 0x12d) = 0;

    *(undefined4 *)(param_2 + 0x70) = 0xb;

    FUN_1402651d0(lVar2);

    if ((*(int *)(lVar2 + 0x148) != 0) ||

       ((uVar4 = 0x45e, *(short *)(param_1 + 0x20) == 0x45e &&

        (uVar4 = 0xb00, *(short *)(param_1 + 0x22) == 0xb00)))) {

      uVar4 = 0;

      *(undefined1 *)(lVar2 + 0x155) = *(undefined1 *)(param_2 + 0x70);

      *(int *)(param_2 + 0x70) = *(int *)(param_2 + 0x70) + 4;

    }

    if ((*(byte *)(lVar2 + 0x14c) & 1) != 0) {

      uVar4 = 0;

      *(undefined1 *)(lVar2 + 0x154) = *(undefined1 *)(param_2 + 0x70);

      *(int *)(param_2 + 0x70) = *(int *)(param_2 + 0x70) + 1;

    }

    if (0 < *(int *)(lVar2 + 0x158)) {

      uVar4 = 0;

      *(undefined1 *)(lVar2 + 0x156) = *(undefined1 *)(param_2 + 0x70);

      *(int *)(param_2 + 0x70) = *(int *)(param_2 + 0x70) + *(int *)(lVar2 + 0x158);

    }

    *(undefined4 *)(param_2 + 0x44) = 6;

    if (*(int *)(lVar2 + 0x144) == 3) {

      uVar1 = *(int *)(lVar2 + 0x15c) + 5;

      uVar4 = (ulonglong)uVar1;

      *(uint *)(param_2 + 0x44) = uVar1;

    }

    *(undefined4 *)(param_2 + 0x60) = 1;

    return CONCAT71((int7)(uVar4 >> 8),1);

  }

  uVar3 = FUN_14012e850("Invalid joystick");

  return uVar3;

}




