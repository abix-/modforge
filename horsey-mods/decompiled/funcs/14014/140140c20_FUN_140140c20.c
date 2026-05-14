// Address: 0x140140c20
// Ghidra name: FUN_140140c20
// ============ 0x140140c20 FUN_140140c20 (size=306) ============


undefined4 * FUN_140140c20(undefined4 *param_1,char param_2,char param_3)



{

  undefined4 *_Buf1;

  short sVar1;

  int iVar2;

  longlong lVar3;

  undefined4 *puVar4;

  short local_res10 [4];

  undefined4 local_28;

  undefined4 uStack_24;

  undefined4 uStack_20;

  undefined4 uStack_1c;

  

  puVar4 = (undefined4 *)0x0;

  local_res10[0] = 0;

  _guard_check_icall();

  local_28 = *param_1;

  uStack_24 = param_1[1];

  uStack_20 = param_1[2];

  uStack_1c = param_1[3];

  FUN_1401582b0(&local_28,0,0,0,local_res10);

  FUN_14015b420(param_1,0);

  _Buf1 = DAT_1403fbf18;

  if (param_2 == '\0') {

    FUN_14015b430(param_1,0);

    _Buf1 = DAT_1403fbf18;

  }

  do {

    if (_Buf1 == (undefined4 *)0x0) {

      return puVar4;

    }

    iVar2 = memcmp(_Buf1,&DAT_1403fbf08,0x10);

    if (iVar2 != 0) {

      local_28 = *_Buf1;

      uStack_24 = _Buf1[1];

      uStack_20 = _Buf1[2];

      uStack_1c = _Buf1[3];

      if (param_2 == '\0') {

        FUN_14015b430(&local_28,0);

      }

      iVar2 = memcmp(param_1,&local_28,0x10);

      if (iVar2 == 0) {

        lVar3 = thunk_FUN_1402c9340(*(undefined8 *)(_Buf1 + 6),&DAT_1403318d4);

        if (lVar3 == 0) {

          if (((local_res10[0] == 0) || (param_3 == '\0')) && (puVar4 == (undefined4 *)0x0)) {

            puVar4 = _Buf1;

          }

        }

        else {

          sVar1 = thunk_FUN_1402d8a8c(lVar3 + 4,0,0x10);

          if (sVar1 == local_res10[0]) {

            return _Buf1;

          }

        }

      }

    }

    _Buf1 = *(undefined4 **)(_Buf1 + 10);

  } while( true );

}




