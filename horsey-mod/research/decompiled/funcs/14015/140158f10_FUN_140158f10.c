// Address: 0x140158f10
// Ghidra name: FUN_140158f10
// ============ 0x140158f10 FUN_140158f10 (size=73) ============


undefined8 FUN_140158f10(undefined4 param_1)



{

  char cVar1;

  undefined4 uVar2;

  undefined8 uVar3;

  undefined4 local_res10 [2];

  longlong local_res18 [2];

  

  cVar1 = FUN_140210c40();

  if (cVar1 != '\0') {

    cVar1 = FUN_140157a10(param_1,local_res18,local_res10);

    if (cVar1 != '\0') {

      uVar2 = (**(code **)(local_res18[0] + 0x30))(local_res10[0]);

      uVar3 = FUN_140210b70(uVar2);

      return uVar3;

    }

  }

  return 0;

}




