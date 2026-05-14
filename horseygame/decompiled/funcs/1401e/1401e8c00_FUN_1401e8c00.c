// Address: 0x1401e8c00
// Ghidra name: FUN_1401e8c00
// ============ 0x1401e8c00 FUN_1401e8c00 (size=965) ============


undefined8 FUN_1401e8c00(longlong param_1,longlong param_2)



{

  longlong lVar1;

  char cVar2;

  int iVar3;

  uint uVar4;

  undefined4 uVar5;

  undefined4 uVar6;

  undefined8 uVar7;

  undefined4 uVar8;

  longlong *plVar9;

  longlong *local_res8;

  undefined8 local_res10;

  ulonglong uVar10;

  longlong **pplVar11;

  undefined8 uVar12;

  undefined8 local_158;

  undefined8 uStack_150;

  undefined4 local_148;

  undefined4 uStack_144;

  undefined4 uStack_140;

  undefined4 uStack_13c;

  undefined4 local_138;

  undefined4 local_134;

  undefined4 local_130;

  undefined4 local_12c;

  undefined4 local_128;

  undefined4 local_124;

  undefined8 local_120;

  undefined8 local_118;

  undefined8 local_110;

  undefined4 local_108;

  undefined8 local_104;

  undefined8 local_fc;

  undefined4 local_f4;

  undefined8 local_f0;

  undefined4 local_e8;

  undefined8 local_e4;

  undefined4 local_dc;

  undefined4 local_d8;

  undefined8 local_d0;

  undefined8 uStack_c8;

  longlong local_c0;

  undefined8 uStack_b8;

  ulonglong local_b0;

  undefined8 uStack_a8;

  undefined8 local_a0;

  longlong *local_98;

  undefined8 local_90;

  undefined4 local_88;

  undefined8 local_84;

  undefined8 uStack_7c;

  undefined8 local_74;

  undefined4 local_6c;

  longlong *local_68;

  undefined8 local_60;

  undefined8 local_58;

  undefined8 uStack_50;

  undefined4 local_48;

  undefined4 uStack_44;

  undefined4 uStack_40;

  undefined4 uStack_3c;

  

  uVar7 = 0;

  lVar1 = *(longlong *)(param_1 + 0x2e0);

  local_res8 = (longlong *)0x0;

  local_158 = 0;

  uStack_150 = 0;

  if (*(longlong *)(lVar1 + 0x422b0) == 0) {

    plVar9 = *(longlong **)(lVar1 + 0xb0 + (longlong)*(int *)(lVar1 + 200) * 8);

  }

  else {

    plVar9 = *(longlong **)(*(longlong *)(lVar1 + 0x422b0) + 8);

  }

  local_a0 = 0;

  local_d0 = 0;

  uStack_c8 = 0;

  local_c0 = 0;

  uStack_b8 = 0;

  local_b0 = 0;

  uStack_a8 = 0;

  (**(code **)(*plVar9 + 0x50))(plVar9,&local_d0);

  local_c0 = (longlong)*(int *)(param_2 + 8);

  uStack_b8 = CONCAT44(uStack_b8._4_4_,*(undefined4 *)(param_2 + 0xc));

  local_120 = 1;

  local_110 = 0;

  local_f0 = 0;

  local_118 = 0x10000;

  local_108 = 1;

  local_104 = 0x10001;

  local_fc = 1;

  local_f4 = 1;

  uVar8 = 0;

  (**(code **)(**(longlong **)(lVar1 + 0x30) + 0x130))

            (*(longlong **)(lVar1 + 0x30),&local_d0,0,1,0,0,0,0,&local_110);

  local_e4 = 0;

  local_e8 = 3;

  local_dc = 1;

  local_d8 = 1;

  uVar10 = CONCAT44(uVar8,0x400);

  iVar3 = (**(code **)(**(longlong **)(lVar1 + 0x30) + 0xd8))

                    (*(longlong **)(lVar1 + 0x30),&local_e8,0,&local_120,uVar10,0,&DAT_14034bc60,

                     &local_res8);

  if (iVar3 < 0) {

    FUN_1401a9ef0("ID3D12Device::CreateTexture2D [create staging texture]",iVar3);

  }

  else {

    FUN_1401ea070(lVar1,plVar9,4,0x800);

    cVar2 = FUN_1401e80a0(param_1,param_2,&local_158,0);

    if (cVar2 != '\0') {

      local_138 = (undefined4)local_158;

      local_12c = (undefined4)uStack_150;

      local_134 = local_158._4_4_;

      local_128 = uStack_150._4_4_;

      local_130 = 0;

      local_124 = 1;

      uVar8 = (undefined4)local_b0;

      uVar4 = FUN_1401e2030(local_b0 & 0xffffffff);

      if ((uVar4 == 0) || ((uVar4 & 0xf0000000) == 0x10000000)) {

        uVar4 = uVar4 & 0xff;

      }

      else if ((((uVar4 == 0x32595559) || (uVar4 == 0x59565955)) || (uVar4 == 0x55595659)) ||

              (uVar4 == 0x30313050)) {

        uVar4 = 2;

      }

      else {

        uVar4 = 1;

      }

      iVar3 = (int)local_c0;

      uVar5 = FUN_1401c5ab0(uVar4 * (int)local_c0,0x100);

      local_60 = 1;

      local_148 = (undefined4)uStack_b8;

      local_68 = local_res8;

      local_90 = 0;

      local_74 = 0;

      local_6c = 0;

      local_88 = 0;

      uStack_150 = CONCAT44(iVar3,uVar8);

      local_158 = 0;

      uStack_13c = 0;

      local_58 = 0;

      uStack_50 = uStack_150;

      uStack_144 = 1;

      local_84 = 0;

      uStack_7c = 0;

      local_48 = (undefined4)uStack_b8;

      uStack_44 = 1;

      uStack_3c = 0;

      pplVar11 = &local_98;

      uStack_140 = uVar5;

      local_98 = plVar9;

      uStack_40 = uVar5;

      (**(code **)(**(longlong **)(lVar1 + 0x48) + 0x80))

                (*(longlong **)(lVar1 + 0x48),&local_68,0,0,uVar10 & 0xffffffff00000000,pplVar11,

                 &local_138);

      uVar8 = (undefined4)((ulonglong)pplVar11 >> 0x20);

      FUN_1401e82f0(lVar1);

      FUN_1401ea070(lVar1,plVar9,0x800,4);

      iVar3 = (**(code **)(*local_res8 + 0x40))(local_res8,0,0,&local_res10);

      if (iVar3 < 0) {

        FUN_1401a9ef0("ID3D12Resource::Map [map staging texture]",iVar3);

      }

      else {

        uVar6 = FUN_1401e2030(local_b0 & 0xffffffff);

        uVar12 = CONCAT44(uVar8,uVar5);

        uVar7 = FUN_1401460c0(*(undefined4 *)(param_2 + 8),*(undefined4 *)(param_2 + 0xc),uVar6);

        (**(code **)(*local_res8 + 0x48))

                  (local_res8,0,0,*(code **)(*local_res8 + 0x48),local_res10,uVar12);

      }

    }

  }

  if (local_res8 != (longlong *)0x0) {

    (**(code **)(*local_res8 + 0x10))();

  }

  return uVar7;

}




