// Address: 0x1400450b0
// Ghidra name: FUN_1400450b0
// ============ 0x1400450b0 FUN_1400450b0 (size=384) ============


void FUN_1400450b0(float param_1)



{

  float fVar1;

  

  fVar1 = 0.0;

  if (0.0 <= param_1) {

    fVar1 = param_1;

  }

  if (fVar1 != 0.0) {

    switch(*(undefined4 *)(DAT_1403ea2a8 + 0x4c)) {

    case 1:

    case 3:

      *(undefined4 *)(DAT_1403ea2a8 + 0x48) =

           *(undefined4 *)(*(longlong *)(DAT_1403ea2a8 + 0x58) + 0xc);

      *(undefined4 *)(DAT_1403ea2a8 + 0x4c) = 2;

      *(float *)(DAT_1403ea2a8 + 0x40) = fVar1;

      *(undefined4 *)(DAT_1403ea2a8 + 0x3c) = 0;

      return;

    default:

      return;

    case 4:

      *(undefined4 *)(DAT_1403ea2a8 + 0x48) =

           *(undefined4 *)(*(longlong *)(DAT_1403ea2a8 + 0x58) + 0xc);

      *(undefined4 *)(DAT_1403ea2a8 + 0x4c) = 2;

      *(float *)(DAT_1403ea2a8 + 0x40) = fVar1;

      *(undefined4 *)(DAT_1403ea2a8 + 0x3c) = 0;

      *(undefined1 *)(*(longlong *)(DAT_1403ea2a8 + 0x60) + 9) = 0;

      *(undefined8 *)(DAT_1403ea2a8 + 0x60) = 0;

      return;

    case 5:

    case 6:

      *(undefined4 *)(DAT_1403ea2a8 + 0x48) =

           *(undefined4 *)(*(longlong *)(DAT_1403ea2a8 + 0x60) + 0xc);

      *(undefined4 *)(DAT_1403ea2a8 + 0x4c) = 2;

      *(float *)(DAT_1403ea2a8 + 0x40) = fVar1;

      *(undefined4 *)(DAT_1403ea2a8 + 0x3c) = 0;

      *(undefined1 *)(*(longlong *)(DAT_1403ea2a8 + 0x58) + 9) = 0;

      *(undefined8 *)(DAT_1403ea2a8 + 0x58) = *(undefined8 *)(DAT_1403ea2a8 + 0x60);

      *(undefined8 *)(DAT_1403ea2a8 + 0x60) = 0;

      return;

    case 7:

      break;

    }

  }

  if (*(longlong *)(DAT_1403ea2a8 + 0x58) != 0) {

    *(undefined1 *)(*(longlong *)(DAT_1403ea2a8 + 0x58) + 9) = 0;

    *(undefined1 *)(*(longlong *)(DAT_1403ea2a8 + 0x58) + 10) = 0;

  }

  if (*(longlong *)(DAT_1403ea2a8 + 0x60) != 0) {

    *(undefined1 *)(*(longlong *)(DAT_1403ea2a8 + 0x60) + 9) = 0;

    *(undefined1 *)(*(longlong *)(DAT_1403ea2a8 + 0x60) + 10) = 0;

  }

  *(undefined8 *)(DAT_1403ea2a8 + 0x58) = 0;

  *(undefined8 *)(DAT_1403ea2a8 + 0x60) = 0;

  *(undefined4 *)(DAT_1403ea2a8 + 0x4c) = 0;

  return;

}




