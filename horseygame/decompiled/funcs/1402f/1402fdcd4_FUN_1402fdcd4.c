// Address: 0x1402fdcd4
// Ghidra name: FUN_1402fdcd4
// ============ 0x1402fdcd4 FUN_1402fdcd4 (size=44) ============


void FUN_1402fdcd4(undefined8 param_1,longlong param_2)



{

  if ((*(uint *)(param_2 + 200) & 1) != 0) {

    *(uint *)(param_2 + 200) = *(uint *)(param_2 + 200) & 0xfffffffe;

    FUN_140027900(param_2 + 0x30);

  }

  return;

}




