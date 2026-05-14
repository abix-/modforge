// Address: 0x1402f5a70
// Ghidra name: FUN_1402f5a70
// ============ 0x1402f5a70 FUN_1402f5a70 (size=639) ============


undefined4 FUN_1402f5a70(uint param_1,byte *param_2,uint param_3,char *param_4)



{

  int iVar1;

  int iVar2;

  longlong lVar3;

  undefined4 *puVar4;

  uint uVar5;

  int iVar6;

  uint local_res8 [2];

  

  iVar6 = 0;

  *param_4 = '\0';

  if (-1 < *(char *)((&DAT_1403ff160)[(longlong)(int)param_1 >> 6] + 0x38 +

                    (ulonglong)(param_1 & 0x3f) * 0x48)) {

    return 0;

  }

  if ((param_3 & 0x74000) == 0) {

    local_res8[0] = 0;

    iVar1 = FUN_1402e7ebc();

    if (iVar1 != 0) {

                    /* WARNING: Subroutine does not return */

      _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

    }

    if ((local_res8[0] & 0x74000) == 0) {

      param_3 = param_3 | 0x4000;

    }

    else {

      param_3 = param_3 | local_res8[0] & 0x74000;

    }

  }

  uVar5 = param_3 & 0x74000;

  iVar1 = 2;

  if (uVar5 == 0x4000) {

    *param_4 = '\0';

  }

  else if ((uVar5 - 0x10000 & 0xffffbfff) == 0) {

    if ((param_3 & 0x301) == 0x301) goto LAB_1402f5b37;

  }

  else if ((uVar5 - 0x20000 & 0xffffbfff) == 0) {

LAB_1402f5b37:

    *param_4 = '\x02';

  }

  else if ((uVar5 - 0x40000 & 0xffffbfff) == 0) {

    *param_4 = '\x01';

  }

  if ((param_3 & 0x70000) == 0) {

    return 0;

  }

  if ((*param_2 & 0x40) != 0) {

    return 0;

  }

  uVar5 = *(uint *)(param_2 + 4) & 0xc0000000;

  if (uVar5 == 0x40000000) {

LAB_1402f5b7b:

    iVar2 = *(int *)(param_2 + 8);

    if ((iVar2 != 1) && (iVar2 != 2)) {

      if ((iVar2 == 3) || (iVar2 == 4)) {

        lVar3 = FUN_1402eb16c(param_1,0,2);

        if (lVar3 != 0) {

          lVar3 = FUN_1402eb16c(param_1,0,0);

          if (lVar3 == -1) goto LAB_1402f5be4;

          if ((*(uint *)(param_2 + 4) & 0x80000000) == 0) {

            return 0;

          }

          goto LAB_1402f5bf9;

        }

      }

      else if (iVar2 != 5) {

        return 0;

      }

    }

    if (*param_4 == '\x01') {

      iVar1 = 3;

      local_res8[0] = 0xbfbbef;

    }

    else {

      if (*param_4 != '\x02') {

        return 0;

      }

      local_res8[0] = 0xfeff;

    }

    while (iVar2 = FUN_1402ee474(param_1,(longlong)local_res8 + (longlong)iVar6,iVar1 - iVar6),

          iVar2 != -1) {

      iVar6 = iVar6 + iVar2;

      if (iVar1 <= iVar6) {

        return 0;

      }

    }

    goto LAB_1402f5be4;

  }

  if (uVar5 != 0x80000000) {

    if (uVar5 != 0xc0000000) {

      return 0;

    }

    goto LAB_1402f5b7b;

  }

LAB_1402f5bf9:

  local_res8[0] = 0;

  iVar6 = FUN_1402ea824(param_1,local_res8,3);

  if (iVar6 == -1) goto LAB_1402f5be4;

  if (iVar6 == 2) {

LAB_1402f5c32:

    if ((local_res8[0] & 0xffff) == 0xfffe) {

      puVar4 = (undefined4 *)FUN_1402e68b0();

      *puVar4 = 0x16;

      goto LAB_1402f5be4;

    }

    if ((local_res8[0] & 0xffff) == 0xfeff) {

      lVar3 = FUN_1402eb16c(param_1,2,0);

      if (lVar3 != -1) {

        *param_4 = '\x02';

        return 0;

      }

      goto LAB_1402f5be4;

    }

  }

  else if (iVar6 == 3) {

    if (local_res8[0] == 0xbfbbef) {

      *param_4 = '\x01';

      return 0;

    }

    goto LAB_1402f5c32;

  }

  lVar3 = FUN_1402eb16c(param_1,0,0);

  if (lVar3 != -1) {

    return 0;

  }

LAB_1402f5be4:

  puVar4 = (undefined4 *)FUN_1402e68b0();

  return *puVar4;

}




