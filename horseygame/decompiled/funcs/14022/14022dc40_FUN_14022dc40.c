// Address: 0x14022dc40
// Ghidra name: FUN_14022dc40
// ============ 0x14022dc40 FUN_14022dc40 (size=191) ============


undefined8 FUN_14022dc40(undefined8 param_1,undefined8 param_2)



{

  int iVar1;

  int iVar2;

  undefined8 uVar3;

  CHAR *pCVar4;

  undefined *puVar5;

  CHAR local_28 [16];

  CHAR local_18 [16];

  

  iVar1 = GetLocaleInfoA(0x400,0x59,local_18,0x10);

  iVar2 = GetLocaleInfoA(0x400,0x5a,local_28,0x10);

  if (iVar1 != 0) {

    puVar5 = &DAT_14039bcb9;

    pCVar4 = local_28;

    if (iVar2 == 0) {

      pCVar4 = "";

    }

    else {

      puVar5 = &DAT_140357c10;

    }

    FUN_14012ef10(param_1,param_2,"%s%s%s",local_18,puVar5,pCVar4);

    return 1;

  }

  uVar3 = FUN_14012e850("Couldn\'t obtain language info");

  return uVar3;

}




