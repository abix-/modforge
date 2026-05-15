// Address: 0x140271460
// Ghidra name: FUN_140271460
// ============ 0x140271460 FUN_140271460 (size=504) ============


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void FUN_140271460(longlong param_1)



{

  short *psVar1;

  longlong lVar2;

  char cVar3;

  double dVar4;

  double dVar5;

  double dVar6;

  

  lVar2 = *(longlong *)(param_1 + 0x70);

  cVar3 = FUN_140271660();

  if (cVar3 == '\0') {

    *(undefined4 *)(lVar2 + 0x2c) = 0x3f800000;

    *(undefined2 *)(lVar2 + 0x28) = 0;

    *(undefined2 *)(lVar2 + 0x30) = 0;

    *(undefined4 *)(lVar2 + 0x34) = 0x3f800000;

    *(undefined2 *)(lVar2 + 0x38) = 0;

    *(undefined4 *)(lVar2 + 0x3c) = 0x3f800000;

    *(undefined2 *)(lVar2 + 0x40) = 0;

    *(undefined4 *)(lVar2 + 0x44) = 0x3f800000;

    *(undefined2 *)(lVar2 + 0x48) = 0;

    *(undefined4 *)(lVar2 + 0x4c) = 0x3f800000;

    *(undefined2 *)(lVar2 + 0x50) = 0;

    *(undefined4 *)(lVar2 + 0x54) = 0x3f800000;

  }

  dVar6 = (((double)*(ushort *)(lVar2 + 0x6a) / (double)*(ushort *)(lVar2 + 0x6c)) * DAT_140333080)

          / _DAT_140333088;

  dVar4 = (double)*(float *)(lVar2 + 0x2c) * dVar6;

  if ((*(short *)(param_1 + 0x20) == 0x54c) && (*(short *)(param_1 + 0x22) == 0x5c5)) {

    dVar4 = dVar4 + dVar4;

  }

  *(float *)(lVar2 + 0x2c) = (float)dVar4;

  dVar4 = (double)*(float *)(lVar2 + 0x34) * dVar6;

  if ((*(short *)(param_1 + 0x20) == 0x54c) && (*(short *)(param_1 + 0x22) == 0x5c5)) {

    dVar4 = dVar4 + dVar4;

  }

  *(float *)(lVar2 + 0x34) = (float)dVar4;

  dVar4 = DAT_14037f270;

  dVar6 = (double)*(float *)(lVar2 + 0x3c) * dVar6;

  psVar1 = (short *)(param_1 + 0x20);

  if ((*psVar1 == 0x54c) && (*(short *)(param_1 + 0x22) == 0x5c5)) {

    dVar6 = dVar6 + dVar6;

  }

  *(float *)(lVar2 + 0x3c) = (float)dVar6;

  dVar5 = ((double)*(ushort *)(lVar2 + 0x6e) / (double)*(ushort *)(lVar2 + 0x70)) * _DAT_14037f268;

  dVar6 = (double)*(float *)(lVar2 + 0x44) * dVar5;

  if ((*psVar1 == 0x54c) && (*(short *)(param_1 + 0x22) == 0x5c5)) {

    dVar6 = dVar6 * dVar4;

  }

  *(float *)(lVar2 + 0x44) = (float)dVar6;

  dVar6 = (double)*(float *)(lVar2 + 0x4c) * dVar5;

  if ((*psVar1 == 0x54c) && (*(short *)(param_1 + 0x22) == 0x5c5)) {

    dVar6 = dVar6 * dVar4;

  }

  *(float *)(lVar2 + 0x4c) = (float)dVar6;

  dVar5 = (double)*(float *)(lVar2 + 0x54) * dVar5;

  if ((*(short *)(param_1 + 0x20) == 0x54c) && (*(short *)(param_1 + 0x22) == 0x5c5)) {

    dVar5 = dVar5 * dVar4;

  }

  *(float *)(lVar2 + 0x54) = (float)dVar5;

  return;

}




