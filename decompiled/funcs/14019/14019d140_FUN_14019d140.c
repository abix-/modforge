// Address: 0x14019d140
// Ghidra name: FUN_14019d140
// ============ 0x14019d140 FUN_14019d140 (size=132) ============


undefined8 FUN_14019d140(undefined8 *param_1,short *param_2,int param_3)



{

  short *psVar1;

  short sVar2;

  uint uVar3;

  ulonglong uVar4;

  

  uVar3 = ((int *)*param_1)[1] * *(int *)*param_1;

  psVar1 = (short *)param_1[3];

  if (uVar3 != 0) {

    uVar4 = (ulonglong)uVar3;

    if (param_3 == 2) {

      do {

        sVar2 = -1;

        if (*psVar1 == *param_2) {

          sVar2 = 0;

        }

        psVar1[1] = sVar2;

        uVar4 = uVar4 - 1;

        psVar1 = psVar1 + 2;

      } while (uVar4 != 0);

      return 1;

    }

    do {

      if (((*psVar1 == *param_2) && (psVar1[1] == param_2[1])) && (psVar1[2] == param_2[2])) {

        psVar1[3] = 0;

      }

      psVar1 = psVar1 + 4;

      uVar4 = uVar4 - 1;

    } while (uVar4 != 0);

  }

  return 1;

}




