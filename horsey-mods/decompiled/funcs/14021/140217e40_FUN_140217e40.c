// Address: 0x140217e40
// Ghidra name: FUN_140217e40
// ============ 0x140217e40 FUN_140217e40 (size=106) ============


void FUN_140217e40(longlong *param_1)



{

  char cVar1;

  longlong lVar2;

  longlong lVar3;

  

  cVar1 = *(char *)(*param_1 + 0x18);

  lVar2 = *(longlong *)(*param_1 + 0x20);

  FUN_140217700();

  while (cVar1 == '\0') {

    cVar1 = *(char *)(lVar2 + 0x18);

    lVar3 = *(longlong *)(lVar2 + 0x20);

    FUN_140217700(param_1,lVar2);

    lVar2 = lVar3;

  }

  *param_1 = lVar2;

  param_1[3] = 0;

  if (lVar2 == 0) {

    param_1[1] = 0;

  }

  return;

}




