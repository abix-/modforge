// Address: 0x1401aacb0
// Ghidra name: FUN_1401aacb0
// ============ 0x1401aacb0 FUN_1401aacb0 (size=236) ============


undefined8 FUN_1401aacb0(char *param_1,undefined8 param_2)



{

  size_t sVar1;

  int iVar2;

  longlong lVar3;

  size_t sVar4;

  undefined8 uVar5;

  

  iVar2 = memcmp(param_1,"file:/",6);

  if (iVar2 == 0) {

    param_1 = param_1 + 6;

  }

  else {

    lVar3 = thunk_FUN_1402c9340(param_1,&DAT_14033c9a0);

    if (lVar3 != 0) {

      return 0xffffffffffffffff;

    }

  }

  if ((*param_1 == '/') && (param_1[1] != '/')) {

    if ((param_1[2] != '/') && (lVar3 = thunk_FUN_1402c9190(param_1 + 1,0x2f), lVar3 != 0)) {

      sVar1 = (lVar3 - (longlong)param_1) - 1;

      sVar4 = strlen(PTR_s_localhost_1403e3d68);

      if ((sVar4 == sVar1) &&

         (iVar2 = FUN_14012f260(param_1 + 1,PTR_s_localhost_1403e3d68,sVar1), iVar2 == 0)) {

        param_1 = (char *)(lVar3 + 1);

        goto LAB_1401aad5d;

      }

    }

    return 0xffffffffffffffff;

  }

LAB_1401aad5d:

  lVar3 = 1;

  if (*param_1 != '/') {

    lVar3 = -1;

  }

  uVar5 = FUN_1401aab10(param_1 + lVar3,param_2,0);

  return uVar5;

}




