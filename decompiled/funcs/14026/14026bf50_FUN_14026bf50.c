// Address: 0x14026bf50
// Ghidra name: FUN_14026bf50
// ============ 0x14026bf50 FUN_14026bf50 (size=1000) ============


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



undefined8 FUN_14026bf50(longlong param_1)



{

  short sVar1;

  short sVar2;

  short sVar3;

  short sVar4;

  short sVar5;

  short sVar6;

  longlong lVar7;

  char cVar8;

  short sVar9;

  short sVar10;

  short sVar11;

  short sVar12;

  short sVar13;

  short sVar14;

  float fVar15;

  float fVar16;

  float fVar17;

  float fVar18;

  float fVar19;

  float fVar20;

  undefined4 local_80;

  undefined1 local_7c;

  longlong local_78 [8];

  

  local_78[0] = 0;

  local_80 = 0x6020;

  local_7c = 0x18;

  cVar8 = FUN_14026d5b0(param_1,0x10,&local_80,5,local_78);

  lVar7 = local_78[0];

  fVar15 = DAT_14037ef9c;

  fVar16 = DAT_14037ef98;

  fVar17 = DAT_14037ef98;

  fVar18 = DAT_14037ef98;

  fVar19 = DAT_14037ef9c;

  fVar20 = DAT_14037ef9c;

  if (cVar8 != '\0') {

    sVar10 = *(short *)(local_78[0] + 0x13);

    sVar9 = *(short *)(local_78[0] + 0x15);

    sVar13 = *(short *)(local_78[0] + 0x17);

    sVar2 = *(short *)(local_78[0] + 0x19);

    sVar3 = *(short *)(local_78[0] + 0x1b);

    sVar4 = *(short *)(local_78[0] + 0x1d);

    sVar14 = *(short *)(local_78[0] + 0x1f);

    sVar11 = *(short *)(local_78[0] + 0x21);

    sVar12 = *(short *)(local_78[0] + 0x23);

    sVar1 = *(short *)(local_78[0] + 0x25);

    sVar5 = *(short *)(local_78[0] + 0x27);

    sVar6 = *(short *)(local_78[0] + 0x29);

    local_80 = 0x8026;

    local_7c = 0x14;

    cVar8 = FUN_14026d5b0(param_1,0x10,&local_80,5,local_78);

    if ((cVar8 != '\0') && (*(short *)(lVar7 + 0x13) == -0x5e4e)) {

      sVar10 = *(short *)(local_78[0] + 0x15);

      sVar9 = *(short *)(local_78[0] + 0x17);

      sVar13 = *(short *)(local_78[0] + 0x19);

      sVar14 = *(short *)(local_78[0] + 0x21);

      sVar11 = *(short *)(local_78[0] + 0x23);

      sVar12 = *(short *)(local_78[0] + 0x25);

    }

    fVar15 = (DAT_140303390 / ((float)(int)sVar4 - (float)(int)sVar13)) * _DAT_1403553cc;

    fVar16 = ((DAT_14037efa4 / ((float)(int)sVar6 - (float)(int)sVar12)) * DAT_14039ca50) /

             DAT_140304c34;

    fVar17 = ((DAT_14037efa4 / ((float)(int)sVar1 - (float)(int)sVar14)) * DAT_14039ca50) /

             DAT_140304c34;

    fVar18 = ((DAT_14037efa4 / ((float)(int)sVar5 - (float)(int)sVar11)) * DAT_14039ca50) /

             DAT_140304c34;

    fVar19 = (DAT_140303390 / ((float)(int)sVar2 - (float)(int)sVar10)) * _DAT_1403553cc;

    fVar20 = (DAT_140303390 / ((float)(int)sVar3 - (float)(int)sVar9)) * _DAT_1403553cc;

  }

  *(float *)(param_1 + 0x158) = fVar19;

  *(float *)(param_1 + 0x15c) = fVar20;

  *(float *)(param_1 + 0x160) = fVar15;

  *(float *)(param_1 + 0x164) = fVar17;

  *(float *)(param_1 + 0x168) = fVar18;

  *(float *)(param_1 + 0x16c) = fVar16;

  return 1;

}




