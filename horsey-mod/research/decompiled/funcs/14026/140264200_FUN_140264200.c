// Address: 0x140264200
// Ghidra name: FUN_140264200
// ============ 0x140264200 FUN_140264200 (size=1259) ============


void FUN_140264200(undefined8 param_1,int *param_2,char *param_3,int param_4)



{

  undefined4 uVar1;

  byte bVar2;

  undefined1 uVar3;

  undefined8 uVar4;

  longlong lVar5;

  int *piVar6;

  byte *pbVar7;

  byte *pbVar8;

  ulonglong uVar9;

  int *piVar10;

  float fVar11;

  undefined4 uVar12;

  

  uVar4 = FUN_140149300();

  uVar1 = DAT_1403053f0;

  if ((0x24 < param_4) && (*param_3 == '!')) {

    piVar6 = param_2 + 0x12;

    pbVar7 = (byte *)(param_3 + 1);

    pbVar8 = (byte *)((longlong)param_2 + 0x32);

    uVar9 = 0;

    piVar10 = param_2;

    do {

      piVar10 = piVar10 + 1;

      bVar2 = *pbVar7 >> 5 & 1;

      *(byte *)(piVar6 + -0xd) = bVar2;

      if (((*pbVar7 & 4) == 0) || (bVar2 != 0)) {

        uVar3 = 0;

      }

      else {

        uVar3 = 1;

      }

      *(undefined1 *)piVar6 = uVar3;

      if ((*pbVar7 & 0x30) == 0) {

        if (*piVar10 != 0) {

          FUN_140208230(param_1);

          *piVar10 = 0;

        }

      }

      else {

        if (*piVar10 == 0) {

          FUN_1402646f0(param_2,uVar9);

          FUN_140208110(param_1,piVar10);

        }

        lVar5 = FUN_1401581c0(*piVar10);

        if (lVar5 != 0) {

          FUN_14015ad00(uVar4,lVar5,0,pbVar7[1] & 1);

          FUN_14015ad00(uVar4,lVar5,1,pbVar7[1] >> 1 & 1);

          FUN_14015ad00(uVar4,lVar5,2,pbVar7[1] >> 2 & 1);

          FUN_14015ad00(uVar4,lVar5,3,pbVar7[1] >> 3 & 1);

          FUN_14015ad00(uVar4,lVar5,4,pbVar7[1] >> 4 & 1);

          FUN_14015ad00(uVar4,lVar5,5,pbVar7[1] >> 5 & 1);

          FUN_14015ad00(uVar4,lVar5,6,pbVar7[1] >> 6 & 1);

          FUN_14015ad00(uVar4,lVar5,7,pbVar7[1] >> 7);

          FUN_14015ad00(uVar4,lVar5,8,pbVar7[2] & 1);

          FUN_14015ad00(uVar4,lVar5,9,pbVar7[2] >> 1 & 1);

          FUN_14015ad00(uVar4,lVar5,10,pbVar7[2] >> 2 & 1);

          FUN_14015ad00(uVar4,lVar5,0xb,pbVar7[2] >> 3 & 1);

          if (pbVar7[3] < *(byte *)((longlong)param_2 + uVar9 * 6 + 0x18)) {

            *(byte *)((longlong)param_2 + uVar9 * 6 + 0x18) = pbVar7[3];

          }

          if (*(byte *)((longlong)param_2 + uVar9 * 6 + 0x30) < pbVar7[3]) {

            *(byte *)((longlong)param_2 + uVar9 * 6 + 0x30) = pbVar7[3];

          }

          uVar12 = uVar1;

          fVar11 = (float)FUN_140208370();

          FUN_14015aab0(uVar4,lVar5,0,(int)fVar11,uVar12);

          if (pbVar7[4] < *(byte *)((longlong)param_2 + uVar9 * 6 + 0x19)) {

            *(byte *)((longlong)param_2 + uVar9 * 6 + 0x19) = pbVar7[4];

          }

          if (*(byte *)((longlong)param_2 + uVar9 * 6 + 0x31) < pbVar7[4]) {

            *(byte *)((longlong)param_2 + uVar9 * 6 + 0x31) = pbVar7[4];

          }

          uVar12 = uVar1;

          fVar11 = (float)FUN_140208370();

          FUN_14015aab0(uVar4,lVar5,1,(int)fVar11,uVar12);

          if (pbVar7[5] < pbVar8[-0x18]) {

            pbVar8[-0x18] = pbVar7[5];

          }

          if (*pbVar8 < pbVar7[5]) {

            *pbVar8 = pbVar7[5];

          }

          uVar12 = uVar1;

          fVar11 = (float)FUN_140208370();

          FUN_14015aab0(uVar4,lVar5,2,(int)fVar11,uVar12);

          if (pbVar7[6] < pbVar8[-0x17]) {

            pbVar8[-0x17] = pbVar7[6];

          }

          if (pbVar8[1] < pbVar7[6]) {

            pbVar8[1] = pbVar7[6];

          }

          uVar12 = uVar1;

          fVar11 = (float)FUN_140208370();

          FUN_14015aab0(uVar4,lVar5,3,(int)fVar11,uVar12);

          if (pbVar7[7] < pbVar8[-0x16]) {

            pbVar8[-0x16] = pbVar7[7];

          }

          if (pbVar8[2] < pbVar7[7]) {

            pbVar8[2] = pbVar7[7];

          }

          uVar12 = uVar1;

          fVar11 = (float)FUN_140208370();

          FUN_14015aab0(uVar4,lVar5,4,(int)fVar11,uVar12);

          if (pbVar7[8] < pbVar8[-0x15]) {

            pbVar8[-0x15] = pbVar7[8];

          }

          if (pbVar8[3] < pbVar7[8]) {

            pbVar8[3] = pbVar7[8];

          }

          uVar12 = uVar1;

          fVar11 = (float)FUN_140208370();

          FUN_14015aab0(uVar4,lVar5,5,(int)fVar11,uVar12);

        }

      }

      bVar2 = (char)uVar9 + 1;

      uVar9 = (ulonglong)bVar2;

      piVar6 = (int *)((longlong)piVar6 + 1);

      pbVar8 = pbVar8 + 6;

      pbVar7 = pbVar7 + 9;

    } while (bVar2 < 4);

  }

  return;

}




