// Address: 0x1400c5c80
// Ghidra name: FUN_1400c5c80
// ============ 0x1400c5c80 FUN_1400c5c80 (size=138) ============


void FUN_1400c5c80(longlong param_1,int param_2)



{

  undefined4 uVar1;

  ulonglong uVar2;

  ulonglong uVar3;

  longlong lVar4;

  ulonglong uVar5;

  undefined4 *puVar6;

  

  if ((1 < param_2) && (0 < (int)(param_2 - 1U))) {

    uVar2 = (ulonglong)param_2;

    uVar5 = (ulonglong)(param_2 - 1U);

    puVar6 = (undefined4 *)(param_1 + -4 + uVar2 * 4);

    do {

      uVar1 = *puVar6;

      uVar3 = DAT_1403da740 << 0xd ^ DAT_1403da740;

      uVar3 = uVar3 >> 7 ^ uVar3;

      DAT_1403da740 = uVar3 << 0x11 ^ uVar3;

      uVar3 = DAT_1403da740 % uVar2;

      uVar2 = uVar2 - 1;

      lVar4 = (longlong)(int)uVar3;

      *puVar6 = *(undefined4 *)(param_1 + lVar4 * 4);

      *(undefined4 *)(param_1 + lVar4 * 4) = uVar1;

      uVar5 = uVar5 - 1;

      puVar6 = puVar6 + -1;

    } while (uVar5 != 0);

  }

  return;

}




