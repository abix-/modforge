// Address: 0x140041fe0
// Ghidra name: FUN_140041fe0
// ============ 0x140041fe0 FUN_140041fe0 (size=325) ============


longlong FUN_140041fe0(undefined8 param_1,undefined4 param_2,undefined4 *param_3,undefined4 *param_4

                      ,undefined4 param_5)



{

  int iVar1;

  longlong lVar2;

  undefined1 local_778 [8];

  int local_770;

  undefined8 local_748;

  undefined4 local_740;

  undefined4 local_73c;

  undefined8 local_738;

  undefined4 local_720;

  undefined4 local_6f8;

  undefined4 uStack_6f4;

  uint uStack_6f0;

  undefined4 uStack_6ec;

  int local_6e8;

  uint local_6e4;

  undefined8 local_6e0;

  undefined8 local_6c0;

  undefined4 local_68;

  

  FUN_1402f94c0(local_778,0,0x770);

  if (param_4 != (undefined4 *)0x0) {

    local_6f8 = *param_4;

    uStack_6f4 = param_4[1];

    uStack_6ec = param_4[3];

    uStack_6f0 = param_4[2] & 0xfffffff8;

    local_6e4 = uStack_6f0;

  }

  local_68 = 0xffffffff;

  local_6e0 = 0;

  local_738 = 0;

  local_6c0 = 0;

  local_748 = param_1;

  local_740 = FUN_1402cf00c(param_1);

  local_720 = param_5;

  local_73c = param_2;

  iVar1 = FUN_140050ad0(local_778);

  if (iVar1 != 0) {

    local_770 = local_770 + 0x770;

    if (CONCAT44(uStack_6f4,local_6f8) == 0) {

      lVar2 = _malloc_base(0x770);

      iVar1 = local_6e8;

    }

    else {

      lVar2 = CONCAT44(uStack_6f4,local_6f8) + (longlong)local_6e8;

      iVar1 = local_6e8 + 0x770;

      if ((int)local_6e4 < local_6e8 + 0x770) goto LAB_1400420f2;

    }

    local_6e8 = iVar1;

    if (lVar2 != 0) {

      FUN_1402f8e20(lVar2,local_778,0x770);

      FUN_140055360(lVar2);

      return lVar2;

    }

  }

LAB_1400420f2:

  if (param_3 != (undefined4 *)0x0) {

    *param_3 = local_6e0._4_4_;

  }

  FUN_140054630(local_778);

  return 0;

}




