// Address: 0x1402720b0
// Ghidra name: FUN_1402720b0
// ============ 0x1402720b0 FUN_1402720b0 (size=104) ============


bool FUN_1402720b0(longlong param_1,int param_2)



{

  undefined4 uVar1;

  int iVar2;

  longlong lVar3;

  undefined1 local_res10 [24];

  

  lVar3 = (longlong)param_2;

  local_res10[0] = 0xa1;

  uVar1 = FUN_1401917b0(0,local_res10,1);

  iVar2 = FUN_1401917b0(uVar1,param_1,lVar3 + -4);

  return iVar2 == CONCAT31(CONCAT21(CONCAT11(*(undefined1 *)(lVar3 + -1 + param_1),

                                             *(undefined1 *)(lVar3 + -2 + param_1)),

                                    *(undefined1 *)(lVar3 + -3 + param_1)),

                           *(undefined1 *)(lVar3 + -4 + param_1));

}




