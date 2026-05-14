// Address: 0x14017e1d0
// Ghidra name: FUN_14017e1d0
// ============ 0x14017e1d0 FUN_14017e1d0 (size=238) ============


char * FUN_14017e1d0(char *param_1)



{

  char cVar1;

  int iVar2;

  undefined4 uVar3;

  char *pcVar4;

  char *pcVar5;

  

  cVar1 = FUN_14017ebb0();

  if (cVar1 == '\0') {

    FUN_14012e850("Parameter \'%s\' is invalid",&DAT_140304430);

    return (char *)0x0;

  }

  iVar2 = strcmp(param_1,"SDL.app.metadata.name");

  if (iVar2 == 0) {

    pcVar4 = "SDL_APP_NAME";

LAB_14017e238:

    pcVar4 = (char *)FUN_140142960(pcVar4);

    if ((pcVar4 != (char *)0x0) && (*pcVar4 != '\0')) goto LAB_14017e25f;

  }

  else {

    iVar2 = strcmp(param_1,"SDL.app.metadata.identifier");

    if (iVar2 == 0) {

      pcVar4 = "SDL_APP_ID";

      goto LAB_14017e238;

    }

  }

  uVar3 = FUN_140174be0();

  pcVar4 = (char *)FUN_140174e70(uVar3,param_1,0);

LAB_14017e25f:

  if ((pcVar4 == (char *)0x0) || (pcVar5 = pcVar4, *pcVar4 == '\0')) {

    iVar2 = strcmp(param_1,"SDL.app.metadata.name");

    if (iVar2 == 0) {

      return "SDL Application";

    }

    iVar2 = strcmp(param_1,"SDL.app.metadata.type");

    pcVar5 = "application";

    if (iVar2 != 0) {

      pcVar5 = pcVar4;

    }

  }

  return pcVar5;

}




