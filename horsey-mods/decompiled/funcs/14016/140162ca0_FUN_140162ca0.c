// Address: 0x140162ca0
// Ghidra name: FUN_140162ca0
// ============ 0x140162ca0 FUN_140162ca0 (size=108) ============


void FUN_140162ca0(longlong param_1)



{

  longlong lVar1;

  longlong lVar2;

  

  lVar2 = FUN_1401611a0();

  lVar1 = *(longlong *)(lVar2 + 0x88);

  if (lVar1 != param_1) {

    if (lVar1 != 0) {

      FUN_1401cda90(lVar1,0x20d,0,0);

    }

    *(longlong *)(lVar2 + 0x88) = param_1;

    *(undefined1 *)(lVar2 + 0xc0) = 0;

    if (param_1 != 0) {

      FUN_1401cda90(param_1,0x20c,0,0);

    }

    FUN_140162700();

  }

  return;

}




