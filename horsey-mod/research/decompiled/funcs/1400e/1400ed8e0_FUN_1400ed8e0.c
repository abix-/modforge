// Address: 0x1400ed8e0
// Ghidra name: FUN_1400ed8e0
// ============ 0x1400ed8e0 FUN_1400ed8e0 (size=411) ============


undefined8 FUN_1400ed8e0(longlong param_1,int *param_2,int *param_3,int *param_4)



{

  char cVar1;

  int iVar2;

  char *pcVar3;

  int iVar4;

  

  pcVar3 = *(char **)(param_1 + 0xb8);

  if (*(char **)(param_1 + 0xc0) <= pcVar3) {

    if (*(int *)(param_1 + 0x30) == 0) goto LAB_1400eda50;

    FUN_1400ed820();

    pcVar3 = *(char **)(param_1 + 0xb8);

  }

  cVar1 = *pcVar3;

  pcVar3 = pcVar3 + 1;

  *(char **)(param_1 + 0xb8) = pcVar3;

  if (cVar1 == 'B') {

    if (*(char **)(param_1 + 0xc0) <= pcVar3) {

      if (*(int *)(param_1 + 0x30) == 0) goto LAB_1400eda50;

      FUN_1400ed820(param_1);

      pcVar3 = *(char **)(param_1 + 0xb8);

    }

    if (*pcVar3 == 'M') {

      if ((*(longlong *)(param_1 + 0x10) == 0) ||

         (iVar4 = *(int *)(param_1 + 0xc0) - ((int)pcVar3 + 1), 0xb < iVar4)) {

        *(char **)(param_1 + 0xb8) = pcVar3 + 0xd;

      }

      else {

        *(undefined8 *)(param_1 + 0xb8) = *(undefined8 *)(param_1 + 0xc0);

        (**(code **)(param_1 + 0x18))(*(undefined8 *)(param_1 + 0x28),0xc - iVar4);

      }

      iVar4 = FUN_1400e8b80(param_1);

      iVar2 = FUN_1400e8b80(param_1);

      iVar4 = iVar2 * 0x10000 + iVar4;

      if (iVar4 == 0xc) {

        iVar4 = FUN_1400e8b80(param_1);

        *param_2 = iVar4;

        iVar4 = FUN_1400e8b80(param_1);

      }

      else {

        if (((iVar4 != 0x28) && (iVar4 != 0x38)) && (iVar4 != 0x6c)) goto LAB_1400eda50;

        iVar4 = FUN_1400e8b80(param_1);

        iVar2 = FUN_1400e8b80(param_1);

        *param_2 = iVar2 * 0x10000 + iVar4;

        iVar4 = FUN_1400e8b80(param_1);

        iVar2 = FUN_1400e8b80(param_1);

        iVar4 = iVar2 * 0x10000 + iVar4;

      }

      *param_3 = iVar4;

      iVar4 = FUN_1400e8b80(param_1);

      if (iVar4 == 1) {

        iVar4 = FUN_1400e8b80(param_1);

        *param_4 = (int)(iVar4 + (iVar4 >> 0x1f & 7U)) >> 3;

        return 1;

      }

    }

  }

LAB_1400eda50:

  *(undefined8 *)(param_1 + 0xb8) = *(undefined8 *)(param_1 + 200);

  return 0;

}




