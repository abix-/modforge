// Address: 0x1402f8c0c
// Ghidra name: __GSHandlerCheck_SEH
// ============ 0x1402f8c0c __GSHandlerCheck_SEH (size=133) ============


/* Library Function - Single Match

    __GSHandlerCheck_SEH

   

   Libraries: Visual Studio 2015 Release, Visual Studio 2017 Release, Visual Studio 2019 Release */



void __GSHandlerCheck_SEH(longlong param_1,undefined8 param_2,undefined8 param_3,longlong param_4)



{

  uint uVar1;

  uint *puVar2;

  

  puVar2 = *(uint **)(param_4 + 0x38);

  uVar1 = *puVar2;

  FUN_1402c7b20(param_2,param_4,puVar2 + (ulonglong)uVar1 * 4 + 1);

  if ((puVar2[(ulonglong)uVar1 * 4 + 1] & ((*(uint *)(param_1 + 4) & 0x66) != 0) + 1) != 0) {

    FUN_1402c9598(param_1,param_2,param_3,param_4);

  }

  return;

}




