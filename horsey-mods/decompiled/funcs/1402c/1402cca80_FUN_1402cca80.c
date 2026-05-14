// Address: 0x1402cca80
// Ghidra name: FUN_1402cca80
// ============ 0x1402cca80 FUN_1402cca80 (size=176) ============


int FUN_1402cca80(undefined8 *param_1,int param_2,longlong param_3,int param_4,undefined8 *param_5)



{

  ulonglong uVar1;

  UWMap4 *pUVar2;

  uchar *puStack_10;

  

  uVar1 = param_5[1];

  if ((*(ulonglong *)(param_3 + 8) < uVar1) || (uVar1 < (ulonglong)param_1[1])) {

    param_2 = -1;

  }

  else if ((longlong)(uVar1 - param_1[1]) < (longlong)(*(longlong *)(param_3 + 8) - uVar1)) {

    pUVar2 = (UWMap4 *)*param_1;

    puStack_10 = (uchar *)param_1[1];

    if ((ulonglong)param_1[1] < uVar1) {

      do {

        FH4::UWMap4::ReadEntry(pUVar2,&puStack_10);

        param_2 = param_2 + 1;

      } while (puStack_10 < (uchar *)param_5[1]);

    }

  }

  else {

    pUVar2 = (UWMap4 *)*param_5;

    puStack_10 = (uchar *)param_5[1];

    param_2 = param_4;

    if (uVar1 < *(ulonglong *)(param_3 + 8)) {

      do {

        FH4::UWMap4::ReadEntry(pUVar2,&puStack_10);

        param_2 = param_2 + -1;

      } while (puStack_10 < *(uchar **)(param_3 + 8));

    }

  }

  return param_2;

}




