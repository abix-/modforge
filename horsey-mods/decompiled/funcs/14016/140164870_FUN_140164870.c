// Address: 0x140164870
// Ghidra name: FUN_140164870
// ============ 0x140164870 FUN_140164870 (size=125) ============


void FUN_140164870(longlong param_1,undefined8 *param_2,undefined8 param_3,undefined1 *param_4)



{

  undefined8 local_res8;

  longlong local_18 [2];

  

  local_18[0] = FUN_140217b30(*(undefined8 *)(param_1 + 0x60));

  if (local_18[0] == 0) {

    *param_2 = 0;

    *(undefined4 *)(param_2 + 1) = 0;

    *param_4 = 0;

  }

  else {

    local_res8 = *(undefined8 *)(param_1 + 0xa0);

    FUN_140164d70(param_1,local_18,&local_res8,param_2,param_3,param_4);

  }

  return;

}




