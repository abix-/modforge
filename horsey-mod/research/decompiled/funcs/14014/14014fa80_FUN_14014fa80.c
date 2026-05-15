// Address: 0x14014fa80
// Ghidra name: FUN_14014fa80
// ============ 0x14014fa80 FUN_14014fa80 (size=225) ============


void FUN_14014fa80(longlong param_1)



{

  undefined4 uVar1;

  longlong lVar2;

  undefined8 uVar3;

  

  uVar1 = FUN_14016ea50(*(undefined8 *)(param_1 + 0x118));

  lVar2 = FUN_140174d30(uVar1,"SDL.window.shape",0);

  if (lVar2 != *(longlong *)(param_1 + 0x2b8)) {

    if (*(longlong *)(param_1 + 0x2c0) != 0) {

      FUN_14014dd50();

      *(undefined8 *)(param_1 + 0x2c0) = 0;

    }

    if (lVar2 != 0) {

      uVar3 = FUN_14014c790(param_1,lVar2);

      *(undefined8 *)(param_1 + 0x2c0) = uVar3;

      uVar1 = FUN_14014baa0(1,5,1,1,5,1);

      FUN_140154fa0(uVar3,uVar1);

    }

    *(longlong *)(param_1 + 0x2b8) = lVar2;

  }

  if (*(longlong *)(param_1 + 0x2c0) != 0) {

    FUN_140153570(param_1,*(longlong *)(param_1 + 0x2c0),0,0);

    return;

  }

  return;

}




