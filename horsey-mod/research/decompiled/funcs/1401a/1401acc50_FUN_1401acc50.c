// Address: 0x1401acc50
// Ghidra name: FUN_1401acc50
// ============ 0x1401acc50 FUN_1401acc50 (size=177) ============


void FUN_1401acc50(longlong *param_1,undefined4 *param_2,undefined4 *param_3)



{

  int iVar1;

  undefined4 uVar2;

  ulonglong uVar3;

  undefined **ppuVar4;

  undefined1 local_28 [16];

  

  iVar1 = (**(code **)(*param_1 + 0x50))(param_1,&DAT_14033cb20,local_28);

  if (-1 < iVar1) {

    uVar3 = 0;

    ppuVar4 = &PTR_DAT_14033ccd0;

    do {

      iVar1 = FUN_1401a98e0(local_28,*ppuVar4);

      if (iVar1 != 0) {

        *param_2 = (&DAT_14033ccd8)[uVar3 * 4];

        uVar2 = FUN_1401abee0(param_1,(&DAT_14033ccdc)[uVar3 * 4]);

        *param_3 = uVar2;

        return;

      }

      uVar3 = uVar3 + 1;

      ppuVar4 = ppuVar4 + 2;

    } while (uVar3 < 0xe);

  }

  *param_2 = 0;

  *param_3 = 0;

  return;

}




