// Address: 0x1400e3420
// Ghidra name: FUN_1400e3420
// ============ 0x1400e3420 FUN_1400e3420 (size=178) ============


void FUN_1400e3420(longlong param_1)



{

  int iVar1;

  longlong lVar2;

  undefined8 uVar3;

  

  FUN_14006d580(param_1 + 0x25c);

  FUN_140075b80(param_1 + 0x46c);

  FUN_140075e80(param_1 + 0x470);

  iVar1 = FUN_140075da0();

  if (iVar1 != 0) {

    lVar2 = FUN_1402c704c(0x498);

    uVar3 = 0;

    if (lVar2 != 0) {

      uVar3 = FUN_1400aac60(lVar2);

    }

    *(undefined8 *)(param_1 + 0x458) = uVar3;

    FUN_14006f150(uVar3);

  }

  if (*(int *)(param_1 + 600) == 0) {

    FUN_140075e80(&DAT_1403da920);

    FUN_140075e80(&DAT_1403da921);

    FUN_140075e80(&DAT_1403f4bb0);

    FUN_140075e80(&DAT_1403f4bb1);

    FUN_140075e80(&DAT_1403f4bb2);

    return;

  }

  return;

}




