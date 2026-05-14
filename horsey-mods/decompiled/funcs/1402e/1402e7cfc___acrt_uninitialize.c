// Address: 0x1402e7cfc
// Ghidra name: __acrt_uninitialize
// ============ 0x1402e7cfc __acrt_uninitialize (size=53) ============


/* Library Function - Single Match

    __acrt_uninitialize

   

   Library: Visual Studio 2019 Release */



undefined4 __acrt_uninitialize(bool param_1)



{

  undefined4 uVar1;

  

  if (param_1 != false) {

    if (DAT_1403fed30 != 0) {

      common_flush_all(param_1);

    }

    return 1;

  }

  uVar1 = FUN_1402f4aa8(&PTR_LAB_14038d0d0,&PTR_DAT_14038d1d0);

  return uVar1;

}




