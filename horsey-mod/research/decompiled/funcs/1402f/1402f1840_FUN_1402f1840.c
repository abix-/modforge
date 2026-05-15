// Address: 0x1402f1840
// Ghidra name: FUN_1402f1840
// ============ 0x1402f1840 FUN_1402f1840 (size=154) ============


ulonglong FUN_1402f1840(ulonglong *param_1,short param_2)



{

  ulonglong uVar1;

  ulonglong uVar2;

  int iVar3;

  ulonglong uVar4;

  uint uVar5;

  

  uVar1 = *param_1;

  uVar5 = (uint)(uVar1 >> 0x34) & 0x7ff;

  if (uVar5 == 0x7ff) {

    return (ulonglong)(ushort)(((uVar1 & 0xfffffffffffff) != 0) + 1);

  }

  if (((uVar5 != 0) || ((uVar1 & 0x7fffffffffffffff) != 0)) &&

     (iVar3 = (0x433 - param_2) - uVar5, 0 < iVar3)) {

    if (0x34 < iVar3) {

      *param_1 = uVar1 & 0x8000000000000000;

      return 0xffffffff;

    }

    uVar4 = (1L << ((byte)iVar3 & 0x3f)) - 1;

    uVar2 = ~uVar4 & uVar1;

    *param_1 = uVar2;

    return CONCAT62((int6)(uVar2 >> 0x10),-(ushort)((uVar1 & uVar4) != 0));

  }

  return 0;

}




