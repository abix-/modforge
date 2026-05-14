// Address: 0x1402f07a8
// Ghidra name: _isctype_l
// ============ 0x1402f07a8 _isctype_l (size=264) ============


/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

/* Library Function - Single Match

    _isctype_l

   

   Library: Visual Studio 2019 Release */



int __cdecl _isctype_l(int _C,int _Type,_locale_t _Locale)



{

  int iVar1;

  undefined8 uVar2;

  undefined1 auStack_88 [32];

  undefined4 *local_68;

  undefined4 local_60;

  undefined4 local_58;

  undefined1 local_48;

  undefined1 local_47;

  undefined1 local_46;

  longlong local_40;

  longlong *local_38 [2];

  char local_28;

  undefined4 local_20;

  undefined2 local_1c;

  ulonglong local_18;

  

  local_18 = DAT_1403e8b00 ^ (ulonglong)auStack_88;

  _LocaleUpdate::_LocaleUpdate((_LocaleUpdate *)&local_40,(__crt_locale_pointers *)_Locale);

  if (_C + 1U < 0x101) {

    local_20._0_2_ = *(ushort *)(*local_38[0] + (longlong)_C * 2);

  }

  else {

    if (*(short *)(*local_38[0] + (ulonglong)(_C >> 8 & 0xff) * 2) < 0) {

      uVar2 = 2;

      local_46 = 0;

      local_48 = (char)((uint)_C >> 8);

      local_47 = (char)_C;

    }

    else {

      uVar2 = 1;

      local_47 = 0;

      local_48 = (char)_C;

    }

    local_58 = 1;

    local_20 = 0;

    local_1c = 0;

    local_60 = *(undefined4 *)((longlong)local_38[0] + 0xc);

    local_68 = &local_20;

    iVar1 = FUN_1402f2fc0(local_38,1,&local_48,uVar2);

    if (iVar1 == 0) {

      if (local_28 != '\0') {

        *(uint *)(local_40 + 0x3a8) = *(uint *)(local_40 + 0x3a8) & 0xfffffffd;

      }

      return 0;

    }

  }

  if (local_28 != '\0') {

    *(uint *)(local_40 + 0x3a8) = *(uint *)(local_40 + 0x3a8) & 0xfffffffd;

  }

  return (uint)(ushort)local_20 & _Type;

}




