// Address: 0x140269080
// Ghidra name: FUN_140269080
// ============ 0x140269080 FUN_140269080 (size=167) ============


int FUN_140269080(longlong param_1,int param_2,int param_3,short param_4)



{

  longlong lVar1;

  float fVar2;

  undefined4 uVar3;

  undefined4 uVar4;

  

  lVar1 = (longlong)param_3 + (longlong)param_2 * 2;

  param_4 = param_4 - *(short *)(param_1 + 0x11e + lVar1 * 6);

  if (param_4 < 0) {

    if (param_4 < *(short *)(param_1 + 0x136 + lVar1 * 4)) {

      *(short *)(param_1 + 0x136 + lVar1 * 4) = param_4;

    }

    uVar4 = 0;

    uVar3 = DAT_14037dea8;

  }

  else {

    lVar1 = (longlong)param_3 + (longlong)param_2 * 2;

    if (*(short *)(param_1 + 0x138 + lVar1 * 4) < param_4) {

      *(short *)(param_1 + 0x138 + lVar1 * 4) = param_4;

    }

    uVar3 = 0;

    uVar4 = DAT_1403053f0;

  }

  fVar2 = (float)FUN_140208370(param_1,lVar1,param_3,uVar3,uVar4);

  return (int)fVar2;

}




