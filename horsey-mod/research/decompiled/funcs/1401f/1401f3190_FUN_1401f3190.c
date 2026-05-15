// Address: 0x1401f3190
// Ghidra name: FUN_1401f3190
// ============ 0x1401f3190 FUN_1401f3190 (size=279) ============


longlong FUN_1401f3190(longlong param_1,undefined4 *param_2)



{

  longlong lVar1;

  char cVar2;

  int iVar3;

  longlong lVar4;

  undefined4 uVar5;

  int local_res8 [2];

  undefined1 local_res10 [8];

  undefined8 in_stack_ffffffffffffffc8;

  undefined4 uVar6;

  

  uVar6 = (undefined4)((ulonglong)in_stack_ffffffffffffffc8 >> 0x20);

  lVar1 = *(longlong *)(param_1 + 0x2e0);

  if (*(undefined4 **)(param_1 + 0x1f0) == (undefined4 *)0x0) {

    uVar5 = 0x16762004;

  }

  else {

    uVar5 = **(undefined4 **)(param_1 + 0x1f0);

  }

  lVar4 = FUN_140145e60(param_2[2],param_2[3],uVar5);

  if (lVar4 != 0) {

    iVar3 = param_2[1];

    if (*(longlong *)(param_1 + 0x1f0) == 0) {

      FUN_14014e850(param_1,local_res10,local_res8);

      iVar3 = (local_res8[0] - param_2[3]) - iVar3;

    }

    (**(code **)(lVar1 + 0x108))

              (*param_2,iVar3,param_2[2],param_2[3],CONCAT44(uVar6,0x1908),0x1401,

               *(undefined8 *)(lVar4 + 0x18));

    cVar2 = FUN_1401f4660("glReadPixels()",param_1,"SDL_render_gles2.c",0x8eb,

                          "GLES2_RenderReadPixels");

    if (cVar2 != '\0') {

      if (*(longlong *)(param_1 + 0x1f0) == 0) {

        FUN_140146490(lVar4,2);

      }

      return lVar4;

    }

    FUN_140146010(lVar4);

  }

  return 0;

}




