// Address: 0x14015f940
// Ghidra name: FUN_14015f940
// ============ 0x14015f940 FUN_14015f940 (size=124) ============


ulonglong FUN_14015f940(undefined8 param_1,float param_2)



{

  ulonglong uVar1;

  longlong lVar2;

  undefined8 local_res18 [2];

  

  if (param_2 < 0.0) {

    uVar1 = FUN_14012e850("Parameter \'%s\' is invalid",&DAT_1403338ec);

    return uVar1;

  }

  local_res18[0] = 0;

  lVar2 = FUN_14015cb20(0,local_res18);

  if (lVar2 != 0) {

    *(float *)(lVar2 + 0x14) = param_2;

    FUN_14015fec0(local_res18[0]);

  }

  FUN_14015d3e0(local_res18[0]);

  return (ulonglong)(lVar2 != 0);

}




