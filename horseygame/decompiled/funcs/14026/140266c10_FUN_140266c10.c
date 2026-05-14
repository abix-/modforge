// Address: 0x140266c10
// Ghidra name: FUN_140266c10
// ============ 0x140266c10 FUN_140266c10 (size=166) ============


undefined1 FUN_140266c10(longlong param_1,char *param_2,undefined8 param_3)



{

  char cVar1;

  undefined1 uVar2;

  

  if ((param_2[1] & 0x20U) != 0) {

    uVar2 = FUN_140266f90();

    return uVar2;

  }

  cVar1 = *param_2;

  if (cVar1 == '\f') {

    if ((*(byte *)(param_1 + 0x14c) & 4) != 0) {

      uVar2 = FUN_1402661b0(param_1,param_2,param_3);

      return uVar2;

    }

  }

  else {

    if (cVar1 == ' ') {

      uVar2 = FUN_140266850(param_1,param_2,param_3);

      return uVar2;

    }

    if (cVar1 == '!') {

      uVar2 = FUN_140266bf0(param_1,param_2,param_3);

      return uVar2;

    }

    if (cVar1 == '\"') {

      uVar2 = FUN_140266830(param_1,param_2,param_3);

      return uVar2;

    }

    if (cVar1 == '&') {

      uVar2 = FUN_140266bd0(param_1,param_2,param_3);

      return uVar2;

    }

  }

  FUN_14012e2e0(7,"GIP: Received unknown vendor message type %02x");

  return 0;

}




