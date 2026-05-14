// Address: 0x140131ef0
// Ghidra name: FUN_140131ef0
// ============ 0x140131ef0 FUN_140131ef0 (size=798) ============


undefined8 FUN_140131ef0(longlong param_1)



{

  int iVar1;

  longlong lVar2;

  undefined8 uVar3;

  int iVar4;

  longlong lVar5;

  ulonglong uVar6;

  longlong lVar7;

  uint uVar8;

  int iVar9;

  int iVar10;

  longlong *plVar11;

  bool bVar12;

  

  iVar9 = *(int *)(param_1 + 0x5c);

  if ((iVar9 < 1) || (iVar4 = *(int *)(param_1 + 0x60), iVar4 < 1)) {

    iVar9 = *(int *)(param_1 + 0x44);

    *(int *)(param_1 + 0x5c) = iVar9;

    iVar4 = *(int *)(param_1 + 0x48);

    *(int *)(param_1 + 0x60) = iVar4;

  }

  iVar10 = *(int *)(param_1 + 0x54);

  if (iVar10 == 0) {

    iVar10 = *(int *)(param_1 + 0x3c);

    *(int *)(param_1 + 0x54) = iVar10;

  }

  if (*(int *)(param_1 + 0x68) == 0) {

    *(undefined4 *)(param_1 + 100) = *(undefined4 *)(param_1 + 0x4c);

    *(undefined4 *)(param_1 + 0x68) = *(undefined4 *)(param_1 + 0x50);

  }

  iVar1 = *(int *)(param_1 + 0x44);

  uVar8 = 0;

  if ((iVar1 == iVar9) && (*(int *)(param_1 + 0x48) == iVar4)) {

    *(undefined4 *)(param_1 + 0x1b0) = 0;

  }

  else {

    uVar6 = (longlong)iVar1 * (longlong)*(int *)(param_1 + 0x48);

    if ((ulonglong)((longlong)iVar4 * (longlong)iVar9) < uVar6 ||

        (longlong)iVar4 * (longlong)iVar9 - uVar6 == 0) {

      *(undefined4 *)(param_1 + 0x1b0) = 0xffffffff;

    }

    else {

      *(undefined4 *)(param_1 + 0x1b0) = 1;

    }

  }

  *(bool *)(param_1 + 0x1b4) = *(int *)(param_1 + 0x3c) != iVar10;

  lVar2 = FUN_140145bc0(iVar1,*(undefined4 *)(param_1 + 0x48),*(int *)(param_1 + 0x3c),0,0);

  *(longlong *)(param_1 + 0x90) = lVar2;

  if (lVar2 == 0) {

LAB_140132124:

    if (*(longlong *)(param_1 + 0x90) != 0) {

      FUN_140146010();

      *(undefined8 *)(param_1 + 0x90) = 0;

    }

    if (*(longlong *)(param_1 + 0x98) != 0) {

      FUN_140146010();

      *(undefined8 *)(param_1 + 0x98) = 0;

    }

    if (*(longlong *)(param_1 + 0xa0) != 0) {

      FUN_140146010();

    }

    if (*(longlong *)(param_1 + 0xb8) != 0) {

      FUN_140146010();

    }

    if (*(longlong *)(param_1 + 0xd0) != 0) {

      FUN_140146010();

    }

    if (*(longlong *)(param_1 + 0xe8) != 0) {

      FUN_140146010();

    }

    if (*(longlong *)(param_1 + 0x100) != 0) {

      FUN_140146010();

    }

    if (*(longlong *)(param_1 + 0x118) != 0) {

      FUN_140146010();

    }

    if (*(longlong *)(param_1 + 0x130) != 0) {

      FUN_140146010();

    }

    if (*(longlong *)(param_1 + 0x148) != 0) {

      FUN_140146010();

    }

    FUN_1402f94c0(param_1 + 0xa0,0,0xc0);

    uVar3 = 0;

  }

  else {

    FUN_1401487a0(lVar2,*(undefined4 *)(param_1 + 0x40));

    iVar9 = *(int *)(param_1 + 0x1b0);

    if ((iVar9 != 0) && (*(char *)(param_1 + 0x1b4) != '\0')) {

      bVar12 = -1 < iVar9;

      lVar2 = 0x3c;

      if (bVar12) {

        lVar2 = 0x54;

      }

      lVar7 = 0x48;

      if (!bVar12) {

        lVar7 = 0x60;

      }

      lVar5 = 0x44;

      if (!bVar12) {

        lVar5 = 0x5c;

      }

      lVar2 = FUN_140145e60(*(undefined4 *)(lVar5 + param_1),*(undefined4 *)(lVar7 + param_1),

                            *(undefined4 *)(lVar2 + param_1));

      *(longlong *)(param_1 + 0x98) = lVar2;

      if (lVar2 == 0) goto LAB_140132124;

      FUN_1401487a0(lVar2,*(undefined4 *)(param_1 + 0x40));

    }

    *(longlong *)(param_1 + 0xb0) = param_1 + 0xb8;

    plVar11 = (longlong *)(param_1 + 0xa0);

    *(longlong *)(param_1 + 200) = param_1 + 0xd0;

    *(longlong *)(param_1 + 0xe0) = param_1 + 0xe8;

    *(longlong *)(param_1 + 0xf8) = param_1 + 0x100;

    *(longlong *)(param_1 + 0x110) = param_1 + 0x118;

    *(longlong *)(param_1 + 0x128) = param_1 + 0x130;

    *(longlong *)(param_1 + 0x140) = param_1 + 0x148;

    *(longlong **)(param_1 + 0x188) = plVar11;

    do {

      if ((*(int *)(param_1 + 0x1b0) == 0) && (*(char *)(param_1 + 0x1b4) == '\0')) {

        lVar2 = FUN_140145bc0(*(undefined4 *)(param_1 + 0x5c),*(undefined4 *)(param_1 + 0x60),

                              *(undefined4 *)(param_1 + 0x54),0,0);

      }

      else {

        lVar2 = FUN_140145e60(*(undefined4 *)(param_1 + 0x5c),*(undefined4 *)(param_1 + 0x60),

                              *(undefined4 *)(param_1 + 0x54));

      }

      if (lVar2 == 0) goto LAB_140132124;

      FUN_1401487a0(lVar2,*(undefined4 *)(param_1 + 0x40));

      *plVar11 = lVar2;

      uVar8 = uVar8 + 1;

      plVar11 = plVar11 + 3;

    } while (uVar8 < 8);

    uVar3 = 1;

  }

  return uVar3;

}




