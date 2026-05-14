// Address: 0x1400276e0
// Ghidra name: FUN_1400276e0
// ============ 0x1400276e0 FUN_1400276e0 (size=98) ============


int FUN_1400276e0(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)



{

  int iVar1;

  undefined8 *puVar2;

  undefined8 local_res20;

  

  local_res20 = param_4;

  puVar2 = (undefined8 *)FUN_140023ec0();

  iVar1 = FUN_1402d7b3c(*puVar2,param_1,0x40,param_2,param_3,0,&local_res20);

  if (iVar1 < 0) {

    iVar1 = -1;

  }

  return iVar1;

}




