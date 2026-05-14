// Address: 0x140140570
// Ghidra name: FUN_140140570
// ============ 0x140140570 FUN_140140570 (size=194) ============


uint FUN_140140570(char *param_1,char param_2,char param_3)



{

  int iVar1;

  uint uVar2;

  undefined **ppuVar3;

  

  if ((param_1 != (char *)0x0) && (*param_1 != '\0')) {

    uVar2 = 0;

    ppuVar3 = &PTR_DAT_1403e1c90;

    do {

      iVar1 = FUN_14012ef60(param_1,*ppuVar3);

      if (iVar1 == 0) {

        if (param_2 == '\0') {

          if (param_3 == '\0') {

            return uVar2;

          }

          if (uVar2 != 0) {

            if (uVar2 == 1) {

              return 0;

            }

            if (uVar2 != 2) {

              if (uVar2 == 3) {

                return 2;

              }

              return uVar2;

            }

            return 3;

          }

        }

        else {

          if (uVar2 == 1) {

            return 2;

          }

          if (uVar2 != 2) {

            return uVar2;

          }

        }

        return 1;

      }

      uVar2 = uVar2 + 1;

      ppuVar3 = ppuVar3 + 1;

    } while (uVar2 < 0x1a);

  }

  return 0xffffffff;

}




