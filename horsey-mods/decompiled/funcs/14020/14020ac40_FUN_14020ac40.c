// Address: 0x14020ac40
// Ghidra name: FUN_14020ac40
// ============ 0x14020ac40 FUN_14020ac40 (size=114) ============


void FUN_14020ac40(longlong param_1)



{

  int iVar1;

  longlong lVar2;

  

  if (((*(longlong *)(param_1 + 0x48) != 0) &&

      (lVar2 = *(longlong *)(*(longlong *)(param_1 + 0x48) + 0x148), *(char *)(lVar2 + 0x50) != '\0'

      )) && (*(char *)(lVar2 + 0x51) != '\0')) {

    FUN_14020a8b0(*(undefined1 *)(lVar2 + 0x55));

    *(undefined1 *)(lVar2 + 0x51) = 0;

  }

  iVar1 = FUN_140138fb0(param_1,0xffffffff);

  if (iVar1 == 1) {

    FUN_1401841e0(*(undefined8 *)(param_1 + 0x38));

    FUN_1401841e0(*(undefined8 *)(param_1 + 8));

    FUN_1401841e0(*(undefined8 *)(param_1 + 0x10));

    FUN_1401841e0(param_1);

    return;

  }

  return;

}




