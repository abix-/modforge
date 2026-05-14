// Address: 0x140131550
// Ghidra name: FUN_140131550
// ============ 0x140131550 FUN_140131550 (size=714) ============


byte FUN_140131550(undefined8 *param_1)



{

  int iVar1;

  undefined4 uVar2;

  longlong lVar3;

  undefined8 *puVar4;

  undefined8 *puVar5;

  undefined8 *puVar6;

  undefined8 *puVar7;

  undefined8 *puVar8;

  undefined4 local_res8 [2];

  longlong local_res10;

  

  FUN_140179b40(*param_1);

  iVar1 = FUN_140138fe0(param_1 + 0x37);

  if (iVar1 != 0) {

    FUN_140179b60(*param_1);

    return 0;

  }

  iVar1 = *(int *)((longlong)param_1 + 0x1cc);

  if (iVar1 < 1) {

    FUN_140179b60(*param_1);

    return (byte)((uint)iVar1 >> 0x1f) ^ 1;

  }

  puVar6 = (undefined8 *)0x0;

  local_res8[0] = 0;

  local_res10 = 0;

  iVar1 = (*(code *)param_1[4])(param_1,param_1[0x12],&local_res10,local_res8);

  if (iVar1 != 2) {

    if (iVar1 != 1) {

      FUN_140179b60(*param_1);

      FUN_140130fb0(param_1);

      return 1;

    }

    goto LAB_1401317dc;

  }

  if (*(int *)(param_1 + 0xf) < 1) {

    if (param_1[0x31] == 0) goto LAB_14013160f;

    lVar3 = param_1[0x11];

    if (lVar3 == 0) {

      lVar3 = FUN_140149300();

      param_1[0x10] = local_res10;

      param_1[0x11] = lVar3;

    }

    puVar8 = (undefined8 *)param_1[0x31];

    puVar7 = (undefined8 *)param_1[0x12];

    local_res10 = local_res10 + (lVar3 - param_1[0x10]);

    puVar6 = (undefined8 *)*puVar8;

    param_1[0x31] = puVar8[2];

    puVar8[1] = local_res10;

  }

  else {

    *(int *)(param_1 + 0xf) = *(int *)(param_1 + 0xf) + -1;

LAB_14013160f:

    (*(code *)param_1[5])(param_1,param_1[0x12]);

    *(undefined8 *)(param_1[0x12] + 0x18) = 0;

    *(undefined4 *)(param_1[0x12] + 0x10) = 0;

    puVar7 = puVar6;

    puVar8 = puVar6;

  }

  FUN_140179b60(*param_1);

  if (puVar7 == (undefined8 *)0x0) {

    return 1;

  }

  if ((*(int *)(param_1 + 0x36) == 0) && (*(char *)((longlong)param_1 + 0x1b4) == '\0')) {

    *(undefined4 *)(puVar6 + 1) = *(undefined4 *)(puVar7 + 1);

    *(undefined4 *)((longlong)puVar6 + 0xc) = *(undefined4 *)((longlong)puVar7 + 0xc);

    puVar6[3] = puVar7[3];

    *(undefined4 *)(puVar6 + 2) = *(undefined4 *)(puVar7 + 2);

  }

  else {

    puVar4 = puVar7;

    if (*(int *)(param_1 + 0x36) == -1) {

      puVar4 = puVar6;

      if (*(char *)((longlong)param_1 + 0x1b4) != '\0') {

        puVar4 = (undefined8 *)param_1[0x13];

      }

      FUN_140199be0(puVar7,0,puVar4,0,0);

    }

    puVar5 = puVar4;

    if (*(char *)((longlong)param_1 + 0x1b4) != '\0') {

      puVar5 = puVar6;

      if (*(int *)(param_1 + 0x36) == 1) {

        puVar5 = (undefined8 *)param_1[0x13];

      }

      FUN_1401451c0(*(undefined4 *)(puVar4 + 1),*(undefined4 *)((longlong)puVar4 + 0xc),

                    *(undefined4 *)((longlong)puVar4 + 4),puVar4[3],*(undefined4 *)(puVar4 + 2),

                    *(undefined4 *)((longlong)puVar5 + 4),puVar5[3],*(undefined4 *)(puVar5 + 2));

    }

    if (*(int *)(param_1 + 0x36) == 1) {

      FUN_140199be0(puVar5,0,puVar6,0,0);

    }

    (*(code *)param_1[5])(param_1,puVar7);

  }

  puVar7[3] = 0;

  *(undefined4 *)(puVar7 + 2) = 0;

  uVar2 = FUN_140146bc0(puVar6);

  FUN_1401752f0(uVar2,"SDL.surface.rotation",local_res8[0]);

  FUN_140179b40(*param_1);

  puVar8[2] = param_1[0x2e];

  param_1[0x2e] = puVar8;

LAB_1401317dc:

  FUN_140179b60(*param_1);

  return 1;

}




