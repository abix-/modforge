// Address: 0x140182560
// Ghidra name: FUN_140182560
// ============ 0x140182560 FUN_140182560 (size=191) ============


uint FUN_140182560(uint param_1,undefined2 *param_2)



{

  uint uVar1;

  uint *puVar2;

  uint uVar3;

  

  uVar3 = 0;

  if (param_2 != (undefined2 *)0x0) {

    *param_2 = 0;

  }

  if (param_1 != 0) {

    if ((param_1 >> 0x1d & 1) == 0) {

      if ((param_1 >> 0x1e & 1) != 0) {

        return param_1 & 0xbfffffff;

      }

      if (param_1 - 0x61 < 0x1a) {

        return param_1 - 0x5d;

      }

      if (param_1 - 0x41 < 0x1a) {

        if (param_2 != (undefined2 *)0x0) {

          *param_2 = 3;

        }

        return param_1 - 0x3d;

      }

      uVar1 = 0;

      puVar2 = &DAT_140337fe0;

      do {

        if (param_1 == *puVar2) goto LAB_14018261b;

        uVar1 = uVar1 + 1;

        puVar2 = puVar2 + 1;

      } while (uVar1 < 0x1b);

      uVar1 = 0;

      puVar2 = &DAT_140338050;

      while (param_1 != *puVar2) {

        uVar1 = uVar1 + 1;

        puVar2 = puVar2 + 1;

        if (0x1a < uVar1) {

          if (param_1 == 0x7f) {

            uVar3 = 0x4c;

          }

          return uVar3;

        }

      }

      if (param_2 != (undefined2 *)0x0) {

        *param_2 = 3;

      }

LAB_14018261b:

      return uVar1 + 0x1e;

    }

    puVar2 = &DAT_140337fb0;

    do {

      if (*puVar2 == param_1) {

        return *(uint *)(&DAT_140337fb4 + (longlong)(int)uVar3 * 8);

      }

      uVar3 = uVar3 + 1;

      puVar2 = puVar2 + 2;

    } while (uVar3 < 5);

  }

  return 0;

}




