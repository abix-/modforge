// Address: 0x140144740
// Ghidra name: FUN_140144740
// ============ 0x140144740 FUN_140144740 (size=765) ============


ulonglong FUN_140144740(longlong param_1,float param_2,float param_3,float param_4,float param_5)



{

  uint uVar1;

  float *pfVar2;

  char cVar3;

  byte bVar4;

  undefined4 uVar5;

  ulonglong uVar6;

  longlong lVar7;

  float fVar8;

  float fVar9;

  float fVar10;

  float fVar11;

  float fVar12;

  undefined1 local_78 [112];

  

  bVar4 = 0;

  cVar3 = FUN_1401489c0();

  if (cVar3 == '\0') {

    uVar6 = FUN_14012e850("Parameter \'%s\' is invalid","surface");

    return uVar6;

  }

  FUN_1401466d0(param_1,local_78);

  FUN_1401485c0(param_1,0);

  fVar11 = DAT_14030a2d0;

  uVar1 = *(uint *)(param_1 + 4);

  if (uVar1 != 0) {

    if ((uVar1 & 0xf0000000) != 0x10000000) {

      lVar7 = FUN_140145e60(*(undefined4 *)(param_1 + 8),*(undefined4 *)(param_1 + 0xc),0x16362004);

      if (lVar7 != 0) {

        cVar3 = FUN_140144740(lVar7,param_2,param_3,param_4,param_5);

        if (cVar3 != '\0') {

          bVar4 = FUN_140144d60(*(undefined4 *)(param_1 + 8),*(undefined4 *)(param_1 + 0xc),

                                *(undefined4 *)(lVar7 + 4),*(undefined4 *)(lVar7 + 0x40),

                                *(undefined4 *)(lVar7 + 0x34),*(undefined8 *)(lVar7 + 0x18),

                                *(undefined4 *)(lVar7 + 0x10),*(undefined4 *)(param_1 + 4),

                                *(undefined4 *)(param_1 + 0x40),*(undefined4 *)(param_1 + 0x34),

                                *(undefined8 *)(param_1 + 0x18),*(undefined4 *)(param_1 + 0x10));

        }

        FUN_140146010(lVar7);

      }

      goto LAB_140144a04;

    }

    if (4 < (byte)uVar1) {

      lVar7 = FUN_140145e60(1,1,0x1b208010);

      if (lVar7 != 0) {

        FUN_1401487a0(lVar7,*(undefined4 *)(param_1 + 0x40));

        FUN_140148450(lVar7,0);

        pfVar2 = *(float **)(lVar7 + 0x18);

        *pfVar2 = param_2;

        pfVar2[1] = param_3;

        pfVar2[2] = param_4;

        pfVar2[3] = param_5;

        bVar4 = FUN_140143490(lVar7,0,param_1,0,0);

        FUN_140146010(lVar7);

      }

      goto LAB_140144a04;

    }

  }

  if (0.0 <= param_5) {

    fVar8 = DAT_14039ca44;

    if (param_5 <= DAT_14039ca44) {

      fVar8 = param_5;

    }

  }

  else {

    fVar8 = 0.0;

  }

  if (0.0 <= param_4) {

    fVar9 = DAT_14039ca44;

    if (param_4 <= DAT_14039ca44) {

      fVar9 = param_4;

    }

  }

  else {

    fVar9 = 0.0;

  }

  if (0.0 <= param_3) {

    fVar10 = DAT_14039ca44;

    if (param_3 <= DAT_14039ca44) {

      fVar10 = param_3;

    }

  }

  else {

    fVar10 = 0.0;

  }

  fVar12 = 0.0;

  if ((0.0 <= param_2) && (fVar12 = DAT_14039ca44, param_2 <= DAT_14039ca44)) {

    fVar12 = param_2;

  }

  fVar8 = (float)thunk_FUN_1402e1d00(fVar8 * DAT_14030a2d0);

  fVar9 = (float)thunk_FUN_1402e1d00(fVar9 * fVar11);

  fVar10 = (float)thunk_FUN_1402e1d00(fVar10 * fVar11);

  fVar11 = (float)thunk_FUN_1402e1d00(fVar12 * fVar11);

  uVar5 = FUN_140146f80(param_1,(int)fVar11,(int)fVar10 & 0xff,(int)fVar9 & 0xff,(int)fVar8 & 0xff);

  bVar4 = FUN_14017dc90(param_1,0,uVar5);

LAB_140144a04:

  FUN_1401485c0(param_1,local_78);

  return (ulonglong)bVar4;

}




