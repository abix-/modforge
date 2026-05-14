// Address: 0x14011e4f0
// Ghidra name: FUN_14011e4f0
// ============ 0x14011e4f0 FUN_14011e4f0 (size=53) ============


undefined8 * FUN_14011e4f0(undefined8 *param_1,undefined4 param_2)



{

  undefined8 uVar1;

  undefined8 *puVar2;

  undefined1 local_18 [16];

  

  FUN_140124b00();

  puVar2 = (undefined8 *)(*(code *)PTR_FUN_1403dce68)(local_18,param_2);

  uVar1 = puVar2[1];

  *param_1 = *puVar2;

  param_1[1] = uVar1;

  return param_1;

}




