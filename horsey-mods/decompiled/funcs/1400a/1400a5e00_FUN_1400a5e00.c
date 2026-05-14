// Address: 0x1400a5e00
// Ghidra name: FUN_1400a5e00
// ============ 0x1400a5e00 FUN_1400a5e00 (size=215) ============


int FUN_1400a5e00(longlong param_1,int param_2)



{

  uint uVar1;

  longlong lVar2;

  uint uVar3;

  uint uVar4;

  

  lVar2 = (longlong)param_2;

  if ((&DAT_1403ee4a0)[lVar2 * 8] != param_2) {

    FUN_1400c4340("Bad GXI %d");

  }

  uVar4 = (int)*(char *)(lVar2 + param_1) & 0x80000003;

  if ((int)uVar4 < 0) {

    uVar4 = (uVar4 - 1 | 0xfffffffc) + 1;

  }

  uVar3 = (int)*(char *)(lVar2 + 0xf0 + param_1) & 0x80000003;

  if ((int)uVar3 < 0) {

    uVar3 = (uVar3 - 1 | 0xfffffffc) + 1;

  }

  uVar1 = uVar4;

  if ((int)uVar4 < (int)uVar3) {

    uVar1 = uVar3;

  }

  if ((int)uVar4 < (int)uVar3) {

    uVar3 = uVar4;

  }

  return ((int)(float)(&DAT_1403ee4b0)[(longlong)(int)uVar1 + lVar2 * 8] *

          (100 - (&DAT_1403ee4a4)[lVar2 * 8]) +

         (int)(float)(&DAT_1403ee4b0)[(longlong)(int)uVar3 + lVar2 * 8] *

         (&DAT_1403ee4a4)[lVar2 * 8]) / 100;

}




