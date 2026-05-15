// Address: 0x140141cf0
// Ghidra name: FUN_140141cf0
// ============ 0x140141cf0 FUN_140141cf0 (size=122) ============


void FUN_140141cf0(undefined8 param_1,undefined8 *param_2,undefined1 param_3,undefined2 param_4)



{

  char cVar1;

  undefined4 local_88 [2];

  undefined8 local_80;

  undefined4 local_78;

  undefined1 local_74;

  undefined2 local_70;

  

  _guard_check_icall();

  cVar1 = FUN_140139420(0x650);

  if (cVar1 != '\0') {

    local_88[0] = 0x650;

    local_78 = *(undefined4 *)*param_2;

    local_80 = param_1;

    local_74 = param_3;

    local_70 = param_4;

    FUN_14013b140(local_88);

  }

  return;

}




