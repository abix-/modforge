// Address: 0x14013e620
// Ghidra name: FUN_14013e620
// ============ 0x14013e620 FUN_14013e620 (size=34) ============


undefined8 * FUN_14013e620(undefined8 *param_1)



{

  undefined8 uVar1;

  undefined8 *puVar2;

  undefined1 local_18 [16];

  

  puVar2 = (undefined8 *)FUN_140158250(local_18);

  uVar1 = puVar2[1];

  *param_1 = *puVar2;

  param_1[1] = uVar1;

  return param_1;

}




