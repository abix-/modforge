// Address: 0x1402daed8
// Ghidra name: FUN_1402daed8
// ============ 0x1402daed8 FUN_1402daed8 (size=82) ============


int FUN_1402daed8(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)



{

  int iVar1;

  undefined8 *puVar2;

  undefined8 local_res20;

  

  local_res20 = param_4;

  puVar2 = (undefined8 *)FUN_140023ec0();

  iVar1 = FUN_1402d7f54(*puVar2,param_1,param_2,param_3,0,&local_res20);

  if (iVar1 < 0) {

    iVar1 = -1;

  }

  return iVar1;

}




