// Address: 0x140045af0
// Ghidra name: FUN_140045af0
// ============ 0x140045af0 FUN_140045af0 (size=31) ============


void FUN_140045af0(undefined8 param_1,float param_2)



{

  longlong lVar1;

  float fVar2;

  

  lVar1 = FUN_14004f010();

  if (lVar1 != 0) {

    fVar2 = 0.0;

    if (0.0 <= param_2) {

      fVar2 = param_2;

    }

    *(float *)(lVar1 + 0xc) = fVar2;

  }

  return;

}




