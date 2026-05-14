// Address: 0x14020f920
// Ghidra name: FUN_14020f920
// ============ 0x14020f920 FUN_14020f920 (size=135) ============


ulonglong FUN_14020f920(short param_1,short param_2)



{

  longlong lVar1;

  uint uVar2;

  ulonglong uVar3;

  longlong *plVar4;

  

  uVar3 = _guard_check_icall();

  if (DAT_1403fd3b0 != 0) {

    if ((param_1 == 0x45e) && (uVar3 = 0x2ff, param_2 == 0x2ff)) {

LAB_14020f99a:

      return CONCAT71((int7)(uVar3 >> 8),1);

    }

    uVar3 = 0;

    plVar4 = DAT_1403fd3a0;

    if (0 < DAT_1403fd3a8) {

      do {

        if (((*plVar4 != 0) &&

            (lVar1 = *(longlong *)(*plVar4 + 0x70), param_1 == *(short *)(lVar1 + 4))) &&

           (param_2 == *(short *)(lVar1 + 6))) goto LAB_14020f99a;

        uVar2 = (int)uVar3 + 1;

        uVar3 = (ulonglong)uVar2;

        plVar4 = plVar4 + 1;

      } while ((int)uVar2 < DAT_1403fd3a8);

    }

  }

  return uVar3 & 0xffffffffffffff00;

}




