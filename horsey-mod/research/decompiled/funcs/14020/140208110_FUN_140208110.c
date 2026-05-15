// Address: 0x140208110
// Ghidra name: FUN_140208110
// ============ 0x140208110 FUN_140208110 (size=284) ============


undefined8 FUN_140208110(longlong param_1,undefined4 *param_2)



{

  int *piVar1;

  longlong lVar2;

  undefined4 uVar3;

  longlong lVar4;

  ulonglong uVar5;

  uint uVar6;

  ulonglong uVar7;

  ulonglong uVar8;

  

  _guard_check_icall();

  uVar5 = 0;

  piVar1 = (int *)(param_1 + 0xa8);

  uVar7 = uVar5;

  uVar8 = uVar5;

  if (0 < *piVar1) {

    do {

      lVar2 = *(longlong *)(uVar8 + *(longlong *)(param_1 + 0xb0));

      lVar4 = (longlong)*(int *)(lVar2 + 0x8c);

      while (lVar4 != 0) {

        lVar4 = lVar4 + -1;

        FUN_140208230(lVar2,*(undefined4 *)(*(longlong *)(lVar2 + 0x90) + lVar4 * 4));

      }

      uVar6 = (int)uVar7 + 1;

      uVar7 = (ulonglong)uVar6;

      uVar8 = uVar8 + 8;

    } while ((int)uVar6 < *piVar1);

  }

  uVar3 = FUN_1401aa810();

  FUN_1402072d0(param_1,uVar3);

  uVar7 = uVar5;

  if (0 < *piVar1) {

    do {

      FUN_1402072d0(*(undefined8 *)(uVar5 + *(longlong *)(param_1 + 0xb0)),uVar3);

      uVar6 = (int)uVar7 + 1;

      uVar5 = uVar5 + 8;

      uVar7 = (ulonglong)uVar6;

    } while ((int)uVar6 < *(int *)(param_1 + 0xa8));

  }

  DAT_1403fd1a0 = DAT_1403fd1a0 + 1;

  if (param_2 != (undefined4 *)0x0) {

    *param_2 = uVar3;

  }

  FUN_14015a2b0(uVar3);

  return 1;

}




