// Address: 0x1401bde60
// Ghidra name: FUN_1401bde60
// ============ 0x1401bde60 FUN_1401bde60 (size=150) ============


char FUN_1401bde60(undefined8 param_1,longlong param_2,longlong param_3,longlong param_4,

                  uint param_5,int *param_6)



{

  int iVar1;

  char cVar2;

  longlong lVar3;

  

  cVar2 = FUN_1401bdd60(param_1,param_2,param_6);

  if (cVar2 == '\0') {

    iVar1 = *param_6;

    if (iVar1 == 0x31) {

      lVar3 = param_2 + 0x3c;

      param_4 = param_2 + 0x10;

    }

    else if (iVar1 == 0x33) {

      lVar3 = param_3 + 200;

      param_4 = param_3 + 0x10;

    }

    else {

      if ((iVar1 != 0x35) || ((param_5 & 0x3ff000) < 0x3000)) {

        return '\0';

      }

      lVar3 = param_4 + 0x48;

      param_4 = param_4 + 0x10;

    }

    FUN_1401b29f0(param_4,lVar3,param_6 + 4);

    cVar2 = '\x01';

  }

  return cVar2;

}




