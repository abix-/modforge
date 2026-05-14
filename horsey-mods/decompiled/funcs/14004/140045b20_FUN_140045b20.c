// Address: 0x140045b20
// Ghidra name: FUN_140045b20
// ============ 0x140045b20 FUN_140045b20 (size=55) ============


void FUN_140045b20(undefined8 param_1,float param_2)



{

  longlong lVar1;

  float fVar2;

  float fVar3;

  

  fVar2 = 0.0;

  if (0.0 <= param_2) {

    fVar2 = param_2;

  }

  fVar3 = DAT_14039ca44;

  if (fVar2 <= DAT_14039ca44) {

    fVar3 = fVar2;

  }

  fVar2 = DAT_14039ca44;

  lVar1 = FUN_14004f010();

  if (lVar1 != 0) {

    *(float *)(lVar1 + 0x14) = fVar3;

    *(float *)(lVar1 + 0x10) = fVar2 - fVar3;

  }

  return;

}




