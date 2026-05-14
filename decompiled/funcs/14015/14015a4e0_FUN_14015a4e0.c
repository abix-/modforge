// Address: 0x14015a4e0
// Ghidra name: FUN_14015a4e0
// ============ 0x14015a4e0 FUN_14015a4e0 (size=99) ============


undefined1 FUN_14015a4e0(undefined4 param_1,undefined8 param_2)



{

  char cVar1;

  undefined1 uVar2;

  undefined4 local_res18 [2];

  longlong local_res20;

  

  uVar2 = 0;

  FUN_140159d30();

  cVar1 = FUN_140157a10(param_1,&local_res20,local_res18);

  if (cVar1 != '\0') {

    uVar2 = (**(code **)(local_res20 + 0xa0))(local_res18[0],param_2);

  }

  FUN_14015bb10();

  return uVar2;

}




