// Address: 0x140215530
// Ghidra name: FUN_140215530
// ============ 0x140215530 FUN_140215530 (size=118) ============


void FUN_140215530(longlong param_1)



{

  longlong lVar1;

  int iVar2;

  undefined8 uVar3;

  undefined4 local_res10 [6];

  

  iVar2 = FUN_1401a9610();

  if (-1 < iVar2) {

    *(undefined1 *)(*(longlong *)(param_1 + 200) + 0x38) = 1;

  }

  if (DAT_1403fdab0 != (code *)0x0) {

    lVar1 = *(longlong *)(param_1 + 200);

    local_res10[0] = 0;

    uVar3 = (*DAT_1403fdab0)(L"Pro Audio",local_res10);

    *(undefined8 *)(lVar1 + 0x30) = uVar3;

    return;

  }

  thunk_FUN_140180060(3 - (uint)(*(char *)(param_1 + 0x94) != '\0'));

  return;

}




