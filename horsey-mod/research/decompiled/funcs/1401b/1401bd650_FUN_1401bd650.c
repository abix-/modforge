// Address: 0x1401bd650
// Ghidra name: FUN_1401bd650
// ============ 0x1401bd650 FUN_1401bd650 (size=108) ============


void FUN_1401bd650(undefined8 param_1,undefined8 param_2,undefined4 param_3,longlong param_4)



{

  uint uVar1;

  ulonglong uVar2;

  

  uVar2 = 0;

  if (*(int *)(param_4 + 0x44) != 0) {

    do {

      FUN_1401bd590(param_1,param_2,param_3,*(longlong *)(param_4 + 0x48) + uVar2 * 0x28);

      uVar1 = (int)uVar2 + 1;

      uVar2 = (ulonglong)uVar1;

    } while (uVar1 < *(uint *)(param_4 + 0x44));

  }

  return;

}




