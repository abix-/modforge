// Address: 0x14016e6c0
// Ghidra name: FUN_14016e6c0
// ============ 0x14016e6c0 FUN_14016e6c0 (size=185) ============


float FUN_14016e6c0(longlong param_1)



{

  char cVar1;

  float fVar2;

  int local_res10 [2];

  int local_res18 [2];

  undefined1 local_res20 [8];

  undefined1 local_28 [32];

  

  fVar2 = DAT_14039ca44;

  if (DAT_1403fc410 == 0) {

    FUN_1401730c0();

    return 0.0;

  }

  if (param_1 != 0) {

    if (DAT_1403e3d60 != '\0') {

      cVar1 = FUN_1401aa7c0(param_1,1);

      if (cVar1 == '\0') goto LAB_14016e75f;

    }

    cVar1 = FUN_14016ed40(param_1,local_res18,local_res20);

    if (cVar1 != '\0') {

      cVar1 = FUN_14016ebe0(param_1,local_res10,local_28);

      if (cVar1 != '\0') {

        fVar2 = (float)local_res10[0] / (float)local_res18[0];

      }

    }

    return fVar2;

  }

LAB_14016e75f:

  FUN_14012e850("Invalid window");

  return 0.0;

}




