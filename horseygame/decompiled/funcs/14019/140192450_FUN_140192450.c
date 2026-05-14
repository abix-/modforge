// Address: 0x140192450
// Ghidra name: FUN_140192450
// ============ 0x140192450 FUN_140192450 (size=252) ============


void FUN_140192450(void)



{

  longlong lVar1;

  char cVar2;

  int iVar3;

  BOOL BVar4;

  ulonglong uVar5;

  tagMSG local_38;

  

  if (DAT_1403fcbc0 == '\0') {

    FUN_1401922b0();

  }

  if (DAT_1403fcbc8 == '\0') {

    uVar5 = FUN_140149350();

    if ((DAT_1403fcbd0 == 0) || (DAT_1403fcbd0 + 3000 <= uVar5)) {

      DAT_1403fcbc4 = DAT_1403fcbc4 + 1;

      DAT_1403fcbd0 = uVar5;

      return;

    }

  }

  else {

    cVar2 = FUN_14017e840();

    if ((cVar2 == '\0') && (lVar1 = FUN_14017ffb0(), lVar1 == DAT_1403fcbd8)) {

      iVar3 = PeekMessageW(&local_38,DAT_1403fcc30,0,0,0);

      while (iVar3 != 0) {

        BVar4 = GetMessageA(&local_38,DAT_1403fcc30,0,0);

        if (BVar4 != 0) {

          TranslateMessage(&local_38);

          DispatchMessageW(&local_38);

        }

        iVar3 = PeekMessageW(&local_38,DAT_1403fcc30,0,0,0);

      }

    }

  }

  return;

}




