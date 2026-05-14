// Address: 0x14026ddb0
// Ghidra name: FUN_14026ddb0
// ============ 0x14026ddb0 FUN_14026ddb0 (size=916) ============


void FUN_14026ddb0(undefined8 param_1,longlong param_2,longlong param_3,int param_4)



{

  undefined8 uVar1;

  undefined2 uVar2;

  ulonglong uVar3;

  int iVar4;

  undefined8 uVar5;

  float fVar6;

  undefined4 uVar7;

  undefined4 uVar8;

  

  uVar1 = FUN_140149300();

  if (*(byte *)(param_2 + 1) != *(byte *)(param_3 + 1)) {

    FUN_14015ad00(uVar1,param_1,0,*(byte *)(param_3 + 1) & 1);

    FUN_14015ad00(uVar1,param_1,1,*(byte *)(param_3 + 1) >> 1 & 1);

    FUN_14015ad00(uVar1,param_1,2,*(byte *)(param_3 + 1) >> 2 & 1);

    FUN_14015ad00(uVar1,param_1,3,*(byte *)(param_3 + 1) >> 3 & 1);

    FUN_14015ad00(uVar1,param_1,9,*(byte *)(param_3 + 1) >> 4 & 1);

    FUN_14015ad00(uVar1,param_1,10,*(byte *)(param_3 + 1) >> 5 & 1);

    FUN_14015ad00(uVar1,param_1,4,*(byte *)(param_3 + 1) >> 6 & 1);

    FUN_14015ad00(uVar1,param_1,6,*(byte *)(param_3 + 1) >> 7);

  }

  if (*(byte *)(param_2 + 2) != *(byte *)(param_3 + 2)) {

    FUN_14015ad00(uVar1,param_1,5,*(byte *)(param_3 + 2) & 1);

    FUN_14015ad00(uVar1,param_1,0xb,*(byte *)(param_3 + 2) >> 1 & 1);

    FUN_14015ad00(uVar1,param_1,7,*(byte *)(param_3 + 2) >> 2 & 1);

    FUN_14015ad00(uVar1,param_1,8,*(byte *)(param_3 + 2) >> 3 & 1);

  }

  if (*(byte *)(param_2 + 3) != *(byte *)(param_3 + 3)) {

    switch(*(byte *)(param_3 + 3) & 0xf) {

    case 0:

      uVar5 = 1;

      break;

    case 1:

      uVar5 = 3;

      break;

    case 2:

      uVar5 = 2;

      break;

    case 3:

      uVar5 = 6;

      break;

    case 4:

      uVar5 = 4;

      break;

    case 5:

      uVar5 = 0xc;

      break;

    case 6:

      uVar5 = 8;

      break;

    case 7:

      uVar5 = 9;

      break;

    default:

      uVar5 = 0;

    }

    FUN_14015ae90(uVar1,param_1,0,uVar5);

  }

  uVar8 = DAT_1403053f0;

  uVar2 = 0;

  if (*(char *)(param_3 + 4) == '\x7f') {

    iVar4 = 0;

  }

  else {

    fVar6 = (float)FUN_140208370();

    iVar4 = (int)fVar6;

  }

  FUN_14015aab0(uVar1,param_1,0,iVar4);

  if (*(char *)(param_3 + 5) == '\x7f') {

    iVar4 = 0;

  }

  else {

    fVar6 = (float)FUN_140208370();

    iVar4 = (int)fVar6;

  }

  FUN_14015aab0(uVar1,param_1,1,iVar4);

  if (*(char *)(param_3 + 6) == '\x7f') {

    iVar4 = 0;

  }

  else {

    fVar6 = (float)FUN_140208370();

    iVar4 = (int)fVar6;

  }

  FUN_14015aab0(uVar1,param_1,2,iVar4);

  if (*(char *)(param_3 + 7) != '\x7f') {

    fVar6 = (float)FUN_140208370();

    uVar2 = (undefined2)(int)fVar6;

  }

  FUN_14015aab0(uVar1,param_1,3,uVar2);

  uVar7 = uVar8;

  fVar6 = (float)FUN_140208370();

  FUN_14015aab0(uVar1,param_1,4,(int)fVar6,uVar7);

  fVar6 = (float)FUN_140208370();

  FUN_14015aab0(uVar1,param_1,5,(int)fVar6,uVar8);

  uVar3 = 0x40;

  if ((ulonglong)(longlong)param_4 < 0x40) {

    uVar3 = (longlong)param_4;

  }

  FUN_1402f8e20(param_2,param_3,uVar3);

  return;

}




