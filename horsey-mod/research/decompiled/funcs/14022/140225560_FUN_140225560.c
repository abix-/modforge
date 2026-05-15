// Address: 0x140225560
// Ghidra name: FUN_140225560
// ============ 0x140225560 FUN_140225560 (size=791) ============


bool FUN_140225560(HWND param_1,uint param_2,longlong param_3,ulonglong *param_4,longlong param_5)



{

  uint uVar1;

  HIMC pHVar2;

  ulonglong uVar3;

  bool bVar4;

  

  bVar4 = false;

  if (param_2 == 0x281) {

    if ((*(char *)(param_5 + 0x143) == '\0') || (*(char *)(param_5 + 0x144) == '\0')) {

      uVar3 = 0x4000000f;

      if (*(char *)(param_5 + 0x143) == '\0') {

        uVar3 = 0xc000000f;

      }

      if (*(char *)(param_5 + 0x144) != '\0') {

        uVar3 = uVar3 & 0xfffffffffffffff0;

      }

    }

    else {

      uVar3 = 0;

    }

    *param_4 = *param_4 & uVar3;

  }

  else {

    if ((param_2 == 0x10d) && (*(char *)(param_5 + 0x143) != '\0')) {

      return true;

    }

    if (((*(char *)(param_5 + 0x140) != '\0') && (*(char *)(param_5 + 0x142) != '\0')) &&

       (*(char *)(param_5 + 0x141) != '\0')) {

      if (param_2 < 0x10f) {

        if (param_2 == 0x10e) {

          if (*(char *)(param_5 + 0x143) != '\0') {

            **(undefined2 **)(param_5 + 0x168) = 0;

            *(undefined2 *)(param_5 + 0x174) = 0;

            *(undefined8 *)(param_5 + 0x194) = 0;

            *(undefined4 *)(param_5 + 0x19c) = 0;

            FUN_140224c10(param_5);

            return true;

          }

          return false;

        }

        if (param_2 == 0x51) {

          FUN_140224aa0(param_5);

          return false;

        }

        if ((param_2 != 0x100) && (param_2 != 0x104)) {

          return false;

        }

        return param_3 == 0xe5;

      }

      if (param_2 == 0x10f) {

        if (*(char *)(param_5 + 0x143) != '\0') {

          bVar4 = true;

          pHVar2 = ImmGetContext(param_1);

          if (((uint)*param_4 >> 0xb & 1) != 0) {

            FUN_140224150(param_5,pHVar2,0x800);

            FUN_140224c10(param_5);

            FUN_140224dd0();

          }

          if ((*param_4 & 8) != 0) {

            *(undefined2 *)(param_5 + 0x174) = 0;

            FUN_140224150(param_5,pHVar2,8);

            FUN_140224c40(param_5);

          }

          ImmReleaseContext(param_1,pHVar2);

        }

      }

      else if (param_2 == 0x282) {

        switch(param_3) {

        case 3:

        case 5:

          if (*(char *)(param_5 + 0x144) != '\0') {

            *(undefined1 *)(param_5 + 0x1a1) = 1;

            return true;

          }

          break;

        case 4:

          if (*(char *)(param_5 + 0x144) != '\0') {

            *(undefined1 *)(param_5 + 0x1a1) = 0;

            FUN_140223e80(param_5);

            return true;

          }

          break;

        case 6:

        case 8:

          FUN_140225110(param_5);

          return false;

        default:

          return true;

        case 9:

        case 10:

        case 0xb:

          break;

        case 0xe:

          uVar1 = FUN_140224350(param_5,0);

          FUN_1402246a0(param_5,param_1);

          if (uVar1 < 0x5000405) {

            if (uVar1 != 0x5000404) {

              if ((((uVar1 != 0x4010804) && (uVar1 != 0x4020404)) && (uVar1 != 0x4020804)) &&

                 ((uVar1 != 0x4030404 && (uVar1 != 0x4040404)))) {

                return false;

              }

              if (*param_4 == 1) {

                return true;

              }

              if (*param_4 != 2) {

                return false;

              }

              return true;

            }

          }

          else if (((uVar1 != 0x5010404) && (uVar1 != 0x5020404)) &&

                  ((uVar1 != 0x5030804 && (uVar1 != 0x6000404)))) {

            return false;

          }

          uVar3 = *param_4;

          if (uVar3 == 0x10) {

            return true;

          }

          if (uVar3 == 0x11) {

            return true;

          }

          if (uVar3 - 0x1a < 3) {

            return true;

          }

        }

      }

      return bVar4;

    }

  }

  return false;

}




