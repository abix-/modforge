// Address: 0x140200340
// Ghidra name: FUN_140200340
// ============ 0x140200340 FUN_140200340 (size=42) ============


undefined1 FUN_140200340(undefined8 param_1,longlong param_2)



{

  longlong lVar1;

  

  lVar1 = FUN_14017a030(0x100);

  if (lVar1 == 0) {

    return 0;

  }

  *(longlong *)(param_2 + 0x10) = lVar1;

  return 1;

}




