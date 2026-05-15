// Address: 0x14013e580
// Ghidra name: FUN_14013e580
// ============ 0x14013e580 FUN_14013e580 (size=85) ============


undefined8 * FUN_14013e580(int param_1)



{

  undefined8 *puVar1;

  

  FUN_140159d30();

  puVar1 = DAT_1403fbef8;

  while( true ) {

    if (puVar1 == (undefined8 *)0x0) {

      FUN_14015bb10();

      return (undefined8 *)0x0;

    }

    if (*(int *)*puVar1 == param_1) break;

    puVar1 = (undefined8 *)puVar1[10];

  }

  FUN_14015bb10();

  return puVar1;

}




