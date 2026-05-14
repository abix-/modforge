// Address: 0x14020e470
// Ghidra name: FUN_14020e470
// ============ 0x14020e470 FUN_14020e470 (size=300) ============


undefined8 FUN_14020e470(undefined8 param_1)



{

  int iVar1;

  longlong *local_res10;

  longlong *local_res18;

  longlong *local_res20;

  longlong *local_18 [2];

  

  local_res18 = (longlong *)0x0;

  local_res20 = (longlong *)0x0;

  local_res10 = (longlong *)0x0;

  local_18[0] = (longlong *)0x0;

  FUN_14020e9b0();

  if (DAT_1403fd2c8 != (longlong *)0x0) {

    iVar1 = (**(code **)(*DAT_1403fd2c8 + 0x30))(DAT_1403fd2c8,param_1,&local_res10);

    if ((-1 < iVar1) && (local_res10 != (longlong *)0x0)) {

      (**(code **)(*local_res10 + 0x10))();

      return 1;

    }

  }

  if (DAT_1403fd2b0 != (longlong *)0x0) {

    iVar1 = (**(code **)(*DAT_1403fd2b0 + 0x30))(DAT_1403fd2b0,param_1,&local_res18);

    if ((-1 < iVar1) && (local_res18 != (longlong *)0x0)) {

      (**(code **)(*local_res18 + 0x10))();

      return 3;

    }

  }

  if (DAT_1403fd2b8 != (longlong *)0x0) {

    iVar1 = (**(code **)(*DAT_1403fd2b8 + 0x58))(DAT_1403fd2b8,param_1,&local_res20);

    if ((-1 < iVar1) && (local_res20 != (longlong *)0x0)) {

      (**(code **)(*local_res20 + 0x10))();

      return 4;

    }

  }

  if (DAT_1403fd2d8 != (longlong *)0x0) {

    iVar1 = (**(code **)(*DAT_1403fd2d8 + 0x30))(DAT_1403fd2d8,param_1,local_18);

    if ((-1 < iVar1) && (local_18[0] != (longlong *)0x0)) {

      (**(code **)(*local_18[0] + 0x10))();

      return 2;

    }

  }

  return 0;

}




