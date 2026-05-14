// Address: 0x140270a20
// Ghidra name: FUN_140270a20
// ============ 0x140270a20 FUN_140270a20 (size=1804) ============


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void FUN_140270a20(undefined8 param_1,undefined8 param_2,longlong param_3,byte *param_4,int param_5)



{

  byte *pbVar1;

  byte *pbVar2;

  uint uVar3;

  short sVar4;

  undefined8 uVar5;

  byte bVar6;

  byte bVar7;

  uint uVar8;

  ulonglong uVar9;

  ulonglong uVar10;

  uint uVar11;

  undefined8 uVar12;

  undefined4 uVar13;

  undefined4 uVar14;

  float local_38;

  undefined8 local_34;

  

  uVar5 = FUN_140149300();

  uVar14 = DAT_14039ca44;

  if (((9 < param_5) && (*(char *)(param_3 + 0x25) != '\0')) && (*(char *)(param_3 + 0x20) != '\0'))

  {

    uVar13 = DAT_14039ca44;

    if ((char)param_4[0x22] < '\0') {

      uVar13 = 0;

    }

    FUN_14015b110(uVar5,param_1,0,0,-1 < (char)param_4[0x22],

                  (float)((param_4[0x24] & 0xf) << 8 | (uint)param_4[0x23]) * _DAT_14037f260,

                  (float)((uint)param_4[0x25] << 4 | (uint)(param_4[0x24] >> 4)) * _DAT_14037f264,

                  uVar13);

    if ((char)param_4[0x26] < '\0') {

      uVar14 = 0;

    }

    FUN_14015b110(uVar5,param_1,0,1,-1 < (char)param_4[0x26],

                  (float)((param_4[0x28] & 0xf) << 8 | (uint)param_4[0x27]) * _DAT_14037f260,

                  (float)((uint)param_4[0x29] << 4 | (uint)(param_4[0x28] >> 4)) * _DAT_14037f264,

                  uVar14);

  }

  bVar7 = param_4[4];

  if (*(byte *)(param_3 + 0x88) != bVar7) {

    FUN_14015ad00(uVar5,param_1,2,bVar7 >> 4 & 1);

    FUN_14015ad00(uVar5,param_1,0,bVar7 >> 5 & 1);

    FUN_14015ad00(uVar5,param_1,1,bVar7 >> 6 & 1);

    FUN_14015ad00(uVar5,param_1,3,bVar7 >> 7);

    switch(param_4[4] & 0xf) {

    case 0:

      uVar12 = 1;

      break;

    case 1:

      uVar12 = 3;

      break;

    case 2:

      uVar12 = 2;

      break;

    case 3:

      uVar12 = 6;

      break;

    case 4:

      uVar12 = 4;

      break;

    case 5:

      uVar12 = 0xc;

      break;

    case 6:

      uVar12 = 8;

      break;

    case 7:

      uVar12 = 9;

      break;

    default:

      uVar12 = 0;

    }

    FUN_14015ae90(uVar5,param_1,0,uVar12);

  }

  bVar7 = param_4[5];

  if (*(byte *)(param_3 + 0x89) != bVar7) {

    FUN_14015ad00(uVar5,param_1,9,bVar7 & 1);

    FUN_14015ad00(uVar5,param_1,10,bVar7 >> 1 & 1);

    FUN_14015ad00(uVar5,param_1,4,bVar7 >> 4 & 1);

    FUN_14015ad00(uVar5,param_1,6,bVar7 >> 5 & 1);

    FUN_14015ad00(uVar5,param_1,7,bVar7 >> 6 & 1);

    FUN_14015ad00(uVar5,param_1,8,bVar7 >> 7);

  }

  bVar7 = param_4[5];

  pbVar1 = param_4 + 7;

  if ((bVar7 & 0xc) != 0) {

    if (((bVar7 & 4) == 0) || (bVar6 = 0xff, *pbVar1 != 0)) {

      bVar6 = *pbVar1;

    }

    *pbVar1 = bVar6;

    pbVar2 = param_4 + 8;

    if (((bVar7 & 8) == 0) || (bVar7 = 0xff, *pbVar2 != 0)) {

      bVar7 = *pbVar2;

    }

    *pbVar2 = bVar7;

  }

  bVar7 = param_4[6];

  if (*(byte *)(param_3 + 0x8a) != bVar7) {

    FUN_14015ad00(uVar5,param_1,5,bVar7 & 1);

    FUN_14015ad00(uVar5,param_1,0xb,bVar7 >> 1 & 1);

  }

  FUN_14015aab0(uVar5,param_1,4,(ushort)*pbVar1 * 0x101 + -0x8000);

  FUN_14015aab0(uVar5,param_1,5,(ushort)param_4[8] * 0x101 + -0x8000);

  FUN_14015aab0(uVar5,param_1,0,(ushort)*param_4 * 0x101 + -0x8000);

  FUN_14015aab0(uVar5,param_1,1,(ushort)param_4[1] * 0x101 + -0x8000);

  FUN_14015aab0(uVar5,param_1,2,(ushort)param_4[2] * 0x101 + -0x8000);

  FUN_14015aab0(uVar5,param_1,3,(ushort)param_4[3] * 0x101 + -0x8000);

  if (param_5 < 10) goto LAB_140271017;

  if ((*(char *)(param_3 + 0x26) != '\0') && (*(char *)(param_3 + 0x20) != '\0')) {

    bVar7 = param_4[0x1d] & 0xf;

    if ((param_4[0x1d] & 0x10) == 0) {

      uVar8 = 1;

LAB_140270e8c:

      uVar3 = ((uint)bVar7 + (uint)bVar7 * 4) * 2 + 5;

      uVar11 = 100;

      if (uVar3 < 100) {

        uVar11 = uVar3;

      }

    }

    else {

      if (bVar7 < 0xb) {

        uVar8 = 3;

        goto LAB_140270e8c;

      }

      if (bVar7 == 0xb) {

        uVar11 = 100;

        uVar8 = 4;

      }

      else {

        uVar11 = 0;

        uVar8 = uVar11;

      }

    }

    FUN_14015af40(param_1,uVar8,uVar11);

  }

  if (*(char *)(param_3 + 0x24) != '\0') {

    sVar4 = *(short *)(param_4 + 9);

    *(longlong *)(param_3 + 0x78) =

         *(longlong *)(param_3 + 0x78) + (ulonglong)(ushort)(sVar4 - *(short *)(param_3 + 0x80));

    *(short *)(param_3 + 0x80) = sVar4;

    uVar10 = (ulonglong)(*(longlong *)(param_3 + 0x78) * 16000) / 3;

    uVar12 = FUN_1402709f0(param_3,0,*(undefined2 *)(param_4 + 0xc));

    local_38 = (float)uVar12;

    uVar12 = FUN_1402709f0(uVar12,1,*(undefined2 *)(param_4 + 0xe));

    uVar9 = 2;

    local_34 = CONCAT44(local_34._4_4_,(int)uVar12);

    uVar14 = FUN_1402709f0(uVar12,2,*(undefined2 *)(param_4 + 0x10));

    local_34._4_4_ = uVar14;

    FUN_14015afd0(uVar5,param_1,uVar9 & 0xffffffff,uVar10,&local_38,3);

    uVar12 = FUN_1402709f0(param_3,3,*(undefined2 *)(param_4 + 0x12));

    local_38 = (float)uVar12;

    uVar12 = FUN_1402709f0(uVar12,4,*(undefined2 *)(param_4 + 0x14));

    local_34 = CONCAT44(local_34._4_4_,(int)uVar12);

    uVar14 = FUN_1402709f0(uVar12,5,*(undefined2 *)(param_4 + 0x16));

    local_34 = CONCAT44(uVar14,(undefined4)local_34);

    FUN_14015afd0(uVar5,param_1,1,uVar10,&local_38,3);

  }

LAB_140271017:

  if (*(char *)(param_3 + 0x18) != '\0') {

    FUN_14015aab0(uVar5,param_1,2,(ushort)param_4[0x2b] * 0x101 + -0x8000);

  }

  if ((*(char *)(param_3 + 0x1a) != '\0') && (param_4[0x2a] < 5)) {

    FUN_14015aab0(uVar5,param_1,3,*(undefined2 *)(&DAT_14037f228 + (ulonglong)param_4[0x2a] * 2));

  }

  if (*(char *)(param_3 + 0x19) != '\0') {

    local_34 = 0;

    local_38 = ((float)param_4[0x2c] / DAT_14030a2d0) * _DAT_1403553cc;

    FUN_14015afd0(uVar5,param_1,1,uVar5,&local_38,3);

    FUN_14015ad00(uVar5,param_1,10,0xf0 < param_4[0x2c]);

  }

  uVar5 = *(undefined8 *)(param_4 + 8);

  *(undefined8 *)(param_3 + 0x84) = *(undefined8 *)param_4;

  *(undefined8 *)(param_3 + 0x8c) = uVar5;

  uVar5 = *(undefined8 *)(param_4 + 0x18);

  *(undefined8 *)(param_3 + 0x94) = *(undefined8 *)(param_4 + 0x10);

  *(undefined8 *)(param_3 + 0x9c) = uVar5;

  uVar5 = *(undefined8 *)(param_4 + 0x28);

  *(undefined8 *)(param_3 + 0xa4) = *(undefined8 *)(param_4 + 0x20);

  *(undefined8 *)(param_3 + 0xac) = uVar5;

  *(undefined4 *)(param_3 + 0xb4) = *(undefined4 *)(param_4 + 0x30);

  *(undefined2 *)(param_3 + 0xb8) = *(undefined2 *)(param_4 + 0x34);

  return;

}




