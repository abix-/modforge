// Address: 0x14013bd80
// Ghidra name: FUN_14013bd80
// ============ 0x14013bd80 FUN_14013bd80 (size=358) ============


int FUN_14013bd80(longlong param_1,undefined8 param_2,undefined8 param_3,longlong param_4,

                 longlong param_5)



{

  int iVar1;

  longlong lVar2;

  longlong lVar3;

  longlong lVar4;

  

  lVar2 = FUN_14013bf20();

  FUN_14013b080(1);

  iVar1 = FUN_14013afe0(param_3,1,2,0,0xffff);

  lVar3 = param_5;

  do {

    if (iVar1 < 0) {

      return 0;

    }

    if (iVar1 != 0) {

      return 1;

    }

    if (0 < param_5) {

      lVar3 = FUN_140149300();

      if (param_5 <= lVar3 - param_4) {

        return 0;

      }

      lVar3 = param_5 - (lVar3 - param_4);

    }

    lVar4 = lVar3;

    if (((lVar2 != 0x7fffffffffffffff) && (lVar4 = lVar2, -1 < lVar3)) && (lVar3 < lVar2)) {

      lVar4 = lVar3;

    }

    FUN_140139020(param_1 + 800,param_2);

    iVar1 = (**(code **)(param_1 + 0x240))(param_1,lVar4);

    FUN_140139020(param_1 + 800,0);

    if (iVar1 == 0) {

      if (lVar2 == 0x7fffffffffffffff) {

        return 0;

      }

      if (lVar4 != lVar2) {

        return 0;

      }

    }

    else if (iVar1 < 1) {

      return iVar1;

    }

    FUN_14013b080(1);

    iVar1 = FUN_14013afe0(param_3,1,2,0,0xffff);

    lVar3 = lVar4;

  } while( true );

}




