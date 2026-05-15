// Address: 0x1401e8370
// Ghidra name: FUN_1401e8370
// ============ 0x1401e8370 FUN_1401e8370 (size=767) ============


undefined8

FUN_1401e8370(longlong param_1,uint *param_2,int *param_3,longlong *param_4,undefined4 *param_5)



{

  longlong lVar1;

  longlong *plVar2;

  int iVar3;

  undefined4 uVar4;

  undefined8 uVar5;

  longlong lVar6;

  char *pcVar7;

  uint uVar8;

  longlong local_res8;

  undefined8 local_b8;

  undefined8 local_b0;

  undefined8 local_a8;

  undefined4 local_a0;

  undefined8 local_9c;

  undefined8 local_94;

  undefined4 local_8c;

  undefined8 local_88;

  undefined4 local_80;

  undefined8 local_7c;

  undefined4 local_74;

  undefined4 local_70;

  undefined8 local_68;

  undefined8 uStack_60;

  longlong local_58;

  undefined8 uStack_50;

  undefined8 local_48;

  undefined8 uStack_40;

  undefined8 local_38;

  

  lVar1 = *(longlong *)(param_2 + 0x4e);

  lVar6 = *(longlong *)(param_1 + 0x2e0);

  if (lVar1 == 0) {

    uVar5 = FUN_14012e850("Texture is not currently available");

  }

  else if ((*(char *)(lVar1 + 0x50) == '\0') && (*(char *)(lVar1 + 0x98) == '\0')) {

    if (*(longlong *)(lVar1 + 0x38) == 0) {

      local_68 = 0;

      uStack_60 = 0;

      local_58 = 0;

      uStack_50 = 0;

      local_38 = 0;

      local_48 = 0;

      uStack_40 = 0;

      (**(code **)(**(longlong **)(lVar1 + 8) + 0x50))(*(longlong **)(lVar1 + 8),&local_68);

      local_58 = (longlong)param_3[2];

      uStack_50 = CONCAT44(uStack_50._4_4_,param_3[3]);

      local_b8 = 1;

      local_a8 = 0;

      local_88 = 0;

      local_b0 = 0x10000;

      local_a0 = 1;

      local_9c = 0x10001;

      local_94 = 1;

      local_8c = 1;

      uVar4 = 0;

      (**(code **)(**(longlong **)(lVar6 + 0x30) + 0x130))

                (*(longlong **)(lVar6 + 0x30),&local_68,0,1,0,0,0,0,&local_a8);

      local_7c = 0;

      local_80 = 2;

      local_74 = 1;

      local_70 = 1;

      iVar3 = (**(code **)(**(longlong **)(lVar6 + 0x30) + 0xd8))

                        (*(longlong **)(lVar6 + 0x30),&local_80,0,&local_b8,CONCAT44(uVar4,0xac3),0,

                         &DAT_14034bc60,(undefined8 *)(lVar1 + 0x38));

      if (iVar3 < 0) {

        pcVar7 = "ID3D12Device::CreateCommittedResource [create upload buffer]";

      }

      else {

        plVar2 = *(longlong **)(lVar1 + 0x38);

        iVar3 = (**(code **)(*plVar2 + 0x40))(plVar2,0,0,&local_res8);

        if (-1 < iVar3) {

          iVar3 = 4;

          if ((int)local_48 == 0x3d) {

            iVar3 = 1;

          }

          uVar4 = FUN_1401c5ab0(iVar3 * param_3[2],0x100);

          uVar5 = *(undefined8 *)(param_3 + 2);

          *(undefined8 *)(lVar1 + 0xbc) = *(undefined8 *)param_3;

          *(undefined8 *)(lVar1 + 0xc4) = uVar5;

          *param_4 = local_res8;

          *param_5 = uVar4;

          return 1;

        }

        plVar2 = *(longlong **)(lVar6 + 0x2158 + (longlong)*(int *)(lVar6 + 0x2258) * 8);

        if (plVar2 != (longlong *)0x0) {

          (**(code **)(*plVar2 + 0x10))();

          *(undefined8 *)(lVar6 + 0x2158 + (longlong)*(int *)(lVar6 + 0x2258) * 8) = 0;

        }

        pcVar7 = "ID3D12Resource::Map [map staging texture]";

      }

      uVar5 = FUN_1401a9ef0(pcVar7,iVar3);

    }

    else {

      uVar5 = FUN_14012e850("texture is already locked");

    }

  }

  else {

    lVar6 = *(longlong *)(lVar1 + 0xb0);

    if (lVar6 == 0) {

      uVar8 = param_2[1];

      *(uint *)(lVar1 + 0xb8) = uVar8;

      lVar6 = FUN_1401841f0((longlong)((int)(uVar8 * param_2[2] * 3) / 2));

      *(longlong *)(lVar1 + 0xb0) = lVar6;

      if (lVar6 == 0) {

        return 0;

      }

    }

    uVar5 = *(undefined8 *)(param_3 + 2);

    *(undefined8 *)(lVar1 + 0xbc) = *(undefined8 *)param_3;

    *(undefined8 *)(lVar1 + 0xc4) = uVar5;

    uVar8 = *param_2;

    if ((uVar8 == 0) || ((uVar8 & 0xf0000000) == 0x10000000)) {

      uVar8 = uVar8 & 0xff;

    }

    else if ((((uVar8 == 0x32595559) || (uVar8 == 0x59565955)) || (uVar8 == 0x55595659)) ||

            (uVar8 == 0x30313050)) {

      uVar8 = 2;

    }

    else {

      uVar8 = 1;

    }

    *param_4 = (longlong)(int)(uVar8 * *param_3) + param_3[1] * *(int *)(lVar1 + 0xb8) + lVar6;

    *param_5 = *(undefined4 *)(lVar1 + 0xb8);

    uVar5 = 1;

  }

  return uVar5;

}




