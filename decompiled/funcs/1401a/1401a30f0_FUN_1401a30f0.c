// Address: 0x1401a30f0
// Ghidra name: FUN_1401a30f0
// ============ 0x1401a30f0 FUN_1401a30f0 (size=237) ============


undefined8 FUN_1401a30f0(longlong param_1,int param_2)



{

  uint uVar1;

  int iVar2;

  uint uVar3;

  

  if ((param_2 != 0) && (iVar2 = FUN_1401a31e0(), iVar2 == 0)) {

    return 0;

  }

  *(undefined8 *)(param_1 + 0x10) = 0;

  *(undefined4 *)(param_1 + 0x18) = 0;

  do {

    if (*(int *)(param_1 + 0x10) < 1) {

      FUN_14019f170(param_1);

    }

    uVar1 = *(uint *)(param_1 + 0x18);

    *(int *)(param_1 + 0x10) = *(int *)(param_1 + 0x10) + -1;

    *(uint *)(param_1 + 0x18) = uVar1 >> 1;

    if (*(int *)(param_1 + 0x10) < 2) {

      FUN_14019f170(param_1);

    }

    uVar3 = *(uint *)(param_1 + 0x18);

    *(int *)(param_1 + 0x10) = *(int *)(param_1 + 0x10) + -2;

    *(uint *)(param_1 + 0x18) = uVar3 >> 2;

    uVar3 = uVar3 & 3;

    if (uVar3 == 0) {

      iVar2 = FUN_1401a2fa0(param_1);

    }

    else {

      if (uVar3 == 3) {

        return 0;

      }

      if (uVar3 == 1) {

        iVar2 = FUN_1401a4e00(param_1 + 0x3c,&DAT_14033b1d0,0x120);

        if (iVar2 == 0) {

          return 0;

        }

        iVar2 = FUN_1401a4e00(param_1 + 0x820,&DAT_14033b2f0,0x20);

      }

      else {

        iVar2 = FUN_14019cde0(param_1);

      }

      if (iVar2 == 0) {

        return 0;

      }

      iVar2 = FUN_1401a22f0(param_1);

    }

    if (iVar2 == 0) {

      return 0;

    }

  } while ((uVar1 & 1) == 0);

  return 1;

}




