// Address: 0x1401771c0
// Ghidra name: FUN_1401771c0
// ============ 0x1401771c0 FUN_1401771c0 (size=78) ============


undefined4 FUN_1401771c0(undefined4 param_1)



{

  char cVar1;

  undefined4 uVar2;

  undefined4 local_res10 [2];

  longlong local_res18 [2];

  

  uVar2 = 0xffffffff;

  FUN_140177410();

  cVar1 = FUN_140176dd0(param_1,local_res18,local_res10);

  if (cVar1 != '\0') {

    uVar2 = (**(code **)(local_res18[0] + 0x20))(local_res10[0]);

  }

  FUN_140177750();

  return uVar2;

}




