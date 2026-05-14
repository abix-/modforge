// Address: 0x1401765b0
// Ghidra name: FUN_1401765b0
// ============ 0x1401765b0 FUN_1401765b0 (size=252) ============


ulonglong FUN_1401765b0(longlong param_1,float param_2,undefined4 param_3)



{

  char cVar1;

  undefined2 uVar2;

  ulonglong uVar3;

  float fVar4;

  float fVar5;

  

  if (param_1 == 0) {

LAB_140176687:

    uVar3 = FUN_14012e850("Parameter \'%s\' is invalid","haptic");

  }

  else {

    if (DAT_1403e3d60 != '\0') {

      cVar1 = FUN_1401aa7c0(param_1,6);

      if (cVar1 == '\0') goto LAB_140176687;

    }

    if (*(int *)(param_1 + 0x34) < 0) {

      uVar3 = FUN_14012e850("Haptic: Rumble effect not initialized on haptic device");

      return uVar3;

    }

    fVar4 = 0.0;

    if (0.0 <= param_2) {

      fVar4 = param_2;

    }

    fVar5 = DAT_14039ca44;

    if (fVar4 <= DAT_14039ca44) {

      fVar5 = fVar4;

    }

    uVar2 = (undefined2)(int)(fVar5 * DAT_1403053f0);

    if (*(short *)(param_1 + 0x38) == 2) {

      *(undefined2 *)(param_1 + 0x58) = uVar2;

      *(undefined4 *)(param_1 + 0x4c) = param_3;

    }

    else if (*(short *)(param_1 + 0x38) == 0x800) {

      *(undefined2 *)(param_1 + 0x40) = uVar2;

      *(undefined2 *)(param_1 + 0x42) = uVar2;

      *(undefined4 *)(param_1 + 0x3c) = param_3;

    }

    uVar3 = FUN_140176b70(param_1);

    if ((char)uVar3 != '\0') {

      uVar3 = FUN_140176770(param_1,*(undefined4 *)(param_1 + 0x34),1);

      return uVar3;

    }

  }

  return uVar3 & 0xffffffffffffff00;

}




