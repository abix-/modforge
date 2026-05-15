// Address: 0x1402005c0
// Ghidra name: FUN_1402005c0
// ============ 0x1402005c0 FUN_1402005c0 (size=488) ============


undefined8 FUN_1402005c0(undefined8 param_1,undefined4 *param_2)



{

  uint uVar1;

  float fVar2;

  float fVar3;

  uint uVar4;

  longlong lVar5;

  undefined8 uVar6;

  longlong lVar7;

  byte bVar8;

  uint uVar9;

  float fVar10;

  float fVar11;

  float fVar12;

  float fVar13;

  float fVar14;

  

  lVar5 = FUN_140145e60(param_2[1],param_2[2],*param_2);

  if (lVar5 == 0) {

    uVar6 = FUN_14012e850("Can\'t create surface");

    return uVar6;

  }

  fVar14 = (float)param_2[0xc];

  *(longlong *)(param_2 + 0x4e) = lVar5;

  fVar3 = DAT_14039ca44;

  fVar2 = DAT_14030a2d0;

  if (0.0 <= fVar14) {

    fVar10 = DAT_14039ca44;

    if (fVar14 <= DAT_14039ca44) {

      fVar10 = fVar14;

    }

  }

  else {

    fVar10 = 0.0;

  }

  fVar10 = (float)thunk_FUN_1402e1d00(fVar10 * DAT_14030a2d0);

  fVar14 = (float)param_2[0xd];

  if (0.0 <= fVar14) {

    fVar11 = fVar3;

    if (fVar14 <= fVar3) {

      fVar11 = fVar14;

    }

  }

  else {

    fVar11 = 0.0;

  }

  fVar11 = (float)thunk_FUN_1402e1d00(fVar11 * fVar2);

  fVar14 = (float)param_2[0xe];

  if (0.0 <= fVar14) {

    fVar12 = fVar3;

    if (fVar14 <= fVar3) {

      fVar12 = fVar14;

    }

  }

  else {

    fVar12 = 0.0;

  }

  fVar13 = (float)thunk_FUN_1402e1d00(fVar12 * fVar2);

  fVar14 = (float)param_2[0xf];

  fVar12 = 0.0;

  if ((0.0 <= fVar14) && (fVar12 = fVar3, fVar14 <= fVar3)) {

    fVar12 = fVar14;

  }

  fVar14 = (float)thunk_FUN_1402e1d00(fVar12 * fVar2);

  FUN_1401486f0(lVar5,(int)fVar10 & 0xff,(int)fVar11 & 0xff,(int)fVar13 & 0xff);

  FUN_1401483d0(lVar5,(int)fVar14 & 0xff);

  FUN_140148450(lVar5,param_2[10]);

  uVar1 = *(uint *)(lVar5 + 4);

  uVar9 = (int)uVar1 >> 0x1c & 0xf;

  if (uVar1 == 0) {

LAB_14020076d:

    uVar4 = uVar1 & 0xf000000;

    if (((uVar4 != 0xc000000) && (uVar4 != 0x2000000)) && (uVar4 != 0x3000000)) goto LAB_14020078f;

    if ((uVar1 == 0) || (uVar9 == 1)) goto LAB_140200737;

    bVar8 = 0;

  }

  else {

    if (uVar9 != 1) goto LAB_14020078f;

    if ((uVar1 & 0xf000000) != 0x1000000) goto LAB_14020076d;

LAB_140200737:

    bVar8 = (byte)(uVar1 >> 8);

  }

  lVar7 = FUN_14017a030(1 << (bVar8 & 0x1f));

  *(longlong *)(lVar5 + 0x48) = lVar7;

  if (lVar7 == 0) {

    uVar6 = FUN_14012e850("Can\'t create palette");

    return uVar6;

  }

LAB_14020078f:

  if (param_2[9] == 0) {

    FUN_1401488a0(lVar5,1);

  }

  return 1;

}




