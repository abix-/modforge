# `FUN_1402f6abc` @ 0x1402f6abc

**Size**: 208 bytes
**Role**: unclassified game logic

**Game callers** (2): `FUN_1402f6abc`, `FUN_1402f6b8c`

**Game callees** (1): `FUN_1402f6abc`

**Vendor callees** (0) - SDL/CRT/etc.

## Decompiled

```c
bool FUN_1402f6abc(char *param_1,char *param_2,int param_3,int param_4,int param_5)

{

  int iVar1;

  char *pcVar2;

  if (param_5 == 0) {

    return '4' < *param_2;

  }

  iVar1 = fegetround();

  if (iVar1 == 0) {

    if ('5' < *param_2) {

      return true;

    }

    if ('4' < *param_2) {

      pcVar2 = param_2;

      if (param_4 == 0) {

        return true;

      }

      do {

        pcVar2 = pcVar2 + 1;

      } while (*pcVar2 == '0');

      if (*pcVar2 != '\0') {

        return true;

      }

      if (param_2 != param_1) {

        return (bool)(param_2[-1] & 1);

      }

    }

  }

  else if (iVar1 == 0x200) {

    if (param_4 != 0) {

      for (; *param_2 == '0'; param_2 = param_2 + 1) {

      }

      if (*param_2 == '\0') {

        return false;

      }

    }

    if (param_3 != 0x2d) {

      return true;

    }

  }

  else if (iVar1 == 0x100) {

    if (param_4 != 0) {

      for (; *param_2 == '0'; param_2 = param_2 + 1) {

      }

      if (*param_2 == '\0') {

        return false;

      }

    }

    if (param_3 == 0x2d) {

      return true;

    }

  }

  return false;

}
```