// Address: 0x140267f50
// Ghidra name: FUN_140267f50
// ============ 0x140267f50 FUN_140267f50 (size=191) ============


ulonglong FUN_140267f50(longlong param_1,char param_2,char param_3)



{

  byte bVar1;

  ulonglong in_RAX;

  ulonglong uVar2;

  

  if (param_3 == '\0') {

    if (param_2 == '\t') {

      return in_RAX & 0xffffffffffffff00;

    }

    bVar1 = *(byte *)(param_1 + 0xdc);

    uVar2 = (ulonglong)bVar1;

    *(byte *)(param_1 + 0xdc) = bVar1 + 1;

    if (bVar1 == 0) {

      *(undefined1 *)(param_1 + 0xdc) = 2;

      uVar2 = 1;

    }

  }

  else if (param_2 == '\x06') {

    bVar1 = *(byte *)(param_1 + 0xd9);

    uVar2 = (ulonglong)bVar1;

    *(byte *)(param_1 + 0xd9) = bVar1 + 1;

    if (bVar1 == 0) {

      *(undefined1 *)(param_1 + 0xd9) = 2;

      return 1;

    }

  }

  else if (param_2 == '\x1e') {

    bVar1 = *(byte *)(param_1 + 0xda);

    uVar2 = (ulonglong)bVar1;

    *(byte *)(param_1 + 0xda) = bVar1 + 1;

    if (bVar1 == 0) {

      *(undefined1 *)(param_1 + 0xda) = 2;

      return 1;

    }

  }

  else if (param_2 == '`') {

    bVar1 = *(byte *)(param_1 + 0xdb);

    uVar2 = (ulonglong)bVar1;

    *(byte *)(param_1 + 0xdb) = bVar1 + 1;

    if (bVar1 == 0) {

      *(undefined1 *)(param_1 + 0xdb) = 2;

      return 1;

    }

  }

  else {

    bVar1 = *(byte *)(param_1 + 0xd8);

    uVar2 = (ulonglong)bVar1;

    *(byte *)(param_1 + 0xd8) = bVar1 + 1;

    if (bVar1 == 0) {

      *(undefined1 *)(param_1 + 0xd8) = 2;

      return 1;

    }

  }

  return uVar2;

}




