// Address: 0x140160150
// Ghidra name: FUN_140160150
// ============ 0x140160150 FUN_140160150 (size=203) ============


ulonglong FUN_140160150(undefined8 param_1,longlong param_2,ulonglong param_3)



{

  undefined1 auVar1 [16];

  undefined1 auVar2 [16];

  DWORD DVar3;

  int iVar4;

  undefined8 in_RAX;

  undefined4 extraout_var;

  ulonglong uVar5;

  

  auVar2._8_8_ = param_2;

  auVar2._0_8_ = in_RAX;

  if ((longlong)param_3 < 0) {

    param_3 = 0xffffffff;

  }

  else {

    auVar1._8_8_ = 0;

    auVar1._0_8_ = param_3;

    auVar2 = ZEXT816(0x431bde82d7b634db) * auVar1;

    param_3 = param_3 / 1000000;

  }

  uVar5 = auVar2._0_8_;

  if (DAT_1403fc528 == 1) {

    if (*(int *)(param_2 + 8) == 1) {

      DVar3 = GetCurrentThreadId();

      uVar5 = CONCAT44(extraout_var,DVar3);

      if (*(DWORD *)(param_2 + 0xc) == DVar3) {

        *(undefined8 *)(param_2 + 8) = 0;

        iVar4 = (*DAT_1403fc1b0)(param_1,param_2,param_3 & 0xffffffff,0);

        *(undefined4 *)(param_2 + 8) = 1;

        DVar3 = GetCurrentThreadId();

        *(DWORD *)(param_2 + 0xc) = DVar3;

        return (ulonglong)(iVar4 == 1);

      }

    }

    return uVar5 & 0xffffffffffffff00;

  }

  iVar4 = (*DAT_1403fc1b8)(param_1,param_2,param_3 & 0xffffffff);

  return (ulonglong)(iVar4 == 1);

}




