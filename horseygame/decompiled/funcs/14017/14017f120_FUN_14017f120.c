// Address: 0x14017f120
// Ghidra name: FUN_14017f120
// ============ 0x14017f120 FUN_14017f120 (size=219) ============


void FUN_14017f120(void)



{

  undefined *puVar1;

  undefined *puVar2;

  char *pcVar3;

  

  pcVar3 = DAT_1403fc670;

  if ((DAT_1403fc670 != (char *)0x0) && ((code *)PTR_FUN_1403e28f0 != FUN_14017ed00)) {

    FUN_14017f420("\n\nSDL assertion report.\n");

    FUN_14017f420("All SDL assertions between last init/quit:\n\n");

    do {

      puVar2 = &DAT_14031b690;

      puVar1 = &DAT_14030cc60;

      if (*pcVar3 != '\0') {

        puVar2 = &DAT_14030db64;

      }

      if (*(int *)(pcVar3 + 4) == 1) {

        puVar1 = &DAT_14039bcb9;

      }

      FUN_14017f420("\'%s\'\n    * %s (%s:%d)\n    * triggered %u time%s.\n    * always ignore: %s.\n"

                    ,*(undefined8 *)(pcVar3 + 8),*(undefined8 *)(pcVar3 + 0x20),

                    *(undefined8 *)(pcVar3 + 0x10),*(undefined4 *)(pcVar3 + 0x18),

                    *(int *)(pcVar3 + 4),puVar1,puVar2);

      pcVar3 = *(char **)(pcVar3 + 0x28);

    } while (pcVar3 != (char *)0x0);

    FUN_14017f420(&DAT_14039bd10);

    FUN_14017f3c0();

    return;

  }

  return;

}




