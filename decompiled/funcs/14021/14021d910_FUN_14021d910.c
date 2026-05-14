// Address: 0x14021d910
// Ghidra name: FUN_14021d910
// ============ 0x14021d910 FUN_14021d910 (size=427) ============


bool FUN_14021d910(byte *param_1,int *param_2,byte *param_3,int *param_4)



{

  int iVar1;

  longlong lVar2;

  bool bVar3;

  bool bVar4;

  bool bVar5;

  char cVar6;

  int iVar7;

  uint uVar8;

  

  bVar5 = false;

  bVar3 = true;

  bVar4 = false;

  if ((*param_3 & 2) != 0) {

    cVar6 = FUN_140146f20(param_3);

    if (cVar6 == '\0') {

      bVar3 = false;

    }

    else {

      bVar4 = true;

    }

  }

  if ((*param_1 & 2) != 0) {

    cVar6 = FUN_140146f20(param_1);

    if (cVar6 == '\0') {

      bVar3 = false;

      goto LAB_14021da7f;

    }

    bVar5 = true;

  }

  if (bVar3) {

    lVar2 = *(longlong *)(param_1 + 0xd8);

    if (*(byte *)(lVar2 + 4) < 8) {

      iVar7 = (uint)*(byte *)(lVar2 + 4) * *param_2;

      *(longlong *)(param_1 + 0x98) =

           (longlong)((int)(iVar7 + (iVar7 >> 0x1f & 7U)) >> 3) +

           (longlong)(param_2[1] * *(int *)(param_1 + 0x10)) + *(longlong *)(param_1 + 0x18);

      uVar8 = (uint)*(byte *)(lVar2 + 4) * *param_2 & 0x80000007;

      if ((int)uVar8 < 0) {

        uVar8 = (uVar8 - 1 | 0xfffffff8) + 1;

      }

      *(int *)(param_1 + 0xb0) = (int)uVar8 / (int)(uint)*(byte *)(lVar2 + 4);

    }

    else {

      *(longlong *)(param_1 + 0x98) =

           (longlong)(int)((uint)*(byte *)(lVar2 + 5) * *param_2) +

           (longlong)(param_2[1] * *(int *)(param_1 + 0x10)) + *(longlong *)(param_1 + 0x18);

    }

    iVar7 = param_2[2];

    *(int *)(param_1 + 0xa0) = iVar7;

    *(int *)(param_1 + 0xa4) = param_2[3];

    *(int *)(param_1 + 0xa8) = *(int *)(param_1 + 0x10);

    *(uint *)(param_1 + 0xac) = *(int *)(param_1 + 0x10) - (uint)*(byte *)(lVar2 + 5) * iVar7;

    *(longlong *)(param_1 + 0xc0) =

         (longlong)(int)((uint)*(byte *)(*(longlong *)(param_1 + 0xe8) + 5) * *param_4) +

         (longlong)(param_4[1] * *(int *)(param_3 + 0x10)) + *(longlong *)(param_3 + 0x18);

    iVar7 = param_4[2];

    *(int *)(param_1 + 200) = iVar7;

    *(int *)(param_1 + 0xcc) = param_4[3];

    iVar1 = *(int *)(param_3 + 0x10);

    *(int *)(param_1 + 0xd0) = iVar1;

    *(uint *)(param_1 + 0xd4) = iVar1 - (uint)*(byte *)(*(longlong *)(param_1 + 0xe8) + 5) * iVar7;

    (**(code **)(param_1 + 0x88))(param_1 + 0x90);

  }

LAB_14021da7f:

  if (bVar4) {

    FUN_1401489e0(param_3);

  }

  if (bVar5) {

    FUN_1401489e0(param_1);

  }

  return bVar3;

}




