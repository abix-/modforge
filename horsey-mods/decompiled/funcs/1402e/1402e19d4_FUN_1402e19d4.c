// Address: 0x1402e19d4
// Ghidra name: FUN_1402e19d4
// ============ 0x1402e19d4 FUN_1402e19d4 (size=210) ============


int FUN_1402e19d4(FILE *param_1)



{

  int iVar1;

  longlong lVar2;

  undefined4 in_XMM0_Da;

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

    in_XMM0_Da = PTR_PTR_1403e8e88._0_4_;

  }

  if (param_1 == (FILE *)0x0) {

    iVar1 = common_flush_all(false);

    goto LAB_1402e1a59;

  }

  iVar1 = FUN_1402e1948(in_XMM0_Da,local_48);

  if (iVar1 == 0) {

    if ((*(uint *)((longlong)&param_1->_base + 4) >> 0xb & 1) != 0) {

      iVar1 = _fileno(param_1);

      iVar1 = _commit(iVar1);

      if (iVar1 != 0) goto LAB_1402e1a34;

    }

    iVar1 = 0;

  }

  else {

LAB_1402e1a34:

    iVar1 = -1;

  }

LAB_1402e1a59:

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

  return iVar1;

}




