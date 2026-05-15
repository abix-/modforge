// Address: 0x140278680
// Ghidra name: FUN_140278680
// ============ 0x140278680 FUN_140278680 (size=63) ============


undefined8 FUN_140278680(longlong param_1)



{

  int iVar1;

  undefined8 uVar2;

  

  iVar1 = *(int *)(param_1 + 0x1c);

  if ((iVar1 == 0x81) || (iVar1 == 0x82)) {

    uVar2 = 0x32;

    if (*(char *)(param_1 + 0x2b) != '\0') {

      uVar2 = 0x35;

    }

    return uVar2;

  }

  if (iVar1 == 0x83) {

    return 0x3d;

  }

  if (*(char *)(param_1 + 0x2b) == '\0') {

    return 0x30;

  }

  return 0x35;

}




