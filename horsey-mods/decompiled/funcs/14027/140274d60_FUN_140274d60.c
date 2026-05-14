// Address: 0x140274d60
// Ghidra name: FUN_140274d60
// ============ 0x140274d60 FUN_140274d60 (size=717) ============


void FUN_140274d60(undefined8 param_1,longlong param_2,longlong param_3,int param_4)



{

  undefined8 uVar1;

  ulonglong uVar2;

  undefined8 uVar3;

  

  uVar1 = FUN_140149300();

  if (0x16 < param_4) {

    if (*(char *)(param_2 + 0x22) != *(char *)(param_3 + 2)) {

      switch(*(char *)(param_3 + 2)) {

      case '\0':

        uVar3 = 1;

        break;

      case '\x01':

        uVar3 = 3;

        break;

      case '\x02':

        uVar3 = 2;

        break;

      case '\x03':

        uVar3 = 6;

        break;

      case '\x04':

        uVar3 = 4;

        break;

      case '\x05':

        uVar3 = 0xc;

        break;

      case '\x06':

        uVar3 = 8;

        break;

      case '\a':

        uVar3 = 9;

        break;

      default:

        uVar3 = 0;

      }

      FUN_14015ae90(uVar1,param_1,0,uVar3);

    }

    if (*(byte *)(param_2 + 0x23) != *(byte *)(param_3 + 3)) {

      FUN_14015ad00(uVar1,param_1,0,*(byte *)(param_3 + 3) & 1);

      FUN_14015ad00(uVar1,param_1,1,*(byte *)(param_3 + 3) >> 1 & 1);

      FUN_14015ad00(uVar1,param_1,2,*(byte *)(param_3 + 3) >> 2 & 1);

      FUN_14015ad00(uVar1,param_1,3,*(byte *)(param_3 + 3) >> 3 & 1);

      FUN_14015ad00(uVar1,param_1,9,*(byte *)(param_3 + 3) >> 4 & 1);

      FUN_14015ad00(uVar1,param_1,10,*(byte *)(param_3 + 3) >> 5 & 1);

      FUN_14015ad00(uVar1,param_1,7,*(byte *)(param_3 + 3) >> 6 & 1);

      FUN_14015ad00(uVar1,param_1,8,*(byte *)(param_3 + 3) >> 7);

    }

    if (*(byte *)(param_2 + 0x24) != *(byte *)(param_3 + 4)) {

      FUN_14015ad00(uVar1,param_1,6,*(byte *)(param_3 + 4) & 1);

    }

    FUN_14015aab0(uVar1,param_1,0,*(short *)(param_3 + 9) + -0x8000);

    FUN_14015aab0(uVar1,param_1,1,*(short *)(param_3 + 0xb) + -0x8000);

    FUN_14015aab0(uVar1,param_1,2,*(short *)(param_3 + 0xd) + -0x8000);

    FUN_14015aab0(uVar1,param_1,3,*(short *)(param_3 + 0xf) + -0x8000);

    FUN_14015aab0(uVar1,param_1,4,*(short *)(param_3 + 0x13) + -0x8000);

    FUN_14015aab0(uVar1,param_1,5,*(short *)(param_3 + 0x15) + -0x8000);

    if (*(byte *)(param_2 + 0x31) != *(byte *)(param_3 + 0x11)) {

      FUN_14015ad00(uVar1,param_1,4,*(byte *)(param_3 + 0x11) >> 1 & 1);

      FUN_14015ad00(uVar1,param_1,5,*(byte *)(param_3 + 0x11) & 1);

    }

    uVar2 = 0x40;

    if ((ulonglong)(longlong)param_4 < 0x40) {

      uVar2 = (longlong)param_4;

    }

    FUN_1402f8e20(param_2 + 0x20,param_3,uVar2);

  }

  return;

}




