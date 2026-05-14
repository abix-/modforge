// Address: 0x1400a30c0
// Ghidra name: FUN_1400a30c0
// ============ 0x1400a30c0 FUN_1400a30c0 (size=304) ============


void FUN_1400a30c0(undefined8 param_1,undefined8 *param_2)



{

  longlong *plVar1;

  longlong *plVar2;

  char cVar3;

  longlong *plVar4;

  longlong *plVar5;

  longlong lVar6;

  

  plVar2 = DAT_1403f2fb0;

  plVar1 = (longlong *)DAT_1403f2fb0[1];

  cVar3 = *(char *)((longlong)plVar1 + 0x19);

  plVar5 = DAT_1403f2fb0;

  while (cVar3 == '\0') {

    cVar3 = FUN_140046de0(plVar1 + 4,param_2);

    plVar4 = plVar1 + 2;

    if (cVar3 == '\0') {

      plVar4 = plVar1;

      plVar5 = plVar1;

    }

    plVar1 = (longlong *)*plVar4;

    cVar3 = *(char *)((longlong)plVar1 + 0x19);

  }

  if ((*(char *)((longlong)plVar5 + 0x19) != '\0') ||

     (cVar3 = FUN_140046de0(param_2,plVar5 + 4), cVar3 != '\0')) {

    plVar5 = plVar2;

  }

  if (plVar5 == plVar2) {

    if (0xf < (ulonglong)param_2[3]) {

      param_2 = (undefined8 *)*param_2;

    }

    FUN_1400c4340("pop not found %s",param_2);

  }

  else {

    lVar6 = 0xf0;

    do {

      lVar6 = lVar6 + -1;

    } while (lVar6 != 0);

  }

  return;

}




