// Address: 0x140225110
// Ghidra name: FUN_140225110
// ============ 0x140225110 FUN_140225110 (size=102) ============


void FUN_140225110(longlong param_1)



{

  undefined1 uVar1;

  HKL pHVar2;

  

  pHVar2 = GetKeyboardLayout(0);

  if (pHVar2 != *(HKL *)(param_1 + 0x248)) {

    *(HKL *)(param_1 + 0x248) = pHVar2;

    if ((((ushort)pHVar2 & 0x3ff) == 0x12) || ((ushort)pHVar2 == 0x804)) {

      uVar1 = 1;

    }

    else {

      uVar1 = 0;

    }

    *(undefined1 *)(param_1 + 0x208) = uVar1;

    *(uint *)(param_1 + 0x204) = (uint)(pHVar2 != (HKL)0xe0060404);

  }

  return;

}




