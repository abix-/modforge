// Address: 0x14027f5a0
// Ghidra name: FUN_14027f5a0
// ============ 0x14027f5a0 FUN_14027f5a0 (size=381) ============


bool FUN_14027f5a0(longlong param_1,int param_2)



{

  int iVar1;

  int iVar2;

  uint uVar3;

  uint uVar4;

  undefined1 local_res8;

  undefined1 uStackX_9;

  byte bStackX_a;

  byte bStackX_b;

  undefined1 uStackX_c;

  undefined2 local_resd;

  

  uStackX_9 = 0;

  bStackX_a = 0;

  bStackX_b = 0;

  uStackX_c = 0;

  local_resd = 0;

  iVar1 = 0;

  if (-1 < param_2) {

    iVar1 = param_2;

  }

  if (0xffff < iVar1) {

    iVar1 = 0xffff;

  }

  if (*(char *)(*(longlong *)(param_1 + 0x70) + 0x21) == '\0') {

    local_res8 = 0xf5;

    iVar2 = FUN_140195730(*(undefined8 *)(param_1 + 0x80),&local_res8,7);

    if (iVar2 != -1) {

      if (iVar1 == 0) {

        return true;

      }

      if (iVar1 < 0xaaab) {

        uVar3 = iVar1 * 0xc;

        uVar4 = iVar1 << 7;

      }

      else {

        uVar3 = (iVar1 + 0xaaaa) * 6;

        uVar4 = iVar1 * 0xff - 0x54aa56;

      }

      bStackX_a = (byte)((ulonglong)(uVar3 >> 1) / 0xaaaa);

      local_resd = 0;

      uStackX_c = (undefined1)((ulonglong)uVar4 / 0xaaaa);

      local_res8 = 0xfe;

      uStackX_9 = 0xd;

      bStackX_b = bStackX_a;

      iVar1 = FUN_140195730(*(undefined8 *)(param_1 + 0x80),&local_res8,7);

      if (iVar1 != -1) {

        uStackX_9 = 0;

        bStackX_a = 0;

        bStackX_b = 0;

        uStackX_c = 0;

        local_resd = 0;

        local_res8 = 0x14;

        iVar1 = FUN_140195730(*(undefined8 *)(param_1 + 0x80),&local_res8,7);

        return iVar1 != -1;

      }

    }

  }

  else {

    local_res8 = 0xfe;

    uStackX_9 = 3;

    iVar1 = (iVar1 * 0x5a) / 0xffff;

    uStackX_c = (undefined1)iVar1;

    bStackX_a = (byte)((uint)iVar1 >> 8) >> 6;

    bStackX_b = bStackX_a;

    iVar1 = FUN_140195730(*(undefined8 *)(param_1 + 0x80),&local_res8,7);

    if (iVar1 != -1) {

      return true;

    }

  }

  return false;

}




