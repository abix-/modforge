// Address: 0x14012f4e0
// Ghidra name: thunk_FUN_1402d8b40
// ============ 0x14012f4e0 thunk_FUN_1402d8b40 (size=5) ============


undefined8 thunk_FUN_1402d8b40(undefined8 param_1,undefined8 *param_2,undefined8 param_3)



{

  undefined8 uVar1;

  longlong lVar2;

  undefined8 uStack_58;

  undefined8 *puStack_50;

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

  if (param_2 != (undefined8 *)0x0) {

    *param_2 = param_1;

  }

  uStack_58 = param_1;

  puStack_50 = param_2;

  uVar1 = FUN_1402d8688(alStack_48,&uStack_58,param_3,1);

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




