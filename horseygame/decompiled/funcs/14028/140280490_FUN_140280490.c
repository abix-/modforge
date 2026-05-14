// Address: 0x140280490
// Ghidra name: FUN_140280490
// ============ 0x140280490 FUN_140280490 (size=1475) ============


void FUN_140280490(undefined8 param_1,longlong param_2,char *param_3,int param_4)



{

  char cVar1;

  longlong lVar2;

  byte bVar3;

  uint uVar4;

  undefined8 uVar5;

  byte bVar6;

  byte bVar7;

  ulonglong uVar8;

  int iVar9;

  undefined8 uVar10;

  float fVar11;

  float local_78;

  float local_74;

  float local_70;

  

  uVar5 = FUN_140149300();

  cVar1 = *param_3;

  if (((cVar1 == '\x01') || (cVar1 == '\x03')) || (cVar1 == '\x04')) {

    if (*(char *)(param_2 + 0x1d) != param_3[1]) {

      switch(param_3[1]) {

      case '\0':

        uVar10 = 1;

        break;

      case '\x01':

        uVar10 = 3;

        break;

      case '\x02':

        uVar10 = 2;

        break;

      case '\x03':

        uVar10 = 6;

        break;

      case '\x04':

        uVar10 = 4;

        break;

      case '\x05':

        uVar10 = 0xc;

        break;

      case '\x06':

        uVar10 = 8;

        break;

      case '\a':

        uVar10 = 9;

        break;

      default:

        uVar10 = 0;

      }

      FUN_14015ae90(uVar5,param_1,0,uVar10);

    }

    if (*(byte *)(param_2 + 0x24) != param_3[8]) {

      FUN_14015ad00(uVar5,param_1,0,param_3[8] & 1);

      FUN_14015ad00(uVar5,param_1,1,(byte)param_3[8] >> 1 & 1);

      FUN_14015ad00(uVar5,param_1,2,(byte)param_3[8] >> 3 & 1);

      FUN_14015ad00(uVar5,param_1,3,(byte)param_3[8] >> 4 & 1);

      FUN_14015ad00(uVar5,param_1,9,(byte)param_3[8] >> 6 & 1);

      FUN_14015ad00(uVar5,param_1,10,(byte)param_3[8] >> 7);

      FUN_14015ad00(uVar5,param_1,0xd,(byte)param_3[8] >> 5 & 1);

      FUN_14015ad00(uVar5,param_1,0xe,(byte)param_3[8] >> 2 & 1);

    }

    if (*(byte *)(param_2 + 0x25) != param_3[9]) {

      FUN_14015ad00(uVar5,param_1,5,(byte)param_3[9] >> 4 & 1);

      FUN_14015ad00(uVar5,param_1,4,(byte)param_3[9] >> 2 & 1);

      FUN_14015ad00(uVar5,param_1,6,(byte)param_3[9] >> 3 & 1);

      FUN_14015ad00(uVar5,param_1,7,(byte)param_3[9] >> 5 & 1);

      FUN_14015ad00(uVar5,param_1,8,(byte)param_3[9] >> 6 & 1);

    }

    if ((10 < param_4) && (*(byte *)(param_2 + 0x26) != param_3[10])) {

      FUN_14015ad00(uVar5,param_1,0xb,param_3[10] & 1);

      FUN_14015ad00(uVar5,param_1,0xc,(byte)param_3[10] >> 1 & 1);

    }

    bVar7 = 0;

    if (param_3[2] == '\x7f') {

      iVar9 = 0;

    }

    else {

      fVar11 = (float)FUN_140208370();

      iVar9 = (int)fVar11;

    }

    FUN_14015aab0(uVar5,param_1,0,iVar9);

    if (param_3[3] == '\x7f') {

      iVar9 = 0;

    }

    else {

      fVar11 = (float)FUN_140208370();

      iVar9 = (int)fVar11;

    }

    FUN_14015aab0(uVar5,param_1,1,iVar9);

    if (param_3[4] == '\x7f') {

      iVar9 = 0;

    }

    else {

      fVar11 = (float)FUN_140208370();

      iVar9 = (int)fVar11;

    }

    FUN_14015aab0(uVar5,param_1,2,iVar9);

    if (param_3[5] == '\x7f') {

      iVar9 = 0;

    }

    else {

      fVar11 = (float)FUN_140208370();

      iVar9 = (int)fVar11;

    }

    FUN_14015aab0(uVar5,param_1,3,iVar9);

    FUN_14015aab0(uVar5,param_1,4,(ushort)(byte)param_3[7] * 0x101 + -0x8000);

    FUN_14015aab0(uVar5,param_1,5,(ushort)(byte)param_3[6] * 0x101 + -0x8000);

    if (*(char *)(param_2 + 8) != '\0') {

      bVar6 = param_3[0xe] & 0x7f;

      bVar3 = (byte)param_3[0xe] >> 7;

      if (bVar6 == 100) {

        bVar3 = 2;

      }

      if (bVar3 == 0) {

        bVar7 = bVar6;

        bVar6 = 1;

      }

      else if (bVar3 == 1) {

        bVar7 = bVar6;

        bVar6 = 3;

      }

      else {

        bVar6 = bVar7;

        if (bVar3 == 2) {

          bVar7 = 100;

          bVar6 = 4;

        }

      }

      FUN_14015af40(param_1,bVar6,bVar7);

    }

    if (*(char *)(param_2 + 1) != '\0') {

      if (*(char *)(param_2 + 9) != '\0') {

        iVar9 = *(int *)(param_3 + 0x1b);

        if ((*(int *)(param_2 + 0x70) != 0) &&

           (uVar4 = iVar9 - *(int *)(param_2 + 0x70), uVar4 < 100000)) {

          *(ulonglong *)(param_2 + 0x68) = (ulonglong)uVar4 * 1000;

        }

        *(int *)(param_2 + 0x70) = iVar9;

      }

      lVar2 = *(longlong *)(param_2 + 0x60);

      local_70 = *(float *)(param_2 + 0x18);

      *(longlong *)(param_2 + 0x60) = *(longlong *)(param_2 + 0x68) + lVar2;

      local_78 = (float)-(int)*(short *)(param_3 + 0x17) * local_70;

      local_74 = (float)(int)*(short *)(param_3 + 0x19) * local_70;

      local_70 = (float)-(int)*(short *)(param_3 + 0x15) * local_70;

      FUN_14015afd0(uVar5,param_1,2,lVar2,&local_78,3);

      local_70 = *(float *)(param_2 + 0x14);

      local_78 = (float)-(int)*(short *)(param_3 + 0x11) * local_70;

      local_74 = (float)(int)*(short *)(param_3 + 0x13) * local_70;

      local_70 = (float)-(int)*(short *)(param_3 + 0xf) * local_70;

      FUN_14015afd0(uVar5,param_1,1,lVar2,&local_78,3);

    }

    uVar8 = 0x40;

    if ((ulonglong)(longlong)param_4 < 0x40) {

      uVar8 = (longlong)param_4;

    }

    FUN_1402f8e20(param_2 + 0x1c,param_3,uVar8);

  }

  return;

}




