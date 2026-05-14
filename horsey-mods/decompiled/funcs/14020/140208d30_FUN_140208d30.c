// Address: 0x140208d30
// Ghidra name: FUN_140208d30
// ============ 0x140208d30 FUN_140208d30 (size=173) ============


void FUN_140208d30(void)



{

  undefined **ppuVar1;

  char cVar2;

  uint uVar3;

  longlong lVar4;

  undefined **ppuVar5;

  char local_res8 [8];

  

  _guard_check_icall();

  uVar3 = 0;

  ppuVar5 = &PTR_PTR_1403e4d40;

  DAT_1403fd1a4 = 0;

  do {

    ppuVar1 = (undefined **)*ppuVar5;

    cVar2 = (*(code *)ppuVar1[4])();

    *(char *)(ppuVar1 + 1) = cVar2;

    if ((cVar2 != '\0') && (ppuVar1 != &PTR_s_SDL_JOYSTICK_HIDAPI_COMBINED_1403e6980)) {

      DAT_1403fd1a4 = DAT_1403fd1a4 + 1;

    }

    uVar3 = uVar3 + 1;

    ppuVar5 = ppuVar5 + 1;

  } while (uVar3 < 0x1a);

  local_res8[0] = '\0';

  cVar2 = '\0';

  do {

    while (lVar4 = DAT_1403fd198, DAT_1403fd198 != 0) {

      while (FUN_140208550(lVar4,local_res8), cVar2 = local_res8[0], local_res8[0] == '\0') {

        lVar4 = *(longlong *)(lVar4 + 0xb8);

        if (lVar4 == 0) {

          return;

        }

      }

    }

  } while (cVar2 != '\0');

  return;

}




