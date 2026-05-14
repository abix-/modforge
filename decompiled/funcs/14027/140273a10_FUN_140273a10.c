// Address: 0x140273a10
// Ghidra name: FUN_140273a10
// ============ 0x140273a10 FUN_140273a10 (size=451) ============


undefined1 FUN_140273a10(longlong *param_1,undefined8 param_2,int param_3,char param_4)



{

  longlong lVar1;

  undefined1 uVar2;

  char cVar3;

  undefined4 uVar4;

  int iVar5;

  longlong lVar6;

  ulonglong uVar7;

  longlong lVar8;

  bool bVar9;

  undefined1 local_res8 [8];

  undefined1 local_88 [8];

  longlong local_80;

  int *local_78;

  undefined4 uStack_6c;

  char local_68 [80];

  

  if (*(char *)((longlong)param_1 + 0x17) == '\0') {

LAB_140273a2b:

    uVar2 = FUN_14012e850("That operation is not supported");

    return uVar2;

  }

  if (*(char *)((longlong)param_1 + 0x21) == '\0') {

    if (param_4 != '\0') {

      FUN_140274450();

      FUN_1401492f0(10);

    }

    if (*(char *)((longlong)param_1 + 0x21) == '\0') goto LAB_140273a2b;

  }

  lVar1 = *param_1;

  local_68[8] = '\0';

  local_68[9] = '\0';

  local_68[10] = '\0';

  local_68[0xb] = '\0';

  local_68[0xc] = '\0';

  local_68[0xd] = '\0';

  local_68[0xe] = '\0';

  local_68[0xf] = '\0';

  local_68[0x40] = '\0';

  local_68[0x41] = '\0';

  local_68[0x42] = '\0';

  local_68[0x43] = '\0';

  local_68[0x44] = '\0';

  local_68[0x45] = '\0';

  local_68[0x46] = '\0';

  local_68[0x47] = '\0';

  local_68[0x10] = '\0';

  local_68[0x11] = '\0';

  local_68[0x12] = '\0';

  local_68[0x13] = '\0';

  local_68[0x14] = '\0';

  local_68[0x15] = '\0';

  local_68[0x16] = '\0';

  local_68[0x17] = '\0';

  local_68[0x18] = '\0';

  local_68[0x19] = '\0';

  local_68[0x1a] = '\0';

  local_68[0x1b] = '\0';

  local_68[0x1c] = '\0';

  local_68[0x1d] = '\0';

  local_68[0x1e] = '\0';

  local_68[0x1f] = '\0';

  local_68[0x48] = '\0';

  local_68[0x49] = '\0';

  local_68[0x4a] = '\0';

  local_68[0x4b] = '\0';

  local_68[0x20] = '\0';

  local_68[0x21] = '\0';

  local_68[0x22] = '\0';

  local_68[0x23] = '\0';

  local_68[0x24] = '\0';

  local_68[0x25] = '\0';

  local_68[0x26] = '\0';

  local_68[0x27] = '\0';

  local_68[0x28] = '\0';

  local_68[0x29] = '\0';

  local_68[0x2a] = '\0';

  local_68[0x2b] = '\0';

  local_68[0x2c] = '\0';

  local_68[0x2d] = '\0';

  local_68[0x2e] = '\0';

  local_68[0x2f] = '\0';

  local_68[0x4c] = '\0';

  local_68[0x4d] = '\0';

  local_68[0x30] = '\0';

  local_68[0x31] = '\0';

  local_68[0x32] = '\0';

  local_68[0x33] = '\0';

  local_68[0x34] = '\0';

  local_68[0x35] = '\0';

  local_68[0x36] = '\0';

  local_68[0x37] = '\0';

  local_68[0x38] = '\0';

  local_68[0x39] = '\0';

  local_68[0x3a] = '\0';

  local_68[0x3b] = '\0';

  local_68[0x3c] = '\0';

  local_68[0x3d] = '\0';

  local_68[0x3e] = '\0';

  local_68[0x3f] = '\0';

  if (*(char *)(lVar1 + 0x54) == '\0') {

    local_68[0] = '\x02';

    local_68[1] = '\0';

    local_68[2] = '\0';

    local_68[3] = '\0';

    local_68[4] = '\0';

    local_68[5] = '\0';

    local_68[6] = '\0';

    local_68[7] = '\0';

    lVar6 = 0x30;

    lVar8 = 1;

  }

  else {

    lVar6 = 0x4e;

    local_68[0] = '1';

    local_68[1] = '\0';

    local_68[2] = '\x10';

    local_68[3] = '\0';

    local_68[4] = '\0';

    local_68[5] = '\0';

    local_68[6] = '\0';

    local_68[7] = '\0';

    lVar8 = 3;

  }

  uVar7 = 0x4eU - lVar8;

  if ((ulonglong)(longlong)param_3 <= 0x4eU - lVar8) {

    uVar7 = (longlong)param_3;

  }

  FUN_1402f8e20(local_68 + lVar8,param_2,uVar7);

  if (*(char *)(lVar1 + 0x54) != '\0') {

    local_res8[0] = 0xa2;

    uVar4 = FUN_1401917b0(0,local_res8,1);

    uVar4 = FUN_1401917b0(uVar4,local_68,lVar6 + -4);

    *(undefined4 *)((longlong)&uStack_6c + lVar6) = uVar4;

  }

  cVar3 = FUN_1402843f0();

  if (cVar3 == '\0') {

    bVar9 = false;

  }

  else {

    cVar3 = FUN_1402843a0(*param_1,&local_80,&local_78,local_88);

    if ((((cVar3 == '\0') || ((int)lVar6 != *local_78)) ||

        (local_68[lVar8] != *(char *)(lVar8 + local_80))) ||

       (local_68[lVar8 + 1] != *(char *)(lVar8 + 1 + local_80))) {

      iVar5 = FUN_140284650(*param_1,local_68,lVar6);

      bVar9 = iVar5 == (int)lVar6;

    }

    else {

      FUN_1402f8e20(local_80,local_68,lVar6);

      FUN_140284910();

      bVar9 = true;

    }

  }

  return bVar9;

}




