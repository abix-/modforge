// Address: 0x1402d9c18
// Ghidra name: _LocaleUpdate
// ============ 0x1402d9c18 _LocaleUpdate (size=155) ============


/* Library Function - Single Match

    public: __cdecl _LocaleUpdate::_LocaleUpdate(struct __crt_locale_pointers * __ptr64 const)

   __ptr64

   

   Libraries: Visual Studio 2017 Debug, Visual Studio 2017 Release, Visual Studio 2019 Debug, Visual

   Studio 2019 Release */



_LocaleUpdate * __thiscall

_LocaleUpdate::_LocaleUpdate(_LocaleUpdate *this,__crt_locale_pointers *param_1)



{

  _LocaleUpdate *p_Var1;

  uint uVar2;

  longlong lVar3;

  undefined4 uVar4;

  undefined4 uVar5;

  undefined4 uVar6;

  undefined4 uVar7;

  

  this[0x18] = (_LocaleUpdate)0x0;

  p_Var1 = this + 8;

  if (param_1 == (__crt_locale_pointers *)0x0) {

    uVar4 = PTR_PTR_1403e8e88._0_4_;

    uVar5 = PTR_PTR_1403e8e88._4_4_;

    uVar6 = PTR_DAT_1403e8e90._0_4_;

    uVar7 = PTR_DAT_1403e8e90._4_4_;

    if (DAT_1403ff13c != 0) {

      lVar3 = FUN_1402e8664();

      *(longlong *)this = lVar3;

      *(undefined8 *)p_Var1 = *(undefined8 *)(lVar3 + 0x90);

      *(undefined8 *)(this + 0x10) = *(undefined8 *)(lVar3 + 0x88);

      __acrt_update_locale_info(lVar3,p_Var1);

      FUN_1402eef30(*(undefined8 *)this,this + 0x10);

      uVar2 = *(uint *)(*(longlong *)this + 0x3a8);

      if ((uVar2 & 2) != 0) {

        return this;

      }

      *(uint *)(*(longlong *)this + 0x3a8) = uVar2 | 2;

      this[0x18] = (_LocaleUpdate)0x1;

      return this;

    }

  }

  else {

    uVar4 = *(undefined4 *)param_1;

    uVar5 = *(undefined4 *)(param_1 + 4);

    uVar6 = *(undefined4 *)(param_1 + 8);

    uVar7 = *(undefined4 *)(param_1 + 0xc);

  }

  *(undefined4 *)p_Var1 = uVar4;

  *(undefined4 *)(this + 0xc) = uVar5;

  *(undefined4 *)(this + 0x10) = uVar6;

  *(undefined4 *)(this + 0x14) = uVar7;

  return this;

}




