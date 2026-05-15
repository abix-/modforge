// Address: 0x1401489e0
// Ghidra name: FUN_1401489e0
// ============ 0x1401489e0 FUN_1401489e0 (size=56) ============


void FUN_1401489e0(uint *param_1)



{

  char cVar1;

  uint uVar2;

  

  cVar1 = FUN_1401489c0();

  if (((cVar1 != '\0') && (param_1[0x18] != 0)) &&

     (uVar2 = param_1[0x18] - 1, param_1[0x18] = uVar2, (int)uVar2 < 1)) {

    *param_1 = *param_1 & 0xfffffffb;

    FUN_140148a20(param_1);

    return;

  }

  return;

}




