// Address: 0x1402304f0
// Ghidra name: FUN_1402304f0
// ============ 0x1402304f0 FUN_1402304f0 (size=421) ============


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



bool FUN_1402304f0(void)



{

  DAT_1403fdd50 = FUN_140188550(DAT_1403fdd40,"QueryIoRingCapabilities");

  if (DAT_1403fdd50 != 0) {

    DAT_1403fdd58 = FUN_140188550(DAT_1403fdd40,"IsIoRingOpSupported");

    if (DAT_1403fdd58 != 0) {

      DAT_1403fdd60 = FUN_140188550(DAT_1403fdd40,"CreateIoRing");

      if (DAT_1403fdd60 != 0) {

        _DAT_1403fdd68 = FUN_140188550(DAT_1403fdd40,"GetIoRingInfo");

        if (_DAT_1403fdd68 != 0) {

          DAT_1403fdd70 = FUN_140188550(DAT_1403fdd40,"SubmitIoRing");

          if (DAT_1403fdd70 != 0) {

            DAT_1403fdd78 = FUN_140188550(DAT_1403fdd40,"CloseIoRing");

            if (DAT_1403fdd78 != 0) {

              DAT_1403fdd80 = FUN_140188550(DAT_1403fdd40,"PopIoRingCompletion");

              if (DAT_1403fdd80 != 0) {

                DAT_1403fdd88 = FUN_140188550(DAT_1403fdd40,"SetIoRingCompletionEvent");

                if (DAT_1403fdd88 != 0) {

                  DAT_1403fdd90 = FUN_140188550(DAT_1403fdd40,"BuildIoRingCancelRequest");

                  if (DAT_1403fdd90 != 0) {

                    DAT_1403fdd98 = FUN_140188550(DAT_1403fdd40,"BuildIoRingReadFile");

                    if (DAT_1403fdd98 != 0) {

                      DAT_1403fdda0 = FUN_140188550(DAT_1403fdd40,"BuildIoRingWriteFile");

                      if (DAT_1403fdda0 != 0) {

                        DAT_1403fdda8 = FUN_140188550(DAT_1403fdd40,"BuildIoRingFlushFile");

                        return DAT_1403fdda8 != 0;

                      }

                    }

                  }

                }

              }

            }

          }

        }

      }

    }

  }

  return false;

}




