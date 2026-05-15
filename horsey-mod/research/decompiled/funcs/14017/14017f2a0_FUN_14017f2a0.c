// Address: 0x14017f2a0
// Ghidra name: FUN_14017f2a0
// ============ 0x14017f2a0 FUN_14017f2a0 (size=277) ============


ulonglong FUN_14017f2a0(char *param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4)



{

  code *pcVar1;

  uint uVar2;

  ulonglong uVar3;

  

  uVar3 = 3;

  FUN_14018b130(&DAT_1403fc68c);

  if ((DAT_1403fc678 == 0) && (DAT_1403fc678 = FUN_140179a30(), DAT_1403fc678 == 0)) {

    FUN_14018b190(&DAT_1403fc68c);

    return 3;

  }

  FUN_14018b190(&DAT_1403fc68c);

  FUN_140179b40(DAT_1403fc678);

  if (*(int *)(param_1 + 4) == 0) {

    *(undefined8 *)(param_1 + 0x20) = param_2;

    *(undefined8 *)(param_1 + 0x10) = param_3;

    *(undefined4 *)(param_1 + 0x18) = param_4;

  }

  FUN_14017f0d0(param_1);

  DAT_1403fc688 = DAT_1403fc688 + 1;

  if (DAT_1403fc688 < 2) {

    if (*param_1 == '\0') {

      uVar2 = (*(code *)PTR_FUN_1403e28f0)(param_1,DAT_1403fc680);

      uVar3 = (ulonglong)uVar2;

      if (uVar2 == 2) goto LAB_14017f3aa;

      if (uVar2 == 4) {

        uVar3 = 3;

        *param_1 = '\x01';

      }

    }

    DAT_1403fc688 = DAT_1403fc688 + -1;

    FUN_140179b60(DAT_1403fc678);

    return uVar3;

  }

  if (DAT_1403fc688 != 2) {

    if (DAT_1403fc688 == 3) {

                    /* WARNING: Subroutine does not return */

      FUN_1402e1bf8();

    }

    do {

                    /* WARNING: Do nothing block with infinite loop */

    } while( true );

  }

LAB_14017f3aa:

  FUN_14017f0c0();

  pcVar1 = (code *)swi(3);

  uVar3 = (*pcVar1)();

  return uVar3;

}




