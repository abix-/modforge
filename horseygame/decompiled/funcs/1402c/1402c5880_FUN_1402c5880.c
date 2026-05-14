// Address: 0x1402c5880
// Ghidra name: FUN_1402c5880
// ============ 0x1402c5880 FUN_1402c5880 (size=39) ============


uint FUN_1402c5880(byte *param_1,int param_2)



{

  byte bVar1;

  uint uVar2;

  byte bVar3;

  uint uVar4;

  

  uVar4 = 0;

  uVar2 = uVar4;

  for (; param_2 != 0; param_2 = param_2 + -1) {

    bVar1 = *param_1;

    param_1 = param_1 + 1;

    bVar3 = (byte)uVar4;

    uVar4 = uVar4 + 8;

    uVar2 = uVar2 | (uint)bVar1 << (bVar3 & 0x1f);

  }

  return uVar2;

}




