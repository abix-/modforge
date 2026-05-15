// Address: 0x140076390
// Ghidra name: FUN_140076390
// ============ 0x140076390 FUN_140076390 (size=220) ============


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void FUN_140076390(longlong *param_1)



{

  int iVar1;

  ulonglong uVar2;

  longlong lVar3;

  uint uVar4;

  ulonglong uVar5;

  undefined1 local_res8 [8];

  

  uVar2 = 0;

  iVar1 = 0;

  if ((ulonglong)((longlong)DAT_1403ead20 - _DAT_1403ead18) <=

      (ulonglong)(DAT_1403ead30 - DAT_1403ead28)) {

    iVar1 = *DAT_1403ead20;

    DAT_1403ead20 = DAT_1403ead20 + 1;

  }

  FUN_140076550(param_1,(longlong)iVar1,local_res8);

  lVar3 = *param_1;

  uVar5 = uVar2;

  if (param_1[1] - lVar3 >> 2 != 0) {

    do {

      if ((ulonglong)(DAT_1403ead30 - DAT_1403ead28) <

          (ulonglong)((longlong)DAT_1403ead20 - _DAT_1403ead18)) {

        *(undefined4 *)(uVar2 + lVar3) = 0;

      }

      else {

        *(int *)(uVar2 + lVar3) = *DAT_1403ead20;

        DAT_1403ead20 = DAT_1403ead20 + 1;

      }

      lVar3 = *param_1;

      uVar4 = (int)uVar5 + 1;

      uVar2 = uVar2 + 4;

      uVar5 = (ulonglong)uVar4;

    } while ((ulonglong)(longlong)(int)uVar4 < (ulonglong)(param_1[1] - lVar3 >> 2));

  }

  return;

}




