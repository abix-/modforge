// Address: 0x1401df290
// Ghidra name: FUN_1401df290
// ============ 0x1401df290 FUN_1401df290 (size=584) ============


void FUN_1401df290(undefined8 param_1,int param_2)



{

  if (param_2 < -0x7789f7e7) {

    if (param_2 == -0x7789f7e8) {

      FUN_14012e850("%s: %s",param_1,"WRONGTEXTUREFORMAT");

      return;

    }

    if (param_2 == -0x7789fe84) {

      FUN_14012e850("%s: %s",param_1,"OUTOFVIDEOMEMORY");

      return;

    }

    if (param_2 == -0x7789fde4) {

      FUN_14012e850("%s: %s",param_1,"WASSTILLDRAWING");

      return;

    }

  }

  else {

    switch(param_2) {

    case -0x7789f7e7:

      FUN_14012e850("%s: %s",param_1,"UNSUPPORTEDCOLOROPERATION");

      return;

    case -0x7789f7e6:

      FUN_14012e850("%s: %s",param_1,"UNSUPPORTEDCOLORARG");

      return;

    case -0x7789f7e5:

      FUN_14012e850("%s: %s",param_1,"UNSUPPORTEDALPHAOPERATION");

      return;

    case -0x7789f7e4:

      FUN_14012e850("%s: %s",param_1,"UNSUPPORTEDALPHAARG");

      return;

    case -0x7789f7e3:

      FUN_14012e850("%s: %s",param_1,"TOOMANYOPERATIONS");

      return;

    case -0x7789f7e2:

      FUN_14012e850("%s: %s",param_1,"CONFLICTINGTEXTUREFILTER");

      return;

    case -0x7789f7e1:

      FUN_14012e850("%s: %s",param_1,"UNSUPPORTEDFACTORVALUE");

      return;

    case -0x7789f7df:

      FUN_14012e850("%s: %s",param_1,"CONFLICTINGRENDERSTATE");

      return;

    case -0x7789f7de:

      FUN_14012e850("%s: %s",param_1,"UNSUPPORTEDTEXTUREFILTER");

      return;

    case -0x7789f7da:

      FUN_14012e850("%s: %s",param_1,"CONFLICTINGTEXTUREPALETTE");

      return;

    case -0x7789f7d9:

      FUN_14012e850("%s: %s",param_1,"DRIVERINTERNALERROR");

      return;

    case -0x7789f79a:

      FUN_14012e850("%s: %s",param_1,"NOTFOUND");

      return;

    case -0x7789f799:

      FUN_14012e850("%s: %s",param_1,"MOREDATA");

      return;

    case -0x7789f798:

      FUN_14012e850("%s: %s",param_1,"DEVICELOST");

      return;

    case -0x7789f797:

      FUN_14012e850("%s: %s",param_1,"DEVICENOTRESET");

      return;

    case -0x7789f796:

      FUN_14012e850("%s: %s",param_1,"NOTAVAILABLE");

      return;

    case -0x7789f795:

      FUN_14012e850("%s: %s",param_1,"INVALIDDEVICE");

      return;

    case -0x7789f794:

      FUN_14012e850("%s: %s",param_1,"INVALIDCALL");

      return;

    case -0x7789f793:

      FUN_14012e850("%s: %s",param_1,"DRIVERINVALIDCALL");

      return;

    }

  }

  FUN_14012e850("%s: %s",param_1,"UNKNOWN");

  return;

}




