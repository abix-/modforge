// Address: 0x140283da0
// Ghidra name: FUN_140283da0
// ============ 0x140283da0 FUN_140283da0 (size=1268) ============


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void FUN_140283da0(undefined8 param_1,longlong param_2,longlong param_3,int param_4)



{

  uint uVar1;

  undefined8 uVar2;

  ulonglong uVar3;

  undefined8 uVar4;

  float fVar5;

  undefined8 in_stack_ffffffffffffff98;

  undefined4 uVar6;

  undefined4 local_58;

  undefined4 local_54;

  undefined4 local_50;

  float local_48;

  float local_44;

  float local_40;

  

  uVar6 = (undefined4)((ulonglong)in_stack_ffffffffffffff98 >> 0x20);

  uVar2 = FUN_140149300();

  uVar1 = DAT_1403053f0;

  uVar4 = CONCAT44(uVar6,DAT_1403053f0);

  fVar5 = (float)FUN_140208370();

  FUN_14015aab0(uVar2,param_1,0,(int)fVar5,uVar4);

  uVar3 = (ulonglong)uVar1;

  fVar5 = (float)FUN_140208370();

  FUN_14015aab0(uVar2,param_1,1,(int)fVar5,uVar3);

  uVar3 = (ulonglong)uVar1;

  fVar5 = (float)FUN_140208370();

  FUN_14015aab0(uVar2,param_1,2,(int)fVar5,uVar3);

  uVar3 = (ulonglong)uVar1;

  fVar5 = (float)FUN_140208370();

  FUN_14015aab0(uVar2,param_1,3,(int)fVar5,uVar3);

  uVar3 = (ulonglong)uVar1;

  fVar5 = (float)FUN_140208370();

  FUN_14015aab0(uVar2,param_1,4,(int)fVar5,uVar3);

  uVar3 = (ulonglong)uVar1;

  fVar5 = (float)FUN_140208370();

  FUN_14015aab0(uVar2,param_1,5,(int)fVar5,uVar3);

  if (*(char *)(param_2 + 0xd) != *(char *)(param_3 + 0xd)) {

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

    FUN_14015ae90(uVar2,param_1,0,uVar4);

  }

  if (*(byte *)(param_2 + 0xe) != *(byte *)(param_3 + 0xe)) {

    FUN_14015ad00(uVar2,param_1,0,*(byte *)(param_3 + 0xe) & 1);

    FUN_14015ad00(uVar2,param_1,1,*(byte *)(param_3 + 0xe) >> 1 & 1);

    FUN_14015ad00(uVar2,param_1,2,*(byte *)(param_3 + 0xe) >> 3 & 1);

    FUN_14015ad00(uVar2,param_1,3,*(byte *)(param_3 + 0xe) >> 4 & 1);

    FUN_14015ad00(uVar2,param_1,9,*(byte *)(param_3 + 0xe) >> 6 & 1);

    FUN_14015ad00(uVar2,param_1,10,*(byte *)(param_3 + 0xe) >> 7);

  }

  if (*(byte *)(param_2 + 0xf) != *(byte *)(param_3 + 0xf)) {

    FUN_14015ad00(uVar2,param_1,4,*(byte *)(param_3 + 0xf) >> 2 & 1);

    FUN_14015ad00(uVar2,param_1,6,*(byte *)(param_3 + 0xf) >> 3 & 1);

    FUN_14015ad00(uVar2,param_1,5,*(byte *)(param_3 + 0xf) >> 4 & 1);

    FUN_14015ad00(uVar2,param_1,7,*(byte *)(param_3 + 0xf) >> 5 & 1);

    FUN_14015ad00(uVar2,param_1,8,*(byte *)(param_3 + 0xf) >> 6 & 1);

  }

  if (*(char *)(param_2 + 0x40) != '\0') {

    fVar5 = DAT_1403802b8;

    local_58 = FUN_1402842c0(param_2 + 0x54,(float)(int)*(short *)(param_3 + 0x11) * DAT_1403802b8);

    local_54 = FUN_1402842c0(param_2 + 0x84,(float)(int)*(short *)(param_3 + 0x15) * fVar5);

    local_50 = FUN_1402842c0(param_2 + 0xb4,

                             (float)(int)-((int)(short)((ushort)*(byte *)(param_3 + 0x14) << 8) |

                                          (uint)*(byte *)(param_3 + 0x13)) * fVar5);

    FUN_14015afd0(uVar2,param_1,2,uVar2,&local_58,3);

    local_48 = (float)(int)*(short *)(param_3 + 0x17) * DAT_14037ef9c;

    local_40 = (float)(int)-((int)(short)((ushort)*(byte *)(param_3 + 0x1a) << 8) |

                            (uint)*(byte *)(param_3 + 0x19)) * DAT_14037ef9c;

    local_44 = (float)(int)*(short *)(param_3 + 0x1b) * DAT_14037ef9c;

    FUN_14015afd0(uVar2,param_1,1,uVar2,&local_48,3);

  }

  uVar3 = 0x40;

  if ((ulonglong)(longlong)param_4 < 0x40) {

    uVar3 = (longlong)param_4;

  }

  FUN_1402f8e20(param_2,param_3,uVar3);

  return;

}




