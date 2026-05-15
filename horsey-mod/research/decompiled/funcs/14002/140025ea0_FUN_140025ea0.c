// Address: 0x140025ea0
// Ghidra name: FUN_140025ea0
// ============ 0x140025ea0 FUN_140025ea0 (size=90) ============


void FUN_140025ea0(longlong param_1,undefined8 param_2)



{

  undefined8 *puVar1;

  undefined8 *puVar2;

  

  puVar2 = *(undefined8 **)(param_1 + 0x28);

  while (puVar2 != (undefined8 *)0x0) {

    puVar1 = (undefined8 *)puVar2[0xc];

    (**(code **)*puVar2)(puVar2,1);

    puVar2 = puVar1;

  }

  *(undefined8 *)(param_1 + 0x28) = 0;

  *(undefined8 *)(param_1 + 0x30) = 0;

  FUN_140026370(param_2,param_1);

  return;

}




