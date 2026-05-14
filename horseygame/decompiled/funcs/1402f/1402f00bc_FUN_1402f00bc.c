// Address: 0x1402f00bc
// Ghidra name: FUN_1402f00bc
// ============ 0x1402f00bc FUN_1402f00bc (size=163) ============


undefined4

FUN_1402f00bc(undefined4 param_1,undefined8 param_2,undefined8 param_3,undefined4 *param_4)



{

  undefined4 uVar1;

  longlong lVar2;

  undefined4 uVar3;

  undefined4 uVar4;

  undefined4 uVar5;

  longlong local_48 [2];

  undefined1 local_38;

  undefined4 local_30;

  undefined4 uStack_2c;

  undefined4 uStack_28;

  undefined4 uStack_24;

  char local_20;

  undefined4 local_1c;

  char local_18;

  undefined4 local_14;

  char local_10;

  

  local_48[0] = 0;

  local_38 = 0;

  local_20 = '\0';

  local_18 = '\0';

  local_10 = '\0';

  if (param_4 == (undefined4 *)0x0) {

    uVar1 = PTR_PTR_1403e8e88._0_4_;

    uVar3 = PTR_PTR_1403e8e88._4_4_;

    uVar4 = PTR_DAT_1403e8e90._0_4_;

    uVar5 = PTR_DAT_1403e8e90._4_4_;

    if (DAT_1403ff13c != 0) goto LAB_1402f0107;

  }

  else {

    uVar1 = *param_4;

    uVar3 = param_4[1];

    uVar4 = param_4[2];

    uVar5 = param_4[3];

  }

  local_20 = '\x01';

  param_1 = uVar1;

  local_30 = uVar1;

  uStack_2c = uVar3;

  uStack_28 = uVar4;

  uStack_24 = uVar5;

LAB_1402f0107:

  uVar1 = FUN_1402eff44(param_1,param_2,param_3,local_48);

  if (local_20 == '\x02') {

    *(uint *)(local_48[0] + 0x3a8) = *(uint *)(local_48[0] + 0x3a8) & 0xfffffffd;

  }

  if (local_18 != '\0') {

    lVar2 = FUN_1402cd068(local_48);

    *(undefined4 *)(lVar2 + 0x20) = local_1c;

  }

  if (local_10 != '\0') {

    lVar2 = FUN_1402cd068(local_48);

    *(undefined4 *)(lVar2 + 0x24) = local_14;

  }

  return uVar1;

}




