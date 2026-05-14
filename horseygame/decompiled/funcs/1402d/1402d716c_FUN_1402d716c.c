// Address: 0x1402d716c
// Ghidra name: FUN_1402d716c
// ============ 0x1402d716c FUN_1402d716c (size=196) ============


undefined8 FUN_1402d716c(__uint64 *param_1)



{

  undefined2 uVar1;

  undefined2 *puVar2;

  __uint64 _Var3;

  int iVar4;

  __uint64 *p_Var5;

  undefined1 local_res8;

  undefined1 local_res9;

  

  *(undefined1 *)((longlong)param_1 + 0x4c) = 1;

  puVar2 = (undefined2 *)param_1[3];

  param_1[3] = (__uint64)(puVar2 + 4);

  uVar1 = *puVar2;

  local_res9 = __crt_stdio_output::is_wide_character_specifier<wchar_t>

                         (*param_1,*(wchar_t *)((longlong)param_1 + 0x3a),

                          *(length_modifier *)((longlong)param_1 + 0x34));

  if ((bool)local_res9) {

    p_Var5 = (__uint64 *)param_1[0x8b];

    if ((__uint64 *)param_1[0x8b] == (__uint64 *)0x0) {

      p_Var5 = param_1 + 10;

    }

    *(undefined2 *)p_Var5 = uVar1;

  }

  else {

    local_res8 = (undefined1)uVar1;

    _Var3 = param_1[1];

    if (*(char *)(_Var3 + 0x28) == '\0') {

      FUN_1402d74e0(_Var3);

    }

    p_Var5 = (__uint64 *)param_1[0x8b];

    if ((__uint64 *)param_1[0x8b] == (__uint64 *)0x0) {

      p_Var5 = param_1 + 10;

    }

    iVar4 = FUN_1402eff44(p_Var5,&local_res8,(longlong)*(int *)(*(longlong *)(_Var3 + 0x18) + 8),

                          _Var3);

    if (iVar4 < 0) {

      *(undefined1 *)(param_1 + 7) = 1;

    }

  }

  *(undefined4 *)(param_1 + 9) = 1;

  p_Var5 = (__uint64 *)param_1[0x8b];

  if ((__uint64 *)param_1[0x8b] == (__uint64 *)0x0) {

    p_Var5 = param_1 + 10;

  }

  param_1[8] = (__uint64)p_Var5;

  return 1;

}




