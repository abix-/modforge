// Address: 0x140181a10
// Ghidra name: FUN_140181a10
// ============ 0x140181a10 FUN_140181a10 (size=1947) ============


int FUN_140181a10(uint param_1,ushort param_2)



{

  int iVar1;

  bool bVar2;

  

  if (param_1 < 0x200) {

    if (3 < (int)param_1) {

      if ((int)param_1 < 0x1e) {

        bVar2 = (param_2 & 3) != 0;

        if ((param_2 >> 0xd & 1) != 0) {

          bVar2 = (param_2 & 3) == 0;

        }

        if ((param_2 >> 0xe & 1) == 0) {

          iVar1 = param_1 + 0x3d;

          if (!bVar2) {

            iVar1 = param_1 + 0x5d;

          }

          return iVar1;

        }

      }

      else if ((int)param_1 < 0x39) {

        if ((param_2 >> 0xe & 1) == 0) {

          if ((param_2 & 3) == 0) {

            return *(int *)(L"Software\\Microsoft\\Windows\\CurrentVersion\\Themes\\Personalize" +

                           (longlong)(int)param_1 * 2 + 0x34);

          }

          return *(int *)(&DAT_140337fd8 + (longlong)(int)param_1 * 4);

        }

      }

      else {

        switch(param_1) {

        case 0x39:

          return 0x40000039;

        case 0x3a:

          return 0x4000003a;

        case 0x3b:

          return 0x4000003b;

        case 0x3c:

          return 0x4000003c;

        case 0x3d:

          return 0x4000003d;

        case 0x3e:

          return 0x4000003e;

        case 0x3f:

          return 0x4000003f;

        case 0x40:

          return 0x40000040;

        case 0x41:

          return 0x40000041;

        case 0x42:

          return 0x40000042;

        case 0x43:

          return 0x40000043;

        case 0x44:

          return 0x40000044;

        case 0x45:

          return 0x40000045;

        case 0x46:

          return 0x40000046;

        case 0x47:

          return 0x40000047;

        case 0x48:

          return 0x40000048;

        case 0x49:

          return 0x40000049;

        case 0x4a:

          return 0x4000004a;

        case 0x4b:

          return 0x4000004b;

        case 0x4c:

          return 0x7f;

        case 0x4d:

          return 0x4000004d;

        case 0x4e:

          return 0x4000004e;

        case 0x4f:

          return 0x4000004f;

        case 0x50:

          return 0x40000050;

        case 0x51:

          return 0x40000051;

        case 0x52:

          return 0x40000052;

        case 0x53:

          return 0x40000053;

        case 0x54:

          return 0x40000054;

        case 0x55:

          return 0x40000055;

        case 0x56:

          return 0x40000056;

        case 0x57:

          return 0x40000057;

        case 0x58:

          return 0x40000058;

        case 0x59:

          return 0x40000059;

        case 0x5a:

          return 0x4000005a;

        case 0x5b:

          return 0x4000005b;

        case 0x5c:

          return 0x4000005c;

        case 0x5d:

          return 0x4000005d;

        case 0x5e:

          return 0x4000005e;

        case 0x5f:

          return 0x4000005f;

        case 0x60:

          return 0x40000060;

        case 0x61:

          return 0x40000061;

        case 0x62:

          return 0x40000062;

        case 99:

          return 0x40000063;

        case 0x65:

          return 0x40000065;

        case 0x66:

          return 0x40000066;

        case 0x67:

          return 0x40000067;

        case 0x68:

          return 0x40000068;

        case 0x69:

          return 0x40000069;

        case 0x6a:

          return 0x4000006a;

        case 0x6b:

          return 0x4000006b;

        case 0x6c:

          return 0x4000006c;

        case 0x6d:

          return 0x4000006d;

        case 0x6e:

          return 0x4000006e;

        case 0x6f:

          return 0x4000006f;

        case 0x70:

          return 0x40000070;

        case 0x71:

          return 0x40000071;

        case 0x72:

          return 0x40000072;

        case 0x73:

          return 0x40000073;

        case 0x74:

          return 0x40000074;

        case 0x75:

          return 0x40000075;

        case 0x76:

          return 0x40000076;

        case 0x77:

          return 0x40000077;

        case 0x78:

          return 0x40000078;

        case 0x79:

          return 0x40000079;

        case 0x7a:

          return 0x4000007a;

        case 0x7b:

          return 0x4000007b;

        case 0x7c:

          return 0x4000007c;

        case 0x7d:

          return 0x4000007d;

        case 0x7e:

          return 0x4000007e;

        case 0x7f:

          return 0x4000007f;

        case 0x80:

          return 0x40000080;

        case 0x81:

          return 0x40000081;

        case 0x85:

          return 0x40000085;

        case 0x86:

          return 0x40000086;

        case 0x99:

          return 0x40000099;

        case 0x9a:

          return 0x4000009a;

        case 0x9b:

          return 0x4000009b;

        case 0x9c:

          return 0x4000009c;

        case 0x9d:

          return 0x4000009d;

        case 0x9e:

          return 0x4000009e;

        case 0x9f:

          return 0x4000009f;

        case 0xa0:

          return 0x400000a0;

        case 0xa1:

          return 0x400000a1;

        case 0xa2:

          return 0x400000a2;

        case 0xa3:

          return 0x400000a3;

        case 0xa4:

          return 0x400000a4;

        case 0xb0:

          return 0x400000b0;

        case 0xb1:

          return 0x400000b1;

        case 0xb2:

          return 0x400000b2;

        case 0xb3:

          return 0x400000b3;

        case 0xb4:

          return 0x400000b4;

        case 0xb5:

          return 0x400000b5;

        case 0xb6:

          return 0x400000b6;

        case 0xb7:

          return 0x400000b7;

        case 0xb8:

          return 0x400000b8;

        case 0xb9:

          return 0x400000b9;

        case 0xba:

          return 0x400000ba;

        case 0xbb:

          return 0x400000bb;

        case 0xbc:

          return 0x400000bc;

        case 0xbd:

          return 0x400000bd;

        case 0xbe:

          return 0x400000be;

        case 0xbf:

          return 0x400000bf;

        case 0xc0:

          return 0x400000c0;

        case 0xc1:

          return 0x400000c1;

        case 0xc2:

          return 0x400000c2;

        case 0xc3:

          return 0x400000c3;

        case 0xc4:

          return 0x400000c4;

        case 0xc5:

          return 0x400000c5;

        case 0xc6:

          return 0x400000c6;

        case 199:

          return 0x400000c7;

        case 200:

          return 0x400000c8;

        case 0xc9:

          return 0x400000c9;

        case 0xca:

          return 0x400000ca;

        case 0xcb:

          return 0x400000cb;

        case 0xcc:

          return 0x400000cc;

        case 0xcd:

          return 0x400000cd;

        case 0xce:

          return 0x400000ce;

        case 0xcf:

          return 0x400000cf;

        case 0xd0:

          return 0x400000d0;

        case 0xd1:

          return 0x400000d1;

        case 0xd2:

          return 0x400000d2;

        case 0xd3:

          return 0x400000d3;

        case 0xd4:

          return 0x400000d4;

        case 0xd5:

          return 0x400000d5;

        case 0xd6:

          return 0x400000d6;

        case 0xd7:

          return 0x400000d7;

        case 0xd8:

          return 0x400000d8;

        case 0xd9:

          return 0x400000d9;

        case 0xda:

          return 0x400000da;

        case 0xdb:

          return 0x400000db;

        case 0xdc:

          return 0x400000dc;

        case 0xdd:

          return 0x400000dd;

        case 0xe0:

          return 0x400000e0;

        case 0xe1:

          return 0x400000e1;

        case 0xe2:

          return 0x400000e2;

        case 0xe3:

          return 0x400000e3;

        case 0xe4:

          return 0x400000e4;

        case 0xe5:

          return 0x400000e5;

        case 0xe6:

          return 0x400000e6;

        case 0xe7:

          return 0x400000e7;

        case 0x101:

          return 0x40000101;

        case 0x102:

          return 0x40000102;

        case 0x103:

          return 0x40000103;

        case 0x104:

          return 0x40000104;

        case 0x105:

          return 0x40000105;

        case 0x106:

          return 0x40000106;

        case 0x107:

          return 0x40000107;

        case 0x108:

          return 0x40000108;

        case 0x109:

          return 0x40000109;

        case 0x10a:

          return 0x4000010a;

        case 0x10b:

          return 0x4000010b;

        case 0x10c:

          return 0x4000010c;

        case 0x10d:

          return 0x4000010d;

        case 0x10e:

          return 0x4000010e;

        case 0x10f:

          return 0x4000010f;

        case 0x110:

          return 0x40000110;

        case 0x111:

          return 0x40000111;

        case 0x112:

          return 0x40000112;

        case 0x113:

          return 0x40000113;

        case 0x114:

          return 0x40000114;

        case 0x115:

          return 0x40000115;

        case 0x116:

          return 0x40000116;

        case 0x117:

          return 0x40000117;

        case 0x118:

          return 0x40000118;

        case 0x119:

          return 0x40000119;

        case 0x11a:

          return 0x4000011a;

        case 0x11b:

          return 0x4000011b;

        case 0x11c:

          return 0x4000011c;

        case 0x11d:

          return 0x4000011d;

        case 0x11e:

          return 0x4000011e;

        case 0x11f:

          return 0x4000011f;

        case 0x120:

          return 0x40000120;

        case 0x121:

          return 0x40000121;

        case 0x122:

          return 0x40000122;

        }

      }

    }

  }

  else {

    FUN_14012e850("Parameter \'%s\' is invalid","scancode");

  }

  return 0;

}




