// Address: 0x1402e0120
// Ghidra name: FUN_1402e0120
// ============ 0x1402e0120 FUN_1402e0120 (size=179) ============


char FUN_1402e0120(longlong param_1)



{

  char cVar1;

  int iVar2;

  

  iVar2 = *(int *)(param_1 + 0x30);

  if (iVar2 < 6) {

    if (iVar2 != 5) {

      if ((iVar2 == 0) || (iVar2 == 1)) {

LAB_1402e0182:

        return (*(char *)(param_1 + 0x2c) != '\0') + '\x01';

      }

      if ((iVar2 != 2) && (iVar2 = iVar2 + -3, iVar2 != 0)) goto LAB_1402e017a;

    }

LAB_1402e0140:

    iVar2 = *(int *)(param_1 + 0x28);

    if (iVar2 < 6) {

      if (iVar2 != 5) {

        if (iVar2 != 0) {

          if (iVar2 == 1) {

            return '\x01';

          }

          if (iVar2 == 2) {

            return '\x02';

          }

          iVar2 = iVar2 + -3;

          goto LAB_1402e015b;

        }

        goto LAB_1402e01aa;

      }

    }

    else if ((iVar2 != 6) && (iVar2 != 7)) {

      iVar2 = iVar2 + -9;

LAB_1402e015b:

      if (iVar2 == 0) goto LAB_1402e01aa;

      if (iVar2 != 1) {

        return '\0';

      }

    }

    cVar1 = '\b';

  }

  else {

    if (iVar2 == 6) goto LAB_1402e0140;

    if (iVar2 != 7) {

      iVar2 = iVar2 + -8;

      if (iVar2 == 0) goto LAB_1402e0182;

LAB_1402e017a:

      if (iVar2 != 1) {

        return '\0';

      }

      goto LAB_1402e0140;

    }

    iVar2 = *(int *)(param_1 + 0x28);

    if (iVar2 != 0) {

      if (iVar2 == 3) {

        return '\b';

      }

      if (iVar2 == 8) {

        return '\b';

      }

      return '\0';

    }

LAB_1402e01aa:

    cVar1 = '\x04';

  }

  return cVar1;

}




