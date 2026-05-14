// Address: 0x14015e2b0
// Ghidra name: FUN_14015e2b0
// ============ 0x14015e2b0 FUN_14015e2b0 (size=124) ============


undefined8 FUN_14015e2b0(undefined8 param_1,undefined8 *param_2,undefined4 *param_3)



{

  undefined8 uVar1;

  longlong lVar2;

  

  if (param_2 == (undefined8 *)0x0) {

    uVar1 = FUN_14012e850("Parameter \'%s\' is invalid",&DAT_14031769c);

    return uVar1;

  }

  uVar1 = 0;

  lVar2 = FUN_14015cd00();

  if (lVar2 != 0) {

    *param_2 = *(undefined8 *)(lVar2 + 0x60);

    *(undefined4 *)(param_2 + 1) = *(undefined4 *)(lVar2 + 0x68);

    if (param_3 != (undefined4 *)0x0) {

      *param_3 = *(undefined4 *)(lVar2 + 0x84);

    }

    uVar1 = 1;

  }

  FUN_14015d3e0(lVar2);

  return uVar1;

}




