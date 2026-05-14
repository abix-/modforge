// Address: 0x140159710
// Ghidra name: FUN_140159710
// ============ 0x140159710 FUN_140159710 (size=85) ============


undefined1 FUN_140159710(undefined4 param_1)



{

  char cVar1;

  undefined1 uVar2;

  undefined1 local_res10 [8];

  undefined **local_res18 [2];

  

  FUN_140159d30();

  cVar1 = FUN_140157a10(param_1,local_res18,local_res10);

  uVar2 = 0;

  if (cVar1 != '\0') {

    uVar2 = 0;

    if (local_res18[0] == &PTR_FUN_1403e4f30) {

      uVar2 = 1;

    }

  }

  FUN_14015bb10();

  return uVar2;

}




