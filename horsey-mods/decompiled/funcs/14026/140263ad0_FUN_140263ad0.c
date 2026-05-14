// Address: 0x140263ad0
// Ghidra name: FUN_140263ad0
// ============ 0x140263ad0 FUN_140263ad0 (size=214) ============


undefined4 FUN_140263ad0(longlong param_1)



{

  char *pcVar1;

  int iVar2;

  char local_48;

  undefined1 local_47 [63];

  

  pcVar1 = *(char **)(param_1 + 0x70);

  iVar2 = FUN_140193800(*(undefined8 *)(param_1 + 0x80),&local_48,0x40,0);

  while (0 < iVar2) {

    if (*pcVar1 == '\0') {

      FUN_140264200(param_1,pcVar1,&local_48,iVar2);

    }

    else if (iVar2 == 10) {

      FUN_140263e00(param_1,pcVar1,local_48 + -1,local_47,1);

    }

    else if (iVar2 == 9) {

      FUN_140263e00(param_1,pcVar1,0,&local_48,0);

    }

    iVar2 = FUN_140193800(*(undefined8 *)(param_1 + 0x80),&local_48,0x40,0);

  }

  if (pcVar1[0x51] != '\0') {

    FUN_140284590(param_1,pcVar1 + 0x4c,5);

    pcVar1[0x51] = '\0';

  }

  return 1;

}




