// Address: 0x1402d7420
// Ghidra name: FUN_1402d7420
// ============ 0x1402d7420 FUN_1402d7420 (size=192) ============


int FUN_1402d7420(longlong param_1,int param_2)



{

  int iVar1;

  int iVar2;

  byte *pbVar3;

  longlong lVar4;

  byte *pbVar5;

  int iVar6;

  

  lVar4 = *(longlong *)(param_1 + 8);

  if (*(char *)(lVar4 + 0x28) == '\0') {

    FUN_1402d74e0(lVar4);

  }

  pbVar5 = *(byte **)(param_1 + 0x40);

  if (*(int *)((longlong)*(longlong **)(lVar4 + 0x18) + 0xc) == 0xfde9) {

    iVar6 = 0;

    if (0 < param_2) {

      do {

        if (*pbVar5 == 0) {

          return iVar6;

        }

        iVar2 = FUN_1402f0160(pbVar5);

        lVar4 = (longlong)iVar2;

        if (3 < iVar2 - 1U) {

          lVar4 = 1;

        }

        iVar1 = iVar6 + 1;

        if (iVar2 != 4) {

          iVar1 = iVar6;

        }

        iVar6 = iVar1 + 1;

        pbVar5 = pbVar5 + lVar4;

      } while (iVar6 < param_2);

    }

  }

  else {

    iVar6 = 0;

    if (0 < param_2) {

      do {

        if (*pbVar5 == 0) {

          return iVar6;

        }

        pbVar3 = pbVar5 + 1;

        if (-1 < *(short *)(**(longlong **)(lVar4 + 0x18) + (ulonglong)*pbVar5 * 2)) {

          pbVar3 = pbVar5;

        }

        pbVar5 = pbVar3 + 1;

        iVar6 = iVar6 + 1;

      } while (iVar6 < param_2);

    }

  }

  return iVar6;

}




