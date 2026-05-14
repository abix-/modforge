// Address: 0x140169150
// Ghidra name: FUN_140169150
// ============ 0x140169150 FUN_140169150 (size=121) ============


void FUN_140169150(longlong param_1)



{

  ulonglong uVar1;

  

  if (*(longlong *)(param_1 + 0x378) != 0) {

    uVar1 = 0;

    if (*(longlong *)(param_1 + 0x380) != 0) {

      do {

        FUN_1401841e0(*(undefined8 *)(*(longlong *)(param_1 + 0x378) + uVar1 * 8));

        uVar1 = uVar1 + 1;

      } while (uVar1 < *(ulonglong *)(param_1 + 0x380));

    }

    FUN_1401841e0(*(undefined8 *)(param_1 + 0x378));

    *(undefined8 *)(param_1 + 0x378) = 0;

    *(undefined8 *)(param_1 + 0x380) = 0;

  }

  return;

}




