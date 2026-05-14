// Address: 0x1401dd2f0
// Ghidra name: FUN_1401dd2f0
// ============ 0x1401dd2f0 FUN_1401dd2f0 (size=111) ============


void FUN_1401dd2f0(longlong param_1,longlong param_2)



{

  longlong lVar1;

  longlong lVar2;

  

  lVar1 = *(longlong *)(param_2 + 0x10);

  lVar2 = *(longlong *)(param_1 + 0x2e0);

  if (lVar1 != 0) {

    FUN_1401dd680(lVar1);

    if (*(longlong *)(lVar2 + 0x198) == lVar1) {

      *(undefined8 *)(lVar2 + 0x198) = *(undefined8 *)(lVar1 + 0x30);

    }

    else {

      lVar2 = *(longlong *)(lVar1 + 0x28);

      if (lVar2 != 0) {

        *(undefined8 *)(lVar2 + 0x30) = *(undefined8 *)(lVar1 + 0x30);

      }

    }

    if (*(longlong *)(lVar1 + 0x30) != 0) {

      *(longlong *)(*(longlong *)(lVar1 + 0x30) + 0x28) = *(longlong *)(lVar1 + 0x28);

    }

    FUN_1401841e0(lVar1);

  }

  return;

}




