// Address: 0x1401e0170
// Ghidra name: FUN_1401e0170
// ============ 0x1401e0170 FUN_1401e0170 (size=1474) ============


undefined1 FUN_1401e0170(longlong param_1,longlong param_2)



{

  undefined8 *puVar1;

  char *pcVar2;

  longlong lVar3;

  char cVar4;

  undefined1 uVar5;

  int iVar6;

  int iVar7;

  undefined4 uVar8;

  longlong *plVar9;

  undefined8 uVar10;

  code *pcVar11;

  longlong lVar12;

  longlong lVar13;

  int local_res8 [2];

  int local_res10;

  longlong local_res18;

  longlong local_res20;

  int local_a8;

  int local_a4;

  int local_a0;

  int local_9c;

  undefined4 local_98;

  undefined4 local_94;

  float local_88 [6];

  undefined8 local_70;

  undefined8 local_68;

  undefined8 local_60;

  undefined4 local_58;

  undefined8 local_54;

  undefined4 local_4c;

  

  lVar3 = *(longlong *)(param_2 + 0x30);

  lVar12 = *(longlong *)(param_1 + 0x160);

  local_res10 = *(int *)(param_2 + 0x2c);

  if ((lVar3 == lVar12) && (*(char *)(param_1 + 400) == '\0')) {

    if (lVar3 != 0) {

      lVar12 = *(longlong *)(lVar3 + 0x138);

      if (lVar12 != 0) {

        FUN_1401e0860(*(undefined8 *)(param_1 + 0x10),lVar12);

        if (*(longlong *)(lVar3 + 0xe0) != 0) {

          FUN_1401e0860(*(undefined8 *)(param_1 + 0x10),

                        *(undefined8 *)(*(longlong *)(lVar3 + 0xe0) + 0x10));

        }

        if (*(char *)(lVar12 + 0x48) != '\0') {

          FUN_1401e0860(*(undefined8 *)(param_1 + 0x10),lVar12 + 0x50);

          FUN_1401e0860(*(undefined8 *)(param_1 + 0x10),lVar12 + 0x78);

        }

      }

LAB_1401e03db:

      FUN_1401e09f0(param_1,*(undefined4 *)(param_2 + 0x38),0);

      FUN_1401e0950(param_1,*(undefined4 *)(param_2 + 0x3c),*(undefined4 *)(param_2 + 0x40),0);

      if ((*(longlong *)(lVar3 + 0x138) != 0) &&

         (*(char *)(*(longlong *)(lVar3 + 0x138) + 0x48) != '\0')) {

        FUN_1401e09f0(param_1,*(undefined4 *)(param_2 + 0x38),1);

        FUN_1401e09f0(param_1,*(undefined4 *)(param_2 + 0x38),2);

        FUN_1401e0950(param_1,*(undefined4 *)(param_2 + 0x3c),*(undefined4 *)(param_2 + 0x40),1);

        FUN_1401e0950(param_1,*(undefined4 *)(param_2 + 0x3c),*(undefined4 *)(param_2 + 0x40),2);

      }

    }

  }

  else {

    lVar13 = 0;

    if (lVar12 != 0) {

      lVar13 = *(longlong *)(lVar12 + 0x138);

    }

    local_res8[0] = 0;

    local_res20 = 0;

    if (lVar3 == 0) {

      local_res18 = 0;

      (**(code **)(**(longlong **)(param_1 + 0x10) + 0x208))(*(longlong **)(param_1 + 0x10),0,0);

LAB_1401e026f:

      if (((lVar13 != 0) && (*(longlong *)(*(longlong *)(param_1 + 0x160) + 0xe0) != 0)) ||

         (*(char *)(param_1 + 400) != '\0')) {

        (**(code **)(**(longlong **)(param_1 + 0x10) + 0x208))(*(longlong **)(param_1 + 0x10),1,0);

      }

      if (local_res18 != 0) goto LAB_1401e02af;

LAB_1401e02b5:

      if (((lVar13 != 0) && (*(char *)(lVar13 + 0x48) != '\0')) ||

         (*(char *)(param_1 + 400) != '\0')) {

        (**(code **)(**(longlong **)(param_1 + 0x10) + 0x208))(*(longlong **)(param_1 + 0x10),1,0);

        (**(code **)(**(longlong **)(param_1 + 0x10) + 0x208))(*(longlong **)(param_1 + 0x10),2,0);

      }

    }

    else {

      local_res18 = *(longlong *)(lVar3 + 0x138);

      if ((local_res18 == 0) || (*(longlong *)(lVar3 + 0xe0) == 0)) goto LAB_1401e026f;

LAB_1401e02af:

      if (*(char *)(local_res18 + 0x48) == '\0') goto LAB_1401e02b5;

    }

    lVar12 = 0;

    iVar7 = 0;

    if ((lVar3 != 0) &&

       (cVar4 = FUN_1401e0740(param_1,lVar3,*(undefined4 *)(param_2 + 0x38),local_res8,&local_res20)

       , lVar12 = local_res20, iVar7 = local_res8[0], cVar4 == '\0')) {

      return 0;

    }

    pcVar2 = (char *)(param_1 + 400);

    if ((iVar7 != *(int *)(param_1 + 0x184)) || (*pcVar2 != '\0')) {

      iVar6 = (**(code **)(**(longlong **)(param_1 + 0x10) + 0x358))

                        (*(longlong **)(param_1 + 0x10),

                         *(undefined8 *)(param_1 + 0xa0 + (longlong)iVar7 * 8));

      if (iVar6 < 0) {

        uVar5 = FUN_1401df290("IDirect3DDevice9_SetPixelShader()",iVar6);

        return uVar5;

      }

      *(int *)(param_1 + 0x184) = iVar7;

    }

    if ((lVar12 != *(longlong *)(param_1 + 0x188)) || (*pcVar2 != '\0')) {

      if ((lVar12 != 0) &&

         (iVar7 = (**(code **)(**(longlong **)(param_1 + 0x10) + 0x368))

                            (*(longlong **)(param_1 + 0x10),0,lVar12,4), iVar7 < 0)) {

        uVar5 = FUN_1401df290("IDirect3DDevice9_SetPixelShaderConstantF()",iVar7);

        return uVar5;

      }

      *(longlong *)(param_1 + 0x188) = lVar12;

    }

    *(longlong *)(param_1 + 0x160) = lVar3;

    *pcVar2 = '\0';

    if (lVar3 != 0) goto LAB_1401e03db;

  }

  iVar7 = local_res10;

  puVar1 = (undefined8 *)(param_1 + 0x10);

  if (local_res10 == *(int *)(param_1 + 0x168)) goto LAB_1401e0593;

  plVar9 = (longlong *)*puVar1;

  uVar10 = 0x1b;

  pcVar11 = *(code **)(*plVar9 + 0x1c8);

  if (local_res10 == 0) {

    uVar8 = 0;

LAB_1401e0589:

    (*pcVar11)(plVar9,uVar10,uVar8);

  }

  else {

    (*pcVar11)(plVar9,0x1b,1);

    uVar8 = FUN_14014df00(iVar7);

    uVar8 = FUN_1401e0080(uVar8);

    (**(code **)(*(longlong *)*puVar1 + 0x1c8))((longlong *)*puVar1,0x13,uVar8);

    uVar8 = FUN_14014dec0(iVar7);

    uVar8 = FUN_1401e0080(uVar8);

    (**(code **)(*(longlong *)*puVar1 + 0x1c8))((longlong *)*puVar1,0x14,uVar8);

    uVar8 = FUN_14014de80(iVar7);

    uVar8 = FUN_1401e0040(uVar8);

    (**(code **)(*(longlong *)*puVar1 + 0x1c8))((longlong *)*puVar1,0xab,uVar8);

    if (*(char *)(param_1 + 0x62) != '\0') {

      uVar8 = FUN_14014dee0(iVar7);

      uVar8 = FUN_1401e0080(uVar8);

      (**(code **)(*(longlong *)*puVar1 + 0x1c8))((longlong *)*puVar1,0xcf,uVar8);

      uVar8 = FUN_14014dea0(iVar7);

      uVar8 = FUN_1401e0080(uVar8);

      (**(code **)(*(longlong *)*puVar1 + 0x1c8))((longlong *)*puVar1,0xd0,uVar8);

      uVar8 = FUN_14014de60(iVar7);

      uVar8 = FUN_1401e0040(uVar8);

      plVar9 = (longlong *)*puVar1;

      pcVar11 = *(code **)(*plVar9 + 0x1c8);

      uVar10 = 0xd1;

      goto LAB_1401e0589;

    }

  }

  *(int *)(param_1 + 0x168) = iVar7;

LAB_1401e0593:

  if (*(char *)(param_1 + 0x158) != '\0') {

    local_a8 = *(int *)(param_1 + 0x148);

    local_a4 = *(undefined4 *)(param_1 + 0x14c);

    local_a0 = *(undefined4 *)(param_1 + 0x150);

    local_9c = *(undefined4 *)(param_1 + 0x154);

    local_98 = 0;

    local_94 = 0x3f800000;

    (**(code **)(*(longlong *)*puVar1 + 0x178))((longlong *)*puVar1,&local_a8);

    if ((*(int *)(param_1 + 0x150) != 0) && (*(int *)(param_1 + 0x154) != 0)) {

      local_88[1] = 0.0;

      local_88[2] = 0.0;

      local_88[3] = 0.0;

      local_88[4] = 0.0;

      local_70 = 0;

      local_68 = 0;

      local_88[0] = DAT_14030374c / (float)*(int *)(param_1 + 0x150);

      local_60 = 0x3f800000;

      local_54 = 0x3f800000;

      local_58 = 0xbf800000;

      local_4c = 0x3f800000;

      local_88[5] = DAT_140304c68 / (float)*(int *)(param_1 + 0x154);

      (**(code **)(*(longlong *)*puVar1 + 0x160))((longlong *)*puVar1,3,local_88);

    }

    *(undefined1 *)(param_1 + 0x158) = 0;

  }

  if (*(char *)(param_1 + 0x16d) != '\0') {

    (**(code **)(*(longlong *)*puVar1 + 0x1c8))

              ((longlong *)*puVar1,0xae,*(char *)(param_1 + 0x16c) != '\0');

    *(undefined1 *)(param_1 + 0x16d) = 0;

  }

  if (*(char *)(param_1 + 0x180) != '\0') {

    local_a8 = *(int *)(param_1 + 0x170) + *(int *)(param_1 + 0x148);

    local_a4 = *(int *)(param_1 + 0x174) + *(int *)(param_1 + 0x14c);

    local_a0 = *(int *)(param_1 + 0x178) + *(int *)(param_1 + 0x170) + *(int *)(param_1 + 0x148);

    local_9c = *(int *)(param_1 + 0x17c) + *(int *)(param_1 + 0x174) + *(int *)(param_1 + 0x14c);

    (**(code **)(**(longlong **)(param_1 + 0x10) + 600))(*(longlong **)(param_1 + 0x10),&local_a8);

    *(undefined1 *)(param_1 + 0x180) = 0;

  }

  return 1;

}




