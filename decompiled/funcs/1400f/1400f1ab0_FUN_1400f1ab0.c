// Address: 0x1400f1ab0
// Ghidra name: FUN_1400f1ab0
// ============ 0x1400f1ab0 FUN_1400f1ab0 (size=72) ============


bool FUN_1400f1ab0(longlong param_1)



{

  int iVar1;

  byte *pbVar2;

  

  iVar1 = FUN_1400f3c70();

  if (iVar1 < 0) {

    return true;

  }

  pbVar2 = (byte *)(*(longlong *)(param_1 + 8) + (longlong)iVar1);

  return (ushort)((ushort)*pbVar2 * 0x100 + (ushort)pbVar2[1]) == 0;

}




