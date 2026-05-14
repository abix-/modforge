// Address: 0x140278760
// Ghidra name: FUN_140278760
// ============ 0x140278760 FUN_140278760 (size=218) ============


undefined8 FUN_140278760(longlong param_1,undefined1 *param_2,undefined1 *param_3)



{

  char cVar1;

  undefined8 uVar2;

  ushort local_res8 [4];

  

  if (param_2 != (undefined1 *)0x0) {

    *param_2 = 0;

  }

  if (param_3 != (undefined1 *)0x0) {

    *param_3 = 0;

  }

  if (*(int *)(param_1 + 0x1c) == 0x83) {

LAB_1402787dc:

    uVar2 = 1;

  }

  else {

    cVar1 = FUN_140279d40(param_1,1);

    if (cVar1 != '\0') {

      cVar1 = FUN_1402796b0(param_1,local_res8);

      if (cVar1 != '\0') {

        if ((local_res8[0] & 0xf0ff) == 5) {

          if (param_2 != (undefined1 *)0x0) {

            *param_2 = 1;

          }

          if (param_3 != (undefined1 *)0x0) {

            *param_3 = (char)(local_res8[0] >> 8);

          }

          goto LAB_1402787dc;

        }

      }

    }

    cVar1 = FUN_140279c00(param_1,0xa600fe,2,1);

    if (cVar1 != '\0') {

      cVar1 = FUN_1402796b0(param_1,local_res8);

      if (cVar1 != '\0') {

        if (((local_res8[0] & 0xf0ff) == 5) && (param_2 != (undefined1 *)0x0)) {

          *param_2 = 1;

        }

        goto LAB_1402787dc;

      }

    }

    uVar2 = 0;

  }

  return uVar2;

}




