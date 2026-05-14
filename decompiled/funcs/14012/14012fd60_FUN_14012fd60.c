// Address: 0x14012fd60
// Ghidra name: FUN_14012fd60
// ============ 0x14012fd60 FUN_14012fd60 (size=326) ============


undefined8 FUN_14012fd60(longlong param_1,longlong param_2,longlong param_3)



{

  uint uVar1;

  int iVar2;

  undefined4 uVar3;

  int iVar4;

  longlong lVar5;

  uint *puVar6;

  int iVar7;

  int iVar8;

  longlong lVar9;

  longlong local_res8;

  longlong local_res10;

  longlong local_res18;

  longlong local_res20;

  uint local_68 [4];

  uint local_58 [6];

  

  iVar2 = 0;

  iVar8 = 0;

  iVar4 = 0;

  iVar7 = 0;

  lVar9 = param_3;

  local_res8 = param_3;

  local_res10 = param_2;

  local_res18 = param_1;

  local_res20 = param_2;

  do {

    if (iVar2 == iVar8) {

      uVar3 = FUN_140130020(&local_res18,lVar9);

      iVar2 = FUN_14012e880(uVar3,local_68);

      puVar6 = local_68;

      lVar9 = lVar9 - (local_res18 - param_1 >> 1);

      iVar8 = 1;

      param_3 = local_res8;

      param_2 = local_res10;

      param_1 = local_res18;

    }

    else {

      lVar5 = (longlong)iVar8;

      iVar8 = iVar8 + 1;

      puVar6 = local_68 + lVar5;

    }

    uVar1 = *puVar6;

    if (iVar4 == iVar7) {

      uVar3 = FUN_140130020(&local_res20,param_3);

      iVar4 = FUN_14012e880(uVar3,local_58);

      local_res10 = local_res20;

      iVar7 = 1;

      param_3 = local_res8 - (local_res20 - param_2 >> 1);

      puVar6 = local_58;

      param_2 = local_res20;

      local_res8 = param_3;

    }

    else {

      lVar5 = (longlong)iVar7;

      iVar7 = iVar7 + 1;

      puVar6 = local_58 + lVar5;

    }

    if (uVar1 < *puVar6) {

      return 0xffffffff;

    }

    if (uVar1 != *puVar6) {

      return 1;

    }

  } while (uVar1 != 0);

  return 0;

}




