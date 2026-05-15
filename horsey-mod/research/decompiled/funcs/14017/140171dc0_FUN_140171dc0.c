// Address: 0x140171dc0
// Ghidra name: FUN_140171dc0
// ============ 0x140171dc0 FUN_140171dc0 (size=224) ============


bool FUN_140171dc0(longlong param_1,float param_2)



{

  code *pcVar1;

  longlong lVar2;

  char cVar3;

  float fVar4;

  

  if (DAT_1403fc410 == 0) {

    FUN_1401730c0();

    return false;

  }

  if ((param_1 == 0) ||

     ((DAT_1403e3d60 != '\0' && (cVar3 = FUN_1401aa7c0(param_1,1), cVar3 == '\0')))) {

    FUN_14012e850("Invalid window");

    return false;

  }

  lVar2 = DAT_1403fc410;

  if ((*(uint *)(param_1 + 0x48) & 0xc0000) != 0) {

    FUN_14012e850("Operation invalid on popup windows");

    return false;

  }

  fVar4 = 0.0;

  if ((0.0 <= param_2) && (fVar4 = DAT_14039ca44, param_2 <= DAT_14039ca44)) {

    fVar4 = param_2;

  }

  *(float *)(param_1 + 0x174) = fVar4;

  pcVar1 = *(code **)(lVar2 + 0x178);

  if (pcVar1 == (code *)0x0) {

    return true;

  }

  cVar3 = (*pcVar1)(lVar2,param_1);

  return cVar3 != '\0';

}




