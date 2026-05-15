// Address: 0x1400455f0
// Ghidra name: FUN_1400455f0
// ============ 0x1400455f0 FUN_1400455f0 (size=284) ============


void FUN_1400455f0(undefined8 param_1,float param_2)



{

  uint uVar1;

  longlong lVar2;

  float fVar3;

  undefined4 uVar4;

  float fVar5;

  

  fVar5 = 0.0;

  if (0.0 <= param_2) {

    fVar5 = param_2;

  }

  uVar1 = *(uint *)(DAT_1403ea2a8 + 0x4c);

joined_r0x00014004561a:

  if (uVar1 < 8) {

    switch(IMAGE_DOS_HEADER_140000000.e_magic +

           (&switchD_14004563c::switchdataD_14004570c)[(int)uVar1]) {

    case (char *)0x14004563e:

      goto switchD_14004563c_caseD_4004563e;

    case (char *)0x140045664:

      FUN_140044ff0(param_1,fVar5);

      return;

    case (char *)0x140045674:

      *(undefined1 *)(*(longlong *)(DAT_1403ea2a8 + 0x60) + 9) = 0;

      break;

    case (char *)0x14004567e:

      *(undefined1 *)(*(longlong *)(DAT_1403ea2a8 + 0x58) + 9) = 0;

      *(undefined8 *)(DAT_1403ea2a8 + 0x58) = *(undefined8 *)(DAT_1403ea2a8 + 0x60);

    }

    uVar4 = 0;

    if (fVar5 == 0.0) {

      uVar4 = DAT_14039ca44;

    }

    lVar2 = FUN_14004f150(param_1,uVar4);

    *(undefined1 *)(lVar2 + 10) = 0;

    *(longlong *)(DAT_1403ea2a8 + 0x60) = lVar2;

    *(undefined4 *)(DAT_1403ea2a8 + 0x48) =

         *(undefined4 *)(*(longlong *)(DAT_1403ea2a8 + 0x58) + 0xc);

    *(float *)(DAT_1403ea2a8 + 0x40) = fVar5;

    *(undefined4 *)(DAT_1403ea2a8 + 0x3c) = 0;

    *(undefined4 *)(DAT_1403ea2a8 + 0x4c) = 6;

  }

  return;

switchD_14004563c_caseD_4004563e:

  FUN_1400450b0(0);

  fVar3 = 0.0;

  if (0.0 <= fVar5) {

    fVar3 = fVar5;

  }

  uVar1 = *(uint *)(DAT_1403ea2a8 + 0x4c);

  fVar5 = fVar3;

  goto joined_r0x00014004561a;

}




