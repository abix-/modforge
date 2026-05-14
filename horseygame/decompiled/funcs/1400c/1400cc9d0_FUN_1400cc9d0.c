// Address: 0x1400cc9d0
// Ghidra name: FUN_1400cc9d0
// ============ 0x1400cc9d0 FUN_1400cc9d0 (size=120) ============


longlong FUN_1400cc9d0(longlong param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)



{

  longlong lVar1;

  longlong local_res8;

  

  local_res8 = FUN_1402c704c(0x80);

  if (local_res8 == 0) {

    lVar1 = 0;

  }

  else {

    lVar1 = FUN_14005c9b0(local_res8,param_2,param_3,param_4);

  }

  local_res8 = lVar1;

  FUN_14003e600(param_1 + 0xb8,&local_res8);

  return lVar1;

}




