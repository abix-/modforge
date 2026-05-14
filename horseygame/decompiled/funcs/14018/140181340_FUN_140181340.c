// Address: 0x140181340
// Ghidra name: FUN_140181340
// ============ 0x140181340 FUN_140181340 (size=68) ============


ulonglong FUN_140181340(longlong param_1)



{

  code *UNRECOVERED_JUMPTABLE;

  uint uVar1;

  ulonglong uVar2;

  

  UNRECOVERED_JUMPTABLE = *(code **)(*(longlong *)(param_1 + 0x680) + 0x90);

  if (UNRECOVERED_JUMPTABLE != (code *)0x0) {

                    /* WARNING: Could not recover jumptable at 0x000140181362. Too many branches */

                    /* WARNING: Treating indirect jump as call */

    uVar2 = (*UNRECOVERED_JUMPTABLE)(0xffffffffffffffff);

    return uVar2;

  }

  UNRECOVERED_JUMPTABLE = *(code **)(*(longlong *)(param_1 + 0x680) + 0xe0);

  if (UNRECOVERED_JUMPTABLE != (code *)0x0) {

    uVar1 = (*UNRECOVERED_JUMPTABLE)(0);

    return (ulonglong)(~uVar1 >> 0x1f);

  }

  return 0;

}




