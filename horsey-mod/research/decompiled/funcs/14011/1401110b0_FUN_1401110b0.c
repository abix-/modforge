// Address: 0x1401110b0
// Ghidra name: FUN_1401110b0
// ============ 0x1401110b0 FUN_1401110b0 (size=572) ============


void FUN_1401110b0(undefined8 *param_1,undefined8 *param_2,undefined8 *param_3,code *param_4)



{

  undefined8 uVar1;

  char cVar2;

  longlong lVar3;

  undefined8 *puVar4;

  undefined8 *puVar5;

  undefined8 *puVar6;

  undefined8 *puVar7;

  undefined8 *puVar8;

  

  puVar6 = param_2 + ((longlong)param_3 - (longlong)param_2 >> 4);

  lVar3 = (longlong)param_3 + (-8 - (longlong)param_2) >> 3;

  if (lVar3 < 0x29) {

    puVar8 = param_3 + -1;

    puVar4 = param_2;

  }

  else {

    lVar3 = lVar3 + 1 >> 3;

    _Med3_unchecked<>(param_2,param_2 + lVar3,param_2 + lVar3 * 2);

    _Med3_unchecked<>(puVar6 + -lVar3,puVar6,puVar6 + lVar3,param_4);

    puVar8 = param_3 + (-1 - lVar3);

    _Med3_unchecked<>(param_3 + lVar3 * -2 + -1,puVar8,param_3 + -1,param_4);

    puVar4 = param_2 + lVar3;

  }

  _Med3_unchecked<>(puVar4,puVar6,puVar8,param_4);

  puVar8 = puVar6;

  while (puVar4 = puVar8, param_2 < puVar4) {

    cVar2 = (*param_4)(puVar4[-1],*puVar4);

    if ((cVar2 != '\0') ||

       (cVar2 = (*param_4)(*puVar4,puVar4[-1]), puVar8 = puVar4 + -1, cVar2 != '\0')) break;

  }

  do {

    puVar6 = puVar6 + 1;

    puVar8 = puVar6;

    puVar5 = puVar4;

    if (param_3 <= puVar6) break;

    cVar2 = (*param_4)(*puVar6,*puVar4);

    if ((cVar2 != '\0') || (cVar2 = (*param_4)(*puVar4,*puVar6), cVar2 != '\0')) break;

  } while( true );

joined_r0x0001401111ca:

  puVar7 = puVar4;

  if (param_3 <= puVar8) {

joined_r0x000140111209:

    for (; param_2 < puVar4; puVar4 = puVar4 + -1) {

      puVar7 = puVar7 + -1;

      cVar2 = (*param_4)(*puVar7,*puVar5);

      if (cVar2 == '\0') {

        cVar2 = (*param_4)(*puVar5,*puVar7);

        if (cVar2 != '\0') break;

        puVar5 = puVar5 + -1;

        if (puVar5 != puVar7) {

          uVar1 = *puVar5;

          *puVar5 = *puVar7;

          *puVar7 = uVar1;

        }

      }

    }

    if (puVar4 == param_2) {

      if (puVar8 == param_3) {

        *param_1 = puVar5;

        param_1[1] = puVar6;

        return;

      }

      if (puVar6 != puVar8) {

        uVar1 = *puVar5;

        *puVar5 = *puVar6;

        *puVar6 = uVar1;

      }

      puVar6 = puVar6 + 1;

      uVar1 = *puVar5;

      *puVar5 = *puVar8;

      *puVar8 = uVar1;

      puVar8 = puVar8 + 1;

      puVar5 = puVar5 + 1;

    }

    else {

      puVar4 = puVar4 + -1;

      if (puVar8 == param_3) {

        puVar5 = puVar5 + -1;

        if (puVar4 != puVar5) {

          uVar1 = *puVar4;

          *puVar4 = *puVar5;

          *puVar5 = uVar1;

        }

        puVar7 = puVar6 + -1;

        puVar6 = puVar6 + -1;

        uVar1 = *puVar5;

        *puVar5 = *puVar7;

        *puVar6 = uVar1;

      }

      else {

        uVar1 = *puVar8;

        *puVar8 = *puVar4;

        *puVar4 = uVar1;

        puVar8 = puVar8 + 1;

      }

    }

    goto joined_r0x0001401111ca;

  }

  cVar2 = (*param_4)(*puVar5,*puVar8);

  if (cVar2 == '\0') {

    cVar2 = (*param_4)(*puVar8,*puVar5);

    if (cVar2 != '\0') goto joined_r0x000140111209;

    if (puVar6 != puVar8) {

      uVar1 = *puVar6;

      *puVar6 = *puVar8;

      *puVar8 = uVar1;

    }

    puVar6 = puVar6 + 1;

  }

  puVar8 = puVar8 + 1;

  goto joined_r0x0001401111ca;

}




