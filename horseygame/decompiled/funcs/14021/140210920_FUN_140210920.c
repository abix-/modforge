// Address: 0x140210920
// Ghidra name: FUN_140210920
// ============ 0x140210920 FUN_140210920 (size=234) ============


void FUN_140210920(int param_1,undefined8 *param_2)



{

  longlong lVar1;

  undefined8 uVar2;

  int iVar3;

  longlong lVar4;

  undefined8 *puVar5;

  uint uVar6;

  

  _guard_check_icall();

  if (-1 < param_1) {

    lVar1 = (longlong)param_1 * 8;

    lVar4 = DAT_1403fd3e0;

    if (DAT_1403fd3e8 <= param_1) {

      lVar4 = FUN_140184230(DAT_1403fd3e0,lVar1 + 8);

      iVar3 = DAT_1403fd3e8;

      if (lVar4 == 0) {

        return;

      }

      if (DAT_1403fd3e8 <= param_1) {

        uVar6 = (param_1 - DAT_1403fd3e8) + 1;

        FUN_1402f94c0(lVar4 + (longlong)DAT_1403fd3e8 * 8,0,(ulonglong)uVar6 << 3);

        DAT_1403fd3e8 = iVar3 + uVar6;

      }

    }

    DAT_1403fd3e0 = lVar4;

    if ((*(longlong *)(lVar1 + DAT_1403fd3e0) == 0) &&

       (puVar5 = (undefined8 *)FUN_1401841f0(0x18), lVar4 = DAT_1403fd3e0,

       puVar5 != (undefined8 *)0x0)) {

      uVar2 = param_2[1];

      *puVar5 = *param_2;

      puVar5[1] = uVar2;

      puVar5[2] = param_2[2];

      *(undefined8 **)(lVar1 + lVar4) = puVar5;

      *param_2 = 0;

      param_2[1] = 0;

      param_2[2] = 0;

    }

  }

  return;

}




