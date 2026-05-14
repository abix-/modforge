// Address: 0x14015af40
// Ghidra name: FUN_14015af40
// ============ 0x14015af40 FUN_14015af40 (size=131) ============


void FUN_14015af40(undefined4 *param_1,int param_2,int param_3)



{

  char cVar1;

  undefined4 local_88 [2];

  undefined8 local_80;

  undefined4 local_78;

  int local_74;

  int local_70;

  

  if ((param_2 != param_1[0x3a]) || (param_3 != param_1[0x3b])) {

    param_1[0x3a] = param_2;

    param_1[0x3b] = param_3;

    cVar1 = FUN_140139420(0x607);

    if (cVar1 != '\0') {

      local_78 = *param_1;

      local_88[0] = 0x607;

      local_80 = 0;

      local_74 = param_2;

      local_70 = param_3;

      FUN_14013b140(local_88);

    }

  }

  return;

}




