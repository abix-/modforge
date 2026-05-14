// Address: 0x140220940
// Ghidra name: FUN_140220940
// ============ 0x140220940 FUN_140220940 (size=148) ============


int FUN_140220940(int param_1,longlong param_2)



{

  int iVar1;

  size_t sVar2;

  char *_Str;

  

  if (param_1 == 1) {

    _Str = "text/plain";

    goto LAB_14022099d;

  }

  if (param_1 != 8) {

    if (param_1 == 0xd) {

      _Str = "text/plain;charset=utf-8";

      goto LAB_14022099d;

    }

    if (param_1 != 0x11) {

      iVar1 = FUN_1402209e0();

      if (param_1 != iVar1) {

        return 0;

      }

      _Str = "image/png";

      goto LAB_14022099d;

    }

  }

  _Str = "image/bmp";

LAB_14022099d:

  sVar2 = strlen(_Str);

  if (param_2 != 0) {

    FUN_1402f8e20(param_2,_Str,sVar2 + 1);

  }

  return (int)sVar2 + 1;

}




