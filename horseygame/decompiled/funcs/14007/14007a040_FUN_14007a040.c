// Address: 0x14007a040
// Ghidra name: FUN_14007a040
// ============ 0x14007a040 FUN_14007a040 (size=93) ============


int FUN_14007a040(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)



{

  int iVar1;

  ulonglong *puVar2;

  undefined8 local_res18;

  undefined8 local_res20;

  

  local_res18 = param_3;

  local_res20 = param_4;

  puVar2 = (ulonglong *)FUN_140023ec0();

  iVar1 = FUN_1402d7d00(*puVar2 | 1,param_1,0xffffffffffffffff,param_2,0,&local_res18);

  if (iVar1 < 0) {

    iVar1 = -1;

  }

  return iVar1;

}




