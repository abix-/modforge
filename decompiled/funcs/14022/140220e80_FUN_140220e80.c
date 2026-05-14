// Address: 0x140220e80
// Ghidra name: FUN_140220e80
// ============ 0x140220e80 FUN_140220e80 (size=732) ============


char * FUN_140220e80(undefined8 param_1,char *param_2,size_t *param_3)



{

  char cVar1;

  BOOL BVar2;

  int iVar3;

  UINT UVar4;

  HANDLE pvVar5;

  LPVOID pvVar6;

  longlong lVar7;

  char *pcVar8;

  size_t sVar9;

  SIZE_T SVar10;

  char *pcVar11;

  

  pcVar8 = (char *)0x0;

  cVar1 = FUN_1401696e0(param_2);

  if (cVar1 == '\0') {

    iVar3 = strcmp(param_2,"image/bmp");

    if (iVar3 == 0) {

      BVar2 = IsClipboardFormatAvailable(0x11);

      if (BVar2 == 0) {

        BVar2 = IsClipboardFormatAvailable(8);

        if (BVar2 == 0) {

          return (char *)0x0;

        }

        iVar3 = FUN_140221210(param_1);

        if (iVar3 == 0) {

          return (char *)0x0;

        }

        UVar4 = 8;

      }

      else {

        iVar3 = FUN_140221210(param_1);

        if (iVar3 == 0) {

          return (char *)0x0;

        }

        UVar4 = 0x11;

      }

      pvVar5 = GetClipboardData(UVar4);

      if (pvVar5 != (HANDLE)0x0) {

        pcVar8 = (char *)FUN_140220d20(pvVar5,param_3);

        CloseClipboard();

        return pcVar8;

      }

      FUN_1401a9ed0("Couldn\'t get clipboard data");

      CloseClipboard();

      return (char *)0x0;

    }

    iVar3 = strcmp(param_2,"image/png");

    if (iVar3 != 0) {

      pcVar8 = (char *)FUN_1401693d0(param_1,param_2,param_3);

      return pcVar8;

    }

    UVar4 = FUN_1402209e0();

    BVar2 = IsClipboardFormatAvailable(UVar4);

    if (BVar2 == 0) {

      return (char *)0x0;

    }

    iVar3 = FUN_140221210(param_1);

    if (iVar3 == 0) {

      return (char *)0x0;

    }

    UVar4 = FUN_1402209e0();

    pvVar5 = GetClipboardData(UVar4);

    if (pvVar5 != (HANDLE)0x0) {

      SVar10 = GlobalSize(pvVar5);

      pvVar6 = GlobalLock(pvVar5);

      if (pvVar6 != (LPVOID)0x0) {

        pcVar8 = (char *)FUN_1401841f0(SVar10);

        if (pcVar8 != (char *)0x0) {

          FUN_1402f8e20(pcVar8,pvVar6,SVar10);

          *param_3 = SVar10;

        }

        GlobalUnlock(pvVar5);

        CloseClipboard();

        return pcVar8;

      }

      FUN_1401a9ed0("Couldn\'t lock clipboard data");

      CloseClipboard();

      return (char *)0x0;

    }

    FUN_1401a9ed0("Couldn\'t get clipboard data");

    CloseClipboard();

    return (char *)0x0;

  }

  BVar2 = IsClipboardFormatAvailable(0xd);

  if (BVar2 == 0) {

    BVar2 = IsClipboardFormatAvailable(1);

    if ((BVar2 != 0) && (iVar3 = FUN_140221210(param_1), iVar3 != 0)) {

      pvVar5 = GetClipboardData(1);

      if (pvVar5 == (HANDLE)0x0) goto LAB_140220f86;

      pvVar6 = GlobalLock(pvVar5);

      if (pvVar6 == (LPVOID)0x0) goto LAB_140220f2b;

      pcVar8 = (char *)FUN_14012f0d0(pvVar6);

      GlobalUnlock(pvVar5);

      goto LAB_140220f92;

    }

  }

  else {

    iVar3 = FUN_140221210(param_1);

    if (iVar3 != 0) {

      pvVar5 = GetClipboardData(0xd);

      if (pvVar5 == (HANDLE)0x0) {

LAB_140220f86:

        pcVar11 = "Couldn\'t get clipboard data";

      }

      else {

        pvVar6 = GlobalLock(pvVar5);

        if (pvVar6 != (LPVOID)0x0) {

          lVar7 = FUN_14012fd40(pvVar6);

          pcVar8 = (char *)FUN_140197820(&DAT_14039c6f0,"UTF-16LE",pvVar6,lVar7 * 2 + 2);

          GlobalUnlock(pvVar5);

          goto LAB_140220f92;

        }

LAB_140220f2b:

        pcVar11 = "Couldn\'t lock clipboard data";

      }

      FUN_1401a9ed0(pcVar11);

LAB_140220f92:

      CloseClipboard();

      if (pcVar8 != (char *)0x0) goto LAB_140220fab;

    }

  }

  pcVar8 = (char *)FUN_14012f0d0(&DAT_14039bcb9);

LAB_140220fab:

  sVar9 = strlen(pcVar8);

  *param_3 = sVar9;

  return pcVar8;

}




