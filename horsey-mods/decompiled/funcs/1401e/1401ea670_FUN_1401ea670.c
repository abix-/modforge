// Address: 0x1401ea670
// Ghidra name: FUN_1401ea670
// ============ 0x1401ea670 FUN_1401ea670 (size=885) ============


undefined8

FUN_1401ea670(longlong param_1,longlong *param_2,undefined4 param_3,undefined4 param_4,

             undefined4 param_5,int param_6,uint param_7,longlong param_8,uint param_9,

             undefined4 *param_10)



{

  longlong *plVar1;

  uint uVar2;

  longlong lVar3;

  int iVar4;

  undefined8 uVar5;

  uint uVar6;

  ulonglong uVar7;

  uint local_res8 [2];

  longlong *local_res10;

  undefined4 local_res18;

  undefined4 local_res20;

  undefined4 uVar9;

  ulonglong uVar8;

  undefined8 local_168;

  undefined8 local_160;

  undefined8 local_158;

  undefined4 local_150;

  undefined8 local_14c;

  undefined8 local_144;

  undefined4 local_13c;

  undefined8 local_138;

  longlong local_130;

  uint local_128 [2];

  longlong *local_120;

  undefined4 local_118;

  undefined8 local_114;

  undefined4 local_10c;

  undefined4 local_108;

  undefined8 local_100;

  undefined8 uStack_f8;

  ulonglong local_f0;

  undefined8 uStack_e8;

  undefined8 local_e0;

  undefined8 uStack_d8;

  undefined8 local_d0;

  longlong *local_c8;

  undefined8 local_c0;

  undefined4 local_b8;

  undefined8 local_b4;

  undefined8 uStack_ac;

  undefined8 local_a4;

  undefined4 local_9c;

  undefined4 local_98;

  undefined4 uStack_94;

  undefined4 uStack_90;

  undefined4 uStack_8c;

  undefined4 local_88;

  undefined4 uStack_84;

  uint uStack_80;

  undefined4 uStack_7c;

  undefined8 local_78;

  undefined4 local_70;

  undefined4 local_6c;

  undefined4 local_68;

  undefined4 uStack_64;

  undefined4 uStack_60;

  undefined4 uStack_5c;

  undefined4 local_58;

  undefined4 uStack_54;

  uint uStack_50;

  undefined4 uStack_4c;

  

  local_d0 = 0;

  local_100 = 0;

  uStack_f8 = 0;

  local_f0 = 0;

  uStack_e8 = 0;

  local_e0 = 0;

  uStack_d8 = 0;

  local_res10 = param_2;

  local_res18 = param_3;

  local_res20 = param_4;

  (**(code **)(*param_2 + 0x50))(param_2,&local_100);

  local_f0 = (ulonglong)param_6;

  if ((int)local_e0 - 0x67U < 2) {

    local_f0 = local_f0 + 1 & 0xfffffffffffffffe;

    param_7 = param_7 + 1 & 0xfffffffe;

  }

  uStack_e8 = CONCAT44(uStack_e8._4_4_,param_7);

  local_168 = 1;

  local_160 = 0x10000;

  local_158 = 0;

  local_138 = 0;

  local_150 = 1;

  local_14c = 0x10001;

  local_144 = 1;

  local_13c = 1;

  uVar9 = 0;

  (**(code **)(**(longlong **)(param_1 + 0x30) + 0x130))

            (*(longlong **)(param_1 + 0x30),&local_100,param_3,1,0,&local_98,local_res8,local_128,

             &local_158);

  uVar6 = uStack_80;

  uVar7 = (ulonglong)uStack_80;

  local_114 = 0;

  local_118 = 2;

  local_10c = 1;

  local_108 = 1;

  uVar8 = CONCAT44(uVar9,0xac3);

  iVar4 = (**(code **)(**(longlong **)(param_1 + 0x30) + 0xd8))

                    (*(longlong **)(param_1 + 0x30),&local_118,0,&local_168,uVar8,0,&DAT_14034bc60,

                     param_1 + ((longlong)*(int *)(param_1 + 0x2258) + 0x42b) * 8);

  if (iVar4 < 0) {

    uVar5 = FUN_1401a9ef0("ID3D12Device::CreateCommittedResource [create upload buffer]",iVar4);

  }

  else {

    local_120 = *(longlong **)(param_1 + 0x2158 + (longlong)*(int *)(param_1 + 0x2258) * 8);

    iVar4 = (**(code **)(*local_120 + 0x40))(local_120,0,0,&local_130);

    if (iVar4 < 0) {

      plVar1 = *(longlong **)(param_1 + 0x2158 + (longlong)*(int *)(param_1 + 0x2258) * 8);

      if (plVar1 != (longlong *)0x0) {

        (**(code **)(*plVar1 + 0x10))();

        *(undefined8 *)(param_1 + 0x2158 + (longlong)*(int *)(param_1 + 0x2258) * 8) = 0;

      }

      uVar5 = FUN_1401a9ef0("ID3D12Resource::Map [map staging texture]",iVar4);

    }

    else {

      if ((local_128[0] == param_9) && (local_128[0] == uVar6)) {

        FUN_1402f8e20(local_130,param_8,(ulonglong)local_128[0] * (ulonglong)local_res8[0]);

      }

      else {

        if (param_9 < local_128[0]) {

          local_128[0] = param_9;

        }

        uVar2 = local_res8[0];

        lVar3 = local_130;

        if (local_128[0] <= uVar6) {

          uVar6 = local_128[0];

        }

        for (; uVar2 != 0; uVar2 = uVar2 - 1) {

          FUN_1402f8e20(lVar3,param_8,uVar6);

          param_8 = param_8 + (int)param_9;

          param_2 = local_res10;

          lVar3 = lVar3 + uVar7;

        }

      }

      (**(code **)(*local_120 + 0x48))(local_120,0,0);

      FUN_1401ea070(param_1,param_2,*param_10,0x400);

      local_b8 = local_res18;

      *param_10 = 0x400;

      local_b4 = 0;

      uStack_ac = 0;

      local_c0 = 0;

      local_a4 = 0;

      local_9c = 0;

      local_6c = 0;

      local_78 = *(undefined8 *)(param_1 + 0x2158 + (longlong)*(int *)(param_1 + 0x2258) * 8);

      local_70 = 1;

      local_68 = local_98;

      uStack_64 = uStack_94;

      uStack_60 = uStack_90;

      uStack_5c = uStack_8c;

      local_58 = local_88;

      uStack_54 = uStack_84;

      uStack_50 = uStack_80;

      uStack_4c = uStack_7c;

      local_c8 = param_2;

      (**(code **)(**(longlong **)(param_1 + 0x48) + 0x80))

                (*(longlong **)(param_1 + 0x48),&local_c8,local_res20,param_5,

                 uVar8 & 0xffffffff00000000,&local_78,0);

      FUN_1401ea070(param_1,param_2,*param_10,0x80);

      *param_10 = 0x80;

      *(int *)(param_1 + 0x2258) = *(int *)(param_1 + 0x2258) + 1;

      if (*(int *)(param_1 + 0x2258) == 0x20) {

        FUN_1401e82f0(param_1);

      }

      uVar5 = 1;

    }

  }

  return uVar5;

}




