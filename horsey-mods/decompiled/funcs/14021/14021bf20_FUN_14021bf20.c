// Address: 0x14021bf20
// Ghidra name: FUN_14021bf20
// ============ 0x14021bf20 FUN_14021bf20 (size=136) ============


undefined1 FUN_14021bf20(char *param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)



{

  undefined1 uVar1;

  longlong lVar2;

  size_t local_28;

  undefined8 local_20;

  undefined8 local_18;

  

  lVar2 = FUN_14021c4a0();

  uVar1 = 0;

  if (lVar2 != 0) {

    if (param_1 == (char *)0x0) {

      local_28 = 0;

    }

    else {

      local_28 = strlen(param_1);

    }

    local_20 = param_3;

    local_18 = param_4;

    uVar1 = FUN_140178a60(lVar2,FUN_14021c400,&local_28);

    FUN_1401841e0(lVar2);

  }

  return uVar1;

}




