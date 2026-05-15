// Address: 0x14012f580
// Ghidra name: FUN_14012f580
// ============ 0x14012f580 FUN_14012f580 (size=89) ============


char * FUN_14012f580(ulonglong param_1,char *param_2,int param_3)



{

  ulonglong uVar1;

  char *pcVar2;

  

  if (param_1 == 0) {

    *param_2 = '0';

    pcVar2 = param_2 + 1;

  }

  else {

    pcVar2 = param_2;

    do {

      uVar1 = param_1 / (ulonglong)(longlong)param_3;

      *pcVar2 = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ"[param_1 % (ulonglong)(longlong)param_3];

      pcVar2 = pcVar2 + 1;

      param_1 = uVar1;

    } while (uVar1 != 0);

  }

  *pcVar2 = '\0';

  _strrev(param_2);

  return param_2;

}




