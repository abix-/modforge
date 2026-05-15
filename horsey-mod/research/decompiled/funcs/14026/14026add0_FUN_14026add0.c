// Address: 0x14026add0
// Ghidra name: FUN_14026add0
// ============ 0x14026add0 FUN_14026add0 (size=911) ============


void FUN_14026add0(undefined8 param_1,longlong param_2,byte *param_3)



{

  byte bVar1;

  undefined1 uVar2;

  undefined8 uVar3;

  undefined8 uVar4;

  float fVar5;

  undefined4 uVar6;

  undefined4 uVar7;

  

  uVar3 = FUN_140149300();

  bVar1 = *param_3;

  if (bVar1 != *(byte *)(param_2 + 0xdc)) {

    uVar2 = FUN_14026ca40(param_2,0);

    FUN_14015ad00(uVar3,param_1,uVar2);

    uVar2 = FUN_14026ca40(param_2,1);

    FUN_14015ad00(uVar3,param_1,uVar2);

    uVar2 = FUN_14026ca40(param_2,2);

    FUN_14015ad00(uVar3,param_1,uVar2);

    uVar2 = FUN_14026ca40(param_2,3);

    FUN_14015ad00(uVar3,param_1,uVar2);

    FUN_14015ad00(uVar3,param_1,9,bVar1 >> 4 & 1);

    FUN_14015ad00(uVar3,param_1,10,bVar1 >> 5 & 1);

  }

  bVar1 = param_3[1];

  if (bVar1 != *(byte *)(param_2 + 0xdd)) {

    FUN_14015ad00(uVar3,param_1,4,bVar1 & 1);

    FUN_14015ad00(uVar3,param_1,6,bVar1 >> 1 & 1);

    FUN_14015ad00(uVar3,param_1,7,bVar1 >> 2 & 1);

    FUN_14015ad00(uVar3,param_1,8,bVar1 >> 3 & 1);

    FUN_14015ad00(uVar3,param_1,5,bVar1 >> 4 & 1);

    FUN_14015ad00(uVar3,param_1,0xb,bVar1 >> 5 & 1);

  }

  if (param_3[2] != *(byte *)(param_2 + 0xde)) {

    switch(param_3[2]) {

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

    FUN_14015ae90(uVar3,param_1,0,uVar4);

  }

  uVar4 = 0xffff8000;

  if ((*param_3 & 0x40) != 0) {

    uVar4 = 0xffff7fff;

  }

  FUN_14015aab0(uVar3,param_1,4,uVar4);

  FUN_14015aab0(uVar3,param_1,5,((char)*param_3 >> 7) + -0x8000);

  uVar7 = DAT_1403053f0;

  if (param_3[3] != *(byte *)(param_2 + 0xdf)) {

    uVar6 = DAT_1403053f0;

    fVar5 = (float)FUN_140208370();

    FUN_14015aab0(uVar3,param_1,0,(int)fVar5,uVar6);

  }

  if (param_3[4] != *(byte *)(param_2 + 0xe0)) {

    uVar6 = uVar7;

    fVar5 = (float)FUN_140208370();

    FUN_14015aab0(uVar3,param_1,1,(int)fVar5,uVar6);

  }

  if (param_3[5] != *(byte *)(param_2 + 0xe1)) {

    uVar6 = uVar7;

    fVar5 = (float)FUN_140208370();

    FUN_14015aab0(uVar3,param_1,2,(int)fVar5,uVar6);

  }

  if (param_3[6] != *(byte *)(param_2 + 0xe2)) {

    fVar5 = (float)FUN_140208370();

    FUN_14015aab0(uVar3,param_1,3,(int)fVar5,uVar7);

  }

  *(undefined4 *)(param_2 + 0xdc) = *(undefined4 *)param_3;

  *(undefined2 *)(param_2 + 0xe0) = *(undefined2 *)(param_3 + 4);

  *(byte *)(param_2 + 0xe2) = param_3[6];

  return;

}




