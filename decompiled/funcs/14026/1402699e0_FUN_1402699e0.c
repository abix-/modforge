// Address: 0x1402699e0
// Ghidra name: FUN_1402699e0
// ============ 0x1402699e0 FUN_1402699e0 (size=132) ============


char FUN_1402699e0(longlong *param_1)



{

  short sVar1;

  int iVar2;

  char cVar3;

  

  cVar3 = *(char *)((longlong)param_1 + 0x24);

  if ((cVar3 == '\0') && (cVar3 = '0', *(char *)(*param_1 + 0x54) != '\0')) {

    cVar3 = '?';

  }

  iVar2 = (int)param_1[6];

  if (iVar2 != 0) {

    if (iVar2 == 1) {

      if (cVar3 == '?') {

        return '0';

      }

    }

    else {

      if (((iVar2 == 2) && (*(short *)(*param_1 + 0x20) == 0x57e)) &&

         ((sVar1 = *(short *)(*param_1 + 0x22), sVar1 == 0x2006 || (sVar1 == 0x2007)))) {

        return '0';

      }

      if (cVar3 == '?') goto LAB_140269a55;

    }

    return cVar3;

  }

  cVar3 = '?';

LAB_140269a55:

  if (*(char *)(*param_1 + 0x54) == '\0') {

    cVar3 = '0';

  }

  return cVar3;

}




