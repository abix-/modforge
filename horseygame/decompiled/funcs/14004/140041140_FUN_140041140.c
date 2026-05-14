// Address: 0x140041140
// Ghidra name: FUN_140041140
// ============ 0x140041140 FUN_140041140 (size=310) ============


longlong FUN_140041140(longlong param_1,int param_2,int *param_3,undefined4 *param_4,

                      undefined4 *param_5)



{

  int iVar1;

  undefined4 uVar2;

  longlong lVar3;

  undefined1 local_788 [8];

  int local_780;

  undefined8 local_758;

  undefined4 local_74c;

  longlong local_748;

  longlong local_738;

  undefined1 local_72c;

  undefined4 local_708;

  undefined4 uStack_704;

  uint uStack_700;

  undefined4 uStack_6fc;

  int local_6f8;

  uint local_6f4;

  undefined8 local_6f0;

  undefined8 local_6d0;

  undefined4 local_78;

  

  FUN_1402f94c0(local_788,0,0x770);

  if (param_5 != (undefined4 *)0x0) {

    local_708 = *param_5;

    uStack_704 = param_5[1];

    uStack_6fc = param_5[3];

    uStack_700 = param_5[2] & 0xfffffff8;

    local_6f4 = uStack_700;

  }

  local_78 = 0xffffffff;

  local_738 = param_2 + param_1;

  local_6f0 = 0;

  local_6d0 = 0;

  local_74c = 0;

  local_758 = 0;

  local_72c = 1;

  local_748 = param_1;

  iVar1 = FUN_140050ad0(local_788);

  if (iVar1 == 0) {

    uVar2 = local_6f0._4_4_;

    if ((int)local_6f0 != 0) {

      uVar2 = 1;

    }

    *param_4 = uVar2;

  }

  else {

    local_780 = local_780 + 0x770;

    if (CONCAT44(uStack_704,local_708) == 0) {

      lVar3 = _malloc_base(0x770);

      iVar1 = local_6f8;

    }

    else {

      lVar3 = CONCAT44(uStack_704,local_708) + (longlong)local_6f8;

      iVar1 = local_6f8 + 0x770;

      if ((int)local_6f4 < local_6f8 + 0x770) goto LAB_1400411f0;

    }

    local_6f8 = iVar1;

    if (lVar3 != 0) {

      FUN_1402f8e20(lVar3,local_788,0x770);

      *param_3 = *(int *)(lVar3 + 0x40) - (int)param_1;

      *param_4 = 0;

      return lVar3;

    }

  }

LAB_1400411f0:

  FUN_140054630(local_788);

  return 0;

}




