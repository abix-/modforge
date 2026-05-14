// Address: 0x1402680b0
// Ghidra name: FUN_1402680b0
// ============ 0x1402680b0 FUN_1402680b0 (size=44) ============


undefined4 FUN_1402680b0(longlong param_1,byte param_2,char param_3)



{

  undefined3 uVar1;

  uint uVar2;

  

  uVar2 = 1 << (param_2 & 0x1f);

  uVar1 = (undefined3)(uVar2 >> 8);

  if (param_3 != '\0') {

    return CONCAT31(uVar1,(*(uint *)(param_1 + 0x5c + (ulonglong)(param_2 >> 5) * 4) & uVar2) != 0);

  }

  return CONCAT31(uVar1,(*(uint *)(param_1 + 0x7c + (ulonglong)(param_2 >> 5) * 4) & uVar2) != 0);

}




