// Address: 0x14012f260
// Ghidra name: FUN_14012f260
// ============ 0x14012f260 FUN_14012f260 (size=277) ============


undefined8 FUN_14012f260(longlong param_1,longlong param_2,longlong param_3)



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

  uint local_58 [4];

  uint local_48 [4];

  

  iVar2 = 0;

  iVar7 = 0;

  iVar4 = 0;

  iVar8 = 0;

  lVar9 = param_3;

  local_res8 = param_1;

  local_res10 = param_2;

  local_res18 = param_2;

  do {

    if (iVar2 == iVar7) {

      uVar3 = FUN_1401300a0(&local_res8,lVar9);

      iVar2 = FUN_14012e880(uVar3,local_58);

      puVar6 = local_58;

      iVar7 = 1;

      lVar9 = lVar9 + (param_1 - local_res8);

      param_1 = local_res8;

    }

    else {

      lVar5 = (longlong)iVar7;

      iVar7 = iVar7 + 1;

      puVar6 = local_58 + lVar5;

    }

    uVar1 = *puVar6;

    if (iVar4 == iVar8) {

      uVar3 = FUN_1401300a0(&local_res10,param_3);

      iVar4 = FUN_14012e880(uVar3,local_48);

      iVar8 = 1;

      lVar5 = local_res18 - local_res10;

      local_res18 = local_res10;

      param_3 = param_3 + lVar5;

      puVar6 = local_48;

    }

    else {

      lVar5 = (longlong)iVar8;

      iVar8 = iVar8 + 1;

      puVar6 = local_48 + lVar5;

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




