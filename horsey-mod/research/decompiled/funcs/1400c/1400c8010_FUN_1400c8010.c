// Address: 0x1400c8010
// Ghidra name: FUN_1400c8010
// ============ 0x1400c8010 FUN_1400c8010 (size=513) ============


void FUN_1400c8010(void)



{

  longlong lVar1;

  int iVar2;

  longlong lVar3;

  byte local_res8 [8];

  longlong local_28 [3];

  ulonglong local_10;

  

  FUN_140075d50(&DAT_1403f34b0);

  FUN_1400c7320(DAT_1403f34b0);

  FUN_140075b80(&DAT_1403f34a8);

  iVar2 = FUN_140075da0();

  FUN_1400c85f0(&DAT_1403f34e0,(longlong)iVar2);

  iVar2 = 0;

  lVar3 = DAT_1403f34e8 - DAT_1403f34e0 >> 0x3f;

  if ((DAT_1403f34e8 - DAT_1403f34e0) / 0x88 + lVar3 != lVar3) {

    lVar3 = 0;

    do {

      lVar1 = lVar3 + DAT_1403f34e0;

      FUN_1400760f0(local_28,lVar1);

      if (0xf < local_10) {

        if ((0xfff < local_10 + 1) && (0x1f < (local_28[0] - *(longlong *)(local_28[0] + -8)) - 8U))

        {

                    /* WARNING: Subroutine does not return */

          _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

        }

        FUN_1402c7088();

      }

      FUN_140075e30(local_res8);

      *(byte *)(lVar1 + 0x40) = local_res8[0] & 1;

      *(byte *)(lVar1 + 0x58) = local_res8[0] >> 1 & 1;

      *(byte *)(lVar1 + 0x6c) = local_res8[0] >> 2 & 1;

      *(byte *)(lVar1 + 0x60) = local_res8[0] >> 3 & 1;

      *(byte *)(lVar1 + 0x61) = local_res8[0] >> 4 & 1;

      *(byte *)(lVar1 + 0x62) = local_res8[0] >> 5 & 1;

      *(byte *)(lVar1 + 99) = local_res8[0] >> 6 & 1;

      FUN_140075c60(lVar1 + 0x44);

      FUN_140075c60(lVar1 + 0x50);

      FUN_140075c60(lVar1 + 0x54);

      FUN_140075c60(lVar1 + 0x5c);

      FUN_140075c60(lVar1 + 100);

      FUN_140075b80(lVar1 + 0x48);

      FUN_140075b80(lVar1 + 0x4c);

      FUN_140075b80(lVar1 + 0x68);

      FUN_1400762a0(lVar1 + 0x70);

      FUN_1400c7910(iVar2,lVar1);

      iVar2 = iVar2 + 1;

      lVar3 = lVar3 + 0x88;

    } while ((ulonglong)(longlong)iVar2 < (ulonglong)((DAT_1403f34e8 - DAT_1403f34e0) / 0x88));

  }

  return;

}




