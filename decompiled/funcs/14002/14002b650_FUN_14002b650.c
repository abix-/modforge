// Address: 0x14002b650
// Ghidra name: FUN_14002b650
// ============ 0x14002b650 FUN_14002b650 (size=808) ============


/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



longlong FUN_14002b650(longlong *param_1,char *param_2,longlong *param_3,undefined4 param_4)



{

  char cVar1;

  ulonglong uVar2;

  longlong lVar3;

  char *pcVar4;

  longlong *plVar5;

  char *pcVar6;

  char *pcVar7;

  longlong lVar8;

  undefined1 auStackY_98 [32];

  longlong local_68 [3];

  ulonglong uStack_50;

  ulonglong local_48;

  

  local_48 = DAT_1403e8b00 ^ (ulonglong)auStackY_98;

  FUN_140027f50(param_1 + 7,&DAT_14039bcb9,0);

  for (plVar5 = param_1; plVar5 != (longlong *)0x0; plVar5 = (longlong *)plVar5[3]) {

    lVar3 = (**(code **)(*plVar5 + 0x20))(plVar5);

    if (lVar3 != 0) {

      lVar3 = (**(code **)(*plVar5 + 0x20))(plVar5);

      goto LAB_14002b6b0;

    }

  }

  lVar3 = 0;

LAB_14002b6b0:

  if (param_3 != (longlong *)0x0) {

    FUN_140028650(param_3,param_2,param_4);

    param_1[1] = *param_3;

  }

  pcVar6 = "<![CDATA[";

  if ((char)param_1[0xd] == '\0') {

    pcVar7 = "<![CDATA[";

    if (param_2 == (char *)0x0) {

      FID_conflict__assert(L"p",L"C:\\dev\\tinyxml\\tinyxmlparser.cpp",0x21b);

    }

    else {

      pcVar4 = param_2;

      if (*param_2 != '\0') {

        do {

          if ((*pcVar7 == '\0') || (*pcVar4 != *pcVar7)) break;

          pcVar4 = pcVar4 + 1;

          pcVar7 = pcVar7 + 1;

        } while (*pcVar4 != '\0');

        if (*pcVar7 != '\0') goto LAB_14002b715;

        goto LAB_14002b77e;

      }

    }

    FID_conflict__assert(L"0",L"C:\\dev\\tinyxml\\tinyxmlparser.cpp",0x21f);

LAB_14002b715:

    lVar3 = FUN_140028cc0(param_2,param_1 + 7,1,&DAT_14039c080);

    if (lVar3 == 0) {

      return 0;

    }

    return lVar3 + -1;

  }

LAB_14002b77e:

  *(undefined1 *)(param_1 + 0xd) = 1;

  if (param_2 == (char *)0x0) {

    FID_conflict__assert(L"p",L"C:\\dev\\tinyxml\\tinyxmlparser.cpp",0x21b);

  }

  else {

    pcVar7 = param_2;

    if (*param_2 != '\0') {

      do {

        if ((*pcVar6 == '\0') || (*pcVar7 != *pcVar6)) break;

        pcVar7 = pcVar7 + 1;

        pcVar6 = pcVar6 + 1;

      } while (*pcVar7 != '\0');

      if (*pcVar6 == '\0') {

        pcVar6 = param_2 + 9;

        if (pcVar6 != (char *)0x0) {

          param_2 = param_2 + -0x14039c08b;

          do {

            if (*pcVar6 == '\0') break;

            pcVar7 = "]]>";

            do {

              if ((*pcVar7 == '\0') || (param_2[(longlong)pcVar7] != *pcVar7)) break;

              pcVar7 = pcVar7 + 1;

            } while (param_2[(longlong)pcVar7] != '\0');

            if (*pcVar7 == '\0') break;

            cVar1 = *pcVar6;

            uVar2 = param_1[9];

            if (uVar2 < (ulonglong)param_1[10]) {

              param_1[9] = uVar2 + 1;

              plVar5 = param_1 + 7;

              if (0xf < (ulonglong)param_1[10]) {

                plVar5 = (longlong *)param_1[7];

              }

              *(char *)((longlong)plVar5 + uVar2) = cVar1;

              *(undefined1 *)((longlong)plVar5 + uVar2 + 1) = 0;

            }

            else {

              FUN_1400280d0(param_1 + 7);

            }

            param_2 = param_2 + 1;

            pcVar6 = pcVar6 + 1;

          } while (pcVar6 != (char *)0x0);

        }

        local_68[1] = 0;

        local_68[2] = _DAT_14039caa0;

        uStack_50 = _UNK_14039caa8;

        local_68[0] = 0;

        lVar3 = FUN_140028cc0(pcVar6,local_68,0);

        if (uStack_50 < 0x10) {

          return lVar3;

        }

        lVar8 = local_68[0];

        if ((0xfff < uStack_50 + 1) &&

           (lVar8 = *(longlong *)(local_68[0] + -8), 0x1f < (local_68[0] - lVar8) - 8U)) {

                    /* WARNING: Subroutine does not return */

          _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

        }

        FUN_1402c7088(lVar8);

        return lVar3;

      }

      goto LAB_14002b7bd;

    }

  }

  FID_conflict__assert(L"0",L"C:\\dev\\tinyxml\\tinyxmlparser.cpp",0x21f);

LAB_14002b7bd:

  if (*(char *)(lVar3 + 0x68) != '\0') {

    return 0;

  }

  *(undefined1 *)(lVar3 + 0x68) = 1;

  *(undefined4 *)(lVar3 + 0x6c) = 0xe;

  lVar8 = -1;

  do {

    lVar8 = lVar8 + 1;

  } while (PTR_s_Error_parsing_CDATA__14039a420[lVar8] != '\0');

  FUN_140027f50(lVar3 + 0x70);

  *(undefined8 *)(lVar3 + 0x94) = 0xffffffffffffffff;

  if (param_2 == (char *)0x0) {

    return 0;

  }

  if (param_3 == (longlong *)0x0) {

    return 0;

  }

  FUN_140028650(param_3,param_2,param_4);

  *(longlong *)(lVar3 + 0x94) = *param_3;

  return 0;

}




