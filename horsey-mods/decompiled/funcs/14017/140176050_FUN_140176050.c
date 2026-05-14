// Address: 0x140176050
// Ghidra name: FUN_140176050
// ============ 0x140176050 FUN_140176050 (size=252) ============


bool FUN_140176050(longlong param_1)



{

  char cVar1;

  undefined1 uVar2;

  int iVar3;

  

  if (param_1 != 0) {

    if (DAT_1403e3d60 != '\0') {

      cVar1 = FUN_1401aa7c0(param_1,6);

      if (cVar1 == '\0') goto LAB_14017612c;

    }

    if (-1 < *(int *)(param_1 + 0x34)) {

      return true;

    }

    *(undefined8 *)(param_1 + 0x38) = 0;

    *(undefined8 *)(param_1 + 0x40) = 0;

    *(undefined8 *)(param_1 + 0x48) = 0;

    *(undefined8 *)(param_1 + 0x50) = 0;

    *(undefined8 *)(param_1 + 0x58) = 0;

    *(undefined8 *)(param_1 + 0x60) = 0;

    *(undefined8 *)(param_1 + 0x68) = 0;

    *(undefined8 *)(param_1 + 0x70) = 0;

    *(undefined8 *)(param_1 + 0x78) = 0;

    if ((*(uint *)(param_1 + 0x20) & 2) == 0) {

      if ((*(uint *)(param_1 + 0x20) & 0x800) == 0) {

        uVar2 = FUN_14012e850("Device doesn\'t support rumble");

        return (bool)uVar2;

      }

      *(undefined2 *)(param_1 + 0x38) = 0x800;

      *(undefined4 *)(param_1 + 0x3c) = 5000;

      *(undefined4 *)(param_1 + 0x40) = 0x40004000;

    }

    else {

      *(undefined2 *)(param_1 + 0x38) = 2;

      *(undefined2 *)(param_1 + 0x5e) = 0;

      *(undefined2 *)(param_1 + 0x62) = 0;

      *(undefined1 *)(param_1 + 0x3c) = 1;

      *(undefined4 *)(param_1 + 0x56) = 0x400003e8;

      *(undefined4 *)(param_1 + 0x4c) = 5000;

    }

    iVar3 = FUN_140175740(param_1,param_1 + 0x38);

    *(int *)(param_1 + 0x34) = iVar3;

    return -1 < iVar3;

  }

LAB_14017612c:

  FUN_14012e850("Parameter \'%s\' is invalid","haptic");

  return false;

}




