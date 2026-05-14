// Address: 0x1400c7c60
// Ghidra name: FUN_1400c7c60
// ============ 0x1400c7c60 FUN_1400c7c60 (size=274) ============


void FUN_1400c7c60(int param_1,undefined4 param_2)



{

  undefined4 uVar1;

  undefined8 uVar2;

  undefined8 uVar3;

  undefined8 *puVar4;

  undefined8 *puVar5;

  longlong lVar6;

  longlong local_28 [3];

  ulonglong local_10;

  

  if (param_1 == -1) {

    FUN_1400c4320("No Record!");

    return;

  }

  lVar6 = (longlong)param_1 * 0x88;

  *(undefined4 *)(lVar6 + 100 + DAT_1403f34e0) = param_2;

  *(undefined4 *)(lVar6 + 0x44 + DAT_1403f34e0) = param_2;

  puVar4 = (undefined8 *)(DAT_1403f34e0 + lVar6);

  puVar5 = puVar4;

  if (0xf < (ulonglong)puVar4[3]) {

    puVar5 = (undefined8 *)*puVar4;

  }

  uVar1 = *(undefined4 *)((longlong)puVar4 + 0x44);

  uVar2 = FUN_140086330();

  uVar3 = FUN_140086310(uVar1);

  uVar2 = FUN_14008d760(local_28,"%s%s%s",uVar3,puVar5,uVar2);

  FUN_1400c5580(DAT_1403f34e0 + 0x20 + lVar6,uVar2);

  if (0xf < local_10) {

    if (0xfff < local_10 + 1) {

      if (0x1f < (local_28[0] - *(longlong *)(local_28[0] + -8)) - 8U) {

                    /* WARNING: Subroutine does not return */

        _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

      }

    }

    FUN_1402c7088();

  }

  return;

}




