// Address: 0x140172190
// Ghidra name: FUN_140172190
// ============ 0x140172190 FUN_140172190 (size=424) ============


undefined8 FUN_140172190(longlong param_1,int param_2,int param_3)



{

  int iVar1;

  code *pcVar2;

  longlong lVar3;

  char cVar4;

  undefined8 uVar5;

  float fVar6;

  float fVar7;

  

  if (DAT_1403fc410 == 0) {

    FUN_1401730c0();

    return 0;

  }

  if (param_1 != 0) {

    if (DAT_1403e3d60 != '\0') {

      cVar4 = FUN_1401aa7c0(param_1,1);

      if (cVar4 == '\0') goto LAB_14017231a;

    }

    if (param_2 < 1) {

      uVar5 = FUN_14012e850("Parameter \'%s\' is invalid",&DAT_14039bee0);

      return uVar5;

    }

    if (param_3 < 1) {

      uVar5 = FUN_14012e850("Parameter \'%s\' is invalid",&DAT_14030a2a4);

      return uVar5;

    }

    fVar6 = *(float *)(param_1 + 0x3c);

    fVar7 = (float)param_2 / (float)param_3;

    if ((fVar6 <= 0.0) || (fVar7 <= fVar6)) {

      fVar6 = *(float *)(param_1 + 0x38);

      if ((0.0 < fVar6) && (fVar7 < fVar6)) {

        fVar6 = (float)thunk_FUN_1402e1d00((float)param_2 / fVar6);

        param_3 = (int)fVar6;

      }

    }

    else {

      fVar6 = (float)thunk_FUN_1402e1d00(fVar6 * (float)param_3);

      param_2 = (int)fVar6;

    }

    lVar3 = DAT_1403fc410;

    iVar1 = *(int *)(param_1 + 0x28);

    if ((iVar1 != 0) && (param_2 < iVar1)) {

      param_2 = iVar1;

    }

    iVar1 = *(int *)(param_1 + 0x30);

    if ((iVar1 != 0) && (iVar1 < param_2)) {

      param_2 = iVar1;

    }

    iVar1 = *(int *)(param_1 + 0x2c);

    if ((iVar1 != 0) && (param_3 < iVar1)) {

      param_3 = iVar1;

    }

    iVar1 = *(int *)(param_1 + 0x34);

    if ((iVar1 != 0) && (iVar1 < param_3)) {

      param_3 = iVar1;

    }

    *(undefined1 *)(param_1 + 0x10c) = 1;

    *(int *)(param_1 + 0x94) = param_2;

    *(int *)(param_1 + 0x98) = param_3;

    pcVar2 = *(code **)(lVar3 + 0x68);

    if (pcVar2 != (code *)0x0) {

      (*pcVar2)(lVar3,param_1);

      FUN_140172f30(param_1);

      return 1;

    }

    uVar5 = FUN_14012e850("That operation is not supported");

    return uVar5;

  }

LAB_14017231a:

  FUN_14012e850("Invalid window");

  return 0;

}




