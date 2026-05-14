// Address: 0x14027b990
// Ghidra name: FUN_14027b990
// ============ 0x14027b990 FUN_14027b990 (size=597) ============


void FUN_14027b990(undefined8 param_1,undefined8 param_2,longlong param_3,longlong param_4,

                  int param_5)



{

  longlong lVar1;

  byte *pbVar2;

  undefined8 uVar3;

  byte bVar4;

  bool bVar5;

  

  if (*(byte *)(param_3 + 0x6a) != *(byte *)(param_4 + 0xe)) {

    FUN_14015ad00(param_1,param_2,0,*(byte *)(param_4 + 0xe) & 1);

    FUN_14015ad00(param_1,param_2,1,*(byte *)(param_4 + 0xe) >> 1 & 1);

    FUN_14015ad00(param_1,param_2,2,*(byte *)(param_4 + 0xe) >> 3 & 1);

    FUN_14015ad00(param_1,param_2,3,*(byte *)(param_4 + 0xe) >> 4 & 1);

    FUN_14015ad00(param_1,param_2,9,*(byte *)(param_4 + 0xe) >> 6 & 1);

    FUN_14015ad00(param_1,param_2,10,*(byte *)(param_4 + 0xe) >> 7);

  }

  if (*(byte *)(param_3 + 0x6b) != *(byte *)(param_4 + 0xf)) {

    if (*(char *)(param_3 + 0x28) == '\0') {

      FUN_14015ad00(param_1,param_2,5,*(byte *)(param_4 + 0xf) >> 4 & 1);

    }

    FUN_14015ad00(param_1,param_2,6,*(byte *)(param_4 + 0xf) >> 3 & 1);

    FUN_14015ad00(param_1,param_2,7,*(byte *)(param_4 + 0xf) >> 5 & 1);

    FUN_14015ad00(param_1,param_2,8,*(byte *)(param_4 + 0xf) >> 6 & 1);

  }

  if (*(char *)(param_3 + 0x2d) == '\0') {

    if (((*(byte *)(param_4 + 0xf) & 4) == 0) && ((*(byte *)(param_4 + 0x10) & 1) == 0)) {

      bVar4 = 0;

    }

    else {

      bVar4 = 1;

    }

    uVar3 = 4;

  }

  else {

    FUN_14015ad00(param_1,param_2,4,*(byte *)(param_4 + 0xf) >> 2 & 1);

    uVar3 = 0xb;

    bVar4 = *(byte *)(param_4 + 0x10) & 1;

  }

  FUN_14015ad00(param_1,param_2,uVar3,bVar4);

  if (*(char *)(param_3 + 0x2a) != '\0') {

    if (param_5 == 0x14) {

      bVar5 = *(char *)(param_4 + 0x11) == '\0';

      lVar1 = 0x13;

    }

    else if (param_5 == 0x27) {

      bVar5 = *(char *)(param_4 + 0x13) == '\0';

      lVar1 = 0x11;

    }

    else {

      if (param_5 != 0x37) {

        return;

      }

      bVar5 = *(char *)(param_4 + 0x23) == '\0';

      lVar1 = 0x21;

    }

    pbVar2 = (byte *)(param_4 + lVar1);

    if (!bVar5) {

      *pbVar2 = 0;

    }

    if (*(byte *)(param_3 + 0x30) != *pbVar2) {

      FUN_14015ad00(param_1,param_2,0xb,*pbVar2 & 1);

      FUN_14015ad00(param_1,param_2,0xc,*pbVar2 >> 1 & 1);

      FUN_14015ad00(param_1,param_2,0xd,*pbVar2 >> 2 & 1);

      FUN_14015ad00(param_1,param_2,0xe,*pbVar2 >> 3 & 1);

      *(byte *)(param_3 + 0x30) = *pbVar2;

    }

  }

  return;

}




