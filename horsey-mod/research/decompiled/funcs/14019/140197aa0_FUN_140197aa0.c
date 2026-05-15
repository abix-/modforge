// Address: 0x140197aa0
// Ghidra name: FUN_140197aa0
// ============ 0x140197aa0 FUN_140197aa0 (size=75) ============


undefined4 * FUN_140197aa0(undefined4 *param_1,undefined4 param_2,ulonglong param_3)



{

  undefined4 *puVar1;

  uint uVar2;

  ulonglong uVar3;

  

  uVar3 = param_3 + 3 >> 2;

  if (param_3 != 0) {

    uVar2 = (uint)param_3 & 3;

    puVar1 = param_1;

    if ((param_3 & 3) == 0) goto LAB_140197ac9;

    if (uVar2 == 1) goto LAB_140197adb;

    if (uVar2 == 2) goto LAB_140197ad5;

    if (uVar2 != 3) {

      return param_1;

    }

    while( true ) {

      *puVar1 = param_2;

      puVar1 = puVar1 + 1;

LAB_140197ad5:

      *puVar1 = param_2;

      puVar1 = puVar1 + 1;

LAB_140197adb:

      *puVar1 = param_2;

      puVar1 = puVar1 + 1;

      uVar3 = uVar3 - 1;

      if (uVar3 == 0) break;

LAB_140197ac9:

      *puVar1 = param_2;

      puVar1 = puVar1 + 1;

    }

  }

  return param_1;

}




