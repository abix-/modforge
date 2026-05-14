// Address: 0x1402f1514
// Ghidra name: FUN_1402f1514
// ============ 0x1402f1514 FUN_1402f1514 (size=309) ============


undefined4 FUN_1402f1514(longlong param_1,undefined8 param_2,int param_3,longlong param_4)



{

  undefined4 uVar1;

  undefined4 uVar2;

  longlong lVar3;

  int local_res8 [2];

  longlong local_res10;

  undefined1 local_res18 [8];

  longlong local_res20;

  longlong local_98 [2];

  undefined1 local_88;

  undefined4 local_80;

  undefined4 uStack_7c;

  undefined4 uStack_78;

  undefined4 uStack_74;

  char local_70;

  undefined4 local_6c;

  char local_68;

  undefined4 local_64;

  char local_60;

  undefined8 local_58;

  longlong local_50;

  longlong local_48;

  longlong *local_40;

  longlong *local_38;

  longlong *local_30;

  int *local_28;

  undefined8 *local_20;

  

  local_98[0] = 0;

  local_70 = DAT_1403ff13c == 0;

  local_88 = 0;

  local_68 = '\0';

  local_60 = '\0';

  if ((bool)local_70) {

    local_80 = PTR_PTR_1403e8e88._0_4_;

    uStack_7c = PTR_PTR_1403e8e88._4_4_;

    uStack_78 = PTR_DAT_1403e8e90._0_4_;

    uStack_74 = PTR_DAT_1403e8e90._4_4_;

  }

  local_res8[0] = param_3;

  local_res10 = param_4;

  local_res20 = param_1;

  local_58 = param_2;

  if ((param_1 == 0) ||

     ((param_3 != 4 && (((param_3 != 0 && (param_3 != 0x40)) || (0x7ffffffd < param_4 - 2U)))))) {

    local_68 = '\x01';

    local_6c = 0x16;

    FUN_1402cd39c(0,0,0,0,0,local_98);

    uVar2 = 0xffffffff;

  }

  else {

    local_40 = &local_res10;

    local_38 = &local_res20;

    local_30 = local_98;

    local_28 = local_res8;

    local_20 = &local_58;

    local_50 = param_1;

    local_48 = param_1;

    uVar2 = operator()<>(local_res18,&local_48,&local_40,&local_50);

  }

  uVar1 = local_6c;

  if (local_70 == '\x02') {

    *(uint *)(local_98[0] + 0x3a8) = *(uint *)(local_98[0] + 0x3a8) & 0xfffffffd;

  }

  if (local_68 != '\0') {

    lVar3 = FUN_1402cd068(local_98);

    *(undefined4 *)(lVar3 + 0x20) = uVar1;

  }

  if (local_60 != '\0') {

    lVar3 = FUN_1402cd068(local_98);

    *(undefined4 *)(lVar3 + 0x24) = local_64;

  }

  return uVar2;

}




