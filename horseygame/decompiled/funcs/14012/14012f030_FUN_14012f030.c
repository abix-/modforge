// Address: 0x14012f030
// Ghidra name: FUN_14012f030
// ============ 0x14012f030 FUN_14012f030 (size=126) ============


undefined8 FUN_14012f030(undefined8 param_1,char *param_2)



{

  int iVar1;

  size_t sVar2;

  undefined8 local_res8;

  

  local_res8 = param_1;

  sVar2 = strlen(param_2);

  do {

    iVar1 = FUN_14012f260(param_1,param_2,sVar2);

    if (iVar1 == 0) {

      return param_1;

    }

    iVar1 = FUN_14012ed20(&local_res8,0);

    param_1 = local_res8;

  } while (iVar1 != 0);

  return 0;

}




