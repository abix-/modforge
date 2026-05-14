// Address: 0x140077d30
// Ghidra name: FUN_140077d30
// ============ 0x140077d30 FUN_140077d30 (size=130) ============


undefined4

FUN_140077d30(undefined8 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,

             undefined8 param_5)



{

  undefined4 uVar1;

  longlong lVar2;

  undefined1 *local_18;

  longlong local_10;

  

  lVar2 = FUN_1402ce0f8(param_1,&DAT_14030a390);

  local_18 = &LAB_140077f90;

  if (lVar2 == 0) {

    uVar1 = 0;

  }

  else {

    local_10 = lVar2;

    uVar1 = FUN_14007a2c0(&local_18,param_2,param_3,param_4,param_5);

    FUN_1402ce288(lVar2);

  }

  return uVar1;

}




