// Address: 0x14022e3c0
// Ghidra name: FUN_14022e3c0
// ============ 0x14022e3c0 FUN_14022e3c0 (size=338) ============


void FUN_14022e3c0(code *param_1,undefined8 param_2,undefined8 param_3,longlong param_4,

                  undefined1 param_5,longlong param_6,longlong param_7,longlong param_8)



{

  longlong lVar1;

  undefined8 *puVar2;

  undefined8 uVar3;

  undefined8 uVar4;

  

  lVar1 = FUN_140142960("SDL_FILE_DIALOG_DRIVER");

  if (lVar1 == 0) {

    puVar2 = (undefined8 *)FUN_1401841f0(0x40);

    if (puVar2 == (undefined8 *)0x0) {

      (*param_1)(param_2,0,0xffffffff);

    }

    else {

      *puVar2 = param_3;

      uVar4 = 0;

      *(undefined1 *)(puVar2 + 1) = param_5;

      puVar2[2] = param_1;

      uVar3 = uVar4;

      if (param_4 != 0) {

        uVar3 = FUN_14012f0d0(param_4);

      }

      puVar2[3] = uVar3;

      puVar2[4] = param_2;

      uVar3 = uVar4;

      if (param_6 != 0) {

        uVar3 = FUN_14012f0d0();

      }

      puVar2[5] = uVar3;

      uVar3 = uVar4;

      if (param_7 != 0) {

        uVar3 = FUN_14012f0d0();

      }

      puVar2[6] = uVar3;

      if (param_8 != 0) {

        uVar4 = FUN_14012f0d0();

      }

      puVar2[7] = uVar4;

      lVar1 = FUN_140163260(FUN_14022f830,"SDL_Windows_ShowFolderDialog",puVar2,FUN_1402cfa08,

                            FUN_1402cfae8);

      if (lVar1 == 0) {

        (*param_1)(param_2,0,0xffffffff);

        FUN_14022e5d0(puVar2);

      }

      else {

        FUN_140163550(lVar1);

      }

    }

  }

  else {

    FUN_14012e850("File dialog driver unsupported");

    (*param_1)(param_2,0,0xffffffff);

  }

  return;

}




