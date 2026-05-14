// Address: 0x14028ac30
// Ghidra name: FUN_14028ac30
// ============ 0x14028ac30 FUN_14028ac30 (size=559) ============


undefined8 FUN_14028ac30(longlong param_1,int param_2)



{

  longlong lVar1;

  char cVar2;

  uint uVar3;

  int iVar4;

  uint uVar5;

  undefined1 local_res8;

  undefined1 uStackX_9;

  byte bStackX_a;

  byte bStackX_b;

  undefined1 uStackX_c;

  undefined2 local_resd;

  

  lVar1 = *(longlong *)(param_1 + 0x18);

  uStackX_9 = 0;

  bStackX_a = 0;

  bStackX_b = 0;

  uStackX_c = 0;

  local_resd = 0;

  iVar4 = 0;

  if (-1 < param_2) {

    iVar4 = param_2;

  }

  if (100 < iVar4) {

    iVar4 = 100;

  }

  FUN_140179b40(*(undefined8 *)(lVar1 + 0xb80));

  if (*(char *)(lVar1 + 0xb88) == '\0') {

    local_res8 = 0xf5;

    iVar4 = (iVar4 * 0xffff) / 100;

    cVar2 = FUN_14015adf0(*(undefined8 *)(lVar1 + 0xa68),&local_res8,7);

    if (cVar2 == '\0') {

      FUN_140179b60(*(undefined8 *)(lVar1 + 0xb80));

      FUN_14012e850("Failed sending autocenter disable command");

      return 0;

    }

    if (iVar4 != 0) {

      if (iVar4 < 0xaaab) {

        uVar3 = iVar4 * 0xc;

        uVar5 = iVar4 * 0x80;

      }

      else {

        uVar3 = (iVar4 + 0xaaaa) * 6;

        uVar5 = (iVar4 + -0xaaaa) * 0xff + 0x555500;

      }

      local_resd = 0;

      bStackX_a = (byte)((ulonglong)(uVar3 >> 1) / 0xaaaa);

      local_res8 = 0xfe;

      uStackX_9 = 0xd;

      uStackX_c = (undefined1)((ulonglong)uVar5 / 0xaaaa);

      bStackX_b = bStackX_a;

      cVar2 = FUN_14015adf0(*(undefined8 *)(lVar1 + 0xa68),&local_res8,7);

      if (cVar2 == '\0') {

        FUN_140179b60(*(undefined8 *)(lVar1 + 0xb80));

        FUN_14012e850("Failed sending autocenter magnitude command");

        return 0;

      }

      uStackX_9 = 0;

      bStackX_a = 0;

      bStackX_b = 0;

      uStackX_c = 0;

      local_resd = 0;

      local_res8 = 0x14;

      cVar2 = FUN_14015adf0(*(undefined8 *)(lVar1 + 0xa68),&local_res8,7);

      if (cVar2 == '\0') {

        FUN_140179b60(*(undefined8 *)(lVar1 + 0xb80));

        FUN_14012e850("Failed sending autocenter enable command");

        return 0;

      }

    }

  }

  else {

    local_res8 = 0xfe;

    uStackX_9 = 3;

    iVar4 = (iVar4 * 0x5a) / 100;

    uStackX_c = (undefined1)iVar4;

    bStackX_a = (byte)((uint)iVar4 >> 8) >> 6;

    bStackX_b = bStackX_a;

    cVar2 = FUN_14015adf0(*(undefined8 *)(lVar1 + 0xa68),&local_res8,7);

    if (cVar2 == '\0') {

      FUN_140179b60(*(undefined8 *)(lVar1 + 0xb80));

      FUN_14012e850("Failed sending autocenter command");

      return 0;

    }

  }

  FUN_140179b60(*(undefined8 *)(lVar1 + 0xb80));

  return 1;

}




