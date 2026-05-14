// Address: 0x1401ce350
// Ghidra name: FUN_1401ce350
// ============ 0x1401ce350 FUN_1401ce350 (size=177) ============


void FUN_1401ce350(undefined8 *param_1,longlong param_2,longlong param_3)



{

  longlong *plVar1;

  longlong *plVar2;

  int iVar3;

  int iVar4;

  

  FUN_140179b40(*param_1);

  iVar3 = *(int *)(param_1 + 5);

  iVar4 = 0;

  if (0 < iVar3) {

    plVar1 = (longlong *)param_1[4];

    plVar2 = plVar1;

    do {

      if ((*plVar2 == param_2) && (plVar2[1] == param_3)) {

        if (*(char *)((longlong)param_1 + 0x2c) == '\0') {

          iVar3 = iVar3 + -1;

          *(int *)(param_1 + 5) = iVar3;

          if (iVar4 < iVar3) {

            FUN_1402f8e20(plVar1 + (longlong)iVar4 * 3,plVar1 + (longlong)(iVar4 + 1) * 3,

                          (longlong)(iVar3 - iVar4) * 0x18);

          }

        }

        else {

          *(undefined1 *)(plVar1 + (longlong)iVar4 * 3 + 2) = 1;

          *(undefined1 *)((longlong)param_1 + 0x2d) = 1;

        }

        break;

      }

      iVar4 = iVar4 + 1;

      plVar2 = plVar2 + 3;

    } while (iVar4 < iVar3);

  }

  FUN_140179b60(*param_1);

  return;

}




