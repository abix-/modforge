// Address: 0x1401425e0
// Ghidra name: FUN_1401425e0
// ============ 0x1401425e0 FUN_1401425e0 (size=67) ============


void FUN_1401425e0(undefined8 param_1,undefined8 *param_2)



{

  longlong lVar1;

  longlong lVar2;

  

  FUN_1401841e0(*param_2);

  lVar2 = param_2[2];

  while (lVar2 != 0) {

    lVar1 = *(longlong *)(lVar2 + 0x10);

    FUN_1401841e0(lVar2);

    lVar2 = lVar1;

  }

  FUN_1401841e0(param_2);

  return;

}




