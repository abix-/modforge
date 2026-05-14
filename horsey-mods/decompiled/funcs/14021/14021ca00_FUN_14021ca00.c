// Address: 0x14021ca00
// Ghidra name: FUN_14021ca00
// ============ 0x14021ca00 FUN_14021ca00 (size=663) ============


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



char * FUN_14021ca00(undefined4 param_1)



{

  int iVar1;

  HMODULE hModule;

  FARPROC pFVar2;

  ulonglong uVar3;

  longlong lVar4;

  char *pcVar5;

  size_t sVar6;

  undefined8 uVar7;

  char *_Str;

  undefined1 *local_res10;

  undefined4 local_228;

  undefined4 uStack_224;

  undefined4 uStack_220;

  undefined4 uStack_21c;

  undefined1 local_218 [528];

  

  hModule = LoadLibraryW(L"Shell32.dll");

  pcVar5 = (char *)0x0;

  _Str = (char *)0x0;

  if ((hModule != (HMODULE)0x0) &&

     (pFVar2 = GetProcAddress(hModule,"SHGetKnownFolderPath"), pFVar2 != (FARPROC)0x0)) {

    switch(param_1) {

    case 0:

      local_228 = _DAT_1403555c0;

      uStack_224 = _UNK_1403555c4;

      uStack_220 = _UNK_1403555c8;

      uStack_21c = _UNK_1403555cc;

      break;

    case 1:

      local_228 = _DAT_1403555d0;

      uStack_224 = _UNK_1403555d4;

      uStack_220 = _UNK_1403555d8;

      uStack_21c = _UNK_1403555dc;

      break;

    case 2:

      local_228 = _DAT_1403555e0;

      uStack_224 = _UNK_1403555e4;

      uStack_220 = _UNK_1403555e8;

      uStack_21c = _UNK_1403555ec;

      break;

    case 3:

      local_228 = _DAT_1403555f0;

      uStack_224 = _UNK_1403555f4;

      uStack_220 = _UNK_1403555f8;

      uStack_21c = _UNK_1403555fc;

      break;

    case 4:

      local_228 = _DAT_140355600;

      uStack_224 = _UNK_140355604;

      uStack_220 = _UNK_140355608;

      uStack_21c = _UNK_14035560c;

      break;

    case 5:

      local_228 = _DAT_140355610;

      uStack_224 = _UNK_140355614;

      uStack_220 = _UNK_140355618;

      uStack_21c = _UNK_14035561c;

      break;

    case 6:

      FUN_14012e850("Public share unavailable on Windows");

      goto LAB_14021cc76;

    case 7:

      local_228 = _DAT_140355620;

      uStack_224 = _UNK_140355624;

      uStack_220 = _UNK_140355628;

      uStack_21c = _UNK_14035562c;

      break;

    case 8:

      local_228 = _DAT_140355630;

      uStack_224 = _UNK_140355634;

      uStack_220 = _UNK_140355638;

      uStack_21c = _UNK_14035563c;

      break;

    case 9:

      local_228 = _DAT_140355640;

      uStack_224 = _UNK_140355644;

      uStack_220 = _UNK_140355648;

      uStack_21c = _UNK_14035564c;

      break;

    case 10:

      local_228 = _DAT_140355650;

      uStack_224 = _UNK_140355654;

      uStack_220 = _UNK_140355658;

      uStack_21c = _UNK_14035565c;

      break;

    default:

      FUN_14012e850("Invalid SDL_Folder: %d",param_1);

      goto LAB_14021cc76;

    }

    uVar3 = (*pFVar2)(&local_228,0x8000,0,&local_res10);

    if (-1 < (int)uVar3) {

      lVar4 = FUN_14012fd40(local_res10);

      goto LAB_14021cbe8;

    }

    FUN_1401a9ef0("Couldn\'t get folder",uVar3 & 0xffffffff);

    goto LAB_14021cc76;

  }

  switch(param_1) {

  case 0:

    uVar7 = 0x8028;

    break;

  case 1:

    uVar7 = 0x8000;

    break;

  case 2:

    uVar7 = 0x8005;

    break;

  case 3:

    FUN_14012e850("Downloads folder unavailable before Vista");

    goto LAB_14021cc71;

  case 4:

    uVar7 = 0x800d;

    break;

  case 5:

    uVar7 = 0x8027;

    break;

  case 6:

    FUN_14012e850("Public share unavailable on Windows");

    goto LAB_14021cc71;

  case 7:

    FUN_14012e850("Saved games unavailable before Vista");

    goto LAB_14021cc71;

  case 8:

    FUN_14012e850("Screenshots folder unavailable before Vista");

    goto LAB_14021cc71;

  case 9:

    uVar7 = 0x8015;

    break;

  case 10:

    uVar7 = 0x800e;

    break;

  default:

    FUN_14012e850("Unsupported SDL_Folder on Windows before Vista: %d",param_1);

    _Str = pcVar5;

    goto LAB_14021cc71;

  }

  iVar1 = SHGetFolderPathW(0,uVar7,0,0,local_218);

  if (iVar1 < 0) {

    FUN_1401a9ef0("Couldn\'t get folder",iVar1);

  }

  else {

    lVar4 = FUN_14012fd40(local_218);

    local_res10 = local_218;

LAB_14021cbe8:

    pcVar5 = (char *)FUN_140197820(&DAT_14039c6f0,"UTF-16LE",local_res10,lVar4 * 2 + 2);

    _Str = (char *)0x0;

    if (pcVar5 != (char *)0x0) {

      sVar6 = strlen(pcVar5);

      _Str = (char *)FUN_140184230(pcVar5,sVar6 + 2);

      if (_Str == (char *)0x0) {

        FUN_1401841e0(pcVar5);

        _Str = (char *)0x0;

      }

      else {

        sVar6 = strlen(_Str);

        FUN_14012f120(_Str,&DAT_14030df6c,sVar6 + 2);

      }

    }

  }

LAB_14021cc71:

  pcVar5 = _Str;

  if (hModule != (HMODULE)0x0) {

LAB_14021cc76:

    FreeLibrary(hModule);

    _Str = pcVar5;

  }

  return _Str;

}




