// Address: 0x1402fc300
// Ghidra name: FUN_1402fc300
// ============ 0x1402fc300 FUN_1402fc300 (size=47) ============


void FUN_1402fc300(undefined8 param_1,longlong param_2)



{

  if ((*(uint *)(param_2 + 0x1b8) & 1) != 0) {

    *(uint *)(param_2 + 0x1b8) = *(uint *)(param_2 + 0x1b8) & 0xfffffffe;

    FUN_140027900(param_2 + 0x80);

  }

  return;

}




