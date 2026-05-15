// Address: 0x1400edde0
// Ghidra name: FUN_1400edde0
// ============ 0x1400edde0 FUN_1400edde0 (size=142) ============


/* WARNING: Function: __chkstk replaced with injection: alloca_probe */



longlong FUN_1400edde0(undefined8 param_1,undefined4 *param_2,undefined4 *param_3,undefined8 param_4

                      )



{

  longlong lVar1;

  longlong lVar2;

  undefined4 local_4868;

  undefined4 local_4864;

  undefined8 uStack_10;

  

  uStack_10 = 0x1400eddfb;

  FUN_1402f94c0(&local_4868,0,0x4858);

  lVar1 = FUN_1400ede70(param_1,&local_4868,param_4);

  lVar2 = 0;

  if (lVar1 != 1) {

    lVar2 = lVar1;

  }

  if (lVar2 != 0) {

    *param_2 = local_4868;

    *param_3 = local_4864;

  }

  return lVar2;

}




