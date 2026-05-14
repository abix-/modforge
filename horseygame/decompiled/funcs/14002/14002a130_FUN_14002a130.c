// Address: 0x14002a130
// Ghidra name: FUN_14002a130
// ============ 0x14002a130 FUN_14002a130 (size=1804) ============


/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */



char * FUN_14002a130(longlong *param_1,undefined8 param_2,longlong *param_3,undefined4 param_4)



{

  char cVar1;

  ulonglong uVar2;

  char *pcVar3;

  longlong lVar4;

  char *pcVar5;

  longlong *plVar6;

  longlong lVar7;

  undefined1 auStackY_b8 [32];

  undefined8 local_78;

  undefined8 uStack_70;

  longlong local_68;

  ulonglong local_60;

  ulonglong local_58;

  

  local_58 = DAT_1403e8b00 ^ (ulonglong)auStackY_b8;

  pcVar3 = (char *)FUN_140028820(param_2,param_4);

  for (plVar6 = param_1; plVar6 != (longlong *)0x0; plVar6 = (longlong *)plVar6[3]) {

    lVar4 = (**(code **)(*plVar6 + 0x20))(plVar6);

    if (lVar4 != 0) {

      lVar4 = (**(code **)(*plVar6 + 0x20))(plVar6);

      goto LAB_14002a1a0;

    }

  }

  lVar4 = 0;

LAB_14002a1a0:

  if ((pcVar3 == (char *)0x0) || (*pcVar3 == '\0')) {

    if (lVar4 == 0) {

      return (char *)0x0;

    }

    if (*(char *)(lVar4 + 0x68) != '\0') {

      return (char *)0x0;

    }

    *(undefined1 *)(lVar4 + 0x68) = 1;

    *(undefined4 *)(lVar4 + 0x6c) = 3;

    lVar7 = -1;

    do {

      lVar7 = lVar7 + 1;

    } while (PTR_s_Error_parsing_Element__14039a3c8[lVar7] != '\0');

    FUN_140027f50(lVar4 + 0x70);

    *(undefined8 *)(lVar4 + 0x94) = 0xffffffffffffffff;

    return (char *)0x0;

  }

  if (param_3 != (longlong *)0x0) {

    FUN_140028650(param_3,pcVar3);

    param_1[1] = *param_3;

  }

  if (*pcVar3 == '<') {

    pcVar3 = (char *)FUN_140028820(pcVar3 + 1,param_4);

    pcVar5 = (char *)FUN_140028900(pcVar3,param_1 + 7);

    if ((pcVar5 != (char *)0x0) && (*pcVar5 != '\0')) {

      uStack_70 = 0;

      local_68 = 2;

      local_60 = 0xf;

      local_78 = (char *)(ulonglong)DAT_14039c084;

      plVar6 = param_1 + 7;

      if (0xf < (ulonglong)param_1[10]) {

        plVar6 = (longlong *)param_1[7];

      }

      uVar2 = param_1[9];

      if (uVar2 < 0xe) {

        local_68 = uVar2 + 2;

        FUN_1402f8e20((longlong)&local_78 + 2,plVar6);

        *(undefined1 *)(uVar2 + (longlong)&local_78 + 2) = 0;

      }

      else {

        FUN_140027c80(&local_78,uVar2);

      }

      while (*pcVar5 != '\0') {

        pcVar3 = (char *)FUN_140028820(pcVar5,param_4);

        if ((pcVar3 == (char *)0x0) || (cVar1 = *pcVar3, cVar1 == '\0')) {

          if ((lVar4 != 0) && (*(char *)(lVar4 + 0x68) == '\0')) {

            *(undefined1 *)(lVar4 + 0x68) = 1;

            *(undefined4 *)(lVar4 + 0x6c) = 6;

            lVar7 = -1;

            do {

              lVar7 = lVar7 + 1;

            } while (PTR_s_Error_reading_Attributes__14039a3e0[lVar7] != '\0');

LAB_14002a6ce:

            FUN_140027f50(lVar4 + 0x70);

            *(undefined8 *)(lVar4 + 0x94) = 0xffffffffffffffff;

            goto joined_r0x00014002a6e5;

          }

          goto LAB_14002a704;

        }

        if (cVar1 == '/') {

          if (pcVar3[1] != '>') {

            if ((lVar4 != 0) && (*(char *)(lVar4 + 0x68) == '\0')) {

              *(undefined1 *)(lVar4 + 0x68) = 1;

              *(undefined4 *)(lVar4 + 0x6c) = 7;

              lVar7 = -1;

              do {

                lVar7 = lVar7 + 1;

              } while (PTR_s_Error__empty_tag__14039a3e8[lVar7] != '\0');

              FUN_140027f50(lVar4 + 0x70);

              *(undefined8 *)(lVar4 + 0x94) = 0xffffffffffffffff;

              if (param_3 != (longlong *)0x0) {

                pcVar5 = pcVar3 + 1;

                goto LAB_14002a6ef;

              }

            }

            goto LAB_14002a704;

          }

          pcVar5 = pcVar3 + 2;

          break;

        }

        if (cVar1 == '>') {

          pcVar5 = (char *)FUN_14002a840(param_1,pcVar3 + 1);

          if ((pcVar5 == (char *)0x0) || (*pcVar5 == '\0')) {

            if ((lVar4 != 0) && (*(char *)(lVar4 + 0x68) == '\0')) {

              *(undefined1 *)(lVar4 + 0x68) = 1;

              *(undefined4 *)(lVar4 + 0x6c) = 8;

              lVar7 = -1;

              do {

                lVar7 = lVar7 + 1;

              } while (PTR_s_Error_reading_end_tag__14039a3f0[lVar7] != '\0');

              goto LAB_14002a6ce;

            }

            goto LAB_14002a704;

          }

          pcVar3 = (char *)&local_78;

          if (0xf < local_60) {

            pcVar3 = local_78;

          }

          if (pcVar3 == (char *)0x0) {

            FID_conflict__assert(L"tag",L"C:\\dev\\tinyxml\\tinyxmlparser.cpp",0x21c);

          }

          if (*pcVar5 != '\0') {

            lVar7 = (longlong)pcVar5 - (longlong)pcVar3;

            goto LAB_14002a4e7;

          }

          FID_conflict__assert(L"0",L"C:\\dev\\tinyxml\\tinyxmlparser.cpp",0x21f);

          goto LAB_14002a5b1;

        }

        plVar6 = (longlong *)FUN_1402c704c(0x70);

        plVar6[1] = -1;

        plVar6[2] = 0;

        *plVar6 = (longlong)TiXmlAttribute::vftable;

        plVar6[4] = 0;

        plVar6[5] = 0;

        plVar6[6] = 0;

        plVar6[7] = 0xf;

        *(undefined1 *)(plVar6 + 4) = 0;

        plVar6[8] = 0;

        plVar6[9] = 0;

        plVar6[10] = 0;

        plVar6[0xb] = 0xf;

        *(undefined1 *)(plVar6 + 8) = 0;

        plVar6[0xd] = 0;

        plVar6[0xc] = 0;

        plVar6[3] = lVar4;

        pcVar5 = (char *)(**(code **)(*plVar6 + 0x10))(plVar6,pcVar3);

        if ((pcVar5 == (char *)0x0) || (*pcVar5 == '\0')) {

          if ((lVar4 != 0) && (*(char *)(lVar4 + 0x68) == '\0')) {

            *(undefined1 *)(lVar4 + 0x68) = 1;

            *(undefined4 *)(lVar4 + 0x6c) = 3;

            lVar7 = -1;

            do {

              lVar7 = lVar7 + 1;

            } while (PTR_s_Error_parsing_Element__14039a3c8[lVar7] != '\0');

LAB_14002a40f:

            FUN_140027f50(lVar4 + 0x70);

            *(undefined8 *)(lVar4 + 0x94) = 0xffffffffffffffff;

            if (param_3 != (longlong *)0x0) {

              FUN_140028650(param_3,pcVar3);

              *(longlong *)(lVar4 + 0x94) = *param_3;

            }

          }

LAB_14002a440:

          (**(code **)*plVar6)(plVar6,1);

          goto LAB_14002a704;

        }

        lVar7 = FUN_1400273e0(param_1 + 0xd,plVar6 + 4);

        if (lVar7 != 0) {

          if ((lVar4 != 0) && (*(char *)(lVar4 + 0x68) == '\0')) {

            *(undefined1 *)(lVar4 + 0x68) = 1;

            *(undefined4 *)(lVar4 + 0x6c) = 3;

            lVar7 = -1;

            do {

              lVar7 = lVar7 + 1;

            } while (PTR_s_Error_parsing_Element__14039a3c8[lVar7] != '\0');

            goto LAB_14002a40f;

          }

          goto LAB_14002a440;

        }

        FUN_1400272d0(param_1 + 0xd,plVar6);

      }

      goto LAB_14002a706;

    }

    if (lVar4 == 0) {

      return (char *)0x0;

    }

    if (*(char *)(lVar4 + 0x68) != '\0') {

      return (char *)0x0;

    }

    *(undefined1 *)(lVar4 + 0x68) = 1;

    *(undefined4 *)(lVar4 + 0x6c) = 4;

    lVar7 = -1;

    do {

      lVar7 = lVar7 + 1;

    } while (PTR_s_Failed_to_read_Element_name_14039a3d0[lVar7] != '\0');

    FUN_140027f50(lVar4 + 0x70);

    *(undefined8 *)(lVar4 + 0x94) = 0xffffffffffffffff;

    if (pcVar3 == (char *)0x0) {

      return (char *)0x0;

    }

  }

  else {

    if (lVar4 == 0) {

      return (char *)0x0;

    }

    if (*(char *)(lVar4 + 0x68) != '\0') {

      return (char *)0x0;

    }

    *(undefined1 *)(lVar4 + 0x68) = 1;

    *(undefined4 *)(lVar4 + 0x6c) = 3;

    lVar7 = -1;

    do {

      lVar7 = lVar7 + 1;

    } while (PTR_s_Error_parsing_Element__14039a3c8[lVar7] != '\0');

    FUN_140027f50(lVar4 + 0x70);

    *(undefined8 *)(lVar4 + 0x94) = 0xffffffffffffffff;

  }

  if (param_3 != (longlong *)0x0) {

    FUN_140028650(param_3,pcVar3,param_4);

    *(longlong *)(lVar4 + 0x94) = *param_3;

  }

  return (char *)0x0;

  while ((pcVar3[lVar7] == *pcVar3 && (pcVar3 = pcVar3 + 1, pcVar3[lVar7] != '\0'))) {

LAB_14002a4e7:

    if (*pcVar3 == '\0') goto LAB_14002a505;

  }

  if (*pcVar3 == '\0') {

LAB_14002a505:

    pcVar5 = (char *)FUN_140028820(pcVar5 + local_68,param_4);

    if (((pcVar5 != (char *)0x0) && (*pcVar5 != '\0')) && (*pcVar5 == '>')) {

      pcVar5 = pcVar5 + 1;

      goto LAB_14002a706;

    }

    if ((lVar4 != 0) && (*(char *)(lVar4 + 0x68) == '\0')) {

      *(undefined1 *)(lVar4 + 0x68) = 1;

      *(undefined4 *)(lVar4 + 0x6c) = 8;

      lVar7 = -1;

      do {

        lVar7 = lVar7 + 1;

      } while (PTR_s_Error_reading_end_tag__14039a3f0[lVar7] != '\0');

      FUN_140027f50(lVar4 + 0x70);

      *(undefined8 *)(lVar4 + 0x94) = 0xffffffffffffffff;

joined_r0x00014002a6e5:

      if (pcVar5 != (char *)0x0) goto joined_r0x00014002a6ea;

    }

  }

  else {

LAB_14002a5b1:

    if ((lVar4 != 0) && (*(char *)(lVar4 + 0x68) == '\0')) {

      *(undefined1 *)(lVar4 + 0x68) = 1;

      *(undefined4 *)(lVar4 + 0x6c) = 8;

      lVar7 = -1;

      do {

        lVar7 = lVar7 + 1;

      } while (PTR_s_Error_reading_end_tag__14039a3f0[lVar7] != '\0');

      FUN_140027f50(lVar4 + 0x70);

      *(undefined8 *)(lVar4 + 0x94) = 0xffffffffffffffff;

joined_r0x00014002a6ea:

      if (param_3 != (longlong *)0x0) {

LAB_14002a6ef:

        FUN_140028650(param_3,pcVar5);

        *(longlong *)(lVar4 + 0x94) = *param_3;

      }

    }

  }

LAB_14002a704:

  pcVar5 = (char *)0x0;

LAB_14002a706:

  if (0xf < local_60) {

    if ((0xfff < local_60 + 1) && ((char *)0x1f < local_78 + (-8 - *(longlong *)(local_78 + -8)))) {

                    /* WARNING: Subroutine does not return */

      _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

    }

    FUN_1402c7088();

  }

  return pcVar5;

}




