// Address: 0x14013d790
// Ghidra name: FUN_14013d790
// ============ 0x14013d790 FUN_14013d790 (size=409) ============


undefined8 FUN_14013d790(undefined8 param_1,int *param_2)



{

  int iVar1;

  char cVar2;

  undefined8 *puVar3;

  undefined4 local_88 [2];

  undefined8 local_80;

  int local_78;

  

  iVar1 = *param_2;

  if (iVar1 == 0x600) {

    _guard_check_icall();

    if (DAT_1403fbef8 != (undefined8 *)0x0) {

      puVar3 = DAT_1403fbef8;

      while (*(int *)*puVar3 != param_2[4]) {

        puVar3 = (undefined8 *)puVar3[10];

        if (puVar3 == (undefined8 *)0x0) {

          return 1;

        }

      }

      FUN_14013c2f0(*(undefined8 *)(param_2 + 2),puVar3,(char)param_2[5],(int)(short)param_2[6]);

    }

  }

  else if (iVar1 == 0x602) {

    _guard_check_icall();

    if (DAT_1403fbef8 != (undefined8 *)0x0) {

      puVar3 = DAT_1403fbef8;

      do {

        if (*(int *)*puVar3 == param_2[4]) {

          FUN_14013c4f0(*(undefined8 *)(param_2 + 2),puVar3,(char)param_2[5],

                        *(undefined1 *)((longlong)param_2 + 0x15));

          return 1;

        }

        puVar3 = (undefined8 *)puVar3[10];

      } while (puVar3 != (undefined8 *)0x0);

      return 1;

    }

  }

  else {

    if ((iVar1 != 0x603) && (iVar1 != 0x604)) {

      if (iVar1 != 0x608) {

        return 1;

      }

      _guard_check_icall();

      cVar2 = FUN_140139420(0x65a);

      if (cVar2 == '\0') {

        return 1;

      }

      if (DAT_1403fbef8 == (undefined8 *)0x0) {

        return 1;

      }

      local_78 = param_2[4];

      puVar3 = DAT_1403fbef8;

      do {

        if (*(int *)*puVar3 == local_78) {

          local_80 = *(undefined8 *)(param_2 + 2);

          local_88[0] = 0x65a;

          FUN_14013b140(local_88);

          return 1;

        }

        puVar3 = (undefined8 *)puVar3[10];

      } while (puVar3 != (undefined8 *)0x0);

      return 1;

    }

    _guard_check_icall();

    if (DAT_1403fbef8 != (undefined8 *)0x0) {

      puVar3 = DAT_1403fbef8;

      do {

        if (*(int *)*puVar3 == param_2[4]) {

          FUN_14013c450(*(undefined8 *)(param_2 + 2),puVar3,(char)param_2[5],

                        *(undefined1 *)((longlong)param_2 + 0x15));

          return 1;

        }

        puVar3 = (undefined8 *)puVar3[10];

      } while (puVar3 != (undefined8 *)0x0);

      return 1;

    }

  }

  return 1;

}




