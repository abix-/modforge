// Address: 0x140230c10
// Ghidra name: FUN_140230c10
// ============ 0x140230c10 FUN_140230c10 (size=136) ============


undefined8 FUN_140230c10(char *param_1,undefined4 *param_2,uint *param_3)



{

  ushort uVar1;

  int iVar2;

  undefined8 uVar3;

  uint uVar4;

  undefined **ppuVar5;

  

  ppuVar5 = &PTR_DAT_140358080;

  uVar4 = 0;

  do {

    iVar2 = strcmp(*ppuVar5,param_1);

    if (iVar2 == 0) {

      *param_2 = (&DAT_140358088)[(longlong)(int)uVar4 * 4];

      uVar1 = (&DAT_14035808c)[(longlong)(int)uVar4 * 8];

      *param_3 = (uint)uVar1;

      return CONCAT71((uint7)(byte)(uVar1 >> 8),1);

    }

    uVar4 = uVar4 + 1;

    ppuVar5 = ppuVar5 + 2;

  } while (uVar4 < 4);

  uVar3 = FUN_14012e850("Invalid file open mode");

  return uVar3;

}




