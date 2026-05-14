// Address: 0x140217ac0
// Ghidra name: FUN_140217ac0
// ============ 0x140217ac0 FUN_140217ac0 (size=105) ============


void FUN_140217ac0(longlong *param_1,longlong param_2)



{

  longlong lVar1;

  char cVar2;

  

  lVar1 = param_1[1];

  if (lVar1 != 0) {

    cVar2 = FUN_14015da30(lVar1,param_2,*(undefined8 *)(lVar1 + 0x10),

                          *(undefined8 *)(param_2 + 0x10));

    if (cVar2 == '\0') {

      FUN_140217780(lVar1);

    }

    *(longlong *)(lVar1 + 0x20) = param_2;

    param_1[1] = param_2;

    return;

  }

  *param_1 = param_2;

  param_1[1] = param_2;

  return;

}




