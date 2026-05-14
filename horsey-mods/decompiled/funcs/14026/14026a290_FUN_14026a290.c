// Address: 0x14026a290
// Ghidra name: FUN_14026a290
// ============ 0x14026a290 FUN_14026a290 (size=625) ============


void FUN_14026a290(undefined8 param_1,undefined8 param_2,longlong param_3,byte *param_4)



{

  byte bVar1;

  undefined1 uVar2;

  undefined8 uVar3;

  

  bVar1 = *param_4;

  if (bVar1 != *(byte *)(param_3 + 0xe3)) {

    uVar2 = FUN_14026ca40(param_3,1,param_3,bVar1 & 1);

    FUN_14015ad00(param_1,param_2,uVar2);

    uVar2 = FUN_14026ca40(param_3,3);

    FUN_14015ad00(param_1,param_2,uVar2);

    uVar2 = FUN_14026ca40(param_3,0);

    FUN_14015ad00(param_1,param_2,uVar2);

    uVar2 = FUN_14026ca40(param_3,2);

    FUN_14015ad00(param_1,param_2,uVar2);

    FUN_14015ad00(param_1,param_2,0xe,bVar1 >> 4 & 1);

    FUN_14015ad00(param_1,param_2,0xc,bVar1 >> 5 & 1);

  }

  bVar1 = param_4[1];

  if (bVar1 != *(byte *)(param_3 + 0xe4)) {

    FUN_14015ad00(param_1,param_2,6,bVar1 >> 1 & 1);

    FUN_14015ad00(param_1,param_2,8,bVar1 >> 3 & 1);

    FUN_14015ad00(param_1,param_2,5,bVar1 >> 4 & 1);

    FUN_14015ad00(param_1,param_2,10,bVar1 >> 6 & 1);

  }

  FUN_14015aab0(param_1,param_2,5,((char)param_4[1] >> 7) + -0x8000);

  if (param_4[2] == *(byte *)(param_3 + 0xe5)) {

    return;

  }

  switch(param_4[2]) {

  case 0:

    uVar3 = 0xffff8000;

    break;

  case 1:

    uVar3 = 0xffff8000;

    goto LAB_14026a44e;

  case 2:

    uVar3 = 0;

    goto LAB_14026a44e;

  case 3:

    uVar3 = 0x7fff;

LAB_14026a44e:

    FUN_14015aab0(param_1,param_2,2,uVar3);

    uVar3 = 0xffff8000;

    goto LAB_14026a4d8;

  case 4:

    uVar3 = 0x7fff;

    break;

  case 5:

    FUN_14015aab0(param_1,param_2,2,0x7fff);

    uVar3 = 0x7fff;

    goto LAB_14026a4d8;

  case 6:

    FUN_14015aab0(param_1,param_2,2,0);

    uVar3 = 0x7fff;

    goto LAB_14026a4d8;

  case 7:

    FUN_14015aab0(param_1,param_2,2,0xffff8000);

    uVar3 = 0x7fff;

    goto LAB_14026a4d8;

  default:

    uVar3 = 0;

  }

  FUN_14015aab0(param_1,param_2,2,uVar3);

  uVar3 = 0;

LAB_14026a4d8:

  FUN_14015aab0(param_1,param_2,3,uVar3);

  return;

}




