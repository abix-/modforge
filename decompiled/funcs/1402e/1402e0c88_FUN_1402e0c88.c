// Address: 0x1402e0c88
// Ghidra name: FUN_1402e0c88
// ============ 0x1402e0c88 FUN_1402e0c88 (size=122) ============


ulonglong FUN_1402e0c88(longlong param_1,undefined8 param_2)



{

  longlong *plVar1;

  undefined8 *puVar2;

  undefined4 *puVar3;

  ulonglong uVar4;

  longlong lVar5;

  

  plVar1 = *(longlong **)(param_1 + 0x80);

  *(longlong **)(param_1 + 0x80) = plVar1 + 1;

  puVar2 = (undefined8 *)*plVar1;

  if (puVar2 == (undefined8 *)0x0) {

    puVar3 = (undefined4 *)FUN_1402e68b0();

    *puVar3 = 0x16;

    uVar4 = FUN_1402cd454();

LAB_1402e0cbf:

    uVar4 = uVar4 & 0xffffffffffffff00;

  }

  else {

    lVar5 = FUN_1402e0120(param_1 + 0x20);

    if (lVar5 == 1) {

      *(char *)puVar2 = (char)param_2;

      uVar4 = 0;

    }

    else if (lVar5 == 2) {

      *(short *)puVar2 = (short)param_2;

      uVar4 = 0;

    }

    else {

      uVar4 = lVar5 - 4;

      if (uVar4 == 0) {

        *(int *)puVar2 = (int)param_2;

      }

      else {

        if (uVar4 != 4) goto LAB_1402e0cbf;

        *puVar2 = param_2;

      }

    }

    uVar4 = CONCAT71((int7)(uVar4 >> 8),1);

  }

  return uVar4;

}




