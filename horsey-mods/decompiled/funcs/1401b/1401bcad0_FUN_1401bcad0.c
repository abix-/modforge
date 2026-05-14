// Address: 0x1401bcad0
// Ghidra name: FUN_1401bcad0
// ============ 0x1401bcad0 FUN_1401bcad0 (size=158) ============


void FUN_1401bcad0(longlong param_1,undefined8 param_2)



{

  uint uVar1;

  ulonglong uVar2;

  undefined8 local_28;

  longlong local_20;

  undefined8 local_18;

  

  local_28 = 8;

  uVar2 = 0;

  local_18 = param_2;

  local_20 = FUN_1401841f0(0x40);

  if (local_20 != 0) {

    FUN_140179b40(*(undefined8 *)(param_1 + 0x8f0));

    FUN_1401ab210(*(undefined8 *)(param_1 + 0x808),FUN_1401adae0,&local_28);

    if (local_28._4_4_ != 0) {

      do {

        FUN_1401ab340(*(undefined8 *)(param_1 + 0x808),*(undefined8 *)(local_20 + uVar2 * 8));

        uVar1 = (int)uVar2 + 1;

        uVar2 = (ulonglong)uVar1;

      } while (uVar1 < local_28._4_4_);

    }

    FUN_140179b60(*(undefined8 *)(param_1 + 0x8f0));

    FUN_1401841e0(local_20);

  }

  return;

}




