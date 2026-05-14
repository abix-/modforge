// Address: 0x1401ab210
// Ghidra name: FUN_1401ab210
// ============ 0x1401ab210 FUN_1401ab210 (size=209) ============


undefined8 FUN_1401ab210(undefined8 *param_1,code *param_2,undefined8 param_3)



{

  undefined8 *puVar1;

  char cVar2;

  undefined8 uVar3;

  undefined8 *puVar4;

  uint uVar5;

  

  if (param_1 == (undefined8 *)0x0) {

    uVar3 = FUN_14012e850("Parameter \'%s\' is invalid","table");

    return uVar3;

  }

  if (param_2 != (code *)0x0) {

    FUN_14017caa0(*param_1);

    uVar5 = 0;

    puVar4 = (undefined8 *)param_1[1];

    puVar1 = puVar4 + (ulonglong)(*(int *)(param_1 + 6) + 1) * 3;

    while ((puVar4 < puVar1 &&

           ((-1 < *(int *)((longlong)puVar4 + 0x14) ||

            ((cVar2 = (*param_2)(param_3,param_1,*puVar4,puVar4[1]), cVar2 != '\0' &&

             (uVar5 = uVar5 + 1, uVar5 < *(uint *)(param_1 + 7)))))))) {

      puVar4 = puVar4 + 3;

    }

    FUN_14017cae0(*param_1);

    return 1;

  }

  uVar3 = FUN_14012e850("Parameter \'%s\' is invalid","callback");

  return uVar3;

}




