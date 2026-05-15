// Address: 0x1402dfcc0
// Ghidra name: FUN_1402dfcc0
// ============ 0x1402dfcc0 FUN_1402dfcc0 (size=477) ============


undefined8

FUN_1402dfcc0(input_processor<char,__crt_stdio_input::string_input_adapter<char>_> *param_1,

             int param_2)



{

  byte bVar1;

  undefined8 *puVar2;

  wchar_t *pwVar3;

  undefined4 *puVar4;

  wchar_t *pwVar5;

  wchar_t *pwVar6;

  __uint64 _Var7;

  byte *pbVar8;

  uint uVar9;

  __uint64 _Var10;

  bool bVar11;

  __uint64 local_res8;

  wchar_t *local_res20;

  

  pwVar5 = (wchar_t *)0x0;

  pwVar6 = pwVar5;

  if (param_1[0x3a] == (input_processor<char,__crt_stdio_input::string_input_adapter<char>_>)0x0) {

    puVar2 = *(undefined8 **)(param_1 + 0x80);

    *(undefined8 **)(param_1 + 0x80) = puVar2 + 1;

    pwVar6 = (wchar_t *)*puVar2;

    if (pwVar6 == (wchar_t *)0x0) {

      puVar4 = (undefined4 *)FUN_1402e68b0();

      *puVar4 = 0x16;

      FUN_1402cd454();

      return 0;

    }

    if (((byte)*param_1 & 1) != 0) {

      *(undefined8 **)(param_1 + 0x80) = puVar2 + 2;

      _Var7 = (__uint64)*(uint *)(puVar2 + 1);

      if (_Var7 == 0) {

        if (((byte)*param_1 & 4) != 0) {

          if (*(longlong *)(param_1 + 0x18) != *(longlong *)(param_1 + 0x10)) {

            *(longlong *)(param_1 + 0x18) = *(longlong *)(param_1 + 0x18) + 1;

          }

LAB_1402dfd5c:

          *pwVar6 = L'\0';

        }

LAB_1402dfd60:

        puVar4 = (undefined4 *)FUN_1402e68b0();

        *puVar4 = 0xc;

        return 0;

      }

      goto LAB_1402dfd71;

    }

  }

  _Var7 = 0xffffffffffffffff;

LAB_1402dfd71:

  pwVar3 = *(wchar_t **)(param_1 + 0x40);

  _Var10 = _Var7;

  local_res8 = _Var7;

  local_res20 = pwVar6;

  if ((param_2 != 0) && (_Var7 != 0xffffffffffffffff)) {

    _Var10 = _Var7 - 1;

    local_res8 = _Var10;

  }

  while( true ) {

    if ((pwVar3 != (wchar_t *)0x0) && (pwVar5 == pwVar3)) goto LAB_1402dfe66;

    pbVar8 = *(byte **)(param_1 + 0x18);

    if (pbVar8 == *(byte **)(param_1 + 0x10)) {

      uVar9 = 0xffffffff;

      goto LAB_1402dfe4c;

    }

    bVar1 = *pbVar8;

    uVar9 = (uint)bVar1;

    pbVar8 = pbVar8 + 1;

    *(byte **)(param_1 + 0x18) = pbVar8;

    if (param_2 != 0) break;

LAB_1402dfdfb:

    if (param_1[0x3a] == (input_processor<char,__crt_stdio_input::string_input_adapter<char>_>)0x0)

    {

      if (_Var10 == 0) {

        if (_Var7 != 0xffffffffffffffff) goto LAB_1402dfd5c;

        goto LAB_1402dfd60;

      }

      bVar11 = __crt_stdio_input::

               input_processor<char,__crt_stdio_input::string_input_adapter<char>_>::write_character

                         (param_1,pwVar6,_Var7,&local_res20,&local_res8,bVar1);

      _Var10 = local_res8;

      if (!bVar11) goto LAB_1402dfe66;

    }

    pwVar5 = (wchar_t *)((longlong)pwVar5 + 1);

  }

  if (param_2 == 1) {

    if (4 < bVar1 - 9) {

      bVar11 = bVar1 == 0x20;

      goto LAB_1402dfdf9;

    }

  }

  else if (param_2 == 8) {

    bVar11 = ((byte)param_1[(ulonglong)(bVar1 >> 3) + 0x54] & (byte)(1 << (bVar1 & 7))) == 0;

LAB_1402dfdf9:

    if (!bVar11) goto LAB_1402dfdfb;

  }

LAB_1402dfe4c:

  if ((pbVar8 != *(byte **)(param_1 + 8)) &&

     ((pbVar8 != *(byte **)(param_1 + 0x10) || (uVar9 != 0xffffffff)))) {

    *(byte **)(param_1 + 0x18) = pbVar8 + -1;

  }

LAB_1402dfe66:

  if ((pwVar5 != (wchar_t *)0x0) &&

     (((param_2 != 0 || (pwVar5 == pwVar3)) || (((byte)*param_1 & 4) != 0)))) {

    if ((param_1[0x3a] == (input_processor<char,__crt_stdio_input::string_input_adapter<char>_>)0x0)

       && (param_2 != 0)) {

      *local_res20 = L'\0';

    }

    return 1;

  }

  return 0;

}




