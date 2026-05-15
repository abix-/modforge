// Address: 0x1402ce320
// Ghidra name: _fgetc_nolock
// ============ 0x1402ce320 _fgetc_nolock (size=67) ============


/* Library Function - Single Match

    _fgetc_nolock

   

   Libraries: Visual Studio 2015 Release, Visual Studio 2017 Release, Visual Studio 2019 Release */



ulonglong _fgetc_nolock(undefined8 *param_1)



{

  int *piVar1;

  undefined4 *puVar2;

  ulonglong uVar3;

  

  if (param_1 == (undefined8 *)0x0) {

    puVar2 = (undefined4 *)FUN_1402e68b0();

    *puVar2 = 0x16;

    FUN_1402cd454();

    uVar3 = 0xffffffff;

  }

  else {

    piVar1 = (int *)(param_1 + 2);

    *piVar1 = *piVar1 + -1;

    if (*piVar1 < 0) {

      uVar3 = FUN_1402e9de8();

      return uVar3;

    }

    uVar3 = (ulonglong)*(byte *)*param_1;

    *param_1 = (byte *)*param_1 + 1;

  }

  return uVar3;

}




