// Address: 0x140284e00
// Ghidra name: FUN_140284e00
// ============ 0x140284e00 FUN_140284e00 (size=111) ============


void FUN_140284e00(longlong param_1,undefined8 param_2)



{

  longlong lVar1;

  int iVar2;

  longlong lVar3;

  

  iVar2 = 0;

  if (0 < *(int *)(param_1 + 0xa8)) {

    lVar3 = 0;

    do {

      lVar1 = *(longlong *)(lVar3 + *(longlong *)(param_1 + 0xb0));

      (**(code **)(*(longlong *)(lVar1 + 0x68) + 0x88))(lVar1,param_2);

      iVar2 = iVar2 + 1;

      lVar3 = lVar3 + 8;

    } while (iVar2 < *(int *)(param_1 + 0xa8));

  }

  return;

}




