// Address: 0x1401f3f00
// Ghidra name: FUN_1401f3f00
// ============ 0x1401f3f00 FUN_1401f3f00 (size=197) ============


void FUN_1401f3f00(longlong param_1,longlong param_2,undefined4 param_3,undefined8 param_4)



{

  longlong lVar1;

  undefined4 *puVar2;

  undefined8 in_stack_ffffffffffffffc8;

  undefined4 uVar3;

  

  uVar3 = (undefined4)((ulonglong)in_stack_ffffffffffffffc8 >> 0x20);

  lVar1 = *(longlong *)(param_1 + 0x2e0);

  puVar2 = *(undefined4 **)(param_2 + 0x10);

  FUN_1401f0320();

  *(undefined8 *)(lVar1 + 0x278) = 0;

  (**(code **)(lVar1 + 0x28))(0xde1,*puVar2);

  (**(code **)(lVar1 + 0x138))(0xde1,0,0,0,CONCAT44(uVar3,param_3),1,0x1908,0x1401,param_4);

  FUN_1401f4660("glTexSubImage2D()",param_1,"SDL_render_gles2.c",0x6d1,"GLES2_UpdatePalette");

  return;

}




