// Address: 0x140087710
// Ghidra name: FUN_140087710
// ============ 0x140087710 FUN_140087710 (size=887) ============


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void FUN_140087710(void)



{

  char cVar1;

  uint uVar2;

  longlong lVar3;

  undefined1 uVar4;

  uint uVar5;

  uint local_158 [84];

  

  if (DAT_1403eaf28 == '\0') {

    uVar5 = 0;

    DAT_1403eaf28 = '\x01';

    uVar2 = 0;

    do {

      if ((int)uVar2 < 0x20) {

LAB_140087758:

        uVar4 = 0;

      }

      else if ((int)uVar2 < 0x7f) {

        uVar4 = (undefined1)uVar2;

      }

      else {

        if (uVar2 == 0x7f) goto LAB_140087758;

        uVar4 = 0xff;

      }

      lVar3 = (longlong)(int)uVar2;

      uVar2 = uVar2 + 1;

      (&DAT_1403eaf30)[lVar3] = uVar4;

    } while (uVar2 < 0x2165);

    local_158[0] = 0xa1;

    local_158[1] = 0xa2;

    local_158[2] = 0xa3;

    local_158[3] = 0xa5;

    local_158[4] = 0xa9;

    local_158[5] = 0xab;

    local_158[6] = 0xae;

    local_158[7] = 0xb0;

    local_158[8] = 0xbb;

    local_158[9] = 0xbf;

    local_158[10] = 0xc0;

    local_158[0xb] = 0xc1;

    local_158[0xc] = 0xc2;

    local_158[0xd] = 0xc3;

    local_158[0xe] = 0xc4;

    local_158[0xf] = 0xc5;

    local_158[0x10] = 0xc6;

    local_158[0x11] = 199;

    local_158[0x12] = 200;

    local_158[0x13] = 0xc9;

    local_158[0x14] = 0xca;

    local_158[0x15] = 0xcb;

    local_158[0x16] = 0xcc;

    local_158[0x17] = 0xcd;

    local_158[0x18] = 0xce;

    local_158[0x19] = 0xcf;

    local_158[0x1a] = 0xd1;

    local_158[0x1b] = 0xd2;

    local_158[0x1c] = 0xd3;

    local_158[0x1d] = 0xd4;

    local_158[0x1e] = 0xd5;

    local_158[0x1f] = 0xd6;

    local_158[0x20] = 0xd9;

    local_158[0x21] = 0xda;

    local_158[0x22] = 0xdb;

    local_158[0x23] = 0xdc;

    local_158[0x24] = 0xdf;

    local_158[0x25] = 0xe0;

    local_158[0x26] = 0xe1;

    local_158[0x27] = 0xe2;

    local_158[0x28] = 0xe3;

    local_158[0x29] = 0xe4;

    local_158[0x2a] = 0xe5;

    local_158[0x2b] = 0xe6;

    local_158[0x2c] = 0xe7;

    local_158[0x2d] = 0xe8;

    local_158[0x2e] = 0xe9;

    local_158[0x2f] = 0xea;

    local_158[0x30] = 0xeb;

    local_158[0x31] = 0xec;

    local_158[0x32] = 0xed;

    local_158[0x33] = 0xee;

    local_158[0x34] = 0xef;

    local_158[0x35] = 0xf1;

    local_158[0x36] = 0xf2;

    local_158[0x37] = 0xf3;

    local_158[0x38] = 0xf4;

    local_158[0x39] = 0xf5;

    local_158[0x3a] = 0xf6;

    local_158[0x3b] = 0xf9;

    local_158[0x3c] = 0xfa;

    local_158[0x3d] = 0xfb;

    local_158[0x3e] = 0xfc;

    local_158[0x3f] = 0xff;

    local_158[0x40] = 0x152;

    local_158[0x41] = 0x153;

    local_158[0x42] = 0x178;

    local_158[0x43] = 0x1e9e;

    local_158[0x44] = 0x2013;

    local_158[0x45] = 0x2014;

    local_158[0x46] = 0x2018;

    local_158[0x47] = 0x2019;

    local_158[0x48] = 0x201a;

    local_158[0x49] = 0x201c;

    local_158[0x4a] = 0x201d;

    local_158[0x4b] = 0x201e;

    local_158[0x4c] = 0x2022;

    local_158[0x4d] = 0x2026;

    local_158[0x4e] = 0x2039;

    local_158[0x4f] = 0x203a;

    local_158[0x50] = 0x20ac;

    local_158[0x51] = 0x2122;

    do {

      cVar1 = (char)uVar5;

      (&DAT_1403eaf30)[local_158[(int)uVar5]] = cVar1 + -0x80;

      lVar3 = (longlong)(int)uVar5;

      uVar5 = uVar5 + 2;

      (&DAT_1403eaf30)[local_158[lVar3 + 1]] = cVar1 + -0x7f;

    } while (uVar5 < 0x52);

    DAT_1403ed056 = 1;

    DAT_1403ed071 = 2;

    DAT_1403ed051 = 3;

    _DAT_1403ec2d0 =

         CONCAT13((char)((uint)DAT_14030b020 >> 0x18) + UNK_14030b043,

                  CONCAT12((char)((uint)DAT_14030b020 >> 0x10) + UNK_14030b042,

                           CONCAT11((char)((uint)DAT_14030b020 >> 8) + UNK_14030b041,

                                    (char)DAT_14030b020 + DAT_14030b040)));

    DAT_1403ed04b = 4;

    DAT_1403ed094 = 5;

    _DAT_1403ec2d4 =

         CONCAT13((char)((uint)DAT_14030b030 >> 0x18) + UNK_14030b043,

                  CONCAT12((char)((uint)DAT_14030b030 >> 0x10) + UNK_14030b042,

                           CONCAT11((char)((uint)DAT_14030b030 >> 8) + UNK_14030b041,

                                    (char)DAT_14030b030 + DAT_14030b040)));

    DAT_1403ed05c = 6;

    DAT_1403ed047 = 7;

    DAT_1403ed079 = 8;

    _DAT_1403eb0b0 = 0xc0b0a09;

    _DAT_1403eb0b4 = 0x100f0e0d;

    DAT_1403ed07f = 0x11;

  }

  return;

}




