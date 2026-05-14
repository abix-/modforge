// Address: 0x140207e40
// Ghidra name: FUN_140207e40
// ============ 0x140207e40 FUN_140207e40 (size=107) ============


ulonglong FUN_140207e40(longlong param_1,longlong *param_2)



{

  longlong lVar1;

  ulonglong uVar2;

  

  uVar2 = _guard_check_icall();

  if ((param_1 != 0) && (*(longlong **)(param_1 + 0x148) != (longlong *)0x0)) {

    lVar1 = **(longlong **)(param_1 + 0x148);

    *param_2 = lVar1;

    if (lVar1 != 0) {

      if (DAT_1403e3d60 != '\0') {

        uVar2 = FUN_1401aa7c0(lVar1,9);

        if ((char)uVar2 == '\0') goto LAB_140207e9e;

      }

      return CONCAT71((int7)((ulonglong)*param_2 >> 8),*(longlong *)(*param_2 + 0x68) != 0);

    }

  }

LAB_140207e9e:

  return uVar2 & 0xffffffffffffff00;

}




