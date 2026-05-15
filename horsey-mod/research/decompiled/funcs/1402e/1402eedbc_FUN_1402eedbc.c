// Address: 0x1402eedbc
// Ghidra name: FUN_1402eedbc
// ============ 0x1402eedbc FUN_1402eedbc (size=199) ============


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



undefined8 FUN_1402eedbc(longlong *param_1)



{

  char cVar1;

  longlong *plVar2;

  longlong lVar3;

  

  cVar1 = FUN_1402eed70();

  if (cVar1 != '\0') {

    plVar2 = (longlong *)FUN_1402e16a0(1);

    if (param_1 == plVar2) {

      plVar2 = &DAT_1403ff638;

    }

    else {

      plVar2 = (longlong *)FUN_1402e16a0(2);

      if (param_1 != plVar2) {

        return 0;

      }

      plVar2 = &DAT_1403ff640;

    }

    _DAT_1403fed38 = _DAT_1403fed38 + 1;

    if ((*(uint *)((longlong)param_1 + 0x14) & 0x4c0) == 0) {

      LOCK();

      *(uint *)((longlong)param_1 + 0x14) = *(uint *)((longlong)param_1 + 0x14) | 0x282;

      UNLOCK();

      if (*plVar2 == 0) {

        lVar3 = _malloc_base(0x1000);

        *plVar2 = lVar3;

        FUN_1402e9a80(0);

      }

      if (*plVar2 == 0) {

        *(undefined4 *)(param_1 + 2) = 2;

        param_1[1] = (longlong)param_1 + 0x1c;

        *param_1 = (longlong)param_1 + 0x1c;

        *(undefined4 *)(param_1 + 4) = 2;

      }

      else {

        param_1[1] = *plVar2;

        *param_1 = *plVar2;

        *(undefined4 *)(param_1 + 2) = 0x1000;

        *(undefined4 *)(param_1 + 4) = 0x1000;

      }

      return 1;

    }

  }

  return 0;

}




