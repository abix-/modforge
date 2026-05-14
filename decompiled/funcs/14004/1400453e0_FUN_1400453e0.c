// Address: 0x1400453e0
// Ghidra name: FUN_1400453e0
// ============ 0x1400453e0 FUN_1400453e0 (size=479) ============


void FUN_1400453e0(undefined8 param_1,float param_2,float param_3)



{

  uint uVar1;

  float fVar2;

  undefined8 uVar3;

  float fVar4;

  float fVar5;

  undefined4 uVar6;

  float fVar7;

  

  uVar6 = 0;

  fVar7 = 0.0;

  if (0.0 <= param_3) {

    fVar7 = param_3;

  }

  uVar1 = *(uint *)(DAT_1403ea2a8 + 0x4c);

  fVar2 = 0.0;

  if (0.0 <= param_2) {

    fVar2 = param_2;

  }

joined_r0x000140045419:

  if (uVar1 < 8) {

    switch(IMAGE_DOS_HEADER_140000000.e_magic +

           (&switchD_14004543d::switchdataD_1400455c0)[(int)uVar1]) {

    case (char *)0x14004543f:

      goto switchD_14004543d_caseD_4004543f;

    case (char *)0x140045471:

      FUN_140044ff0(param_1,fVar7);

      return;

    case (char *)0x140045481:

      if (fVar7 == 0.0) {

        uVar6 = DAT_14039ca44;

      }

      uVar3 = FUN_14004f150(param_1,uVar6);

      break;

    case (char *)0x1400454a0:

      if (fVar7 == 0.0) {

        uVar6 = DAT_14039ca44;

      }

      uVar3 = FUN_14004f150(param_1,uVar6);

      *(undefined8 *)(DAT_1403ea2a8 + 0x60) = uVar3;

      *(float *)(DAT_1403ea2a8 + 0x44) = fVar7;

      goto LAB_140045596;

    case (char *)0x1400454d6:

      if (fVar7 == 0.0) {

        uVar6 = DAT_14039ca44;

      }

      uVar3 = FUN_14004f150(param_1,uVar6);

      *(undefined1 *)(*(longlong *)(DAT_1403ea2a8 + 0x60) + 9) = 0;

      *(undefined8 *)(DAT_1403ea2a8 + 0x60) = uVar3;

      *(float *)(DAT_1403ea2a8 + 0x44) = fVar7;

      return;

    case (char *)0x14004551b:

      if (fVar7 == 0.0) {

        uVar6 = DAT_14039ca44;

      }

      uVar3 = FUN_14004f150(param_1,uVar6);

      *(undefined1 *)(*(longlong *)(DAT_1403ea2a8 + 0x58) + 9) = 0;

      *(undefined8 *)(DAT_1403ea2a8 + 0x58) = *(undefined8 *)(DAT_1403ea2a8 + 0x60);

    }

    *(undefined8 *)(DAT_1403ea2a8 + 0x60) = uVar3;

    *(undefined4 *)(DAT_1403ea2a8 + 0x48) =

         *(undefined4 *)(*(longlong *)(DAT_1403ea2a8 + 0x58) + 0xc);

    *(float *)(DAT_1403ea2a8 + 0x40) = fVar2;

    *(float *)(DAT_1403ea2a8 + 0x44) = fVar7;

    *(undefined4 *)(DAT_1403ea2a8 + 0x3c) = 0;

LAB_140045596:

    *(undefined4 *)(DAT_1403ea2a8 + 0x4c) = 4;

  }

  return;

switchD_14004543d_caseD_4004543f:

  FUN_1400450b0(0);

  fVar4 = 0.0;

  if (0.0 <= fVar7) {

    fVar4 = fVar7;

  }

  fVar5 = 0.0;

  if (0.0 <= fVar2) {

    fVar5 = fVar2;

  }

  uVar1 = *(uint *)(DAT_1403ea2a8 + 0x4c);

  fVar7 = fVar4;

  fVar2 = fVar5;

  goto joined_r0x000140045419;

}




