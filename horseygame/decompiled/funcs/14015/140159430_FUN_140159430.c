// Address: 0x140159430
// Ghidra name: FUN_140159430
// ============ 0x140159430 FUN_140159430 (size=58) ============


ulonglong FUN_140159430(short param_1,short param_2)



{

  ulonglong uVar1;

  

  if (param_1 == 0x4b4) {

    uVar1 = 0x2412;

    if (param_2 == 0x2412) {

LAB_140159467:

      return CONCAT71((int7)(uVar1 >> 8),1);

    }

  }

  else {

    uVar1 = 0x37d7;

    if (param_1 == 0x37d7) {

      uVar1 = 0x2501;

      if (param_2 != 0x2501) {

        return CONCAT71(0x24,param_2 == 0x2401);

      }

      goto LAB_140159467;

    }

  }

  return uVar1 & 0xffffffffffffff00;

}




