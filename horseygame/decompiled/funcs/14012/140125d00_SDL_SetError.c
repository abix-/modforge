// Address: 0x140125d00
// Ghidra name: SDL_SetError
// ============ 0x140125d00 SDL_SetError (size=157) ============


ulonglong SDL_SetError(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)



{

  uint uVar1;

  int iVar2;

  undefined1 *puVar3;

  undefined8 local_res10;

  undefined8 local_res18;

  undefined8 local_res20;

  undefined1 *local_98 [2];

  undefined1 local_88 [136];

  

                    /* 0x125d00  871  SDL_SetError */

  local_98[0] = local_88;

  local_res10 = param_2;

  local_res18 = param_3;

  local_res20 = param_4;

  uVar1 = (*(code *)PTR_FUN_1403de8b8)(local_88,0x80,param_1,&local_res10);

  if (-1 < (int)uVar1) {

    if (0x7f < uVar1) {

      local_98[0] = (undefined1 *)0x0;

      iVar2 = (*(code *)PTR_FUN_1403de8b0)(local_98,param_1,&local_res10);

      if (iVar2 < 0) goto LAB_140125d7e;

    }

    (*(code *)PTR_FUN_1403dc4d0)(&DAT_14039bf30,local_98[0]);

  }

LAB_140125d7e:

  puVar3 = local_88;

  if (local_98[0] != puVar3) {

    puVar3 = (undefined1 *)(*(code *)PTR_FUN_1403de4e0)();

  }

  return (ulonglong)puVar3 & 0xffffffffffffff00;

}




