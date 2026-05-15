// Address: 0x14027b8c0
// Ghidra name: FUN_14027b8c0
// ============ 0x14027b8c0 FUN_14027b8c0 (size=72) ============


int FUN_14027b8c0(byte *param_1,int param_2,uint *param_3)



{

  uint uVar1;

  byte bVar2;

  uint uVar3;

  

  uVar3 = 0;

  uVar1 = 0;

  bVar2 = 0;

  do {

    if ((param_2 <= (int)uVar1) ||

       (uVar3 = uVar3 | (*param_1 & 0x7f) << (bVar2 & 0x1f), -1 < (char)*param_1)) break;

    uVar1 = uVar1 + 1;

    bVar2 = bVar2 + 7;

    param_1 = param_1 + 1;

  } while (uVar1 < 4);

  *param_3 = uVar3;

  return uVar1 + 1;

}




