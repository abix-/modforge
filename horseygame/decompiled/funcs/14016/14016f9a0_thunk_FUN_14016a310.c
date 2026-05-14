// Address: 0x14016f9a0
// Ghidra name: thunk_FUN_14016a310
// ============ 0x14016f9a0 thunk_FUN_14016a310 (size=5) ============


void thunk_FUN_14016a310(longlong param_1)



{

  longlong lVar1;

  longlong lVar2;

  char cVar3;

  int iVar4;

  int iVar5;

  longlong lVar6;

  int iVar7;

  undefined4 uStack_58;

  undefined4 uStack_54;

  undefined4 uStack_50;

  undefined4 uStack_4c;

  undefined1 auStack_48 [8];

  int iStack_40;

  int iStack_3c;

  undefined1 auStack_38 [8];

  int iStack_30;

  int iStack_2c;

  undefined1 auStack_28 [16];

  undefined1 auStack_18 [16];

  

  cVar3 = FUN_1401702d0(DAT_1403fc410);

  if (cVar3 == '\0') {

    iVar4 = FUN_14016d450(param_1);

    if (((iVar4 != *(int *)(param_1 + 100)) && (cVar3 = FUN_14016d280(), cVar3 != '\0')) &&

       (cVar3 = FUN_14016d280(iVar4), cVar3 != '\0')) {

      uStack_58 = *(undefined4 *)(param_1 + 0x18);

      uStack_54 = *(undefined4 *)(param_1 + 0x1c);

      uStack_50 = *(undefined4 *)(param_1 + 0x20);

      uStack_4c = *(undefined4 *)(param_1 + 0x24);

      cVar3 = FUN_140185790(auStack_28,&uStack_58,auStack_38);

      if (((cVar3 != '\0') &&

          (cVar3 = FUN_140185790(auStack_18,&uStack_58,auStack_48), cVar3 != '\0')) &&

         ((double)((float)(iStack_3c * iStack_40) /

                  ((float)(iStack_2c * iStack_30) + (float)(iStack_3c * iStack_40))) < DAT_140304b88

         )) {

        return;

      }

    }

    if (iVar4 != *(int *)(param_1 + 100)) {

      iVar5 = FUN_14016d5f0(iVar4);

      iVar7 = 0;

      if (0 < *(int *)(DAT_1403fc410 + 0x328)) {

        lVar6 = 0;

        do {

          lVar1 = *(longlong *)(*(longlong *)(DAT_1403fc410 + 0x330) + lVar6 * 8);

          if (*(longlong *)(lVar1 + 0x68) == param_1) {

            if ((iVar5 != iVar7) && (-1 < iVar5)) {

              lVar6 = *(longlong *)(*(longlong *)(DAT_1403fc410 + 0x330) + (longlong)iVar5 * 8);

              lVar2 = *(longlong *)(lVar6 + 0x68);

              if ((lVar2 != 0) && (lVar2 != param_1)) {

                FUN_14016f4f0();

              }

              *(longlong *)(lVar6 + 0x68) = param_1;

              *(undefined8 *)(lVar1 + 0x68) = 0;

            }

            break;

          }

          iVar7 = iVar7 + 1;

          lVar6 = lVar6 + 1;

        } while (lVar6 < *(int *)(DAT_1403fc410 + 0x328));

      }

      FUN_1401cda90(param_1,0x213,iVar4,0);

    }

  }

  return;

}




