// Address: 0x140158df0
// Ghidra name: FUN_140158df0
// ============ 0x140158df0 FUN_140158df0 (size=112) ============


undefined2 FUN_140158df0(undefined4 param_1)



{

  undefined2 uVar1;

  longlong lVar2;

  undefined4 *puVar3;

  undefined2 local_res10 [12];

  undefined4 local_18;

  undefined4 uStack_14;

  undefined4 uStack_10;

  undefined4 uStack_c;

  

  FUN_140159d30();

  lVar2 = FUN_140158f10(param_1);

  if (lVar2 != 0) {

    uVar1 = *(undefined2 *)(lVar2 + 0x10);

    FUN_14015bb10();

    return uVar1;

  }

  puVar3 = (undefined4 *)FUN_140158250(&local_18,param_1);

  local_18 = *puVar3;

  uStack_14 = puVar3[1];

  uStack_10 = puVar3[2];

  uStack_c = puVar3[3];

  FUN_1401582b0(&local_18,local_res10,0,0,0);

  FUN_14015bb10();

  return local_res10[0];

}




