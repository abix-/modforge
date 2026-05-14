// Address: 0x140275280
// Ghidra name: FUN_140275280
// ============ 0x140275280 FUN_140275280 (size=51) ============


void FUN_140275280(undefined8 param_1,longlong param_2)



{

  undefined8 uVar1;

  

  if ((*(char *)(param_2 + 1) != '\0') && (*(char *)(param_2 + 3) != '\0')) {

    uVar1 = 1;

    if (*(char *)(param_2 + 2) != '\0') {

      uVar1 = 3;

    }

    FUN_14015af40(param_1,uVar1,

                  ((uint)*(byte *)(param_2 + 4) + (uint)*(byte *)(param_2 + 4) * 4) * 4);

    return;

  }

  return;

}




