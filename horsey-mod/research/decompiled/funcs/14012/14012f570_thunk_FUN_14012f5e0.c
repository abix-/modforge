// Address: 0x14012f570
// Ghidra name: thunk_FUN_14012f5e0
// ============ 0x14012f570 thunk_FUN_14012f5e0 (size=5) ============


char * thunk_FUN_14012f5e0(uint param_1,char *param_2,uint param_3)



{

  ulonglong uVar1;

  char *pcVar2;

  ulonglong uVar3;

  

  uVar3 = (ulonglong)param_1;

  pcVar2 = param_2;

  if (param_1 == 0) {

    *param_2 = '0';

    pcVar2 = param_2 + 1;

  }

  else {

    do {

      uVar1 = uVar3 / param_3;

      *pcVar2 = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ"[uVar3 % (ulonglong)param_3];

      pcVar2 = pcVar2 + 1;

      uVar3 = uVar1;

    } while ((int)uVar1 != 0);

  }

  *pcVar2 = '\0';

  _strrev(param_2);

  return param_2;

}




