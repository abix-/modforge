// Address: 0x140175b70
// Ghidra name: FUN_140175b70
// ============ 0x140175b70 FUN_140175b70 (size=46) ============


undefined8 FUN_140175b70(undefined8 param_1)



{

  char cVar1;

  undefined8 uVar2;

  undefined4 local_res10 [6];

  

  cVar1 = FUN_140175b00(param_1,local_res10);

  if (cVar1 != '\0') {

    uVar2 = FUN_14021acc0(local_res10[0]);

    uVar2 = FUN_1401aa890(uVar2);

    return uVar2;

  }

  return 0;

}




