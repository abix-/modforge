// Address: 0x1402f1a00
// Ghidra name: FUN_1402f1a00
// ============ 0x1402f1a00 FUN_1402f1a00 (size=322) ============


uint FUN_1402f1a00(ulonglong *param_1,int param_2)



{

  byte bVar1;

  ushort uVar2;

  int iVar3;

  ulonglong uVar4;

  ulonglong uVar5;

  ulonglong uVar6;

  ulonglong uVar7;

  

  uVar5 = *param_1;

  uVar2 = (ushort)(uVar5 >> 0x34) & 0x7ff;

  if (uVar2 == 0x7ff) {

    return (uint)(ushort)(((uVar5 & 0xfffffffffffff) != 0) + 1);

  }

  if (uVar2 == 0) {

    if ((uVar5 & 0xfffffffffffff) == 0) {

      return 0;

    }

    uVar2 = FUN_1402f7fe0();

    uVar5 = *param_1;

  }

  iVar3 = (int)(short)uVar2;

  if ((0 < param_2) && (0x7ff - iVar3 <= param_2)) {

    *param_1 = uVar5 & 0xfff0000000000000 | 0x7ff0000000000000;

    return 1;

  }

  if (-iVar3 < param_2) {

    *param_1 = (longlong)(iVar3 + param_2) << 0x34 | uVar5 & 0x800fffffffffffff;

    return 0xffffffff;

  }

  iVar3 = param_2 + -1 + iVar3;

  uVar4 = uVar5 & 0x8000000000000000;

  if ((-0x36 < iVar3) && (iVar3 < 0)) {

    uVar5 = uVar5 & 0xfffffffffffff | 0x10000000000000;

    bVar1 = (byte)-(short)iVar3;

    uVar7 = uVar5 << (0x40 - bVar1 & 0x3f);

    uVar5 = uVar5 >> (bVar1 & 0x3f);

    uVar6 = uVar5 | uVar4;

    if ((0x8000000000000000 < uVar7) || ((uVar7 == 0x8000000000000000 && ((uVar5 & 1) != 0)))) {

      uVar6 = uVar6 + 1;

    }

    *param_1 = uVar6;

    return CONCAT22((short)-(short)iVar3 >> 0xf,-(ushort)(uVar6 != uVar4));

  }

  *param_1 = uVar4;

  return 0;

}




