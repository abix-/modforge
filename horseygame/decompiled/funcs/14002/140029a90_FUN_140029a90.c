// Address: 0x140029a90
// Ghidra name: FUN_140029a90
// ============ 0x140029a90 FUN_140029a90 (size=1689) ============


/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

/* WARNING: Type propagation algorithm not settling */



void FUN_140029a90(longlong *param_1,longlong *param_2,undefined8 *param_3)



{

  ulonglong uVar1;

  ulonglong uVar2;

  undefined8 *puVar3;

  code *pcVar4;

  bool bVar5;

  bool bVar6;

  bool bVar7;

  undefined1 uVar8;

  int iVar9;

  uint uVar10;

  int iVar11;

  undefined8 *puVar12;

  longlong lVar13;

  longlong *plVar14;

  char cVar15;

  longlong lVar16;

  undefined1 auStackY_e8 [32];

  undefined **local_b8;

  undefined8 local_b0;

  undefined8 local_a8;

  undefined8 local_a0;

  undefined4 local_98;

  undefined8 *local_90;

  undefined8 local_88;

  longlong local_80;

  undefined8 uStack_78;

  undefined8 local_70;

  ulonglong local_68;

  undefined8 local_60;

  undefined8 local_58;

  undefined1 local_50;

  ulonglong local_48;

  

  local_48 = DAT_1403e8b00 ^ (ulonglong)auStackY_e8;

  iVar9 = *(int *)((longlong)*(int *)(*param_2 + 4) + 0x10 + (longlong)param_2);

  while (iVar9 == 0) {

    iVar9 = FUN_14002cac0(param_2);

    if (iVar9 < 1) goto joined_r0x000140029c3c;

    uVar1 = param_3[2];

    if (uVar1 < (ulonglong)param_3[3]) {

      param_3[2] = uVar1 + 1;

      puVar12 = param_3;

      if (0xf < (ulonglong)param_3[3]) {

        puVar12 = (undefined8 *)*param_3;

      }

      *(char *)((longlong)puVar12 + uVar1) = (char)iVar9;

      *(undefined1 *)((longlong)puVar12 + uVar1 + 1) = 0;

    }

    else {

      FUN_1400280d0(param_3);

    }

    if (iVar9 == 0x3e) break;

    iVar9 = *(int *)((longlong)*(int *)(*param_2 + 4) + 0x10 + (longlong)param_2);

  }

  uVar1 = param_3[2];

  if (2 < uVar1) {

    if (uVar1 <= uVar1 - 1) {

LAB_14002a124:

      FUN_14002cca0();

      pcVar4 = (code *)swi(3);

      (*pcVar4)();

      return;

    }

    uVar2 = param_3[3];

    puVar12 = param_3;

    if (0xf < uVar2) {

      puVar12 = (undefined8 *)*param_3;

    }

    if (*(char *)((longlong)puVar12 + (uVar1 - 1)) == '>') {

      if (uVar1 <= uVar1 - 2) goto LAB_14002a124;

      puVar12 = param_3;

      if (0xf < uVar2) {

        puVar12 = (undefined8 *)*param_3;

      }

      if (*(char *)((longlong)puVar12 + (uVar1 - 2)) == '/') {

        return;

      }

    }

    puVar12 = param_3;

    if (0xf < uVar2) {

      puVar12 = (undefined8 *)*param_3;

    }

    if (*(char *)((longlong)puVar12 + (uVar1 - 1)) == '>') {

LAB_140029bb0:

      do {

        if (*(int *)((longlong)*(int *)(*param_2 + 4) + 0x10 + (longlong)param_2) == 0) {

          while (uVar10 = FUN_14002c950(param_2), (int)uVar10 < 0x100) {

            iVar9 = isspace(uVar10 & 0xff);

            if ((((iVar9 == 0) && ((char)uVar10 != '\n')) && ((char)uVar10 != '\r')) ||

               ((int)uVar10 < 1)) break;

            uVar8 = FUN_14002cac0(param_2);

            uVar1 = param_3[2];

            if (uVar1 < (ulonglong)param_3[3]) {

              param_3[2] = uVar1 + 1;

              puVar12 = param_3;

              if (0xf < (ulonglong)param_3[3]) {

                puVar12 = (undefined8 *)*param_3;

              }

              *(undefined1 *)((longlong)puVar12 + uVar1) = uVar8;

              *(undefined1 *)((longlong)puVar12 + uVar1 + 1) = 0;

            }

            else {

              FUN_1400280d0(param_3);

            }

            if (*(int *)((longlong)*(int *)(*param_2 + 4) + 0x10 + (longlong)param_2) != 0) break;

          }

        }

        if ((*(int *)((longlong)*(int *)(*param_2 + 4) + 0x10 + (longlong)param_2) != 0) ||

           (iVar9 = FUN_14002c950(param_2), iVar9 == 0x3c)) {

          if (*(int *)((longlong)*(int *)(*param_2 + 4) + 0x10 + (longlong)param_2) != 0) {

            return;

          }

          iVar9 = FUN_14002c950(param_2);

          if (iVar9 != 0x3c) {

            FID_conflict__assert

                      (L"in->peek() == \'<\'",L"C:\\dev\\tinyxml\\tinyxmlparser.cpp",0x3c0);

          }

          iVar9 = *(int *)(param_3 + 2);

          bVar6 = false;

          bVar5 = false;

LAB_140029e60:

          if (*(int *)((longlong)*(int *)(*param_2 + 4) + 0x10 + (longlong)param_2) != 0) {

            return;

          }

          uVar10 = FUN_14002c950(param_2);

          if ((int)uVar10 < 1) goto joined_r0x00014002a0a1;

          if (uVar10 == 0x3e) {

            if (!bVar6) goto LAB_140029fd1;

            goto LAB_140029f7b;

          }

          uVar1 = param_3[2];

          cVar15 = (char)uVar10;

          if (uVar1 < (ulonglong)param_3[3]) {

            param_3[2] = uVar1 + 1;

            puVar12 = param_3;

            if (0xf < (ulonglong)param_3[3]) {

              puVar12 = (undefined8 *)*param_3;

            }

            *(char *)((longlong)puVar12 + uVar1) = cVar15;

            *(undefined1 *)((longlong)puVar12 + uVar1 + 1) = 0;

          }

          else {

            FUN_1400280d0(param_3);

          }

          FUN_14002cac0(param_2);

          if ((uVar10 == 0x5b) && (8 < (ulonglong)param_3[2])) {

            puVar12 = param_3;

            if (0xf < (ulonglong)param_3[3]) {

              puVar12 = (undefined8 *)*param_3;

            }

            iVar11 = strcmp((char *)((param_3[2] - 9) + (longlong)puVar12),"<![CDATA[");

            if (iVar11 == 0) goto LAB_140029f5d;

          }

          if ((!bVar5) && (uVar10 != 0x3c)) {

            if ((int)uVar10 < 0x100) {

              iVar11 = isspace(uVar10 & 0xff);

              if (((iVar11 != 0) || (cVar15 == '\n')) || (bVar7 = false, cVar15 == '\r')) {

                bVar7 = true;

              }

              if ((!bVar7) && (bVar5 = true, uVar10 == 0x2f)) {

                bVar6 = true;

              }

            }

            else {

              bVar5 = true;

            }

          }

          goto LAB_140029e60;

        }

        local_b0 = 0xffffffffffffffff;

        local_a8 = 0;

        uStack_78 = 0;

        local_68 = 0xf;

        local_a0 = 0;

        local_98 = 4;

        local_90 = (undefined8 *)0x0;

        local_88 = 0;

        local_60 = 0;

        local_58 = 0;

        local_b8 = TiXmlText::vftable;

        local_70 = 0;

        local_80 = 0;

        local_50 = 0;

        FUN_14002b4d0(&local_b8,param_2);

        local_b8 = TiXmlNode::vftable;

        puVar12 = local_90;

        while (puVar12 != (undefined8 *)0x0) {

          puVar3 = (undefined8 *)puVar12[0xc];

          (**(code **)*puVar12)(puVar12,1);

          puVar12 = puVar3;

        }

        if (0xf < local_68) {

          if ((0xfff < local_68 + 1) && (0x1f < (local_80 - *(longlong *)(local_80 + -8)) - 8U)) {

                    /* WARNING: Subroutine does not return */

            _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

          }

          FUN_1402c7088();

        }

      } while( true );

    }

  }

  return;

joined_r0x000140029c3c:

  while( true ) {

    if (param_1 == (longlong *)0x0) {

      return;

    }

    lVar13 = (**(code **)(*param_1 + 0x20))(param_1);

    if (lVar13 != 0) break;

    param_1 = (longlong *)param_1[3];

  }

  lVar13 = (**(code **)(*param_1 + 0x20))(param_1);

  if (lVar13 == 0) {

    return;

  }

  if (*(char *)(lVar13 + 0x68) != '\0') {

    return;

  }

  *(undefined1 *)(lVar13 + 0x68) = 1;

  *(undefined4 *)(lVar13 + 0x6c) = 0xd;

  lVar16 = -1;

  do {

    lVar16 = lVar16 + 1;

  } while (PTR_s_Error_null__0__or_unexpected_EOF_14039a418[lVar16] != '\0');

  goto LAB_140029c9a;

joined_r0x00014002a0a1:

  while( true ) {

    if (param_1 == (longlong *)0x0) {

      return;

    }

    lVar13 = (**(code **)(*param_1 + 0x20))(param_1);

    if (lVar13 != 0) break;

    param_1 = (longlong *)param_1[3];

  }

  lVar13 = (**(code **)(*param_1 + 0x20))(param_1);

  if (lVar13 == 0) {

    return;

  }

  if (*(char *)(lVar13 + 0x68) != '\0') {

    return;

  }

  *(undefined1 *)(lVar13 + 0x68) = 1;

  *(undefined4 *)(lVar13 + 0x6c) = 0xd;

  lVar16 = -1;

  do {

    lVar16 = lVar16 + 1;

  } while (PTR_s_Error_null__0__or_unexpected_EOF_14039a418[lVar16] != '\0');

  goto LAB_140029c9a;

LAB_140029f5d:

  if (!bVar6) {

LAB_140029fd1:

    puVar12 = param_3;

    if (0xf < (ulonglong)param_3[3]) {

      puVar12 = (undefined8 *)*param_3;

    }

    plVar14 = (longlong *)FUN_1400297b0(param_1,(longlong)puVar12 + (longlong)iVar9,0);

    if (plVar14 == (longlong *)0x0) {

      return;

    }

    (**(code **)(*plVar14 + 0x88))(plVar14,param_2,param_3);

    (**(code **)*plVar14)(plVar14,1);

    goto LAB_140029bb0;

  }

  FID_conflict__assert(L"!closingTag",L"C:\\dev\\tinyxml\\tinyxmlparser.cpp",0x3e0);

LAB_140029f7b:

  if (*(int *)((longlong)*(int *)(*param_2 + 4) + 0x10 + (longlong)param_2) != 0) {

    return;

  }

  uVar10 = FUN_14002cac0(param_2);

  if (0 < (int)uVar10) {

    if (uVar10 != 0x3e) {

      FID_conflict__assert(L"c == \'>\'",L"C:\\dev\\tinyxml\\tinyxmlparser.cpp",0x3fb);

    }

    FUN_140027890(param_3,uVar10 & 0xff);

    return;

  }

  while( true ) {

    if (param_1 == (longlong *)0x0) {

      return;

    }

    lVar13 = (**(code **)(*param_1 + 0x20))(param_1);

    if (lVar13 != 0) break;

    param_1 = (longlong *)param_1[3];

  }

  lVar13 = (**(code **)(*param_1 + 0x20))(param_1);

  if (lVar13 == 0) {

    return;

  }

  if (*(char *)(lVar13 + 0x68) != '\0') {

    return;

  }

  *(undefined1 *)(lVar13 + 0x68) = 1;

  *(undefined4 *)(lVar13 + 0x6c) = 0xd;

  lVar16 = -1;

  do {

    lVar16 = lVar16 + 1;

  } while (PTR_s_Error_null__0__or_unexpected_EOF_14039a418[lVar16] != '\0');

LAB_140029c9a:

  FUN_140027f50(lVar13 + 0x70);

  *(undefined8 *)(lVar13 + 0x94) = 0xffffffffffffffff;

  return;

}




