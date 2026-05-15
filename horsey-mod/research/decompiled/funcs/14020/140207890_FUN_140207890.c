// Address: 0x140207890
// Ghidra name: FUN_140207890
// ============ 0x140207890 FUN_140207890 (size=131) ============


undefined8 FUN_140207890(longlong param_1,int param_2)



{

  int iVar1;

  int *piVar2;

  int iVar3;

  int iVar4;

  int *piVar5;

  

  iVar1 = *(int *)(param_1 + 0x8c);

  if (0 < iVar1) {

    piVar2 = *(int **)(param_1 + 0x90);

    piVar5 = piVar2;

    iVar3 = 0;

    do {

      iVar4 = iVar3 + 1;

      if (*piVar5 == param_2) {

        FUN_1402f8e20(piVar2 + iVar3,piVar2 + iVar4,(longlong)((iVar1 - iVar3) * 4 + -4));

        piVar2 = (int *)(param_1 + 0x8c);

        *piVar2 = *piVar2 + -1;

        if (*piVar2 == 0) {

          FUN_1401841e0(*(undefined8 *)(param_1 + 0x90));

          *(undefined8 *)(param_1 + 0x90) = 0;

        }

        return 1;

      }

      piVar5 = piVar5 + 1;

      iVar3 = iVar4;

    } while (iVar4 < iVar1);

  }

  return 0;

}




