// Address: 0x1401ebf60
// Ghidra name: FUN_1401ebf60
// ============ 0x1401ebf60 FUN_1401ebf60 (size=279) ============


undefined8 FUN_1401ebf60(longlong param_1,longlong param_2)



{

  undefined4 uVar1;

  longlong lVar2;

  char cVar3;

  undefined4 *puVar4;

  undefined8 in_stack_ffffffffffffffc8;

  undefined4 uVar5;

  

  uVar5 = (undefined4)((ulonglong)in_stack_ffffffffffffffc8 >> 0x20);

  lVar2 = *(longlong *)(param_1 + 0x2e0);

  puVar4 = (undefined4 *)FUN_1401841a0(1,4);

  if (puVar4 != (undefined4 *)0x0) {

    *(undefined4 **)(param_2 + 0x10) = puVar4;

    uVar1 = *(undefined4 *)(lVar2 + 0x28);

    *(undefined8 *)(lVar2 + 0x218) = 0;

    (**(code **)(lVar2 + 0xd0))(1,puVar4);

    (**(code **)(lVar2 + 0x40))(uVar1,*puVar4);

    (**(code **)(lVar2 + 0x180))(uVar1,0,0x8058,0x100,CONCAT44(uVar5,1),0,0x1908,0x1401,0);

    cVar3 = FUN_1401ebd90("glTexImage2D()",param_1,"SDL_render_gl.c",0x209,"GL_CreatePalette");

    if (cVar3 != '\0') {

      FUN_1401efc00(lVar2,uVar1,0,0);

      FUN_1401efba0(lVar2,uVar1,1);

      return 1;

    }

  }

  return 0;

}




