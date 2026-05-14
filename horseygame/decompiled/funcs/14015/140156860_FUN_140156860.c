// Address: 0x140156860
// Ghidra name: FUN_140156860
// ============ 0x140156860 FUN_140156860 (size=242) ============


void FUN_140156860(longlong param_1)



{

  float fVar1;

  int iVar2;

  int iVar3;

  undefined4 uVar4;

  float fVar5;

  

  iVar2 = FUN_14016ea50(*(undefined8 *)(param_1 + 0x118));

  if ((iVar2 != 0) && (iVar3 = FUN_14014f090(param_1), fVar1 = DAT_14039ca44, iVar3 != 0)) {

    if (*(int *)(param_1 + 0x208) == 0x12000500) {

      uVar4 = FUN_140174af0(iVar2,"SDL.window.SDR_white_level",DAT_14039ca44);

      *(undefined4 *)(param_1 + 0x20c) = uVar4;

      fVar5 = (float)FUN_140174af0(iVar2,"SDL.window.HDR_headroom",fVar1);

    }

    else {

      *(undefined4 *)(param_1 + 0x20c) = 0x3f800000;

      fVar5 = fVar1;

    }

    *(float *)(param_1 + 0x210) = fVar5;

    FUN_140175280(iVar3,"SDL.renderer.HDR_enabled",fVar1 < fVar5);

    FUN_1401752f0(iVar3,"SDL.renderer.SDR_white_point",*(undefined4 *)(param_1 + 0x20c));

    FUN_1401752f0(iVar3,"SDL.renderer.HDR_headroom",*(undefined4 *)(param_1 + 0x210));

    FUN_140156820(param_1);

  }

  return;

}




