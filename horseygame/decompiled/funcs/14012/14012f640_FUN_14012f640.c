// Address: 0x14012f640
// Ghidra name: FUN_14012f640
// ============ 0x14012f640 FUN_14012f640 (size=190) ============


size_t FUN_14012f640(longlong param_1,char *param_2,longlong param_3)



{

  size_t sVar1;

  longlong lVar2;

  size_t sVar3;

  

  if (param_3 == 0) {

    return 0;

  }

  sVar1 = strlen(param_2);

  sVar3 = param_3 - 1U;

  if (sVar1 < param_3 - 1U) {

    sVar3 = sVar1;

  }

  if (sVar3 != 0) {

    if ((byte)(param_2[sVar3 - 1] + 0x40U) < 0x35) {

      sVar3 = sVar3 - 1;

    }

    else {

      sVar1 = sVar3;

      if ((byte)(param_2[sVar3 - 1] + 0x80U) < 0x40) {

        do {

          sVar1 = sVar1 - 1;

          if (sVar1 == 0) goto LAB_14012f6c7;

          lVar2 = FUN_140130200(param_2[sVar1]);

        } while (lVar2 == 0);

        if (sVar3 - sVar1 != lVar2 + 1) {

          sVar3 = sVar1;

        }

      }

    }

LAB_14012f6c7:

    FUN_1402f8e20(param_1,param_2,sVar3);

  }

  *(undefined1 *)(sVar3 + param_1) = 0;

  return sVar3;

}




