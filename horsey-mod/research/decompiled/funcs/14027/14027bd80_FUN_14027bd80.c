// Address: 0x14027bd80
// Ghidra name: FUN_14027bd80
// ============ 0x14027bd80 FUN_14027bd80 (size=522) ============


void FUN_14027bd80(undefined8 param_1,longlong param_2,longlong param_3,int param_4)



{

  undefined8 uVar1;

  ulonglong uVar2;

  short sVar3;

  undefined8 uVar4;

  

  uVar1 = FUN_140149300();

  if (param_4 == 0x10) {

    FUN_14027bbf0(uVar1,param_1,param_2,param_3,0x10);

  }

  else {

    if (param_4 < 0x11) {

      return;

    }

    FUN_14027b990(uVar1,param_1,param_2,param_3,param_4);

  }

  if (*(char *)(param_2 + 0x69) != *(char *)(param_3 + 0xd)) {

    switch(*(char *)(param_3 + 0xd)) {

    case '\x01':

      uVar4 = 1;

      break;

    case '\x02':

      uVar4 = 3;

      break;

    case '\x03':

      uVar4 = 2;

      break;

    case '\x04':

      uVar4 = 6;

      break;

    case '\x05':

      uVar4 = 4;

      break;

    case '\x06':

      uVar4 = 0xc;

      break;

    case '\a':

      uVar4 = 8;

      break;

    case '\b':

      uVar4 = 9;

      break;

    default:

      uVar4 = 0;

    }

    FUN_14015ae90(uVar1,param_1,0,uVar4);

  }

  sVar3 = (*(short *)(param_3 + 9) + -0x200) * 0x40;

  if (sVar3 == 0x7fc0) {

    sVar3 = 0x7fff;

  }

  FUN_14015aab0(uVar1,param_1,4,sVar3);

  sVar3 = (*(short *)(param_3 + 0xb) + -0x200) * 0x40;

  if (sVar3 == 0x7fc0) {

    sVar3 = 0x7fff;

  }

  FUN_14015aab0(uVar1,param_1,5,sVar3);

  FUN_14015aab0(uVar1,param_1,0,*(short *)(param_3 + 1) + -0x8000);

  FUN_14015aab0(uVar1,param_1,1,*(short *)(param_3 + 3) + -0x8000);

  FUN_14015aab0(uVar1,param_1,2,*(short *)(param_3 + 5) + -0x8000);

  FUN_14015aab0(uVar1,param_1,3,*(short *)(param_3 + 7) + -0x8000);

  uVar2 = 0x40;

  if ((ulonglong)(longlong)param_4 < 0x40) {

    uVar2 = (longlong)param_4;

  }

  FUN_1402f8e20(param_2 + 0x5c,param_3,uVar2);

  return;

}




