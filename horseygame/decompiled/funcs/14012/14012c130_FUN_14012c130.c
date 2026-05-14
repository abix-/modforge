// Address: 0x14012c130
// Ghidra name: FUN_14012c130
// ============ 0x14012c130 FUN_14012c130 (size=118) ============


undefined8 FUN_14012c130(char *param_1,char *param_2)



{

  longlong lVar1;

  undefined8 uVar2;

  undefined *puVar3;

  

  uVar2 = 0;

  if ((param_1 == (char *)0x0) || (*param_1 == '\0')) {

    puVar3 = &DAT_140314094;

  }

  else {

    if ((param_2 != (char *)0x0) && (*param_2 != '\0')) {

      lVar1 = FUN_14012d250();

      if (lVar1 != -1) {

        uVar2 = FUN_14012c1b0(lVar1,param_2,1);

      }

      return uVar2;

    }

    puVar3 = &DAT_1403140bc;

  }

  FUN_14012e850("Parameter \'%s\' is invalid",puVar3);

  return 0;

}




