// Address: 0x14002b980
// Ghidra name: FUN_14002b980
// ============ 0x14002b980 FUN_14002b980 (size=4035) ============


/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

/* WARNING: Removing unreachable block (ram,0x00014002c70d) */

/* WARNING: Removing unreachable block (ram,0x00014002c717) */

/* WARNING: Removing unreachable block (ram,0x00014002c730) */

/* WARNING: Removing unreachable block (ram,0x00014002c73a) */

/* WARNING: Removing unreachable block (ram,0x00014002c757) */

/* WARNING: Removing unreachable block (ram,0x00014002c7bf) */

/* WARNING: Removing unreachable block (ram,0x00014002c7c5) */

/* WARNING: Removing unreachable block (ram,0x00014002c7e0) */

/* WARNING: Removing unreachable block (ram,0x00014002c7ea) */

/* WARNING: Removing unreachable block (ram,0x00014002c76a) */

/* WARNING: Removing unreachable block (ram,0x00014002c774) */

/* WARNING: Removing unreachable block (ram,0x00014002c790) */

/* WARNING: Removing unreachable block (ram,0x00014002c79a) */

/* WARNING: Removing unreachable block (ram,0x00014002c7b3) */

/* WARNING: Removing unreachable block (ram,0x00014002c7fe) */

/* WARNING: Removing unreachable block (ram,0x00014002c803) */

/* WARNING: Removing unreachable block (ram,0x00014002c6e5) */

/* WARNING: Type propagation algorithm not settling */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



byte * FUN_14002b980(longlong *param_1,undefined8 param_2,longlong *param_3,undefined4 param_4)



