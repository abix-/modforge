// Address: 0x140283890
// Ghidra name: FUN_140283890
// ============ 0x140283890 FUN_140283890 (size=1257) ============


void FUN_140283890(undefined8 param_1,byte *param_2,byte *param_3,ulonglong param_4)



{

  undefined8 uVar1;

  ulonglong uVar2;

  int iVar3;

  int iVar4;

  undefined8 uVar5;

  uint uVar6;

  float fVar7;

  undefined4 local_78;

  undefined4 local_74;

  undefined4 local_70;

  float local_68;

  float local_64;

  float local_60;

  

  iVar3 = (int)param_4;

  uVar1 = FUN_140149300();

  if (param_2[2] != param_3[2]) {

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

  if (*param_2 != *param_3) {

    FUN_14015ad00(uVar1,param_1,3,*param_3 & 1);

    FUN_14015ad00(uVar1,param_1,1,*param_3 >> 1 & 1);

    FUN_14015ad00(uVar1,param_1,0,*param_3 >> 2 & 1);

    FUN_14015ad00(uVar1,param_1,2,*param_3 >> 3 & 1);

    FUN_14015ad00(uVar1,param_1,9,*param_3 >> 4 & 1);

    FUN_14015ad00(uVar1,param_1,10,*param_3 >> 5 & 1);

    uVar5 = 0xffff8000;

    if ((*param_3 & 0x40) != 0) {

      uVar5 = 0xffff7fff;

    }

    FUN_14015aab0(uVar1,param_1,4,uVar5);

    FUN_14015aab0(uVar1,param_1,5,((char)*param_3 >> 7) + -0x8000);

  }

  if (param_2[1] != param_3[1]) {

    FUN_14015ad00(uVar1,param_1,4,param_3[1] & 1);

    FUN_14015ad00(uVar1,param_1,6,param_3[1] >> 1 & 1);

    FUN_14015ad00(uVar1,param_1,7,param_3[1] >> 2 & 1);

    FUN_14015ad00(uVar1,param_1,8,param_3[1] >> 3 & 1);

    FUN_14015ad00(uVar1,param_1,5,param_3[1] >> 4 & 1);

    FUN_14015ad00(uVar1,param_1,0xf,param_3[1] >> 5 & 1);

  }

  uVar6 = 0;

  if (param_3[3] == 0x7f) {

    iVar4 = 0;

  }

  else {

    fVar7 = (float)FUN_140208370();

    iVar4 = (int)fVar7;

  }

  FUN_14015aab0(uVar1,param_1,0,iVar4);

  if (param_3[4] == 0x7f) {

    iVar4 = 0;

  }

  else {

    fVar7 = (float)FUN_140208370();

    iVar4 = (int)fVar7;

  }

  FUN_14015aab0(uVar1,param_1,1,iVar4);

  if (param_3[5] == 0x7f) {

    iVar4 = 0;

  }

  else {

    fVar7 = (float)FUN_140208370();

    iVar4 = (int)fVar7;

  }

  FUN_14015aab0(uVar1,param_1,2,iVar4);

  if (param_3[6] != 0x7f) {

    fVar7 = (float)FUN_140208370();

    uVar6 = (uint)fVar7;

  }

  FUN_14015aab0(uVar1,param_1,3,uVar6 & 0xffff);

  if (param_2[0x40] != 0) {

    fVar7 = DAT_1403802b8;

    local_78 = FUN_1402842c0(param_2 + 0x54,(float)(int)*(short *)(param_3 + 8) * DAT_1403802b8);

    local_74 = FUN_1402842c0(param_2 + 0x84,(float)(int)*(short *)(param_3 + 0xc) * fVar7);

    local_70 = FUN_1402842c0(param_2 + 0xb4,

                             (float)(int)-((int)(short)((ushort)param_3[0xb] << 8) |

                                          (uint)param_3[10]) * fVar7);

    local_68 = (float)(int)*(short *)(param_3 + 0xe) * DAT_14037ef9c;

    local_60 = (float)(int)-((int)(short)((ushort)param_3[0x11] << 8) | (uint)param_3[0x10]) *

               DAT_14037ef9c;

    local_64 = (float)(int)*(short *)(param_3 + 0x12) * DAT_14037ef9c;

    FUN_14015afd0(uVar1,param_1,2,uVar1,&local_78,3);

    FUN_14015afd0(uVar1,param_1,1,uVar1,&local_68,3);

  }

  uVar2 = 0x40;

  if ((ulonglong)(longlong)iVar3 < 0x40) {

    uVar2 = (longlong)iVar3;

  }

  FUN_1402f8e20(param_2,param_3,uVar2);

  return;

}




