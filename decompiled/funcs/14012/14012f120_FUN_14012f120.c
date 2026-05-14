// Address: 0x14012f120
// Ghidra name: FUN_14012f120
// ============ 0x14012f120 FUN_14012f120 (size=113) ============


longlong FUN_14012f120(char *param_1,char *param_2,ulonglong param_3)



{

  size_t sVar1;

  size_t sVar2;

  

  sVar1 = strlen(param_1);

  sVar2 = strlen(param_2);

  if (sVar1 < param_3) {

    FUN_14012f1a0(param_1 + sVar1,param_2,param_3 - sVar1);

  }

  return sVar2 + sVar1;

}




