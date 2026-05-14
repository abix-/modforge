// Address: 0x14028ae80
// Ghidra name: FUN_14028ae80
// ============ 0x14028ae80 FUN_14028ae80 (size=77) ============


undefined8 FUN_14028ae80(longlong param_1)



{

  char cVar1;

  

  cVar1 = *(char *)(param_1 + 0xa70);

  while (cVar1 == '\0') {

    FUN_140179b40(*(undefined8 *)(param_1 + 0xb80));

    FUN_14028b540(param_1);

    FUN_140179b60(*(undefined8 *)(param_1 + 0xb80));

    FUN_1401492f0(2);

    cVar1 = *(char *)(param_1 + 0xa70);

  }

  return 0;

}




