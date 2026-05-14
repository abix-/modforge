// Address: 0x14006ac30
// Ghidra name: FUN_14006ac30
// ============ 0x14006ac30 FUN_14006ac30 (size=176) ============


void FUN_14006ac30(longlong param_1,int param_2)



{

  longlong lVar1;

  

  lVar1 = *(longlong *)(*(longlong *)(param_1 + 0x130) + (longlong)param_2 * 8);

  if ((lVar1 == *(longlong *)(param_1 + 0x2d0)) || (lVar1 == *(longlong *)(param_1 + 0x2d8))) {

    if (*(longlong *)(param_1 + 0x2e8) != 0) {

      FUN_140006230(*(undefined8 *)(param_1 + 0x98));

    }

    if (*(longlong *)(param_1 + 0x2d8) != 0) {

      FUN_1400b8420();

    }

    *(undefined8 *)(param_1 + 0x2d0) = 0;

    *(undefined8 *)(param_1 + 0x2d8) = 0;

    *(undefined8 *)(param_1 + 0x2e8) = 0;

    *(undefined4 *)(param_1 + 0x2e0) = 0;

  }

  return;

}




