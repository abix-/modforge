// Address: 0x1401537c0
// Ghidra name: FUN_1401537c0
// ============ 0x1401537c0 FUN_1401537c0 (size=253) ============


undefined8 FUN_1401537c0(undefined8 *param_1,int *param_2)



{

  int iVar1;

  undefined8 uVar2;

  int iVar3;

  ulonglong uVar4;

  

  uVar2 = param_1[0x23];

  iVar1 = param_2[4];

  iVar3 = FUN_14016e2d0(uVar2);

  if (iVar1 != iVar3) {

    return 1;

  }

  if ((code *)*param_1 != (code *)0x0) {

    (*(code *)*param_1)(param_1,param_2);

  }

  iVar1 = *param_2;

  if ((iVar1 == 0x206) || (iVar1 - 0x207U < 2)) {

    uVar2 = param_1[0x27];

    param_1[0x27] = param_1 + 0x28;

    FUN_140156960(param_1);

    param_1[0x27] = uVar2;

    return 1;

  }

  if (iVar1 == 0x203) {

LAB_140153879:

    *(undefined1 *)(param_1 + 0x24) = 1;

  }

  else {

    if (iVar1 == 0x202) {

      uVar4 = FUN_14016e130(uVar2);

      uVar4 = uVar4 & 0x40;

    }

    else {

      if (iVar1 == 0x209) goto LAB_140153879;

      if (1 < iVar1 - 0x20aU) {

        if ((iVar1 != 0x213) && (iVar1 != 0x21a)) {

          return 1;

        }

        FUN_140156860(param_1);

        return 1;

      }

      uVar4 = FUN_14016e130(uVar2);

      uVar4 = uVar4 & 8;

    }

    if (uVar4 == 0) {

      *(undefined1 *)(param_1 + 0x24) = 0;

    }

  }

  return 1;

}




