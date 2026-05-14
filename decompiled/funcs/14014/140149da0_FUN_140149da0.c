// Address: 0x140149da0
// Ghidra name: FUN_140149da0
// ============ 0x140149da0 FUN_140149da0 (size=18) ============


undefined8 FUN_140149da0(longlong param_1,longlong param_2)



{

  undefined8 uVar1;

  uint7 uVar2;

  

  uVar2 = (uint7)(uint3)((uint)*(int *)(param_1 + 600) >> 8);

  if (*(int *)(param_2 + 8) != *(int *)(param_1 + 600)) {

    return CONCAT71(uVar2,1);

  }

  if (*(longlong *)(param_1 + 0x240) == 0) {

    return CONCAT71(uVar2,1);

  }

  uVar1 = (**(code **)(param_1 + 0x68))();

  if (*(longlong *)(param_1 + 0x248) != 0) {

    *(undefined8 *)(*(longlong *)(param_1 + 0x248) + 0x50) = *(undefined8 *)(param_1 + 0x250);

    *(undefined8 *)(param_1 + 0x250) = *(undefined8 *)(param_1 + 0x240);

    *(undefined8 *)(param_1 + 0x248) = 0;

    *(undefined8 *)(param_1 + 0x240) = 0;

  }

  *(int *)(param_1 + 600) = *(int *)(param_1 + 600) + 1;

  *(undefined8 *)(param_1 + 0x2a0) = 0;

  *(undefined2 *)(param_1 + 0x291) = 0;

  *(undefined1 *)(param_1 + 0x293) = 0;

  return uVar1;

}




