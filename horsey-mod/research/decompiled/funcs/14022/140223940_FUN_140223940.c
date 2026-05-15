// Address: 0x140223940
// Ghidra name: FUN_140223940
// ============ 0x140223940 FUN_140223940 (size=87) ============


undefined8 FUN_140223940(longlong param_1)



{

  int iVar1;

  char cVar2;

  

  if (*(char *)(*(longlong *)(param_1 + 0x688) + 6) != '\0') {

    cVar2 = FUN_140142940("SDL_OPENGL_ES_DRIVER",0);

    if (cVar2 == '\0') {

      iVar1 = *(int *)(*(longlong *)(param_1 + 0x688) + 8);

      if ((*(int *)(param_1 + 0x3e4) <= iVar1) &&

         ((*(int *)(param_1 + 0x3e4) != iVar1 ||

          (*(int *)(param_1 + 1000) <= *(int *)(*(longlong *)(param_1 + 0x688) + 0xc))))) {

        return 0;

      }

    }

  }

  return 1;

}




