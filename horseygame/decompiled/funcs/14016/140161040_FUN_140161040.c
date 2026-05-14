// Address: 0x140161040
// Ghidra name: FUN_140161040
// ============ 0x140161040 FUN_140161040 (size=99) ============


void FUN_140161040(undefined4 *param_1,undefined4 *param_2)



{

  longlong lVar1;

  undefined4 *puVar2;

  undefined4 *puVar3;

  undefined4 local_res18 [2];

  undefined4 local_res20 [2];

  

  lVar1 = FUN_1401611a0();

  if (*(longlong *)(lVar1 + 0x50) != 0) {

    puVar2 = local_res18;

    if (param_1 != (undefined4 *)0x0) {

      puVar2 = param_1;

    }

    puVar3 = local_res20;

    if (param_2 != (undefined4 *)0x0) {

      puVar3 = param_2;

    }

    *puVar3 = 0;

    *puVar2 = 0;

    (**(code **)(lVar1 + 0x50))();

    return;

  }

  FUN_1401612e0(param_1,param_2);

  return;

}




