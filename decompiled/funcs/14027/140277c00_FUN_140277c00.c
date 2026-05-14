// Address: 0x140277c00
// Ghidra name: FUN_140277c00
// ============ 0x140277c00 FUN_140277c00 (size=1274) ============


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void FUN_140277c00(longlong param_1,undefined8 param_2,longlong param_3)



{

  uint uVar1;

  uint *puVar2;

  float fVar3;

  float fVar4;

  byte bVar5;

  undefined8 uVar6;

  byte bVar7;

  float fVar8;

  float local_48;

  float local_44;

  float local_40;

  

  puVar2 = *(uint **)(param_1 + 0x70);

  uVar6 = FUN_140149300();

  if (*(ulonglong *)(param_3 + 8) != *(ulonglong *)(puVar2 + 4)) {

    FUN_14015ad00(uVar6,param_2,0,*(ulonglong *)(param_3 + 8) >> 7 & 0x1ffff01);

    FUN_14015ad00(uVar6,param_2,1,*(uint *)(param_3 + 8) >> 5 & 0xffffff01);

    FUN_14015ad00(uVar6,param_2,2,*(uint *)(param_3 + 8) >> 6 & 0xffffff01);

    FUN_14015ad00(uVar6,param_2,3,*(uint *)(param_3 + 8) >> 4 & 0xffffff01);

    FUN_14015ad00(uVar6,param_2,9,*(uint *)(param_3 + 8) >> 3 & 0xffffff01);

    FUN_14015ad00(uVar6,param_2,10,*(uint *)(param_3 + 8) >> 2 & 0xffffff01);

    FUN_14015ad00(uVar6,param_2,4,*(uint *)(param_3 + 8) >> 0xc & 0xffffff01);

    FUN_14015ad00(uVar6,param_2,6,*(uint *)(param_3 + 8) >> 0xe & 0xffffff01);

    FUN_14015ad00(uVar6,param_2,5,*(uint *)(param_3 + 8) >> 0xd & 0xffffff01);

    FUN_14015ad00(uVar6,param_2,0xb,*(uint *)(param_3 + 0xc) >> 0x12 & 0xffffff01);

    FUN_14015ad00(uVar6,param_2,7,*(uint *)(param_3 + 8) >> 0x16 & 0xffffff01);

    FUN_14015ad00(uVar6,param_2,8,*(uint *)(param_3 + 8) >> 0x1a & 0xffffff01);

    FUN_14015ad00(uVar6,param_2,0xc,*(uint *)(param_3 + 0xc) >> 10 & 0xffffff01);

    FUN_14015ad00(uVar6,param_2,0xd,*(uint *)(param_3 + 0xc) >> 9 & 0xffffff01);

    FUN_14015ad00(uVar6,param_2,0xe,*(byte *)(param_3 + 10) & 1);

    FUN_14015ad00(uVar6,param_2,0xf,*(uint *)(param_3 + 8) >> 0xf & 0xffffff01);

    uVar1 = *(uint *)(param_3 + 8);

    bVar5 = (byte)(uVar1 >> 8) & 1;

    bVar7 = bVar5 | 4;

    if ((uVar1 >> 0xb & 1) == 0) {

      bVar7 = bVar5;

    }

    bVar5 = bVar7 | 8;

    if ((uVar1 >> 10 & 1) == 0) {

      bVar5 = bVar7;

    }

    bVar7 = bVar5 | 2;

    if ((uVar1 >> 9 & 1) == 0) {

      bVar7 = bVar5;

    }

    FUN_14015ae90(uVar6,param_2,0,bVar7);

    *(undefined8 *)(puVar2 + 4) = *(undefined8 *)(param_3 + 8);

  }

  FUN_14015aab0(uVar6,param_2,4,(*(short *)(param_3 + 0x2c) + -0x4000) * 2);

  FUN_14015aab0(uVar6,param_2,5,(*(short *)(param_3 + 0x2e) + -0x4000) * 2);

  FUN_14015aab0(uVar6,param_2,0,*(undefined2 *)(param_3 + 0x30));

  FUN_14015aab0(uVar6,param_2,1,-*(short *)(param_3 + 0x32));

  FUN_14015aab0(uVar6,param_2,2,*(undefined2 *)(param_3 + 0x34));

  FUN_14015aab0(uVar6,param_2,3,-*(short *)(param_3 + 0x36));

  local_40 = DAT_14037f684;

  fVar3 = DAT_14037f67c;

  *(ulonglong *)(puVar2 + 2) = *(longlong *)(puVar2 + 2) + (ulonglong)*puVar2 * 1000;

  local_48 = (float)(int)*(short *)(param_3 + 0x1e) * fVar3 * local_40;

  local_44 = (float)(int)*(short *)(param_3 + 0x22) * fVar3 * local_40;

  local_40 = (float)-(int)*(short *)(param_3 + 0x20) * fVar3 * local_40;

  FUN_14015afd0(uVar6,param_2,2,*(undefined8 *)(puVar2 + 2),&local_48,3);

  fVar8 = (float)(int)*(short *)(param_3 + 0x18) * fVar3;

  local_48 = (fVar8 + fVar8) * _DAT_1403553cc;

  fVar8 = (float)(int)*(short *)(param_3 + 0x1c) * fVar3;

  local_44 = (fVar8 + fVar8) * _DAT_1403553cc;

  fVar8 = (float)-(int)*(short *)(param_3 + 0x1a) * fVar3;

  local_40 = (fVar8 + fVar8) * _DAT_1403553cc;

  FUN_14015afd0(uVar6,param_2,1,*(undefined8 *)(puVar2 + 2),&local_48,3);

  fVar4 = DAT_14039ca34;

  fVar8 = DAT_1403053bc;

  FUN_14015b110(uVar6,param_2,0,0,*(ushort *)(param_3 + 0x38) != 0,

                (float)(int)*(short *)(param_3 + 0x10) * DAT_1403053bc + DAT_14039ca34,

                (float)(int)*(short *)(param_3 + 0x12) * DAT_1403053bc + DAT_14039ca34,

                (float)*(ushort *)(param_3 + 0x38) * fVar3);

  FUN_14015b110(uVar6,param_2,1,0,*(ushort *)(param_3 + 0x3a) != 0,

                (float)(int)*(short *)(param_3 + 0x14) * fVar8 + fVar4,

                (float)(int)*(short *)(param_3 + 0x16) * fVar8 + fVar4,

                (float)*(ushort *)(param_3 + 0x3a) * fVar3);

  return;

}




