// Address: 0x140027670
// Ghidra name: FUN_140027670
// ============ 0x140027670 FUN_140027670 (size=98) ============


int FUN_140027670(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)



{

  int iVar1;

  undefined8 *puVar2;

  undefined8 local_res20;

  

  local_res20 = param_4;

  puVar2 = (undefined8 *)FUN_140023ec0();

  iVar1 = FUN_1402d7b3c(*puVar2,param_1,0x20,param_2,param_3,0,&local_res20);

  if (iVar1 < 0) {

    iVar1 = -1;

  }

  return iVar1;

}