{

  byte bVar1;

  longlong *plVar2;

  ulonglong uVar3;

  int iVar4;

  int iVar5;

  char *pcVar6;

  longlong lVar7;

  byte *pbVar8;

  byte *pbVar9;

  undefined8 *******pppppppuVar10;

  char *pcVar11;

  byte *pbVar12;

  longlong lVar13;

  ulonglong uVar14;

  ulonglong uVar15;

  undefined1 auStackY_208 [32];

  ulonglong local_198;

  undefined8 uStack_190;

  ulonglong local_188;

  ulonglong uStack_180;

  undefined8 *******local_178;

  undefined8 uStack_170;

  ulonglong local_168;

  ulonglong uStack_160;

  undefined8 local_158;

  undefined8 local_150;

  undefined **local_148;

  longlong local_140;

  undefined8 local_138;

  longlong local_130;

  ulonglong local_128;

  undefined8 uStack_120;

  ulonglong local_118;

  ulonglong uStack_110;

  undefined8 *******local_108;

  undefined8 uStack_100;

  ulonglong local_f8;

  ulonglong uStack_f0;

  undefined8 local_e8;

  undefined8 local_e0;

  undefined **local_d8;

  longlong local_d0;

  undefined8 local_c8;

  longlong local_c0;

  ulonglong local_b8;

  undefined8 uStack_b0;

  ulonglong local_a8;

  ulonglong uStack_a0;

  undefined8 *******local_98;

  undefined8 uStack_90;

  ulonglong local_88;

  ulonglong uStack_80;

  undefined8 local_78;

  undefined8 local_70;

  ulonglong local_68;

  

  local_68 = DAT_1403e8b00 ^ (ulonglong)auStackY_208;

  pcVar6 = (char *)FUN_140028820(param_2,param_4);

  for (plVar2 = param_1; plVar2 != (longlong *)0x0; plVar2 = (longlong *)plVar2[3]) {

    lVar7 = (**(code **)(*plVar2 + 0x20))(plVar2);

    if (lVar7 != 0) {

      lVar7 = (**(code **)(*plVar2 + 0x20))(plVar2);

      goto LAB_14002ba01;

    }

  }

  lVar7 = 0;

LAB_14002ba01:

  if ((pcVar6 != (char *)0x0) && (*pcVar6 != '\0')) {

    pcVar11 = "<?xml";

    do {

      if (*pcVar11 == '\0') goto LAB_14002ba50;

      iVar4 = tolower((int)pcVar11[(longlong)(pcVar6 + -0x14039c754)]);

      iVar5 = tolower((int)*pcVar11);

    } while ((iVar4 == iVar5) &&

            (pcVar11 = pcVar11 + 1, (pcVar6 + -0x14039c754)[(longlong)pcVar11] != '\0'));

    if (*pcVar11 == '\0') {

LAB_14002ba50:

      if (param_3 != (longlong *)0x0) {

        FUN_140028650(param_3,pcVar6,param_4);

        param_1[1] = *param_3;

      }

      FUN_140027f50(param_1 + 0xd,&DAT_14039bcb9,0);

      FUN_140027f50(param_1 + 0x11,&DAT_14039bcb9,0);

      FUN_140027f50(param_1 + 0x15,&DAT_14039bcb9,0);

      uVar15 = _UNK_14039caa8;

      uVar14 = _DAT_14039caa0;

      pbVar12 = (byte *)(pcVar6 + 5);

      if (pbVar12 == (byte *)0x0) {

        return (byte *)0x0;

      }

LAB_14002bae2:

      do {

        pcVar6 = "version";

        if (*pbVar12 == 0) {

          return (byte *)0x0;

        }

        if (*pbVar12 == 0x3e) {

          return pbVar12 + 1;

        }

        pbVar12 = (byte *)FUN_140028820(pbVar12,param_4);

        if (pbVar12 == (byte *)0x0) {

          FID_conflict__assert(L"p",L"C:\\dev\\tinyxml\\tinyxmlparser.cpp",0x21b);

LAB_14002bb28:

          FID_conflict__assert(L"0",L"C:\\dev\\tinyxml\\tinyxmlparser.cpp",0x21f);

LAB_14002bf9e:

          pcVar6 = "encoding";

          if (pbVar12 == (byte *)0x0) {

            FID_conflict__assert(L"p",L"C:\\dev\\tinyxml\\tinyxmlparser.cpp",0x21b);

LAB_14002bfc3:

            FID_conflict__assert(L"0",L"C:\\dev\\tinyxml\\tinyxmlparser.cpp",0x21f);

          }

          else {

            if (*pbVar12 == 0) goto LAB_14002bfc3;

            do {

              if (*pcVar6 == '\0') goto LAB_14002c0b6;

              iVar4 = tolower((int)pcVar6[(longlong)(pbVar12 + -0x14039c7c0)]);

              iVar5 = tolower((int)*pcVar6);

            } while ((iVar4 == iVar5) &&

                    (pcVar6 = pcVar6 + 1, (pbVar12 + -0x14039c7c0)[(longlong)pcVar6] != 0));

            if (*pcVar6 == '\0') {

LAB_14002c0b6:

              local_d0 = -1;

              pbVar9 = (byte *)0x0;

              local_c8 = 0;

              local_d8 = TiXmlAttribute::vftable;

              uStack_b0 = 0;

              local_a8 = uVar14;

              uStack_a0 = uVar15;

              local_b8 = 0;

              uStack_90 = 0;

              local_88 = uVar14;

              uStack_80 = uVar15;

              local_98 = (undefined8 *******)0x0;

              local_c0 = 0;

              local_70 = 0;

              local_78 = 0;

              pbVar8 = (byte *)FUN_140028820(pbVar12,param_4);

              pbVar12 = pbVar9;

              if ((pbVar8 != (byte *)0x0) && (*pbVar8 != 0)) {

                if (param_3 != (longlong *)0x0) {

                  FUN_140028650(param_3,pbVar8,param_4);

                  local_d0 = *param_3;

                }

                pcVar6 = (char *)FUN_140028900(pbVar8,&local_b8);

                if ((pcVar6 == (char *)0x0) || (*pcVar6 == '\0')) {

                  if ((local_c0 != 0) && (*(char *)(local_c0 + 0x68) == '\0')) {

                    *(undefined1 *)(local_c0 + 0x68) = 1;

                    *(undefined4 *)(local_c0 + 0x6c) = 6;

                    lVar7 = -1;

                    do {

                      lVar7 = lVar7 + 1;

                    } while (PTR_s_Error_reading_Attributes__14039a3e0[lVar7] != '\0');

LAB_14002c3ca:

                    lVar7 = local_c0;

                    FUN_140027f50(local_c0 + 0x70);

                    *(undefined8 *)(lVar7 + 0x94) = 0xffffffffffffffff;

LAB_14002c3de:

                    pbVar12 = pbVar9;

                    if (param_3 != (longlong *)0x0) {

                      FUN_140028650(param_3,pbVar8,param_4);

                      *(longlong *)(lVar7 + 0x94) = *param_3;

                    }

                  }

                }

                else {

                  pbVar8 = (byte *)FUN_140028820(pcVar6,param_4);

                  lVar7 = local_c0;

                  if (((pbVar8 == (byte *)0x0) || (*pbVar8 == 0)) || (*pbVar8 != 0x3d)) {

                    if ((local_c0 != 0) && (*(char *)(local_c0 + 0x68) == '\0')) {

                      *(undefined1 *)(local_c0 + 0x68) = 1;

                      *(undefined4 *)(local_c0 + 0x6c) = 6;

                      lVar13 = -1;

                      do {

                        lVar13 = lVar13 + 1;

                      } while (PTR_s_Error_reading_Attributes__14039a3e0[lVar13] != '\0');

                      FUN_140027f50(local_c0 + 0x70);

                      *(undefined8 *)(lVar7 + 0x94) = 0xffffffffffffffff;

joined_r0x00014002c391:

                      if (pbVar8 != (byte *)0x0) goto LAB_14002c3de;

                    }

                  }

                  else {

                    pbVar8 = (byte *)FUN_140028820(pbVar8 + 1,param_4);

                    lVar7 = local_c0;

                    if ((pbVar8 == (byte *)0x0) || (bVar1 = *pbVar8, bVar1 == 0)) {

                      if ((local_c0 != 0) && (*(char *)(local_c0 + 0x68) == '\0')) {

                        *(undefined1 *)(local_c0 + 0x68) = 1;

                        *(undefined4 *)(local_c0 + 0x6c) = 6;

                        lVar13 = -1;

                        do {

                          lVar13 = lVar13 + 1;

                        } while (PTR_s_Error_reading_Attributes__14039a3e0[lVar13] != '\0');

                        FUN_140027f50(local_c0 + 0x70);

                        *(undefined8 *)(lVar7 + 0x94) = 0xffffffffffffffff;

                        goto joined_r0x00014002c391;

                      }

                    }

                    else {

                      if ((bVar1 != 0x27) && (bVar1 != 0x22)) {

                        pppppppuVar10 = &local_98;

                        if (0xf < uStack_80) {

                          pppppppuVar10 = local_98;

                        }

                        local_88 = 0;

                        *(undefined1 *)pppppppuVar10 = 0;

LAB_14002c200:

                        bVar1 = *pbVar8;

                        pbVar12 = pbVar8;

                        if ((((bVar1 != 0) &&

                             (iVar4 = isspace((uint)bVar1), uVar3 = local_88, iVar4 == 0)) &&

                            (bVar1 != 10)) &&

                           (((bVar1 != 0xd && (bVar1 = *pbVar8, bVar1 != 0x2f)) && (bVar1 != 0x3e)))

                           ) {

                          if ((bVar1 != 0x27) && (bVar1 != 0x22)) goto code_r0x00014002c250;

                          pbVar12 = pbVar9;

                          if ((local_c0 != 0) && (*(char *)(local_c0 + 0x68) == '\0')) {

                            *(undefined1 *)(local_c0 + 0x68) = 1;

                            *(undefined4 *)(local_c0 + 0x6c) = 6;

                            lVar7 = -1;

                            do {

                              lVar7 = lVar7 + 1;

                            } while (PTR_s_Error_reading_Attributes__14039a3e0[lVar7] != '\0');

                            goto LAB_14002c3ca;

                          }

                        }

                        goto LAB_14002c3fe;

                      }

                      pbVar12 = (byte *)FUN_140028cc0(pbVar8 + 1,&local_98,0);

                    }

                  }

                }

              }

LAB_14002c3fe:

              pppppppuVar10 = &local_98;

              if (0xf < uStack_80) {

                pppppppuVar10 = local_98;

              }

              lVar7 = -1;

              do {

                lVar7 = lVar7 + 1;

              } while (*(char *)((longlong)pppppppuVar10 + lVar7) != '\0');

              FUN_140027f50(param_1 + 0x11);

              if (0xf < uStack_80) {

                if ((0xfff < uStack_80 + 1) &&

                   ((undefined1 *)0x1f <

                    (undefined1 *)((longlong)local_98 + (-8 - (longlong)local_98[-1]))))

                goto LAB_14002c91b;

                FUN_1402c7088();

              }

              local_88 = uVar14;

              uStack_80 = uVar15;

              local_98 = (undefined8 *******)((ulonglong)local_98 & 0xffffffffffffff00);

              if (0xf < uStack_a0) {

                if ((0xfff < uStack_a0 + 1) && (0x1f < (local_b8 - *(longlong *)(local_b8 - 8)) - 8)

                   ) {

LAB_14002c91b:

                    /* WARNING: Subroutine does not return */

                  _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

                }

                FUN_1402c7088();

              }

              local_b8 = local_b8 & 0xffffffffffffff00;

              local_d8 = TiXmlBase::vftable;

              local_a8 = uVar14;

              uStack_a0 = uVar15;

              goto LAB_14002bf89;

            }

          }

          pcVar6 = "standalone";

          if (pbVar12 == (byte *)0x0) {

            FID_conflict__assert(L"p",L"C:\\dev\\tinyxml\\tinyxmlparser.cpp",0x21b);

          }

          else if (*pbVar12 != 0) {

            do {

              if (*pcVar6 == '\0') goto LAB_14002c508;

              iVar4 = tolower((int)pcVar6[(longlong)(pbVar12 + -0x14039c7d0)]);

              iVar5 = tolower((int)*pcVar6);

            } while ((iVar4 == iVar5) &&

                    (pcVar6 = pcVar6 + 1, pcVar6[(longlong)(pbVar12 + -0x14039c7d0)] != '\0'));

            if (*pcVar6 != '\0') goto LAB_14002c030;

LAB_14002c508:

            pbVar8 = (byte *)0x0;

            uStack_190 = 0;

            local_188 = uVar14;

            uStack_180 = uVar15;

            local_198 = 0;

            uStack_170 = 0;

            local_168 = uVar14;

            uStack_160 = uVar15;

            local_178 = (undefined8 *******)0x0;

            local_150 = 0;

            local_158 = 0;

            pcVar6 = (char *)FUN_140028820(pbVar12,param_4);

            pbVar12 = pbVar8;

            if ((pcVar6 != (char *)0x0) && (*pcVar6 != '\0')) {

              if (param_3 != (longlong *)0x0) {

                FUN_140028650(param_3,pcVar6,param_4);

              }

              pcVar6 = (char *)FUN_140028900(pcVar6,&local_198);

              if (((((pcVar6 != (char *)0x0) && (*pcVar6 != '\0')) &&

                   (pcVar6 = (char *)FUN_140028820(pcVar6,param_4), pcVar6 != (char *)0x0)) &&

                  ((*pcVar6 != '\0' && (*pcVar6 == '=')))) &&

                 ((pbVar9 = (byte *)FUN_140028820(pcVar6 + 1,param_4), pbVar9 != (byte *)0x0 &&

                  (bVar1 = *pbVar9, bVar1 != 0)))) {

                if ((bVar1 == 0x27) || (bVar1 == 0x22)) {

                  pbVar12 = (byte *)FUN_140028cc0(pbVar9 + 1,&local_178,0);

                }

                else {

                  pppppppuVar10 = &local_178;

                  if (0xf < uStack_160) {

                    pppppppuVar10 = local_178;

                  }

                  local_168 = 0;

                  *(undefined1 *)pppppppuVar10 = 0;

                  do {

                    bVar1 = *pbVar9;

                    pbVar12 = pbVar9;

                    if ((((bVar1 == 0) ||

                         (iVar4 = isspace((uint)bVar1), uVar3 = local_168, iVar4 != 0)) ||

                        (bVar1 == 10)) ||

                       (((bVar1 == 0xd || (bVar1 = *pbVar9, bVar1 == 0x2f)) ||

                        ((bVar1 == 0x3e || ((pbVar12 = pbVar8, bVar1 == 0x27 || (bVar1 == 0x22))))))

                       )) break;

                    if (local_168 < uStack_160) {

                      local_168 = local_168 + 1;

                      pppppppuVar10 = &local_178;

                      if (0xf < uStack_160) {

                        pppppppuVar10 = local_178;

                      }

                      *(byte *)(uVar3 + (longlong)pppppppuVar10) = bVar1;

                      *(undefined1 *)(uVar3 + 1 + (longlong)pppppppuVar10) = 0;

                    }

                    else {

                      FUN_1400280d0(&local_178);

                    }

                    pbVar9 = pbVar9 + 1;

                    pbVar12 = pbVar9;

                  } while (pbVar9 != (byte *)0x0);

                }

              }

            }

            pppppppuVar10 = &local_178;

            if (0xf < uStack_160) {

              pppppppuVar10 = local_178;

            }

            lVar7 = -1;

            do {

              lVar7 = lVar7 + 1;

            } while (*(char *)((longlong)pppppppuVar10 + lVar7) != '\0');

            FUN_140027f50(param_1 + 0x15);

            if (0xf < uStack_160) {

              FUN_140028310(&local_178,local_178);

            }

            local_168 = uVar14;

            uStack_160 = uVar15;

            local_178 = (undefined8 *******)((ulonglong)local_178 & 0xffffffffffffff00);

            if (0xf < uStack_180) {

              FUN_140028310(&local_198,local_198);

            }

            local_198 = local_198 & 0xffffffffffffff00;

            local_188 = uVar14;

            uStack_180 = uVar15;

            goto LAB_14002bf89;

          }

          FID_conflict__assert(L"0",L"C:\\dev\\tinyxml\\tinyxmlparser.cpp",0x21f);

          while( true ) {

            if (pbVar12 == (byte *)0x0) {

              return (byte *)0x0;

            }

LAB_14002c030:

            bVar1 = *pbVar12;

            if (bVar1 == 0) goto LAB_14002bae2;

            if ((((bVar1 == 0x3e) || (iVar4 = isspace((uint)bVar1), iVar4 != 0)) || (bVar1 == 10))

               || (bVar1 == 0xd)) break;

            pbVar12 = pbVar12 + 1;

          }

        }

        else {

          if (*pbVar12 == 0) goto LAB_14002bb28;

          do {

            if (*pcVar6 == '\0') goto LAB_14002bba0;

            iVar4 = tolower((int)(char)(pbVar12 + -0x14039c7b8)[(longlong)pcVar6]);

            iVar5 = tolower((int)*pcVar6);

          } while ((iVar4 == iVar5) &&

                  (pcVar6 = pcVar6 + 1, (pbVar12 + -0x14039c7b8)[(longlong)pcVar6] != 0));

          if (*pcVar6 != '\0') goto LAB_14002bf9e;

LAB_14002bba0:

          local_140 = -1;

          pbVar9 = (byte *)0x0;

          local_138 = 0;

          local_148 = TiXmlAttribute::vftable;

          uStack_120 = 0;

          local_118 = uVar14;

          uStack_110 = uVar15;

          local_128 = 0;

          uStack_100 = 0;

          local_f8 = uVar14;

          uStack_f0 = uVar15;

          local_108 = (undefined8 *******)0x0;

          local_130 = 0;

          local_e0 = 0;

          local_e8 = 0;

          pbVar8 = (byte *)FUN_140028820(pbVar12,param_4);

          pbVar12 = pbVar9;

          if ((pbVar8 != (byte *)0x0) && (*pbVar8 != 0)) {

            if (param_3 != (longlong *)0x0) {

              FUN_140028650(param_3,pbVar8,param_4);

              local_140 = *param_3;

            }

            pcVar6 = (char *)FUN_140028900(pbVar8,&local_128);

            if ((pcVar6 == (char *)0x0) || (*pcVar6 == '\0')) {

              if ((local_130 != 0) && (*(char *)(local_130 + 0x68) == '\0')) {

                *(undefined1 *)(local_130 + 0x68) = 1;

                *(undefined4 *)(local_130 + 0x6c) = 6;

                lVar7 = -1;

                do {

                  lVar7 = lVar7 + 1;

                } while (PTR_s_Error_reading_Attributes__14039a3e0[lVar7] != '\0');

LAB_14002be9a:

                lVar7 = local_130;

                FUN_140027f50(local_130 + 0x70);

                *(undefined8 *)(lVar7 + 0x94) = 0xffffffffffffffff;

LAB_14002beae:

                pbVar12 = pbVar9;

                if (param_3 != (longlong *)0x0) {

                  FUN_140028650(param_3,pbVar8,param_4);

                  *(longlong *)(lVar7 + 0x94) = *param_3;

                }

              }

            }

            else {

              pbVar8 = (byte *)FUN_140028820(pcVar6,param_4);

              lVar7 = local_130;

              if (((pbVar8 == (byte *)0x0) || (*pbVar8 == 0)) || (*pbVar8 != 0x3d)) {

                if ((local_130 != 0) && (*(char *)(local_130 + 0x68) == '\0')) {

                  *(undefined1 *)(local_130 + 0x68) = 1;

                  *(undefined4 *)(local_130 + 0x6c) = 6;

                  lVar13 = -1;

                  do {

                    lVar13 = lVar13 + 1;

                  } while (PTR_s_Error_reading_Attributes__14039a3e0[lVar13] != '\0');

                  FUN_140027f50(local_130 + 0x70);

                  *(undefined8 *)(lVar7 + 0x94) = 0xffffffffffffffff;

joined_r0x00014002be61:

                  if (pbVar8 != (byte *)0x0) goto LAB_14002beae;

                }

              }

              else {

                pbVar8 = (byte *)FUN_140028820(pbVar8 + 1,param_4);

                lVar7 = local_130;

                if ((pbVar8 == (byte *)0x0) || (bVar1 = *pbVar8, bVar1 == 0)) {

                  if ((local_130 != 0) && (*(char *)(local_130 + 0x68) == '\0')) {

                    *(undefined1 *)(local_130 + 0x68) = 1;

                    *(undefined4 *)(local_130 + 0x6c) = 6;

                    lVar13 = -1;

                    do {

                      lVar13 = lVar13 + 1;

                    } while (PTR_s_Error_reading_Attributes__14039a3e0[lVar13] != '\0');

                    FUN_140027f50(local_130 + 0x70);

                    *(undefined8 *)(lVar7 + 0x94) = 0xffffffffffffffff;

                    goto joined_r0x00014002be61;

                  }

                }

                else {

                  if ((bVar1 != 0x27) && (bVar1 != 0x22)) {

                    pppppppuVar10 = &local_108;

                    if (0xf < uStack_f0) {

                      pppppppuVar10 = local_108;

                    }

                    local_f8 = 0;

                    *(undefined1 *)pppppppuVar10 = 0;

LAB_14002bcd2:

                    bVar1 = *pbVar8;

                    pbVar12 = pbVar8;

                    if (((((bVar1 != 0) &&

                          (iVar4 = isspace((uint)bVar1), uVar3 = local_f8, iVar4 == 0)) &&

                         (bVar1 != 10)) && ((bVar1 != 0xd && (bVar1 = *pbVar8, bVar1 != 0x2f)))) &&

                       (bVar1 != 0x3e)) {

                      if ((bVar1 != 0x27) && (bVar1 != 0x22)) goto code_r0x00014002bd22;

                      pbVar12 = pbVar9;

                      if ((local_130 != 0) && (*(char *)(local_130 + 0x68) == '\0')) {

                        *(undefined1 *)(local_130 + 0x68) = 1;

                        *(undefined4 *)(local_130 + 0x6c) = 6;

                        lVar7 = -1;

                        do {

                          lVar7 = lVar7 + 1;

                        } while (PTR_s_Error_reading_Attributes__14039a3e0[lVar7] != '\0');

                        goto LAB_14002be9a;

                      }

                    }

                    goto LAB_14002bece;

                  }

                  pbVar12 = (byte *)FUN_140028cc0(pbVar8 + 1,&local_108,0);

                }

              }

            }

          }

LAB_14002bece:

          pppppppuVar10 = &local_108;

          if (0xf < uStack_f0) {

            pppppppuVar10 = local_108;

          }

          lVar7 = -1;

          do {

            lVar7 = lVar7 + 1;

          } while (*(char *)((longlong)pppppppuVar10 + lVar7) != '\0');

          FUN_140027f50(param_1 + 0xd);

          if (0xf < uStack_f0) {

            if ((0xfff < uStack_f0 + 1) &&

               ((undefined1 *)0x1f <

                (undefined1 *)((longlong)local_108 + (-8 - (longlong)local_108[-1]))))

            goto LAB_14002c930;

            FUN_1402c7088();

          }

          local_f8 = uVar14;

          uStack_f0 = uVar15;

          local_108 = (undefined8 *******)((ulonglong)local_108 & 0xffffffffffffff00);

          if (0xf < uStack_110) {

            if ((0xfff < uStack_110 + 1) && (0x1f < (local_128 - *(longlong *)(local_128 - 8)) - 8))

            {

LAB_14002c930:

                    /* WARNING: Subroutine does not return */

              _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

            }

            FUN_1402c7088();

          }

          local_118 = uVar14;

          uStack_110 = uVar15;

          local_128 = local_128 & 0xffffffffffffff00;

          local_148 = TiXmlBase::vftable;

        }

LAB_14002bf89:

        if (pbVar12 == (byte *)0x0) {

          return (byte *)0x0;

        }

      } while( true );

    }

  }

  if ((lVar7 != 0) && (*(char *)(lVar7 + 0x68) == '\0')) {

    *(undefined1 *)(lVar7 + 0x68) = 1;

    *(undefined4 *)(lVar7 + 0x6c) = 0xb;

    lVar13 = -1;

    do {

      lVar13 = lVar13 + 1;

    } while (PTR_s_Error_parsing_Declaration__14039a408[lVar13] != '\0');

    FUN_140027f50(lVar7 + 0x70);

    *(undefined8 *)(lVar7 + 0x94) = 0xffffffffffffffff;

  }

  return (byte *)0x0;

code_r0x00014002bd22:

  if (local_f8 < uStack_f0) {

    local_f8 = local_f8 + 1;

    pppppppuVar10 = &local_108;

    if (0xf < uStack_f0) {

      pppppppuVar10 = local_108;

    }

    *(byte *)((longlong)pppppppuVar10 + uVar3) = bVar1;

    *(undefined1 *)((longlong)pppppppuVar10 + uVar3 + 1) = 0;

  }

  else {

    FUN_1400280d0(&local_108);

  }

  pbVar8 = pbVar8 + 1;

  pbVar12 = pbVar8;

  if (pbVar8 == (byte *)0x0) goto LAB_14002bece;

  goto LAB_14002bcd2;

code_r0x00014002c250:

  if (local_88 < uStack_80) {

    local_88 = local_88 + 1;

    pppppppuVar10 = &local_98;

    if (0xf < uStack_80) {

      pppppppuVar10 = local_98;

    }

    *(byte *)((longlong)pppppppuVar10 + uVar3) = bVar1;

    *(undefined1 *)((longlong)pppppppuVar10 + uVar3 + 1) = 0;

  }

  else {

    FUN_1400280d0(&local_98);

  }

  pbVar8 = pbVar8 + 1;

  pbVar12 = pbVar8;

  if (pbVar8 == (byte *)0x0) goto LAB_14002c3fe;

  goto LAB_14002c200;

}




