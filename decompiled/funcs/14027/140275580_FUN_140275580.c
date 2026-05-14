// Address: 0x140275580
// Ghidra name: FUN_140275580
// ============ 0x140275580 FUN_140275580 (size=993) ============


void FUN_140275580(undefined8 param_1,longlong param_2,char *param_3,int param_4)



{

  undefined8 uVar1;

  undefined2 uVar2;

  ulonglong uVar3;

  int iVar4;

  undefined8 uVar5;

  float fVar6;

  

  uVar1 = FUN_140149300();

  if ((9 < param_4) && (*param_3 == '\x03')) {

    if (*(char *)(param_2 + 2) != param_3[1]) {

      switch(param_3[1]) {

      case '\0':

        uVar5 = 1;

        break;

      case '\x01':

        uVar5 = 3;

        break;

      case '\x02':

        uVar5 = 2;

        break;

      case '\x03':

        uVar5 = 6;

        break;

      case '\x04':

        uVar5 = 4;

        break;

      case '\x05':

        uVar5 = 0xc;

        break;

      case '\x06':

        uVar5 = 8;

        break;

      case '\a':

        uVar5 = 9;

        break;

      default:

        uVar5 = 0;

      }

      FUN_14015ae90(uVar1,param_1,0,uVar5);

    }

    if (*(byte *)(param_2 + 3) != param_3[2]) {

      FUN_14015ad00(uVar1,param_1,4,(byte)param_3[2] >> 6 & 1);

      FUN_14015ad00(uVar1,param_1,5,(byte)param_3[2] >> 4 & 1);

      FUN_14015ad00(uVar1,param_1,6,(byte)param_3[2] >> 5 & 1);

      FUN_14015ad00(uVar1,param_1,8,(byte)param_3[2] >> 7);

      FUN_14015ad00(uVar1,param_1,0xb,param_3[2] & 1);

      FUN_14015ad00(uVar1,param_1,0xc,(byte)param_3[2] >> 1 & 1);

    }

    if (*(byte *)(param_2 + 4) != param_3[3]) {

      FUN_14015ad00(uVar1,param_1,0,(byte)param_3[3] >> 6 & 1);

      FUN_14015ad00(uVar1,param_1,1,(byte)param_3[3] >> 5 & 1);

      FUN_14015ad00(uVar1,param_1,2,(byte)param_3[3] >> 4 & 1);

      FUN_14015ad00(uVar1,param_1,3,(byte)param_3[3] >> 3 & 1);

      FUN_14015ad00(uVar1,param_1,9,(byte)param_3[3] >> 2 & 1);

      FUN_14015ad00(uVar1,param_1,10,(byte)param_3[3] >> 1 & 1);

      FUN_14015ad00(uVar1,param_1,7,param_3[3] & 1);

    }

    uVar2 = 0;

    if (param_3[4] == -0x80) {

      iVar4 = 0;

    }

    else {

      fVar6 = (float)FUN_140208370();

      iVar4 = (int)fVar6;

    }

    FUN_14015aab0(uVar1,param_1,0,iVar4);

    if (param_3[5] == -0x80) {

      iVar4 = 0;

    }

    else {

      fVar6 = (float)FUN_140208370();

      iVar4 = (int)fVar6;

    }

    FUN_14015aab0(uVar1,param_1,1,iVar4);

    if (param_3[6] == -0x80) {

      iVar4 = 0;

    }

    else {

      fVar6 = (float)FUN_140208370();

      iVar4 = (int)fVar6;

    }

    FUN_14015aab0(uVar1,param_1,2,iVar4);

    if (param_3[7] != -0x80) {

      fVar6 = (float)FUN_140208370();

      uVar2 = (undefined2)(int)fVar6;

    }

    FUN_14015aab0(uVar1,param_1,3,uVar2);

    FUN_14015aab0(uVar1,param_1,4,(ushort)(byte)param_3[8] * 0x101 + -0x8000);

    FUN_14015aab0(uVar1,param_1,5,(ushort)(byte)param_3[9] * 0x101 + -0x8000);

    uVar3 = 0x40;

    if ((ulonglong)(longlong)param_4 < 0x40) {

      uVar3 = (longlong)param_4;

    }

    FUN_1402f8e20(param_2 + 1,param_3,uVar3);

  }

  return;

}




