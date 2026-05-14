// Address: 0x140117480
// Ghidra name: FUN_140117480
// ============ 0x140117480 FUN_140117480 (size=55) ============


undefined8 * FUN_140117480(undefined8 *param_1,undefined8 param_2)



{

  undefined8 uVar1;

  undefined8 *puVar2;

  undefined1 local_18 [16];

  

  FUN_140124b00();

  puVar2 = (undefined8 *)(*(code *)PTR_FUN_1403de140)(local_18,param_2);

  uVar1 = puVar2[1];

  *param_1 = *puVar2;

  param_1[1] = uVar1;

  return param_1;

}




