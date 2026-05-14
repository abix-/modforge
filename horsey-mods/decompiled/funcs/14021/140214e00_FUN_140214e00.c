// Address: 0x140214e00
// Ghidra name: FUN_140214e00
// ============ 0x140214e00 FUN_140214e00 (size=219) ============


void FUN_140214e00(longlong param_1)



{

  longlong lVar1;

  longlong lVar2;

  

  if ((param_1 != 0) && (lVar1 = *(longlong *)(param_1 + 200), lVar1 != 0)) {

    lVar2 = *(longlong *)(lVar1 + 0x10);

    if (lVar2 != 0) {

      *(undefined8 *)(lVar1 + 0x10) = 0;

      FUN_140215240(FUN_140215d70,lVar2,0);

    }

    lVar1 = *(longlong *)(*(longlong *)(param_1 + 200) + 0x18);

    if (lVar1 != 0) {

      *(undefined8 *)(*(longlong *)(param_1 + 200) + 0x18) = 0;

      FUN_140215240(FUN_140215d50,lVar1,0);

    }

    lVar1 = *(longlong *)(*(longlong *)(param_1 + 200) + 0x20);

    if (lVar1 != 0) {

      *(undefined8 *)(*(longlong *)(param_1 + 200) + 0x20) = 0;

      FUN_140215240(FUN_140215d50,lVar1,0);

    }

    lVar1 = *(longlong *)(*(longlong *)(param_1 + 200) + 8);

    if (lVar1 != 0) {

      *(undefined8 *)(*(longlong *)(param_1 + 200) + 8) = 0;

      FUN_140215240(FUN_1402157f0,lVar1,0);

    }

    lVar1 = *(longlong *)(*(longlong *)(param_1 + 200) + 0x28);

    if (lVar1 != 0) {

      *(undefined8 *)(*(longlong *)(param_1 + 200) + 0x28) = 0;

      FUN_140215240(FUN_1402157d0,lVar1,0);

    }

  }

  return;

}




