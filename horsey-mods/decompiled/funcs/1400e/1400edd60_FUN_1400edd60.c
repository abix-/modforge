// Address: 0x1400edd60
// Ghidra name: FUN_1400edd60
// ============ 0x1400edd60 FUN_1400edd60 (size=125) ============


/* WARNING: Function: __chkstk replaced with injection: alloca_probe */



undefined8

FUN_1400edd60(longlong param_1,undefined4 *param_2,undefined4 *param_3,undefined8 param_4)



{

  int iVar1;

  undefined8 uVar2;

  undefined4 local_4868;

  undefined4 local_4864;

  undefined8 uStack_10;

  

  uStack_10 = 0x1400edd75;

  iVar1 = FUN_1400eda80(param_1,&local_4868,param_4,1);

  if (iVar1 == 0) {

    *(undefined8 *)(param_1 + 0xb8) = *(undefined8 *)(param_1 + 200);

    uVar2 = 0;

  }

  else {

    if (param_2 != (undefined4 *)0x0) {

      *param_2 = local_4868;

    }

    if (param_3 != (undefined4 *)0x0) {

      *param_3 = local_4864;

    }

    uVar2 = 1;

  }

  return uVar2;

}




