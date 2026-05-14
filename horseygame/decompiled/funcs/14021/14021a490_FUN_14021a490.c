// Address: 0x14021a490
// Ghidra name: FUN_14021a490
// ============ 0x14021a490 FUN_14021a490 (size=91) ============


void FUN_14021a490(undefined8 param_1,undefined8 param_2,ulonglong param_3)



{

  char *pcVar1;

  char local_28 [32];

  

  pcVar1 = (char *)FUN_140218f40(param_3 & 0xffffffff);

  if (*pcVar1 == '\0') {

    FUN_14012ef10(local_28,0x20,&DAT_140354404,param_3 & 0xffffffff);

    pcVar1 = local_28;

  }

  FUN_14012e850("%s (call to %s failed, reporting an error of %s)",param_1,param_2,pcVar1);

  return;

}




