// Address: 0x1401abee0
// Ghidra name: FUN_1401abee0
// ============ 0x1401abee0 FUN_1401abee0 (size=684) ============


uint FUN_1401abee0(longlong *param_1,uint param_2)



{

  int iVar1;

  uint uVar2;

  uint uVar3;

  uint local_res10 [2];

  uint local_res18 [2];

  uint local_res20 [2];

  uint local_38;

  int local_34 [3];

  

  if ((param_2 & 0xf0000000) != 0x20000000) {

    return param_2;

  }

  local_res10[0] = 0;

  local_res18[0] = 0;

  local_res20[0] = 0;

  local_38 = 0;

  local_34[0] = 0;

  iVar1 = (**(code **)(*param_1 + 0x38))(param_1,&DAT_14033cb30,local_res10);

  if (iVar1 < 0) {

LAB_1401abf5a:

    local_res10[0] = (int)param_2 >> 0x18 & 0xf;

  }

  else if (local_res10[0] == 1) {

    local_res10[0] = 2;

  }

  else {

    if (local_res10[0] != 2) goto LAB_1401abf5a;

    local_res10[0] = 1;

  }

  iVar1 = (**(code **)(*param_1 + 0x38))(param_1,&DAT_14033cb40,local_res18);

  uVar2 = 5;

  uVar3 = 6;

  if (iVar1 < 0) {

switchD_1401abfab_caseD_8:

    local_res18[0] = (int)param_2 >> 10 & 0x1f;

  }

  else {

    switch(local_res18[0]) {

    case 2:

      local_res18[0] = 1;

      break;

    case 3:

      local_res18[0] = 4;

      break;

    case 4:

      local_res18[0] = 5;

      break;

    case 5:

      local_res18[0] = 6;

      break;

    case 6:

      local_res18[0] = 7;

      break;

    case 7:

      local_res18[0] = 0x16;

      break;

    default:

      goto switchD_1401abfab_caseD_8;

    case 9:

      local_res18[0] = 9;

      break;

    case 10:

      local_res18[0] = 10;

      break;

    case 0xb:

      local_res18[0] = 0xc;

    }

  }

  iVar1 = (**(code **)(*param_1 + 0x38))(param_1,&DAT_14033cb50,local_res20);

  if (iVar1 < 0) {

switchD_1401ac025_caseD_2:

    uVar2 = (int)param_2 >> 5 & 0x1f;

  }

  else {

    switch(local_res20[0]) {

    case 1:

      uVar2 = 8;

      break;

    default:

      goto switchD_1401ac025_caseD_2;

    case 4:

      uVar2 = 4;

      break;

    case 5:

      uVar2 = 1;

      break;

    case 6:

      uVar2 = 7;

      break;

    case 7:

      uVar2 = 0xd;

      break;

    case 8:

      break;

    case 9:

      uVar2 = 9;

      break;

    case 0xf:

      uVar2 = 0x10;

      break;

    case 0x10:

      uVar2 = 0x12;

      break;

    case 0x12:

      uVar2 = 0xc;

      break;

    case 0x13:

      uVar2 = 0x11;

    }

  }

  local_res20[0] = uVar2;

  iVar1 = (**(code **)(*param_1 + 0x38))(param_1,&DAT_14033cb60,&local_38);

  if (iVar1 < 0) {

switchD_1401ac0b1_caseD_5:

    uVar3 = param_2 & 0x1f;

  }

  else {

    switch(local_38) {

    case 1:

      uVar3 = 1;

      break;

    case 2:

      break;

    case 3:

      uVar3 = 7;

      break;

    case 4:

      uVar3 = 9;

      break;

    default:

      goto switchD_1401ac0b1_caseD_5;

    case 6:

      uVar3 = 0;

      break;

    case 7:

      uVar3 = 4;

      break;

    case 8:

      uVar3 = 8;

      break;

    case 9:

      uVar3 = 0xb;

      break;

    case 10:

      uVar3 = 0xc;

      break;

    case 0xb:

      uVar3 = 0xd;

      break;

    case 0xc:

      uVar3 = 0xe;

    }

  }

  local_38 = uVar3;

  iVar1 = (**(code **)(*param_1 + 0x38))(param_1,&DAT_14033cb70,local_34);

  if (-1 < iVar1) {

    if (local_34[0] == 1) {

      uVar2 = 2;

      goto LAB_1401ac159;

    }

    if (local_34[0] == 5) {

      uVar2 = 1;

      goto LAB_1401ac159;

    }

    if (local_34[0] == 6) {

      uVar2 = 3;

      goto LAB_1401ac159;

    }

  }

  uVar2 = (int)param_2 >> 0x14 & 0xf;

LAB_1401ac159:

  return ((((local_res10[0] | 0x20) << 4 | uVar2) << 10 | local_res18[0]) << 5 | local_res20[0]) <<

         5 | local_38;

}




