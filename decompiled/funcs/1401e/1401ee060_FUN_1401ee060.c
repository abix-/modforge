// Address: 0x1401ee060
// Ghidra name: FUN_1401ee060
// ============ 0x1401ee060 FUN_1401ee060 (size=526) ============


longlong FUN_1401ee060(longlong param_1,undefined4 *param_2)



{

  longlong lVar1;

  char cVar2;

  undefined8 uVar3;

  longlong lVar4;

  uint uVar5;

  uint uVar6;

  int iVar7;

  int local_res8 [2];

  undefined4 local_res18 [2];

  undefined4 local_res20 [2];

  undefined8 in_stack_ffffffffffffff98;

  undefined4 uVar8;

  undefined1 local_48 [8];

  longlong local_40;

  

  uVar8 = (undefined4)((ulonglong)in_stack_ffffffffffffff98 >> 0x20);

  lVar1 = *(longlong *)(param_1 + 0x2e0);

  if (*(uint **)(param_1 + 0x1f0) == (uint *)0x0) {

    uVar5 = 0x16762004;

  }

  else {

    uVar5 = **(uint **)(param_1 + 0x1f0);

  }

  local_40 = lVar1;

  FUN_1401ebd30();

  cVar2 = FUN_1401efcd0(uVar5,local_res8,local_res20,local_res18);

  if (cVar2 == '\0') {

    uVar3 = FUN_14017af90(uVar5);

    FUN_14012e850("Texture format %s not supported by OpenGL",uVar3);

    return 0;

  }

  lVar4 = FUN_140145e60(param_2[2],param_2[3],uVar5);

  if (lVar4 != 0) {

    iVar7 = param_2[1];

    if (*(longlong *)(param_1 + 0x1f0) == 0) {

      FUN_14014e850(param_1,local_48,local_res8);

      iVar7 = (local_res8[0] - iVar7) - param_2[3];

    }

    uVar6 = 1;

    (**(code **)(lVar1 + 0x120))(0xd05,1);

    lVar1 = local_40;

    if ((uVar5 == 0) || ((uVar5 & 0xf0000000) == 0x10000000)) {

      uVar6 = uVar5 & 0xff;

    }

    else if ((((uVar5 == 0x32595559) || (uVar5 == 0x59565955)) || (uVar5 == 0x55595659)) ||

            (uVar5 == 0x30313050)) {

      uVar6 = 2;

    }

    (**(code **)(local_40 + 0x120))

              (0xd02,(longlong)*(int *)(lVar4 + 0x10) / (longlong)(int)uVar6 & 0xffffffff);

    (**(code **)(lVar1 + 0x140))

              (*param_2,iVar7,param_2[2],param_2[3],CONCAT44(uVar8,local_res20[0]),local_res18[0],

               *(undefined8 *)(lVar4 + 0x18));

    cVar2 = FUN_1401ebd90("glReadPixels()",param_1,"SDL_render_gl.c",0x671,"GL_RenderReadPixels");

    if (cVar2 != '\0') {

      if (*(longlong *)(param_1 + 0x1f0) != 0) {

        return lVar4;

      }

      FUN_140146490(lVar4,2);

      return lVar4;

    }

    FUN_140146010(lVar4);

  }

  return 0;

}




