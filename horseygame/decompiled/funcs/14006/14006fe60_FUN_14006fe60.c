// Address: 0x14006fe60
// Ghidra name: FUN_14006fe60
// ============ 0x14006fe60 FUN_14006fe60 (size=309) ============


ulonglong FUN_14006fe60(undefined8 param_1)



{

  longlong *plVar1;

  int iVar2;

  longlong *plVar3;

  char cVar4;

  longlong *plVar5;

  ulonglong uVar6;

  longlong *plVar7;

  undefined1 local_48 [16];

  undefined1 local_38 [32];

  int local_18;

  

  plVar3 = DAT_1403ead08;

  plVar1 = (longlong *)DAT_1403ead08[1];

  cVar4 = *(char *)((longlong)plVar1 + 0x19);

  plVar7 = DAT_1403ead08;

  while (cVar4 == '\0') {

    cVar4 = FUN_140046de0(plVar1 + 4,param_1);

    plVar5 = plVar1 + 2;

    if (cVar4 == '\0') {

      plVar5 = plVar1;

      plVar7 = plVar1;

    }

    plVar1 = (longlong *)*plVar5;

    cVar4 = *(char *)((longlong)plVar1 + 0x19);

  }

  if ((*(char *)((longlong)plVar7 + 0x19) != '\0') ||

     (cVar4 = FUN_140046de0(param_1,plVar7 + 4), cVar4 != '\0')) {

    plVar7 = plVar3;

  }

  if (plVar7 == plVar3) {

    uVar6 = (DAT_1403eace0 - DAT_1403eacd8) / 0x38;

    iVar2 = (int)uVar6;

    FUN_140075320(&DAT_1403eacd8,(longlong)(iVar2 + 1));

    *(undefined8 *)((longlong)iVar2 * 0x38 + DAT_1403eacd8) = 0;

    *(undefined4 *)((longlong)iVar2 * 0x38 + 8 + DAT_1403eacd8) = 0xffffffff;

    FUN_1400279c0(local_38,param_1);

    local_18 = iVar2;

    FUN_140074f80(&DAT_1403ead08,local_48,local_38);

    FUN_140027900(local_38);

  }

  else {

    uVar6 = (ulonglong)*(uint *)(plVar7 + 8);

  }

  FUN_140027900(param_1);

  return uVar6 & 0xffffffff;

}




