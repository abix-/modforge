// Address: 0x1401988b0
// Ghidra name: FUN_1401988b0
// ============ 0x1401988b0 FUN_1401988b0 (size=70) ============


void FUN_1401988b0(longlong param_1)



{

  char cVar1;

  

  if (param_1 != 0) {

    if ((*(byte *)(param_1 + 0x1010) & 2) != 0) {

      cVar1 = FUN_140198d00();

      FUN_140199410(param_1,cVar1 == '\0');

    }

    if (*(code **)(param_1 + 0x1018) != (code *)0x0) {

      (**(code **)(param_1 + 0x1018))(*(undefined8 *)(param_1 + 0x1020),param_1);

    }

  }

  return;

}




