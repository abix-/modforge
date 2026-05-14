// Address: 0x140025980
// Ghidra name: FUN_140025980
// ============ 0x140025980 FUN_140025980 (size=65) ============


void FUN_140025980(longlong param_1,undefined8 param_2,undefined8 *param_3)



{

  longlong lVar1;

  undefined8 *puVar2;

  

  lVar1 = FUN_140027470(param_1 + 0x68);

  if ((lVar1 != 0) && ((undefined8 *)(lVar1 + 0x40) != param_3)) {

    puVar2 = param_3;

    if (0xf < (ulonglong)param_3[3]) {

      puVar2 = (undefined8 *)*param_3;

    }

    FUN_140027f50((undefined8 *)(lVar1 + 0x40),puVar2,param_3[2]);

    return;

  }

  return;

}




