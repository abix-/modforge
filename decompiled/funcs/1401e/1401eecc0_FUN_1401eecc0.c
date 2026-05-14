// Address: 0x1401eecc0
// Ghidra name: FUN_1401eecc0
// ============ 0x1401eecc0 FUN_1401eecc0 (size=873) ============


void FUN_1401eecc0(longlong param_1,uint *param_2,int *param_3,longlong param_4,int param_5)



{

  undefined4 uVar1;

  undefined4 uVar2;

  longlong lVar3;

  undefined4 *puVar4;

  code *pcVar5;

  int iVar6;

  uint uVar7;

  

  lVar3 = *(longlong *)(param_1 + 0x2e0);

  uVar7 = *param_2;

  puVar4 = *(undefined4 **)(param_2 + 0x4e);

  uVar1 = *(undefined4 *)(lVar3 + 0x28);

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

  do {

    if (uVar7 != 0) goto LAB_1401eed71;

    iVar6 = FUN_14017f2a0(&DAT_1403e4ba8,"GL_UpdateTexture",

                          "C:\\dev\\SDL-3.4.4\\src\\render\\opengl\\SDL_render_gl.c",0x31c);

  } while (iVar6 == 0);

  if (iVar6 == 1) {

    pcVar5 = (code *)swi(3);

    (*pcVar5)();

    return;

  }

LAB_1401eed71:

  FUN_1401ebd30(param_1);

  *(undefined8 *)(lVar3 + 0x218) = 0;

  (**(code **)(lVar3 + 0x40))(uVar1,*puVar4);

  (**(code **)(lVar3 + 0x120))(0xcf5,1);

  (**(code **)(lVar3 + 0x120))(0xcf2,(longlong)param_5 / (longlong)(int)uVar7 & 0xffffffff);

  (**(code **)(lVar3 + 400))

            (uVar1,0,*param_3,param_3[1],param_3[2],param_3[3],puVar4[4],puVar4[5],param_4);

  if (*(char *)(puVar4 + 0x15) != '\0') {

    iVar6 = (param_5 + 1) / 2;

    (**(code **)(lVar3 + 0x120))(0xcf2,iVar6);

    param_4 = param_4 + param_5 * param_3[3];

    if (*param_2 == 0x32315659) {

      uVar2 = puVar4[0x18];

    }

    else {

      uVar2 = puVar4[0x16];

    }

    (**(code **)(lVar3 + 0x40))(uVar1,uVar2);

    (**(code **)(lVar3 + 400))

              (uVar1,0,*param_3 / 2,param_3[1] / 2,(param_3[2] + 1) / 2,(param_3[3] + 1) / 2,

               puVar4[4],puVar4[5],param_4);

    param_4 = param_4 + ((param_3[3] + 1) / 2) * iVar6;

    if (*param_2 == 0x32315659) {

      uVar2 = puVar4[0x16];

    }

    else {

      uVar2 = puVar4[0x18];

    }

    (**(code **)(lVar3 + 0x40))(uVar1,uVar2);

    (**(code **)(lVar3 + 400))

              (uVar1,0,*param_3 / 2,param_3[1] / 2,(param_3[2] + 1) / 2,(param_3[3] + 1) / 2,

               puVar4[4],puVar4[5],param_4);

  }

  if (*(char *)((longlong)puVar4 + 0x55) != '\0') {

    (**(code **)(lVar3 + 0x120))(0xcf2,(param_5 + 1) / 2);

    iVar6 = param_3[3];

    (**(code **)(lVar3 + 0x40))(uVar1,puVar4[0x16]);

    (**(code **)(lVar3 + 400))

              (uVar1,0,*param_3 / 2,param_3[1] / 2,(param_3[2] + 1) / 2,(param_3[3] + 1) / 2,0x190a,

               0x1401,param_5 * iVar6 + param_4);

  }

  FUN_1401ebd90("glTexSubImage2D()",param_1,"SDL_render_gl.c",0x34e);

  return;

}




