// Address: 0x1401cb510
// Ghidra name: FUN_1401cb510
// ============ 0x1401cb510 FUN_1401cb510 (size=98) ============


void FUN_1401cb510(undefined8 param_1,undefined4 param_2,longlong param_3)



{

  uint uVar1;

  ulonglong uVar2;

  

  uVar2 = 0;

  if (*(int *)(param_3 + 0x18) != 0) {

    do {

      FUN_1401cb470(param_1,param_2,uVar2 * 0x60 + *(longlong *)(param_3 + 0x10));

      uVar1 = (int)uVar2 + 1;

      uVar2 = (ulonglong)uVar1;

    } while (uVar1 < *(uint *)(param_3 + 0x18));

  }

  return;

}




