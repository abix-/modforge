// Address: 0x14017b920
// Ghidra name: FUN_14017b920
// ============ 0x14017b920 FUN_14017b920 (size=315) ============


undefined8 FUN_14017b920(undefined4 *param_1,undefined4 param_2)



{

  undefined8 uVar1;

  ulonglong uVar2;

  char cVar3;

  int local_res18 [2];

  uint local_res20 [2];

  uint local_18;

  uint local_14;

  uint local_10 [2];

  

  uVar1 = FUN_14017a540(param_2,local_res18,local_res20,&local_18,&local_14,local_10);

  if ((char)uVar1 == '\0') {

    return uVar1;

  }

  *(undefined2 *)((longlong)param_1 + 6) = 0;

  *(char *)(param_1 + 1) = (char)local_res18[0];

  *param_1 = param_2;

  *(undefined1 *)(param_1 + 7) = 0;

  *(undefined1 *)(param_1 + 6) = 0;

  *(char *)((longlong)param_1 + 5) =

       (char)((int)(local_res18[0] + 7 + (local_res18[0] + 7 >> 0x1f & 7U)) >> 3);

  param_1[2] = local_res20[0];

  if (local_res20[0] != 0) {

    if ((local_res20[0] & 1) == 0) {

      cVar3 = '\0';

      do {

        cVar3 = cVar3 + '\x01';

        local_res20[0] = local_res20[0] >> 1;

      } while ((local_res20[0] & 1) == 0);

      *(char *)(param_1 + 7) = cVar3;

    }

    cVar3 = '\0';

    do {

      cVar3 = cVar3 + '\x01';

      local_res20[0] = local_res20[0] >> 1;

    } while ((local_res20[0] & 1) != 0);

    *(char *)(param_1 + 6) = cVar3;

  }

  param_1[3] = local_18;

  *(undefined1 *)((longlong)param_1 + 0x1d) = 0;

  *(undefined1 *)((longlong)param_1 + 0x19) = 0;

  if (local_18 != 0) {

    if ((local_18 & 1) == 0) {

      cVar3 = '\0';

      do {

        cVar3 = cVar3 + '\x01';

        local_18 = local_18 >> 1;

      } while ((local_18 & 1) == 0);

      *(char *)((longlong)param_1 + 0x1d) = cVar3;

    }

    cVar3 = '\0';

    do {

      cVar3 = cVar3 + '\x01';

      local_18 = local_18 >> 1;

    } while ((local_18 & 1) != 0);

    *(char *)((longlong)param_1 + 0x19) = cVar3;

  }

  param_1[4] = local_14;

  *(undefined1 *)((longlong)param_1 + 0x1e) = 0;

  *(undefined1 *)((longlong)param_1 + 0x1a) = 0;

  if (local_14 != 0) {

    if ((local_14 & 1) == 0) {

      cVar3 = '\0';

      do {

        cVar3 = cVar3 + '\x01';

        local_14 = local_14 >> 1;

      } while ((local_14 & 1) == 0);

      *(char *)((longlong)param_1 + 0x1e) = cVar3;

    }

    cVar3 = '\0';

    do {

      cVar3 = cVar3 + '\x01';

      local_14 = local_14 >> 1;

    } while ((local_14 & 1) != 0);

    *(char *)((longlong)param_1 + 0x1a) = cVar3;

  }

  uVar2 = (ulonglong)local_10[0];

  param_1[5] = local_10[0];

  *(undefined1 *)((longlong)param_1 + 0x1f) = 0;

  *(undefined1 *)((longlong)param_1 + 0x1b) = 0;

  if (local_10[0] != 0) {

    if ((local_10[0] & 1) == 0) {

      cVar3 = '\0';

      do {

        cVar3 = cVar3 + '\x01';

        uVar2 = uVar2 >> 1;

      } while ((uVar2 & 1) == 0);

      *(char *)((longlong)param_1 + 0x1f) = cVar3;

    }

    cVar3 = '\0';

    do {

      cVar3 = cVar3 + '\x01';

      uVar2 = uVar2 >> 1;

    } while ((uVar2 & 1) != 0);

    *(char *)((longlong)param_1 + 0x1b) = cVar3;

  }

  return CONCAT71((int7)(uVar2 >> 8),1);

}




