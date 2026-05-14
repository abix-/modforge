// Address: 0x1400a3640
// Ghidra name: FUN_1400a3640
// ============ 0x1400a3640 FUN_1400a3640 (size=150) ============


undefined4 FUN_1400a3640(undefined8 param_1)



{

  longlong *plVar1;

  longlong *plVar2;

  char cVar3;

  undefined4 uVar4;

  longlong *plVar5;

  longlong *plVar6;

  

  plVar2 = DAT_1403f2fd8;

  plVar1 = (longlong *)DAT_1403f2fd8[1];

  cVar3 = *(char *)((longlong)plVar1 + 0x19);

  plVar6 = DAT_1403f2fd8;

  while (cVar3 == '\0') {

    cVar3 = FUN_140046de0(plVar1 + 4,param_1);

    plVar5 = plVar1 + 2;

    if (cVar3 == '\0') {

      plVar5 = plVar1;

      plVar6 = plVar1;

    }

    plVar1 = (longlong *)*plVar5;

    cVar3 = *(char *)((longlong)plVar1 + 0x19);

  }

  if ((*(char *)((longlong)plVar6 + 0x19) != '\0') ||

     (cVar3 = FUN_140046de0(param_1,plVar6 + 4), cVar3 != '\0')) {

    plVar6 = plVar2;

  }

  if (plVar6 == plVar2) {

    uVar4 = 0xffffffff;

  }

  else {

    uVar4 = (undefined4)plVar6[8];

  }

  return uVar4;

}




