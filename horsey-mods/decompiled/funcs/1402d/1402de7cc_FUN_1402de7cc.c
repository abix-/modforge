// Address: 0x1402de7cc
// Ghidra name: FUN_1402de7cc
// ============ 0x1402de7cc FUN_1402de7cc (size=1988) ============


undefined8 FUN_1402de7cc(longlong *param_1,longlong *param_2,int *param_3)



{

  int *piVar1;

  int *piVar2;

  longlong lVar3;

  longlong lVar4;

  longlong *plVar5;

  char *pcVar6;

  bool bVar7;

  char cVar8;

  byte bVar9;

  int iVar10;

  uint uVar11;

  undefined4 *puVar12;

  undefined8 uVar13;

  char cVar14;

  int *piVar15;

  int iVar16;

  int iVar17;

  byte bVar18;

  char local_res10 [24];

  longlong local_58;

  longlong *local_50;

  char *local_48;

  longlong *local_40;

  

  iVar17 = 0;

  lVar3 = *param_2;

  if ((lVar3 == 0) || (param_2[3] == 0)) {

    puVar12 = (undefined4 *)FUN_1402e68b0();

    *puVar12 = 0x16;

    FUN_1402cd454();

    return 7;

  }

  local_58 = param_2[2];

  param_2[2] = local_58 + 1U;

  cVar8 = '\0';

  if (((param_2[1] == 0) || (local_58 + 1U <= (ulonglong)param_2[1])) &&

     (pcVar6 = *(char **)(lVar3 + 0x10), pcVar6 != *(char **)(lVar3 + 8))) {

    local_res10[0] = *pcVar6;

    *(char **)(lVar3 + 0x10) = pcVar6 + 1;

  }

  else {

    local_res10[0] = '\0';

  }

  local_48 = local_res10;

  local_40 = &local_58;

  local_50 = param_2;

  while (iVar10 = FUN_1402d8964(local_res10[0],8), iVar10 != 0) {

    lVar3 = param_2[2];

    param_2[2] = lVar3 + 1U;

    if ((param_2[1] == 0) || (lVar3 + 1U <= (ulonglong)param_2[1])) {

      lVar3 = *param_2;

      pcVar6 = *(char **)(lVar3 + 0x10);

      if (pcVar6 == *(char **)(lVar3 + 8)) goto LAB_1402de87c;

      local_res10[0] = *pcVar6;

      *(char **)(lVar3 + 0x10) = pcVar6 + 1;

    }

    else {

LAB_1402de87c:

      local_res10[0] = '\0';

    }

  }

  piVar2 = param_3 + 0xc2;

  *(bool *)piVar2 = local_res10[0] == '-';

  if ((local_res10[0] - 0x2bU & 0xfd) == 0) {

    lVar3 = param_2[2];

    param_2[2] = lVar3 + 1U;

    if ((param_2[1] == 0) || (local_res10[0] = cVar8, lVar3 + 1U <= (ulonglong)param_2[1])) {

      lVar3 = *param_2;

      pcVar6 = *(char **)(lVar3 + 0x10);

      local_res10[0] = cVar8;

      if (pcVar6 != *(char **)(lVar3 + 8)) {

        local_res10[0] = *pcVar6;

        *(char **)(lVar3 + 0x10) = pcVar6 + 1;

      }

    }

  }

  if ((local_res10[0] + 0xb7U & 0xdf) == 0) {

    uVar13 = FUN_1402def90(local_res10,param_2,local_58);

    return uVar13;

  }

  if ((local_res10[0] + 0xb2U & 0xdf) == 0) {

    uVar13 = FUN_1402df140(local_res10,param_2,local_58);

    return uVar13;

  }

  uVar13 = 0;

  if (local_res10[0] == '0') {

    lVar3 = param_2[2];

    param_2[2] = lVar3 + 1U;

    cVar14 = cVar8;

    if ((param_2[1] == 0) || (lVar3 + 1U <= (ulonglong)param_2[1])) {

      lVar4 = *param_2;

      pcVar6 = *(char **)(lVar4 + 0x10);

      if (pcVar6 != *(char **)(lVar4 + 8)) {

        cVar14 = *pcVar6;

        *(char **)(lVar4 + 0x10) = pcVar6 + 1;

        if ((cVar14 == 'x') || (cVar14 == 'X')) {

          lVar4 = param_2[2];

          uVar13 = 1;

          param_2[2] = lVar4 + 1U;

          local_58 = lVar3;

          if ((param_2[1] == 0) || (local_res10[0] = cVar8, lVar4 + 1U <= (ulonglong)param_2[1])) {

            lVar3 = *param_2;

            pcVar6 = *(char **)(lVar3 + 0x10);

            local_res10[0] = cVar8;

            if (pcVar6 != *(char **)(lVar3 + 8)) {

              local_res10[0] = *pcVar6;

              *(char **)(lVar3 + 0x10) = pcVar6 + 1;

            }

          }

          goto LAB_1402de9ce;

        }

      }

    }

    lVar3 = param_2[2];

    param_2[2] = lVar3 - 1U;

    if (((param_2[1] == 0) || (lVar3 - 1U <= (ulonglong)param_2[1])) && (1 < (byte)(cVar14 + 1U))) {

      plVar5 = (longlong *)*param_2;

      if (plVar5[2] != *plVar5) {

        plVar5[2] = plVar5[2] + -1;

      }

    }

  }

LAB_1402de9ce:

  bVar18 = (byte)uVar13;

  piVar1 = param_3 + 2;

  cVar8 = '\0';

  bVar7 = false;

  if (local_res10[0] == '0') {

    bVar7 = true;

    do {

      lVar3 = param_2[2];

      param_2[2] = lVar3 + 1U;

      if ((param_2[1] != 0) && ((ulonglong)param_2[1] < lVar3 + 1U)) {

LAB_1402dea1a:

        local_res10[0] = '\0';

        break;

      }

      lVar3 = *param_2;

      pcVar6 = *(char **)(lVar3 + 0x10);

      if (pcVar6 == *(char **)(lVar3 + 8)) goto LAB_1402dea1a;

      local_res10[0] = *pcVar6;

      *(char **)(lVar3 + 0x10) = pcVar6 + 1;

    } while (local_res10[0] == '0');

  }

  piVar15 = piVar1;

  while( true ) {

    if ((byte)(local_res10[0] - 0x30U) < 10) {

      uVar11 = (int)local_res10[0] - 0x30;

    }

    else if ((byte)(local_res10[0] + 0x9fU) < 0x1a) {

      uVar11 = (int)local_res10[0] - 0x57;

    }

    else if ((byte)(local_res10[0] + 0xbfU) < 0x1a) {

      uVar11 = (int)local_res10[0] - 0x37;

    }

    else {

      uVar11 = 0xffffffff;

    }

    if ((-(uint)(bVar18 != 0) & 6) + 9 < uVar11) break;

    bVar7 = true;

    if (piVar15 != piVar2) {

      *(char *)piVar15 = (char)uVar11;

      piVar15 = (int *)((longlong)piVar15 + 1);

    }

    lVar3 = param_2[2];

    iVar17 = iVar17 + 1;

    param_2[2] = lVar3 + 1U;

    local_res10[0] = cVar8;

    if ((param_2[1] == 0) || (lVar3 + 1U <= (ulonglong)param_2[1])) {

      lVar3 = *param_2;

      pcVar6 = *(char **)(lVar3 + 0x10);

      if (pcVar6 != *(char **)(lVar3 + 8)) {

        local_res10[0] = *pcVar6;

        *(char **)(lVar3 + 0x10) = pcVar6 + 1;

      }

    }

  }

  if (local_res10[0] == *(char *)**(undefined8 **)(*param_1 + 0xf8)) {

    lVar3 = param_2[2];

    param_2[2] = lVar3 + 1U;

    if ((param_2[1] == 0) || (lVar3 + 1U <= (ulonglong)param_2[1])) {

      lVar3 = *param_2;

      pcVar6 = *(char **)(lVar3 + 0x10);

      if (pcVar6 != *(char **)(lVar3 + 8)) {

        cVar8 = *pcVar6;

        *(char **)(lVar3 + 0x10) = pcVar6 + 1;

      }

    }

    local_res10[0] = cVar8;

    if ((piVar15 == piVar1) && (cVar8 == '0')) {

      bVar7 = true;

      do {

        lVar3 = param_2[2];

        iVar17 = iVar17 + -1;

        param_2[2] = lVar3 + 1U;

        if ((param_2[1] != 0) && ((ulonglong)param_2[1] < lVar3 + 1U)) {

LAB_1402deb41:

          local_res10[0] = '\0';

          break;

        }

        lVar3 = *param_2;

        pcVar6 = *(char **)(lVar3 + 0x10);

        if (pcVar6 == *(char **)(lVar3 + 8)) goto LAB_1402deb41;

        local_res10[0] = *pcVar6;

        *(char **)(lVar3 + 0x10) = pcVar6 + 1;

      } while (local_res10[0] == '0');

    }

    while( true ) {

      if ((local_res10[0] < '0') || ('9' < local_res10[0])) {

        if ((byte)(local_res10[0] + 0x9fU) < 0x1a) {

          uVar11 = (int)local_res10[0] - 0x57;

        }

        else if ((byte)(local_res10[0] + 0xbfU) < 0x1a) {

          uVar11 = (int)local_res10[0] - 0x37;

        }

        else {

          uVar11 = 0xffffffff;

        }

      }

      else {

        uVar11 = (int)local_res10[0] - 0x30;

      }

      if ((-(uint)(bVar18 != 0) & 6) + 9 < uVar11) break;

      bVar7 = true;

      if (piVar15 != piVar2) {

        *(char *)piVar15 = (char)uVar11;

        piVar15 = (int *)((longlong)piVar15 + 1);

      }

      lVar3 = param_2[2];

      param_2[2] = lVar3 + 1U;

      if ((param_2[1] == 0) || (lVar3 + 1U <= (ulonglong)param_2[1])) {

        lVar3 = *param_2;

        pcVar6 = *(char **)(lVar3 + 0x10);

        if (pcVar6 == *(char **)(lVar3 + 8)) goto LAB_1402debbb;

        local_res10[0] = *pcVar6;

        *(char **)(lVar3 + 0x10) = pcVar6 + 1;

      }

      else {

LAB_1402debbb:

        local_res10[0] = '\0';

      }

    }

  }

  iVar16 = 0;

  iVar10 = 0;

  if (!bVar7) {

    cVar8 = FUN_1402dfef4(&local_50);

    if ((cVar8 != '\0') && (bVar18 != 0)) {

      return 2;

    }

    return 7;

  }

  lVar3 = param_2[2];

  param_2[2] = lVar3 - 1U;

  if (((param_2[1] == 0) || (lVar3 - 1U <= (ulonglong)param_2[1])) &&

     (1 < (byte)(local_res10[0] + 1U))) {

    plVar5 = (longlong *)*param_2;

    if (plVar5[2] != *plVar5) {

      plVar5[2] = plVar5[2] + -1;

    }

  }

  local_58 = param_2[2];

  param_2[2] = local_58 + 1U;

  if ((param_2[1] == 0) || (local_58 + 1U <= (ulonglong)param_2[1])) {

    lVar3 = *param_2;

    pcVar6 = *(char **)(lVar3 + 0x10);

    if (pcVar6 != *(char **)(lVar3 + 8)) {

      local_res10[0] = *pcVar6;

      *(char **)(lVar3 + 0x10) = pcVar6 + 1;

      if (local_res10[0] == 'E') {

LAB_1402dec9b:

        bVar9 = bVar18 ^ 1;

      }

      else if (local_res10[0] == 'P') {

LAB_1402dec96:

        bVar9 = bVar18;

      }

      else {

        if (local_res10[0] == 'e') goto LAB_1402dec9b;

        bVar9 = 0;

        if (local_res10[0] == 'p') goto LAB_1402dec96;

      }

      iVar10 = 0;

      if (bVar9 == 0) goto LAB_1402deebb;

      lVar3 = param_2[2];

      param_2[2] = lVar3 + 1U;

      if ((param_2[1] == 0) || (lVar3 + 1U <= (ulonglong)param_2[1])) {

        lVar3 = *param_2;

        pcVar6 = *(char **)(lVar3 + 0x10);

        if (pcVar6 != *(char **)(lVar3 + 8)) {

          cVar8 = *pcVar6;

          *(char **)(lVar3 + 0x10) = pcVar6 + 1;

          if ((cVar8 == '+') || (local_res10[0] = cVar8, cVar8 == '-')) {

            lVar3 = param_2[2];

            param_2[2] = lVar3 + 1U;

            if ((param_2[1] == 0) || (lVar3 + 1U <= (ulonglong)param_2[1])) {

              lVar3 = *param_2;

              pcVar6 = *(char **)(lVar3 + 0x10);

              if (pcVar6 != *(char **)(lVar3 + 8)) {

                local_res10[0] = *pcVar6;

                *(char **)(lVar3 + 0x10) = pcVar6 + 1;

                goto LAB_1402ded2b;

              }

            }

            local_res10[0] = '\0';

          }

LAB_1402ded2b:

          bVar7 = false;

          if (local_res10[0] == '0') {

            bVar7 = true;

            do {

              lVar3 = param_2[2];

              param_2[2] = lVar3 + 1U;

              if ((param_2[1] != 0) && ((ulonglong)param_2[1] < lVar3 + 1U)) goto LAB_1402ded74;

              lVar3 = *param_2;

              pcVar6 = *(char **)(lVar3 + 0x10);

              if (pcVar6 == *(char **)(lVar3 + 8)) goto LAB_1402ded74;

              local_res10[0] = *pcVar6;

              *(char **)(lVar3 + 0x10) = pcVar6 + 1;

            } while (local_res10[0] == '0');

          }

          goto LAB_1402ded7f;

        }

      }

      cVar8 = '\0';

      bVar7 = false;

LAB_1402ded74:

      local_res10[0] = '\0';

LAB_1402ded7f:

      while( true ) {

        if ((local_res10[0] < '0') || ('9' < local_res10[0])) {

          if ((byte)(local_res10[0] + 0x9fU) < 0x1a) {

            uVar11 = (int)local_res10[0] - 0x57;

          }

          else {

            if (0x19 < (byte)(local_res10[0] + 0xbfU)) goto LAB_1402dedf8;

            uVar11 = (int)local_res10[0] - 0x37;

          }

        }

        else {

          uVar11 = (int)local_res10[0] - 0x30;

        }

        if (9 < uVar11) goto LAB_1402dedf8;

        bVar7 = true;

        iVar16 = uVar11 + iVar16 * 10;

        if (0x1450 < iVar16) break;

        lVar3 = param_2[2];

        param_2[2] = lVar3 + 1U;

        if ((param_2[1] == 0) || (lVar3 + 1U <= (ulonglong)param_2[1])) {

          lVar3 = *param_2;

          pcVar6 = *(char **)(lVar3 + 0x10);

          if (pcVar6 == *(char **)(lVar3 + 8)) goto LAB_1402dedd4;

          local_res10[0] = *pcVar6;

          *(char **)(lVar3 + 0x10) = pcVar6 + 1;

        }

        else {

LAB_1402dedd4:

          local_res10[0] = '\0';

        }

      }

      iVar16 = 0x1451;

LAB_1402dedf8:

      if ((byte)(local_res10[0] - 0x30U) < 10) {

        uVar11 = (int)local_res10[0] - 0x30;

      }

      else if ((byte)(local_res10[0] + 0x9fU) < 0x1a) {

        uVar11 = (int)local_res10[0] - 0x57;

      }

      else {

        if (0x19 < (byte)(local_res10[0] + 0xbfU)) goto LAB_1402dee5f;

        uVar11 = (int)local_res10[0] - 0x37;

      }

      if (9 < uVar11) goto LAB_1402dee5f;

      lVar3 = param_2[2];

      param_2[2] = lVar3 + 1U;

      if ((param_2[1] == 0) || (lVar3 + 1U <= (ulonglong)param_2[1])) {

        lVar3 = *param_2;

        pcVar6 = *(char **)(lVar3 + 0x10);

        if (pcVar6 == *(char **)(lVar3 + 8)) goto LAB_1402dee3f;

        local_res10[0] = *pcVar6;

        *(char **)(lVar3 + 0x10) = pcVar6 + 1;

      }

      else {

LAB_1402dee3f:

        local_res10[0] = '\0';

      }

      goto LAB_1402dedf8;

    }

  }

  local_res10[0] = '\0';

LAB_1402deebb:

  lVar3 = param_2[2];

  param_2[2] = lVar3 - 1U;

  if (((param_2[1] == 0) || (lVar3 - 1U <= (ulonglong)param_2[1])) &&

     (1 < (byte)(local_res10[0] + 1U))) {

    param_2 = (longlong *)*param_2;

    if (param_2[2] != *param_2) {

      param_2[2] = param_2[2] + -1;

    }

  }

  if (piVar15 != piVar1) {

    do {

      piVar2 = (int *)((longlong)piVar15 + -1);

      if (*(char *)piVar2 != '\0') break;

      piVar15 = piVar2;

    } while (piVar2 != piVar1);

    if (piVar15 != piVar1) {

      if (0x1450 < iVar10) {

        return 9;

      }

      if (-0x1451 < iVar10) {

        iVar10 = iVar10 + ((-(uint)(bVar18 != 0) & 3) + 1) * iVar17;

        if (0x1450 < iVar10) {

          return 9;

        }

        if (-0x1451 < iVar10) {

          *param_3 = iVar10;

          param_3[1] = (int)piVar15 - (int)piVar1;

          return uVar13;

        }

      }

      return 8;

    }

  }

  return 2;

LAB_1402dee5f:

  iVar10 = iVar16;

  if (cVar8 == '-') {

    iVar10 = -iVar16;

  }

  if (!bVar7) {

    cVar8 = FUN_1402dfef4(&local_50);

    if (cVar8 == '\0') {

      return 7;

    }

    lVar3 = param_2[2];

    param_2[2] = lVar3 + 1U;

    if ((param_2[1] == 0) || (lVar3 + 1U <= (ulonglong)param_2[1])) {

      lVar3 = *param_2;

      pcVar6 = *(char **)(lVar3 + 0x10);

      if (pcVar6 != *(char **)(lVar3 + 8)) {

        local_res10[0] = *pcVar6;

        *(char **)(lVar3 + 0x10) = pcVar6 + 1;

        goto LAB_1402deebb;

      }

    }

    local_res10[0] = '\0';

  }

  goto LAB_1402deebb;

}




