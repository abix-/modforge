// Address: 0x140176fc0
// Ghidra name: FUN_140176fc0
// ============ 0x140176fc0 FUN_140176fc0 (size=85) ============


undefined8 FUN_140176fc0(undefined4 param_1)



{

  char cVar1;

  undefined8 uVar2;

  undefined4 local_res10 [2];

  longlong local_res18 [2];

  

  uVar2 = 0;

  FUN_140177410();

  cVar1 = FUN_140176dd0(param_1,local_res18,local_res10);

  if (cVar1 != '\0') {

    uVar2 = (**(code **)(local_res18[0] + 0x18))(local_res10[0]);

    uVar2 = FUN_1401aa890(uVar2);

  }

  FUN_140177750();

  return uVar2;

}




