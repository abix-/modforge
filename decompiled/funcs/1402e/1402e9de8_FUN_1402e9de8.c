// Address: 0x1402e9de8
// Ghidra name: FUN_1402e9de8
// ============ 0x1402e9de8 FUN_1402e9de8 (size=362) ============


ulonglong FUN_1402e9de8(FILE *param_1)



{

  uint *puVar1;

  byte bVar2;

  char *pcVar3;

  int iVar4;

  int iVar5;

  uint uVar6;

  undefined4 *puVar7;

  undefined *puVar8;

  

  if (param_1 == (FILE *)0x0) {

    puVar7 = (undefined4 *)FUN_1402e68b0();

    *puVar7 = 0x16;

    FUN_1402cd454();

  }

  else if (((*(uint *)((longlong)&param_1->_base + 4) >> 0xd & 1) != 0) &&

          ((*(uint *)((longlong)&param_1->_base + 4) >> 0xc & 1) == 0)) {

    if ((*(uint *)((longlong)&param_1->_base + 4) >> 1 & 1) == 0) {

      LOCK();

      puVar1 = (uint *)((longlong)&param_1->_base + 4);

      *puVar1 = *puVar1 | 1;

      UNLOCK();

      if (((ulonglong)param_1->_base & 0x4c000000000) == 0) {

        __acrt_stdio_allocate_buffer_nolock();

      }

      pcVar3 = *(char **)&param_1->_cnt;

      iVar5 = param_1->_charbuf;

      param_1->_ptr = pcVar3;

      iVar4 = _fileno(param_1);

      iVar5 = FUN_1402ea704(iVar4,pcVar3,iVar5);

      *(int *)&param_1->_base = iVar5;

      if (1 < iVar5 + 1U) {

        if (((ulonglong)param_1->_base & 0x600000000) == 0) {

          iVar5 = _fileno(param_1);

          if ((iVar5 == -1) || (iVar5 = _fileno(param_1), iVar5 == -2)) {

            puVar8 = &DAT_1403e8ea0;

          }

          else {

            iVar5 = _fileno(param_1);

            uVar6 = _fileno(param_1);

            puVar8 = (undefined *)

                     ((&DAT_1403ff160)[(longlong)iVar5 >> 6] + (ulonglong)(uVar6 & 0x3f) * 0x48);

          }

          if ((puVar8[0x38] & 0x82) == 0x82) {

            LOCK();

            puVar1 = (uint *)((longlong)&param_1->_base + 4);

            *puVar1 = *puVar1 | 0x20;

            UNLOCK();

          }

        }

        if (((param_1->_charbuf == 0x200) &&

            ((*(uint *)((longlong)&param_1->_base + 4) >> 6 & 1) != 0)) &&

           ((*(uint *)((longlong)&param_1->_base + 4) >> 8 & 1) == 0)) {

          param_1->_charbuf = 0x1000;

        }

        *(int *)&param_1->_base = *(int *)&param_1->_base + -1;

        bVar2 = *param_1->_ptr;

        param_1->_ptr = param_1->_ptr + 1;

        return (ulonglong)bVar2;

      }

      LOCK();

      puVar1 = (uint *)((longlong)&param_1->_base + 4);

      *puVar1 = *puVar1 | (-(uint)(iVar5 != 0) & 8) + 8;

      UNLOCK();

      *(undefined4 *)&param_1->_base = 0;

    }

    else {

      LOCK();

      puVar1 = (uint *)((longlong)&param_1->_base + 4);

      *puVar1 = *puVar1 | 0x10;

      UNLOCK();

    }

  }

  return 0xffffffff;

}




