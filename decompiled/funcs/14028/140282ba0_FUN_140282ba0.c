// Address: 0x140282ba0
// Ghidra name: FUN_140282ba0
// ============ 0x140282ba0 FUN_140282ba0 (size=1418) ============


void FUN_140282ba0(undefined8 param_1,longlong param_2,longlong param_3,int param_4)



{

  float fVar1;

  byte bVar2;

  int iVar3;

  short sVar4;

  short sVar5;

  int iVar6;

  ushort uVar7;

  float fVar8;

  uint uVar9;

  undefined8 uVar10;

  byte bVar11;

  byte bVar12;

  char cVar13;

  undefined4 uVar14;

  byte bVar15;

  ulonglong uVar16;

  longlong lVar17;

  undefined8 uVar18;

  byte bVar19;

  byte *pbVar20;

  undefined8 local_68;

  float local_60;

  

  uVar10 = FUN_140149300();

  pbVar20 = (byte *)(param_2 + 0x6e);

  bVar15 = 0;

  local_68 = 0;

  bVar19 = 0;

  local_60 = 0.0;

  do {

    bVar12 = 0;

    do {

      bVar11 = '\x01' << (bVar12 & 0x1f);

      if ((*pbVar20 & bVar11) != 0) {

        bVar2 = *(byte *)((ulonglong)(byte)(bVar19 + 3) + param_3);

        if ((bVar15 < 0x1a) && (*(byte *)((ulonglong)(byte)(bVar19 + 3) + 0x2c + param_2) != bVar2))

        {

          FUN_14015ad00(uVar10,param_1,bVar15,(bVar11 & bVar2) != 0);

        }

        bVar15 = bVar15 + 1;

      }

      bVar12 = bVar12 + 1;

    } while (bVar12 < 8);

    bVar19 = bVar19 + 1;

    pbVar20 = pbVar20 + 1;

  } while (bVar19 < 4);

  if (*(char *)(param_2 + 0x17) != '\0') {

    bVar15 = *(byte *)(param_3 + 3);

    bVar12 = bVar15 >> 4 & 1;

    bVar19 = bVar12 | 4;

    if ((bVar15 & 0x20) == 0) {

      bVar19 = bVar12;

    }

    bVar12 = bVar19 | 8;

    if ((bVar15 & 0x40) == 0) {

      bVar12 = bVar19;

    }

    bVar19 = bVar12 | 2;

    if (-1 < (char)bVar15) {

      bVar19 = bVar12;

    }

    FUN_14015ae90(uVar10,param_1,0,bVar19);

  }

  cVar13 = '\0';

  if (*(char *)(param_2 + 0x13) != '\0') {

    FUN_14015aab0(uVar10,param_1,0,*(undefined2 *)(param_3 + 7));

    FUN_14015aab0(uVar10,param_1,1,*(undefined2 *)(param_3 + 9));

    cVar13 = '\x02';

  }

  if (*(char *)(param_2 + 0x14) != '\0') {

    FUN_14015aab0(uVar10,param_1,cVar13,*(undefined2 *)(param_3 + 0xb));

    FUN_14015aab0(uVar10,param_1,cVar13 + '\x01',*(undefined2 *)(param_3 + 0xd));

    cVar13 = cVar13 + '\x02';

  }

  if (*(char *)(param_2 + 0x15) != '\0') {

    FUN_14015aab0(uVar10,param_1,cVar13,*(undefined2 *)(param_3 + 0xf));

    cVar13 = cVar13 + '\x01';

  }

  if (*(char *)(param_2 + 0x16) != '\0') {

    FUN_14015aab0(uVar10,param_1,cVar13,*(undefined2 *)(param_3 + 0x11));

  }

  cVar13 = *(char *)(param_3 + 1);

  if ((*(char *)(param_2 + 0x2d) != cVar13) || (*(char *)(param_2 + 0x2e) != *(char *)(param_3 + 2))

     ) {

    if (cVar13 == '\x01') {

      FUN_14015af40(param_1,2,0);

    }

    else if (cVar13 == '\x02') {

      FUN_14015af40(param_1,3);

    }

    else if (cVar13 == '\x03') {

      FUN_14015af40(param_1,4,100);

    }

    else if (cVar13 == '\x04') {

      FUN_14015af40(param_1,1);

    }

  }

  uVar9 = DAT_14039cac0;

  iVar6 = *(int *)(param_3 + 0x13);

  uVar14 = 1;

  if (*(char *)(param_2 + 0xc) != '\0') {

    iVar3 = *(int *)(param_2 + 0x74);

    *(int *)(param_2 + 0x74) = iVar6;

    lVar17 = (ulonglong)(uint)(iVar6 - iVar3) * 1000 + *(longlong *)(param_2 + 0x78);

    *(longlong *)(param_2 + 0x78) = lVar17;

    if (*(char *)(param_2 + 0x12) != '\0') {

      fVar1 = *(float *)(param_2 + 0x28);

      local_60 = (float)((uint)(float)(int)*(short *)(param_3 + 0x1f) ^ uVar9) * fVar1;

      local_68 = CONCAT44((float)(int)*(short *)(param_3 + 0x21) * fVar1,

                          (float)((uint)(float)(int)*(short *)(param_3 + 0x1d) ^ uVar9) * fVar1);

      FUN_14015afd0(uVar10,param_1,2,lVar17,&local_68,3);

    }

    if (*(char *)(param_2 + 0x11) != '\0') {

      fVar1 = *(float *)(param_2 + 0x24);

      local_60 = (float)((uint)(float)(int)*(short *)(param_3 + 0x19) ^ uVar9) * fVar1;

      local_68 = CONCAT44((float)(int)*(short *)(param_3 + 0x1b) * fVar1,

                          (float)((uint)(float)(int)*(short *)(param_3 + 0x17) ^ uVar9) * fVar1);

      FUN_14015afd0(uVar10,param_1,1,*(undefined8 *)(param_2 + 0x78),&local_68,3);

    }

  }

  fVar8 = DAT_14039ca34;

  fVar1 = DAT_1403053bc;

  if ((*(char *)(param_2 + 0x18) != '\0') && (*(char *)(param_2 + 0x1a) != '\0')) {

    sVar4 = *(short *)(param_3 + 0x29);

    sVar5 = *(short *)(param_3 + 0x2b);

    uVar7 = *(ushort *)(param_3 + 0x2d);

    FUN_14015b110(uVar10,param_1,0,0,*(ushort *)(param_3 + 0x27) != 0,

                  (float)(int)*(short *)(param_3 + 0x23) * DAT_1403053bc + DAT_14039ca34,

                  (float)(int)*(short *)(param_3 + 0x25) * DAT_1403053bc + DAT_14039ca34,

                  (float)*(ushort *)(param_3 + 0x27) * DAT_14037f67c);

    if (*(byte *)(param_2 + 0x1a) < 2) {

      if (*(byte *)(param_2 + 0x1b) < 2) goto LAB_1402830ed;

      uVar18 = 1;

      uVar14 = 0;

    }

    else {

      uVar18 = 0;

    }

    FUN_14015b110(uVar10,param_1,uVar14,uVar18,uVar7 != 0,(float)(int)sVar4 * fVar1 + fVar8,

                  (float)(int)sVar5 * fVar1 + fVar8,(float)uVar7 * DAT_14037f67c);

  }

LAB_1402830ed:

  uVar16 = 0x40;

  if ((ulonglong)(longlong)param_4 < 0x40) {

    uVar16 = (longlong)param_4;

  }

  FUN_1402f8e20(param_2 + 0x2c,param_3,uVar16);

  return;

}




