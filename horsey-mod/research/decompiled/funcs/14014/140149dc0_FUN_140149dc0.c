// Address: 0x140149dc0
// Ghidra name: FUN_140149dc0
// ============ 0x140149dc0 FUN_140149dc0 (size=29) ============


undefined8 FUN_140149dc0(longlong param_1)



{

  int iVar1;

  undefined8 uVar2;

  

  iVar1 = *(int *)(*(longlong *)(param_1 + 0x10) + 600);

  if (*(int *)(param_1 + 0x130) == iVar1) {

    uVar2 = FUN_140149cf0(*(longlong *)(param_1 + 0x10));

    return uVar2;

  }

  return CONCAT71((uint7)(uint3)((uint)iVar1 >> 8),1);

}




