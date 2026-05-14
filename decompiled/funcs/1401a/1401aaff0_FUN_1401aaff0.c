// Address: 0x1401aaff0
// Ghidra name: FUN_1401aaff0
// ============ 0x1401aaff0 FUN_1401aaff0 (size=171) ============


undefined8 FUN_1401aaff0(undefined8 *param_1,undefined8 param_2,undefined8 *param_3)



{

  int iVar1;

  undefined8 uVar2;

  longlong lVar3;

  

  if (param_1 == (undefined8 *)0x0) {

    if (param_3 != (undefined8 *)0x0) {

      *param_3 = 0;

    }

    uVar2 = FUN_14012e850("Parameter \'%s\' is invalid","table");

    return uVar2;

  }

  FUN_14017caa0(*param_1);

  uVar2 = 0;

  iVar1 = (*(code *)param_1[2])(param_1[5],param_2);

  lVar3 = FUN_1401ab530(param_1,param_2,iVar1 * -0x61c8864f);

  if (lVar3 != 0) {

    if (param_3 != (undefined8 *)0x0) {

      *param_3 = *(undefined8 *)(lVar3 + 8);

    }

    uVar2 = 1;

  }

  FUN_14017cae0(*param_1);

  return uVar2;

}




