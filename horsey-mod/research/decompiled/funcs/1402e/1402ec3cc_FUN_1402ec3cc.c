// Address: 0x1402ec3cc
// Ghidra name: FUN_1402ec3cc
// ============ 0x1402ec3cc FUN_1402ec3cc (size=242) ============


/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */



void FUN_1402ec3cc(undefined8 param_1,DWORD param_2,LPCWSTR param_3,int param_4,LPWSTR param_5,

                  int param_6,undefined8 param_7,undefined8 param_8,undefined8 param_9)



{

  LCID Locale;

  code *pcVar1;

  

  if (DAT_140424090 == (code *)0xffffffffffffffff) {

LAB_1402ec477:

    Locale = FUN_1402ec4c0(param_1,0);

    LCMapStringW(Locale,param_2,param_3,param_4,param_5,param_6);

  }

  else {

    pcVar1 = DAT_140424090;

    if (DAT_140424090 == (code *)0x0) {

      pcVar1 = (code *)FUN_1402ec028(0x12,"LCMapStringEx",&DAT_14038eaa8,"LCMapStringEx");

      if (pcVar1 == (code *)0x0) goto LAB_1402ec477;

    }

    (*pcVar1)(param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8,param_9);

  }

  return;

}




