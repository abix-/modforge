// Address: 0x1402220f0
// Ghidra name: FUN_1402220f0
// ============ 0x1402220f0 FUN_1402220f0 (size=159) ============


void FUN_1402220f0(longlong param_1)



{

  int iVar1;

  longlong *plVar2;

  longlong *plVar3;

  

  plVar2 = *(longlong **)(*(longlong *)(param_1 + 0x680) + 0x138);

  if (plVar2 != (longlong *)0x0) {

    plVar3 = (longlong *)*plVar2;

    if (plVar3 != (longlong *)0x0) {

      if (plVar2[1] != 0) {

        (**(code **)(*plVar3 + 0x68))(plVar3,plVar2[1],10000);

        plVar2[1] = 0;

      }

      iVar1 = (int)plVar2[2];

      while (0 < iVar1) {

        FUN_140221de0(plVar2,0);

        iVar1 = (int)plVar2[2];

      }

      FUN_140289330();

      *plVar2 = 0;

    }

    if (plVar2[5] != 0) {

      FUN_140179b30();

      plVar2[5] = 0;

    }

    FUN_1401841e0(plVar2);

    *(undefined8 *)(*(longlong *)(param_1 + 0x680) + 0x138) = 0;

  }

  return;

}




