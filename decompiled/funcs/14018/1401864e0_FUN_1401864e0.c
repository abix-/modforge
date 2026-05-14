// Address: 0x1401864e0
// Ghidra name: FUN_1401864e0
// ============ 0x1401864e0 FUN_1401864e0 (size=49) ============


int FUN_1401864e0(longlong param_1)



{

  int iVar1;

  undefined8 *puVar2;

  

  iVar1 = 0;

  puVar2 = DAT_1403fcb60;

  if (0 < DAT_1403fcb5c) {

    do {

      if (*(longlong *)*puVar2 == param_1) {

        return iVar1;

      }

      iVar1 = iVar1 + 1;

      puVar2 = puVar2 + 1;

    } while (iVar1 < DAT_1403fcb5c);

  }

  return -1;

}




