// Address: 0x14015d9a0
// Ghidra name: FUN_14015d9a0
// ============ 0x14015d9a0 FUN_14015d9a0 (size=73) ============


undefined1 FUN_14015d9a0(undefined8 param_1)



{

  int iVar1;

  longlong lVar2;

  undefined1 uVar3;

  undefined8 local_res10 [3];

  

  local_res10[0] = 0;

  lVar2 = FUN_14015cb20(param_1,local_res10);

  uVar3 = 0;

  if (lVar2 != 0) {

    iVar1 = FUN_140138fe0(lVar2 + 0x10);

    uVar3 = 0;

    if (iVar1 != 0) {

      uVar3 = 1;

    }

  }

  FUN_14015d3e0(local_res10[0]);

  return uVar3;

}




