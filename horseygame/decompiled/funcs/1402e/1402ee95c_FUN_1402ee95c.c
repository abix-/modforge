// Address: 0x1402ee95c
// Ghidra name: FUN_1402ee95c
// ============ 0x1402ee95c FUN_1402ee95c (size=247) ============


bool FUN_1402ee95c(undefined1 param_1,FILE *param_2,undefined8 param_3)



{

  uint *puVar1;

  uint uVar2;

  int iVar3;

  longlong lVar4;

  undefined *puVar5;

  int iVar6;

  bool bVar7;

  undefined1 local_res8 [8];

  

  local_res8[0] = param_1;

  uVar2 = _fileno(param_2);

  if (((ulonglong)param_2->_base & 0xc000000000) == 0) {

    iVar3 = FUN_1402ee50c(uVar2,local_res8,1,param_3);

    bVar7 = iVar3 == 1;

  }

  else {

    iVar3 = 0;

    iVar6 = *(int *)&param_2->_ptr - param_2->_cnt;

    param_2->_ptr = (char *)(*(longlong *)&param_2->_cnt + 1);

    *(int *)&param_2->_base = param_2->_charbuf + -1;

    if (iVar6 < 1) {

      if (uVar2 + 2 < 2) {

        puVar5 = &DAT_1403e8ea0;

      }

      else {

        puVar5 = (undefined *)

                 ((&DAT_1403ff160)[(longlong)(int)uVar2 >> 6] + (ulonglong)(uVar2 & 0x3f) * 0x48);

      }

      if (((puVar5[0x38] & 0x20) != 0) && (lVar4 = FUN_1402eb0c8(uVar2,0,2), lVar4 == -1)) {

        LOCK();

        puVar1 = (uint *)((longlong)&param_2->_base + 4);

        *puVar1 = *puVar1 | 0x10;

        UNLOCK();

        return true;

      }

    }

    else {

      iVar3 = FUN_1402ee50c(uVar2,*(longlong *)&param_2->_cnt,iVar6,param_3);

    }

    bVar7 = iVar3 == iVar6;

    **(undefined1 **)&param_2->_cnt = local_res8[0];

  }

  return bVar7;

}




