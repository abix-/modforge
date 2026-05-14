// Address: 0x140170080
// Ghidra name: FUN_140170080
// ============ 0x140170080 FUN_140170080 (size=111) ============


void FUN_140170080(longlong param_1,longlong param_2)



{

  int iVar1;

  longlong *plVar2;

  uint uVar3;

  longlong *plVar4;

  

  iVar1 = *(int *)(param_1 + 0x17c);

  uVar3 = 0;

  if (0 < iVar1) {

    plVar2 = *(longlong **)(param_1 + 0x180);

    plVar4 = plVar2;

    while (*plVar4 != param_2) {

      uVar3 = uVar3 + 1;

      plVar4 = plVar4 + 1;

      if (iVar1 <= (int)uVar3) {

        return;

      }

    }

    if ((int)uVar3 < iVar1 + -1) {

      FUN_1402f8e20(plVar2 + (int)uVar3,plVar2 + (int)(uVar3 + 1),

                    (longlong)(int)(~uVar3 + iVar1) << 3);

    }

    *(int *)(param_1 + 0x17c) = *(int *)(param_1 + 0x17c) + -1;

  }

  return;

}




