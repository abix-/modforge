// Address: 0x140275340
// Ghidra name: FUN_140275340
// ============ 0x140275340 FUN_140275340 (size=129) ============


void FUN_140275340(longlong param_1)



{

  int iVar1;

  undefined1 *puVar2;

  undefined4 local_res10;

  undefined1 local_res14;

  

  puVar2 = (undefined1 *)FUN_1401841a0(1,0x41);

  if (puVar2 == (undefined1 *)0x0) {

    return;

  }

  *(undefined1 **)(param_1 + 0x70) = puVar2;

  local_res10 = 5;

  local_res14 = 0;

  iVar1 = FUN_140195730(*(undefined8 *)(param_1 + 0x80),&local_res10,5);

  if (-1 < iVar1) {

    *puVar2 = 1;

  }

  FUN_1402083c0(param_1,"Google Stadia Controller");

  FUN_140208110(param_1,0);

  return;

}




