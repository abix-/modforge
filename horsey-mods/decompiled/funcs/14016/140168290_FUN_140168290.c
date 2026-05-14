// Address: 0x140168290
// Ghidra name: FUN_140168290
// ============ 0x140168290 FUN_140168290 (size=497) ============


undefined8 FUN_140168290(undefined8 *param_1,undefined8 *param_2,undefined8 *param_3)



{

  char cVar1;

  undefined8 uVar2;

  undefined8 *puVar3;

  undefined8 *puVar4;

  

  if (param_1 == (undefined8 *)0x0) {

    uVar2 = FUN_14012e850("Parameter \'%s\' is invalid","stream");

    return uVar2;

  }

  puVar4 = param_3;

  if (param_2 != (undefined8 *)0x0) {

    puVar3 = param_2;

    cVar1 = FUN_140167e20(*(undefined4 *)param_2);

    if (cVar1 == '\0') {

      uVar2 = FUN_14012e850("Parameter \'%s\' is invalid","src_spec->format");

      return uVar2;

    }

    cVar1 = FUN_140167e60(*(undefined4 *)((longlong)puVar3 + 4));

    if (cVar1 == '\0') {

      uVar2 = FUN_14012e850("Parameter \'%s\' is invalid","src_spec->channels");

      return uVar2;

    }

    if (*(int *)(puVar3 + 1) < 1) {

      uVar2 = FUN_14012e850("Parameter \'%s\' is invalid","src_spec->freq");

      return uVar2;

    }

  }

  if (puVar4 != (undefined8 *)0x0) {

    cVar1 = FUN_140167e20(*(undefined4 *)puVar4);

    if (cVar1 == '\0') {

      uVar2 = FUN_14012e850("Parameter \'%s\' is invalid","dst_spec->format");

      return uVar2;

    }

    cVar1 = FUN_140167e60(*(undefined4 *)((longlong)puVar4 + 4));

    if (cVar1 == '\0') {

      uVar2 = FUN_14012e850("Parameter \'%s\' is invalid","dst_spec->channels");

      return uVar2;

    }

    if (*(int *)(puVar4 + 1) < 1) {

      uVar2 = FUN_14012e850("Parameter \'%s\' is invalid","dst_spec->freq");

      return uVar2;

    }

  }

  FUN_140179b40(*param_1);

  if (param_1[0x18] != 0) {

    if (*(char *)(*(longlong *)(param_1[0x18] + 8) + 0x94) != '\0') goto LAB_14016843a;

    param_3 = (undefined8 *)0x0;

  }

  if (param_2 != (undefined8 *)0x0) {

    if (*(int *)((longlong)param_2 + 4) != *(int *)((longlong)param_1 + 0x34)) {

      FUN_1401841e0(param_1[9]);

      param_1[9] = 0;

    }

    param_1[6] = *param_2;

    *(undefined4 *)(param_1 + 7) = *(undefined4 *)(param_2 + 1);

  }

LAB_14016843a:

  if (param_3 != (undefined8 *)0x0) {

    if (*(int *)((longlong)param_3 + 4) != *(int *)(param_1 + 8)) {

      FUN_1401841e0(param_1[10]);

      param_1[10] = 0;

    }

    *(undefined8 *)((longlong)param_1 + 0x3c) = *param_3;

    *(undefined4 *)((longlong)param_1 + 0x44) = *(undefined4 *)(param_3 + 1);

  }

  FUN_140179b60(*param_1);

  return 1;

}




