// Address: 0x140218400
// Ghidra name: FUN_140218400
// ============ 0x140218400 FUN_140218400 (size=125) ============


void FUN_140218400(char param_1,undefined8 param_2,undefined8 param_3)



{

  char cVar1;

  undefined4 local_88 [2];

  undefined8 local_80;

  char local_78;

  undefined4 local_74;

  undefined8 local_70;

  

  if (param_1 == '\0') {

    FUN_140168fa0(0);

    FUN_140169700(param_2,param_3);

  }

  cVar1 = FUN_140139420(0x900);

  if (cVar1 != '\0') {

    local_88[0] = 0x900;

    local_80 = 0;

    local_74 = (undefined4)param_3;

    local_78 = param_1;

    local_70 = param_2;

    FUN_14013b140(local_88);

  }

  return;

}




