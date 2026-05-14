// Address: 0x14012bd50
// Ghidra name: FUN_14012bd50
// ============ 0x14012bd50 FUN_14012bd50 (size=70) ============


undefined1 FUN_14012bd50(longlong param_1)



{

  undefined1 uVar1;

  

  uVar1 = 1;

  if (param_1 != 0) {

    if (*(code **)(param_1 + 0x30) != (code *)0x0) {

      uVar1 = (**(code **)(param_1 + 0x30))(*(undefined8 *)(param_1 + 0x38));

    }

    FUN_1401747e0(*(undefined4 *)(param_1 + 0x44));

    FUN_1401841e0(param_1);

  }

  return uVar1;

}




