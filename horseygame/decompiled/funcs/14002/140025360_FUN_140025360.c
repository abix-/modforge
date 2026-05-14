// Address: 0x140025360
// Ghidra name: FUN_140025360
// ============ 0x140025360 FUN_140025360 (size=231) ============


undefined8 FUN_140025360(longlong param_1,longlong param_2)



{

  char cVar1;

  longlong lVar2;

  longlong *plVar3;

  undefined8 uVar4;

  longlong *plVar5;

  longlong lVar6;

  

  plVar5 = *(longlong **)(param_1 + 0x28);

  do {

    if (plVar5 == (longlong *)0x0) {

      return 0;

    }

    plVar3 = plVar5 + 7;

    if (0xf < (ulonglong)plVar5[10]) {

      plVar3 = (longlong *)*plVar3;

    }

    lVar6 = param_2 - (longlong)plVar3;

    do {

      lVar2 = *plVar3;

      cVar1 = *(char *)((longlong)plVar3 + lVar6);

      if ((char)lVar2 != cVar1) break;

      plVar3 = (longlong *)((longlong)plVar3 + 1);

    } while (cVar1 != '\0');

    if ((char)lVar2 == cVar1) {

      if (plVar5 == (longlong *)0x0) {

        return 0;

      }

      break;

    }

    plVar5 = (longlong *)plVar5[0xc];

  } while( true );

LAB_1400253c6:

  lVar6 = (**(code **)(*plVar5 + 0x30))(plVar5);

  if (lVar6 != 0) {

                    /* WARNING: Could not recover jumptable at 0x000140025443. Too many branches */

                    /* WARNING: Treating indirect jump as call */

    uVar4 = (**(code **)(*plVar5 + 0x30))(plVar5);

    return uVar4;

  }

  plVar5 = (longlong *)plVar5[0xc];

  if (plVar5 == (longlong *)0x0) {

    return 0;

  }

  do {

    plVar3 = plVar5 + 7;

    if (0xf < (ulonglong)plVar5[10]) {

      plVar3 = (longlong *)*plVar3;

    }

    lVar6 = param_2 - (longlong)plVar3;

    do {

      lVar2 = *plVar3;

      cVar1 = *(char *)((longlong)plVar3 + lVar6);

      if ((char)lVar2 != cVar1) break;

      plVar3 = (longlong *)((longlong)plVar3 + 1);

    } while (cVar1 != '\0');

    if ((char)lVar2 == cVar1) break;

    plVar5 = (longlong *)plVar5[0xc];

    if (plVar5 == (longlong *)0x0) {

      return 0;

    }

  } while( true );

  if (plVar5 == (longlong *)0x0) {

    return 0;

  }

  goto LAB_1400253c6;

}




