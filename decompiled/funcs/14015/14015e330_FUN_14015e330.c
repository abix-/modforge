// Address: 0x14015e330
// Ghidra name: FUN_14015e330
// ============ 0x14015e330 FUN_14015e330 (size=71) ============


undefined4 FUN_14015e330(undefined8 param_1)



{

  longlong lVar1;

  undefined4 uVar2;

  undefined8 local_res10 [3];

  

  local_res10[0] = 0;

  lVar1 = FUN_14015cb20(param_1,local_res10);

  uVar2 = DAT_14039ca80;

  if (lVar1 != 0) {

    uVar2 = *(undefined4 *)(lVar1 + 0x14);

  }

  FUN_14015d3e0(local_res10[0]);

  return uVar2;

}




