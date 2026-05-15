// Address: 0x1402191b0
// Ghidra name: FUN_1402191b0
// ============ 0x1402191b0 FUN_1402191b0 (size=308) ============


undefined8 FUN_1402191b0(longlong param_1,int param_2,char *param_3)



{

  char *pcVar1;

  longlong lVar2;

  ulonglong uVar3;

  size_t sVar4;

  char *pcVar5;

  char *pcVar6;

  char cVar7;

  

  if ((((param_3 != (char *)0x0) && (*param_3 != '\0')) &&

      (lVar2 = thunk_FUN_1402c9190(param_3,0x20), lVar2 == 0)) &&

     ((lVar2 = FUN_140142960(param_3), lVar2 == 0 ||

      (((uVar3 = thunk_FUN_1402d89dc(lVar2), (uVar3 & 1) == 0 || (param_2 != 0)) &&

       (((uVar3 & 2) == 0 || (param_2 != 1)))))))) {

    sVar4 = strlen(param_3);

    if (param_2 == 0) {

      pcVar5 = (char *)(**(code **)(*(longlong *)(param_1 + 0x690) + 0xa8))

                                 (*(undefined8 *)(*(longlong *)(param_1 + 0x690) + 0x10),0x3055);

    }

    else {

      if (param_2 != 1) {

        return 0;

      }

      pcVar5 = (char *)(**(code **)(*(longlong *)(param_1 + 0x690) + 0xa8))(0,0x3055);

    }

    if (pcVar5 != (char *)0x0) {

      cVar7 = *pcVar5;

      pcVar6 = pcVar5;

      while ((cVar7 != '\0' &&

             (pcVar6 = (char *)thunk_FUN_1402c9340(pcVar6,param_3), pcVar6 != (char *)0x0))) {

        if ((pcVar6 == pcVar5) || (pcVar6[-1] == ' ')) {

          if ((pcVar6[sVar4] & 0xdfU) != 0) {

            pcVar6 = pcVar6 + sVar4;

            cVar7 = *pcVar6;

            goto LAB_1402192b4;

          }

          return 1;

        }

        pcVar6 = pcVar6 + sVar4;

        cVar7 = *pcVar6;

        while (cVar7 != ' ') {

LAB_1402192b4:

          if (cVar7 == '\0') break;

          pcVar1 = pcVar6 + 1;

          pcVar6 = pcVar6 + 1;

          cVar7 = *pcVar1;

        }

        cVar7 = *pcVar6;

      }

    }

  }

  return 0;

}




