// Address: 0x140044ff0
// Ghidra name: FUN_140044ff0
// ============ 0x140044ff0 FUN_140044ff0 (size=177) ============


void FUN_140044ff0(undefined8 param_1,float param_2)



{

  undefined8 uVar1;

  float fVar2;

  undefined4 uVar3;

  

  if (*(int *)(DAT_1403ea2a8 + 0x4c) != 1) {

    FUN_1400450b0(0);

  }

  fVar2 = 0.0;

  if (0.0 <= param_2) {

    fVar2 = param_2;

  }

  if (fVar2 == 0.0) {

    *(undefined4 *)(DAT_1403ea2a8 + 0x4c) = 1;

  }

  else {

    *(undefined4 *)(DAT_1403ea2a8 + 0x4c) = 3;

  }

  *(float *)(DAT_1403ea2a8 + 0x40) = fVar2;

  *(undefined4 *)(DAT_1403ea2a8 + 0x3c) = 0;

  uVar3 = 0;

  if (fVar2 == 0.0) {

    uVar3 = DAT_14039ca44;

  }

  uVar1 = FUN_14004f150(param_1,uVar3);

  *(undefined8 *)(DAT_1403ea2a8 + 0x58) = uVar1;

  *(undefined8 *)(DAT_1403ea2a8 + 0x60) = 0;

  return;

}




