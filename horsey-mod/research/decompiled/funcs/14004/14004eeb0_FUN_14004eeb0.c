// Address: 0x14004eeb0
// Ghidra name: FUN_14004eeb0
// ============ 0x14004eeb0 FUN_14004eeb0 (size=211) ============


char FUN_14004eeb0(longlong param_1)



{

  char cVar1;

  int iVar2;

  

  if (*(int *)(param_1 + 0x6ec) == 0) {

    if (*(int *)(param_1 + 0x6e8) != -1) {

LAB_14004ef38:

      iVar2 = *(int *)(param_1 + 0x6e8);

      cVar1 = *(char *)((longlong)iVar2 + 0x5e4 + param_1);

      *(int *)(param_1 + 0x6e8) = iVar2 + 1;

      if (cVar1 != -1) {

        *(undefined4 *)(param_1 + 0x6ec) = 1;

        *(int *)(param_1 + 0x6f0) = iVar2;

      }

      if (*(int *)(param_1 + 0x5e0) <= iVar2 + 1) {

        *(undefined4 *)(param_1 + 0x6e8) = 0xffffffff;

      }

      *(char *)(param_1 + 0x6e4) = cVar1;

      return cVar1;

    }

    *(int *)(param_1 + 0x6f0) = *(int *)(param_1 + 0x5e0) + -1;

    iVar2 = FUN_140053730();

    if (iVar2 == 0) {

      *(undefined4 *)(param_1 + 0x6ec) = 1;

    }

    else {

      if ((*(byte *)(param_1 + 0x6e3) & 1) != 0) goto LAB_14004ef38;

      *(undefined4 *)(param_1 + 0x9c) = 0x20;

    }

  }

  return '\0';

}




