// Address: 0x140278330
// Ghidra name: FUN_140278330
// ============ 0x140278330 FUN_140278330 (size=84) ============


undefined1 FUN_140278330(longlong param_1,undefined8 param_2,short param_3,short param_4)



{

  longlong lVar1;

  char cVar2;

  undefined1 local_res18;

  char local_res19;

  

  lVar1 = *(longlong *)(param_1 + 0x70);

  if ((param_3 == 0) && (param_4 == 0)) {

    cVar2 = '\0';

  }

  else {

    cVar2 = '\x01';

  }

  if (cVar2 != *(char *)(lVar1 + 0x28)) {

    local_res18 = 0x10;

    local_res19 = cVar2;

    FUN_140279fc0(lVar1,&local_res18,2,0);

    *(char *)(lVar1 + 0x28) = cVar2;

  }

  return 1;

}




