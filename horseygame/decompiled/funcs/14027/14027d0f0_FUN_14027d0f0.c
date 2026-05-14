// Address: 0x14027d0f0
// Ghidra name: FUN_14027d0f0
// ============ 0x14027d0f0 FUN_14027d0f0 (size=154) ============


ulonglong FUN_14027d0f0(undefined8 param_1,longlong param_2,longlong param_3,undefined8 param_4)



{

  ulonglong uVar1;

  

  if ((*(byte *)(param_3 + 1) & 0x40) == 0) {

LAB_14027d137:

    if ((*(byte *)(param_3 + 1) & 0x10) != 0) {

      uVar1 = FUN_140018e60(param_2,param_3);

      if ((char)uVar1 == '\0') goto LAB_14027d14c;

    }

    if (*(char *)(param_3 + 1) < '\0') {

      uVar1 = FUN_14027d190();

    }

    else {

      uVar1 = FUN_14027cf20(param_1,param_2,param_3,param_4,*(undefined4 *)(param_3 + 3));

    }

  }

  else {

    uVar1 = FUN_14027ce10(param_2,*(undefined4 *)(param_3 + 7));

    if ((char)uVar1 != '\0') {

      *(undefined4 *)(param_2 + 0xa8) = *(undefined4 *)(param_3 + 7);

      *(undefined4 *)(param_3 + 7) = 0;

      goto LAB_14027d137;

    }

LAB_14027d14c:

    uVar1 = uVar1 & 0xffffffffffffff00;

  }

  return uVar1;

}




