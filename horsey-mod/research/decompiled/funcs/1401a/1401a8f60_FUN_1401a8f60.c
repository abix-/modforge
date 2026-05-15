// Address: 0x1401a8f60
// Ghidra name: FUN_1401a8f60
// ============ 0x1401a8f60 FUN_1401a8f60 (size=189) ============


void FUN_1401a8f60(void)



{

  char cVar1;

  longlong lVar2;

  int iVar3;

  undefined4 *puVar4;

  longlong lVar5;

  

  cVar1 = FUN_140138fc0(&DAT_1403fcd58,1,0);

  if (cVar1 != '\0') {

    FUN_14017caa0(DAT_1403fcd48);

    iVar3 = 0;

    if (0 < DAT_1403fcd44) {

      lVar5 = 0;

      do {

        puVar4 = (undefined4 *)(DAT_1403fcd50 + lVar5);

        if (*(char *)(puVar4 + 0x14) != '\0') {

          lVar2 = 0;

          *(undefined1 *)(puVar4 + 0x14) = 0;

          if ((puVar4[0x15] == 0) || (lVar2 = FUN_14016e190(), lVar2 != 0)) {

            FUN_1401a8b60(0,*puVar4,lVar2,0,1);

          }

        }

        iVar3 = iVar3 + 1;

        lVar5 = lVar5 + 0x60;

      } while (iVar3 < DAT_1403fcd44);

    }

    FUN_14017cae0(DAT_1403fcd48);

    return;

  }

  return;

}




