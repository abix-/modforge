// Address: 0x1401784e0
// Ghidra name: FUN_1401784e0
// ============ 0x1401784e0 FUN_1401784e0 (size=228) ============


undefined4 FUN_1401784e0(char *param_1)



{

  undefined4 uVar1;

  int iVar2;

  longlong lVar3;

  

  lVar3 = thunk_FUN_1402c9190(param_1,0x5c);

  if (lVar3 != 0) {

    uVar1 = FUN_14012e850("Windows-style path separators (\'\\\') not permitted, use \'/\' instead."

                         );

    return uVar1;

  }

  lVar3 = thunk_FUN_1402c9190(param_1,0x2f);

  while (lVar3 != 0) {

    iVar2 = strncmp(param_1,"./",2);

    if ((iVar2 == 0) || (iVar2 = strncmp(param_1,"../",3), iVar2 == 0)) goto LAB_1401785ae;

    param_1 = (char *)(lVar3 + 1);

    lVar3 = thunk_FUN_1402c9190(param_1,0x2f);

  }

  iVar2 = strcmp(param_1,".");

  if ((iVar2 != 0) && (iVar2 = strcmp(param_1,".."), iVar2 != 0)) {

    return 1;

  }

LAB_1401785ae:

  uVar1 = FUN_14012e850("Relative paths not permitted");

  return uVar1;

}




