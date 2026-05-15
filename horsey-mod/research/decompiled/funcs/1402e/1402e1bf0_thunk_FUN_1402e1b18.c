// Address: 0x1402e1bf0
// Ghidra name: thunk_FUN_1402e1b18
// ============ 0x1402e1bf0 thunk_FUN_1402e1b18 (size=5) ============


char * thunk_FUN_1402e1b18(char *param_1,int param_2,_iobuf *param_3)



{

  bool bVar1;

  int iVar2;

  undefined4 *puVar3;

  char *pcVar4;

  char *pcVar5;

  int iVar6;

  

  if ((param_1 != (char *)0x0) || (bVar1 = false, param_2 == 0)) {

    bVar1 = true;

  }

  if (((bVar1) && (-1 < param_2)) && (param_3 != (_iobuf *)0x0)) {

    if (param_2 != 0) {

      FUN_1402e1710(param_3);

      bVar1 = __acrt_stdio_char_traits<char>::validate_stream_is_ansi_if_required(param_3);

      pcVar5 = (char *)0x0;

      if (bVar1) {

        pcVar4 = param_1;

        for (iVar6 = 1; iVar6 != param_2; iVar6 = iVar6 + 1) {

          iVar2 = _fgetc_nolock(param_3);

          if (iVar2 == -1) {

            if (pcVar4 == param_1) goto LAB_1402e1bde;

            break;

          }

          *pcVar4 = (char)iVar2;

          pcVar4 = pcVar4 + 1;

          if ((char)iVar2 == '\n') break;

        }

        *pcVar4 = '\0';

        pcVar5 = param_1;

      }

LAB_1402e1bde:

      FUN_1402e171c(param_3);

      return pcVar5;

    }

  }

  else {

    puVar3 = (undefined4 *)FUN_1402e68b0();

    *puVar3 = 0x16;

    FUN_1402cd454();

  }

  return (char *)0x0;

}




