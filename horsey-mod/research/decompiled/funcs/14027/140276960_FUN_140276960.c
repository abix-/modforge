// Address: 0x140276960
// Ghidra name: FUN_140276960
// ============ 0x140276960 FUN_140276960 (size=323) ============


int FUN_140276960(longlong param_1,undefined8 *param_2)



{

  int iVar1;

  int iVar2;

  int iVar3;

  undefined1 local_d8;

  undefined8 local_d7;

  undefined8 uStack_cf;

  undefined4 local_c7;

  undefined1 local_b8 [160];

  

  if (*(char *)(param_1 + 0x54) == '\0') {

    *param_2 = 0;

    param_2[1] = 0;

    iVar3 = 0;

    param_2[2] = 0;

    param_2[3] = 0;

    param_2[4] = 0;

    param_2[5] = 0;

    param_2[6] = 0;

    param_2[7] = 0;

    *(undefined1 *)(param_2 + 8) = 0;

    do {

      iVar2 = FUN_140193250(*(undefined8 *)(param_1 + 0x80),param_2,0x41);

      if (-1 < iVar2) {

        return iVar2;

      }

      thunk_FUN_140184480(500000);

      iVar3 = iVar3 + 1;

    } while (iVar3 < 0x32);

  }

  else {

    iVar3 = 0;

    FUN_140276b90(local_b8);

    do {

      local_c7 = 0;

      local_d8 = 3;

      local_d7 = 0;

      uStack_cf = 0;

      iVar2 = FUN_140193250(*(undefined8 *)(param_1 + 0x80),&local_d8,0x15);

      if (((2 < iVar2) && (iVar1 = 0, local_d7._1_1_ < '\0')) ||

         (iVar3 = iVar3 + 1, iVar1 = iVar3, 0 < iVar2)) {

        iVar3 = iVar1;

        iVar2 = FUN_140277670(local_b8,&local_d7,iVar2 + -1);

        if (iVar2 - 1U < 0x40) {

          *(undefined1 *)param_2 = 0;

          FUN_1402f8e20((undefined1 *)((longlong)param_2 + 1),local_b8,(longlong)iVar2);

          return iVar2;

        }

      }

    } while (iVar3 < 8);

    FUN_14012e310("Could not get a full ble packet after %d retries\n",iVar3);

    iVar2 = -1;

  }

  return iVar2;

}




