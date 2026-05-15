// Address: 0x14012faf0
// Ghidra name: FUN_14012faf0
// ============ 0x14012faf0 FUN_14012faf0 (size=200) ============


undefined8 FUN_14012faf0(undefined8 param_1,undefined8 param_2)



{

  uint uVar1;

  int iVar2;

  undefined4 uVar3;

  int iVar4;

  longlong lVar5;

  uint *puVar6;

  int iVar7;

  int iVar8;

  undefined8 local_res8;

  undefined8 local_res10;

  uint local_38 [4];

  uint local_28 [4];

  

  iVar2 = 0;

  iVar7 = 0;

  iVar4 = 0;

  iVar8 = 0;

  local_res8 = param_1;

  local_res10 = param_2;

  do {

    if (iVar2 == iVar7) {

      uVar3 = FUN_140130020(&local_res8,2);

      iVar2 = FUN_14012e880(uVar3,local_38);

      puVar6 = local_38;

      iVar7 = 1;

    }

    else {

      lVar5 = (longlong)iVar7;

      iVar7 = iVar7 + 1;

      puVar6 = local_38 + lVar5;

    }

    uVar1 = *puVar6;

    if (iVar4 == iVar8) {

      uVar3 = FUN_140130020(&local_res10,2);

      iVar4 = FUN_14012e880(uVar3,local_28);

      puVar6 = local_28;

      iVar8 = 1;

    }

    else {

      lVar5 = (longlong)iVar8;

      iVar8 = iVar8 + 1;

      puVar6 = local_28 + lVar5;

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




