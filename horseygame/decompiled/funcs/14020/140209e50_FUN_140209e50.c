// Address: 0x140209e50
// Ghidra name: FUN_140209e50
// ============ 0x140209e50 FUN_140209e50 (size=102) ============


void FUN_140209e50(longlong param_1)



{

  longlong lVar1;

  longlong lVar2;

  longlong lVar3;

  

  lVar1 = DAT_1403ffc50;

  lVar3 = 0;

  if (DAT_1403ffc50 == 0) {

    return;

  }

  do {

    lVar2 = lVar1;

    if (lVar2 == param_1) {

      lVar1 = *(longlong *)(lVar2 + 0x58);

      if (lVar3 != 0) {

        *(longlong *)(lVar3 + 0x58) = *(longlong *)(lVar2 + 0x58);

        lVar1 = DAT_1403ffc50;

      }

      DAT_1403ffc50 = lVar1;

      DAT_1403fd1b4 = DAT_1403fd1b4 + -1;

      FUN_14015a550(*(undefined4 *)(param_1 + 0x50));

      FUN_14020ac40(param_1);

      return;

    }

    lVar1 = *(longlong *)(lVar2 + 0x58);

    lVar3 = lVar2;

  } while (*(longlong *)(lVar2 + 0x58) != 0);

  return;

}




