// Address: 0x140229f80
// Ghidra name: FUN_140229f80
// ============ 0x140229f80 FUN_140229f80 (size=364) ============


LPSTR FUN_140229f80(UINT param_1,LPSTR param_2,int param_3)



{

  int iVar1;

  LPSTR pCVar2;

  

  switch(param_1) {

  case 1:

    return "CF_TEXT";

  case 2:

    return "CF_BITMAP";

  case 3:

    return "CF_METAFILEPICT";

  case 4:

    return "CF_SYLK";

  case 5:

    return "CF_DIF";

  case 6:

    return "CF_TIFF";

  case 7:

    return "CF_OEMTEXT";

  case 8:

    return "CF_DIB";

  case 9:

    return "CF_PALETTE";

  case 10:

    return "CF_PENDATA";

  case 0xb:

    return "CF_RIFF";

  case 0xc:

    return "CF_WAVE";

  case 0xd:

    return "CF_UNICODETEXT";

  case 0xe:

    return "CF_ENHMETAFILE";

  case 0xf:

    return "CF_HDROP";

  case 0x10:

    return "CF_LOCALE";

  case 0x11:

    return "CF_DIBV5";

  case 0x80:

    return "CF_OWNERDISPLAY";

  case 0x81:

    return "CF_DSPTEXT";

  case 0x82:

    return "CF_DSPBITMAP";

  case 0x83:

    return "CF_DSPMETAFILEPICT";

  case 0x8e:

    return "CF_DSPENHMETAFILE";

  }

  iVar1 = GetClipboardFormatNameA(param_1,param_2,param_3);

  pCVar2 = (LPSTR)0x0;

  if (iVar1 != 0) {

    pCVar2 = param_2;

  }

  return pCVar2;

}




