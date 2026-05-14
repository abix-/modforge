// Address: 0x140177ca0
// Ghidra name: FUN_140177ca0
// ============ 0x140177ca0 FUN_140177ca0 (size=163) ============


undefined8

FUN_140177ca0(longlong param_1,undefined1 *param_2,undefined8 param_3,undefined4 param_4,

             undefined8 param_5)



{

  char cVar1;

  undefined8 uVar2;

  undefined1 *puVar3;

  

  if (param_1 == 0) {

    FUN_14012e850("Invalid storage container");

    return 0;

  }

  puVar3 = &DAT_14039bcb9;

  if (param_2 != (undefined1 *)0x0) {

    puVar3 = param_2;

  }

  cVar1 = FUN_1401784e0(puVar3);

  if (cVar1 == '\0') {

    uVar2 = 0;

  }

  else {

    uVar2 = FUN_140178c00(puVar3,param_3,param_4,param_5,&LAB_140177860,&LAB_140177880,param_1);

  }

  return uVar2;

}




