// Address: 0x1402e7388
// Ghidra name: __acrt_allocate_buffer_for_argv
// ============ 0x1402e7388 __acrt_allocate_buffer_for_argv (size=93) ============


/* Library Function - Single Match

    __acrt_allocate_buffer_for_argv

   

   Libraries: Visual Studio 2017 Release, Visual Studio 2019 Release */



undefined8 __acrt_allocate_buffer_for_argv(ulonglong param_1,ulonglong param_2,ulonglong param_3)



{

  undefined1 auVar1 [16];

  undefined8 uVar2;

  

  if ((param_1 < 0x1fffffffffffffff) &&

     (auVar1._8_8_ = 0, auVar1._0_8_ = param_3,

     param_2 < SUB168((ZEXT816(0) << 0x40 | ZEXT816(0xffffffffffffffff)) / auVar1,0))) {

    if (param_2 * param_3 < ~(param_1 * 8)) {

      uVar2 = _calloc_base(param_1 * 8 + param_2 * param_3,1);

      FUN_1402e9a80(0);

      return uVar2;

    }

  }

  return 0;

}




