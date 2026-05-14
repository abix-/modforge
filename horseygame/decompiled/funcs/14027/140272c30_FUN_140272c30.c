// Address: 0x140272c30
// Ghidra name: FUN_140272c30
// ============ 0x140272c30 FUN_140272c30 (size=125) ============


void FUN_140272c30(longlong param_1)



{

  if ((((*(char *)(param_1 + 0x20) != '\0') && (*(char *)(param_1 + 0x12) != '\0')) &&

      (*(char *)(param_1 + 0x11) == '\0')) && (*(uint *)(param_1 + 0x9f) < 10200000)) {

    return;

  }

  FUN_140274300(param_1,4,0);

  *(undefined4 *)(param_1 + 0x74) = 2;

  FUN_140274300(param_1,0x18,0);

  return;

}




