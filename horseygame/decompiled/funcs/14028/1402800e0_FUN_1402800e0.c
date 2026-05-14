// Address: 0x1402800e0
// Ghidra name: FUN_1402800e0
// ============ 0x1402800e0 FUN_1402800e0 (size=903) ============


void FUN_1402800e0(undefined8 param_1,longlong param_2,byte *param_3,ulonglong param_4)



{

  undefined8 uVar1;

  undefined2 uVar2;

  ulonglong uVar3;

  int iVar4;

  int iVar5;

  undefined8 uVar6;

  float fVar7;

  

  iVar4 = (int)param_4;

  uVar1 = FUN_140149300();

  if (*(byte *)(param_2 + 0x1e) != param_3[2]) {

    switch(param_3[2]) {

    case 0:

      param_4 = 1;

      break;

    case 1:

      param_4 = 3;

      break;

    case 2:

      param_4 = 2;

      break;

    case 3:

      param_4 = 6;

      break;

    case 4:

      param_4 = 4;

      break;

    case 5:

      param_4 = 0xc;

      break;

    case 6:

      param_4 = 8;

      break;

    case 7:

      param_4 = 9;

      break;

    default:

      param_4 = param_4 & 0xffffffffffffff00;

    }

    FUN_14015ae90(uVar1,param_1,0,param_4);

  }

  if (*(byte *)(param_2 + 0x1c) != *param_3) {

    FUN_14015ad00(uVar1,param_1,0,*param_3 & 1);

    FUN_14015ad00(uVar1,param_1,1,*param_3 >> 1 & 1);

    FUN_14015ad00(uVar1,param_1,2,*param_3 >> 3 & 1);

    FUN_14015ad00(uVar1,param_1,3,*param_3 >> 4 & 1);

    FUN_14015ad00(uVar1,param_1,9,*param_3 >> 6 & 1);

    FUN_14015ad00(uVar1,param_1,10,*param_3 >> 7);

  }

  if (*(byte *)(param_2 + 0x1d) != param_3[1]) {

    FUN_14015ad00(uVar1,param_1,5,param_3[1] >> 4 & 1);

    FUN_14015ad00(uVar1,param_1,4,param_3[1] >> 2 & 1);

    FUN_14015ad00(uVar1,param_1,6,param_3[1] >> 3 & 1);

    FUN_14015ad00(uVar1,param_1,7,param_3[1] >> 5 & 1);

    FUN_14015ad00(uVar1,param_1,8,param_3[1] >> 6 & 1);

    uVar2 = 0x8000;

    uVar6 = 0xffff8000;

    if ((param_3[1] & 1) != 0) {

      uVar6 = 0xffff7fff;

    }

    FUN_14015aab0(uVar1,param_1,4,uVar6);

    if ((param_3[1] & 2) != 0) {

      uVar2 = 0x7fff;

    }

    FUN_14015aab0(uVar1,param_1,5,uVar2);

  }

  uVar2 = 0;

  if (param_3[3] == 0x7f) {

    iVar5 = 0;

  }

  else {

    fVar7 = (float)FUN_140208370();

    iVar5 = (int)fVar7;

  }

  FUN_14015aab0(uVar1,param_1,0,iVar5);

  if (param_3[4] == 0x7f) {

    iVar5 = 0;

  }

  else {

    fVar7 = (float)FUN_140208370();

    iVar5 = (int)fVar7;

  }

  FUN_14015aab0(uVar1,param_1,1,iVar5);

  if (param_3[5] == 0x7f) {

    iVar5 = 0;

  }

  else {

    fVar7 = (float)FUN_140208370();

    iVar5 = (int)fVar7;

  }

  FUN_14015aab0(uVar1,param_1,2,iVar5);

  if (param_3[6] != 0x7f) {

    fVar7 = (float)FUN_140208370();

    uVar2 = (undefined2)(int)fVar7;

  }

  FUN_14015aab0(uVar1,param_1,3,uVar2);

  uVar3 = 0x40;

  if ((ulonglong)(longlong)iVar4 < 0x40) {

    uVar3 = (longlong)iVar4;

  }

  FUN_1402f8e20((byte *)(param_2 + 0x1c),param_3,uVar3);

  return;

}




