// Address: 0x1401f4450
// Ghidra name: FUN_1401f4450
// ============ 0x1401f4450 FUN_1401f4450 (size=489) ============


undefined8

FUN_1401f4450(longlong param_1,longlong param_2,int *param_3,undefined8 param_4,undefined4 param_5,

             undefined8 param_6,undefined4 param_7,undefined8 param_8,undefined4 param_9)



{

  longlong lVar1;

  undefined4 *puVar2;

  undefined8 uVar3;

  undefined8 in_stack_ffffffffffffffb8;

  undefined4 uVar4;

  

  uVar4 = (undefined4)((ulonglong)in_stack_ffffffffffffffb8 >> 0x20);

  lVar1 = *(longlong *)(param_1 + 0x2e0);

  puVar2 = *(undefined4 **)(param_2 + 0x138);

  FUN_1401f0320();

  if ((param_3[2] < 1) || (param_3[3] < 1)) {

    uVar3 = 1;

  }

  else {

    *(undefined8 *)(lVar1 + 0x278) = 0;

    (**(code **)(lVar1 + 0x28))(puVar2[2],puVar2[10]);

    uVar3 = CONCAT44(uVar4,(param_3[2] + 1) / 2);

    FUN_1401f3d60(lVar1,puVar2[2],*param_3 / 2,param_3[1] / 2,uVar3,(param_3[3] + 1) / 2,puVar2[3],

                  puVar2[4],param_8,param_9,1);

    uVar4 = (undefined4)((ulonglong)uVar3 >> 0x20);

    (**(code **)(lVar1 + 0x28))(puVar2[2],puVar2[0xc]);

    uVar3 = CONCAT44(uVar4,(param_3[2] + 1) / 2);

    FUN_1401f3d60(lVar1,puVar2[2],*param_3 / 2,param_3[1] / 2,uVar3,(param_3[3] + 1) / 2,puVar2[3],

                  puVar2[4],param_6,param_7,1);

    uVar4 = (undefined4)((ulonglong)uVar3 >> 0x20);

    (**(code **)(lVar1 + 0x28))(puVar2[2],*puVar2);

    FUN_1401f3d60(lVar1,puVar2[2],*param_3,param_3[1],CONCAT44(uVar4,param_3[2]),param_3[3],

                  puVar2[3],puVar2[4],param_4,param_5,1);

    uVar3 = FUN_1401f4660("glTexSubImage2D()",param_1,"SDL_render_gles2.c",0x857,

                          "GLES2_UpdateTextureYUV");

  }

  return uVar3;

}




