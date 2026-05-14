// Address: 0x14019d0c0
// Ghidra name: FUN_14019d0c0
// ============ 0x14019d0c0 FUN_14019d0c0 (size=114) ============


undefined8 FUN_14019d0c0(undefined8 *param_1,char *param_2,int param_3)



{

  char *pcVar1;

  char cVar2;

  uint uVar3;

  ulonglong uVar4;

  

  uVar3 = ((int *)*param_1)[1] * *(int *)*param_1;

  pcVar1 = (char *)param_1[3];

  if (uVar3 != 0) {

    uVar4 = (ulonglong)uVar3;

    if (param_3 == 2) {

      do {

        cVar2 = -1;

        if (*pcVar1 == *param_2) {

          cVar2 = '\0';

        }

        pcVar1[1] = cVar2;

        uVar4 = uVar4 - 1;

        pcVar1 = pcVar1 + 2;

      } while (uVar4 != 0);

      return 1;

    }

    do {

      if (((*pcVar1 == *param_2) && (pcVar1[1] == param_2[1])) && (pcVar1[2] == param_2[2])) {

        pcVar1[3] = '\0';

      }

      pcVar1 = pcVar1 + 4;

      uVar4 = uVar4 - 1;

    } while (uVar4 != 0);

  }

  return 1;

}




