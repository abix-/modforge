// Address: 0x14026f7e0
// Ghidra name: FUN_14026f7e0
// ============ 0x14026f7e0 FUN_14026f7e0 (size=669) ============


void FUN_14026f7e0(undefined8 param_1,longlong param_2,byte *param_3,int param_4)



{

  undefined8 uVar1;

  ulonglong uVar2;

  undefined8 uVar3;

  

  uVar1 = FUN_140149300();

  if (*(byte *)(param_2 + 0x1e) != param_3[4]) {

    switch(param_3[4] & 0xf) {

    case 0:

      uVar3 = 1;

      break;

    case 1:

      uVar3 = 3;

      break;

    case 2:

      uVar3 = 2;

      break;

    case 3:

      uVar3 = 6;

      break;

    case 4:

      uVar3 = 4;

      break;

    case 5:

      uVar3 = 0xc;

      break;

    case 6:

      uVar3 = 8;

      break;

    case 7:

      uVar3 = 9;

      break;

    default:

      uVar3 = 0;

    }

    FUN_14015ae90(uVar1,param_1,0,uVar3);

    FUN_14015ad00(uVar1,param_1,3,param_3[4] >> 4 & 1);

    FUN_14015ad00(uVar1,param_1,1,param_3[4] >> 5 & 1);

    FUN_14015ad00(uVar1,param_1,0,param_3[4] >> 6 & 1);

    FUN_14015ad00(uVar1,param_1,2,param_3[4] >> 7);

  }

  if (*(byte *)(param_2 + 0x1f) != param_3[5]) {

    FUN_14015ad00(uVar1,param_1,9,param_3[5] & 1);

    FUN_14015ad00(uVar1,param_1,10,param_3[5] >> 1 & 1);

    uVar3 = 0xffff8000;

    if ((param_3[5] & 4) != 0) {

      uVar3 = 0xffff7fff;

    }

    FUN_14015aab0(uVar1,param_1,4,uVar3);

    uVar3 = 0xffff8000;

    if ((param_3[5] & 8) != 0) {

      uVar3 = 0xffff7fff;

    }

    FUN_14015aab0(uVar1,param_1,5,uVar3);

    FUN_14015ad00(uVar1,param_1,4,param_3[5] >> 4 & 1);

    FUN_14015ad00(uVar1,param_1,6,param_3[5] >> 5 & 1);

    FUN_14015ad00(uVar1,param_1,7,param_3[5] >> 6 & 1);

    FUN_14015ad00(uVar1,param_1,8,param_3[5] >> 7);

  }

  FUN_14015aab0(uVar1,param_1,0,(ushort)param_3[2] * 0x101 + -0x8000);

  FUN_14015aab0(uVar1,param_1,1,(ushort)param_3[3] * 0x101 + -0x8000);

  FUN_14015aab0(uVar1,param_1,2,(ushort)*param_3 * 0x101 + -0x8000);

  FUN_14015aab0(uVar1,param_1,3,(ushort)param_3[1] * 0x101 + -0x8000);

  uVar2 = 0x40;

  if ((ulonglong)(longlong)param_4 < 0x40) {

    uVar2 = (longlong)param_4;

  }

  FUN_1402f8e20(param_2 + 0x1a,param_3,uVar2);

  return;

}




