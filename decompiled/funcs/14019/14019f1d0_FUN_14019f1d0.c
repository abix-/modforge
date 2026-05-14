// Address: 0x14019f1d0
// Ghidra name: FUN_14019f1d0
// ============ 0x14019f1d0 FUN_14019f1d0 (size=132) ============


undefined4 FUN_14019f1d0(longlong param_1,uint param_2,undefined4 param_3)



{

  longlong *plVar1;

  ulonglong uVar2;

  

  if (0 < (int)param_2) {

    plVar1 = (longlong *)(param_1 + 0x46d8);

    uVar2 = (ulonglong)param_2;

    do {

      if (*plVar1 != 0) {

        FUN_1401841e0();

        *plVar1 = 0;

        plVar1[-1] = 0;

      }

      if (plVar1[1] != 0) {

        FUN_1401841e0();

        plVar1[1] = 0;

        plVar1[3] = 0;

      }

      if (plVar1[2] != 0) {

        FUN_1401841e0();

        plVar1[2] = 0;

      }

      plVar1 = plVar1 + 0xc;

      uVar2 = uVar2 - 1;

    } while (uVar2 != 0);

  }

  return param_3;

}




