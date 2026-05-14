// Address: 0x1401b8fa0
// Ghidra name: FUN_1401b8fa0
// ============ 0x1401b8fa0 FUN_1401b8fa0 (size=248) ============


void FUN_1401b8fa0(longlong param_1,longlong param_2)



{

  longlong lVar1;

  uint uVar2;

  ulonglong uVar3;

  

  (**(code **)(param_1 + 0xb78))(*(undefined8 *)(param_1 + 0x570),*(undefined8 *)(param_2 + 8),0);

  uVar3 = 0;

  if (*(int *)(param_2 + 0x1c) != 0) {

    do {

      lVar1 = *(longlong *)(*(longlong *)(param_2 + 0x10) + uVar3 * 8);

      FUN_1401841e0(*(undefined8 *)(lVar1 + 0x128));

      FUN_1401841e0(*(undefined8 *)(lVar1 + 0x138));

      FUN_1401841e0(*(undefined8 *)(lVar1 + 0x148));

      FUN_1401841e0(*(undefined8 *)(lVar1 + 0xa00));

      FUN_1401841e0(*(undefined8 *)(lVar1 + 0xa20));

      FUN_1401841e0(*(undefined8 *)(lVar1 + 0xa40));

      FUN_1401841e0(*(undefined8 *)(lVar1 + 0xa50));

      FUN_1401841e0(*(undefined8 *)(lVar1 + 0xa60));

      FUN_1401841e0(*(undefined8 *)(lVar1 + 0xa70));

      FUN_1401841e0(*(undefined8 *)(lVar1 + 0xa80));

      FUN_1401841e0(lVar1);

      uVar2 = (int)uVar3 + 1;

      uVar3 = (ulonglong)uVar2;

    } while (uVar2 < *(uint *)(param_2 + 0x1c));

  }

  FUN_1401841e0(*(undefined8 *)(param_2 + 0x10));

  FUN_1401841e0(param_2);

  return;

}




