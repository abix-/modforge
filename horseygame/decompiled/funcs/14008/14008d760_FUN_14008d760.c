// Address: 0x14008d760
// Ghidra name: FUN_14008d760
// ============ 0x14008d760 FUN_14008d760 (size=134) ============


undefined8 *

FUN_14008d760(undefined8 *param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)



{

  ulonglong *puVar1;

  size_t sVar2;

  undefined8 local_res18;

  undefined8 local_res20;

  

  local_res18 = param_3;

  local_res20 = param_4;

  puVar1 = (ulonglong *)FUN_140023ec0();

  FUN_1402d7d00(*puVar1 | 2,&DAT_1403eda10,0x3ff,param_2,0,&local_res18);

  *param_1 = 0;

  param_1[1] = 0;

  param_1[2] = 0;

  param_1[3] = 0;

  sVar2 = strlen(&DAT_1403eda10);

  FUN_140027e30(param_1,&DAT_1403eda10,sVar2);

  return param_1;

}




