// Address: 0x1401aada0
// Ghidra name: FUN_1401aada0
// ============ 0x1401aada0 FUN_1401aada0 (size=118) ============


ulonglong FUN_1401aada0(char *param_1,char *param_2)



{

  int iVar1;

  ulonglong in_RAX;

  undefined4 extraout_var;

  size_t sVar2;

  

  if (param_1 == (char *)0x0) {

    sVar2 = 0;

  }

  else {

    in_RAX = strlen(param_1);

    sVar2 = in_RAX;

  }

  if (param_2 != (char *)0x0) {

    in_RAX = strlen(param_2);

    if ((in_RAX != 0) && (in_RAX <= sVar2)) {

      iVar1 = memcmp(param_1 + (sVar2 - in_RAX),param_2,in_RAX);

      return CONCAT71((int7)(CONCAT44(extraout_var,iVar1) >> 8),iVar1 == 0);

    }

  }

  return in_RAX & 0xffffffffffffff00;

}




