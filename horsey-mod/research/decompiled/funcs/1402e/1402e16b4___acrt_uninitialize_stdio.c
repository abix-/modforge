// Address: 0x1402e16b4
// Ghidra name: __acrt_uninitialize_stdio
// ============ 0x1402e16b4 __acrt_uninitialize_stdio (size=91) ============


/* Library Function - Single Match

    __acrt_uninitialize_stdio

   

   Library: Visual Studio 2019 Release */



void __acrt_uninitialize_stdio(bool param_1)



{

  longlong lVar1;

  

  common_flush_all(param_1);

  FUN_1402f1664();

  lVar1 = 0;

  do {

    __acrt_stdio_free_buffer_nolock(*(undefined8 *)(lVar1 + DAT_1403fed30));

    DeleteCriticalSection((LPCRITICAL_SECTION)(*(longlong *)(lVar1 + DAT_1403fed30) + 0x30));

    lVar1 = lVar1 + 8;

  } while (lVar1 != 0x18);

  FUN_1402e9a80(DAT_1403fed30);

  DAT_1403fed30 = 0;

  return;

}




