// Address: 0x140149d80
// Ghidra name: FUN_140149d80
// ============ 0x140149d80 FUN_140149d80 (size=25) ============


undefined8 FUN_140149d80(longlong *param_1)



{

  int iVar1;

  undefined8 uVar2;

  

  iVar1 = *(int *)(*param_1 + 600);

  if ((int)param_1[1] == iVar1) {

    uVar2 = FUN_140149cf0(*param_1);

    return uVar2;

  }

  return CONCAT71((uint7)(uint3)((uint)iVar1 >> 8),1);

}




