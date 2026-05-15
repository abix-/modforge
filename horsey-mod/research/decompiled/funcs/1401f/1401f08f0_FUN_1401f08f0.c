// Address: 0x1401f08f0
// Ghidra name: FUN_1401f08f0
// ============ 0x1401f08f0 FUN_1401f08f0 (size=330) ============


undefined8 FUN_1401f08f0(longlong param_1,longlong param_2)



{

  longlong lVar1;

  char cVar2;

  undefined4 *puVar3;

  undefined4 uVar4;

  

  lVar1 = *(longlong *)(param_1 + 0x2e0);

  puVar3 = (undefined4 *)FUN_1401841a0(1,4);

  if (puVar3 != (undefined4 *)0x0) {

    *(undefined4 **)(param_2 + 0x10) = puVar3;

    *(undefined8 *)(lVar1 + 0x278) = 0;

    (**(code **)(lVar1 + 0xb8))(1,puVar3);

    uVar4 = 1;

    cVar2 = FUN_1401f4660("glGenTexures()",param_1,"SDL_render_gles2.c",0x6b8,"GLES2_CreatePalette")

    ;

    if (cVar2 != '\0') {

      (**(code **)(lVar1 + 0x28))(0xde1,*puVar3);

      (**(code **)(lVar1 + 0x128))(0xde1,0,0x1908,0x100,CONCAT44(uVar4,1),0,0x1908,0x1401,0);

      cVar2 = FUN_1401f4660("glTexImage2D()",param_1,"SDL_render_gles2.c",0x6bd,

                            "GLES2_CreatePalette");

      if (cVar2 != '\0') {

        FUN_1401f4ff0(lVar1,0xde1,0,0);

        FUN_1401f4f90(lVar1,0xde1,1);

        return 1;

      }

    }

  }

  return 0;

}




