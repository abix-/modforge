// Address: 0x1402f0f80
// Ghidra name: FUN_1402f0f80
// ============ 0x1402f0f80 FUN_1402f0f80 (size=71) ============


int FUN_1402f0f80(int param_1)



{

  int iVar1;

  int iVar2;

  undefined4 *puVar3;

  

  iVar1 = param_1;

  iVar2 = DAT_1403ff668;

  if ((((param_1 != 0) && (iVar1 = param_1, param_1 != 1)) && (iVar1 = param_1, param_1 != 2)) &&

     (iVar1 = DAT_1403ff668, param_1 != 3)) {

    puVar3 = (undefined4 *)FUN_1402e68b0();

    *puVar3 = 0x16;

    FUN_1402cd454();

    iVar1 = DAT_1403ff668;

    iVar2 = -1;

  }

  DAT_1403ff668 = iVar1;

  return iVar2;

}




