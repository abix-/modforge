// Address: 0x140130020
// Ghidra name: FUN_140130020
// ============ 0x140130020 FUN_140130020 (size=125) ============


uint FUN_140130020(longlong *param_1)



{

  ushort uVar1;

  ushort uVar2;

  ushort *puVar3;

  uint uVar4;

  

  puVar3 = (ushort *)*param_1;

  uVar1 = *puVar3;

  uVar4 = (uint)uVar1;

  if (uVar1 == 0) {

    return 0;

  }

  if (0x3ff < uVar1 - 0xdc00) {

    if (0x3ff < uVar1 - 0xd800) goto LAB_14013008d;

    uVar2 = puVar3[1];

    if ((uVar2 != 0) && (uVar4 = uVar2 - 0xdc00, uVar4 < 0x400)) {

      *param_1 = (longlong)(puVar3 + 2);

      uVar4 = ((uVar1 - 0xd800) * 0x400 | uVar4) + 0x10000;

      if (0x10ffff < uVar4) {

        uVar4 = 0xfffd;

      }

      return uVar4;

    }

  }

  uVar4 = 0xfffd;

LAB_14013008d:

  *param_1 = (longlong)(puVar3 + 1);

  if (0x10ffff < uVar4) {

    uVar4 = 0xfffd;

  }

  return uVar4;

}




