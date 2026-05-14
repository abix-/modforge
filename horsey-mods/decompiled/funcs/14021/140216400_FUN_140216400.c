// Address: 0x140216400
// Ghidra name: FUN_140216400
// ============ 0x140216400 FUN_140216400 (size=318) ============


bool FUN_140216400(void)



{

  longlong lVar1;

  longlong lVar2;

  longlong lVar3;

  longlong lVar4;

  bool bVar5;

  

  FUN_140216960();

  DAT_1403fdaf8 = FUN_1401885b0("DSOUND.DLL");

  if (DAT_1403fdaf8 == 0) {

    FUN_14012e850("DirectSound: failed to load DSOUND.DLL");

    FUN_140216960();

    return false;

  }

  lVar1 = FUN_140188550(DAT_1403fdaf8,"DirectSoundCreate8");

  DAT_1403fdb00 = lVar1;

  lVar2 = FUN_140188550(DAT_1403fdaf8,"DirectSoundEnumerateW");

  DAT_1403fdb08 = lVar2;

  lVar3 = FUN_140188550(DAT_1403fdaf8,"DirectSoundCaptureCreate8");

  DAT_1403fdb10 = lVar3;

  lVar4 = FUN_140188550(DAT_1403fdaf8,"DirectSoundCaptureEnumerateW");

  DAT_1403fdb18 = lVar4;

  DAT_1403fdb20 = FUN_140188550(DAT_1403fdaf8,"GetDeviceID");

  bVar5 = DAT_1403fdb20 != 0;

  if (!bVar5 || (lVar4 == 0 || (lVar3 == 0 || (lVar2 == 0 || lVar1 == 0)))) {

    FUN_14012e850("DirectSound: System doesn\'t appear to have DX8.");

    FUN_140216960();

  }

  return bVar5 && (lVar4 != 0 && (lVar3 != 0 && (lVar2 != 0 && lVar1 != 0)));

}




