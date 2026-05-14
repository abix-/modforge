// Address: 0x1402fe333
// Ghidra name: FUN_1402fe333
// ============ 0x1402fe333 FUN_1402fe333 (size=47) ============


void FUN_1402fe333(undefined8 param_1,longlong param_2)



{

  if ((*(uint *)(param_2 + 0x158) & 1) != 0) {

    *(uint *)(param_2 + 0x158) = *(uint *)(param_2 + 0x158) & 0xfffffffe;

    FUN_140027900(param_2 + 200);

  }

  return;

}




