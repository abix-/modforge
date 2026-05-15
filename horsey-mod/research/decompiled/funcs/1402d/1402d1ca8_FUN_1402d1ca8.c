// Address: 0x1402d1ca8
// Ghidra name: FUN_1402d1ca8
// ============ 0x1402d1ca8 FUN_1402d1ca8 (size=168) ============


bool FUN_1402d1ca8(longlong param_1,ulonglong param_2,longlong param_3)



{

  longlong lVar1;

  bool bVar2;

  

  if (param_2 < 0x8000000000000000) {

    param_2 = param_2 * 2;

    if (((*(longlong *)(param_1 + 0x408) == 0) && (param_2 < 0x401)) ||

       (param_2 <= *(ulonglong *)(param_1 + 0x400))) {

      bVar2 = true;

    }

    else {

      lVar1 = _malloc_base(param_2);

      bVar2 = lVar1 != 0;

      if (bVar2) {

        FUN_1402e9a80(*(undefined8 *)(param_1 + 0x408));

        *(longlong *)(param_1 + 0x408) = lVar1;

        *(ulonglong *)(param_1 + 0x400) = param_2;

      }

      FUN_1402e9a80(0);

    }

  }

  else {

    *(undefined1 *)(param_3 + 0x30) = 1;

    bVar2 = false;

    *(undefined4 *)(param_3 + 0x2c) = 0xc;

  }

  return bVar2;

}




