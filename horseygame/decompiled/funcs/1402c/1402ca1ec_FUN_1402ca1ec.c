// Address: 0x1402ca1ec
// Ghidra name: FUN_1402ca1ec
// ============ 0x1402ca1ec FUN_1402ca1ec (size=214) ============


void FUN_1402ca1ec(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,

                  undefined8 param_5,longlong param_6,longlong param_7,undefined4 *param_8)



{

  int iVar1;

  undefined4 uVar2;

  undefined4 uVar3;

  undefined8 uVar4;

  longlong lVar5;

  undefined1 local_res10 [8];

  undefined8 local_res18;

  undefined1 in_stack_00000060;

  

  local_res18 = param_3;

  uVar4 = FUN_1402c86d4(param_2,param_4,param_5,local_res10);

  if (param_7 != 0) {

    FUN_1402ca050(param_1,uVar4,param_6);

  }

  iVar1 = *(int *)(param_6 + 0x10);

  uVar2 = param_8[2];

  uVar3 = *param_8;

  lVar5 = FUN_1402c8e50();

  FUN_1402c8ab4(param_2,param_1,local_res18,uVar4,lVar5 + iVar1,param_5,uVar3,uVar2,param_6,param_4,

                in_stack_00000060);

  return;

}




