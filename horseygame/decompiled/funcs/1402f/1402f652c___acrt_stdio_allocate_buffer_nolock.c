// Address: 0x1402f652c
// Ghidra name: __acrt_stdio_allocate_buffer_nolock
// ============ 0x1402f652c __acrt_stdio_allocate_buffer_nolock (size=107) ============


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

/* Library Function - Single Match

    __acrt_stdio_allocate_buffer_nolock

   

   Library: Visual Studio 2019 Release */



void __acrt_stdio_allocate_buffer_nolock(undefined8 *param_1)



{

  undefined8 uVar1;

  undefined4 uVar2;

  

  _DAT_1403fed38 = _DAT_1403fed38 + 1;

  uVar2 = 0x1000;

  uVar1 = _calloc_base(0x1000);

  param_1[1] = uVar1;

  FUN_1402e9a80(0);

  if (param_1[1] == 0) {

    LOCK();

    *(uint *)((longlong)param_1 + 0x14) = *(uint *)((longlong)param_1 + 0x14) | 0x400;

    UNLOCK();

    uVar2 = 2;

    param_1[1] = (longlong)param_1 + 0x1c;

  }

  else {

    LOCK();

    *(uint *)((longlong)param_1 + 0x14) = *(uint *)((longlong)param_1 + 0x14) | 0x40;

    UNLOCK();

  }

  *(undefined4 *)(param_1 + 4) = uVar2;

  *(undefined4 *)(param_1 + 2) = 0;

  *param_1 = param_1[1];

  return;

}




