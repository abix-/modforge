// Address: 0x1402f1940
// Ghidra name: FUN_1402f1940
// ============ 0x1402f1940 FUN_1402f1940 (size=127) ============


uint FUN_1402f1940(uint *param_1,short param_2)



{

  uint uVar1;

  int iVar2;

  uint uVar3;

  uint uVar4;

  

  uVar1 = *param_1;

  uVar4 = uVar1 >> 0x17 & 0xff;

  if (uVar4 == 0xff) {

    return (uint)(ushort)(((uVar1 & 0x7fffff) != 0) + 1);

  }

  if ((((char)(uVar1 >> 0x17) != '\0') || ((uVar1 & 0x7fffffff) != 0)) &&

     (iVar2 = (0x96 - param_2) - uVar4, 0 < iVar2)) {

    if (0x17 < iVar2) {

      *param_1 = uVar1 & 0x80000000;

      return 0xffffffff;

    }

    uVar3 = (1 << ((byte)iVar2 & 0x1f)) - 1;

    uVar4 = ~uVar3 & uVar1;

    *param_1 = uVar4;

    return CONCAT22((short)(uVar4 >> 0x10),-(ushort)((uVar1 & uVar3) != 0));

  }

  return 0;

}




