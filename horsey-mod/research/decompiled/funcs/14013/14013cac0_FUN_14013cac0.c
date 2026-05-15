// Address: 0x14013cac0
// Ghidra name: FUN_14013cac0
// ============ 0x14013cac0 FUN_14013cac0 (size=190) ============


void FUN_14013cac0(undefined8 *param_1)



{

  undefined8 *puVar1;

  undefined8 *puVar2;

  char cVar3;

  

  FUN_140159d30();

  if ((param_1 != (undefined8 *)0x0) &&

     (((DAT_1403e3d60 == '\0' || (cVar3 = FUN_1401aa7c0(param_1), cVar3 != '\0')) &&

      (*(int *)(param_1 + 1) = *(int *)(param_1 + 1) + -1, *(int *)(param_1 + 1) < 1)))) {

    FUN_1401575b0(*param_1);

    puVar1 = (undefined8 *)0x0;

    for (puVar2 = DAT_1403fbef8; puVar2 != (undefined8 *)0x0; puVar2 = (undefined8 *)puVar2[10]) {

      if (param_1 == puVar2) {

        if (puVar1 == (undefined8 *)0x0) {

          DAT_1403fbef8 = (undefined8 *)param_1[10];

        }

        else {

          puVar1[10] = puVar2[10];

        }

        break;

      }

      puVar1 = puVar2;

    }

    FUN_1401aa9d0(param_1,5,0);

    FUN_1401841e0(param_1[6]);

    FUN_1401841e0(param_1[7]);

    FUN_1401841e0(param_1[8]);

    FUN_1401841e0(param_1);

  }

  FUN_14015bb10();

  return;

}




