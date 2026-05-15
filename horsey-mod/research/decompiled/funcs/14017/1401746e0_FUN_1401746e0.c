// Address: 0x1401746e0
// Ghidra name: FUN_1401746e0
// ============ 0x1401746e0 FUN_1401746e0 (size=242) ============


int FUN_1401746e0(void)



{

  char cVar1;

  int iVar2;

  longlong *plVar3;

  longlong lVar4;

  int iVar5;

  

  cVar1 = thunk_FUN_140174fe0();

  if ((cVar1 != '\0') && (plVar3 = (longlong *)FUN_1401841a0(1,0x10), plVar3 != (longlong *)0x0)) {

    lVar4 = FUN_140179a30();

    plVar3[1] = lVar4;

    if (lVar4 != 0) {

      lVar4 = FUN_1401aaee0(0,0,FUN_1401ab0c0,FUN_1401ab2f0,&LAB_140174950,0);

      *plVar3 = lVar4;

      if (lVar4 != 0) {

        do {

          do {

            iVar2 = FUN_140138fe0(&DAT_1403fc458);

            iVar5 = iVar2 + 1;

          } while (iVar5 == 0);

          cVar1 = FUN_140138fc0(&DAT_1403fc458,iVar2,iVar5);

        } while (cVar1 == '\0');

        cVar1 = FUN_1401ab100(DAT_1403fc450,iVar5,plVar3,0);

        if (cVar1 != '\0') {

          return iVar5;

        }

        FUN_140174920(plVar3);

        return 0;

      }

      FUN_140179b30(plVar3[1]);

    }

    FUN_1401841e0(plVar3);

  }

  return 0;

}




