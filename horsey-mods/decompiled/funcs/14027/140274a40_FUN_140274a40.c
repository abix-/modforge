// Address: 0x140274a40
// Ghidra name: FUN_140274a40
// ============ 0x140274a40 FUN_140274a40 (size=762) ============


void FUN_140274a40(undefined8 param_1,longlong param_2,longlong param_3,ulonglong param_4)



{

  undefined8 uVar1;

  ulonglong uVar2;

  int iVar3;

  

  iVar3 = (int)param_4;

  uVar1 = FUN_140149300();

  if (*(char *)(param_2 + 0x23) != *(char *)(param_3 + 3)) {

    switch(*(char *)(param_3 + 3)) {

    case '\0':

      param_4 = 1;

      break;

    case '\x01':

      param_4 = 3;

      break;

    case '\x02':

      param_4 = 2;

      break;

    case '\x03':

      param_4 = 6;

      break;

    case '\x04':

      param_4 = 4;

      break;

    case '\x05':

      param_4 = 0xc;

      break;

    case '\x06':

      param_4 = 8;

      break;

    case '\a':

      param_4 = 9;

      break;

    default:

      param_4 = param_4 & 0xffffffffffffff00;

    }

    FUN_14015ae90(uVar1,param_1,0,param_4);

  }

  if (*(byte *)(param_2 + 0x21) != *(byte *)(param_3 + 1)) {

    FUN_14015ad00(uVar1,param_1,0,*(byte *)(param_3 + 1) & 1);

    FUN_14015ad00(uVar1,param_1,1,*(byte *)(param_3 + 1) >> 1 & 1);

    FUN_14015ad00(uVar1,param_1,2,*(byte *)(param_3 + 1) >> 2 & 1);

    FUN_14015ad00(uVar1,param_1,3,*(byte *)(param_3 + 1) >> 3 & 1);

    FUN_14015ad00(uVar1,param_1,9,*(byte *)(param_3 + 1) >> 4 & 1);

    FUN_14015ad00(uVar1,param_1,10,*(byte *)(param_3 + 1) >> 5 & 1);

    FUN_14015ad00(uVar1,param_1,7,*(byte *)(param_3 + 1) >> 6 & 1);

    FUN_14015ad00(uVar1,param_1,8,*(byte *)(param_3 + 1) >> 7);

  }

  if (*(byte *)(param_2 + 0x22) != *(byte *)(param_3 + 2)) {

    FUN_14015ad00(uVar1,param_1,6,*(byte *)(param_3 + 2) >> 1 & 1);

    FUN_14015ad00(uVar1,param_1,0xe,*(byte *)(param_3 + 2) >> 3 & 1);

    FUN_14015ad00(uVar1,param_1,0xd,*(byte *)(param_3 + 2) >> 4 & 1);

    FUN_14015ad00(uVar1,param_1,4,*(byte *)(param_3 + 2) >> 6 & 1);

    FUN_14015ad00(uVar1,param_1,5,*(byte *)(param_3 + 2) >> 7);

  }

  FUN_14015aab0(uVar1,param_1,0,*(short *)(param_3 + 4) + -0x8000);

  FUN_14015aab0(uVar1,param_1,1,*(short *)(param_3 + 6) + -0x8000);

  FUN_14015aab0(uVar1,param_1,2,*(short *)(param_3 + 8) + -0x8000);

  FUN_14015aab0(uVar1,param_1,3,*(short *)(param_3 + 10) + -0x8000);

  FUN_14015aab0(uVar1,param_1,4,*(short *)(param_3 + 0xc) + -0x8000);

  FUN_14015aab0(uVar1,param_1,5,*(short *)(param_3 + 0xe) + -0x8000);

  uVar2 = 0x40;

  if ((ulonglong)(longlong)iVar3 < 0x40) {

    uVar2 = (longlong)iVar3;

  }

  FUN_1402f8e20(param_2 + 0x20,param_3,uVar2);

  return;

}




