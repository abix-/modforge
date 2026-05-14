// Address: 0x140218330
// Ghidra name: FUN_140218330
// ============ 0x140218330 FUN_140218330 (size=106) ============


void FUN_140218330(longlong param_1,longlong param_2,ulonglong param_3)



{

  ulonglong uVar1;

  longlong lVar2;

  

  uVar1 = *(ulonglong *)(param_1 + 0x18);

  lVar2 = *(longlong *)(param_1 + 0x10);

  if (param_3 < uVar1) {

    FUN_1402f8e20(lVar2,lVar2 + param_3,uVar1 - param_3);

    lVar2 = (uVar1 - param_3) + lVar2;

  }

  else {

    param_2 = param_3 + (param_2 - uVar1);

    param_3 = uVar1;

  }

  FUN_1402f8e20(lVar2,param_2,param_3);

  return;

}




