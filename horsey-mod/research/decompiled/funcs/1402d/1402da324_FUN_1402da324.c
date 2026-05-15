// Address: 0x1402da324
// Ghidra name: FUN_1402da324
// ============ 0x1402da324 FUN_1402da324 (size=421) ============


undefined4 FUN_1402da324(longlong param_1,FILE *param_2)



{

  undefined4 uVar1;

  uint uVar2;

  undefined4 uVar3;

  longlong lVar4;

  undefined *puVar5;

  undefined *puVar6;

  undefined1 local_res8 [8];

  longlong local_res10;

  FILE *local_res18;

  longlong local_res20;

  FILE *local_98;

  FILE *local_90;

  FILE **local_88;

  longlong *local_80;

  longlong *local_78;

  longlong *local_70;

  longlong local_68 [2];

  undefined1 local_58;

  undefined *local_50;

  undefined *puStack_48;

  char local_40;

  undefined4 local_3c;

  char local_38;

  undefined4 local_34;

  char local_30;

  

  local_40 = DAT_1403ff13c == 0;

  local_68[0] = 0;

  local_58 = 0;

  local_38 = '\0';

  local_30 = '\0';

  if ((bool)local_40) {

    local_50 = PTR_PTR_1403e8e88;

    puStack_48 = PTR_DAT_1403e8e90;

  }

  local_res10 = param_1;

  local_res18 = param_2;

  if ((param_1 != 0) && (param_2 != (FILE *)0x0)) {

    if ((*(uint *)((longlong)&param_2->_base + 4) >> 0xc & 1) != 0) {

LAB_1402da428:

      local_res20 = -1;

      do {

        local_res20 = local_res20 + 1;

      } while (*(char *)(local_res10 + local_res20) != '\0');

      local_88 = &local_res18;

      local_80 = local_68;

      local_78 = &local_res10;

      local_70 = &local_res20;

      local_98 = local_res18;

      local_90 = local_res18;

      uVar3 = operator()<>(local_res8,&local_90,&local_88,&local_98);

      goto LAB_1402da480;

    }

    uVar2 = _fileno(param_2);

    puVar5 = &DAT_1403e8ea0;

    if (uVar2 + 2 < 2) {

      puVar6 = &DAT_1403e8ea0;

    }

    else {

      puVar6 = (undefined *)

               ((&DAT_1403ff160)[(longlong)(int)uVar2 >> 6] + (ulonglong)(uVar2 & 0x3f) * 0x48);

    }

    if (puVar6[0x39] == '\0') {

      if (1 < uVar2 + 2) {

        puVar5 = (undefined *)

                 ((&DAT_1403ff160)[(longlong)(int)uVar2 >> 6] + (ulonglong)(uVar2 & 0x3f) * 0x48);

      }

      if ((puVar5[0x3d] & 1) == 0) goto LAB_1402da428;

    }

  }

  local_38 = '\x01';

  local_3c = 0x16;

  FUN_1402cd39c(0,0,0,0,0,local_68);

  uVar3 = 0xffffffff;

LAB_1402da480:

  uVar1 = local_3c;

  if (local_40 == '\x02') {

    *(uint *)(local_68[0] + 0x3a8) = *(uint *)(local_68[0] + 0x3a8) & 0xfffffffd;

  }

  if (local_38 != '\0') {

    lVar4 = FUN_1402cd068(local_68);

    *(undefined4 *)(lVar4 + 0x20) = uVar1;

  }

  if (local_30 != '\0') {

    lVar4 = FUN_1402cd068(local_68);

    *(undefined4 *)(lVar4 + 0x24) = local_34;

  }

  return uVar3;

}




