// Address: 0x1402816a0
// Ghidra name: FUN_1402816a0
// ============ 0x1402816a0 FUN_1402816a0 (size=1485) ============


void FUN_1402816a0(undefined8 param_1,longlong param_2,longlong param_3,int param_4)



{

  uint uVar1;

  longlong lVar2;

  undefined4 uVar3;

  undefined4 uVar4;

  undefined8 uVar5;

  char cVar6;

  ulonglong uVar7;

  short sVar8;

  undefined8 uVar9;

  uint uVar10;

  undefined8 in_stack_ffffffffffffffa8;

  undefined4 uVar11;

  float local_48;

  float local_44;

  float local_40;

  

  uVar11 = (undefined4)((ulonglong)in_stack_ffffffffffffffa8 >> 0x20);

  uVar5 = FUN_140149300();

  cVar6 = '\x0f';

  if (*(byte *)(param_2 + 0x4b) != *(byte *)(param_3 + 0xb)) {

    switch(*(byte *)(param_3 + 0xb) & 0xf) {

    case 1:

      uVar9 = 1;

      break;

    case 2:

      uVar9 = 2;

      break;

    case 3:

      uVar9 = 3;

      break;

    case 4:

      uVar9 = 4;

      break;

    default:

      uVar9 = 0;

      break;

    case 6:

      uVar9 = 6;

      break;

    case 8:

      uVar9 = 8;

      break;

    case 9:

      uVar9 = 9;

      break;

    case 0xc:

      uVar9 = 0xc;

    }

    FUN_14015ae90(uVar5,param_1,0,uVar9);

    FUN_14015ad00(uVar5,param_1,0,*(byte *)(param_3 + 0xb) >> 4 & 1);

    FUN_14015ad00(uVar5,param_1,1,*(byte *)(param_3 + 0xb) >> 5 & 1);

    FUN_14015ad00(uVar5,param_1,4,*(byte *)(param_3 + 0xb) >> 6 & 1);

    FUN_14015ad00(uVar5,param_1,2,*(byte *)(param_3 + 0xb) >> 7);

  }

  if (*(byte *)(param_2 + 0x4c) != *(byte *)(param_3 + 0xc)) {

    FUN_14015ad00(uVar5,param_1,3,*(byte *)(param_3 + 0xc) & 1);

    FUN_14015ad00(uVar5,param_1,6,*(byte *)(param_3 + 0xc) >> 1 & 1);

    FUN_14015ad00(uVar5,param_1,9,*(byte *)(param_3 + 0xc) >> 2 & 1);

    FUN_14015ad00(uVar5,param_1,10,*(byte *)(param_3 + 0xc) >> 3 & 1);

    FUN_14015ad00(uVar5,param_1,7,*(byte *)(param_3 + 0xc) >> 6 & 1);

    FUN_14015ad00(uVar5,param_1,8,*(byte *)(param_3 + 0xc) >> 7);

  }

  if (*(byte *)(param_2 + 0x4d) == *(byte *)(param_3 + 0xd)) {

    cVar6 = '\x11';

    if (*(char *)(param_2 + 10) == '\0') {

      cVar6 = '\x0f';

    }

    if (*(char *)(param_2 + 0xb) != '\0') {

      cVar6 = cVar6 + '\x02';

    }

  }

  else {

    FUN_14015ad00(uVar5,param_1,0xb,*(byte *)(param_3 + 0xd) >> 2 & 1);

    FUN_14015ad00(uVar5,param_1,0xc,*(byte *)(param_3 + 0xd) >> 3 & 1);

    FUN_14015ad00(uVar5,param_1,0xd,*(byte *)(param_3 + 0xd) >> 4 & 1);

    FUN_14015ad00(uVar5,param_1,0xe,*(byte *)(param_3 + 0xd) >> 5 & 1);

    if (*(char *)(param_2 + 10) != '\0') {

      FUN_14015ad00(uVar5,param_1,0xf,*(byte *)(param_3 + 0xd) & 1);

      FUN_14015ad00(uVar5,param_1,0x10,*(byte *)(param_3 + 0xd) >> 1 & 1);

      cVar6 = '\x11';

    }

    if (*(char *)(param_2 + 0xb) != '\0') {

      FUN_14015ad00(uVar5,param_1,cVar6,*(byte *)(param_3 + 0xd) >> 6 & 1);

      FUN_14015ad00(uVar5,param_1,cVar6 + '\x01',*(byte *)(param_3 + 0xd) >> 7);

      cVar6 = cVar6 + '\x02';

    }

  }

  if ((*(byte *)(param_2 + 0x4e) != *(byte *)(param_3 + 0xe)) &&

     (FUN_14015ad00(uVar5,param_1,5,*(byte *)(param_3 + 0xe) >> 3 & 1),

     *(char *)(param_2 + 0xc) != '\0')) {

    FUN_14015ad00(uVar5,param_1,cVar6,*(byte *)(param_3 + 0xe) & 1);

  }

  FUN_14015aab0(uVar5,param_1,0,*(undefined2 *)(param_3 + 3));

  sVar8 = -*(short *)(param_3 + 5);

  if (sVar8 < -0x7fff) {

    sVar8 = 0x7fff;

  }

  FUN_14015aab0(uVar5,param_1,1,sVar8);

  FUN_14015aab0(uVar5,param_1,2,*(undefined2 *)(param_3 + 7));

  sVar8 = -*(short *)(param_3 + 9);

  if (sVar8 < -0x7fff) {

    sVar8 = 0x7fff;

  }

  FUN_14015aab0(uVar5,param_1,3,sVar8);

  FUN_14015aab0(uVar5,param_1,4,(ushort)*(byte *)(param_3 + 0xf) * 0x101 + -0x8000);

  FUN_14015aab0(uVar5,param_1,5,(ushort)*(byte *)(param_3 + 0x10) * 0x101 + -0x8000);

  uVar4 = DAT_14037dea8;

  uVar3 = DAT_1403053f0;

  if (*(char *)(param_2 + 0xf) != '\0') {

    lVar2 = *(longlong *)(param_2 + 0x18);

    *(longlong *)(param_2 + 0x18) = *(longlong *)(param_2 + 0x20) + lVar2;

    uVar1 = *(uint *)(param_2 + 0x2c);

    uVar10 = uVar1 ^ DAT_14039cac0;

    local_48 = (float)FUN_140208370((ulonglong)*(byte *)(param_3 + 0x12) << 8,uVar4,uVar3,uVar10,

                                    CONCAT44(uVar11,uVar1));

    local_44 = (float)FUN_140208370((ulonglong)*(byte *)(param_3 + 0x16) << 8,DAT_14037dea8,

                                    DAT_1403053f0,uVar10,uVar1);

    local_40 = (float)FUN_140208370((ulonglong)*(byte *)(param_3 + 0x14) << 8,DAT_14037dea8,

                                    DAT_1403053f0,uVar10,uVar1);

    FUN_14015afd0(uVar5,param_1,2,lVar2,&local_48,3);

    local_40 = *(float *)(param_2 + 0x28);

    local_48 = (float)(int)*(short *)(param_3 + 0x17) * local_40;

    local_44 = (float)(int)*(short *)(param_3 + 0x1b) * local_40;

    local_40 = (float)(int)-((int)(short)((ushort)*(byte *)(param_3 + 0x1a) << 8) |

                            (uint)*(byte *)(param_3 + 0x19)) * local_40;

    FUN_14015afd0(uVar5,param_1,1,lVar2,&local_48,3);

  }

  uVar7 = 0x40;

  if ((ulonglong)(longlong)param_4 < 0x40) {

    uVar7 = (longlong)param_4;

  }

  FUN_1402f8e20(param_2 + 0x40,param_3,uVar7);

  return;

}




