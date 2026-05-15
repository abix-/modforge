// Address: 0x14012ee80
// Ghidra name: thunk_FUN_1402d89dc
// ============ 0x14012ee80 thunk_FUN_1402d89dc (size=5) ============


undefined4 thunk_FUN_1402d89dc(undefined8 param_1)



{

  undefined4 uVar1;

  longlong lVar2;

  undefined8 uStack_58;

  undefined8 uStack_50;

  longlong alStack_48 [2];

  undefined1 uStack_38;

  undefined4 uStack_30;

  undefined4 uStack_2c;

  undefined4 uStack_28;

  undefined4 uStack_24;

  char cStack_20;

  undefined4 uStack_1c;

  char cStack_18;

  undefined4 uStack_14;

  char cStack_10;

  

  alStack_48[0] = 0;

  cStack_20 = DAT_1403ff13c == 0;

  uStack_38 = 0;

  cStack_18 = '\0';

  cStack_10 = '\0';

  if ((bool)cStack_20) {

    uStack_30 = PTR_PTR_1403e8e88._0_4_;

    uStack_2c = PTR_PTR_1403e8e88._4_4_;

    uStack_28 = PTR_DAT_1403e8e90._0_4_;

    uStack_24 = PTR_DAT_1403e8e90._4_4_;

  }

  uStack_50 = 0;

  uStack_58 = param_1;

  uVar1 = FUN_1402d83ac(alStack_48,&uStack_58,10,1);

  if (cStack_20 == '\x02') {

    *(uint *)(alStack_48[0] + 0x3a8) = *(uint *)(alStack_48[0] + 0x3a8) & 0xfffffffd;

  }

  if (cStack_18 != '\0') {

    lVar2 = FUN_1402cd068(alStack_48);

    *(undefined4 *)(lVar2 + 0x20) = uStack_1c;

  }

  if (cStack_10 != '\0') {

    lVar2 = FUN_1402cd068(alStack_48);

    *(undefined4 *)(lVar2 + 0x24) = uStack_14;

  }

  return uVar1;

}




