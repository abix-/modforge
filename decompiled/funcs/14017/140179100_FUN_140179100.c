// Address: 0x140179100
// Ghidra name: FUN_140179100
// ============ 0x140179100 FUN_140179100 (size=72) ============


undefined8 FUN_140179100(longlong *param_1,undefined8 param_2,char *param_3,char *param_4)



{

  size_t sVar1;

  size_t sVar2;

  longlong lVar3;

  

  sVar1 = strlen(param_3);

  sVar2 = strlen(param_4);

  lVar3 = sVar2 + 2 + sVar1;

  param_1[1] = param_1[1] + lVar3;

  *param_1 = *param_1 + 1;

  return CONCAT71((int7)((ulonglong)lVar3 >> 8),1);

}




