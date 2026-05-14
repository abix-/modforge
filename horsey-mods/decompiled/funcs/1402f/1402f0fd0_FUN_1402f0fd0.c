// Address: 0x1402f0fd0
// Ghidra name: FUN_1402f0fd0
// ============ 0x1402f0fd0 FUN_1402f0fd0 (size=142) ============


undefined8 FUN_1402f0fd0(short *param_1,longlong param_2,longlong param_3)



{

  short sVar1;

  undefined4 *puVar2;

  short *psVar3;

  

  if ((param_1 != (short *)0x0) && (param_2 != 0)) {

    psVar3 = param_1;

    if (param_3 == 0) {

      *param_1 = 0;

    }

    else {

      do {

        if (*psVar3 == 0) {

          param_3 = param_3 - (longlong)psVar3;

          do {

            sVar1 = *(short *)(param_3 + (longlong)psVar3);

            *psVar3 = sVar1;

            psVar3 = psVar3 + 1;

            if (sVar1 == 0) {

              return 0;

            }

            param_2 = param_2 + -1;

          } while (param_2 != 0);

          *param_1 = 0;

          puVar2 = (undefined4 *)FUN_1402e68b0();

          *puVar2 = 0x22;

          FUN_1402cd454();

          return 0x22;

        }

        psVar3 = psVar3 + 1;

        param_2 = param_2 + -1;

      } while (param_2 != 0);

      *param_1 = 0;

    }

  }

  puVar2 = (undefined4 *)FUN_1402e68b0();

  *puVar2 = 0x16;

  FUN_1402cd454();

  return 0x16;

}




