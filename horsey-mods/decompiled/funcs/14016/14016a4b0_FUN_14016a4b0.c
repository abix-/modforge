// Address: 0x14016a4b0
// Ghidra name: FUN_14016a4b0
// ============ 0x14016a4b0 FUN_14016a4b0 (size=111) ============


void FUN_14016a4b0(longlong param_1)



{

  float fVar1;

  float fVar2;

  

  if (*(code **)(DAT_1403fc410 + 0x90) == (code *)0x0) {

    fVar2 = (float)FUN_14016e6c0(param_1);

    fVar1 = (float)FUN_14016d370(*(undefined4 *)(param_1 + 100));

    fVar1 = fVar1 * fVar2;

  }

  else {

    fVar1 = (float)(**(code **)(DAT_1403fc410 + 0x90))(DAT_1403fc410,param_1);

  }

  if (fVar1 != *(float *)(param_1 + 0x58)) {

    *(float *)(param_1 + 0x58) = fVar1;

    FUN_1401cda90(param_1,0x214,0,0);

    return;

  }

  return;

}




