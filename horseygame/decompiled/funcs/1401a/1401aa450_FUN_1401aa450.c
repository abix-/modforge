// Address: 0x1401aa450
// Ghidra name: FUN_1401aa450
// ============ 0x1401aa450 FUN_1401aa450 (size=36) ============


uint FUN_1401aa450(uint param_1,uint param_2)



{

  ulonglong uVar1;

  ulonglong uVar2;

  

  uVar2 = (ulonglong)param_2;

  while (param_2 != 0) {

    uVar1 = (ulonglong)param_1;

    param_1 = (uint)uVar2;

    param_2 = (uint)(uVar1 % uVar2);

    uVar2 = uVar1 % uVar2;

  }

  return param_1;

}




