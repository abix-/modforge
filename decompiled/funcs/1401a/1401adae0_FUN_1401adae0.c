// Address: 0x1401adae0
// Ghidra name: FUN_1401adae0
// ============ 0x1401adae0 FUN_1401adae0 (size=201) ============


undefined8 FUN_1401adae0(uint *param_1,undefined8 param_2,longlong *param_3)



{

  longlong lVar1;

  uint uVar2;

  ulonglong in_RAX;

  ulonglong uVar3;

  longlong lVar4;

  longlong *plVar5;

  ulonglong uVar6;

  

  lVar4 = *(longlong *)(param_1 + 4);

  uVar3 = in_RAX & 0xffffffffffffff00;

  if (*(uint *)(param_3 + 8) != 0) {

    uVar6 = (ulonglong)*(uint *)(param_3 + 8);

    plVar5 = param_3;

    do {

      lVar1 = *plVar5;

      plVar5 = plVar5 + 1;

      uVar3 = uVar3 & 0xff;

      if (lVar1 == lVar4) {

        uVar3 = 1;

      }

      uVar6 = uVar6 - 1;

    } while (uVar6 != 0);

  }

  uVar6 = (ulonglong)*(uint *)(param_3 + 0x11);

  if (*(uint *)(param_3 + 0x11) != 0) {

    plVar5 = param_3 + 9;

    do {

      lVar1 = *plVar5;

      plVar5 = plVar5 + 1;

      uVar3 = uVar3 & 0xff;

      if (lVar1 == lVar4) {

        uVar3 = 1;

      }

      uVar6 = uVar6 - 1;

    } while (uVar6 != 0);

  }

  if ((param_3[0x12] == lVar4) || ((char)uVar3 != '\0')) {

    if (param_1[1] == *param_1) {

      uVar2 = *param_1 * 2;

      *param_1 = uVar2;

      lVar4 = FUN_140184230(*(undefined8 *)(param_1 + 2),(ulonglong)uVar2 << 3);

      if (lVar4 == 0) {

        return 0;

      }

      *(longlong *)(param_1 + 2) = lVar4;

    }

    uVar3 = *(ulonglong *)(param_1 + 2);

    *(longlong **)(uVar3 + (ulonglong)param_1[1] * 8) = param_3;

    param_1[1] = param_1[1] + 1;

  }

  return CONCAT71((int7)(uVar3 >> 8),1);

}




