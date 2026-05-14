// Address: 0x14012f860
// Ghidra name: FUN_14012f860
// ============ 0x14012f860 FUN_14012f860 (size=114) ============


int FUN_14012f860(undefined8 param_1,undefined8 param_2,undefined1 *param_3,undefined8 param_4)



{

  int iVar1;

  ulonglong *puVar2;

  undefined1 *puVar3;

  

  puVar3 = &DAT_14039bcb9;

  if (param_3 != (undefined1 *)0x0) {

    puVar3 = param_3;

  }

  puVar2 = (ulonglong *)FUN_140023ec0();

  iVar1 = FUN_1402d7d00(*puVar2 | 2,param_1,param_2,puVar3,0,param_4);

  if (iVar1 < 0) {

    iVar1 = -1;

  }

  return iVar1;

}




