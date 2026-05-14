// Address: 0x1401e5390
// Ghidra name: FUN_1401e5390
// ============ 0x1401e5390 FUN_1401e5390 (size=808) ============


undefined8 FUN_1401e5390(longlong param_1)



{

  longlong lVar1;

  int iVar2;

  undefined8 uVar3;

  undefined8 *puVar4;

  longlong lVar5;

  int iVar6;

  int *piVar7;

  uint uVar8;

  float local_118;

  float local_114;

  float local_110;

  float local_10c;

  undefined4 local_108;

  undefined4 local_104;

  undefined4 local_f8;

  uint uStack_f4;

  undefined4 uStack_f0;

  undefined4 uStack_ec;

  uint local_e8;

  undefined4 uStack_e4;

  undefined4 uStack_e0;

  undefined4 uStack_dc;

  undefined8 local_d8;

  undefined8 uStack_d0;

  undefined8 local_c8;

  undefined8 uStack_c0;

  float local_b8 [3];

  undefined4 uStack_ac;

  undefined4 local_a8;

  float fStack_a4;

  undefined4 uStack_a0;

  undefined4 uStack_9c;

  undefined8 local_98;

  undefined8 uStack_90;

  undefined8 local_88;

  undefined8 uStack_80;

  undefined1 local_78 [96];

  

  lVar1 = *(longlong *)(param_1 + 0x2e0);

  iVar2 = FUN_1401e2310();

  piVar7 = (int *)(lVar1 + 0x43c);

  if ((*piVar7 == 0) || (*(int *)(lVar1 + 0x440) == 0)) {

    uVar3 = 0;

  }

  else {

    if (iVar2 == 1) {

      local_e8 = 0;

      uVar8 = 0;

      local_f8 = 0x3f800000;

    }

    else {

      if (((iVar2 != 2) && (iVar2 != 3)) && (iVar2 != 4)) {

        uVar3 = FUN_14012e850("An unknown DisplayOrientation is being used");

        return uVar3;

      }

      uVar8 = thunk_FUN_1402cdc50();

      local_f8 = thunk_FUN_1402cfda0();

      local_e8 = uVar8 ^ DAT_14039cac0;

    }

    uStack_dc = 0;

    uStack_e0 = 0;

    uStack_ec = 0;

    uStack_f0 = 0;

    local_a8 = 0;

    local_c8 = 0;

    uStack_c0 = 0x3f80000000000000;

    local_b8[2] = 0.0;

    uStack_d0 = 0x3f800000;

    fStack_a4 = DAT_140304c68 / (float)*(int *)(lVar1 + 0x440);

    uStack_a0 = 0;

    uStack_9c = 0;

    local_b8[0] = DAT_14030374c / (float)*piVar7;

    local_88 = 0x3f800000bf800000;

    uStack_80 = 0x3f80000000000000;

    local_b8[1] = 0.0;

    uStack_ac = 0;

    uStack_90 = 0x3f800000;

    local_d8 = 0;

    local_98 = 0;

    uStack_f4 = uVar8;

    uStack_e4 = local_f8;

    puVar4 = (undefined8 *)FUN_1401e5740(local_78,local_b8,&local_f8,fStack_a4,local_b8[0],0,0,0);

    uVar3 = puVar4[1];

    *(undefined8 *)(lVar1 + 0x1b0) = *puVar4;

    *(undefined8 *)(lVar1 + 0x1b8) = uVar3;

    uVar3 = puVar4[3];

    *(undefined8 *)(lVar1 + 0x1c0) = puVar4[2];

    *(undefined8 *)(lVar1 + 0x1c8) = uVar3;

    uVar3 = puVar4[5];

    *(undefined8 *)(lVar1 + 0x1d0) = puVar4[4];

    *(undefined8 *)(lVar1 + 0x1d8) = uVar3;

    uVar3 = puVar4[7];

    *(undefined8 *)(lVar1 + 0x1e0) = puVar4[6];

    *(undefined8 *)(lVar1 + 0x1e8) = uVar3;

    iVar2 = FUN_1401e2710(iVar2);

    if (iVar2 == 0) {

      iVar2 = *(int *)(lVar1 + 0x438);

      piVar7 = (int *)(lVar1 + 0x440);

      iVar6 = *(int *)(lVar1 + 0x434);

      lVar5 = 8;

    }

    else {

      iVar2 = *(int *)(lVar1 + 0x434);

      lVar5 = 0xc;

      iVar6 = *(int *)(lVar1 + 0x438);

    }

    local_108 = 0;

    local_104 = 0x3f800000;

    local_110 = (float)*(int *)(lVar5 + 0x434 + lVar1);

    local_10c = (float)*piVar7;

    local_118 = (float)iVar6;

    local_114 = (float)iVar2;

    (**(code **)(**(longlong **)(lVar1 + 0x28) + 0x160))(*(longlong **)(lVar1 + 0x28),1,&local_118);

    uVar3 = 1;

    *(undefined1 *)(lVar1 + 0x448) = 0;

  }

  return uVar3;

}




