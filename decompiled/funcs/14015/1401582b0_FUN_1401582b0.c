// Address: 0x1401582b0
// Ghidra name: FUN_1401582b0
// ============ 0x1401582b0 FUN_1401582b0 (size=171) ============


void FUN_1401582b0(ushort *param_1,ushort *param_2,ushort *param_3,ushort *param_4,ushort *param_5)



{

  ushort uVar1;

  

  uVar1 = *param_1;

  if ((uVar1 < 0x20) || (uVar1 == 0xff)) {

    if ((param_1[3] == 0) && (param_1[5] == 0)) {

      if (param_2 != (ushort *)0x0) {

        *param_2 = param_1[2];

      }

      if (param_3 != (ushort *)0x0) {

        *param_3 = param_1[4];

      }

      if (param_4 != (ushort *)0x0) {

        uVar1 = param_1[6];

LAB_140158345:

        *param_4 = uVar1;

      }

    }

    else {

      if ((0x1f < uVar1) && (uVar1 != 0xff)) goto LAB_140158303;

      uVar1 = 0;

      if (param_2 != (ushort *)0x0) {

        *param_2 = 0;

      }

      if (param_3 != (ushort *)0x0) {

        *param_3 = 0;

      }

      if (param_4 != (ushort *)0x0) goto LAB_140158345;

    }

    if (param_5 != (ushort *)0x0) {

      *param_5 = param_1[1];

    }

  }

  else {

LAB_140158303:

    if (param_2 != (ushort *)0x0) {

      *param_2 = 0;

    }

    if (param_3 != (ushort *)0x0) {

      *param_3 = 0;

    }

    if (param_4 != (ushort *)0x0) {

      *param_4 = 0;

    }

    if (param_5 != (ushort *)0x0) {

      *param_5 = 0;

      return;

    }

  }

  return;

}




