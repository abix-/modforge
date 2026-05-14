// Address: 0x14016c0c0
// Ghidra name: FUN_14016c0c0
// ============ 0x14016c0c0 FUN_14016c0c0 (size=359) ============


ulonglong FUN_14016c0c0(char *param_1)



{

  int iVar1;

  int iVar2;

  code *pcVar3;

  code *pcVar4;

  longlong lVar5;

  char *_Str1;

  undefined4 extraout_var;

  longlong lVar6;

  size_t sVar7;

  int local_res10 [2];

  

  pcVar3 = (code *)thunk_FUN_1402c9190(param_1,0x20);

  if ((pcVar3 == (code *)0x0) && (*param_1 != '\0')) {

    pcVar3 = (code *)FUN_140142960(param_1);

    if ((pcVar3 == (code *)0x0) || (*pcVar3 != (code)0x30)) {

      pcVar4 = (code *)FUN_14016c730("glGetString");

      pcVar3 = (code *)0x0;

      if (pcVar4 != (code *)0x0) {

        lVar5 = (*pcVar4)(0x1f02);

        if (lVar5 != 0) {

          iVar1 = thunk_FUN_1402d89dc(lVar5);

          if (2 < iVar1) {

            iVar1 = 0;

            local_res10[0] = 0;

            pcVar4 = (code *)FUN_14016c730("glGetStringi");

            pcVar3 = (code *)FUN_14016c730("glGetIntegerv");

            if ((pcVar4 != (code *)0x0) && (pcVar3 != (code *)0x0)) {

              pcVar3 = (code *)(*pcVar3)(0x821d,local_res10);

              if (0 < local_res10[0]) {

                do {

                  _Str1 = (char *)(*pcVar4)(0x1f03,iVar1);

                  iVar2 = strcmp(_Str1,param_1);

                  pcVar3 = (code *)CONCAT44(extraout_var,iVar2);

                  if (iVar2 == 0) goto LAB_14016c215;

                  iVar1 = iVar1 + 1;

                } while (iVar1 < local_res10[0]);

              }

            }

            goto LAB_14016c195;

          }

        }

        lVar5 = (*pcVar4)(0x1f03);

        pcVar3 = (code *)0x0;

        if (lVar5 != 0) {

          lVar6 = thunk_FUN_1402c9340(lVar5,param_1);

          pcVar3 = (code *)0x0;

          if (lVar6 != 0) {

            while( true ) {

              sVar7 = strlen(param_1);

              pcVar3 = (code *)(sVar7 + lVar6);

              if (((lVar6 == lVar5) || (*(char *)(lVar6 + -1) == ' ')) &&

                 ((*pcVar3 == (code)0x20 || (*pcVar3 == (code)0x0)))) break;

              lVar6 = thunk_FUN_1402c9340(pcVar3,param_1);

              if (lVar6 == 0) {

                return 0;

              }

            }

LAB_14016c215:

            return CONCAT71((int7)((ulonglong)pcVar3 >> 8),1);

          }

        }

      }

    }

  }

LAB_14016c195:

  return (ulonglong)pcVar3 & 0xffffffffffffff00;

}




