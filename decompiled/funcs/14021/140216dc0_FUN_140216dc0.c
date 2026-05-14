// Address: 0x140216dc0
// Ghidra name: FUN_140216dc0
// ============ 0x140216dc0 FUN_140216dc0 (size=79) ============


void FUN_140216dc0(longlong param_1)



{

  if (*(longlong **)(param_1 + 200) != (longlong *)0x0) {

    if (**(longlong **)(param_1 + 200) != 0) {

      FUN_14012bd50();

    }

    FUN_1401841e0(*(undefined8 *)(*(longlong *)(param_1 + 200) + 0x10));

    FUN_1401841e0(*(undefined8 *)(param_1 + 200));

    *(undefined8 *)(param_1 + 200) = 0;

  }

  return;

}




