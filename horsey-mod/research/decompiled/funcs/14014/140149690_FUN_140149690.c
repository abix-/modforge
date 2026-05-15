// Address: 0x140149690
// Ghidra name: FUN_140149690
// ============ 0x140149690 FUN_140149690 (size=221) ============


undefined8 FUN_140149690(int param_1)



{

  int *piVar1;

  int iVar2;

  undefined8 uVar3;

  int *piVar4;

  int *piVar5;

  

  if (param_1 == 0) {

    uVar3 = FUN_14012e850("Parameter \'%s\' is invalid",&DAT_140331fb4);

    return uVar3;

  }

  FUN_140179b40();

  piVar4 = (int *)0x0;

  piVar5 = DAT_1403fbf70;

  piVar1 = DAT_1403fbf70;

  if (DAT_1403fbf70 == (int *)0x0) {

LAB_140149706:

    DAT_1403fbf70 = piVar1;

    FUN_140179b60(DAT_1403fbf78);

    if (piVar5 != (int *)0x0) {

      iVar2 = FUN_140138fe0(*(longlong *)(piVar5 + 2) + 0x30);

      if (iVar2 == 0) {

        FUN_140139010(*(longlong *)(piVar5 + 2) + 0x30,1);

        FUN_1401841e0(piVar5);

        return 1;

      }

      FUN_1401841e0(piVar5);

    }

  }

  else {

    do {

      piVar1 = *(int **)(piVar5 + 4);

      if (*piVar5 == param_1) {

        if (piVar4 != (int *)0x0) {

          *(int **)(piVar4 + 4) = piVar1;

          piVar1 = DAT_1403fbf70;

        }

        goto LAB_140149706;

      }

      piVar4 = piVar5;

      piVar5 = piVar1;

    } while (piVar1 != (int *)0x0);

    FUN_140179b60(DAT_1403fbf78);

  }

  uVar3 = FUN_14012e850("Timer not found");

  return uVar3;

}




