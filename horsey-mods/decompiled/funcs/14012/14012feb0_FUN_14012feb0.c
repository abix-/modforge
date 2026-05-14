// Address: 0x14012feb0
// Ghidra name: FUN_14012feb0
// ============ 0x14012feb0 FUN_14012feb0 (size=74) ============


int FUN_14012feb0(ushort *param_1,ushort *param_2,longlong param_3)



{

  ushort uVar1;

  

  uVar1 = *param_1;

  for (; (uVar1 != 0 && (*param_2 != 0)); param_2 = param_2 + 1) {

    if (param_3 == 0) {

      return 0;

    }

    if (uVar1 != *param_2) goto LAB_14012fef1;

    uVar1 = param_1[1];

    param_1 = param_1 + 1;

    param_3 = param_3 + -1;

  }

  if (param_3 == 0) {

    return 0;

  }

LAB_14012fef1:

  return (uint)*param_1 - (uint)*param_2;

}




