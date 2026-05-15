// Address: 0x140273ce0
// Ghidra name: FUN_140273ce0
// ============ 0x140273ce0 FUN_140273ce0 (size=1065) ============


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void FUN_140273ce0(longlong param_1)



{

  longlong lVar1;

  short sVar2;

  short sVar3;

  short sVar4;

  int iVar5;

  float fVar6;

  float fVar7;

  float fVar8;

  undefined1 local_a8;

  short local_a7;

  undefined2 local_a5;

  undefined1 local_a3;

  undefined1 local_a2;

  short local_a1;

  undefined1 local_9f;

  undefined1 local_9e;

  undefined1 local_9d;

  undefined1 local_9c;

  undefined1 local_9b;

  undefined1 local_9a;

  short local_99;

  undefined1 local_97;

  undefined1 local_96;

  byte local_95;

  byte local_94;

  byte local_93;

  byte local_92;

  undefined1 local_91;

  undefined1 local_90;

  undefined1 local_8f;

  undefined1 local_8e;

  undefined1 local_8d;

  undefined1 local_8c;

  undefined1 local_8b;

  undefined1 local_8a;

  short local_89;

  undefined1 local_87;

  undefined1 local_86;

  

  lVar1 = *(longlong *)(param_1 + 0x70);

  iVar5 = FUN_14026ffd0(*(undefined8 *)(param_1 + 0x80),5,&local_a8,0x40);

  if (0x22 < iVar5) {

    fVar8 = (float)(int)(((int)(short)((ushort)local_94 << 8) | (uint)local_95) +

                        ((int)(short)((ushort)local_92 << 8) | (uint)local_93)) * DAT_1403102f4;

    *(undefined1 *)(lVar1 + 0x26) = 1;

    *(short *)(lVar1 + 0x28) = local_a7;

    *(undefined2 *)(lVar1 + 0x30) = local_a5;

    *(ushort *)(lVar1 + 0x38) = CONCAT11(local_a2,local_a3);

    sVar2 = CONCAT11(local_90,local_91) - CONCAT11(local_8e,local_8f);

    *(float *)(lVar1 + 0x2c) = fVar8 / (float)((int)local_a1 - (int)CONCAT11(local_9e,local_9f));

    *(float *)(lVar1 + 0x34) =

         fVar8 / (float)((int)CONCAT11(local_9c,local_9d) - (int)CONCAT11(local_9a,local_9b));

    *(short *)(lVar1 + 0x40) = CONCAT11(local_90,local_91) - sVar2 / 2;

    sVar3 = CONCAT11(local_8c,local_8d) - CONCAT11(local_8a,local_8b);

    *(float *)(lVar1 + 0x3c) = fVar8 / (float)((int)local_99 - (int)CONCAT11(local_96,local_97));

    fVar8 = _DAT_14037f324;

    *(short *)(lVar1 + 0x48) = CONCAT11(local_8c,local_8d) - sVar3 / 2;

    sVar4 = local_89 - CONCAT11(local_86,local_87);

    *(float *)(lVar1 + 0x44) = fVar8 / (float)(int)sVar2;

    *(short *)(lVar1 + 0x50) = local_89 - sVar4 / 2;

    *(float *)(lVar1 + 0x4c) = fVar8 / (float)(int)sVar3;

    *(float *)(lVar1 + 0x54) = fVar8 / (float)(int)sVar4;

    iVar5 = FUN_140190050((int)local_a7);

    fVar7 = DAT_14039ca44;

    fVar8 = DAT_14039ca34;

    if ((0x400 < iVar5) ||

       (fVar6 = (float)FUN_140190250(DAT_14039ca44 - *(float *)(lVar1 + 0x2c) * DAT_140304b20),

       fVar8 < fVar6)) {

      *(undefined1 *)(lVar1 + 0x26) = 0;

    }

    iVar5 = FUN_140190050((int)*(short *)(lVar1 + 0x30));

    if ((0x400 < iVar5) ||

       (fVar6 = (float)FUN_140190250(fVar7 - *(float *)(lVar1 + 0x34) * DAT_140304b20),

       fVar8 < fVar6)) {

      *(undefined1 *)(lVar1 + 0x26) = 0;

    }

    iVar5 = FUN_140190050((int)*(short *)(lVar1 + 0x38));

    if ((0x400 < iVar5) ||

       (fVar6 = (float)FUN_140190250(fVar7 - *(float *)(lVar1 + 0x3c) * DAT_140304b20),

       fVar8 < fVar6)) {

      *(undefined1 *)(lVar1 + 0x26) = 0;

    }

    iVar5 = FUN_140190050((int)*(short *)(lVar1 + 0x40));

    if ((0x400 < iVar5) ||

       (fVar6 = (float)FUN_140190250(fVar7 - *(float *)(lVar1 + 0x44)), fVar8 < fVar6)) {

      *(undefined1 *)(lVar1 + 0x26) = 0;

    }

    iVar5 = FUN_140190050((int)*(short *)(lVar1 + 0x48));

    if ((0x400 < iVar5) ||

       (fVar7 = (float)FUN_140190250(fVar7 - *(float *)(lVar1 + 0x4c)), fVar8 < fVar7)) {

      *(undefined1 *)(lVar1 + 0x26) = 0;

    }

    iVar5 = FUN_140190050((int)*(short *)(lVar1 + 0x50));

    if ((0x400 < iVar5) || (fVar7 = (float)FUN_140190250(), fVar8 < fVar7)) {

      *(undefined1 *)(lVar1 + 0x26) = 0;

    }

  }

  return;

}




