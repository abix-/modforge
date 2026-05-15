// Address: 0x1400ee920
// Ghidra name: FUN_1400ee920
// ============ 0x1400ee920 FUN_1400ee920 (size=135) ============


/* WARNING: Function: __chkstk replaced with injection: alloca_probe */



undefined8

FUN_1400ee920(undefined4 *param_1,undefined4 *param_2,undefined4 *param_3,undefined4 *param_4)



{

  int iVar1;

  undefined8 uVar2;

  undefined4 *local_36f8 [1757];

  undefined8 uStack_10;

  

  uStack_10 = 0x1400ee935;

  local_36f8[0] = param_1;

  iVar1 = FUN_1400e8760(local_36f8,2);

  if (iVar1 == 0) {

    *(undefined8 *)(local_36f8[0] + 0x2e) = *(undefined8 *)(local_36f8[0] + 0x32);

    uVar2 = 0;

  }

  else {

    if (param_2 != (undefined4 *)0x0) {

      *param_2 = *local_36f8[0];

    }

    if (param_3 != (undefined4 *)0x0) {

      *param_3 = local_36f8[0][1];

    }

    if (param_4 != (undefined4 *)0x0) {

      *param_4 = local_36f8[0][2];

    }

    uVar2 = 1;

  }

  return uVar2;

}




