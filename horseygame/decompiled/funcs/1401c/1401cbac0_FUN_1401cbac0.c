// Address: 0x1401cbac0
// Ghidra name: FUN_1401cbac0
// ============ 0x1401cbac0 FUN_1401cbac0 (size=101) ============


void FUN_1401cbac0(longlong param_1)



{

  int iVar1;

  longlong *local_res8 [4];

  

  local_res8[0] = (longlong *)0x0;

  iVar1 = (**(code **)**(undefined8 **)(param_1 + 0x70))

                    (*(undefined8 **)(param_1 + 0x70),&DAT_140349398,local_res8);

  if (-1 < iVar1) {

    (**(code **)(*local_res8[0] + 0x130))(local_res8[0],FUN_1401ca4f0,0,0,0);

    (**(code **)(*local_res8[0] + 0x10))();

  }

  return;

}




