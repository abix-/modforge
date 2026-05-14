// Address: 0x1401cb360
// Ghidra name: FUN_1401cb360
// ============ 0x1401cb360 FUN_1401cb360 (size=107) ============


void FUN_1401cb360(longlong param_1)



{

  undefined8 *puVar1;

  undefined8 *puVar2;

  undefined8 local_18;

  undefined8 local_10;

  

  puVar1 = (undefined8 *)FUN_1401c5690(param_1,0);

  puVar2 = (undefined8 *)FUN_1401c5690(param_1,1);

  *(undefined8 **)(param_1 + 0x1e8) = puVar2;

  *(undefined8 **)(param_1 + 0x1e0) = puVar1;

  local_18 = *puVar1;

  local_10 = *puVar2;

  (**(code **)(**(longlong **)(param_1 + 0x120) + 0xe0))

            (*(longlong **)(param_1 + 0x120),2,&local_18);

  return;

}




