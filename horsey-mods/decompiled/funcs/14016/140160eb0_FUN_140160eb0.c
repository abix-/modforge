// Address: 0x140160eb0
// Ghidra name: FUN_140160eb0
// ============ 0x140160eb0 FUN_140160eb0 (size=209) ============


void FUN_140160eb0(longlong *param_1)



{

  longlong *plVar1;

  longlong lVar2;

  longlong *plVar3;

  longlong *plVar4;

  

  lVar2 = FUN_1401611a0();

  if ((param_1 != (longlong *)0x0) && (param_1 != *(longlong **)(lVar2 + 0x118))) {

    if (param_1 == *(longlong **)(lVar2 + 0x120)) {

      FUN_140162b40();

    }

    plVar3 = (longlong *)0x0;

    plVar4 = *(longlong **)(lVar2 + 0x110);

    if (*(longlong **)(lVar2 + 0x110) != (longlong *)0x0) {

      while (plVar4 != param_1) {

        plVar1 = plVar4 + 2;

        plVar3 = plVar4;

        plVar4 = (longlong *)*plVar1;

        if ((longlong *)*plVar1 == (longlong *)0x0) {

          return;

        }

      }

      if (plVar3 == (longlong *)0x0) {

        *(longlong *)(lVar2 + 0x110) = plVar4[2];

      }

      else {

        plVar3[2] = plVar4[2];

      }

      if (*plVar4 != 0) {

        FUN_140160e30();

      }

      if ((*(code **)(lVar2 + 0x28) != (code *)0x0) && (plVar4[1] != 0)) {

                    /* WARNING: Could not recover jumptable at 0x000140160f66. Too many branches */

                    /* WARNING: Treating indirect jump as call */

        (**(code **)(lVar2 + 0x28))(plVar4);

        return;

      }

      FUN_1401841e0(plVar4);

    }

  }

  return;

}




