// Address: 0x1401f8fa0
// Ghidra name: FUN_1401f8fa0
// ============ 0x1401f8fa0 FUN_1401f8fa0 (size=104) ============


void FUN_1401f8fa0(longlong param_1)



{

  longlong lVar1;

  int iVar2;

  undefined4 local_res8 [2];

  undefined4 local_res10 [2];

  

  lVar1 = *(longlong *)(param_1 + 0x2e0);

  FUN_1401fabf0(lVar1);

  FUN_1402000b0(lVar1);

  FUN_14016ebe0(*(undefined8 *)(param_1 + 0x118),local_res10,local_res8);

  iVar2 = FUN_1401f79d0(param_1,local_res10[0],local_res8[0]);

  *(undefined1 *)(lVar1 + 0x2928) = 1;

  if (iVar2 != 0) {

    *(undefined1 *)(lVar1 + 0x6e8) = 1;

  }

  return;

}




