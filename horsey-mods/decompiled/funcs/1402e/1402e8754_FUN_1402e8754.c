// Address: 0x1402e8754
// Ghidra name: FUN_1402e8754
// ============ 0x1402e8754 FUN_1402e8754 (size=91) ============


PVOID FUN_1402e8754(undefined8 param_1,longlong param_2)



{

  PVOID pvVar1;

  PVOID pvVar2;

  

  pvVar2 = (PVOID)0x0;

  pvVar1 = pvVar2;

  if (DAT_1403e8d20 != 0xffffffff) {

    pvVar1 = FlsGetValue(DAT_1403e8d20);

  }

  if ((pvVar1 != (PVOID)0xffffffffffffffff) &&

     ((pvVar1 != (PVOID)0x0 || (pvVar1 = (PVOID)FUN_1402e8544(), pvVar1 != (PVOID)0x0)))) {

    pvVar2 = (PVOID)(param_2 * 0x3c8 + (longlong)pvVar1);

  }

  return pvVar2;

}




