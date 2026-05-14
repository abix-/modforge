// Address: 0x140275a00
// Ghidra name: FUN_140275a00
// ============ 0x140275a00 FUN_140275a00 (size=111) ============


bool FUN_140275a00(longlong param_1,undefined8 param_2,undefined8 param_3,undefined2 param_4,

                  undefined2 param_5,undefined8 param_6,int param_7)



{

  char cVar1;

  

  cVar1 = FUN_140159650(param_4,param_5);

  if (cVar1 == '\0') {

    return false;

  }

  if ((param_1 != 0) && (*(char *)(param_1 + 0x54) == '\0')) {

    cVar1 = FUN_140276ba0(param_5);

    if (cVar1 == '\0') {

      return param_7 == 2;

    }

    if (3 < param_7 - 1U) {

      return false;

    }

  }

  return true;

}




