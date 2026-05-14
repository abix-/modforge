// Address: 0x1401f3fd0
// Ghidra name: FUN_1401f3fd0
// ============ 0x1401f3fd0 FUN_1401f3fd0 (size=782) ============


undefined8 FUN_1401f3fd0(longlong param_1,uint *param_2,int *param_3,longlong param_4,int param_5)



{

  undefined4 uVar1;

  int iVar2;

  longlong lVar3;

  undefined4 *puVar4;

  uint uVar5;

  int iVar6;

  undefined8 uVar7;

  undefined8 in_stack_ffffffffffffff98;

  undefined4 uVar8;

  

  uVar8 = (undefined4)((ulonglong)in_stack_ffffffffffffff98 >> 0x20);

  lVar3 = *(longlong *)(param_1 + 0x2e0);

  puVar4 = *(undefined4 **)(param_2 + 0x4e);

  FUN_1401f0320();

  if ((param_3[2] < 1) || (param_3[3] < 1)) {

    uVar7 = 1;

  }

  else {

    *(undefined8 *)(lVar3 + 0x278) = 0;

    (**(code **)(lVar3 + 0x28))(puVar4[2],*puVar4);

    uVar5 = *param_2;

    if ((uVar5 == 0) || ((uVar5 & 0xf0000000) == 0x10000000)) {

      uVar5 = uVar5 & 0xff;

    }

    else if ((((uVar5 == 0x32595559) || (uVar5 == 0x59565955)) || (uVar5 == 0x55595659)) ||

            (uVar5 == 0x30313050)) {

      uVar5 = 2;

    }

    else {

      uVar5 = 1;

    }

    uVar7 = CONCAT44(uVar8,param_3[2]);

    FUN_1401f3d60(lVar3,puVar4[2],*param_3,param_3[1],uVar7,param_3[3],puVar4[3],puVar4[4],param_4,

                  param_5,uVar5);

    uVar8 = (undefined4)((ulonglong)uVar7 >> 0x20);

    if (*(char *)(puVar4 + 9) == '\0') {

      if (*(char *)((longlong)puVar4 + 0x25) != '\0') {

        iVar2 = param_3[3];

        (**(code **)(lVar3 + 0x28))(puVar4[2],puVar4[0xc]);

        FUN_1401f3d60(lVar3,puVar4[2],*param_3 / 2,param_3[1] / 2,

                      CONCAT44(uVar8,(param_3[2] + 1) / 2),(param_3[3] + 1) / 2,0x190a,0x1401,

                      param_4 + param_5 * iVar2,((param_5 + 1) / 2) * 2,2);

      }

    }

    else {

      param_4 = param_4 + param_5 * param_3[3];

      if (*param_2 == 0x32315659) {

        uVar1 = puVar4[10];

      }

      else {

        uVar1 = puVar4[0xc];

      }

      (**(code **)(lVar3 + 0x28))(puVar4[2],uVar1);

      iVar6 = (param_5 + 1) / 2;

      uVar7 = CONCAT44(uVar8,(param_3[2] + 1) / 2);

      FUN_1401f3d60(lVar3,puVar4[2],*param_3 / 2,param_3[1] / 2,uVar7,(param_3[3] + 1) / 2,puVar4[3]

                    ,puVar4[4],param_4,iVar6,1);

      uVar8 = (undefined4)((ulonglong)uVar7 >> 0x20);

      iVar2 = param_3[3];

      if (*param_2 == 0x32315659) {

        uVar1 = puVar4[0xc];

      }

      else {

        uVar1 = puVar4[10];

      }

      (**(code **)(lVar3 + 0x28))(puVar4[2],uVar1);

      FUN_1401f3d60(lVar3,puVar4[2],*param_3 / 2,param_3[1] / 2,CONCAT44(uVar8,(param_3[2] + 1) / 2)

                    ,(param_3[3] + 1) / 2,puVar4[3],puVar4[4],param_4 + ((iVar2 + 1) / 2) * iVar6,

                    iVar6,1);

    }

    uVar7 = FUN_1401f4660("glTexSubImage2D()",param_1,"SDL_render_gles2.c",0x823,

                          "GLES2_UpdateTexture");

  }

  return uVar7;

}




