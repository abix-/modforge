// Address: 0x1401a82c0
// Ghidra name: FUN_1401a82c0
// ============ 0x1401a82c0 FUN_1401a82c0 (size=109) ============


undefined4 FUN_1401a82c0(longlong param_1)



{

  int iVar1;

  longlong *plVar2;

  undefined4 uVar3;

  

  FUN_14017caa0(DAT_1403fcd48);

  iVar1 = 0;

  uVar3 = 0;

  if (0 < DAT_1403fcd44) {

    plVar2 = (longlong *)(DAT_1403fcd50 + 0x58);

    do {

      if (*plVar2 == param_1) {

        uVar3 = *(undefined4 *)((longlong)iVar1 * 0x60 + DAT_1403fcd50);

        break;

      }

      iVar1 = iVar1 + 1;

      plVar2 = plVar2 + 0xc;

      uVar3 = 0;

    } while (iVar1 < DAT_1403fcd44);

  }

  FUN_14017cae0(DAT_1403fcd48);

  return uVar3;

}




