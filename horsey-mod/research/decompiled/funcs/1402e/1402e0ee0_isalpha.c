// Address: 0x1402e0ee0
// Ghidra name: isalpha
// ============ 0x1402e0ee0 isalpha (size=171) ============


/* Library Function - Single Match

    isalpha

   

   Library: Visual Studio 2019 Release */



int __cdecl isalpha(int _C)



{

  int iVar1;

  longlong lVar2;

  longlong *local_res10 [3];

  

  if (DAT_1403ff13c == 0) {

    if (_C + 1U < 0x101) {

      return *(ushort *)(PTR_DAT_1403e8d30 + (longlong)_C * 2) & 0x103;

    }

  }

  else {

    lVar2 = FUN_1402e8664();

    local_res10[0] = *(longlong **)(lVar2 + 0x90);

    __acrt_update_locale_info(lVar2,local_res10);

    if (_C + 1U < 0x101) {

      return *(ushort *)(*local_res10[0] + (longlong)_C * 2) & 0x103;

    }

    if (1 < (int)local_res10[0][1]) {

      iVar1 = _isctype_l(_C,0x103,(_locale_t)0x0);

      return iVar1;

    }

  }

  return 0;

}




