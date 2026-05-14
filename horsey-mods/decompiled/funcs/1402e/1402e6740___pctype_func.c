// Address: 0x1402e6740
// Ghidra name: __pctype_func
// ============ 0x1402e6740 __pctype_func (size=47) ============


/* Library Function - Single Match

    __pctype_func

   

   Library: Visual Studio 2019 Release */



ushort * __cdecl __pctype_func(void)



{

  longlong lVar1;

  undefined8 *local_res8 [4];

  

  lVar1 = FUN_1402e8664();

  local_res8[0] = *(undefined8 **)(lVar1 + 0x90);

  __acrt_update_locale_info(lVar1,local_res8);

  return (ushort *)*local_res8[0];

}




