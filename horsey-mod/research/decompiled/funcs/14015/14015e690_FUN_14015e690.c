// Address: 0x14015e690
// Ghidra name: FUN_14015e690
// ============ 0x14015e690 FUN_14015e690 (size=204) ============


int FUN_14015e690(void)



{

  int iVar1;

  int iVar2;

  longlong lVar3;

  undefined **ppuVar4;

  longlong lVar5;

  

  iVar2 = DAT_1403e2678;

  if (DAT_1403e2678 < 0) {

    iVar2 = 0;

    DAT_1403e2678 = 0;

    if (PTR_PTR_140333660 != (undefined *)0x0) {

      lVar5 = 0;

      ppuVar4 = &PTR_PTR_140333660;

      do {

        lVar3 = 0;

        if (0 < lVar5) {

          do {

            iVar1 = strcmp(*(char **)*ppuVar4,*(char **)(&PTR_PTR_140333660)[lVar3]);

            iVar2 = DAT_1403e2678;

            if (iVar1 == 0) goto LAB_14015e726;

            lVar3 = lVar3 + 1;

          } while (lVar3 < lVar5);

        }

        DAT_1403e2678 = iVar2 + 1;

        (&DAT_1403fc178)[iVar2] = *ppuVar4;

        iVar2 = iVar2 + 1;

LAB_14015e726:

        lVar5 = lVar5 + 1;

        ppuVar4 = &PTR_PTR_140333660 + lVar5;

      } while ((&PTR_PTR_140333660)[lVar5] != (undefined *)0x0);

    }

  }

  return iVar2;

}




