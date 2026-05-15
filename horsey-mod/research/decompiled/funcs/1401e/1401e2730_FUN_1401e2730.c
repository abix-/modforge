// Address: 0x1401e2730
// Ghidra name: FUN_1401e2730
// ============ 0x1401e2730 FUN_1401e2730 (size=536) ============


undefined8

FUN_1401e2730(longlong param_1,uint *param_2,int *param_3,longlong *param_4,undefined4 *param_5)



{

  longlong lVar1;

  longlong *plVar2;

  int iVar3;

  undefined8 uVar4;

  longlong lVar5;

  char *pcVar6;

  uint uVar7;

  longlong local_58;

  undefined4 local_50;

  int local_48;

  int local_44;

  undefined8 local_2c;

  undefined8 local_24;

  

  lVar1 = *(longlong *)(param_2 + 0x4e);

  lVar5 = *(longlong *)(param_1 + 0x2e0);

  if (lVar1 == 0) {

    uVar4 = FUN_14012e850("Texture is not currently available");

  }

  else if ((*(char *)(lVar1 + 0x38) == '\0') && (*(char *)(lVar1 + 0x60) == '\0')) {

    if (*(longlong *)(lVar1 + 0x20) == 0) {

      (**(code **)(**(longlong **)(lVar1 + 8) + 0x50))(*(longlong **)(lVar1 + 8),&local_48);

      local_48 = param_3[2];

      local_44 = param_3[3];

      local_2c = 3;

      local_24 = 0x10000;

      plVar2 = *(longlong **)(lVar5 + 0x20);

      iVar3 = (**(code **)(*plVar2 + 0x28))(plVar2,&local_48,0,lVar1 + 0x20);

      if (iVar3 < 0) {

        pcVar6 = "ID3D11Device1::CreateTexture2D [create staging texture]";

      }

      else {

        plVar2 = *(longlong **)(lVar5 + 0x28);

        iVar3 = (**(code **)(*plVar2 + 0x70))(plVar2,*(undefined8 *)(lVar1 + 0x20),0,2,0,&local_58);

        if (-1 < iVar3) {

          *(int *)(lVar1 + 0x28) = *param_3;

          *(int *)(lVar1 + 0x2c) = param_3[1];

          *param_4 = local_58;

          *param_5 = local_50;

          return 1;

        }

        if (*(longlong **)(lVar1 + 0x20) != (longlong *)0x0) {

          (**(code **)(**(longlong **)(lVar1 + 0x20) + 0x10))();

          *(undefined8 *)(lVar1 + 0x20) = 0;

        }

        pcVar6 = "ID3D11DeviceContext1::Map [map staging texture]";

      }

      uVar4 = FUN_1401a9ef0(pcVar6,iVar3);

    }

    else {

      uVar4 = FUN_14012e850("texture is already locked");

    }

  }

  else {

    lVar5 = *(longlong *)(lVar1 + 0x70);

    if (lVar5 == 0) {

      uVar7 = param_2[1];

      *(uint *)(lVar1 + 0x78) = uVar7;

      lVar5 = FUN_1401841f0((longlong)((int)(uVar7 * param_2[2] * 3) / 2));

      *(longlong *)(lVar1 + 0x70) = lVar5;

      if (lVar5 == 0) {

        return 0;

      }

    }

    uVar4 = *(undefined8 *)(param_3 + 2);

    *(undefined8 *)(lVar1 + 0x7c) = *(undefined8 *)param_3;

    *(undefined8 *)(lVar1 + 0x84) = uVar4;

    uVar7 = *param_2;

    if ((uVar7 == 0) || ((uVar7 & 0xf0000000) == 0x10000000)) {

      uVar7 = uVar7 & 0xff;

    }

    else if ((((uVar7 == 0x32595559) || (uVar7 == 0x59565955)) || (uVar7 == 0x55595659)) ||

            (uVar7 == 0x30313050)) {

      uVar7 = 2;

    }

    else {

      uVar7 = 1;

    }

    *param_4 = (longlong)(int)(uVar7 * *param_3) + param_3[1] * *(int *)(lVar1 + 0x78) + lVar5;

    *param_5 = *(undefined4 *)(lVar1 + 0x78);

    uVar4 = 1;

  }

  return uVar4;

}




