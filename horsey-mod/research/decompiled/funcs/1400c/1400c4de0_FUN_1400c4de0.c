// Address: 0x1400c4de0
// Ghidra name: FUN_1400c4de0
// ============ 0x1400c4de0 FUN_1400c4de0 (size=10) ============


void FUN_1400c4de0(LPVOID param_1)



{

  undefined4 *puVar1;

  BOOL BVar2;

  DWORD DVar3;

  undefined4 uVar4;

  

  if (param_1 != (LPVOID)0x0) {

    if ((param_1 != (LPVOID)0x0) && (BVar2 = HeapFree(DAT_1403ff7a0,0,param_1), BVar2 == 0)) {

      DVar3 = GetLastError();

      uVar4 = FUN_1402e6770(DVar3);

      puVar1 = (undefined4 *)FUN_1402e68b0();

      *puVar1 = uVar4;

    }

    return;

  }

  return;

}




