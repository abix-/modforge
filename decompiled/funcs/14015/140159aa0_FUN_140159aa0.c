// Address: 0x140159aa0
// Ghidra name: FUN_140159aa0
// ============ 0x140159aa0 FUN_140159aa0 (size=168) ============


void FUN_140159aa0(longlong *param_1)



{

  longlong lVar1;

  longlong lVar2;

  

  lVar2 = 0;

  if (*param_1 != 0) {

    FUN_1401427d0(*param_1,FUN_14015bf80,param_1);

  }

  if (param_1[3] != 0) {

    FUN_1401427d0(param_1[3],FUN_14015bee0,param_1);

  }

  *(undefined1 *)(param_1 + 8) = 1;

  lVar1 = lVar2;

  if (*param_1 != 0) {

    lVar1 = FUN_140142960();

    if (lVar1 == 0) {

      lVar1 = FUN_1401796b0(*param_1);

    }

  }

  if (param_1[3] != 0) {

    lVar2 = FUN_140142960();

    if (lVar2 == 0) {

      lVar2 = FUN_1401796b0(param_1[3]);

    }

  }

  FUN_140159c80(param_1,lVar1,lVar2);

  return;

}




