// Address: 0x1402ff867
// Ghidra name: FUN_1402ff867
// ============ 0x1402ff867 FUN_1402ff867 (size=44) ============


void FUN_1402ff867(undefined8 param_1,longlong param_2)



{

  if ((*(uint *)(param_2 + 0x210) & 2) != 0) {

    *(uint *)(param_2 + 0x210) = *(uint *)(param_2 + 0x210) & 0xfffffffd;

    FUN_140027900(param_2 + 0x30);

  }

  return;

}




