// Address: 0x140273be0
// Ghidra name: FUN_140273be0
// ============ 0x140273be0 FUN_140273be0 (size=256) ============


undefined1 FUN_140273be0(longlong param_1,char *param_2,uint param_3)



{

  undefined8 uVar1;

  char cVar2;

  int iVar3;

  

  if (*param_2 == '\x01') {

    if ((*(char *)(param_1 + 0x10) != '\0') && (0x2f < param_3)) {

      iVar3 = memcmp(param_2 + 0xc,(void *)(param_1 + 0x8f),4);

      if (iVar3 != 0) {

        if (*(char *)(param_1 + 0x8f) != '\0') {

          return 1;

        }

        if (*(char *)(param_1 + 0x90) != '\0') {

          return 1;

        }

        if (*(char *)(param_1 + 0x91) != '\0') {

          return 1;

        }

        if (*(char *)(param_1 + 0x92) != '\0') {

          return 1;

        }

        uVar1 = *(undefined8 *)(param_2 + 9);

        *(undefined8 *)(param_1 + 0x84) = *(undefined8 *)(param_2 + 1);

        *(undefined8 *)(param_1 + 0x8c) = uVar1;

        uVar1 = *(undefined8 *)(param_2 + 0x19);

        *(undefined8 *)(param_1 + 0x94) = *(undefined8 *)(param_2 + 0x11);

        *(undefined8 *)(param_1 + 0x9c) = uVar1;

        *(undefined8 *)(param_1 + 0xa4) = *(undefined8 *)(param_2 + 0x21);

        *(undefined4 *)(param_1 + 0xac) = *(undefined4 *)(param_2 + 0x29);

        *(undefined2 *)(param_1 + 0xb0) = *(undefined2 *)(param_2 + 0x2d);

        *(char *)(param_1 + 0xb2) = param_2[0x2f];

      }

      return 0;

    }

  }

  else {

    if (*param_2 != '1') {

      return 0;

    }

    cVar2 = FUN_1402720b0(param_2,param_3);

    if (cVar2 == '\0') {

      return 0;

    }

  }

  return 1;

}




