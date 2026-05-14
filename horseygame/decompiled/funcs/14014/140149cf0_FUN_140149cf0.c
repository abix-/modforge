// Address: 0x140149cf0
// Ghidra name: FUN_140149cf0
// ============ 0x140149cf0 FUN_140149cf0 (size=137) ============


undefined8 FUN_140149cf0(longlong param_1)



{

  undefined8 uVar1;

  

  if (*(longlong *)(param_1 + 0x240) == 0) {

    return 1;

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




