// Address: 0x1402c8f30
// Ghidra name: FUN_1402c8f30
// ============ 0x1402c8f30 FUN_1402c8f30 (size=200) ============


void FUN_1402c8f30(longlong param_1,undefined8 param_2,undefined8 param_3,longlong param_4)



{

  undefined8 uVar1;

  longlong lVar2;

  undefined8 local_res8;

  ulonglong in_stack_ffffffffffffffb8;

  undefined1 local_28 [4];

  undefined8 local_24;

  undefined8 local_1c;

  undefined4 local_14;

  

  uVar1 = *(undefined8 *)(param_4 + 8);

  local_28[0] = 0;

  local_24 = 0;

  local_1c = 0;

  local_14 = 0;

  local_res8 = param_2;

  lVar2 = FUN_1402c97f8();

  *(undefined8 *)(lVar2 + 0x60) = uVar1;

  uVar1 = *(undefined8 *)(param_1 + 0x38);

  lVar2 = FUN_1402c97f8();

  *(undefined8 *)(lVar2 + 0x68) = uVar1;

  lVar2 = FUN_1402c97f8();

  FUN_1402c83f4((ulonglong)**(uint **)(param_4 + 0x38) + *(longlong *)(lVar2 + 0x60),local_28,

                *(undefined8 *)(param_4 + 8),**(undefined4 **)(param_4 + 0x10),

                in_stack_ffffffffffffffb8 & 0xffffffffffffff00);

  FUN_1402cb9c4(param_1,&local_res8,param_3,param_4,local_28,0,0,0);

  return;

}




