// Address: 0x1401ef030
// Ghidra name: FUN_1401ef030
// ============ 0x1401ef030 FUN_1401ef030 (size=382) ============


void FUN_1401ef030(longlong param_1,longlong param_2,int *param_3,undefined8 param_4,

                  undefined4 param_5,undefined8 param_6,int param_7)



{

  undefined4 uVar1;

  longlong lVar2;

  undefined4 *puVar3;

  

  lVar2 = *(longlong *)(param_1 + 0x2e0);

  puVar3 = *(undefined4 **)(param_2 + 0x138);

  uVar1 = *(undefined4 *)(lVar2 + 0x28);

  FUN_1401ebd30();

  *(undefined8 *)(lVar2 + 0x218) = 0;

  (**(code **)(lVar2 + 0x40))(uVar1,*puVar3);

  (**(code **)(lVar2 + 0x120))(0xcf5,1);

  (**(code **)(lVar2 + 0x120))(0xcf2,param_5);

  (**(code **)(lVar2 + 400))

            (uVar1,0,*param_3,param_3[1],param_3[2],param_3[3],puVar3[4],puVar3[5],param_4);

  (**(code **)(lVar2 + 0x120))(0xcf2,param_7 / 2);

  (**(code **)(lVar2 + 0x40))(uVar1,puVar3[0x16]);

  (**(code **)(lVar2 + 400))

            (uVar1,0,*param_3 / 2,param_3[1] / 2,(param_3[2] + 1) / 2,(param_3[3] + 1) / 2,0x190a,

             0x1401,param_6);

  FUN_1401ebd90("glTexSubImage2D()",param_1,"SDL_render_gl.c",0x390);

  return;

}




