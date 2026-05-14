// Address: 0x1401812e0
// Ghidra name: FUN_1401812e0
// ============ 0x1401812e0 FUN_1401812e0 (size=92) ============


ulonglong FUN_1401812e0(longlong param_1)



{

  longlong lVar1;

  uint uVar2;

  ulonglong uVar3;

  

  lVar1 = *(longlong *)(param_1 + 0x680);

  if (*(code **)(lVar1 + 0x90) != (code *)0x0) {

                    /* WARNING: Could not recover jumptable at 0x000140181302. Too many branches */

                    /* WARNING: Treating indirect jump as call */

    uVar3 = (**(code **)(lVar1 + 0x90))(0xfffffffffffffffe);

    return uVar3;

  }

  if (*(code **)(lVar1 + 0xe0) != (code *)0x0) {

    uVar2 = (**(code **)(lVar1 + 0xe0))(1);

    return (ulonglong)(~uVar2 >> 0x1f);

  }

  if (*(code **)(lVar1 + 0x88) != (code *)0x0) {

                    /* WARNING: Could not recover jumptable at 0x000140181332. Too many branches */

                    /* WARNING: Treating indirect jump as call */

    uVar3 = (**(code **)(lVar1 + 0x88))();

    return uVar3;

  }

  return 0;

}




