// Address: 0x14018ade0
// Ghidra name: FUN_14018ade0
// ============ 0x14018ade0 FUN_14018ade0 (size=191) ============


undefined8 FUN_14018ade0(undefined8 param_1,undefined4 *param_2)



{

  longlong lVar1;

  longlong lVar2;

  undefined4 local_res10;

  undefined4 local_res14;

  

  lVar1 = (ulonglong)(uint)param_2[1] + *(longlong *)(param_2 + 2);

  FUN_14018a480(param_2);

  if ((*(longlong *)(param_2 + 2) <= (longlong)(0x7fffffffffffffff - (ulonglong)(uint)param_2[1]))

     && (lVar1 < 0x7ffffffffffffff8)) {

    lVar2 = lVar1 + 1;

    if ((param_2[1] & 1) == 0) {

      lVar2 = lVar1;

    }

    lVar1 = FUN_14012cb40(param_1,lVar2,0);

    if (lVar1 != lVar2) {

      return 0xfffffffe;

    }

    lVar1 = FUN_14012c730(param_1,&local_res10,8);

    if (lVar1 == 8) {

      *param_2 = local_res10;

      param_2[1] = local_res14;

      *(longlong *)(param_2 + 2) = lVar2 + 8;

      return 0;

    }

  }

  return 0xffffffff;

}




