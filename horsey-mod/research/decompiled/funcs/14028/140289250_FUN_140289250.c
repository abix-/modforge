// Address: 0x140289250
// Ghidra name: FUN_140289250
// ============ 0x140289250 FUN_140289250 (size=224) ============


ulonglong FUN_140289250(ulonglong *param_1)



{

  int iVar1;

  code *pcVar2;

  ulonglong uVar3;

  ulonglong uVar4;

  longlong *local_res10 [3];

  

  uVar3 = DAT_1403fde70;

  if (DAT_1403fde78 != 0) {

    DAT_1403fde78 = DAT_1403fde78 + 1;

    uVar4 = (ulonglong)DAT_1403fde78;

    if (param_1 != (ulonglong *)0x0) {

      *param_1 = DAT_1403fde70;

      uVar4 = uVar3;

    }

    return CONCAT71((int7)(uVar4 >> 8),1);

  }

  DAT_1403fde68 = FUN_1401885b0("gameinput.dll");

  uVar3 = 0;

  if (DAT_1403fde68 != 0) {

    pcVar2 = (code *)FUN_140188550(DAT_1403fde68,"GameInputCreate");

    if (pcVar2 != (code *)0x0) {

      local_res10[0] = (longlong *)0x0;

      iVar1 = (*pcVar2)(local_res10);

      if (iVar1 < 0) {

        FUN_140188670(DAT_1403fde68);

        uVar3 = FUN_1401a9ef0("GameInputCreate failed",iVar1);

        return uVar3;

      }

      (**(code **)(*local_res10[0] + 0x10))();

      FUN_140188670(DAT_1403fde68);

      uVar3 = FUN_1401a9ef0("GameInput QueryInterface failed",0x80004002);

      return uVar3;

    }

    uVar3 = FUN_140188670(DAT_1403fde68);

  }

  return uVar3 & 0xffffffffffffff00;

}




