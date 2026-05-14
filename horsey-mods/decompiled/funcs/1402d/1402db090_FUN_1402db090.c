// Address: 0x1402db090
// Ghidra name: FUN_1402db090
// ============ 0x1402db090 FUN_1402db090 (size=22) ============


ulonglong FUN_1402db090(byte param_1,FILE *param_2,longlong param_3)



{

  char **ppcVar1;

  uint *puVar2;

  char cVar3;

  

  ppcVar1 = &param_2->_base;

  *(int *)ppcVar1 = *(int *)ppcVar1 + -1;

  if (-1 < *(int *)ppcVar1) {

    *param_2->_ptr = param_1;

    param_2->_ptr = param_2->_ptr + 1;

    return (ulonglong)param_1;

  }

  _fileno(param_2);

  if (((ulonglong)param_2->_base & 0x600000000) == 0) {

    *(undefined4 *)(param_3 + 0x2c) = 9;

  }

  else {

    if ((*(uint *)((longlong)&param_2->_base + 4) >> 0xc & 1) == 0) {

      if (((ulonglong)param_2->_base & 0x100000000) != 0) {

        cVar3 = FUN_1402eeb50(param_2);

        *(undefined4 *)&param_2->_base = 0;

        if (cVar3 == '\0') goto LAB_1402eec0a;

        param_2->_ptr = *(char **)&param_2->_cnt;

        LOCK();

        puVar2 = (uint *)((longlong)&param_2->_base + 4);

        *puVar2 = *puVar2 & 0xfffffffe;

        UNLOCK();

      }

      LOCK();

      puVar2 = (uint *)((longlong)&param_2->_base + 4);

      *puVar2 = *puVar2 | 2;

      UNLOCK();

      LOCK();

      puVar2 = (uint *)((longlong)&param_2->_base + 4);

      *puVar2 = *puVar2 & 0xfffffff7;

      UNLOCK();

      *(undefined4 *)&param_2->_base = 0;

      if ((((ulonglong)param_2->_base & 0x4c000000000) == 0) &&

         (cVar3 = FUN_1402eed70(param_2), cVar3 == '\0')) {

        __acrt_stdio_allocate_buffer_nolock(param_2);

      }

      cVar3 = FUN_1402ee95c(param_1,param_2,param_3);

      if (cVar3 != '\0') {

        return (ulonglong)param_1;

      }

      goto LAB_1402eec0a;

    }

    *(undefined4 *)(param_3 + 0x2c) = 0x22;

  }

  *(undefined1 *)(param_3 + 0x30) = 1;

LAB_1402eec0a:

  LOCK();

  puVar2 = (uint *)((longlong)&param_2->_base + 4);

  *puVar2 = *puVar2 | 0x10;

  UNLOCK();

  return 0xffffffff;

}




