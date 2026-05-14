// Address: 0x14018a030
// Ghidra name: FUN_14018a030
// ============ 0x14018a030 FUN_14018a030 (size=122) ============


void FUN_14018a030(undefined8 param_1,undefined8 *param_2,undefined8 *param_3,undefined4 *param_4)



{

  longlong lVar1;

  

  lVar1 = FUN_14012c130(param_1,&DAT_14039be7c);

  if (lVar1 == 0) {

    if (param_2 != (undefined8 *)0x0) {

      *param_2 = 0;

      *(undefined4 *)(param_2 + 1) = 0;

    }

    if (param_3 != (undefined8 *)0x0) {

      *param_3 = 0;

    }

    if (param_4 != (undefined4 *)0x0) {

      *param_4 = 0;

      return;

    }

  }

  else {

    FUN_140189e70(lVar1,1,param_2,param_3,param_4);

  }

  return;

}




