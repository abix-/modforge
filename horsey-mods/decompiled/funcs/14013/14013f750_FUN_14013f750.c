// Address: 0x14013f750
// Ghidra name: FUN_14013f750
// ============ 0x14013f750 FUN_14013f750 (size=411) ============


longlong * FUN_14013f750(int param_1)



{

  longlong lVar1;

  longlong *plVar2;

  longlong lVar3;

  

  FUN_140159d30();

  for (plVar2 = DAT_1403fbef8; plVar2 != (longlong *)0x0; plVar2 = (longlong *)plVar2[10]) {

    if (param_1 == *(int *)*plVar2) {

      *(int *)(plVar2 + 1) = (int)plVar2[1] + 1;

      FUN_14015bb10();

      return plVar2;

    }

  }

  lVar1 = FUN_140140710(param_1,1);

  if (lVar1 == 0) {

    FUN_14012e850("Couldn\'t find mapping for device (%u)",param_1);

    FUN_14015bb10();

    return (longlong *)0x0;

  }

  plVar2 = (longlong *)FUN_1401841a0(1,0x58);

  if (plVar2 == (longlong *)0x0) goto LAB_14013f89c;

  FUN_1401aa9d0(plVar2,5,1);

  lVar3 = FUN_140159d70(param_1);

  *plVar2 = lVar3;

  if (lVar3 == 0) {

    FUN_1401aa9d0(plVar2,5,0);

  }

  else {

    if (*(int *)(lVar3 + 0x44) != 0) {

      lVar3 = FUN_1401841a0((longlong)*(int *)(lVar3 + 0x44),8);

      plVar2[7] = lVar3;

      if (lVar3 == 0) {

        FUN_1401aa9d0(plVar2,5,0);

        FUN_1401575b0(*plVar2);

        goto LAB_14013f894;

      }

    }

    if (*(int *)(*plVar2 + 0x60) == 0) {

LAB_14013f8b3:

      FUN_140140b10(plVar2,lVar1);

      *(int *)(plVar2 + 1) = (int)plVar2[1] + 1;

      plVar2[10] = (longlong)DAT_1403fbef8;

      DAT_1403fbef8 = plVar2;

      FUN_14015bb10();

      return plVar2;

    }

    lVar3 = FUN_1401841a0((longlong)*(int *)(*plVar2 + 0x60),1);

    plVar2[8] = lVar3;

    if (lVar3 != 0) goto LAB_14013f8b3;

    FUN_1401aa9d0(plVar2,5,0);

    FUN_1401575b0(*plVar2);

    FUN_1401841e0(plVar2[7]);

  }

LAB_14013f894:

  FUN_1401841e0(plVar2);

LAB_14013f89c:

  FUN_14015bb10();

  return (longlong *)0x0;

}




