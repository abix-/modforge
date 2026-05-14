// Address: 0x140041e50
// Ghidra name: FUN_140041e50
// ============ 0x140041e50 FUN_140041e50 (size=380) ============


longlong FUN_140041e50(undefined8 param_1,undefined4 param_2,undefined4 *param_3,undefined4 *param_4

                      )



{

  int iVar1;

  int iVar2;

  longlong lVar3;

  undefined1 local_788 [8];

  int local_780;

  undefined8 local_758;

  undefined4 local_750;

  undefined4 local_74c;

  undefined8 local_748;

  int local_730;

  undefined4 local_708;

  undefined4 uStack_704;

  uint uStack_700;

  undefined4 uStack_6fc;

  int local_6f8;

  uint local_6f4;

  undefined8 local_6f0;

  undefined8 local_6d0;

  undefined4 local_78;

  

  iVar1 = FUN_1402cf00c();

  FUN_1402cea4c(param_1,0,2);

  iVar2 = FUN_1402cf00c(param_1);

  FUN_1402cea4c(param_1,iVar1,0);

  FUN_1402f94c0(local_788,0,0x770);

  if (param_4 != (undefined4 *)0x0) {

    local_708 = *param_4;

    uStack_704 = param_4[1];

    uStack_6fc = param_4[3];

    uStack_700 = param_4[2] & 0xfffffff8;

    local_6f4 = uStack_700;

  }

  local_78 = 0xffffffff;

  local_6f0 = 0;

  local_748 = 0;

  local_6d0 = 0;

  local_758 = param_1;

  local_750 = FUN_1402cf00c(param_1);

  local_74c = param_2;

  local_730 = iVar2 - iVar1;

  iVar1 = FUN_140050ad0(local_788);

  if (iVar1 != 0) {

    local_780 = local_780 + 0x770;

    if (CONCAT44(uStack_704,local_708) == 0) {

      lVar3 = _malloc_base(0x770);

      iVar1 = local_6f8;

    }

    else {

      lVar3 = CONCAT44(uStack_704,local_708) + (longlong)local_6f8;

      iVar1 = local_6f8 + 0x770;

      if ((int)local_6f4 < local_6f8 + 0x770) goto LAB_140041f94;

    }

    local_6f8 = iVar1;

    if (lVar3 != 0) {

      FUN_1402f8e20(lVar3,local_788,0x770);

      FUN_140055360(lVar3);

      return lVar3;

    }

  }

LAB_140041f94:

  if (param_3 != (undefined4 *)0x0) {

    *param_3 = local_6f0._4_4_;

  }

  FUN_140054630(local_788);

  return 0;

}




