// Address: 0x140084300
// Ghidra name: FUN_140084300
// ============ 0x140084300 FUN_140084300 (size=103) ============


void FUN_140084300(longlong param_1,undefined4 param_2,char param_3,char param_4)



{

  char cVar1;

  

  if (*(int *)(param_1 + 8) != 2) {

    if ((param_3 == '\0') || (param_4 == '\0')) {

      cVar1 = FUN_14000b290();

      if (cVar1 == '\0') {

        FUN_14000b2a0(param_1,1);

      }

      FUN_14000b2f0(param_1,param_2);

    }

    else {

      cVar1 = FUN_14000b290();

      if (cVar1 != '\0') {

        FUN_14000b2a0(param_1,0);

        return;

      }

    }

  }

  return;

}




