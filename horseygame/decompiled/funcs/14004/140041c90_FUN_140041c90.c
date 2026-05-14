// Address: 0x140041c90
// Ghidra name: FUN_140041c90
// ============ 0x140041c90 FUN_140041c90 (size=434) ============


longlong FUN_140041c90(char *param_1,undefined4 *param_2,undefined4 *param_3)



{

  errno_t eVar1;

  int iVar2;

  int iVar3;

  longlong lVar4;

  FILE *local_res20;

  undefined1 local_788 [8];

  int local_780;

  FILE *local_758;

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

  

  eVar1 = fopen_s(&local_res20,param_1,"rb");

  if ((eVar1 != 0) || (local_res20 == (FILE *)0x0)) {

    if (param_2 != (undefined4 *)0x0) {

      *param_2 = 6;

    }

    return 0;

  }

  iVar2 = FUN_1402cf00c(local_res20);

  FUN_1402cea4c(local_res20,0,2);

  iVar3 = FUN_1402cf00c(local_res20);

  FUN_1402cea4c(local_res20,iVar2,0);

  FUN_1402f94c0(local_788,0,0x770);

  if (param_3 != (undefined4 *)0x0) {

    local_708 = *param_3;

    uStack_704 = param_3[1];

    uStack_6fc = param_3[3];

    uStack_700 = param_3[2] & 0xfffffff8;

    local_6f4 = uStack_700;

  }

  local_78 = 0xffffffff;

  local_6f0 = 0;

  local_748 = 0;

  local_6d0 = 0;

  local_758 = local_res20;

  local_750 = FUN_1402cf00c(local_res20);

  local_74c = 1;

  local_730 = iVar3 - iVar2;

  iVar2 = FUN_140050ad0(local_788);

  if (iVar2 != 0) {

    local_780 = local_780 + 0x770;

    if (CONCAT44(uStack_704,local_708) == 0) {

      lVar4 = _malloc_base(0x770);

      iVar2 = local_6f8;

    }

    else {

      lVar4 = CONCAT44(uStack_704,local_708) + (longlong)local_6f8;

      iVar2 = local_6f8 + 0x770;

      if ((int)local_6f4 < local_6f8 + 0x770) goto LAB_140041dfd;

    }

    local_6f8 = iVar2;

    if (lVar4 != 0) {

      FUN_1402f8e20(lVar4,local_788,0x770);

      FUN_140055360(lVar4);

      return lVar4;

    }

  }

LAB_140041dfd:

  if (param_2 != (undefined4 *)0x0) {

    *param_2 = local_6f0._4_4_;

  }

  FUN_140054630(local_788);

  return 0;

}




