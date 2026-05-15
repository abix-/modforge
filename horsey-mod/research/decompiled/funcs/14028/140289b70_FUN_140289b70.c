// Address: 0x140289b70
// Ghidra name: FUN_140289b70
// ============ 0x140289b70 FUN_140289b70 (size=62) ============


void FUN_140289b70(longlong param_1)



{

  undefined8 *puVar1;

  

  if ((param_1 != 0) && (puVar1 = *(undefined8 **)(param_1 + 0x58), puVar1 != (undefined8 *)0x0)) {

    FUN_1401841e0(*puVar1);

    FUN_1401841e0(puVar1);

    *(undefined8 *)(param_1 + 0x58) = 0;

  }

  return;

}




