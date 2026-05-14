// Address: 0x140278840
// Ghidra name: FUN_140278840
// ============ 0x140278840 FUN_140278840 (size=230) ============


void FUN_140278840(longlong param_1,undefined8 param_2,longlong param_3)



{

  int iVar1;

  

  iVar1 = *(int *)(param_1 + 0x1c);

  if (iVar1 == 0x83) {

    FUN_140279480();

    return;

  }

  if ((*(char *)(param_1 + 0x2a) != '\0') && (5 < *(byte *)(param_3 + 0x1c))) {

    if ((*(byte *)(param_3 + 10) & 1) != 0) {

      return;

    }

    if ((*(byte *)(param_3 + 9) & 1) == 0) {

      if (iVar1 != 0x80) goto LAB_1402788a5;

    }

    else if (iVar1 == 0x80) {

LAB_1402788a5:

      *(undefined1 *)(param_1 + 0x60) = 1;

    }

    if ((*(byte *)(param_3 + 10) & 2) != 0) {

      FUN_140278dc0();

      *(undefined1 *)(param_3 + 0x1c) = 0;

    }

  }

  FUN_140279400(param_1,param_2,param_3);

  iVar1 = *(int *)(param_1 + 0x1c);

  if (iVar1 != 0x80) {

    if (iVar1 != 0x81) {

      if (iVar1 == 0x82) {

        FUN_140278b50(param_1,param_2,param_3);

      }

      goto LAB_140278908;

    }

    FUN_140278f30(param_1,param_2,param_3);

  }

  FUN_140279440(param_1,param_2,param_3);

LAB_140278908:

  FUN_140279310(param_1,param_2,param_3);

  return;

}




