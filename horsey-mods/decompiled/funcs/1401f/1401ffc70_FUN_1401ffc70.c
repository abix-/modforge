// Address: 0x1401ffc70
// Ghidra name: FUN_1401ffc70
// ============ 0x1401ffc70 FUN_1401ffc70 (size=804) ============


undefined4 FUN_1401ffc70(longlong param_1)



{

  int iVar1;

  int iVar2;

  int iVar3;

  longlong lVar4;

  undefined8 uVar5;

  char cVar6;

  int iVar7;

  undefined4 uVar8;

  undefined8 *puVar9;

  uint uVar10;

  uint uStack_138;

  float local_108;

  float local_104;

  float local_100;

  float local_fc;

  undefined4 local_f8;

  undefined4 local_f4;

  undefined4 local_e8;

  uint uStack_e4;

  undefined4 uStack_e0;

  undefined4 uStack_dc;

  uint local_d8;

  undefined4 uStack_d4;

  undefined4 uStack_d0;

  undefined4 uStack_cc;

  undefined8 local_c8;

  undefined8 uStack_c0;

  undefined8 local_b8;

  undefined8 uStack_b0;

  float local_a8 [6];

  undefined4 uStack_90;

  undefined4 uStack_8c;

  undefined8 local_88;

  undefined8 uStack_80;

  undefined8 local_78;

  undefined8 uStack_70;

  undefined1 local_68 [96];

  

  lVar4 = *(longlong *)(param_1 + 0x2e0);

  iVar7 = FUN_1401fa5d0(lVar4);

  if ((*(int *)(lVar4 + 0x291c) == 0) || (*(int *)(lVar4 + 0x2920) == 0)) {

    uVar8 = 0;

  }

  else {

    if ((iVar7 == 1) || (((iVar7 != 2 && (iVar7 != 4)) && (iVar7 != 8)))) {

      local_e8 = 0x3f800000;

      uStack_138 = 0;

      uVar10 = 0;

    }

    else {

      uVar10 = thunk_FUN_1402cdc50();

      local_e8 = thunk_FUN_1402cfda0();

      uStack_138 = uVar10 ^ DAT_14039cac0;

    }

    uStack_cc = 0;

    uStack_d0 = 0;

    uStack_dc = 0;

    uStack_e0 = 0;

    local_b8 = 0;

    uStack_b0 = 0x3f80000000000000;

    uStack_c0 = 0x3f800000;

    local_a8[5] = DAT_140304c68 / (float)*(int *)(lVar4 + 0x2920);

    local_a8[0] = DAT_14030374c / (float)*(int *)(lVar4 + 0x291c);

    local_a8[4] = 0.0;

    uStack_90 = 0;

    uStack_8c = 0;

    local_78 = 0x3f800000bf800000;

    uStack_70 = 0x3f80000000000000;

    local_a8[1] = 0.0;

    local_a8[2] = 0.0;

    local_a8[3] = 0.0;

    uStack_80 = 0x3f800000;

    local_c8 = 0;

    local_88 = 0;

    uStack_e4 = uVar10;

    local_d8 = uStack_138;

    uStack_d4 = local_e8;

    puVar9 = (undefined8 *)FUN_1401e5740(local_68,local_a8,&local_e8,local_a8[5],local_e8);

    uVar5 = puVar9[1];

    *(undefined8 *)(lVar4 + 0x2798) = *puVar9;

    *(undefined8 *)(lVar4 + 0x27a0) = uVar5;

    uVar5 = puVar9[3];

    *(undefined8 *)(lVar4 + 0x27a8) = puVar9[2];

    *(undefined8 *)(lVar4 + 0x27b0) = uVar5;

    uVar5 = puVar9[5];

    *(undefined8 *)(lVar4 + 0x27b8) = puVar9[4];

    *(undefined8 *)(lVar4 + 0x27c0) = uVar5;

    uVar5 = puVar9[7];

    *(undefined8 *)(lVar4 + 0x27c8) = puVar9[6];

    *(undefined8 *)(lVar4 + 0x27d0) = uVar5;

    cVar6 = FUN_1401fabe0(iVar7);

    if (cVar6 == '\0') {

      iVar7 = *(int *)(lVar4 + 0x2914);

      iVar1 = *(int *)(lVar4 + 0x2918);

      iVar2 = *(int *)(lVar4 + 0x291c);

      iVar3 = *(int *)(lVar4 + 0x2920);

    }

    else {

      iVar7 = *(int *)(lVar4 + 0x2918);

      iVar1 = *(int *)(lVar4 + 0x2914);

      iVar2 = *(int *)(lVar4 + 0x2920);

      iVar3 = *(int *)(lVar4 + 0x291c);

    }

    local_100 = (float)iVar2;

    local_104 = (float)iVar1;

    local_108 = (float)iVar7;

    local_fc = (float)iVar3;

    local_f8 = 0;

    local_f4 = 0x3f800000;

    (*DAT_1403fcf30)(*(undefined8 *)(lVar4 + 0x698),0,1,&local_108);

    uVar8 = 1;

    *(undefined1 *)(lVar4 + 0x2928) = 0;

  }

  return uVar8;

}




