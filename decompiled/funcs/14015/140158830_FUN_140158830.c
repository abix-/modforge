// Address: 0x140158830
// Ghidra name: FUN_140158830
// ============ 0x140158830 FUN_140158830 (size=102) ============


longlong FUN_140158830(undefined4 param_1)



{

  char cVar1;

  undefined8 uVar2;

  longlong lVar3;

  undefined4 local_res10 [2];

  longlong local_res18 [2];

  

  lVar3 = 0;

  FUN_140159d30();

  cVar1 = FUN_140157a10(param_1,local_res18,local_res10);

  if (cVar1 != '\0') {

    uVar2 = (**(code **)(local_res18[0] + 0x28))(local_res10[0]);

    lVar3 = FUN_1401aa890(uVar2);

  }

  FUN_14015bb10();

  if (lVar3 == 0) {

    FUN_14012e850("That operation is not supported");

  }

  return lVar3;

}




