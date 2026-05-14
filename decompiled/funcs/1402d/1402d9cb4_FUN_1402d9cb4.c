// Address: 0x1402d9cb4
// Ghidra name: FUN_1402d9cb4
// ============ 0x1402d9cb4 FUN_1402d9cb4 (size=307) ============


uint FUN_1402d9cb4(uint param_1,__crt_locale_pointers *param_2)



{

  int iVar1;

  undefined4 *puVar2;

  undefined4 uVar3;

  uint uVar4;

  undefined1 local_res8;

  undefined1 local_res9;

  undefined1 local_resa;

  undefined2 local_res18;

  undefined1 local_res1a;

  longlong local_28;

  longlong *local_20 [2];

  char local_10;

  

  uVar4 = 0xffffffff;

  if (param_1 != 0xffffffff) {

    _LocaleUpdate::_LocaleUpdate((_LocaleUpdate *)&local_28,param_2);

    if (param_1 < 0x100) {

      uVar4 = (uint)*(byte *)(local_20[0][0x22] + ((ulonglong)param_1 & 0xff));

      if (local_10 != '\0') {

        *(uint *)(local_28 + 0x3a8) = *(uint *)(local_28 + 0x3a8) & 0xfffffffd;

      }

    }

    else {

      local_resa = 0;

      if (((int)local_20[0][1] < 2) ||

         (-1 < *(short *)(*local_20[0] + (ulonglong)((int)param_1 >> 8 & 0xff) * 2))) {

        puVar2 = (undefined4 *)FUN_1402e68b0();

        uVar3 = 1;

        *puVar2 = 0x2a;

        local_res9 = 0;

        local_res8 = (char)param_1;

      }

      else {

        uVar3 = 2;

        local_res8 = (char)(param_1 >> 8);

        local_res9 = (char)param_1;

      }

      local_res18 = 0;

      local_res1a = 0;

      iVar1 = __acrt_LCMapStringA(local_20,local_20[0][0x27],0x100,&local_res8,uVar3,&local_res18,3,

                                  *(undefined4 *)((longlong)local_20[0] + 0xc),1);

      uVar4 = param_1;

      if (iVar1 != 0) {

        uVar4 = (uint)(byte)local_res18;

        if (iVar1 != 1) {

          uVar4 = (uint)CONCAT11((byte)local_res18,local_res18._1_1_);

        }

      }

      if (local_10 != '\0') {

        *(uint *)(local_28 + 0x3a8) = *(uint *)(local_28 + 0x3a8) & 0xfffffffd;

      }

    }

  }

  return uVar4;

}




