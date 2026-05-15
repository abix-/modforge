// Address: 0x140207ae0
// Ghidra name: FUN_140207ae0
// ============ 0x140207ae0 FUN_140207ae0 (size=126) ============


longlong FUN_140207ae0(int param_1,undefined4 *param_2)



{

  longlong lVar1;

  

  _guard_check_icall();

  lVar1 = DAT_1403fd198;

  do {

    if (lVar1 == 0) {

      return 0;

    }

    if (((*(longlong *)(lVar1 + 0xa0) == 0) && (*(char *)(lVar1 + 0x9a) == '\0')) &&

       (*(longlong *)(lVar1 + 0x68) != 0)) {

      if (param_1 < *(int *)(lVar1 + 0x8c)) {

        if (param_2 == (undefined4 *)0x0) {

          return lVar1;

        }

        *param_2 = *(undefined4 *)(*(longlong *)(lVar1 + 0x90) + (longlong)param_1 * 4);

        return lVar1;

      }

      param_1 = param_1 - *(int *)(lVar1 + 0x8c);

    }

    lVar1 = *(longlong *)(lVar1 + 0xb8);

  } while( true );

}




