// Address: 0x14022ade0
// Ghidra name: FUN_14022ade0
// ============ 0x14022ade0 FUN_14022ade0 (size=434) ============


void FUN_14022ade0(longlong param_1,char param_2)



{

  int iVar1;

  int iVar2;

  uint uVar3;

  undefined4 uVar4;

  longlong lVar5;

  longlong lVar6;

  int iVar7;

  int iVar8;

  int iVar9;

  int iVar10;

  int iVar11;

  bool bVar12;

  int local_38;

  int local_34;

  int local_30;

  int local_2c;

  

  if ((*(uint *)(param_1 + 0x48) & 0xc0000) != 0) {

    bVar12 = *(char *)(param_1 + 0x10b) == '\0';

    lVar5 = 0x8c;

    if (bVar12) {

      lVar5 = 0x7c;

    }

    iVar10 = *(int *)(lVar5 + param_1);

    lVar5 = 0x90;

    if (bVar12) {

      lVar5 = 0x80;

    }

    bVar12 = *(char *)(param_1 + 0x10c) == '\0';

    lVar6 = 0x94;

    if (bVar12) {

      lVar6 = 0x84;

    }

    iVar1 = *(int *)(lVar6 + param_1);

    lVar6 = 0x98;

    if (bVar12) {

      lVar6 = 0x88;

    }

    iVar8 = 0;

    iVar9 = 0;

    iVar2 = *(int *)(lVar6 + param_1);

    iVar11 = *(int *)(lVar5 + param_1);

    if (*(char *)(param_1 + 0x10e) != '\0') {

      lVar6 = *(longlong *)(param_1 + 0x1a8);

      uVar3 = *(uint *)(lVar6 + 0x48);

      while ((uVar3 & 0xc0000) != 0) {

        iVar9 = iVar9 + *(int *)(lVar6 + 0x18);

        iVar8 = iVar8 + *(int *)(lVar6 + 0x1c);

        lVar6 = *(longlong *)(lVar6 + 0x1a8);

        uVar3 = *(uint *)(lVar6 + 0x48);

      }

      iVar9 = iVar9 + *(int *)(lVar6 + 0x18);

      iVar8 = iVar8 + *(int *)(lVar6 + 0x1c);

      iVar11 = iVar9 + iVar10;

      iVar7 = iVar8 + *(int *)(lVar5 + param_1);

      uVar4 = FUN_14016d540();

      FUN_14016d280(uVar4,&local_38);

      if (local_30 + local_38 < iVar11 + iVar1) {

        iVar11 = (local_30 - iVar1) + local_38;

      }

      if (local_2c + local_34 < iVar2 + iVar7) {

        iVar7 = (local_2c - iVar2) + local_34;

      }

      iVar10 = local_38;

      if (local_38 < iVar11) {

        iVar10 = iVar11;

      }

      iVar11 = local_34;

      if (local_34 < iVar7) {

        iVar11 = iVar7;

      }

    }

    if (param_2 != '\0') {

      *(int *)(param_1 + 0x94) = iVar1;

      *(int *)(param_1 + 0x98) = iVar2;

      *(int *)(param_1 + 0x8c) = iVar10 - iVar9;

      *(int *)(param_1 + 0x90) = iVar11 - iVar8;

      return;

    }

    *(int *)(param_1 + 0x84) = iVar1;

    *(int *)(param_1 + 0x88) = iVar2;

    *(int *)(param_1 + 0x7c) = iVar10 - iVar9;

    *(int *)(param_1 + 0x80) = iVar11 - iVar8;

  }

  return;

}




