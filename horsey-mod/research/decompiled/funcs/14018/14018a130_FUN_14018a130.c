// Address: 0x14018a130
// Ghidra name: FUN_14018a130
// ============ 0x14018a130 FUN_14018a130 (size=701) ============


undefined1 FUN_14018a130(longlong param_1)



{

  int iVar1;

  undefined1 uVar2;

  char cVar3;

  

  if (*(short *)(param_1 + 0x24) == 0) {

    uVar2 = FUN_14012e850("Invalid number of channels");

    return uVar2;

  }

  if (*(uint *)(param_1 + 0x28) == 0) {

    uVar2 = FUN_14012e850("Invalid sample rate");

    return uVar2;

  }

  if (0x7fffffff < *(uint *)(param_1 + 0x28)) {

    uVar2 = FUN_14012e850("Sample rate exceeds limit of %d",0x7fffffff);

    return uVar2;

  }

  iVar1 = *(int *)(param_1 + 0x70);

  if ((iVar1 == 2) && (*(int *)(param_1 + 0x50) == -1)) {

    uVar2 = FUN_14012e850("Invalid fact chunk in WAVE file");

    return uVar2;

  }

  switch(*(undefined2 *)(param_1 + 0x22)) {

  case 2:

  case 3:

  case 6:

  case 7:

  case 0x11:

    if ((iVar1 == 2) && (*(int *)(param_1 + 0x50) < 1)) {

      uVar2 = FUN_14012e850("Missing fact chunk in WAVE file");

      return uVar2;

    }

  case 1:

    if (*(ulonglong *)(param_1 + 0x18) < 0x10) {

      uVar2 = FUN_14012e850("Missing wBitsPerSample field in WAVE fmt chunk");

      return uVar2;

    }

    if (*(short *)(param_1 + 0x32) == 0) {

      uVar2 = FUN_14012e850("Invalid bits per sample");

      return uVar2;

    }

    if (*(short *)(param_1 + 0x30) == 0) {

      *(undefined2 *)(param_1 + 0x30) = 1;

    }

    if ((*(int *)(param_1 + 0x50) == 1) &&

       (((iVar1 == 1 || (iVar1 == 2)) || ((iVar1 == 3 && (*(int *)(param_1 + 0x54) != 0)))))) {

      *(undefined4 *)(param_1 + 0x50) = 2;

    }

  }

  switch(*(undefined2 *)(param_1 + 0x22)) {

  case 1:

  case 3:

    cVar3 = FUN_140189d80(param_1);

    break;

  case 2:

    cVar3 = FUN_140189820(param_1);

    break;

  default:

    if (*(short *)(param_1 + 0x20) == -2) {

      uVar2 = FUN_14012e850("Unknown WAVE format GUID: %08x-%04x-%04x-%02x%02x%02x%02x%02x%02x%02x%02x"

                            ,*(undefined4 *)(param_1 + 0x40),*(undefined2 *)(param_1 + 0x44),

                            *(undefined2 *)(param_1 + 0x46),*(undefined1 *)(param_1 + 0x48),

                            *(undefined1 *)(param_1 + 0x49),*(undefined1 *)(param_1 + 0x4a),

                            *(undefined1 *)(param_1 + 0x4b),*(undefined1 *)(param_1 + 0x4c),

                            *(undefined1 *)(param_1 + 0x4d),*(undefined1 *)(param_1 + 0x4e),

                            *(undefined1 *)(param_1 + 0x4f));

      return uVar2;

    }

    uVar2 = FUN_14012e850("Unknown WAVE format tag: 0x%04x",*(undefined2 *)(param_1 + 0x22));

    return uVar2;

  case 6:

  case 7:

    cVar3 = FUN_1401891b0(param_1);

    break;

  case 0x11:

    cVar3 = FUN_140188c80(param_1);

    return cVar3 != '\0';

  case 0x50:

  case 0x55:

    uVar2 = FUN_14012e850("MPEG formats not supported");

    return uVar2;

  }

  if (cVar3 != '\0') {

    return true;

  }

  return false;

}




