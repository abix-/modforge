// Address: 0x14012f410
// Ghidra name: FUN_14012f410
// ============ 0x14012f410 FUN_14012f410 (size=112) ============


char * FUN_14012f410(char *param_1,char *param_2,ulonglong param_3)



{

  int iVar1;

  size_t _MaxCount;

  

  _MaxCount = strlen(param_2);

  if (_MaxCount != 0) {

    for (; (_MaxCount <= param_3 && (*param_1 != '\0')); param_1 = param_1 + 1) {

      iVar1 = strncmp(param_1,param_2,_MaxCount);

      if (iVar1 == 0) {

        return param_1;

      }

      param_3 = param_3 - 1;

    }

    param_1 = (char *)0x0;

  }

  return param_1;

}




