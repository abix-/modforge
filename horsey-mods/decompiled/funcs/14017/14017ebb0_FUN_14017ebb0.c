// Address: 0x14017ebb0
// Ghidra name: FUN_14017ebb0
// ============ 0x14017ebb0 FUN_14017ebb0 (size=173) ============


undefined4 FUN_14017ebb0(char *param_1)



{

  int iVar1;

  

  if ((param_1 == (char *)0x0) || (*param_1 == '\0')) {

    return 0;

  }

  iVar1 = strcmp(param_1,"SDL.app.metadata.name");

  if (((iVar1 != 0) &&

      (((iVar1 = strcmp(param_1,"SDL.app.metadata.version"), iVar1 != 0 &&

        (iVar1 = strcmp(param_1,"SDL.app.metadata.identifier"), iVar1 != 0)) &&

       (iVar1 = strcmp(param_1,"SDL.app.metadata.creator"), iVar1 != 0)))) &&

     (((iVar1 = strcmp(param_1,"SDL.app.metadata.copyright"), iVar1 != 0 &&

       (iVar1 = strcmp(param_1,"SDL.app.metadata.url"), iVar1 != 0)) &&

      (iVar1 = strcmp(param_1,"SDL.app.metadata.type"), iVar1 != 0)))) {

    return 0;

  }

  return 1;

}




