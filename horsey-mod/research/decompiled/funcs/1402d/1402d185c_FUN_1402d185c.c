// Address: 0x1402d185c
// Ghidra name: FUN_1402d185c
// ============ 0x1402d185c FUN_1402d185c (size=161) ============


undefined8 FUN_1402d185c(void)



{

  undefined8 uVar1;

  longlong lVar2;

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

  local_20 = DAT_1403ff13c == 0;

  local_38 = 0;

  local_18 = '\0';

  local_10 = '\0';

  if ((bool)local_20) {

    local_30 = PTR_PTR_1403e8e88._0_4_;

    uStack_2c = PTR_PTR_1403e8e88._4_4_;

    uStack_28 = PTR_DAT_1403e8e90._0_4_;

    uStack_24 = PTR_DAT_1403e8e90._4_4_;

  }

  uVar1 = FUN_1402d15ac();

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




