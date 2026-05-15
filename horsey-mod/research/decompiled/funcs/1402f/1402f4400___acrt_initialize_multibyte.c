// Address: 0x1402f4400
// Ghidra name: __acrt_initialize_multibyte
// ============ 0x1402f4400 __acrt_initialize_multibyte (size=96) ============


/* Library Function - Single Match

    __acrt_initialize_multibyte

   

   Libraries: Visual Studio 2017 Release, Visual Studio 2019 Release */



undefined8 __acrt_initialize_multibyte(void)



{

  undefined8 uVar1;

  

  if (DAT_1403ff76c == '\0') {

    DAT_1403ff758 = &DAT_1403e94e0;

    DAT_1403ff760 = &DAT_1403e91a0;

    DAT_1403ff750 = &DAT_1403e93d0;

    uVar1 = FUN_1402e8680();

    FUN_1402f40d8(0xfffffffd,1,uVar1,&DAT_1403ff760);

    DAT_1403ff76c = '\x01';

  }

  return 1;

}




