// Address: 0x1402c73a0
// Ghidra name: __scrt_uninitialize_crt
// ============ 0x1402c73a0 __scrt_uninitialize_crt (size=41) ============


/* Library Function - Single Match

    __scrt_uninitialize_crt

   

   Library: Visual Studio 2019 Release */



undefined1 __scrt_uninitialize_crt(undefined1 param_1,char param_2)



{

  if ((DAT_1403fe638 == '\0') || (param_2 == '\0')) {

    __acrt_uninitialize();

    __vcrt_uninitialize(param_1);

  }

  return 1;

}




