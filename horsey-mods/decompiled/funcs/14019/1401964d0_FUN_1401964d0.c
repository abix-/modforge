// Address: 0x1401964d0
// Ghidra name: FUN_1401964d0
// ============ 0x1401964d0 FUN_1401964d0 (size=788) ============


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



undefined8 FUN_1401964d0(void)



{

  DAT_1403fcce8 = LoadLibraryW(L"hid.dll");

  if (DAT_1403fcce8 != (HMODULE)0x0) {

    DAT_1403fccf0 = LoadLibraryW(L"cfgmgr32.dll");

    if (DAT_1403fccf0 != (HMODULE)0x0) {

      DAT_1403fcc48 = GetProcAddress(DAT_1403fcce8,"HidD_GetHidGuid");

      if (DAT_1403fcc48 != (FARPROC)0x0) {

        DAT_1403fcc50 = GetProcAddress(DAT_1403fcce8,"HidD_GetAttributes");

        if (DAT_1403fcc50 != (FARPROC)0x0) {

          DAT_1403fcc58 = GetProcAddress(DAT_1403fcce8,"HidD_GetSerialNumberString");

          if (DAT_1403fcc58 != (FARPROC)0x0) {

            DAT_1403fcc60 = GetProcAddress(DAT_1403fcce8,"HidD_GetManufacturerString");

            if (DAT_1403fcc60 != (FARPROC)0x0) {

              DAT_1403fcc68 = GetProcAddress(DAT_1403fcce8,"HidD_GetProductString");

              if (DAT_1403fcc68 != (FARPROC)0x0) {

                DAT_1403fcc70 = GetProcAddress(DAT_1403fcce8,"HidD_SetFeature");

                if (DAT_1403fcc70 != (FARPROC)0x0) {

                  _DAT_1403fcc78 = GetProcAddress(DAT_1403fcce8,"HidD_GetFeature");

                  if (_DAT_1403fcc78 != (FARPROC)0x0) {

                    _DAT_1403fcc80 = GetProcAddress(DAT_1403fcce8,"HidD_GetInputReport");

                    if (_DAT_1403fcc80 != (FARPROC)0x0) {

                      DAT_1403fcc88 = GetProcAddress(DAT_1403fcce8,"HidD_GetIndexedString");

                      if (DAT_1403fcc88 != (FARPROC)0x0) {

                        DAT_1403fcc90 = GetProcAddress(DAT_1403fcce8,"HidD_GetPreparsedData");

                        if (DAT_1403fcc90 != (FARPROC)0x0) {

                          DAT_1403fcc98 = GetProcAddress(DAT_1403fcce8,"HidD_FreePreparsedData");

                          if (DAT_1403fcc98 != (FARPROC)0x0) {

                            DAT_1403fcca0 = GetProcAddress(DAT_1403fcce8,"HidP_GetCaps");

                            if (DAT_1403fcca0 != (FARPROC)0x0) {

                              DAT_1403fcca8 =

                                   GetProcAddress(DAT_1403fcce8,"HidD_SetNumInputBuffers");

                              if (DAT_1403fcca8 != (FARPROC)0x0) {

                                DAT_1403fccb0 = GetProcAddress(DAT_1403fcce8,"HidD_SetOutputReport")

                                ;

                                if (DAT_1403fccb0 != (FARPROC)0x0) {

                                  DAT_1403fccb8 = GetProcAddress(DAT_1403fccf0,"CM_Locate_DevNodeW")

                                  ;

                                  if (DAT_1403fccb8 != (FARPROC)0x0) {

                                    DAT_1403fccc0 = GetProcAddress(DAT_1403fccf0,"CM_Get_Parent");

                                    if (DAT_1403fccc0 != (FARPROC)0x0) {

                                      DAT_1403fccc8 =

                                           GetProcAddress(DAT_1403fccf0,"CM_Get_DevNode_PropertyW");

                                      if (DAT_1403fccc8 != (FARPROC)0x0) {

                                        DAT_1403fccd0 =

                                             GetProcAddress(DAT_1403fccf0,

                                                            "CM_Get_Device_Interface_PropertyW");

                                        if (DAT_1403fccd0 != (FARPROC)0x0) {

                                          DAT_1403fccd8 =

                                               GetProcAddress(DAT_1403fccf0,

                                                              "CM_Get_Device_Interface_List_SizeW");

                                          if (DAT_1403fccd8 != (FARPROC)0x0) {

                                            DAT_1403fcce0 =

                                                 GetProcAddress(DAT_1403fccf0,

                                                                "CM_Get_Device_Interface_ListW");

                                            if (DAT_1403fcce0 != (FARPROC)0x0) {

                                              return 0;

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

  FUN_1401957b0();

  return 0xffffffff;

}




