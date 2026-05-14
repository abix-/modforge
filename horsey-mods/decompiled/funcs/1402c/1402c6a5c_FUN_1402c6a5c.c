// Address: 0x1402c6a5c
// Ghidra name: FUN_1402c6a5c
// ============ 0x1402c6a5c FUN_1402c6a5c (size=243) ============


void FUN_1402c6a5c(void)



{

  DWORD DVar1;

  int iVar2;

  undefined *puVar3;

  longlong lVar4;

  longlong *plVar5;

  

  puVar3 = &DAT_1403fdf70;

  DVar1 = GetCurrentThreadId();

  iVar2 = FUN_1402c6e48(&DAT_1403e8a50);

  if (iVar2 != 0) {

                    /* WARNING: Subroutine does not return */

    FUN_1402c6c88(5);

  }

  if (DAT_1403e8a9c == 0x7fffffff) {

    DAT_1403e8a9c = 0x7ffffffe;

                    /* WARNING: Subroutine does not return */

    FUN_1402c6c88(6);

  }

  do {

    lVar4 = 0;

    iVar2 = *(int *)(puVar3 + 800);

    if (iVar2 != 0) {

      plVar5 = (longlong *)(puVar3 + 0x10);

      do {

        if (0x13 < lVar4) break;

        if ((*plVar5 != 0) && (*(DWORD *)(plVar5 + -1) == DVar1)) {

          if ((undefined4 *)plVar5[2] != (undefined4 *)0x0) {

            *(undefined4 *)plVar5[2] = 1;

          }

          FUN_1402c6e50(*plVar5);

          FUN_1402c6fa8(plVar5[1]);

          *plVar5 = 0;

          *(int *)(puVar3 + 800) = *(int *)(puVar3 + 800) + -1;

          iVar2 = *(int *)(puVar3 + 800);

        }

        lVar4 = lVar4 + 1;

        plVar5 = plVar5 + 5;

      } while (iVar2 != 0);

    }

    puVar3 = *(undefined **)(puVar3 + 0x328);

    if (puVar3 == (undefined *)0x0) {

      FUN_1402c6e50(&DAT_1403e8a50);

      return;

    }

  } while( true );

}




