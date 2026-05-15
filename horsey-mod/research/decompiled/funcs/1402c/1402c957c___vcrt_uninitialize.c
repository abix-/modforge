// Address: 0x1402c957c
// Ghidra name: __vcrt_uninitialize
// ============ 0x1402c957c __vcrt_uninitialize (size=25) ============


/* Library Function - Single Match

    __vcrt_uninitialize

   

   Library: Visual Studio 2019 Release */



undefined1 __vcrt_uninitialize(char param_1)



{

  if (param_1 == '\0') {

    FUN_1402c9978();

    __vcrt_uninitialize_locks();

  }

  return 1;

}




