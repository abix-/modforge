// Address: 0x140195e10
// Ghidra name: FUN_140195e10
// ============ 0x140195e10 FUN_140195e10 (size=255) ============


void FUN_140195e10(longlong param_1,undefined4 param_2)



{

  int iVar1;

  longlong lVar2;

  undefined4 local_res8 [2];

  

  lVar2 = FUN_14012fd40(*(undefined8 *)(param_1 + 0x20));

  if ((lVar2 == 0) && (lVar2 = FUN_1401961b0(param_2,&DAT_1403e3af0,0x12), lVar2 != 0)) {

    FUN_1401841e0(*(undefined8 *)(param_1 + 0x20));

    *(longlong *)(param_1 + 0x20) = lVar2;

  }

  lVar2 = FUN_14012fd40(*(undefined8 *)(param_1 + 0x10));

  if ((lVar2 == 0) && (lVar2 = FUN_1401961b0(param_2,&DAT_1403e3ad8,0x12), lVar2 != 0)) {

    FUN_1401841e0(*(undefined8 *)(param_1 + 0x10));

    *(longlong *)(param_1 + 0x10) = lVar2;

  }

  lVar2 = FUN_14012fd40(*(undefined8 *)(param_1 + 0x28));

  if (lVar2 != 0) {

    return;

  }

  lVar2 = FUN_1401961b0(param_2,&DAT_1403e3b08,0x12);

  if (lVar2 == 0) {

    local_res8[0] = (int)lVar2;

    iVar1 = (*DAT_1403fccc0)(local_res8,param_2,0);

    if (iVar1 != 0) {

      return;

    }

    lVar2 = FUN_1401961b0(local_res8[0],&DAT_1403e3a48,0x12);

    if (lVar2 == 0) {

      return;

    }

  }

  FUN_1401841e0(*(undefined8 *)(param_1 + 0x28));

  *(longlong *)(param_1 + 0x28) = lVar2;

  return;

}




