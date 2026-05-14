// Address: 0x14022e1d0
// Ghidra name: FUN_14022e1d0
// ============ 0x14022e1d0 FUN_14022e1d0 (size=490) ============


void FUN_14022e1d0(code *UNRECOVERED_JUMPTABLE_00,undefined8 param_2,undefined8 param_3,

                  longlong param_4,undefined4 param_5,longlong param_6,char param_7,char param_8,

                  longlong param_9,longlong param_10,longlong param_11)



{

  uint uVar1;

  longlong lVar2;

  char *pcVar3;

  undefined8 uVar4;

  undefined8 uVar5;

  uint uVar6;

  

  lVar2 = FUN_140142960("SDL_FILE_DIALOG_DRIVER");

  if (lVar2 != 0) {

    FUN_14012e850("File dialog driver unsupported");

                    /* WARNING: Could not recover jumptable at 0x00014022e21a. Too many branches */

                    /* WARNING: Treating indirect jump as call */

    (*UNRECOVERED_JUMPTABLE_00)(param_2,0,0xffffffff);

    return;

  }

  pcVar3 = (char *)FUN_1401841f0(0x58);

  if (pcVar3 != (char *)0x0) {

    lVar2 = FUN_14022e620(param_4);

    uVar6 = -(uint)(param_7 != '\0') & 0x200;

    uVar1 = uVar6 | 2;

    if (param_8 == '\0') {

      uVar1 = uVar6;

    }

    if ((lVar2 == 0) && (param_4 != 0)) {

      (*UNRECOVERED_JUMPTABLE_00)(param_2,0,0xffffffff);

      FUN_1401841e0(pcVar3);

    }

    else {

      *pcVar3 = param_8;

      uVar5 = 0;

      *(longlong *)(pcVar3 + 8) = lVar2;

      *(undefined4 *)(pcVar3 + 0x10) = param_5;

      uVar4 = uVar5;

      if (param_6 != 0) {

        uVar4 = FUN_14012f0d0();

      }

      *(undefined8 *)(pcVar3 + 0x18) = uVar4;

      *(undefined8 *)(pcVar3 + 0x20) = param_3;

      *(uint *)(pcVar3 + 0x28) = uVar1;

      pcVar3[0x2c] = param_7;

      *(code **)(pcVar3 + 0x30) = UNRECOVERED_JUMPTABLE_00;

      *(undefined8 *)(pcVar3 + 0x38) = param_2;

      uVar4 = uVar5;

      if (param_9 != 0) {

        uVar4 = FUN_14012f0d0();

      }

      *(undefined8 *)(pcVar3 + 0x40) = uVar4;

      uVar4 = uVar5;

      if (param_10 != 0) {

        uVar4 = FUN_14012f0d0();

      }

      *(undefined8 *)(pcVar3 + 0x48) = uVar4;

      if (param_11 != 0) {

        uVar5 = FUN_14012f0d0();

      }

      *(undefined8 *)(pcVar3 + 0x50) = uVar5;

      lVar2 = FUN_140163260(FUN_14022f810,"SDL_Windows_ShowFileDialog",pcVar3,FUN_1402cfa08,

                            FUN_1402cfae8);

      if (lVar2 == 0) {

        (*UNRECOVERED_JUMPTABLE_00)(param_2,0,0xffffffff);

        FUN_14022e580(pcVar3);

      }

      else {

        FUN_140163550(lVar2);

      }

    }

    return;

  }

                    /* WARNING: Could not recover jumptable at 0x00014022e250. Too many branches */

                    /* WARNING: Treating indirect jump as call */

  (*UNRECOVERED_JUMPTABLE_00)(param_2,0,0xffffffff);

  return;

}




