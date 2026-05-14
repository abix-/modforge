// Address: 0x140148450
// Ghidra name: FUN_140148450
// ============ 0x140148450 FUN_140148450 (size=293) ============


ulonglong FUN_140148450(longlong param_1,int param_2)



{

  uint uVar1;

  char cVar2;

  byte bVar3;

  ulonglong uVar4;

  uint uVar5;

  

  bVar3 = 1;

  cVar2 = FUN_1401489c0();

  if (cVar2 == '\0') {

    uVar4 = FUN_14012e850("Parameter \'%s\' is invalid","surface");

    return uVar4;

  }

  if (param_2 != 0x7fffffff) {

    uVar1 = *(uint *)(param_1 + 0x108);

    uVar5 = uVar1 & 0xfffffc0f;

    *(uint *)(param_1 + 0x108) = uVar5;

    switch(param_2) {

    case 0:

      break;

    case 1:

      *(uint *)(param_1 + 0x108) = uVar5 | 0x10;

      break;

    case 2:

      *(uint *)(param_1 + 0x108) = uVar5 | 0x40;

      break;

    default:

      bVar3 = FUN_14012e850("That operation is not supported");

      break;

    case 4:

      *(uint *)(param_1 + 0x108) = uVar5 | 0x100;

      break;

    case 8:

      *(uint *)(param_1 + 0x108) = uVar5 | 0x200;

      break;

    case 0x10:

      *(uint *)(param_1 + 0x108) = uVar5 | 0x20;

      break;

    case 0x20:

      *(uint *)(param_1 + 0x108) = uVar5 | 0x80;

    }

    if (*(uint *)(param_1 + 0x108) != uVar1) {

      FUN_14017ba60(param_1 + 0x78);

    }

    return (ulonglong)bVar3;

  }

  uVar4 = FUN_14012e850("Parameter \'%s\' is invalid","blendMode");

  return uVar4;

}




