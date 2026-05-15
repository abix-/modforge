// Address: 0x140266cc0
// Ghidra name: FUN_140266cc0
// ============ 0x140266cc0 FUN_140266cc0 (size=397) ============


void FUN_140266cc0(longlong param_1,undefined8 param_2,undefined8 param_3,byte *param_4)



{

  byte bVar1;

  byte bVar2;

  byte bVar3;

  undefined8 uVar4;

  

  if (*(byte *)(param_1 + 0xf5) != *param_4) {

    FUN_14015ad00(param_3,param_2,6,*param_4 >> 2 & 1);

    FUN_14015ad00(param_3,param_2,4,*param_4 >> 3 & 1);

    FUN_14015ad00(param_3,param_2,0,*param_4 >> 4 & 1);

    FUN_14015ad00(param_3,param_2,1,*param_4 >> 5 & 1);

    FUN_14015ad00(param_3,param_2,2,*param_4 >> 6 & 1);

    FUN_14015ad00(param_3,param_2,3,*param_4 >> 7);

  }

  bVar1 = param_4[1];

  if (*(byte *)(param_1 + 0xf6) != bVar1) {

    bVar2 = bVar1 & 1 | 4;

    if ((bVar1 & 2) == 0) {

      bVar2 = bVar1 & 1;

    }

    bVar3 = bVar2 | 8;

    if ((bVar1 & 4) == 0) {

      bVar3 = bVar2;

    }

    bVar2 = bVar3 | 2;

    if ((bVar1 & 8) == 0) {

      bVar2 = bVar3;

    }

    FUN_14015ae90(param_3,param_2,0,bVar2);

    if (*(int *)(param_1 + 0x144) == 1) {

      FUN_14015ad00(param_3,param_2,10,(param_4[1] & 0x10) != 0);

      uVar4 = 9;

    }

    else {

      FUN_14015ad00(param_3,param_2,9,(param_4[1] & 0x10) != 0);

      uVar4 = 10;

    }

    FUN_14015ad00(param_3,param_2,uVar4,param_4[1] >> 5 & 1);

  }

  return;

}




