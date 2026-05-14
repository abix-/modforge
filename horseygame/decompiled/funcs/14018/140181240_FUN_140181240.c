// Address: 0x140181240
// Ghidra name: FUN_140181240
// ============ 0x140181240 FUN_140181240 (size=75) ============


ulonglong FUN_140181240(longlong param_1)



{

  code *UNRECOVERED_JUMPTABLE;

  uint uVar1;

  ulonglong uVar2;

  

  UNRECOVERED_JUMPTABLE = *(code **)(*(longlong *)(param_1 + 0x680) + 0x90);

  if (UNRECOVERED_JUMPTABLE != (code *)0x0) {

                    /* WARNING: Could not recover jumptable at 0x000140181262. Too many branches */

                    /* WARNING: Treating indirect jump as call */

    uVar2 = (*UNRECOVERED_JUMPTABLE)(0xfffffffffffffffd);

    return uVar2;

  }

  UNRECOVERED_JUMPTABLE = *(code **)(*(longlong *)(param_1 + 0x680) + 0xe0);

  if (UNRECOVERED_JUMPTABLE != (code *)0x0) {

    uVar1 = (*UNRECOVERED_JUMPTABLE)(2);

    return (ulonglong)(~uVar1 >> 0x1f);

  }

  uVar2 = FUN_1401812e0();

  return uVar2;

}




