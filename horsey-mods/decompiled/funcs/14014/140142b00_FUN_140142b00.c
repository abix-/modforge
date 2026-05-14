// Address: 0x140142b00
// Ghidra name: FUN_140142b00
// ============ 0x140142b00 FUN_140142b00 (size=173) ============


void FUN_140142b00(char *param_1,longlong param_2,longlong param_3)



{

  longlong *plVar1;

  longlong *plVar2;

  longlong *plVar3;

  int iVar4;

  longlong lVar5;

  

  if (((param_1 != (char *)0x0) && (*param_1 != '\0')) && (iVar4 = FUN_1401426c0(0), iVar4 != 0)) {

    FUN_140175050(iVar4);

    lVar5 = FUN_140174d30(iVar4,param_1,0);

    if (lVar5 != 0) {

      plVar3 = *(longlong **)(lVar5 + 0x10);

      plVar2 = (longlong *)0x0;

      while (plVar1 = plVar3, plVar1 != (longlong *)0x0) {

        if ((param_2 == *plVar1) && (param_3 == plVar1[1])) {

          if (plVar2 == (longlong *)0x0) {

            *(longlong *)(lVar5 + 0x10) = plVar1[2];

          }

          else {

            plVar2[2] = plVar1[2];

          }

          FUN_1401841e0();

          break;

        }

        plVar2 = plVar1;

        plVar3 = (longlong *)plVar1[2];

      }

    }

    FUN_1401755c0(iVar4);

  }

  return;

}




