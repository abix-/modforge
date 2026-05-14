// Address: 0x14020c2e0
// Ghidra name: FUN_14020c2e0
// ============ 0x14020c2e0 FUN_14020c2e0 (size=1082) ============


ulonglong FUN_14020c2e0(undefined8 param_1,undefined4 *param_2)



{

  ulonglong uVar1;

  byte bVar2;

  byte bVar3;

  

  uVar1 = FUN_14020d2c0();

  bVar2 = 0;

  bVar3 = 0;

  if ((uVar1 != 0) && (*(short *)(uVar1 + 0x2c) == 1)) {

    if ((*(short *)(uVar1 + 0x36) != 0) && ((*(byte *)(uVar1 + 0x44) & 1) != 0)) {

      *(undefined1 *)(param_2 + 1) = 0;

      bVar2 = 1;

      *param_2 = 1;

    }

    if (((ushort)bVar2 < *(ushort *)(uVar1 + 0x36)) && ((*(byte *)(uVar1 + 0x44) & 2) != 0)) {

      *(byte *)(param_2 + 3) = bVar2;

      bVar2 = bVar2 + 1;

      param_2[2] = 1;

    }

    if (((ushort)bVar2 < *(ushort *)(uVar1 + 0x36)) && ((*(byte *)(uVar1 + 0x44) & 4) != 0)) {

      *(byte *)(param_2 + 5) = bVar2;

      bVar2 = bVar2 + 1;

      param_2[4] = 1;

    }

    if (((ushort)bVar2 < *(ushort *)(uVar1 + 0x36)) && ((*(byte *)(uVar1 + 0x44) & 8) != 0)) {

      *(byte *)(param_2 + 7) = bVar2;

      bVar2 = bVar2 + 1;

      param_2[6] = 1;

    }

    if (((ushort)bVar2 < *(ushort *)(uVar1 + 0x36)) && ((*(byte *)(uVar1 + 0x44) & 0x10) != 0)) {

      *(byte *)(param_2 + 9) = bVar2;

      bVar2 = bVar2 + 1;

      param_2[8] = 1;

    }

    if (((ushort)bVar2 < *(ushort *)(uVar1 + 0x36)) && ((*(byte *)(uVar1 + 0x44) & 0x20) != 0)) {

      *(byte *)(param_2 + 0xb) = bVar2;

      bVar2 = bVar2 + 1;

      param_2[10] = 1;

    }

    if (((ushort)bVar2 < *(ushort *)(uVar1 + 0x36)) && ((*(byte *)(uVar1 + 0x44) & 0x40) != 0)) {

      *(byte *)(param_2 + 0xd) = bVar2;

      bVar2 = bVar2 + 1;

      param_2[0xc] = 1;

    }

    if (((ushort)bVar2 < *(ushort *)(uVar1 + 0x36)) && ((*(byte *)(uVar1 + 0x44) & 0x80) != 0)) {

      *(byte *)(param_2 + 0xf) = bVar2;

      bVar2 = bVar2 + 1;

      param_2[0xe] = 1;

    }

    if (((ushort)bVar2 < *(ushort *)(uVar1 + 0x36)) && ((*(uint *)(uVar1 + 0x44) & 0x100) != 0)) {

      *(byte *)(param_2 + 0x11) = bVar2;

      bVar2 = bVar2 + 1;

      param_2[0x10] = 1;

    }

    if (((ushort)bVar2 < *(ushort *)(uVar1 + 0x36)) && ((*(uint *)(uVar1 + 0x44) & 0x200) != 0)) {

      *(byte *)(param_2 + 0x13) = bVar2;

      bVar2 = bVar2 + 1;

      param_2[0x12] = 1;

    }

    if (((ushort)bVar2 < *(ushort *)(uVar1 + 0x36)) && ((*(uint *)(uVar1 + 0x44) & 0x400) != 0)) {

      *(byte *)(param_2 + 0x15) = bVar2;

      bVar2 = bVar2 + 1;

      param_2[0x14] = 1;

    }

    if (((ushort)bVar2 < *(ushort *)(uVar1 + 0x36)) && ((*(uint *)(uVar1 + 0x44) & 0x800) != 0)) {

      *(byte *)(param_2 + 0x17) = bVar2;

      bVar2 = bVar2 + 1;

      param_2[0x16] = 1;

    }

    if (((ushort)bVar2 < *(ushort *)(uVar1 + 0x36)) && ((*(uint *)(uVar1 + 0x44) & 0x1000) != 0)) {

      *(byte *)(param_2 + 0x19) = bVar2;

      bVar2 = bVar2 + 1;

      param_2[0x18] = 1;

    }

    if (((ushort)bVar2 < *(ushort *)(uVar1 + 0x36)) && ((*(uint *)(uVar1 + 0x44) & 0x2000) != 0)) {

      *(byte *)(param_2 + 0x1b) = bVar2;

      bVar2 = bVar2 + 1;

      param_2[0x1a] = 1;

    }

    if (((ushort)bVar2 < *(ushort *)(uVar1 + 0x36)) && ((*(uint *)(uVar1 + 0x44) & 0x4000) != 0)) {

      *(byte *)(param_2 + 0x1d) = bVar2;

      bVar2 = bVar2 + 1;

      param_2[0x1c] = 1;

    }

    if (((ushort)bVar2 < *(ushort *)(uVar1 + 0x36)) && ((*(uint *)(uVar1 + 0x44) & 0x8000) != 0)) {

      *(byte *)(param_2 + 0x1f) = bVar2;

      bVar2 = bVar2 + 1;

      param_2[0x1e] = 1;

    }

    if (((ushort)bVar2 < *(ushort *)(uVar1 + 0x36)) && ((*(uint *)(uVar1 + 0x44) & 0x10000) != 0)) {

      *(byte *)(param_2 + 0x2b) = bVar2;

      bVar2 = bVar2 + 1;

      param_2[0x2a] = 1;

    }

    if (((ushort)bVar2 < *(ushort *)(uVar1 + 0x36)) && ((*(uint *)(uVar1 + 0x44) & 0x20000) != 0)) {

      *(byte *)(param_2 + 0x2d) = bVar2;

      bVar2 = bVar2 + 1;

      param_2[0x2c] = 1;

    }

    if (((ushort)bVar2 < *(ushort *)(uVar1 + 0x36)) && ((*(uint *)(uVar1 + 0x44) & 0x40000) != 0)) {

      *(byte *)(param_2 + 0x2f) = bVar2;

      bVar2 = bVar2 + 1;

      param_2[0x2e] = 1;

    }

    if (((ushort)bVar2 < *(ushort *)(uVar1 + 0x36)) && ((*(uint *)(uVar1 + 0x44) & 0x80000) != 0)) {

      *(byte *)(param_2 + 0x31) = bVar2;

      bVar2 = bVar2 + 1;

      param_2[0x30] = 1;

    }

    if (((ushort)bVar2 < *(ushort *)(uVar1 + 0x36)) && ((*(uint *)(uVar1 + 0x44) & 0x100000) != 0))

    {

      *(byte *)(param_2 + 0x3f) = bVar2;

      bVar2 = bVar2 + 1;

      param_2[0x3e] = 1;

    }

    if (((ushort)bVar2 < *(ushort *)(uVar1 + 0x36)) && ((*(uint *)(uVar1 + 0x44) & 0x200000) != 0))

    {

      *(byte *)(param_2 + 0x21) = bVar2;

      bVar2 = bVar2 + 1;

      param_2[0x20] = 1;

    }

    if (((ushort)bVar2 < *(ushort *)(uVar1 + 0x36)) && ((*(uint *)(uVar1 + 0x44) & 0x400000) != 0))

    {

      *(byte *)(param_2 + 0x23) = bVar2;

      bVar2 = bVar2 + 1;

      param_2[0x22] = 1;

    }

    if (((ushort)bVar2 < *(ushort *)(uVar1 + 0x36)) && ((*(uint *)(uVar1 + 0x44) & 0x800000) != 0))

    {

      *(byte *)(param_2 + 0x25) = bVar2;

      bVar2 = bVar2 + 1;

      param_2[0x24] = 1;

    }

    if (((ushort)bVar2 < *(ushort *)(uVar1 + 0x36)) && ((*(uint *)(uVar1 + 0x44) & 0x1000000) != 0))

    {

      *(byte *)(param_2 + 0x27) = bVar2;

      bVar2 = bVar2 + 1;

      param_2[0x26] = 1;

    }

    if (((ushort)bVar2 < *(ushort *)(uVar1 + 0x36)) && ((*(uint *)(uVar1 + 0x44) & 0x2000000) != 0))

    {

      param_2[0x28] = 1;

      *(byte *)(param_2 + 0x29) = bVar2;

    }

    if ((*(short *)(uVar1 + 0x34) != 0) && ((*(byte *)(uVar1 + 0x48) & 1) != 0)) {

      *(undefined1 *)(param_2 + 0x33) = 0;

      bVar3 = 1;

      param_2[0x32] = 2;

    }

    if (((ushort)bVar3 < *(ushort *)(uVar1 + 0x34)) && ((*(byte *)(uVar1 + 0x48) & 2) != 0)) {

      *(byte *)(param_2 + 0x35) = bVar3;

      bVar3 = bVar3 + 1;

      param_2[0x34] = 2;

    }

    if (((ushort)bVar3 < *(ushort *)(uVar1 + 0x34)) && ((*(byte *)(uVar1 + 0x48) & 4) != 0)) {

      *(byte *)(param_2 + 0x37) = bVar3;

      bVar3 = bVar3 + 1;

      param_2[0x36] = 2;

    }

    if (((ushort)bVar3 < *(ushort *)(uVar1 + 0x34)) && ((*(byte *)(uVar1 + 0x48) & 8) != 0)) {

      *(byte *)(param_2 + 0x39) = bVar3;

      bVar3 = bVar3 + 1;

      param_2[0x38] = 2;

    }

    if (((ushort)bVar3 < *(ushort *)(uVar1 + 0x34)) && ((*(byte *)(uVar1 + 0x48) & 0x10) != 0)) {

      *(byte *)(param_2 + 0x3b) = bVar3;

      bVar3 = bVar3 + 1;

      param_2[0x3a] = 2;

    }

    if (((ushort)bVar3 < *(ushort *)(uVar1 + 0x34)) && ((*(byte *)(uVar1 + 0x48) & 0x20) != 0)) {

      param_2[0x3c] = 2;

      *(byte *)(param_2 + 0x3d) = bVar3;

    }

    return 1;

  }

  return uVar1 & 0xffffffffffffff00;

}




