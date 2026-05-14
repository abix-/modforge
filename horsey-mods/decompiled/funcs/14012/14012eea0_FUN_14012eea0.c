// Address: 0x14012eea0
// Ghidra name: FUN_14012eea0
// ============ 0x14012eea0 FUN_14012eea0 (size=37) ============


undefined1 * FUN_14012eea0(longlong param_1,undefined1 *param_2)



{

  undefined1 *puVar1;

  

  puVar1 = param_2;

  if (param_1 < 0) {

    param_1 = -param_1;

    *param_2 = 0x2d;

    puVar1 = param_2 + 1;

  }

  FUN_14012f580(param_1,puVar1);

  return param_2;

}




