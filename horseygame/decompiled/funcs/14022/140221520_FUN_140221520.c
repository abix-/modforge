// Address: 0x140221520
// Ghidra name: FUN_140221520
// ============ 0x140221520 FUN_140221520 (size=380) ============


ulonglong FUN_140221520(longlong param_1,undefined8 param_2)



{

  short *psVar1;

  short sVar2;

  byte bVar3;

  longlong lVar4;

  short *psVar5;

  ulonglong uVar6;

  HGLOBAL hMem;

  short *psVar7;

  HANDLE pvVar8;

  longlong lVar9;

  longlong lVar10;

  longlong local_res8;

  

  bVar3 = 1;

  lVar4 = (**(code **)(param_1 + 0x360))(*(undefined8 *)(param_1 + 0x370),param_2,&local_res8);

  if ((lVar4 != 0) && (local_res8 != 0)) {

    psVar5 = (short *)FUN_140197820("UTF-16LE",&DAT_14039c6f0,lVar4);

    if (psVar5 == (short *)0x0) {

      uVar6 = FUN_14012e850("Couldn\'t convert text from UTF-8");

      return uVar6;

    }

    lVar10 = 0;

    sVar2 = *psVar5;

    psVar7 = psVar5;

    lVar4 = lVar10;

    lVar9 = lVar10;

    while (sVar2 != 0) {

      if ((sVar2 == 10) && ((lVar4 == 0 || (psVar7[-1] != 0xd)))) {

        lVar9 = lVar9 + 1;

      }

      lVar4 = lVar4 + 1;

      lVar9 = lVar9 + 1;

      psVar7 = psVar5 + lVar4;

      sVar2 = psVar5[lVar4];

    }

    hMem = GlobalAlloc(2,lVar9 * 2 + 2);

    if (hMem == (HGLOBAL)0x0) {

      bVar3 = FUN_14012e770();

    }

    else {

      psVar7 = GlobalLock(hMem);

      if (psVar7 != (short *)0x0) {

        sVar2 = *psVar5;

        psVar1 = psVar5;

        while (sVar2 != 0) {

          if ((sVar2 == 10) && ((lVar10 == 0 || (psVar1[-1] != 0xd)))) {

            *psVar7 = 0xd;

            psVar7 = psVar7 + 1;

          }

          lVar10 = lVar10 + 1;

          *psVar7 = *psVar1;

          psVar1 = psVar5 + lVar10;

          psVar7 = psVar7 + 1;

          sVar2 = *psVar1;

        }

        *psVar7 = 0;

        GlobalUnlock(hMem);

      }

      pvVar8 = SetClipboardData(0xd,hMem);

      if (pvVar8 == (HANDLE)0x0) {

        bVar3 = FUN_1401a9ed0("Couldn\'t set clipboard data");

      }

    }

    FUN_1401841e0(psVar5);

  }

  return (ulonglong)bVar3;

}




