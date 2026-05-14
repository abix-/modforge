// Address: 0x1402fccd6
// Ghidra name: FUN_1402fccd6
// ============ 0x1402fccd6 FUN_1402fccd6 (size=38) ============


void FUN_1402fccd6(undefined8 param_1,longlong param_2)



{

  if ((*(uint *)(param_2 + 0x60) & 1) != 0) {

    *(uint *)(param_2 + 0x60) = *(uint *)(param_2 + 0x60) & 0xfffffffe;

    FUN_140027900(param_2 + 0x30);

  }

  return;

}




