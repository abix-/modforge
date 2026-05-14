// Address: 0x14026cf50
// Ghidra name: FUN_14026cf50
// ============ 0x14026cf50 FUN_14026cf50 (size=59) ============


void FUN_14026cf50(longlong param_1,undefined1 *param_2)



{

  undefined1 uVar1;

  char cVar2;

  

  if ((*(short *)(param_1 + 0x20) == 0x57e) && (*(short *)(param_1 + 0x22) == 0x2019)) {

    cVar2 = '\0';

  }

  else {

    cVar2 = '\x01';

  }

  *param_2 = 0;

  param_2[1] = cVar2;

  uVar1 = 0x40;

  if (cVar2 == '\0') {

    uVar1 = 1;

  }

  param_2[2] = uVar1;

  param_2[3] = 0x40;

  return;

}




