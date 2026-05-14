// Address: 0x14015a220
// Ghidra name: FUN_14015a220
// ============ 0x14015a220 FUN_14015a220 (size=143) ============


void FUN_14015a220(longlong param_1,int param_2)



{

  int iVar1;

  longlong lVar2;

  longlong lVar3;

  longlong lVar4;

  

  iVar1 = *(int *)(param_1 + 0x80);

  lVar4 = (longlong)iVar1 * 0x10;

  lVar2 = FUN_140184230(*(undefined8 *)(param_1 + 0x88),lVar4 + 0x10);

  if (lVar2 != 0) {

    lVar3 = FUN_1401841a0((longlong)param_2,0x10);

    if (lVar3 == 0) {

      param_2 = 0;

    }

    *(int *)(lVar4 + lVar2) = param_2;

    *(longlong *)(lVar4 + 8 + lVar2) = lVar3;

    *(int *)(param_1 + 0x80) = iVar1 + 1;

    *(longlong *)(param_1 + 0x88) = lVar2;

  }

  return;

}




