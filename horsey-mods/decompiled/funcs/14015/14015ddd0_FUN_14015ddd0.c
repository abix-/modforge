// Address: 0x14015ddd0
// Ghidra name: FUN_14015ddd0
// ============ 0x14015ddd0 FUN_14015ddd0 (size=87) ============


void FUN_14015ddd0(undefined8 param_1)



{

  longlong lVar1;

  longlong local_res10 [3];

  

  local_res10[0] = 0;

  lVar1 = FUN_14015cb20(param_1,local_res10);

  if (lVar1 != 0) {

    FUN_14015c7c0(lVar1);

  }

  lVar1 = local_res10[0];

  if (local_res10[0] != 0) {

    if (*(longlong *)(local_res10[0] + 0xd0) == 0) {

      FUN_14015c2e0(local_res10[0]);

    }

    FUN_14015fe40(lVar1);

  }

  FUN_14015d3e0(lVar1);

  return;

}




