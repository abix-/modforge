// Address: 0x140169700
// Ghidra name: FUN_140169700
// ============ 0x140169700 FUN_140169700 (size=217) ============


undefined8 FUN_140169700(longlong param_1,ulonglong param_2)



{

  longlong lVar1;

  undefined8 uVar2;

  longlong lVar3;

  ulonglong uVar4;

  ulonglong uVar5;

  ulonglong uVar6;

  

  lVar1 = FUN_14016dcf0();

  if (lVar1 == 0) {

    uVar2 = FUN_1401730c0();

    return uVar2;

  }

  FUN_140169150(lVar1);

  if ((param_1 == 0) || (param_2 == 0)) {

LAB_1401697b5:

    uVar2 = 1;

  }

  else {

    uVar5 = 0;

    lVar3 = FUN_1401841f0(param_2 * 8);

    *(longlong *)(lVar1 + 0x378) = lVar3;

    uVar6 = uVar5;

    if (lVar3 != 0) {

      do {

        uVar2 = FUN_14012f0d0(*(undefined8 *)(param_1 + uVar5 * 8));

        *(undefined8 *)(*(longlong *)(lVar1 + 0x378) + uVar5 * 8) = uVar2;

        uVar4 = uVar6 + 1;

        if (*(longlong *)(*(longlong *)(lVar1 + 0x378) + uVar5 * 8) == 0) {

          uVar4 = uVar6;

        }

        uVar5 = uVar5 + 1;

        uVar6 = uVar4;

      } while (uVar5 < param_2);

      if (param_2 <= uVar4) {

        *(ulonglong *)(lVar1 + 0x380) = param_2;

        goto LAB_1401697b5;

      }

    }

    FUN_140169150(lVar1);

    uVar2 = 0;

  }

  return uVar2;

}




