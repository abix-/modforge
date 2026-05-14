// Address: 0x14020d110
// Ghidra name: FUN_14020d110
// ============ 0x14020d110 FUN_14020d110 (size=428) ============


void FUN_14020d110(longlong param_1)



{

  longlong lVar1;

  longlong lVar2;

  ulonglong uVar3;

  longlong lVar4;

  ushort uVar5;

  

  lVar4 = 0;

  _guard_check_icall();

  if (param_1 != 0) {

    lVar1 = DAT_1403fd260;

    if (*(code **)(param_1 + 0xa8) != (code *)0x0) {

      (**(code **)(param_1 + 0xa8))(*(undefined8 *)(param_1 + 0x68));

      lVar1 = DAT_1403fd260;

    }

    for (; lVar2 = DAT_1403fd260, lVar1 != 0; lVar1 = *(longlong *)(lVar1 + 0x108)) {

      if (param_1 == lVar1) {

        lVar2 = *(longlong *)(lVar1 + 0x108);

        if (lVar4 != 0) {

          *(longlong *)(lVar4 + 0x108) = *(longlong *)(lVar1 + 0x108);

          lVar2 = DAT_1403fd260;

        }

        break;

      }

      lVar4 = lVar1;

    }

    DAT_1403fd260 = lVar2;

    if (*(longlong *)(param_1 + 0x100) != 0) {

      *(undefined8 *)(*(longlong *)(param_1 + 0x100) + 0x148) = 0;

      *(undefined8 *)(param_1 + 0x100) = 0;

    }

    if (*(longlong *)(param_1 + 8) != 0) {

      FUN_1401841e0();

      *(undefined8 *)(param_1 + 8) = 0;

    }

    if (*(longlong *)(param_1 + 0xb8) != 0) {

      FUN_1401841e0();

      *(undefined8 *)(param_1 + 0xb8) = 0;

    }

    if (*(longlong *)(param_1 + 0xc0) != 0) {

      FUN_1401841e0();

      *(undefined8 *)(param_1 + 0xc0) = 0;

    }

    if (*(longlong *)(param_1 + 200) != 0) {

      FUN_1401841e0();

      *(undefined8 *)(param_1 + 200) = 0;

    }

    if (*(longlong *)(param_1 + 0xd0) != 0) {

      FUN_1401841e0();

      *(undefined8 *)(param_1 + 0xd0) = 0;

    }

    if (*(longlong *)(param_1 + 0xd8) != 0) {

      uVar5 = 0;

      if (*(short *)(param_1 + 0x3c) != 0) {

        do {

          uVar3 = (ulonglong)uVar5;

          FUN_1401841e0(*(undefined8 *)(*(longlong *)(param_1 + 0xd8) + 8 + uVar3 * 0x10));

          uVar5 = uVar5 + 1;

          *(undefined8 *)(*(longlong *)(param_1 + 0xd8) + 8 + uVar3 * 0x10) = 0;

        } while (uVar5 < *(ushort *)(param_1 + 0x3c));

      }

      FUN_1401841e0(*(undefined8 *)(param_1 + 0xd8));

      *(undefined8 *)(param_1 + 0xd8) = 0;

    }

    if (*(longlong *)(param_1 + 0xe0) != 0) {

      FUN_1401841e0();

      *(undefined8 *)(param_1 + 0xe0) = 0;

    }

    if (*(longlong *)(param_1 + 0xf8) != 0) {

      FUN_1401841e0();

      *(undefined8 *)(param_1 + 0xf8) = 0;

    }

    FUN_1401841e0(param_1);

  }

  return;

}




