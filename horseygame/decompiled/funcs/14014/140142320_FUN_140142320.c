// Address: 0x140142320
// Ghidra name: FUN_140142320
// ============ 0x140142320 FUN_140142320 (size=231) ============


void FUN_140142320(longlong param_1)



{

  undefined4 uVar1;

  longlong lVar2;

  size_t sVar3;

  undefined1 *puVar4;

  

  _guard_check_icall();

  *(undefined4 *)(param_1 + 0x1c) = 0;

  lVar2 = thunk_FUN_1402c9340(*(undefined8 *)(*(longlong *)(param_1 + 0x20) + 0x18),"face:");

  if (lVar2 != 0) {

    sVar3 = strlen("type:");

    lVar2 = lVar2 + sVar3;

    puVar4 = (undefined1 *)thunk_FUN_1402c9190(lVar2,0x2c);

    if (puVar4 == (undefined1 *)0x0) {

      uVar1 = FUN_14013e4d0(lVar2);

      *(undefined4 *)(param_1 + 0x1c) = uVar1;

    }

    else {

      *puVar4 = 0;

      uVar1 = FUN_14013e4d0(lVar2);

      *(undefined4 *)(param_1 + 0x1c) = uVar1;

      *puVar4 = 0x2c;

    }

  }

  if (*(int *)(param_1 + 0x1c) == 0) {

    lVar2 = thunk_FUN_1402c9340(*(undefined8 *)(*(longlong *)(param_1 + 0x20) + 0x18),

                                "SDL_GAMECONTROLLER_USE_GAMECUBE_LABELS");

    if (lVar2 != 0) {

      *(undefined4 *)(param_1 + 0x1c) = 2;

    }

    if (*(int *)(param_1 + 0x1c) == 0) {

      lVar2 = thunk_FUN_1402c9340(*(undefined8 *)(*(longlong *)(param_1 + 0x20) + 0x18),

                                  "SDL_GAMECONTROLLER_USE_BUTTON_LABELS");

      if (lVar2 != 0) {

        *(undefined4 *)(param_1 + 0x1c) = 3;

      }

      if (*(int *)(param_1 + 0x1c) == 0) {

        uVar1 = FUN_14013e470(*(undefined4 *)(param_1 + 0x18));

        *(undefined4 *)(param_1 + 0x1c) = uVar1;

      }

    }

  }

  return;

}




