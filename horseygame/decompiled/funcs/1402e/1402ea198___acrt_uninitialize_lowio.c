// Address: 0x1402ea198
// Ghidra name: __acrt_uninitialize_lowio
// ============ 0x1402ea198 __acrt_uninitialize_lowio (size=64) ============


/* Library Function - Single Match

    __acrt_uninitialize_lowio

   

   Library: Visual Studio 2019 Release */



undefined1 __acrt_uninitialize_lowio(void)



{

  ulonglong uVar1;

  

  uVar1 = 0;

  do {

    if (*(longlong *)((longlong)&DAT_1403ff160 + uVar1) != 0) {

      __acrt_lowio_destroy_handle_array();

      *(undefined8 *)((longlong)&DAT_1403ff160 + uVar1) = 0;

    }

    uVar1 = uVar1 + 8;

  } while (uVar1 < 0x400);

  return 1;

}




