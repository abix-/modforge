// Address: 0x1400c5680
// Ghidra name: FUN_1400c5680
// ============ 0x1400c5680 FUN_1400c5680 (size=103) ============


int FUN_1400c5680(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)



{

  int iVar1;

  ulonglong *puVar2;

  

  puVar2 = (ulonglong *)FUN_140023ec0();

  iVar1 = FUN_1402d7d00(*puVar2 | 2,param_1,param_2,param_3,0,param_4);

  if (iVar1 < 0) {

    iVar1 = -1;

  }

  return iVar1;

}




