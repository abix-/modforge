// Address: 0x1402843a0
// Ghidra name: FUN_1402843a0
// ============ 0x1402843a0 FUN_1402843a0 (size=69) ============


undefined8 FUN_1402843a0(longlong param_1,longlong *param_2,undefined8 *param_3,undefined4 *param_4)



{

  longlong *plVar1;

  longlong *plVar2;

  

  plVar1 = (longlong *)0x0;

  plVar2 = DAT_1403fdde0;

  if (DAT_1403fdde0 != (longlong *)0x0) {

    do {

      if (*plVar2 == param_1) {

        plVar1 = plVar2;

      }

      plVar2 = (longlong *)plVar2[0x14];

    } while (plVar2 != (longlong *)0x0);

    if (plVar1 != (longlong *)0x0) {

      *param_2 = (longlong)(plVar1 + 1);

      *param_3 = plVar1 + 0x11;

      *param_4 = 0x80;

      return CONCAT71((int7)((ulonglong)(plVar1 + 0x11) >> 8),1);

    }

  }

  return 0;

}




