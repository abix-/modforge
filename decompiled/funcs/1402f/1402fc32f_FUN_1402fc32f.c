// Address: 0x1402fc32f
// Ghidra name: FUN_1402fc32f
// ============ 0x1402fc32f FUN_1402fc32f (size=44) ============


void FUN_1402fc32f(undefined8 param_1,longlong param_2)



{

  if ((*(uint *)(param_2 + 0x1b8) & 2) != 0) {

    *(uint *)(param_2 + 0x1b8) = *(uint *)(param_2 + 0x1b8) & 0xfffffffd;

    FUN_140027900(param_2 + 0x60);

  }

  return;

}




