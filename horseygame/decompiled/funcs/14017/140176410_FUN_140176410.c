// Address: 0x140176410
// Ghidra name: FUN_140176410
// ============ 0x140176410 FUN_140176410 (size=287) ============


int * FUN_140176410(undefined8 param_1)



{

  char cVar1;

  int *piVar2;

  longlong lVar3;

  undefined8 uVar4;

  undefined4 local_res10 [6];

  

  local_res10[0] = 0;

  cVar1 = FUN_140175b00(param_1,local_res10);

  if (cVar1 != '\0') {

    for (piVar2 = DAT_1403fc460; piVar2 != (int *)0x0; piVar2 = *(int **)(piVar2 + 0x20)) {

      if ((int)param_1 == *piVar2) {

        piVar2[0xc] = piVar2[0xc] + 1;

        return piVar2;

      }

    }

    piVar2 = (int *)FUN_1401841a0(1,0x88);

    if (piVar2 != (int *)0x0) {

      *piVar2 = (int)param_1;

      piVar2[0xd] = -1;

      cVar1 = FUN_14021ad60(piVar2);

      if (cVar1 != '\0') {

        if ((*(longlong *)(piVar2 + 2) == 0) && (lVar3 = FUN_14021acc0(local_res10[0]), lVar3 != 0))

        {

          uVar4 = FUN_14012f0d0(lVar3);

          *(undefined8 *)(piVar2 + 2) = uVar4;

        }

        piVar2[0xc] = piVar2[0xc] + 1;

        *(int **)(piVar2 + 0x20) = DAT_1403fc460;

        DAT_1403fc460 = piVar2;

        FUN_1401aa9d0(piVar2,6,1);

        if ((piVar2[8] & 0x10000U) != 0) {

          FUN_1401768f0(piVar2,100);

        }

        if ((piVar2[8] & 0x20000U) != 0) {

          FUN_140176830(piVar2,0);

        }

        return piVar2;

      }

      FUN_1401aa9d0(piVar2,6,0);

      FUN_1401841e0(piVar2);

    }

  }

  return (int *)0x0;

}




