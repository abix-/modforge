// Address: 0x140279dd0
// Ghidra name: FUN_140279dd0
// ============ 0x140279dd0 FUN_140279dd0 (size=109) ============


void FUN_140279dd0(longlong param_1)



{

  int iVar1;

  longlong lVar2;

  char *pcVar3;

  

  lVar2 = *(longlong *)(param_1 + 0x70);

  iVar1 = *(int *)(lVar2 + 0x1c);

  if (iVar1 == 0x80) {

    pcVar3 = "Nintendo Wii Remote";

  }

  else if (iVar1 == 0x81) {

    pcVar3 = "Nintendo Wii Remote with Nunchuk";

  }

  else if (iVar1 == 0x82) {

    pcVar3 = "Nintendo Wii Remote with Classic Controller";

  }

  else if (iVar1 == 0x83) {

    pcVar3 = "Nintendo Wii U Pro Controller";

  }

  else {

    pcVar3 = "Nintendo Wii Remote with Unknown Extension";

  }

  FUN_1402083c0(param_1,pcVar3);

  *(undefined1 *)(param_1 + 0x3f) = *(undefined1 *)(lVar2 + 0x1c);

  return;

}




