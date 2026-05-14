// Address: 0x14017d5c0
// Ghidra name: FUN_14017d5c0
// ============ 0x14017d5c0 FUN_14017d5c0 (size=226) ============


bool FUN_14017d5c0(void)



{

  int iVar1;

  longlong lVar2;

  ulonglong uVar3;

  ulonglong uVar4;

  undefined8 in_R9;

  undefined8 in_stack_00000028;

  undefined8 in_stack_00000030;

  

  iVar1 = FUN_14021a8d0();

  if (iVar1 == 0) {

    FUN_1401427d0("SDL_MAIN_CALLBACK_RATE",FUN_14017d520,0,in_R9,in_stack_00000028,in_stack_00000030

                 );

    uVar4 = 0;

    if (DAT_1403fc618 != 0) {

      lVar2 = FUN_140149300();

      uVar4 = lVar2 + DAT_1403fc618;

    }

    iVar1 = FUN_14017d4f0();

    while (iVar1 == 0) {

      uVar3 = 0;

      if (DAT_1403fc618 != 0) {

        uVar3 = FUN_140149300();

        if (uVar3 < uVar4) {

          FUN_140149210(uVar4 - uVar3);

          uVar3 = uVar4;

        }

        uVar3 = uVar3 + DAT_1403fc618;

      }

      iVar1 = FUN_14017d4f0();

      uVar4 = uVar3;

    }

    FUN_140142b00("SDL_MAIN_CALLBACK_RATE",FUN_14017d520,0);

  }

  FUN_14021aa60(iVar1);

  return iVar1 == 2;

}




