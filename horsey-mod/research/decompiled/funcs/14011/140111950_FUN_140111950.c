// Address: 0x140111950
// Ghidra name: FUN_140111950
// ============ 0x140111950 FUN_140111950 (size=247) ============


void FUN_140111950(longlong param_1,longlong param_2,ulonglong param_3,undefined8 *param_4,

                  code *param_5)



{

  char cVar1;

  longlong lVar2;

  longlong lVar3;

  longlong lVar4;

  

  lVar4 = (longlong)(param_3 - 1) >> 1;

  lVar3 = param_2;

  while (lVar3 < lVar4) {

    cVar1 = (*param_5)(*(undefined8 *)(param_1 + 0x10 + lVar3 * 0x10),

                       *(undefined8 *)(param_1 + 8 + lVar3 * 0x10));

    lVar2 = (2 - (ulonglong)(cVar1 != '\0')) + lVar3 * 2;

    *(undefined8 *)(param_1 + lVar3 * 8) = *(undefined8 *)(param_1 + lVar2 * 8);

    lVar3 = lVar2;

  }

  if ((lVar3 == lVar4) && ((param_3 & 1) == 0)) {

    *(undefined8 *)(param_1 + lVar3 * 8) = *(undefined8 *)(param_1 + -8 + param_3 * 8);

    lVar3 = param_3 - 1;

  }

  if (param_2 < lVar3) {

    while( true ) {

      lVar4 = lVar3 + -1 >> 1;

      cVar1 = (*param_5)(*(undefined8 *)(param_1 + lVar4 * 8),*param_4);

      if (cVar1 == '\0') break;

      *(undefined8 *)(param_1 + lVar3 * 8) = *(undefined8 *)(param_1 + lVar4 * 8);

      lVar3 = lVar4;

      if (lVar4 <= param_2) {

        *(undefined8 *)(param_1 + lVar4 * 8) = *param_4;

        return;

      }

    }

  }

  *(undefined8 *)(param_1 + lVar3 * 8) = *param_4;

  return;

}




