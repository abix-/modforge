// Address: 0x140276c60
// Ghidra name: FUN_140276c60
// ============ 0x140276c60 FUN_140276c60 (size=79) ============


ulonglong FUN_140276c60(float param_1,float param_2,float param_3,undefined8 param_4,float param_5)



{

  float fVar1;

  float fVar2;

  float fVar3;

  undefined4 uVar4;

  

  uVar4 = (undefined4)((ulonglong)param_4 >> 0x20);

  fVar3 = (float)param_4;

  if (param_2 != param_3) {

    fVar1 = (param_1 - param_2) / (param_3 - param_2);

    fVar2 = 0.0;

    if (0.0 <= fVar1) {

      fVar2 = fVar1;

    }

    fVar1 = DAT_14039ca44;

    if (fVar2 <= DAT_14039ca44) {

      fVar1 = fVar2;

    }

    return (ulonglong)(uint)(fVar1 * (param_5 - fVar3) + fVar3);

  }

  if (0.0 <= param_1 - param_3) {

    uVar4 = 0;

    fVar3 = param_5;

  }

  return CONCAT44(uVar4,fVar3);

}




