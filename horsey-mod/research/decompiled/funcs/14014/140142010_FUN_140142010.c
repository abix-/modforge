// Address: 0x140142010
// Ghidra name: FUN_140142010
// ============ 0x140142010 FUN_140142010 (size=482) ============


undefined4 FUN_140142010(undefined8 param_1,int param_2,char param_3)



{

  char cVar1;

  int iVar2;

  undefined4 uVar3;

  longlong lVar4;

  longlong lVar5;

  int *piVar6;

  

  FUN_140159d30();

  lVar4 = FUN_14013e670(param_1);

  if (lVar4 != 0) {

    iVar2 = 0;

    if (0 < *(int *)(lVar4 + 0x90)) {

      piVar6 = *(int **)(lVar4 + 0x98);

      do {

        if (*piVar6 == param_2) {

          if ((bool)(char)piVar6[1] == (param_3 != '\0')) goto LAB_1401421e6;

          if (param_2 == 1) {

            if (*(int *)(lVar4 + 0xf4) == 0) {

LAB_140142172:

              if (param_3 != '\0') {

                if ((*(int *)(lVar4 + 0x94) != 0) ||

                   (cVar1 = (**(code **)(*(longlong *)(lVar4 + 0x140) + 0x80))(lVar4,1),

                   cVar1 != '\0')) {

                  *(int *)(lVar4 + 0x94) = *(int *)(lVar4 + 0x94) + 1;

                  *(char *)(piVar6 + 1) = param_3;

                  FUN_14015bb10();

                  return 1;

                }

LAB_1401421d0:

                FUN_14015bb10();

                return 0;

              }

              if ((*(int *)(lVar4 + 0x94) == 1) &&

                 (cVar1 = (**(code **)(*(longlong *)(lVar4 + 0x140) + 0x80))(lVar4,0), cVar1 == '\0'

                 )) goto LAB_1401421d0;

              *(int *)(lVar4 + 0x94) = *(int *)(lVar4 + 0x94) + -1;

            }

            else {

              if (param_3 != '\0') {

                lVar5 = FUN_140177450();

                *(longlong *)(lVar4 + 0xf8) = lVar5;

                if (lVar5 != 0) {

                  *(char *)(piVar6 + 1) = param_3;

                  FUN_14015bb10();

                  return 1;

                }

                goto LAB_1401421d0;

              }

              if (*(longlong *)(lVar4 + 0xf8) != 0) {

                FUN_140176ce0();

                *(undefined8 *)(lVar4 + 0xf8) = 0;

                *(undefined1 *)(piVar6 + 1) = 0;

                FUN_14015bb10();

                return 1;

              }

            }

          }

          else {

            if ((param_2 != 2) || (*(int *)(lVar4 + 0x100) == 0)) goto LAB_140142172;

            if (param_3 != '\0') {

              lVar5 = FUN_140177450();

              *(longlong *)(lVar4 + 0x108) = lVar5;

              if (lVar5 != 0) {

                *(char *)(piVar6 + 1) = param_3;

                FUN_14015bb10();

                return 1;

              }

              goto LAB_1401421d0;

            }

            if (*(longlong *)(lVar4 + 0x108) != 0) {

              FUN_140176ce0();

              *(undefined8 *)(lVar4 + 0x108) = 0;

              *(undefined1 *)(piVar6 + 1) = 0;

              FUN_14015bb10();

              return 1;

            }

          }

          *(char *)(piVar6 + 1) = param_3;

LAB_1401421e6:

          FUN_14015bb10();

          return 1;

        }

        iVar2 = iVar2 + 1;

        piVar6 = piVar6 + 6;

      } while (iVar2 < *(int *)(lVar4 + 0x90));

    }

  }

  FUN_14015bb10();

  uVar3 = FUN_14012e850("That operation is not supported");

  return uVar3;

}




