// Address: 0x140287900
// Ghidra name: FUN_140287900
// ============ 0x140287900 FUN_140287900 (size=59) ============


void FUN_140287900(longlong param_1)



{

  longlong *plVar1;

  code *UNRECOVERED_JUMPTABLE;

  

  (**(code **)(*(longlong *)**(undefined8 **)(param_1 + 0x28) + 0x40))();

  if (*(char *)((longlong)*(undefined8 **)(param_1 + 0x28) + 0x14) == '\0') {

    plVar1 = (longlong *)**(undefined8 **)(param_1 + 0x28);

    UNRECOVERED_JUMPTABLE = *(code **)(*plVar1 + 0x10);

                    /* WARNING: Could not recover jumptable at 0x000140287932. Too many branches */

                    /* WARNING: Treating indirect jump as call */

    (*UNRECOVERED_JUMPTABLE)(plVar1,UNRECOVERED_JUMPTABLE);

    return;

  }

  return;

}




