// Address: 0x140283640
// Ghidra name: FUN_140283640
// ============ 0x140283640 FUN_140283640 (size=116) ============


undefined1 FUN_140283640(longlong param_1,longlong param_2)



{

  undefined8 *puVar1;

  

  puVar1 = *(undefined8 **)(param_1 + 0x70);

  _guard_check_icall();

  *puVar1 = 0;

  puVar1[1] = 0;

  puVar1[2] = 0;

  puVar1[3] = 0;

  puVar1[4] = 0;

  puVar1[5] = 0;

  puVar1[6] = 0;

  puVar1[7] = 0;

  *(undefined4 *)(param_2 + 0x70) = 0xb;

  *(undefined4 *)(param_2 + 0x44) = 6;

  *(undefined4 *)(param_2 + 0x60) = 1;

  if (*(char *)(puVar1 + 8) != '\0') {

    FUN_14015a190(param_2,2,*(undefined4 *)(puVar1 + 10));

    FUN_14015a190(param_2,1,*(undefined4 *)(puVar1 + 10));

  }

  return 1;

}




