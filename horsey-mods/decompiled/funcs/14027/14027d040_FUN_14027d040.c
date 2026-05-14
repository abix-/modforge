// Address: 0x14027d040
// Ghidra name: FUN_14027d040
// ============ 0x14027d040 FUN_14027d040 (size=165) ============


undefined8 FUN_14027d040(undefined8 param_1,undefined8 param_2,longlong param_3,uint param_4)



{

  char cVar1;

  int iVar2;

  undefined1 local_18 [3];

  int local_15;

  

  while( true ) {

    if ((int)param_4 < 4) {

      return 1;

    }

    iVar2 = FUN_14027ce60(local_18,param_3,param_4);

    if (param_4 < (uint)(local_15 + iVar2)) {

      local_15 = param_4 - iVar2;

    }

    cVar1 = FUN_14027d0f0(param_1,param_2,local_18,param_3 + iVar2);

    if (cVar1 == '\0') break;

    param_3 = param_3 + (ulonglong)(uint)(local_15 + iVar2);

    param_4 = param_4 - (local_15 + iVar2);

  }

  return 0;

}




