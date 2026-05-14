// Address: 0x14012c650
// Ghidra name: FUN_14012c650
// ============ 0x14012c650 FUN_14012c650 (size=61) ============


undefined8 FUN_14012c650(undefined8 param_1,undefined8 *param_2)



{

  longlong lVar1;

  undefined8 uVar2;

  

  lVar1 = FUN_14012c130(param_1,&DAT_14039be7c);

  if (lVar1 == 0) {

    if (param_2 != (undefined8 *)0x0) {

      *param_2 = 0;

    }

    return 0;

  }

  uVar2 = FUN_14012c500(lVar1,param_2,1);

  return uVar2;

}




