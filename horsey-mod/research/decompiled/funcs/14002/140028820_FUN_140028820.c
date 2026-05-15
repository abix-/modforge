// Address: 0x140028820
// Ghidra name: FUN_140028820
// ============ 0x140028820 FUN_140028820 (size=209) ============


byte * FUN_140028820(byte *param_1,int param_2)



{

  int iVar1;

  byte bVar2;

  

  if ((param_1 == (byte *)0x0) || (bVar2 = *param_1, bVar2 == 0)) {

    return (byte *)0x0;

  }

  if (param_2 != 1) {

    while (((iVar1 = isspace((uint)bVar2), iVar1 != 0 || (bVar2 == 10)) || (bVar2 == 0xd))) {

      bVar2 = param_1[1];

      param_1 = param_1 + 1;

      if (bVar2 == 0) {

        return param_1;

      }

    }

    return param_1;

  }

  do {

    if (bVar2 == 0xef) {

      if ((param_1[1] == 0xbb) && (param_1[2] == 0xbf)) {

        param_1 = param_1 + 3;

      }

      else {

        if (param_1[1] != 0xbf) goto LAB_14002887f;

        if (param_1[2] == 0xbe) {

          param_1 = param_1 + 3;

        }

        else {

          if (param_1[2] != 0xbf) goto LAB_14002887f;

          param_1 = param_1 + 3;

        }

      }

    }

    else {

LAB_14002887f:

      iVar1 = isspace((uint)bVar2);

      if (((iVar1 == 0) && (bVar2 != 10)) && (bVar2 != 0xd)) {

        return param_1;

      }

      param_1 = param_1 + 1;

    }

    bVar2 = *param_1;

    if (bVar2 == 0) {

      return param_1;

    }

  } while( true );

}




