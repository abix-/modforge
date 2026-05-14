// Address: 0x140272cb0
// Ghidra name: FUN_140272cb0
// ============ 0x140272cb0 FUN_140272cb0 (size=767) ============


void FUN_140272cb0(undefined8 param_1,undefined8 param_2,longlong param_3,byte *param_4,

                  undefined8 param_5)



{

  byte bVar1;

  short sVar2;

  short sVar3;

  undefined8 uVar4;

  

  bVar1 = param_4[4];

  if (*(byte *)(param_3 + 0x88) != bVar1) {

    FUN_14015ad00(param_5,param_1,2,bVar1 >> 4 & 1);

    FUN_14015ad00(param_5,param_1,0,bVar1 >> 5 & 1);

    FUN_14015ad00(param_5,param_1,1,bVar1 >> 6 & 1);

    FUN_14015ad00(param_5,param_1,3,bVar1 >> 7);

    switch(param_4[4] & 0xf) {

    case 0:

      uVar4 = 1;

      break;

    case 1:

      uVar4 = 3;

      break;

    case 2:

      uVar4 = 2;

      break;

    case 3:

      uVar4 = 6;

      break;

    case 4:

      uVar4 = 4;

      break;

    case 5:

      uVar4 = 0xc;

      break;

    case 6:

      uVar4 = 8;

      break;

    case 7:

      uVar4 = 9;

      break;

    default:

      uVar4 = 0;

    }

    FUN_14015ae90(param_5,param_1,0,uVar4);

  }

  bVar1 = param_4[5];

  if (*(byte *)(param_3 + 0x89) != bVar1) {

    FUN_14015ad00(param_5,param_1,9,bVar1 & 1);

    FUN_14015ad00(param_5,param_1,10,bVar1 >> 1 & 1);

    FUN_14015ad00(param_5,param_1,4,bVar1 >> 4 & 1);

    FUN_14015ad00(param_5,param_1,6,bVar1 >> 5 & 1);

    FUN_14015ad00(param_5,param_1,7,bVar1 >> 6 & 1);

    FUN_14015ad00(param_5,param_1,8,bVar1 >> 7);

  }

  bVar1 = param_4[6];

  if (*(byte *)(param_3 + 0x8a) != bVar1) {

    FUN_14015ad00(param_5,param_1,5,bVar1 & 1);

    FUN_14015ad00(param_5,param_1,0xb,bVar1 >> 1 & 1);

  }

  sVar2 = 0x7fff;

  if ((param_4[7] == 0) && ((param_4[5] & 4) != 0)) {

    sVar3 = 0x7fff;

  }

  else {

    sVar3 = (ushort)param_4[7] * 0x101 + -0x8000;

  }

  FUN_14015aab0(param_5,param_1,4,sVar3);

  if ((param_4[8] != 0) || ((param_4[5] & 8) == 0)) {

    sVar2 = (ushort)param_4[8] * 0x101 + -0x8000;

  }

  FUN_14015aab0(param_5,param_1,5,sVar2);

  FUN_14015aab0(param_5,param_1,0,(ushort)*param_4 * 0x101 + -0x8000);

  FUN_14015aab0(param_5,param_1,1,(ushort)param_4[1] * 0x101 + -0x8000);

  FUN_14015aab0(param_5,param_1,2,(ushort)param_4[2] * 0x101 + -0x8000);

  FUN_14015aab0(param_5,param_1,3,(ushort)param_4[3] * 0x101 + -0x8000);

  *(undefined8 *)(param_3 + 0x84) = *(undefined8 *)param_4;

  *(byte *)(param_3 + 0x8c) = param_4[8];

  return;

}




