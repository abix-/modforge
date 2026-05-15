// Address: 0x140042950
// Ghidra name: FUN_140042950
// ============ 0x140042950 FUN_140042950 (size=474) ============


int FUN_140042950(longlong param_1)



{

  undefined4 *puVar1;

  int iVar2;

  int iVar3;

  int iVar4;

  size_t sVar5;

  uint uVar6;

  int iVar7;

  int local_res8 [2];

  undefined4 local_res10 [2];

  undefined4 local_res18;

  undefined2 local_res1c;

  

  if (*(char *)(param_1 + 0x5c) != '\0') {

    *(undefined4 *)(param_1 + 0x9c) = 2;

    return 0;

  }

  if (*(int *)(param_1 + 0x374) != 0) goto LAB_140042b11;

  if (*(longlong *)(param_1 + 0x40) == 0) {

    iVar2 = *(int *)(param_1 + 0x38);

    iVar7 = FUN_1402cf00c(*(undefined8 *)(param_1 + 0x30));

    iVar7 = iVar7 - iVar2;

  }

  else {

    iVar7 = (int)*(longlong *)(param_1 + 0x40) - *(int *)(param_1 + 0x48);

  }

  if ((*(uint *)(param_1 + 0x58) < 0x10000) ||

     (uVar6 = *(uint *)(param_1 + 0x58) - 0x10000, uVar6 < *(uint *)(param_1 + 0x60))) {

    uVar6 = *(uint *)(param_1 + 0x60);

  }

  FUN_140050920(param_1,uVar6);

  iVar2 = FUN_140054a60(param_1,local_res10,local_res8);

  if (iVar2 == 0) {

LAB_1400429ea:

    *(undefined4 *)(param_1 + 0x9c) = 0x24;

    iVar3 = -1;

  }

  else {

    iVar2 = FUN_1400410f0(param_1);

    while (local_res8[0] == 0) {

      FUN_140050920(param_1,local_res10[0]);

      iVar3 = FUN_140054a60(param_1,local_res10,local_res8);

      if (iVar3 == 0) break;

      if (*(char *)(param_1 + 0x5c) == '\0') {

        if (*(longlong *)(param_1 + 0x40) == 0) {

          iVar3 = *(int *)(param_1 + 0x38);

          iVar2 = FUN_1402cf00c(*(undefined8 *)(param_1 + 0x30));

          iVar2 = iVar2 - iVar3;

        }

        else {

          iVar2 = (int)*(longlong *)(param_1 + 0x40) - *(int *)(param_1 + 0x48);

        }

      }

      else {

        iVar2 = 0;

      }

    }

    FUN_140050920(param_1,iVar2);

    puVar1 = *(undefined4 **)(param_1 + 0x40);

    if (puVar1 == (undefined4 *)0x0) {

      sVar5 = fread(&local_res18,6,1,*(FILE **)(param_1 + 0x30));

      if (sVar5 != 1) goto LAB_140042ab1;

    }

    else if (*(ulonglong *)(param_1 + 0x50) < (longlong)puVar1 + 6U) {

LAB_140042ab1:

      *(undefined4 *)(param_1 + 0x98) = 1;

    }

    else {

      local_res18 = *puVar1;

      local_res1c = *(undefined2 *)(puVar1 + 1);

      *(ulonglong *)(param_1 + 0x40) = (longlong)puVar1 + 6U;

    }

    iVar3 = FUN_14004c8a0(param_1);

    iVar4 = FUN_14004c8a0(param_1);

    if ((iVar3 == -1) && (iVar4 == -1)) goto LAB_1400429ea;

    *(int *)(param_1 + 0x70) = iVar2;

    if (iVar4 != 0) {

      iVar3 = -2;

    }

    *(undefined4 *)(param_1 + 0x74) = local_res10[0];

    *(int *)(param_1 + 0x78) = iVar3;

  }

  *(int *)(param_1 + 0x374) = iVar3;

  FUN_140050920(param_1,iVar7);

LAB_140042b11:

  iVar2 = 0;

  if (*(int *)(param_1 + 0x374) != -1) {

    iVar2 = *(int *)(param_1 + 0x374);

  }

  return iVar2;

}




