// Address: 0x140230760
// Ghidra name: FUN_140230760
// ============ 0x140230760 FUN_140230760 (size=200) ============


longlong * FUN_140230760(undefined8 param_1,longlong *param_2)



{

  int iVar1;

  longlong *plVar2;

  BOOL BVar3;

  longlong *plVar4;

  

  if (param_2 == (longlong *)0x0) {

    return (longlong *)0x0;

  }

  plVar4 = (longlong *)*param_2;

  if (plVar4 == (longlong *)0x0) {

    return (longlong *)0x0;

  }

  if (plVar4[2] == 0) {

    plVar2 = (longlong *)plVar4[10];

    FUN_1401841e0(plVar4);

    if ((int)param_2[1] < 0) {

      plVar4 = (longlong *)0x0;

    }

    else {

      *(undefined4 *)(plVar2 + 7) = 2;

      plVar4 = plVar2;

    }

  }

  else {

    iVar1 = (int)plVar4[1];

    if ((int)param_2[1] < 0) {

      if (((iVar1 != 2) || ((int)param_2[1] != -0x7ff8fffb)) || (*(char *)(*plVar4 + 0xc9) == '\0'))

      {

        *(undefined4 *)(plVar4 + 7) = 1;

      }

    }

    else {

      if (iVar1 == 1) {

        if ((ulonglong)param_2[2] < (ulonglong)plVar4[8]) {

          *(undefined4 *)(plVar4 + 7) = 1;

        }

      }

      else if (iVar1 != 0) goto LAB_1402307fc;

      plVar4[9] = param_2[2];

    }

  }

LAB_1402307fc:

  if (((int)plVar4[1] == 2) && (BVar3 = CloseHandle(*(HANDLE *)(*plVar4 + 0x28)), BVar3 == 0)) {

    *(undefined4 *)(plVar4 + 7) = 1;

  }

  return plVar4;

}




