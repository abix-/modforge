// Address: 0x14015d120
// Ghidra name: FUN_14015d120
// ============ 0x14015d120 FUN_14015d120 (size=348) ============


undefined8 FUN_14015d120(char *param_1)



{

  int iVar1;

  undefined8 uVar2;

  

  if (param_1 == (char *)0x0) {

    return 0;

  }

  iVar1 = strcmp(param_1,"U8");

  if (iVar1 == 0) {

    return 8;

  }

  iVar1 = strcmp(param_1,"S8");

  if (iVar1 == 0) {

    return 0x8008;

  }

  iVar1 = strcmp(param_1,"S16LE");

  if (iVar1 != 0) {

    iVar1 = strcmp(param_1,"S16BE");

    if (iVar1 == 0) {

      return 0x9010;

    }

    iVar1 = strcmp(param_1,"S16");

    if (iVar1 != 0) {

      iVar1 = strcmp(param_1,"S32LE");

      if (iVar1 != 0) {

        iVar1 = strcmp(param_1,"S32BE");

        if (iVar1 == 0) {

          return 0x9020;

        }

        iVar1 = strcmp(param_1,"S32");

        if (iVar1 != 0) {

          iVar1 = strcmp(param_1,"F32LE");

          if (iVar1 == 0) {

            return 0x8120;

          }

          iVar1 = strcmp(param_1,"F32BE");

          if (iVar1 == 0) {

            return 0x9120;

          }

          iVar1 = strcmp(param_1,"F32");

          uVar2 = 0;

          if (iVar1 == 0) {

            uVar2 = 0x8120;

          }

          return uVar2;

        }

      }

      return 0x8020;

    }

  }

  return 0x8010;

}




