// Address: 0x14013c880
// Ghidra name: FUN_14013c880
// ============ 0x14013c880 FUN_14013c880 (size=140) ============


void FUN_14013c880(undefined8 param_1)



{

  undefined8 uVar1;

  undefined1 extraout_AL;

  char cVar2;

  undefined1 uVar3;

  undefined1 extraout_AH;

  undefined1 extraout_AH_00;

  undefined6 extraout_var;

  int iVar4;

  int iVar5;

  

  FUN_140149300();

  iVar4 = 0;

  uVar1 = CONCAT62(extraout_var,CONCAT11(extraout_AH,extraout_AL));

  iVar5 = 0;

  do {

    cVar2 = FUN_14013e2c0(param_1,iVar5);

    if (cVar2 != '\0') {

      FUN_140141d70(uVar1,param_1,iVar5,0);

    }

    iVar5 = iVar5 + 1;

  } while (iVar5 < 0x1a);

  do {

    uVar3 = FUN_14013de30(param_1,iVar4);

    if (CONCAT11(extraout_AH_00,uVar3) != 0) {

      FUN_140141cf0(uVar1,param_1,iVar4,0);

    }

    iVar4 = iVar4 + 1;

  } while (iVar4 < 6);

  return;

}




