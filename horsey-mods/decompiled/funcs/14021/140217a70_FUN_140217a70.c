// Address: 0x140217a70
// Ghidra name: FUN_140217a70
// ============ 0x140217a70 FUN_140217a70 (size=77) ============


undefined1 FUN_140217a70(undefined8 *param_1,longlong param_2)



{

  undefined8 *puVar1;

  

  while( true ) {

    if (param_2 == 0) {

      return 1;

    }

    puVar1 = (undefined8 *)FUN_140217640(param_1);

    if (puVar1 == (undefined8 *)0x0) break;

    *puVar1 = *param_1;

    param_1[2] = param_1[2] + 1;

    *param_1 = puVar1;

    param_2 = param_2 + -1;

  }

  return 0;

}




