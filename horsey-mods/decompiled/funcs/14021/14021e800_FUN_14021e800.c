// Address: 0x14021e800
// Ghidra name: FUN_14021e800
// ============ 0x14021e800 FUN_14021e800 (size=624) ============


undefined8 FUN_14021e800(undefined8 *param_1,undefined8 *param_2)



{

  char *pcVar1;

  char cVar2;

  bool bVar3;

  char cVar4;

  undefined1 uVar5;

  longlong lVar6;

  longlong lVar7;

  undefined8 uVar8;

  longlong lVar9;

  char *pcVar10;

  longlong lVar11;

  longlong lVar12;

  

  cVar4 = FUN_14021e7a0(*param_1);

  lVar12 = 0;

  pcVar10 = (char *)*param_1;

  lVar11 = lVar12;

  lVar9 = lVar12;

  while (pcVar10 != (char *)0x0) {

    if ((*pcVar10 == '\0') || (lVar6 = thunk_FUN_1402e1190(pcVar10), lVar6 != 0)) {

      bVar3 = true;

      lVar9 = lVar9 + 2;

    }

    else {

      bVar3 = false;

    }

    cVar2 = *pcVar10;

    while (cVar2 != '\0') {

      switch(cVar2) {

      case ' ':

      case '&':

      case '<':

      case '>':

      case '^':

      case '|':

        if (cVar4 == '\0') goto switchD_14021e8a1_caseD_21;

        lVar9 = lVar9 + 2;

        break;

      default:

switchD_14021e8a1_caseD_21:

        lVar9 = lVar9 + 1;

        break;

      case '\"':

        lVar9 = lVar9 + 2;

        break;

      case '\\':

        if ((pcVar10[1] == '\"') || ((bVar3 && (pcVar10[1] == '\0')))) {

          lVar9 = lVar9 + 2;

        }

        else {

          lVar9 = lVar9 + 1;

        }

      }

      pcVar1 = pcVar10 + 1;

      pcVar10 = pcVar10 + 1;

      cVar2 = *pcVar1;

    }

    lVar6 = lVar11 + 8;

    lVar11 = lVar11 + 8;

    lVar9 = lVar9 + 1;

    pcVar10 = *(char **)(lVar6 + (longlong)param_1);

  }

  lVar11 = FUN_1401841f0(lVar9);

  if (lVar11 == 0) {

    *param_2 = 0;

    uVar8 = 0;

  }

  else {

    pcVar10 = (char *)*param_1;

    lVar6 = lVar12;

    while (pcVar10 != (char *)0x0) {

      if ((*pcVar10 == '\0') || (lVar7 = thunk_FUN_1402e1190(pcVar10,&DAT_1403559dc), lVar7 != 0)) {

        *(undefined1 *)(lVar6 + lVar11) = 0x22;

        bVar3 = true;

        lVar6 = lVar6 + 1;

      }

      else {

        bVar3 = false;

      }

      cVar2 = *pcVar10;

      while (cVar2 != '\0') {

        switch(cVar2) {

        case ' ':

        case '&':

        case '<':

        case '>':

        case '^':

        case '|':

          if (cVar4 != '\0') {

            *(undefined1 *)(lVar6 + lVar11) = 0x5e;

            lVar6 = lVar6 + 1;

          }

          *(char *)(lVar6 + lVar11) = *pcVar10;

          goto LAB_14021e9ec;

        default:

          *(char *)(lVar6 + lVar11) = cVar2;

LAB_14021e9ec:

          lVar6 = lVar6 + 1;

          break;

        case '\"':

          uVar5 = 0x22;

          if (cVar4 == '\0') {

            uVar5 = 0x5c;

          }

          *(undefined1 *)(lVar11 + lVar6) = uVar5;

          *(char *)(lVar6 + 1 + lVar11) = *pcVar10;

          lVar6 = lVar6 + 2;

          break;

        case '\\':

          *(char *)(lVar6 + lVar11) = cVar2;

          lVar6 = lVar6 + 1;

          if ((pcVar10[1] == '\"') || ((bVar3 && (pcVar10[1] == '\0')))) {

            *(char *)(lVar6 + lVar11) = *pcVar10;

            goto LAB_14021e9ec;

          }

        }

        pcVar1 = pcVar10 + 1;

        pcVar10 = pcVar10 + 1;

        cVar2 = *pcVar1;

      }

      if (bVar3) {

        *(undefined1 *)(lVar6 + lVar11) = 0x22;

        lVar6 = lVar6 + 1;

      }

      lVar12 = lVar12 + 8;

      *(undefined1 *)(lVar6 + lVar11) = 0x20;

      lVar6 = lVar6 + 1;

      pcVar10 = *(char **)(lVar12 + (longlong)param_1);

    }

    *(undefined1 *)(lVar11 + -1 + lVar9) = 0;

    uVar8 = FUN_140197820("UTF-16LE",&DAT_14039c6f0,lVar11,lVar9);

    *param_2 = uVar8;

    FUN_1401841e0(lVar11);

    uVar8 = 1;

  }

  return uVar8;

}




