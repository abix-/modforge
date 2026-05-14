// Address: 0x1402652e0
// Ghidra name: FUN_1402652e0
// ============ 0x1402652e0 FUN_1402652e0 (size=104) ============


void FUN_1402652e0(longlong param_1,byte param_2)



{

  longlong *plVar1;

  

  if (*(longlong *)(param_1 + 0x18 + (ulonglong)param_2 * 8) == 0) {

    plVar1 = (longlong *)FUN_1401841a0(1,0x160);

    *(byte *)(plVar1 + 1) = param_2;

    if (param_2 != 0) {

      *(undefined4 *)((longlong)plVar1 + 0x144) = 0xffffffff;

    }

    *plVar1 = param_1;

    *(undefined4 *)((longlong)plVar1 + 0x5c) = 0x5e;

    *(undefined4 *)((longlong)plVar1 + 0x7c) = 0x472;

    *(longlong **)(param_1 + (ulonglong)param_2 * 8 + 0x18) = plVar1;

  }

  return;

}




