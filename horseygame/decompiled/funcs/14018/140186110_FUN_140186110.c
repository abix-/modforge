// Address: 0x140186110
// Ghidra name: FUN_140186110
// ============ 0x140186110 FUN_140186110 (size=191) ============


void FUN_140186110(undefined8 param_1)



{

  int iVar1;

  longlong lVar2;

  int iVar3;

  longlong lVar4;

  

  FUN_140186540();

  if (DAT_1403fcb5c != 0) {

    iVar1 = FUN_1401864e0(param_1);

    lVar2 = FUN_140186240();

    if (lVar2 != 0) {

      iVar3 = 0;

      if (0 < *(int *)(lVar2 + 0x10)) {

        lVar4 = 0;

        do {

          FUN_1401841e0(*(undefined8 *)(lVar4 + *(longlong *)(lVar2 + 0x18)));

          iVar3 = iVar3 + 1;

          lVar4 = lVar4 + 8;

        } while (iVar3 < *(int *)(lVar2 + 0x10));

      }

      FUN_1401841e0(*(undefined8 *)(lVar2 + 0x18));

      FUN_1401841e0(*(undefined8 *)(lVar2 + 0x20));

      FUN_1401841e0(lVar2);

      DAT_1403fcb5c = DAT_1403fcb5c + -1;

      *(undefined8 *)(DAT_1403fcb60 + (longlong)iVar1 * 8) =

           *(undefined8 *)(DAT_1403fcb60 + (longlong)DAT_1403fcb5c * 8);

    }

  }

  FUN_140186c50();

  return;

}




