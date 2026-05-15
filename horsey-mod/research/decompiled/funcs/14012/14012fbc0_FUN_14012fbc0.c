// Address: 0x14012fbc0
// Ghidra name: FUN_14012fbc0
// ============ 0x14012fbc0 FUN_14012fbc0 (size=58) ============


int FUN_14012fbc0(ushort *param_1,ushort *param_2)



{

  ushort *puVar1;

  ushort uVar2;

  

  uVar2 = *param_1;

  while (((uVar2 != 0 && (*param_2 != 0)) && (uVar2 == *param_2))) {

    puVar1 = param_1 + 1;

    param_1 = param_1 + 1;

    param_2 = param_2 + 1;

    uVar2 = *puVar1;

  }

  return (uint)*param_1 - (uint)*param_2;

}




