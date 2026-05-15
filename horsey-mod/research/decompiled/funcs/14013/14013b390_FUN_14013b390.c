// Address: 0x14013b390
// Ghidra name: FUN_14013b390
// ============ 0x14013b390 FUN_14013b390 (size=300) ============


undefined8 FUN_14013b390(code *param_1,undefined8 param_2,char param_3)



{

  longlong lVar1;

  char cVar2;

  int iVar3;

  longlong lVar4;

  undefined8 uVar5;

  

  cVar2 = FUN_14017e7d0();

  if ((cVar2 == '\0') && (iVar3 = FUN_14017ec60(0x4000), iVar3 != 0)) {

    lVar4 = FUN_140139260(param_1,param_2,param_3);

    if (lVar4 == 0) {

      return 0;

    }

    FUN_140179b40(DAT_1403fbed8);

    lVar1 = lVar4;

    if (DAT_1403fbee8 != 0) {

      *(longlong *)(DAT_1403fbee8 + 0x20) = lVar4;

      lVar1 = DAT_1403fbee0;

    }

    DAT_1403fbee0 = lVar1;

    DAT_1403fbee8 = lVar4;

    FUN_140179b60(DAT_1403fbed8);

    FUN_14013b580();

    if (param_3 != '\0') {

      FUN_140163d70(*(undefined8 *)(lVar4 + 0x18));

      iVar3 = FUN_140138fe0(lVar4 + 0x10);

      if (iVar3 == 1) {

        FUN_1401393f0(lVar4);

        return 1;

      }

      if (iVar3 == 2) {

        FUN_1401393f0(lVar4);

        uVar5 = FUN_14012e850("Callback canceled");

        return uVar5;

      }

      uVar5 = FUN_14012e850("Callback timed out");

      return uVar5;

    }

  }

  else {

    (*param_1)(param_2);

  }

  return 1;

}




