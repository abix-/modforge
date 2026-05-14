// Address: 0x1402df8d0
// Ghidra name: FUN_1402df8d0
// ============ 0x1402df8d0 FUN_1402df8d0 (size=254) ============


undefined8 FUN_1402df8d0(undefined4 *param_1,undefined8 *param_2)



{

  undefined8 uVar1;

  longlong lVar2;

  undefined4 uVar3;

  undefined4 uVar4;

  undefined4 uVar5;

  undefined4 uVar6;

  undefined8 local_68;

  undefined8 local_60;

  undefined8 local_58;

  undefined8 local_50;

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

  if (param_1 == (undefined4 *)0x0) {

    uVar3 = PTR_PTR_1403e8e88._0_4_;

    uVar4 = PTR_PTR_1403e8e88._4_4_;

    uVar5 = PTR_DAT_1403e8e90._0_4_;

    uVar6 = PTR_DAT_1403e8e90._4_4_;

    if (DAT_1403ff13c != 0) goto LAB_1402df92b;

  }

  else {

    uVar3 = *param_1;

    uVar4 = param_1[1];

    uVar5 = param_1[2];

    uVar6 = param_1[3];

  }

  local_20 = '\x01';

  local_30 = uVar3;

  uStack_2c = uVar4;

  uStack_28 = uVar5;

  uStack_24 = uVar6;

LAB_1402df92b:

  local_68 = *param_2;

  local_60 = param_2[1];

  local_58 = param_2[2];

  local_50 = param_2[3];

  param_2[3] = 0;

  *param_2 = 0;

  uVar1 = FUN_1402df49c(local_48,&local_68);

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

  if (((undefined1 *)param_2[3] != (undefined1 *)0x0) && (param_2[2] == 0)) {

    *(undefined1 *)param_2[3] = 0;

  }

  return uVar1;

}




