// Address: 0x14016a310
// Ghidra name: FUN_14016a310
// ============ 0x14016a310 FUN_14016a310 (size=413) ============


void FUN_14016a310(longlong param_1)



{

  longlong lVar1;

  longlong lVar2;

  char cVar3;

  int iVar4;

  int iVar5;

  longlong lVar6;

  int iVar7;

  undefined4 local_58;

  undefined4 local_54;

  undefined4 local_50;

  undefined4 local_4c;

  undefined1 local_48 [8];

  int local_40;

  int local_3c;

  undefined1 local_38 [8];

  int local_30;

  int local_2c;

  undefined1 local_28 [16];

  undefined1 local_18 [16];

  

  cVar3 = FUN_1401702d0(DAT_1403fc410);

  if (cVar3 == '\0') {

    iVar4 = FUN_14016d450(param_1);

    if (((iVar4 != *(int *)(param_1 + 100)) && (cVar3 = FUN_14016d280(), cVar3 != '\0')) &&

       (cVar3 = FUN_14016d280(iVar4), cVar3 != '\0')) {

      local_58 = *(undefined4 *)(param_1 + 0x18);

      local_54 = *(undefined4 *)(param_1 + 0x1c);

      local_50 = *(undefined4 *)(param_1 + 0x20);

      local_4c = *(undefined4 *)(param_1 + 0x24);

      cVar3 = FUN_140185790(local_28,&local_58,local_38);

      if (((cVar3 != '\0') && (cVar3 = FUN_140185790(local_18,&local_58,local_48), cVar3 != '\0'))

         && ((double)((float)(local_3c * local_40) /

                     ((float)(local_2c * local_30) + (float)(local_3c * local_40))) < DAT_140304b88)

         ) {

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




