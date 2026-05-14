// Address: 0x140101220
// Ghidra name: FUN_140101220
// ============ 0x140101220 FUN_140101220 (size=148) ============


int FUN_140101220(longlong param_1,int param_2,int param_3,char param_4)



{

  int *piVar1;

  int *piVar2;

  int iVar3;

  ulonglong uVar4;

  

  piVar1 = *(int **)(param_1 + 0x420);

  iVar3 = 0;

  uVar4 = *(longlong *)(param_1 + 0x428) - (longlong)piVar1 >> 3;

  if (uVar4 != 0) {

    piVar2 = piVar1;

    do {

      if (*piVar2 == param_3 * *(int *)(param_1 + 0x278) + param_2) {

        piVar2 = piVar1 + (longlong)iVar3 * 2;

        iVar3 = piVar1[(longlong)iVar3 * 2 + 1];

        if (param_4 != '\0') {

          FUN_1402f8e20(piVar2,piVar2 + 2,*(longlong *)(param_1 + 0x428) - (longlong)(piVar2 + 2));

          *(longlong *)(param_1 + 0x428) = *(longlong *)(param_1 + 0x428) + -8;

        }

        return iVar3;

      }

      iVar3 = iVar3 + 1;

      piVar2 = piVar2 + 2;

    } while ((ulonglong)(longlong)iVar3 < uVar4);

  }

  return -1;

}




