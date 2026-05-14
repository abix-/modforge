// Address: 0x1402e73e8
// Ghidra name: FUN_1402e73e8
// ============ 0x1402e73e8 FUN_1402e73e8 (size=381) ============


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



int FUN_1402e73e8(int param_1)



{

  longlong lVar1;

  longlong *plVar2;

  int iVar3;

  undefined4 *puVar4;

  longlong *plVar5;

  char *pcVar6;

  int iVar7;

  longlong *local_res10;

  longlong local_res18;

  undefined8 local_res20;

  

  iVar7 = 0;

  if (param_1 == 0) {

    return 0;

  }

  if (1 < param_1 - 1U) {

    puVar4 = (undefined4 *)FUN_1402e68b0();

    *puVar4 = 0x16;

    FUN_1402cd454();

    return 0x16;

  }

  __acrt_initialize_multibyte();

  FUN_1402f1224(0,&DAT_1403fefd0,0x104);

  _DAT_1403ff770 = &DAT_1403fefd0;

  if ((DAT_1403ff790 == (char *)0x0) || (pcVar6 = DAT_1403ff790, *DAT_1403ff790 == '\0')) {

    pcVar6 = &DAT_1403fefd0;

  }

  local_res18 = 0;

  local_res20 = 0;

  FUN_1402e71c8(pcVar6,0,0,&local_res18,&local_res20);

  lVar1 = local_res18;

  plVar5 = (longlong *)__acrt_allocate_buffer_for_argv(local_res18,local_res20,1);

  if (plVar5 == (longlong *)0x0) {

    puVar4 = (undefined4 *)FUN_1402e68b0();

    iVar7 = 0xc;

    *puVar4 = 0xc;

  }

  else {

    FUN_1402e71c8(pcVar6,plVar5,plVar5 + lVar1,&local_res18,&local_res20);

    if (param_1 != 1) {

      local_res10 = (longlong *)0x0;

      iVar3 = thunk_FUN_1402f34d0(plVar5,&local_res10);

      plVar2 = local_res10;

      if (iVar3 != 0) {

        FUN_1402e9a80(local_res10);

        local_res10 = (longlong *)0x0;

        FUN_1402e9a80(plVar5);

        return iVar3;

      }

      _DAT_1403ff778 = 0;

      lVar1 = *local_res10;

      while (lVar1 != 0) {

        local_res10 = local_res10 + 1;

        _DAT_1403ff778 = _DAT_1403ff778 + 1;

        lVar1 = *local_res10;

      }

      local_res10 = (longlong *)0x0;

      DAT_1403ff780 = plVar2;

      FUN_1402e9a80(0);

      local_res10 = (longlong *)0x0;

      goto LAB_1402e754d;

    }

    _DAT_1403ff778 = (int)local_res18 + -1;

    DAT_1403ff780 = plVar5;

  }

  plVar5 = (longlong *)0x0;

LAB_1402e754d:

  FUN_1402e9a80(plVar5);

  return iVar7;

}




