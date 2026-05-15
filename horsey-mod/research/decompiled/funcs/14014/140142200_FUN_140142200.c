// Address: 0x140142200
// Ghidra name: FUN_140142200
// ============ 0x140142200 FUN_140142200 (size=275) ============


bool FUN_140142200(undefined2 param_1,undefined2 param_2,undefined2 param_3,undefined8 param_4)



{

  undefined8 uVar1;

  char cVar2;

  char cVar3;

  int iVar4;

  longlong lVar5;

  undefined **ppuVar6;

  uint uVar7;

  bool bVar8;

  

  ppuVar6 = &PTR_s_uinput__140330020;

  uVar7 = 0;

  do {

    iVar4 = *(int *)(ppuVar6 + 1);

    if (iVar4 == 0) {

      cVar2 = FUN_1401aae60(param_4,*ppuVar6);

LAB_14014226d:

      bVar8 = cVar2 == '\0';

LAB_14014226f:

      if (!bVar8) {

        return true;

      }

    }

    else {

      if (iVar4 == 1) {

        cVar2 = FUN_1401aada0(param_4,*ppuVar6);

        goto LAB_14014226d;

      }

      if (iVar4 == 2) {

        lVar5 = thunk_FUN_1402c9340(param_4,*ppuVar6);

        bVar8 = lVar5 == 0;

        goto LAB_14014226f;

      }

    }

    uVar7 = uVar7 + 1;

    ppuVar6 = ppuVar6 + 2;

    if (10 < uVar7) {

      uVar1 = FUN_1401796b0("SDL_GAMECONTROLLER_ALLOW_STEAM_VIRTUAL_GAMEPAD");

      cVar2 = FUN_1401429e0(uVar1,0);

      if ((cVar2 == '\0') || (iVar4 = FUN_1401a9a30(), iVar4 == 0)) {

        cVar3 = FUN_1401596b0(param_1,param_2,param_3);

        if (cVar3 != '\0') {

          return cVar2 == '\0';

        }

        if (DAT_1403e1b68 < 1) {

          cVar2 = FUN_14015bf20(param_1,param_2,&PTR_s_SDL_GAMECONTROLLER_IGNORE_DEVICE_1403e1bb0);

          return cVar2 != '\0';

        }

        cVar2 = FUN_14015bf20(param_1,param_2,&PTR_s_SDL_GAMECONTROLLER_IGNORE_DEVICE_1403e1b60);

        if (cVar2 == '\0') {

          return true;

        }

      }

      return false;

    }

  } while( true );

}




