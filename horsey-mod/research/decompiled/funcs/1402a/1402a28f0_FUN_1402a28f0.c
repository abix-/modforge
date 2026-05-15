// Address: 0x1402a28f0
// Ghidra name: FUN_1402a28f0
// ============ 0x1402a28f0 FUN_1402a28f0 (size=220) ============


uint FUN_1402a28f0(uint param_1)



{

  ushort uVar1;

  uint uVar3;

  int iVar4;

  uint uVar2;

  

  uVar1 = (ushort)(param_1 >> 0x10) & 0x8000;

  uVar2 = (uint)uVar1;

  if ((param_1 & 0x7f800000) == 0x7f800000) {

    if ((param_1 & 0x7fffffff) != 0x7f800000) {

      return (uint)(ushort)((ushort)(param_1 >> 0xd) & 0x1ff | 0x7e00 | uVar1);

    }

  }

  else {

    if ((param_1 & 0x7f800000) < 0x33000000) goto LAB_1402a292b;

    iVar4 = (param_1 >> 0x17 & 0xff) - 0x7f;

    if (iVar4 < 0x10) {

      uVar3 = param_1 & 0x7fffff | 0x800000;

      if (iVar4 < -0xe) {

        uVar2 = (uint)(ushort)(uVar1 | (ushort)(uVar3 >> (~(byte)iVar4 & 0x1f)));

        param_1 = uVar3 << ((char)(param_1 >> 0x17) + 0xa2U & 0x1f);

      }

      else {

        param_1 = param_1 << 0x13;

        iVar4 = (uint)(ushort)((short)iVar4 + 0xe) * 0x400;

        uVar2 = CONCAT22((short)((uint)iVar4 >> 0x10),

                         (short)iVar4 + ((ushort)(uVar3 >> 0xd) | uVar1));

      }

      if ((0x80000000 < param_1) || ((param_1 == 0x80000000 && ((uVar2 & 1) != 0)))) {

        return uVar2 + 1;

      }

      goto LAB_1402a292b;

    }

  }

  uVar2 = (uint)(uVar1 | 0x7c00);

LAB_1402a292b:

  return uVar2 & 0xffff;

}




