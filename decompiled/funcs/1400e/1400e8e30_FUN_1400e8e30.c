// Address: 0x1400e8e30
// Ghidra name: FUN_1400e8e30
// ============ 0x1400e8e30 FUN_1400e8e30 (size=367) ============


undefined8 FUN_1400e8e30(longlong param_1)



{

  char cVar1;

  char *pcVar2;

  

  pcVar2 = *(char **)(param_1 + 0xb8);

  if (*(char **)(param_1 + 0xc0) <= pcVar2) {

    if (*(int *)(param_1 + 0x30) == 0) {

      return 0;

    }

    FUN_1400ed820();

    pcVar2 = *(char **)(param_1 + 0xb8);

  }

  cVar1 = *pcVar2;

  pcVar2 = pcVar2 + 1;

  *(char **)(param_1 + 0xb8) = pcVar2;

  if (cVar1 == 'G') {

    if (*(char **)(param_1 + 0xc0) <= pcVar2) {

      if (*(int *)(param_1 + 0x30) == 0) {

        return 0;

      }

      FUN_1400ed820(param_1);

      pcVar2 = *(char **)(param_1 + 0xb8);

    }

    cVar1 = *pcVar2;

    pcVar2 = pcVar2 + 1;

    *(char **)(param_1 + 0xb8) = pcVar2;

    if (cVar1 == 'I') {

      if (*(char **)(param_1 + 0xc0) <= pcVar2) {

        if (*(int *)(param_1 + 0x30) == 0) {

          return 0;

        }

        FUN_1400ed820(param_1);

        pcVar2 = *(char **)(param_1 + 0xb8);

      }

      cVar1 = *pcVar2;

      pcVar2 = pcVar2 + 1;

      *(char **)(param_1 + 0xb8) = pcVar2;

      if (cVar1 == 'F') {

        if (*(char **)(param_1 + 0xc0) <= pcVar2) {

          if (*(int *)(param_1 + 0x30) == 0) {

            return 0;

          }

          FUN_1400ed820(param_1);

          pcVar2 = *(char **)(param_1 + 0xb8);

        }

        cVar1 = *pcVar2;

        pcVar2 = pcVar2 + 1;

        *(char **)(param_1 + 0xb8) = pcVar2;

        if (cVar1 == '8') {

          if (*(char **)(param_1 + 0xc0) <= pcVar2) {

            if (*(int *)(param_1 + 0x30) == 0) {

              return 0;

            }

            FUN_1400ed820(param_1);

            pcVar2 = *(char **)(param_1 + 0xb8);

          }

          cVar1 = *pcVar2;

          pcVar2 = pcVar2 + 1;

          *(char **)(param_1 + 0xb8) = pcVar2;

          if ((cVar1 == '9') || (cVar1 == '7')) {

            if (*(char **)(param_1 + 0xc0) <= pcVar2) {

              if (*(int *)(param_1 + 0x30) == 0) {

                return 0;

              }

              FUN_1400ed820(param_1);

              pcVar2 = *(char **)(param_1 + 0xb8);

            }

            cVar1 = *pcVar2;

            *(char **)(param_1 + 0xb8) = pcVar2 + 1;

            if (cVar1 == 'a') {

              return 1;

            }

          }

        }

      }

    }

  }

  return 0;

}




