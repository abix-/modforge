// Address: 0x1400c78c0
// Ghidra name: FUN_1400c78c0
// ============ 0x1400c78c0 FUN_1400c78c0 (size=65) ============


undefined8 * FUN_1400c78c0(int param_1)



{

  undefined8 *puVar1;

  

  if ((param_1 == -1) ||

     (puVar1 = (undefined8 *)(DAT_1403f34e0 + (longlong)param_1 * 0x88),

     *(char *)(puVar1 + 8) != '\0')) {

    puVar1 = (undefined8 *)&DAT_14030e15c;

  }

  else {

    if (puVar1[2] == 0) {

      return (undefined8 *)&DAT_14030e160;

    }

    if (0xf < (ulonglong)puVar1[3]) {

      return (undefined8 *)*puVar1;

    }

  }

  return puVar1;

}




