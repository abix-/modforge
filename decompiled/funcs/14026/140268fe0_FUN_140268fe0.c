// Address: 0x140268fe0
// Ghidra name: FUN_140268fe0
// ============ 0x140268fe0 FUN_140268fe0 (size=159) ============


int FUN_140268fe0(longlong param_1,int param_2,int param_3,short param_4)



{

  longlong lVar1;

  float fVar2;

  undefined4 uVar3;

  undefined4 uVar4;

  

  param_4 = param_4 + -0x8000;

  lVar1 = (longlong)param_3 + (longlong)param_2 * 2;

  if (param_4 < 0) {

    if (param_4 < *(short *)(param_1 + 0x146 + lVar1 * 4)) {

      *(short *)(param_1 + 0x146 + lVar1 * 4) = param_4;

    }

    uVar4 = 0;

    uVar3 = DAT_14037dea8;

  }

  else {

    if (*(short *)(param_1 + 0x148 + lVar1 * 4) < param_4) {

      *(short *)(param_1 + 0x148 + lVar1 * 4) = param_4;

    }

    uVar3 = 0;

    uVar4 = DAT_1403053f0;

  }

  fVar2 = (float)FUN_140208370(param_1,lVar1,param_3,uVar3,uVar4);

  return (int)fVar2;

}




