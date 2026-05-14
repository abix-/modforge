// Address: 0x140274270
// Ghidra name: FUN_140274270
// ============ 0x140274270 FUN_140274270 (size=138) ============


void FUN_140274270(longlong param_1)



{

  char cVar1;

  undefined2 local_58;

  undefined8 local_56;

  undefined8 local_4e;

  undefined8 local_46;

  undefined8 local_3e;

  undefined8 local_36;

  undefined8 local_2e;

  undefined8 local_26;

  undefined8 local_1e;

  undefined8 local_16;

  undefined4 local_e;

  

  if (*(char *)(*(longlong *)(param_1 + 0x70) + 0x20) == '\0') {

    if (0 < *(int *)(param_1 + 0x8c)) {

      FUN_140208230(param_1,**(undefined4 **)(param_1 + 0x90));

      return;

    }

  }

  else {

    local_56 = 0;

    local_4e = 0;

    local_46 = 0;

    local_3e = 0;

    local_36 = 0;

    local_2e = 0;

    local_26 = 0;

    local_1e = 0;

    local_16 = 0;

    local_e = 0;

    local_58 = 0x231;

    cVar1 = FUN_1402843f0();

    if (cVar1 != '\0') {

      FUN_140284650(param_1,&local_58,0x4e);

      return;

    }

  }

  return;

}




