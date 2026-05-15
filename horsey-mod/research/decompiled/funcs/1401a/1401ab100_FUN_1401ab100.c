// Address: 0x1401ab100
// Ghidra name: FUN_1401ab100
// ============ 0x1401ab100 FUN_1401ab100 (size=257) ============


undefined8 FUN_1401ab100(undefined8 *param_1,undefined8 param_2,undefined8 param_3,char param_4)



{

  char cVar1;

  int iVar2;

  undefined8 uVar3;

  longlong lVar4;

  undefined8 local_38;

  undefined8 local_30;

  int local_28;

  undefined4 local_24;

  

  if (param_1 == (undefined8 *)0x0) {

    uVar3 = FUN_14012e850("Parameter \'%s\' is invalid","table");

    return uVar3;

  }

  uVar3 = 0;

  FUN_14017cab0(*param_1);

  iVar2 = (*(code *)param_1[2])(param_1[5],param_2);

  lVar4 = FUN_1401ab530(param_1,param_2,iVar2 * -0x61c8864f);

  if (lVar4 != 0) {

    if (param_4 == '\0') {

      FUN_14012e850("key already exists and replace is disabled");

      goto LAB_1401ab1dd;

    }

    FUN_1401ab3d0(param_1,lVar4);

  }

  *(int *)(param_1 + 7) = *(int *)(param_1 + 7) + 1;

  local_24 = 0x80000000;

  local_38 = param_2;

  local_30 = param_3;

  local_28 = iVar2 * -0x61c8864f;

  cVar1 = FUN_1401ab760(param_1);

  if (cVar1 == '\0') {

    *(int *)(param_1 + 7) = *(int *)(param_1 + 7) + -1;

  }

  else {

    FUN_1401ab630(&local_38,param_1[1],*(undefined4 *)(param_1 + 6),(longlong)param_1 + 0x34);

    uVar3 = 1;

  }

LAB_1401ab1dd:

  FUN_14017cae0(*param_1);

  return uVar3;

}




