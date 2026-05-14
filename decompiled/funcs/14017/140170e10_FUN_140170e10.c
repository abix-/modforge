// Address: 0x140170e10
// Ghidra name: FUN_140170e10
// ============ 0x140170e10 FUN_140170e10 (size=244) ============


void FUN_140170e10(longlong param_1,float *param_2,char param_3)



{

  bool bVar1;

  undefined4 uVar2;

  float fVar3;

  float fVar4;

  

  fVar3 = *param_2;

  if (*param_2 <= DAT_14039ca44) {

    fVar3 = DAT_14039ca44;

  }

  fVar4 = param_2[1];

  if (param_2[1] <= DAT_14039ca44) {

    fVar4 = DAT_14039ca44;

  }

  if ((*(float *)(param_1 + 0xf4) != fVar4) || (*(float *)(param_1 + 0xf0) != fVar3)) {

    uVar2 = FUN_14016ea50();

    FUN_1401752f0(uVar2,"SDL.window.HDR_headroom",fVar4);

    FUN_1401752f0(uVar2,"SDL.window.SDR_white_level",fVar3);

    bVar1 = DAT_14039ca44 < fVar4;

    FUN_140175280(uVar2,"SDL.window.HDR_enabled",bVar1);

    *(ulonglong *)(param_1 + 0xf0) = CONCAT44(fVar4,fVar3);

    if (param_3 != '\0') {

      FUN_1401cda90(param_1,0x21a,bVar1,0);

    }

  }

  return;

}




