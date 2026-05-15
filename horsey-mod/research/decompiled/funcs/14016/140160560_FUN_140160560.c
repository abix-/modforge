// Address: 0x140160560
// Ghidra name: FUN_140160560
// ============ 0x140160560 FUN_140160560 (size=262) ============


int * FUN_140160560(longlong param_1,int param_2,char param_3,byte param_4)



{

  int iVar1;

  int *piVar2;

  longlong lVar3;

  int *piVar4;

  int *piVar5;

  int *piVar6;

  uint uVar7;

  

  piVar6 = (int *)0x0;

  if (DAT_1403fc32c != '\0') {

    iVar1 = *(int *)(param_1 + 0x100);

    piVar5 = piVar6;

    if (0 < iVar1) {

      piVar2 = *(int **)(param_1 + 0x108);

      piVar4 = piVar6;

      do {

        piVar5 = piVar2;

        if (*piVar2 == param_2) break;

        uVar7 = (int)piVar4 + 1;

        piVar4 = (int *)(ulonglong)uVar7;

        piVar2 = piVar2 + 6;

        piVar5 = (int *)0x0;

      } while ((int)uVar7 < iVar1);

    }

    piVar2 = piVar5;

    if (param_3 == '\0') {

      if ((piVar5 != (int *)0x0) && (((uint)piVar5[1] >> (param_4 - 1 & 0x1f) & 1) != 0)) {

        return piVar5;

      }

      if (0 < iVar1) {

        piVar4 = *(int **)(param_1 + 0x108);

        do {

          piVar2 = piVar4;

          if (((uint)piVar4[1] >> (param_4 - 1 & 0x1f) & 1) != 0) break;

          uVar7 = (int)piVar6 + 1;

          piVar6 = (int *)(ulonglong)uVar7;

          piVar4 = piVar4 + 6;

          piVar2 = piVar5;

        } while ((int)uVar7 < iVar1);

      }

    }

    if (piVar2 != (int *)0x0) {

      return piVar2;

    }

    lVar3 = FUN_140184230(*(undefined8 *)(param_1 + 0x108),((longlong)iVar1 + 1) * 0x18);

    if (lVar3 != 0) {

      iVar1 = *(int *)(param_1 + 0x100);

      *(longlong *)(param_1 + 0x108) = lVar3;

      *(int *)(param_1 + 0x100) = iVar1 + 1;

      piVar6 = (int *)(lVar3 + (longlong)iVar1 * 0x18);

      piVar6[0] = 0;

      piVar6[1] = 0;

      piVar6[2] = 0;

      piVar6[3] = 0;

      piVar6[4] = 0;

      piVar6[5] = 0;

      *piVar6 = param_2;

      return piVar6;

    }

  }

  return (int *)0x0;

}




