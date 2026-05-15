// Address: 0x140170570
// Ghidra name: FUN_140170570
// ============ 0x140170570 FUN_140170570 (size=150) ============


undefined1 FUN_140170570(longlong param_1,longlong param_2)



{

  char cVar1;

  int iVar2;

  undefined8 *puVar3;

  

  puVar3 = DAT_1403fc410;

  cVar1 = FUN_14016f5c0();

  if ((cVar1 != '\0') && (iVar2 = strcmp((char *)*puVar3,"x11"), puVar3 = DAT_1403fc410, iVar2 != 0)

     ) {

    return 1;

  }

  if (param_2 == 0) {

    param_2 = param_1 + 0x20;

  }

  if (param_2 != *(longlong *)(param_1 + 0x48)) {

    if ((code *)puVar3[8] != (code *)0x0) {

      *(undefined1 *)(puVar3 + 0x72) = 1;

      cVar1 = (*(code *)puVar3[8])();

      *(undefined1 *)(DAT_1403fc410 + 0x72) = 0;

      if (cVar1 == '\0') {

        return 0;

      }

    }

    FUN_1401702f0(param_1,param_2);

  }

  return 1;

}




