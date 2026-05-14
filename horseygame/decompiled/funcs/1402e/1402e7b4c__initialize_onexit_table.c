// Address: 0x1402e7b4c
// Ghidra name: _initialize_onexit_table
// ============ 0x1402e7b4c _initialize_onexit_table (size=39) ============


/* Library Function - Single Match

    _initialize_onexit_table

   

   Library: Visual Studio 2019 Release */



undefined8 _initialize_onexit_table(longlong *param_1)



{

  longlong lVar1;

  

  lVar1 = DAT_1403e8b00;

  if (param_1 == (longlong *)0x0) {

    return 0xffffffff;

  }

  if (*param_1 == param_1[2]) {

    *param_1 = DAT_1403e8b00;

    param_1[1] = lVar1;

    param_1[2] = lVar1;

  }

  return 0;

}




