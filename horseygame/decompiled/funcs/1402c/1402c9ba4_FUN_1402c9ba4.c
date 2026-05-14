// Address: 0x1402c9ba4
// Ghidra name: FUN_1402c9ba4
// ============ 0x1402c9ba4 FUN_1402c9ba4 (size=491) ============


char FUN_1402c9ba4(longlong param_1,longlong *param_2,byte *param_3,byte *param_4)



{

  int iVar1;

  longlong lVar2;

  longlong lVar3;

  undefined8 uVar4;

  

  lVar3 = 0;

  iVar1 = *(int *)(param_3 + 4);

  lVar2 = lVar3;

  if (iVar1 != 0) {

    lVar2 = FUN_1402c8e50();

    lVar2 = iVar1 + lVar2;

  }

  if (lVar2 != 0) {

    iVar1 = *(int *)(param_3 + 4);

    lVar2 = lVar3;

    if (iVar1 != 0) {

      lVar2 = FUN_1402c8e50();

      lVar2 = iVar1 + lVar2;

    }

    if ((*(char *)(lVar2 + 0x10) != '\0') && ((*(int *)(param_3 + 8) != 0 || (*(int *)param_3 < 0)))

       ) {

      if (-1 < *(int *)param_3) {

        param_2 = (longlong *)((longlong)*(int *)(param_3 + 8) + *param_2);

      }

      if ((((*param_3 & 0x80) == 0) || ((*param_4 & 0x10) == 0)) || (DAT_1403fec00 == 0)) {

        if ((*param_3 & 8) == 0) {

          if ((*param_4 & 1) == 0) {

            iVar1 = *(int *)(param_4 + 0x18);

            lVar2 = lVar3;

            if (iVar1 != 0) {

              lVar2 = FUN_1402c8e64();

              lVar2 = iVar1 + lVar2;

            }

            if (lVar2 == 0) {

              if ((*(longlong *)(param_1 + 0x28) != 0) && (param_2 != (longlong *)0x0)) {

                iVar1 = *(int *)(param_4 + 0x14);

                uVar4 = __AdjustPointer(*(undefined8 *)(param_1 + 0x28),param_4 + 8);

                FUN_1402f8e20(param_2,uVar4,(longlong)iVar1);

                return '\0';

              }

                    /* WARNING: Subroutine does not return */

              FUN_1402e1bf8();

            }

            if ((*(longlong *)(param_1 + 0x28) != 0) && (param_2 != (longlong *)0x0)) {

              iVar1 = *(int *)(param_4 + 0x18);

              if (iVar1 != 0) {

                lVar3 = FUN_1402c8e64();

                lVar3 = iVar1 + lVar3;

              }

              if (lVar3 != 0) {

                return ((*param_4 & 4) != 0) + '\x01';

              }

            }

                    /* WARNING: Subroutine does not return */

            FUN_1402e1bf8();

          }

          if ((*(longlong *)(param_1 + 0x28) == 0) || (param_2 == (longlong *)0x0)) {

                    /* WARNING: Subroutine does not return */

            FUN_1402e1bf8();

          }

          FUN_1402f8e20(param_2,*(longlong *)(param_1 + 0x28),(longlong)*(int *)(param_4 + 0x14));

          if (*(int *)(param_4 + 0x14) != 8) {

            return '\0';

          }

          if (*param_2 == 0) {

            return '\0';

          }

          lVar3 = *param_2;

        }

        else {

          lVar3 = *(longlong *)(param_1 + 0x28);

          if ((lVar3 == 0) || (param_2 == (longlong *)0x0)) {

                    /* WARNING: Subroutine does not return */

            FUN_1402e1bf8();

          }

          *param_2 = lVar3;

        }

      }

      else {

        lVar3 = (*(code *)PTR__guard_dispatch_icall_140302c68)();

        if ((lVar3 == 0) || (param_2 == (longlong *)0x0)) {

                    /* WARNING: Subroutine does not return */

          FUN_1402e1bf8();

        }

        *param_2 = lVar3;

      }

      lVar3 = __AdjustPointer(lVar3,param_4 + 8);

      *param_2 = lVar3;

      return '\0';

    }

  }

  return '\0';

}




