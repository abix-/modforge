// Address: 0x1401bd270
// Ghidra name: FUN_1401bd270
// ============ 0x1401bd270 FUN_1401bd270 (size=87) ============


void FUN_1401bd270(longlong param_1,longlong param_2,undefined8 param_3)



{

  undefined4 local_38 [2];

  undefined8 local_30;

  undefined4 local_28;

  undefined8 local_20;

  undefined8 local_18;

  

  if ((*(char *)(param_1 + 0x57c) != '\0') && (*(char *)(param_1 + 0x58e) != '\0')) {

    local_20 = *(undefined8 *)(param_2 + 0x18);

    local_38[0] = 0x3b9cbe00;

    local_30 = 0;

    local_28 = 10;

    local_18 = param_3;

    (**(code **)(param_1 + 0x9d0))(*(undefined8 *)(param_1 + 0x570),local_38);

  }

  return;

}




