// Address: 0x140169080
// Ghidra name: FUN_140169080
// ============ 0x140169080 FUN_140169080 (size=205) ============


void FUN_140169080(undefined8 *param_1,ulonglong param_2,char param_3)



{

  undefined8 *puVar1;

  char cVar2;

  size_t sVar3;

  char *pcVar4;

  longlong lVar5;

  ulonglong uVar6;

  char *pcVar7;

  

  uVar6 = 0;

  lVar5 = 8;

  if (param_2 != 0) {

    do {

      sVar3 = strlen((char *)param_1[uVar6]);

      uVar6 = uVar6 + 1;

      lVar5 = lVar5 + 9 + sVar3;

    } while (uVar6 < param_2);

  }

  if (param_3 == '\0') {

    lVar5 = FUN_1401841f0(lVar5);

  }

  else {

    lVar5 = FUN_1401391c0();

  }

  if (lVar5 != 0) {

    puVar1 = (undefined8 *)(lVar5 + param_2 * 8);

    pcVar7 = (char *)(puVar1 + 1);

    if (param_2 != 0) {

      lVar5 = lVar5 - (longlong)param_1;

      do {

        *(char **)(lVar5 + (longlong)param_1) = pcVar7;

        pcVar4 = (char *)*param_1;

        do {

          cVar2 = *pcVar4;

          pcVar4 = pcVar4 + 1;

          *pcVar7 = cVar2;

          pcVar7 = pcVar7 + 1;

        } while (cVar2 != '\0');

        param_1 = param_1 + 1;

        param_2 = param_2 - 1;

      } while (param_2 != 0);

    }

    *puVar1 = 0;

  }

  return;

}




