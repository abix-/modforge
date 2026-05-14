// Address: 0x1402f1b50
// Ghidra name: FUN_1402f1b50
// ============ 0x1402f1b50 FUN_1402f1b50 (size=328) ============


uint FUN_1402f1b50(uint *param_1,int param_2)



{

  byte bVar1;

  ushort uVar2;

  int iVar3;

  uint uVar4;

  uint uVar5;

  uint uVar6;

  uint uVar7;

  

  uVar5 = *param_1;

  uVar2 = (ushort)(uVar5 >> 0x17) & 0xff;

  if (uVar2 == 0xff) {

    return (uint)(ushort)(((uVar5 & 0x7fffff) != 0) + 1);

  }

  if (uVar2 == 0) {

    if ((uVar5 & 0x7fffff) == 0) {

      return 0;

    }

    uVar2 = FUN_1402f8060();

    uVar5 = *param_1;

  }

  iVar3 = (int)(short)uVar2;

  if ((0 < param_2) && (0xff - iVar3 <= param_2)) {

    *param_1 = uVar5 & 0xff800000 | 0x7f800000;

    return 1;

  }

  if (-iVar3 < param_2) {

    *param_1 = (iVar3 + param_2) * 0x800000 | uVar5 & 0x807fffff;

    return 0xffffffff;

  }

  uVar4 = uVar5 & 0x80000000;

  iVar3 = param_2 + -1 + iVar3;

  if ((-0x19 < iVar3) && (iVar3 < 0)) {

    uVar5 = uVar5 & 0x7fffff | 0x800000;

    bVar1 = (byte)-(short)iVar3;

    uVar7 = uVar5 << (0x20 - bVar1 & 0x1f);

    uVar5 = uVar5 >> (bVar1 & 0x1f);

    uVar6 = uVar5 | uVar4;

    if ((0x80000000 < uVar7) || ((uVar7 == 0x80000000 && ((uVar5 & 1) != 0)))) {

      uVar6 = uVar6 + 1;

    }

    *param_1 = uVar6;

    return CONCAT22((short)-(short)iVar3 >> 0xf,-(ushort)(uVar6 != uVar4));

  }

  *param_1 = uVar4;

  return 0;

}




