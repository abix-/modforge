// Address: 0x140177450
// Ghidra name: FUN_140177450
// ============ 0x140177450 FUN_140177450 (size=337) ============


int * FUN_140177450(int param_1)



{

  char cVar1;

  int iVar2;

  int *piVar3;

  longlong lVar4;

  undefined8 uVar5;

  undefined4 local_res10 [2];

  longlong local_res18;

  

  FUN_140177410();

  cVar1 = FUN_140176dd0(param_1,&local_res18,local_res10);

  piVar3 = DAT_1403fc480;

  if (cVar1 != '\0') {

    for (; piVar3 != (int *)0x0; piVar3 = *(int **)(piVar3 + 0x1c)) {

      if (param_1 == *piVar3) {

        piVar3[0x1b] = piVar3[0x1b] + 1;

        FUN_140177750();

        return piVar3;

      }

    }

    piVar3 = (int *)FUN_1401841a0(1,0x78);

    if (piVar3 != (int *)0x0) {

      FUN_1401aa9d0(piVar3,7,1);

      *piVar3 = param_1;

      *(longlong *)(piVar3 + 0x16) = local_res18;

      iVar2 = (**(code **)(local_res18 + 0x20))(local_res10[0]);

      piVar3[4] = iVar2;

      iVar2 = (**(code **)(local_res18 + 0x28))(local_res10[0]);

      piVar3[5] = iVar2;

      cVar1 = (**(code **)(local_res18 + 0x38))(piVar3,local_res10[0]);

      if (cVar1 == '\0') {

        FUN_1401aa9d0(piVar3,7,0);

        FUN_1401841e0(piVar3);

        FUN_140177750();

        return (int *)0x0;

      }

      lVar4 = (**(code **)(local_res18 + 0x18))(local_res10[0]);

      uVar5 = 0;

      if (lVar4 != 0) {

        uVar5 = FUN_14012f0d0(lVar4);

      }

      *(undefined8 *)(piVar3 + 2) = uVar5;

      piVar3[0x1b] = piVar3[0x1b] + 1;

      *(int **)(piVar3 + 0x1c) = DAT_1403fc480;

      DAT_1403fc480 = piVar3;

      (**(code **)(local_res18 + 0x40))(piVar3);

      FUN_140177750();

      return piVar3;

    }

  }

  FUN_140177750();

  return (int *)0x0;

}




