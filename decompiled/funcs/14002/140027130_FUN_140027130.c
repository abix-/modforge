// Address: 0x140027130
// Ghidra name: FUN_140027130
// ============ 0x140027130 FUN_140027130 (size=97) ============


void FUN_140027130(longlong param_1,undefined8 param_2,uint param_3)



{

  ulonglong uVar1;

  longlong *plVar2;

  

  if (0 < (int)param_3) {

    uVar1 = (ulonglong)param_3;

    do {

      FUN_140023ee0(param_2,&DAT_14039bd08);

      uVar1 = uVar1 - 1;

    } while (uVar1 != 0);

  }

  plVar2 = (longlong *)(param_1 + 0x38);

  if (0xf < *(ulonglong *)(param_1 + 0x50)) {

    plVar2 = (longlong *)*plVar2;

  }

  FUN_140023ee0(param_2,&DAT_14039bfac,plVar2);

  return;

}




