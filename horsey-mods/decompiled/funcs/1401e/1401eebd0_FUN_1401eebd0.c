// Address: 0x1401eebd0
// Ghidra name: FUN_1401eebd0
// ============ 0x1401eebd0 FUN_1401eebd0 (size=230) ============


void FUN_1401eebd0(longlong param_1,longlong param_2,undefined4 param_3,undefined8 param_4)



{

  undefined4 uVar1;

  longlong lVar2;

  undefined4 *puVar3;

  undefined8 in_stack_ffffffffffffffb8;

  undefined4 uVar4;

  

  uVar4 = (undefined4)((ulonglong)in_stack_ffffffffffffffb8 >> 0x20);

  lVar2 = *(longlong *)(param_1 + 0x2e0);

  puVar3 = *(undefined4 **)(param_2 + 0x10);

  FUN_1401ebd30();

  uVar1 = *(undefined4 *)(lVar2 + 0x28);

  *(undefined8 *)(lVar2 + 0x218) = 0;

  (**(code **)(lVar2 + 0x40))(uVar1,*puVar3);

  (**(code **)(lVar2 + 0x120))(0xcf5,1);

  (**(code **)(lVar2 + 0x120))(0xcf2,param_3);

  (**(code **)(lVar2 + 400))(uVar1,0,0,0,CONCAT44(uVar4,param_3),1,0x1908,0x1401,param_4);

  FUN_1401ebd90("glTexSubImage2D()",param_1,"SDL_render_gl.c",0x220,"GL_UpdatePalette");

  return;

}




