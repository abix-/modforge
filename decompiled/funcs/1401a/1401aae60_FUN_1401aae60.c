// Address: 0x1401aae60
// Ghidra name: FUN_1401aae60
// ============ 0x1401aae60 FUN_1401aae60 (size=54) ============


undefined8 FUN_1401aae60(char *param_1,char *param_2)



{

  int iVar1;

  size_t _MaxCount;

  undefined4 extraout_var;

  

  _MaxCount = strlen(param_2);

  iVar1 = strncmp(param_1,param_2,_MaxCount);

  return CONCAT71((int7)(CONCAT44(extraout_var,iVar1) >> 8),iVar1 == 0);

}




