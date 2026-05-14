// Address: 0x140283130
// Ghidra name: FUN_140283130
// ============ 0x140283130 FUN_140283130 (size=606) ============


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void FUN_140283130(longlong param_1,undefined2 *param_2)



{

  longlong lVar1;

  float fVar2;

  uint uVar3;

  byte bVar4;

  byte bVar5;

  byte *pbVar6;

  longlong lVar7;

  undefined1 local_28 [32];

  

  lVar1 = *(longlong *)(param_1 + 0x70);

  *(undefined2 *)(lVar1 + 8) = *param_2;

  *(byte *)(lVar1 + 0x10) = *(byte *)(param_2 + 1) & 1;

  *(byte *)(lVar1 + 0xe) = *(byte *)(param_2 + 1) >> 1 & 1;

  *(byte *)(lVar1 + 0x11) = *(byte *)(param_2 + 1) >> 2 & 1;

  *(byte *)(lVar1 + 0x12) = *(byte *)(param_2 + 1) >> 3 & 1;

  *(byte *)(lVar1 + 0x13) = *(byte *)(param_2 + 1) >> 4 & 1;

  *(byte *)(lVar1 + 0x14) = *(byte *)(param_2 + 1) >> 5 & 1;

  *(byte *)(lVar1 + 0x15) = *(byte *)(param_2 + 1) >> 6 & 1;

  *(byte *)(lVar1 + 0x16) = *(byte *)(param_2 + 1) >> 7;

  *(byte *)(lVar1 + 0x18) = *(byte *)((longlong)param_2 + 3) & 1;

  *(byte *)(lVar1 + 0xf) = *(byte *)((longlong)param_2 + 3) >> 1 & 1;

  *(byte *)(lVar1 + 0x19) = *(byte *)((longlong)param_2 + 3) >> 2 & 1;

  uVar3 = (uint)*(byte *)(param_2 + 2);

  if (0xc < *(byte *)(param_2 + 2)) {

    uVar3 = 0xc;

  }

  *(uint *)(param_1 + 0x5c) = uVar3;

  *(undefined1 *)(param_1 + 0x3f) = *(undefined1 *)((longlong)param_2 + 5);

  *(byte *)(lVar1 + 0x1e) = *(byte *)((longlong)param_2 + 5) & 0x1f;

  *(undefined2 *)(lVar1 + 0x1c) = param_2[3];

  *(undefined2 *)(lVar1 + 0x20) = param_2[4];

  *(undefined2 *)(lVar1 + 0x22) = param_2[5];

  *(undefined1 *)(lVar1 + 0x6e) = *(undefined1 *)(param_2 + 6);

  *(undefined1 *)(lVar1 + 0x6f) = *(undefined1 *)((longlong)param_2 + 0xd);

  *(undefined1 *)(lVar1 + 0x70) = *(undefined1 *)(param_2 + 7);

  *(undefined1 *)(lVar1 + 0x71) = *(undefined1 *)((longlong)param_2 + 0xf);

  *(undefined1 *)(lVar1 + 0x1a) = *(undefined1 *)(param_2 + 8);

  *(undefined1 *)(lVar1 + 0x1b) = *(undefined1 *)((longlong)param_2 + 0x11);

  FUN_14012ef10(local_28,0x12,"%.2x-%.2x-%.2x-%.2x-%.2x-%.2x",*(undefined1 *)(param_2 + 9),

                *(undefined1 *)((longlong)param_2 + 0x13),*(undefined1 *)(param_2 + 10),

                *(undefined1 *)((longlong)param_2 + 0x15),*(undefined1 *)(param_2 + 0xb),

                *(undefined1 *)((longlong)param_2 + 0x17));

  FUN_140208490(param_1,local_28);

  fVar2 = _DAT_140350d1c;

  bVar4 = -(*(char *)(lVar1 + 0x13) != '\0') & 2;

  bVar5 = bVar4 + 2;

  if (*(char *)(lVar1 + 0x14) == '\0') {

    bVar5 = bVar4;

  }

  *(float *)(lVar1 + 0x24) = _DAT_1403553cc / (_DAT_140350d1c / (float)*(ushort *)(lVar1 + 0x20));

  *(float *)(lVar1 + 0x28) = DAT_14030d930 / (fVar2 / (float)*(ushort *)(lVar1 + 0x22));

  if ((*(char *)(lVar1 + 0x15) != '\0') || (*(char *)(lVar1 + 0x16) != '\0')) {

    bVar5 = bVar5 + 2;

  }

  *(byte *)(lVar1 + 0x6c) = bVar5;

  FUN_140282990();

  pbVar6 = (byte *)(lVar1 + 0x6e);

  lVar7 = 4;

  do {

    bVar5 = 0;

    do {

      if ((*pbVar6 & (byte)(1 << (bVar5 & 0x1f))) != 0) {

        *(char *)(lVar1 + 0x6d) = *(char *)(lVar1 + 0x6d) + '\x01';

      }

      bVar5 = bVar5 + 1;

    } while (bVar5 < 8);

    pbVar6 = pbVar6 + 1;

    lVar7 = lVar7 + -1;

  } while (lVar7 != 0);

  if ((*(byte *)(lVar1 + 0x6e) & 0xf0) == 0xf0) {

    *(undefined1 *)(lVar1 + 0x17) = 1;

    *(char *)(lVar1 + 0x6d) = *(char *)(lVar1 + 0x6d) + -4;

    *(byte *)(lVar1 + 0x6e) = *(byte *)(lVar1 + 0x6e) & 0xf;

  }

  return;

}




