// Address: 0x14012e3f0
// Ghidra name: FUN_14012e3f0
// ============ 0x14012e3f0 FUN_14012e3f0 (size=305) ============


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void FUN_14012e3f0(void)



{

  bool bVar1;

  char *pcVar2;

  longlong lVar3;

  int *piVar4;

  int iVar5;

  uint uVar6;

  

  FUN_14012dec0();

  FUN_140179b40(DAT_1403fb510);

  pcVar2 = (char *)FUN_140179690("DEBUG_INVOCATION");

  if (((pcVar2 == (char *)0x0) || (*pcVar2 == '\0')) || (*pcVar2 == '0')) {

    bVar1 = false;

  }

  else {

    bVar1 = true;

  }

  FUN_14012da50();

  uVar6 = 0;

  _DAT_1403fb530 = 0;

  _DAT_1403fb538 = 0;

  _DAT_1403fb570 = 0;

  _DAT_1403fb540 = 0;

  _DAT_1403fb548 = 0;

  DAT_1403fb578 = 0;

  _DAT_1403fb550 = 0;

  _DAT_1403fb558 = 0;

  DAT_1403fb4f4 = 0;

  _DAT_1403fb560 = 0;

  _DAT_1403fb568 = 0;

  lVar3 = FUN_140142960("SDL_LOGGING");

  if (lVar3 != 0) {

    FUN_14012dbb0(lVar3);

  }

  if (DAT_1403fb4f4 == 0) {

    DAT_1403fb4f4 = 6;

  }

  piVar4 = &DAT_1403fb530;

LAB_14012e4a5:

  do {

    if (*piVar4 == 0) {

      if (uVar6 == 0) {

        uVar6 = 1;

        if (bVar1) {

          *piVar4 = 3;

          piVar4 = piVar4 + 1;

        }

        else {

          *piVar4 = 4;

          piVar4 = piVar4 + 1;

        }

        goto LAB_14012e4a5;

      }

      if (uVar6 == 2) {

        uVar6 = 3;

        *piVar4 = 5;

        piVar4 = piVar4 + 1;

        goto LAB_14012e4a5;

      }

      if (uVar6 == 8) {

        uVar6 = 9;

        *piVar4 = 2;

        piVar4 = piVar4 + 1;

        goto LAB_14012e4a5;

      }

      iVar5 = 6;

      if (bVar1) {

        iVar5 = 3;

      }

      *piVar4 = iVar5;

    }

    uVar6 = uVar6 + 1;

    piVar4 = piVar4 + 1;

    if (0x12 < uVar6) {

      FUN_140179b60(DAT_1403fb510);

      return;

    }

  } while( true );

}




