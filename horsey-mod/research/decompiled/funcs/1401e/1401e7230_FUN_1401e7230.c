// Address: 0x1401e7230
// Ghidra name: FUN_1401e7230
// ============ 0x1401e7230 FUN_1401e7230 (size=1531) ============


undefined8 FUN_1401e7230(longlong param_1,int *param_2,undefined4 param_3)



{

  longlong *plVar1;

  int iVar2;

  longlong lVar3;

  char cVar4;

  int iVar5;

  undefined4 uVar6;

  undefined8 uVar7;

  undefined4 *puVar8;

  longlong lVar9;

  undefined4 local_c8;

  undefined8 local_c4;

  undefined4 local_bc;

  ulonglong local_b8;

  uint local_b0;

  uint local_ac;

  int local_a8;

  undefined4 local_a4;

  undefined8 local_a0;

  ulonglong local_98;

  undefined4 local_90;

  undefined8 local_8c;

  undefined4 local_84;

  undefined4 local_80;

  int local_78;

  undefined4 uStack_74;

  undefined4 uStack_70;

  undefined4 uStack_6c;

  undefined4 uStack_68;

  uint uStack_64;

  undefined4 uStack_60;

  undefined4 uStack_5c;

  undefined8 local_58;

  int local_50;

  undefined4 uStack_4c;

  undefined4 uStack_48;

  undefined4 uStack_44;

  undefined4 uStack_40;

  uint uStack_3c;

  undefined8 uStack_38;

  undefined8 uStack_30;

  

  lVar3 = *(longlong *)(param_1 + 0x2e0);

  iVar5 = FUN_1401eb330(*param_2,*(undefined4 *)(param_1 + 0x208));

  if (*(longlong *)(lVar3 + 0x30) == 0) {

    uVar7 = FUN_14012e850("Device lost and couldn\'t be recovered");

    return uVar7;

  }

  if (iVar5 == 0) {

    uVar7 = FUN_14012e850("%s, An unsupported SDL pixel format (0x%x) was specified",

                          "D3D12_CreateTexture");

    return uVar7;

  }

  puVar8 = (undefined4 *)FUN_1401841a0(1,0xd0);

  if (puVar8 == (undefined4 *)0x0) {

    return 0;

  }

  *(undefined4 **)(param_2 + 0x4e) = puVar8;

  puVar8[0xc] = iVar5;

  local_b8 = (ulonglong)param_2[1];

  iVar2 = *param_2;

  local_b0 = param_2[2];

  local_c4 = 0;

  local_bc = 0;

  local_a0 = 0;

  local_ac = 0x10001;

  local_a4 = 1;

  local_c8 = 3;

  if (((iVar2 == 0x3231564e) || (iVar2 == 0x3132564e)) || (iVar2 == 0x30313050)) {

    local_b8 = local_b8 + 1 & 0xfffffffffffffffe;

    local_b0 = local_b0 + 1 & 0xfffffffe;

  }

  plVar1 = (longlong *)(puVar8 + 2);

  *puVar8 = (undefined4)local_b8;

  puVar8[1] = local_b0;

  local_90 = 1;

  local_84 = 1;

  local_80 = 1;

  local_98 = (ulonglong)(param_2[9] == 2);

  local_8c = 0;

  local_a8 = iVar5;

  cVar4 = FUN_1401eb220(param_3,"SDL.texture.create.d3d12.texture",plVar1);

  if (cVar4 == '\0') {

    return 0;

  }

  if ((*plVar1 == 0) &&

     (iVar5 = (**(code **)(**(longlong **)(lVar3 + 0x30) + 0xd8))

                        (*(longlong **)(lVar3 + 0x30),&local_90,0,&local_c8,0x400,0,&DAT_14034bc60,

                         plVar1), iVar5 < 0)) goto LAB_1401e7517;

  lVar9 = *plVar1;

  puVar8[6] = 0x400;

  uVar6 = FUN_14014f530(param_2);

  FUN_140175480(uVar6,"SDL.texture.d3d12.texture",lVar9);

  if ((*param_2 == 0x32315659) || (*param_2 == 0x56555949)) {

    *(undefined1 *)(puVar8 + 0x14) = 1;

    plVar1 = (longlong *)(puVar8 + 0x16);

    local_b8 = local_b8 + 1 >> 1;

    local_b0 = local_b0 + 1 >> 1;

    cVar4 = FUN_1401eb220(param_3,"SDL.texture.create.d3d12.texture_u",plVar1);

    if (cVar4 == '\0') {

      return 0;

    }

    if ((*plVar1 == 0) &&

       (iVar5 = (**(code **)(**(longlong **)(lVar3 + 0x30) + 0xd8))

                          (*(longlong **)(lVar3 + 0x30),&local_90,0,&local_c8,0x400,0,&DAT_14034bc60

                           ,plVar1), iVar5 < 0)) {

LAB_1401e7517:

      uVar7 = FUN_1401a9ef0("ID3D12Device::CreateCommittedResource [texture]",iVar5);

      return uVar7;

    }

    lVar9 = *plVar1;

    puVar8[0x1a] = 0x400;

    uVar6 = FUN_14014f530(param_2);

    FUN_140175480(uVar6,"SDL.texture.d3d12.texture_u",lVar9);

    plVar1 = (longlong *)(puVar8 + 0x1e);

    cVar4 = FUN_1401eb220(param_3,"SDL.texture.create.d3d12.texture_v",plVar1);

    if (cVar4 == '\0') {

      return 0;

    }

    if ((*plVar1 == 0) &&

       (iVar5 = (**(code **)(**(longlong **)(lVar3 + 0x30) + 0xd8))

                          (*(longlong **)(lVar3 + 0x30),&local_90,0,&local_c8,0x400,0,&DAT_14034bc60

                           ,plVar1), iVar5 < 0)) goto LAB_1401e7517;

    lVar9 = *plVar1;

    puVar8[0x22] = 0x400;

    uVar6 = FUN_14014f530(param_2);

    FUN_140175480(uVar6,"SDL.texture.d3d12.texture_v",lVar9);

    lVar9 = FUN_14017b8d0(param_2[6],param_2[1],param_2[2],8);

    *(longlong *)(puVar8 + 0x12) = lVar9;

    if (lVar9 == 0) goto LAB_1401e75b3;

  }

  iVar5 = *param_2;

  if (((iVar5 == 0x3231564e) || (iVar5 == 0x3132564e)) || (iVar5 == 0x30313050)) {

    *(undefined1 *)(puVar8 + 0x26) = 1;

    uVar6 = 8;

    if (*param_2 == 0x30313050) {

      uVar6 = 10;

    }

    lVar9 = FUN_14017b8d0(param_2[6],param_2[1],param_2[2],uVar6);

    *(longlong *)(puVar8 + 0x12) = lVar9;

    if (lVar9 == 0) {

LAB_1401e75b3:

      uVar7 = FUN_14012e850("Unsupported YUV colorspace");

      return uVar7;

    }

  }

  uStack_44 = 0;

  uStack_40 = 0;

  uStack_38 = 0;

  uStack_30 = 0;

  uStack_48 = 0x1688;

  local_50 = FUN_1401eb280(*param_2,*(undefined4 *)(param_1 + 0x208));

  uStack_3c = local_ac >> 0x10;

  uStack_4c = 4;

  (**(code **)(**(longlong **)(lVar3 + 0x80) + 0x48))(*(longlong **)(lVar3 + 0x80),puVar8 + 4);

  lVar9 = FUN_1401e7e70(param_1);

  *(longlong *)(puVar8 + 8) = lVar9;

  *(ulonglong *)(puVar8 + 4) =

       *(longlong *)(puVar8 + 4) + (ulonglong)*(uint *)(lVar3 + 0x88) * lVar9;

  (**(code **)(**(longlong **)(lVar3 + 0x30) + 0x90))

            (*(longlong **)(lVar3 + 0x30),*(undefined8 *)(puVar8 + 2),&local_50,

             *(undefined8 *)(puVar8 + 4));

  if (*(char *)(puVar8 + 0x14) != '\0') {

    (**(code **)(**(longlong **)(lVar3 + 0x80) + 0x48))(*(longlong **)(lVar3 + 0x80),puVar8 + 0x18);

    lVar9 = FUN_1401e7e70(param_1);

    *(longlong *)(puVar8 + 0x1c) = lVar9;

    *(ulonglong *)(puVar8 + 0x18) =

         *(longlong *)(puVar8 + 0x18) + (ulonglong)*(uint *)(lVar3 + 0x88) * lVar9;

    (**(code **)(**(longlong **)(lVar3 + 0x30) + 0x90))

              (*(longlong **)(lVar3 + 0x30),*(undefined8 *)(puVar8 + 0x16),&local_50,

               *(undefined8 *)(puVar8 + 0x18));

    (**(code **)(**(longlong **)(lVar3 + 0x80) + 0x48))(*(longlong **)(lVar3 + 0x80),puVar8 + 0x20);

    lVar9 = FUN_1401e7e70(param_1);

    *(longlong *)(puVar8 + 0x24) = lVar9;

    *(ulonglong *)(puVar8 + 0x20) =

         *(longlong *)(puVar8 + 0x20) + (ulonglong)*(uint *)(lVar3 + 0x88) * lVar9;

    (**(code **)(**(longlong **)(lVar3 + 0x30) + 0x90))

              (*(longlong **)(lVar3 + 0x30),*(undefined8 *)(puVar8 + 0x1e),&local_50,

               *(undefined8 *)(puVar8 + 0x20));

  }

  if (*(char *)(puVar8 + 0x26) != '\0') {

    iVar5 = *param_2;

    local_78 = local_50;

    uStack_74 = uStack_4c;

    uStack_70 = uStack_48;

    uStack_6c = uStack_44;

    local_58 = uStack_30;

    uStack_68 = uStack_40;

    uStack_64 = uStack_3c;

    uStack_5c = uStack_38._4_4_;

    if ((iVar5 == 0x3231564e) || (iVar5 == 0x3132564e)) {

      local_78 = 0x31;

    }

    else if (iVar5 == 0x30313050) {

      local_78 = 0x23;

    }

    uStack_60 = 1;

    (**(code **)(**(longlong **)(lVar3 + 0x80) + 0x48))(*(longlong **)(lVar3 + 0x80),puVar8 + 0x28);

    lVar9 = FUN_1401e7e70(param_1);

    *(longlong *)(puVar8 + 0x2a) = lVar9;

    *(ulonglong *)(puVar8 + 0x28) =

         *(longlong *)(puVar8 + 0x28) + (ulonglong)*(uint *)(lVar3 + 0x88) * lVar9;

    (**(code **)(**(longlong **)(lVar3 + 0x30) + 0x90))

              (*(longlong **)(lVar3 + 0x30),*(undefined8 *)(puVar8 + 2),&local_78,

               *(undefined8 *)(puVar8 + 0x28));

  }

  if ((*(byte *)(param_2 + 9) & 2) != 0) {

    uStack_6c = 0;

    uStack_68 = 0;

    uStack_64 = 0;

    local_78 = local_a8;

    uStack_74 = 4;

    uStack_70 = 0;

    (**(code **)(**(longlong **)(lVar3 + 0x78) + 0x48))(*(longlong **)(lVar3 + 0x78),puVar8 + 10);

    *(ulonglong *)(puVar8 + 10) =

         *(longlong *)(puVar8 + 10) + (ulonglong)*(uint *)(lVar3 + 0x70) * *(longlong *)(puVar8 + 8)

    ;

    (**(code **)(**(longlong **)(lVar3 + 0x30) + 0xa0))

              (*(longlong **)(lVar3 + 0x30),*(undefined8 *)(puVar8 + 2),&local_78,

               *(undefined8 *)(puVar8 + 10));

  }

  return 1;

}




