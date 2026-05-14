// Address: 0x140183f10
// Ghidra name: FUN_140183f10
// ============ 0x140183f10 FUN_140183f10 (size=259) ============


void FUN_140183f10(longlong param_1,char param_2)



{

  undefined4 uVar1;

  int iVar2;

  uint uVar3;

  int iVar4;

  

  if ((DAT_1403fcaf0 != 0) && (*(char *)(DAT_1403fcaf0 + 0x14) != '\0')) {

    FUN_1401819c0();

  }

  DAT_1403fcaf0 = param_1;

  if ((param_1 != 0) && (*(char *)(param_1 + 0x15) == '\0')) {

    iVar4 = 0x1e;

    *(undefined2 *)(param_1 + 0x15) = 0x101;

    do {

      uVar1 = FUN_1401829a0(param_1,iVar4,0);

      iVar2 = FUN_140190340(uVar1);

      if (iVar2 != 0) {

LAB_140183fac:

        *(undefined1 *)(param_1 + 0x16) = 0;

        break;

      }

      uVar1 = FUN_1401829a0(param_1,iVar4,3);

      iVar2 = FUN_140190340(uVar1);

      if (iVar2 == 0) goto LAB_140183fac;

      iVar4 = iVar4 + 1;

    } while (iVar4 < 0x28);

    *(undefined2 *)(param_1 + 0x17) = 0;

    iVar4 = 4;

    do {

      uVar3 = FUN_1401829a0(param_1,iVar4,0);

      if (uVar3 < 0x100) {

        *(undefined1 *)(param_1 + 0x17) = 1;

        break;

      }

      if (uVar3 - 0xe00 < 0x80) {

        *(undefined1 *)(param_1 + 0x18) = 1;

        break;

      }

      iVar4 = iVar4 + 1;

    } while (iVar4 < 8);

  }

  if (param_2 == '\0') {

    return;

  }

  FUN_14013b560();

  return;

}




