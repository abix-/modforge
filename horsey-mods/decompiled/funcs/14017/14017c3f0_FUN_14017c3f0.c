// Address: 0x14017c3f0
// Ghidra name: FUN_14017c3f0
// ============ 0x14017c3f0 FUN_14017c3f0 (size=230) ============


undefined1 * FUN_14017c3f0(ulonglong param_1)



{

  undefined1 uVar1;

  char cVar2;

  int iVar3;

  undefined8 *puVar4;

  char *pcVar5;

  undefined1 *puVar6;

  

  puVar4 = (undefined8 *)FUN_140174d30(param_1,"SDL.process.create.args",0);

  pcVar5 = (char *)FUN_140174e70(param_1 & 0xffffffff,"SDL.process.create.cmdline",0);

  if ((((puVar4 == (undefined8 *)0x0) || ((char *)*puVar4 == (char *)0x0)) ||

      (*(char *)*puVar4 == '\0')) && ((pcVar5 == (char *)0x0 || (*pcVar5 == '\0')))) {

    FUN_14012e850(

                 "Either SDL_PROP_PROCESS_CREATE_ARGS_POINTER or SDL_PROP_PROCESS_CREATE_CMDLINE_STRING must be valid"

                 );

  }

  else {

    puVar6 = (undefined1 *)FUN_1401841a0(1,0x18);

    if (puVar6 != (undefined1 *)0x0) {

      uVar1 = FUN_1401749e0(param_1 & 0xffffffff,"SDL.process.create.background",0);

      puVar6[1] = uVar1;

      iVar3 = FUN_1401746e0();

      *(int *)(puVar6 + 8) = iVar3;

      if (iVar3 != 0) {

        FUN_140175280(iVar3,"SDL.process.background",puVar6[1]);

        cVar2 = FUN_14021dad0(puVar6,param_1 & 0xffffffff);

        if (cVar2 != '\0') {

          *puVar6 = 1;

          return puVar6;

        }

      }

      FUN_14017c590(puVar6);

      return (undefined1 *)0x0;

    }

  }

  return (undefined1 *)0x0;

}




