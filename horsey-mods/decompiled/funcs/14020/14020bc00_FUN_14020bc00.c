// Address: 0x14020bc00
// Ghidra name: FUN_14020bc00
// ============ 0x14020bc00 FUN_14020bc00 (size=339) ============


undefined8 FUN_14020bc00(longlong param_1,undefined4 param_2)



{

  undefined4 uVar1;

  longlong lVar2;

  undefined8 uVar3;

  ushort uVar4;

  ushort uVar5;

  

  _guard_check_icall();

  lVar2 = FUN_14020d2c0(param_2);

  if (lVar2 != 0) {

    *(longlong *)(param_1 + 0x148) = lVar2;

    *(uint *)(param_1 + 0x44) = (uint)*(ushort *)(lVar2 + 0x34);

    *(uint *)(param_1 + 0x70) = (uint)*(ushort *)(lVar2 + 0x36);

    uVar4 = 0;

    *(uint *)(param_1 + 0x60) = (uint)*(ushort *)(lVar2 + 0x3a);

    uVar5 = 0;

    *(longlong *)(lVar2 + 0x100) = param_1;

    if (*(short *)(lVar2 + 0x3c) != 0) {

      do {

        FUN_14015a220(param_1,*(undefined4 *)(*(longlong *)(lVar2 + 0xd8) + (ulonglong)uVar5 * 0x10)

                     );

        uVar5 = uVar5 + 1;

      } while (uVar5 < *(ushort *)(lVar2 + 0x3c));

    }

    if (*(short *)(lVar2 + 0x3e) != 0) {

      do {

        FUN_14015a190(param_1,*(undefined4 *)(*(longlong *)(lVar2 + 0xe0) + (ulonglong)uVar4 * 0x18)

                      ,*(undefined4 *)(*(longlong *)(lVar2 + 0xe0) + 8 + (ulonglong)uVar4 * 0x18));

        uVar4 = uVar4 + 1;

      } while (uVar4 < *(ushort *)(lVar2 + 0x3e));

    }

    if (*(longlong *)(lVar2 + 0x90) != 0) {

      uVar1 = FUN_140158c10(param_1);

      FUN_140175280(uVar1,"SDL.joystick.cap.rgb_led",1);

    }

    if (*(longlong *)(lVar2 + 0x80) != 0) {

      uVar1 = FUN_140158c10(param_1);

      FUN_140175280(uVar1,"SDL.joystick.cap.rumble",1);

    }

    if (*(longlong *)(lVar2 + 0x88) != 0) {

      uVar1 = FUN_140158c10(param_1);

      FUN_140175280(uVar1,"SDL.joystick.cap.trigger_rumble",1);

    }

    return 1;

  }

  uVar3 = FUN_14012e850("No such device");

  return uVar3;

}




