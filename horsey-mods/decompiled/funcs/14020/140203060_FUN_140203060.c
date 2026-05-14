// Address: 0x140203060
// Ghidra name: FUN_140203060
// ============ 0x140203060 FUN_140203060 (size=1031) ============


void FUN_140203060(longlong param_1,longlong param_2,undefined4 param_3,undefined4 param_4,

                  int param_5)



{

  longlong lVar1;

  undefined8 uVar2;

  int *piVar3;

  undefined8 *puVar4;

  longlong lVar5;

  longlong lVar6;

  uint uVar7;

  undefined4 *puVar8;

  undefined8 uVar9;

  int iVar10;

  undefined8 local_108;

  undefined8 local_100;

  undefined4 local_f8 [2];

  undefined4 local_f0;

  int local_ec;

  undefined4 local_e8;

  undefined4 local_e4;

  int local_e0;

  undefined4 local_dc;

  longlong local_d8;

  undefined8 local_d0;

  undefined4 local_c8;

  undefined4 local_c4;

  undefined4 local_b8;

  float local_b4;

  float local_b0;

  float local_98;

  

  if ((*(longlong *)(param_1 + 0x90) == 0) || (*(int *)(param_1 + 200) == 1)) {

    FUN_1402057f0();

  }

  lVar1 = *(longlong *)(param_2 + 0x48);

  uVar2 = *(undefined8 *)(param_1 + 0x90);

  if (lVar1 == 0) {

    lVar6 = 0;

  }

  else {

    lVar6 = *(longlong *)(lVar1 + 0x10);

  }

  local_f8[0] = *(undefined4 *)(param_2 + 0x18);

  if (param_5 == 0) {

    piVar3 = *(int **)(param_2 + 0x30);

    if (piVar3 == (int *)0x0) {

      local_e8 = 1;

      goto LAB_14020317c;

    }

    FUN_140202ca0(*(undefined8 *)(piVar3 + 4),param_2,piVar3,&local_b8);

    if ((((local_b4 == DAT_14039ca44) || (local_b4 == DAT_14030338c)) && (local_b0 == 0.0)) &&

       (local_98 == 0.0)) {

      if ((*piVar3 == 0x16762004) || (*piVar3 == 0x16362004)) {

        iVar10 = 2;

        local_e8 = 2;

      }

      else {

        local_e8 = 2;

        iVar10 = 1;

      }

    }

    else {

      local_e8 = 2;

      iVar10 = 3;

    }

  }

  else {

    local_e8 = 0;

LAB_14020317c:

    iVar10 = 0;

  }

  if (lVar6 != 0) {

    iVar10 = 4;

    *(longlong *)(param_1 + 0x48) = lVar6;

  }

  local_f0 = *(undefined4 *)(param_2 + 0x2c);

  local_dc = 0;

  local_e0 = param_5;

  if (*(longlong *)(param_1 + 0x98) == 0) {

    local_e4 = *(undefined4 *)(param_1 + 0x60);

  }

  else {

    local_e4 = *(undefined4 *)(*(longlong *)(*(longlong *)(param_1 + 0x98) + 0x138) + 0x10);

  }

  local_ec = iVar10;

  local_d8 = lVar6;

  lVar6 = FUN_1402634c0(param_1 + 0x50,param_1 + 0x10,*(undefined8 *)(param_1 + 8),&local_f0);

  if (lVar6 == 0) {

    return;

  }

  FUN_140133940(uVar2,lVar6);

  puVar8 = *(undefined4 **)(param_2 + 0x30);

  uVar7 = 0;

  if (puVar8 == (undefined4 *)0x0) goto LAB_140203340;

  lVar6 = *(longlong *)(puVar8 + 0x4e);

  local_100 = FUN_140205530(param_1,*puVar8,*(undefined4 *)(param_2 + 0x38),

                            *(undefined4 *)(param_2 + 0x3c),*(undefined4 *)(param_2 + 0x40));

  local_108 = *(undefined8 *)(lVar6 + 8);

  FUN_140133610(uVar2,0,&local_108,1);

  uVar7 = 1;

  if (iVar10 != 3) goto LAB_140203340;

  if (*(longlong *)(puVar8 + 0x38) == 0) {

    if (*(char *)(lVar6 + 0x40) != '\0') {

      local_108 = *(undefined8 *)(lVar6 + 0x48);

      FUN_140133610(uVar2,1,&local_108,1);

      local_108 = *(undefined8 *)(lVar6 + 0x50);

      FUN_140133610(uVar2,2,&local_108,1);

      uVar7 = 3;

      goto LAB_140203340;

    }

    if (*(char *)(lVar6 + 0x58) != '\0') {

      local_108 = *(undefined8 *)(lVar6 + 0x60);

      goto LAB_1402032fc;

    }

  }

  else {

    puVar4 = *(undefined8 **)(*(longlong *)(puVar8 + 0x38) + 0x10);

    local_100 = FUN_140205530(param_1,0,0,1,1);

    local_108 = *puVar4;

LAB_1402032fc:

    FUN_140133610(uVar2,1,&local_108,1);

    uVar7 = 2;

  }

  do {

    FUN_140133610(uVar2,uVar7,&local_108,1);

    uVar7 = uVar7 + 1;

  } while (uVar7 < 3);

LAB_140203340:

  if (lVar1 == 0) {

    if (iVar10 == 3) {

      uVar9 = 0x70;

      puVar8 = &local_b8;

    }

    else {

      uVar9 = 4;

      puVar8 = local_f8;

    }

    FUN_140137ce0(*(undefined8 *)(param_1 + 0xa0),0,puVar8,uVar9);

  }

  else {

    if (0 < *(int *)(lVar1 + 0x18)) {

      FUN_140133610(uVar2,uVar7,*(undefined8 *)(lVar1 + 0x20));

    }

    if (0 < *(int *)(lVar1 + 0x28)) {

      FUN_140133830(uVar2,0,*(undefined8 *)(lVar1 + 0x30));

    }

    if (0 < *(int *)(lVar1 + 0x38)) {

      FUN_140133720(uVar2,0,*(undefined8 *)(lVar1 + 0x40));

    }

    if (0 < *(int *)(lVar1 + 0x48)) {

      iVar10 = 0;

      lVar6 = 0;

      do {

        lVar5 = *(longlong *)(lVar1 + 0x50);

        FUN_140137ce0(*(undefined8 *)(param_1 + 0xa0),*(undefined4 *)(lVar6 + lVar5),

                      *(undefined8 *)(lVar6 + 8 + lVar5),*(undefined4 *)(lVar6 + 0x10 + lVar5));

        iVar10 = iVar10 + 1;

        lVar6 = lVar6 + 0x18;

      } while (iVar10 < *(int *)(lVar1 + 0x48));

    }

  }

  local_d0 = *(undefined8 *)(param_1 + 0x80);

  local_c4 = 0;

  local_c8 = param_4;

  FUN_140133a70(uVar2,0,&local_d0,1);

  FUN_140205710(param_1,param_2);

  FUN_140205850(param_1);

  FUN_140136560(uVar2,param_3,1,0,0);

  return;

}




