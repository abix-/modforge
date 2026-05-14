// Address: 0x1400c03a0
// Ghidra name: FUN_1400c03a0
// ============ 0x1400c03a0 FUN_1400c03a0 (size=235) ============


void FUN_1400c03a0(undefined8 param_1,int param_2,int param_3,int param_4)



{

  undefined4 uVar1;

  longlong lVar2;

  longlong lVar3;

  longlong lVar4;

  longlong lVar5;

  longlong lVar6;

  int iVar7;

  

  lVar5 = DAT_1403f2fc0;

  lVar4 = (longlong)param_2;

  iVar7 = 0;

  lVar3 = (longlong)param_3;

  lVar6 = (longlong)param_4 + lVar4 * 8;

  lVar2 = lVar3 + lVar4 * 8;

  uVar1 = (&DAT_1403ee4b0)[lVar2];

  (&DAT_1403ee4b0)[lVar2] = (&DAT_1403ee4b0)[lVar6];

  lVar2 = DAT_1403f2fc8;

  (&DAT_1403ee4b0)[lVar6] = uVar1;

  lVar2 = lVar2 - lVar5;

  lVar6 = lVar2 >> 0x3f;

  if (lVar2 / 0x1018 + lVar6 != lVar6) {

    lVar6 = (lVar3 + lVar4 * 4) * 4 + 0x28;

    do {

      uVar1 = *(undefined4 *)(lVar6 + lVar5);

      lVar2 = lVar6 + (param_4 - lVar3) * 4;

      iVar7 = iVar7 + 1;

      *(undefined4 *)(lVar6 + lVar5) = *(undefined4 *)(lVar2 + lVar5);

      lVar6 = lVar6 + 0x1018;

      *(undefined4 *)(lVar2 + lVar5) = uVar1;

      lVar5 = DAT_1403f2fc0;

    } while ((ulonglong)(longlong)iVar7 < (ulonglong)((DAT_1403f2fc8 - DAT_1403f2fc0) / 0x1018));

  }

  return;

}




