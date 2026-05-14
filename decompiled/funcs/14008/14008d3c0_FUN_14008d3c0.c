// Address: 0x14008d3c0
// Ghidra name: FUN_14008d3c0
// ============ 0x14008d3c0 FUN_14008d3c0 (size=147) ============


undefined4 FUN_14008d3c0(char *param_1,undefined8 *param_2)



{

  longlong *plVar1;

  char cVar2;

  int iVar3;

  int iVar4;

  undefined4 uVar5;

  char *pcVar6;

  longlong lVar7;

  

  plVar1 = (longlong *)(param_1 + 0x10);

  if (*plVar1 == param_2[2]) {

    if (0xf < (ulonglong)param_2[3]) {

      param_2 = (undefined8 *)*param_2;

    }

    if (0xf < *(ulonglong *)(param_1 + 0x18)) {

      param_1 = *(char **)param_1;

    }

    pcVar6 = param_1 + *plVar1;

    if (param_1 != pcVar6) {

      lVar7 = (longlong)param_2 - (longlong)param_1;

      do {

        cVar2 = param_1[lVar7];

        iVar3 = toupper((int)*param_1);

        iVar4 = toupper((int)cVar2);

        if (iVar3 != iVar4) goto LAB_14008d436;

        param_1 = param_1 + 1;

      } while (param_1 != pcVar6);

    }

    uVar5 = 1;

  }

  else {

LAB_14008d436:

    uVar5 = 0;

  }

  return uVar5;

}




