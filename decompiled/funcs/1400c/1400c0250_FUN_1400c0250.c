// Address: 0x1400c0250
// Ghidra name: FUN_1400c0250
// ============ 0x1400c0250 FUN_1400c0250 (size=79) ============


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



undefined8 FUN_1400c0250(longlong param_1)



{

  int iVar1;

  

  FUN_1400ce540(param_1,0,0);

  *(undefined2 *)(param_1 + 0x268) = 0;

  *(undefined4 *)(param_1 + 600) = 0;

  *(undefined4 *)(param_1 + 0x260) = 0;

  *(undefined4 *)(param_1 + 0x264) = 0xffffffff;

  iVar1 = DAT_1403da47c - _DAT_1403da474;

  *(int *)(param_1 + 0x278) = iVar1;

  return CONCAT71((uint7)(uint3)((uint)iVar1 >> 8),1);

}




