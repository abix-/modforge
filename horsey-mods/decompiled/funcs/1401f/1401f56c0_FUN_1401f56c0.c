// Address: 0x1401f56c0
// Ghidra name: FUN_1401f56c0
// ============ 0x1401f56c0 FUN_1401f56c0 (size=163) ============


undefined8 FUN_1401f56c0(longlong param_1,int param_2,undefined8 param_3,longlong *param_4)



{

  longlong lVar1;

  undefined8 local_res8;

  

  lVar1 = *(longlong *)(param_1 + 0x2e0);

  FUN_1401f9dc0(lVar1);

  if (*(longlong *)(lVar1 + 0x710) != 0) {

    if (param_2 != 1) goto LAB_1401f571d;

    (*DAT_1403fcf10)(*(undefined8 *)(lVar1 + 0x698));

    *(undefined8 *)(lVar1 + 0x710) = 0;

  }

  FUN_1401f6480(lVar1,param_2,param_3);

LAB_1401f571d:

  if (*param_4 != 0) {

    local_res8 = 0;

    (*DAT_1403fcee8)(*(undefined8 *)(lVar1 + 0x698),0,1,param_4,&local_res8);

  }

  return 1;

}




