// Address: 0x140280fb0
// Ghidra name: FUN_140280fb0
// ============ 0x140280fb0 FUN_140280fb0 (size=23) ============


void FUN_140280fb0(longlong param_1,longlong param_2,char *param_3,int param_4)



{

  longlong lVar1;

  undefined4 uVar2;

  undefined4 uVar3;

  undefined4 uVar4;

  undefined4 uVar5;

  undefined8 uVar6;

  undefined2 uVar7;

  ulonglong uVar8;

  int iVar9;

  undefined8 uVar10;

  float fVar11;

  undefined8 in_stack_ffffffffffffff88;

  undefined4 uVar12;

  float fStack_68;

  float fStack_64;

  float fStack_60;

  

  uVar12 = (undefined4)((ulonglong)in_stack_ffffffffffffff88 >> 0x20);

  if (((*param_3 == '\x04') && (param_3[1] == -2)) && (param_1 != 0)) {

    uVar6 = FUN_140149300();

    if (*(byte *)(param_2 + 0x49) != param_3[9]) {

      switch(param_3[9] & 0xf) {

      case 1:

        uVar10 = 1;

        break;

      case 2:

        uVar10 = 2;

        break;

      case 3:

        uVar10 = 3;

        break;

      case 4:

        uVar10 = 4;

        break;

      default:

        uVar10 = 0;

        break;

      case 6:

        uVar10 = 6;

        break;

      case 8:

        uVar10 = 8;

        break;

      case 9:

        uVar10 = 9;

        break;

      case 0xc:

        uVar10 = 0xc;

      }

      FUN_14015ae90(uVar6,param_1,0,uVar10);

      FUN_14015ad00(uVar6,param_1,0,(byte)param_3[9] >> 4 & 1);

      FUN_14015ad00(uVar6,param_1,1,(byte)param_3[9] >> 5 & 1);

      FUN_14015ad00(uVar6,param_1,4,(byte)param_3[9] >> 6 & 1);

      FUN_14015ad00(uVar6,param_1,2,(byte)param_3[9] >> 7);

    }

    if (*(byte *)(param_2 + 0x4a) != param_3[10]) {

      FUN_14015ad00(uVar6,param_1,3,param_3[10] & 1);

      FUN_14015ad00(uVar6,param_1,6,(byte)param_3[10] >> 1 & 1);

      FUN_14015ad00(uVar6,param_1,9,(byte)param_3[10] >> 2 & 1);

      FUN_14015ad00(uVar6,param_1,10,(byte)param_3[10] >> 3 & 1);

      FUN_14015ad00(uVar6,param_1,7,(byte)param_3[10] >> 6 & 1);

      FUN_14015ad00(uVar6,param_1,8,(byte)param_3[10] >> 7);

    }

    if (*(byte *)(param_2 + 0x47) != param_3[7]) {

      FUN_14015ad00(uVar6,param_1,0xb,(byte)param_3[7] >> 2 & 1);

      FUN_14015ad00(uVar6,param_1,0xc,(byte)param_3[7] >> 3 & 1);

      FUN_14015ad00(uVar6,param_1,0xd,(byte)param_3[7] >> 4 & 1);

      FUN_14015ad00(uVar6,param_1,0xe,(byte)param_3[7] >> 5 & 1);

      if (*(char *)(param_2 + 10) != '\0') {

        FUN_14015ad00(uVar6,param_1,0xf,param_3[7] & 1);

        FUN_14015ad00(uVar6,param_1,0x10,(byte)param_3[7] >> 1 & 1);

      }

    }

    if (*(byte *)(param_2 + 0x48) != param_3[8]) {

      FUN_14015ad00(uVar6,param_1,5,(byte)param_3[8] >> 3 & 1);

    }

    uVar3 = DAT_14037dea8;

    uVar2 = DAT_1403053f0;

    uVar7 = 0;

    if (param_3[0x11] == '\x7f') {

      iVar9 = 0;

    }

    else {

      fVar11 = (float)FUN_140208370();

      iVar9 = (int)fVar11;

    }

    FUN_14015aab0(uVar6,param_1,0,iVar9);

    if (param_3[0x13] == '\x7f') {

      iVar9 = 0;

    }

    else {

      fVar11 = (float)FUN_140208370();

      iVar9 = (int)fVar11;

    }

    FUN_14015aab0(uVar6,param_1,1,iVar9);

    if (param_3[0x15] == '\x7f') {

      iVar9 = 0;

    }

    else {

      fVar11 = (float)FUN_140208370();

      iVar9 = (int)fVar11;

    }

    FUN_14015aab0(uVar6,param_1,2,iVar9);

    if (param_3[0x16] != '\x7f') {

      fVar11 = (float)FUN_140208370();

      uVar7 = (undefined2)(int)fVar11;

    }

    FUN_14015aab0(uVar6,param_1,3,uVar7);

    FUN_14015aab0(uVar6,param_1,4,(ushort)(byte)param_3[0x17] * 0x101 + -0x8000);

    FUN_14015aab0(uVar6,param_1,5,(ushort)(byte)param_3[0x18] * 0x101 + -0x8000);

    uVar5 = DAT_140380110;

    uVar4 = DAT_140380108;

    if (*(char *)(param_2 + 0xf) != '\0') {

      lVar1 = *(longlong *)(param_2 + 0x18);

      *(longlong *)(param_2 + 0x18) = *(longlong *)(param_2 + 0x20) + lVar1;

      fStack_68 = (float)FUN_140208370((float)(int)*(short *)(param_3 + 0x1a) * DAT_14039ca80,uVar3,

                                       uVar2,uVar5,CONCAT44(uVar12,uVar4));

      fStack_64 = (float)FUN_140208370((float)(int)CONCAT11(param_3[0x14],param_3[0x12]) *

                                       DAT_14039ca80,uVar3,uVar2,uVar5,uVar4);

      fStack_60 = (float)FUN_140208370((float)(int)*(short *)(param_3 + 0x1d) * DAT_14039ca80,uVar3,

                                       uVar2,DAT_14038010c,DAT_140380100);

      FUN_14015afd0(uVar6,param_1,2,lVar1,&fStack_68,3);

      fStack_60 = *(float *)(param_2 + 0x28);

      fStack_68 = (float)(int)-((int)(short)((ushort)(byte)param_3[0xc] << 8) |

                               (uint)(byte)param_3[0xb]) * fStack_60;

      fStack_64 = (float)(int)*(short *)(param_3 + 0xf) * fStack_60;

      fStack_60 = (float)(int)*(short *)(param_3 + 0xd) * fStack_60;

      FUN_14015afd0(uVar6,param_1,1,lVar1,&fStack_68,3);

    }

    uVar8 = 0x40;

    if ((ulonglong)(longlong)param_4 < 0x40) {

      uVar8 = (longlong)param_4;

    }

    FUN_1402f8e20(param_2 + 0x40,param_3,uVar8);

    return;

  }

  return;

}




