// Address: 0x1402099c0
// Ghidra name: FUN_1402099c0
// ============ 0x1402099c0 FUN_1402099c0 (size=57) ============


ushort * FUN_1402099c0(ushort param_1,ushort *param_2,uint param_3)



{

  uint uVar1;

  ulonglong uVar2;

  ushort *puVar3;

  

  if ((param_3 <= param_1) ||

     (puVar3 = param_2 + (ulonglong)param_1 * 4, param_2[(ulonglong)param_1 * 4] != param_1)) {

    uVar2 = 0;

    puVar3 = param_2;

    if (param_3 != 0) {

      do {

        if (*puVar3 == param_1) {

          return param_2 + uVar2 * 4;

        }

        uVar1 = (int)uVar2 + 1;

        uVar2 = (ulonglong)uVar1;

        puVar3 = puVar3 + 4;

      } while (uVar1 < param_3);

    }

    puVar3 = (ushort *)0x0;

  }

  return puVar3;

}




