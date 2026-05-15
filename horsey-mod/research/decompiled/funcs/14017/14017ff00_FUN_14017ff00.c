// Address: 0x14017ff00
// Ghidra name: FUN_14017ff00
// ============ 0x14017ff00 FUN_14017ff00 (size=91) ============


ulonglong FUN_14017ff00(char *param_1,char *param_2,char *param_3)



{

  int iVar1;

  undefined4 extraout_var;

  ulonglong uVar2;

  

  iVar1 = strncmp(param_1,param_2,(longlong)param_3 - (longlong)param_2);

  uVar2 = CONCAT44(extraout_var,iVar1);

  if ((iVar1 == 0) && (param_1[(longlong)param_3 - (longlong)param_2] == '\0')) {

    uVar2 = 0;

    if ((*param_3 == '\0') || (*param_3 == ',')) {

      return 1;

    }

  }

  return uVar2 & 0xffffffffffffff00;

}




