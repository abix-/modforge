// Address: 0x1401ab340
// Ghidra name: FUN_1401ab340
// ============ 0x1401ab340 FUN_1401ab340 (size=144) ============


ulonglong FUN_1401ab340(undefined8 *param_1,undefined8 param_2)



{

  int iVar1;

  ulonglong uVar2;

  longlong lVar3;

  

  if (param_1 == (undefined8 *)0x0) {

    uVar2 = FUN_14012e850("Parameter \'%s\' is invalid","table");

    return uVar2;

  }

  FUN_14017cab0(*param_1);

  iVar1 = (*(code *)param_1[2])(param_1[5],param_2);

  lVar3 = FUN_1401ab530(param_1,param_2,iVar1 * -0x61c8864f);

  if (lVar3 != 0) {

    FUN_1401ab3d0(param_1,lVar3);

  }

  FUN_14017cae0(*param_1);

  return (ulonglong)(lVar3 != 0);

}




