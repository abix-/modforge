// Address: 0x14021f6b0
// Ghidra name: FUN_14021f6b0
// ============ 0x14021f6b0 FUN_14021f6b0 (size=254) ============


char * FUN_14021f6b0(undefined8 *param_1,ulonglong *param_2,char *param_3)



{

  char cVar1;

  ulonglong uVar2;

  char *pcVar3;

  ulonglong uVar4;

  longlong lVar5;

  ulonglong uVar6;

  bool bVar7;

  

  lVar5 = 0;

  if (param_3 != (char *)0x0) {

    cVar1 = *param_3;

    uVar2 = 0;

    while (cVar1 != '\0') {

      bVar7 = cVar1 != '&';

      cVar1 = param_3[lVar5 + 1];

      uVar6 = uVar2 + 1;

      if (bVar7) {

        uVar6 = uVar2;

      }

      lVar5 = lVar5 + 1;

      uVar2 = uVar6;

    }

    uVar6 = lVar5 + 1;

    if (uVar2 == 0) {

      return param_3;

    }

    if (uVar2 <= ~uVar6) {

      pcVar3 = (char *)*param_1;

      if ((pcVar3 == (char *)0x0) || (*param_2 < uVar6 + uVar2)) {

        uVar4 = ~uVar6 - uVar2;

        if (0x200 < uVar4) {

          uVar4 = 0x200;

        }

        *param_2 = uVar4 + uVar6 + uVar2;

        FUN_1401841e0(*param_1);

        *param_1 = 0;

        pcVar3 = (char *)FUN_1401841f0(*param_2);

        if (pcVar3 == (char *)0x0) {

          return (char *)0x0;

        }

        *param_1 = pcVar3;

      }

      while (uVar6 != 0) {

        uVar6 = uVar6 - 1;

        if (*param_3 == '&') {

          *pcVar3 = '&';

          pcVar3 = pcVar3 + 1;

        }

        cVar1 = *param_3;

        param_3 = param_3 + 1;

        *pcVar3 = cVar1;

        pcVar3 = pcVar3 + 1;

      }

      return (char *)*param_1;

    }

  }

  return (char *)0x0;

}




