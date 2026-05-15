// Address: 0x1402712b0
// Ghidra name: FUN_1402712b0
// ============ 0x1402712b0 FUN_1402712b0 (size=383) ============


undefined8 FUN_1402712b0(longlong param_1,byte *param_2,uint param_3)



{

  undefined8 uVar1;

  char cVar2;

  int iVar3;

  ushort uVar4;

  

  switch(*param_2 - 1) {

  case 0:

    break;

  default:

    return 0;

  case 0x10:

  case 0x11:

  case 0x12:

  case 0x13:

  case 0x14:

  case 0x15:

  case 0x16:

  case 0x17:

  case 0x18:

    if ((int)param_3 < 0x4e) {

      return 0;

    }

    if (-1 < (char)param_2[1]) {

      return 0;

    }

    cVar2 = FUN_1402720b0(param_2,0x4e);

    uVar4 = *(ushort *)(param_1 + 0x82);

    if (cVar2 != '\0') {

      *(ushort *)(param_1 + 0x82) = uVar4 + 1;

      return 1;

    }

    if (uVar4 != 0) {

      uVar4 = uVar4 - 1;

      *(ushort *)(param_1 + 0x82) = uVar4;

    }

    if (2 < uVar4) {

      return 0;

    }

    return 1;

  }

  if (param_3 != 10) {

    if ((*(char *)(param_1 + 0x11) != '\0') && (0x36 < param_3)) {

      iVar3 = memcmp(param_2 + 10,(void *)(param_1 + 0x8d),2);

      if (iVar3 == 0) {

        return 0;

      }

      if ((((*(char *)(param_1 + 0x96) == '\0') && (*(char *)(param_1 + 0x97) == '\0')) &&

          (*(char *)(param_1 + 0x98) == '\0')) &&

         (((*(char *)(param_1 + 0x99) == '\0' && (*(char *)(param_1 + 0x9a) == '\0')) &&

          (*(char *)(param_1 + 0x9b) == '\0')))) {

        uVar1 = *(undefined8 *)(param_2 + 9);

        *(undefined8 *)(param_1 + 0x84) = *(undefined8 *)(param_2 + 1);

        *(undefined8 *)(param_1 + 0x8c) = uVar1;

        uVar1 = *(undefined8 *)(param_2 + 0x19);

        *(undefined8 *)(param_1 + 0x94) = *(undefined8 *)(param_2 + 0x11);

        *(undefined8 *)(param_1 + 0x9c) = uVar1;

        uVar1 = *(undefined8 *)(param_2 + 0x29);

        *(undefined8 *)(param_1 + 0xa4) = *(undefined8 *)(param_2 + 0x21);

        *(undefined8 *)(param_1 + 0xac) = uVar1;

        *(undefined4 *)(param_1 + 0xb4) = *(undefined4 *)(param_2 + 0x31);

        *(undefined2 *)(param_1 + 0xb8) = *(undefined2 *)(param_2 + 0x35);

        return 0;

      }

    }

    if ((int)param_3 < 0x40) {

      return 0;

    }

    if ((param_2[0x1f] & 4) != 0) {

      return 0;

    }

  }

  return 1;

}




