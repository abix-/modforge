// Address: 0x140144680
// Ghidra name: FUN_140144680
// ============ 0x140144680 FUN_140144680 (size=187) ============


undefined8

FUN_140144680(uint param_1,int param_2,int param_3,ulonglong *param_4,ulonglong *param_5,

             undefined1 param_6)



{

  char cVar1;

  ulonglong local_res20;

  ulonglong local_18 [2];

  

  local_18[0] = 0;

  local_res20 = 0;

  if (param_4 != (ulonglong *)0x0) {

    *param_4 = 0;

  }

  if (param_5 != (ulonglong *)0x0) {

    *param_5 = 0;

  }

  if ((param_1 == 0) || ((param_1 & 0xf0000000) == 0x10000000)) {

    cVar1 = FUN_140144550(param_1,(longlong)param_2,(longlong)param_3,&local_res20,local_18,param_6)

    ;

  }

  else {

    if (param_1 == 0x47504a4d) {

      return 1;

    }

    cVar1 = FUN_1401d47f0();

  }

  if (cVar1 != '\0') {

    if (param_4 != (ulonglong *)0x0) {

      *param_4 = local_res20;

    }

    if (param_5 != (ulonglong *)0x0) {

      *param_5 = local_18[0];

    }

    return 1;

  }

  return 0;

}




