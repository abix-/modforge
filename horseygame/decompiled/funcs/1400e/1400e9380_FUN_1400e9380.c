// Address: 0x1400e9380
// Ghidra name: FUN_1400e9380
// ============ 0x1400e9380 FUN_1400e9380 (size=1631) ============


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



longlong FUN_1400e9380(longlong param_1,uint *param_2,int *param_3,undefined4 *param_4,uint param_5)



{

  undefined8 *puVar1;

  longlong *plVar2;

  int *piVar3;

  char cVar4;

  undefined1 *puVar5;

  code *pcVar6;

  bool bVar7;

  int iVar8;

  int iVar9;

  uint uVar10;

  char *_Str1;

  longlong lVar11;

  byte *pbVar12;

  undefined1 uVar13;

  byte bVar14;

  byte bVar15;

  byte *pbVar16;

  ulonglong uVar17;

  undefined1 *puVar18;

  longlong lVar19;

  int iVar20;

  ulonglong uVar21;

  ulonglong *puVar22;

  uint uVar23;

  longlong lVar24;

  ulonglong *puVar25;

  undefined4 local_468;

  uint local_464;

  char *local_460;

  longlong local_458;

  longlong local_450;

  int local_448;

  int local_444;

  int local_440;

  ulonglong local_438;

  undefined1 local_428 [1024];

  

  bVar7 = false;

  _Str1 = (char *)FUN_1400e91d0(param_1,local_428);

  iVar8 = strcmp(_Str1,"#?RADIANCE");

  if (iVar8 != 0) {

    _DAT_1403f4c40 = "not HDR";

    return 0;

  }

  local_460 = (char *)FUN_1400e91d0(param_1,local_428);

  if (*local_460 != '\0') {

    do {

      iVar8 = strcmp(local_460,"FORMAT=32-bit_rle_rgbe");

      if (iVar8 == 0) {

        bVar7 = true;

      }

      local_460 = (char *)FUN_1400e91d0(param_1,local_428);

    } while (*local_460 != '\0');

    if (bVar7) {

      local_460 = (char *)FUN_1400e91d0(param_1,local_428);

      iVar8 = strncmp(local_460,"-Y ",3);

      if (iVar8 == 0) {

        local_460 = local_460 + 3;

        iVar8 = FUN_1402d8a8c(local_460,&local_460,10);

        cVar4 = *local_460;

        while (cVar4 == ' ') {

          local_460 = local_460 + 1;

          cVar4 = *local_460;

        }

        local_444 = iVar8;

        iVar9 = strncmp(local_460,"+X ",3);

        if (iVar9 == 0) {

          local_460 = local_460 + 3;

          local_464 = FUN_1402d8a8c(local_460,0,10);

          *param_2 = local_464;

          *param_3 = iVar8;

          *param_4 = 3;

          uVar17 = 3;

          if (param_5 != 0) {

            uVar17 = (ulonglong)param_5;

          }

          local_438 = uVar17;

          local_450 = _malloc_base((longlong)(int)((int)uVar17 * local_464 * iVar8) << 2);

          if (0x7ff7 < local_464 - 8) {

            iVar9 = 0;

            uVar23 = local_464;

            goto LAB_1400e98d5;

          }

          local_458 = 0;

          local_448 = 0;

          if (0 < iVar8) {

            local_468 = 0;

            local_440 = (int)uVar17 * local_464;

            puVar1 = (undefined8 *)(param_1 + 0xc0);

            plVar2 = (longlong *)(param_1 + 0xb8);

            do {

              lVar11 = local_458;

              pbVar16 = (byte *)*plVar2;

              if (pbVar16 < (byte *)*puVar1) {

                bVar14 = *pbVar16;

                pbVar16 = pbVar16 + 1;

                *plVar2 = (longlong)pbVar16;

              }

              else if (*(int *)(param_1 + 0x30) == 0) {

                bVar14 = 0;

              }

              else {

                FUN_1400ed820(param_1);

                bVar14 = *(byte *)*plVar2;

                pbVar16 = (byte *)*plVar2 + 1;

                *plVar2 = (longlong)pbVar16;

              }

              piVar3 = (int *)(param_1 + 0x30);

              if (pbVar16 < (byte *)*puVar1) {

                bVar15 = *pbVar16;

                pbVar16 = pbVar16 + 1;

                *plVar2 = (longlong)pbVar16;

              }

              else if (*piVar3 == 0) {

                bVar15 = 0;

              }

              else {

                FUN_1400ed820();

                bVar15 = *(byte *)*plVar2;

                pbVar16 = (byte *)*plVar2 + 1;

                *plVar2 = (longlong)pbVar16;

              }

              if (pbVar16 < (byte *)*puVar1) {

                uVar23 = (uint)*pbVar16;

                pbVar16 = pbVar16 + 1;

                *plVar2 = (longlong)pbVar16;

              }

              else if (*piVar3 == 0) {

                uVar23 = 0;

              }

              else {

                FUN_1400ed820();

                uVar23 = (uint)*(byte *)*plVar2;

                pbVar16 = (byte *)*plVar2 + 1;

                *plVar2 = (longlong)pbVar16;

              }

              iVar8 = local_468;

              if (((bVar14 != 2) || (bVar15 != 2)) || ((char)uVar23 < '\0')) {

                local_468._3_1_ = SUB41(iVar8,3);

                local_468._0_3_ = CONCAT12((char)uVar23,CONCAT11(bVar15,bVar14));

                if (pbVar16 < (byte *)*puVar1) {

                  bVar14 = *pbVar16;

                  *plVar2 = (longlong)(pbVar16 + 1);

                }

                else if (*piVar3 == 0) {

                  bVar14 = 0;

                }

                else {

                  FUN_1400ed820(param_1);

                  bVar14 = *(byte *)*plVar2;

                  *plVar2 = (longlong)((byte *)*plVar2 + 1);

                }

                uVar17 = local_438;

                local_468 = CONCAT13(bVar14,(undefined3)local_468);

                FUN_1400e90a0(local_450,&local_468,local_438 & 0xffffffff);

                iVar9 = 0;

                thunk_FUN_1402e9a80(lVar11);

                iVar8 = 1;

                do {

                  puVar25 = (ulonglong *)(param_1 + 0xc0);

                  puVar22 = (ulonglong *)(param_1 + 0xb8);

                  pcVar6 = *(code **)(param_1 + 0x10);

                  if ((pcVar6 == (code *)0x0) ||

                     (iVar20 = *(int *)puVar25 - *(int *)puVar22, 3 < iVar20)) {

                    piVar3 = (int *)*puVar22 + 1;

                    if (piVar3 <= (int *)*puVar25) {

                      local_468 = *(int *)*puVar22;

                      *puVar22 = (ulonglong)piVar3;

                    }

                  }

                  else {

                    FUN_1402f8e20(&local_468,*puVar22,(longlong)iVar20);

                    (*pcVar6)(*(undefined8 *)(param_1 + 0x28),

                              (longlong)&local_468 + (longlong)iVar20,4 - iVar20);

                    *puVar22 = *puVar25;

                    uVar17 = local_438;

                  }

                  FUN_1400e90a0(local_450 +

                                ((longlong)(int)((int)uVar17 * iVar9 * local_464) +

                                (longlong)((int)uVar17 * iVar8)) * 4,&local_468,uVar17 & 0xffffffff)

                  ;

                  iVar8 = iVar8 + 1;

                  uVar23 = local_464;

                  while ((int)uVar23 <= iVar8) {

                    iVar9 = iVar9 + 1;

                    iVar8 = local_444;

LAB_1400e98d5:

                    if (iVar8 <= iVar9) {

                      return local_450;

                    }

                    iVar8 = 0;

                  }

                } while( true );

              }

              if (pbVar16 < (byte *)*puVar1) {

                bVar14 = *pbVar16;

                *plVar2 = (longlong)(pbVar16 + 1);

                uVar10 = (uint)bVar14;

              }

              else if (*piVar3 == 0) {

                uVar10 = 0;

              }

              else {

                FUN_1400ed820(param_1);

                bVar14 = *(byte *)*plVar2;

                *plVar2 = (longlong)((byte *)*plVar2 + 1);

                uVar10 = (uint)bVar14;

              }

              if ((uVar10 | uVar23 << 8) != local_464) {

                thunk_FUN_1402e9a80(local_450);

                thunk_FUN_1402e9a80(lVar11);

                _DAT_1403f4c40 = "invalid decoded scanline length";

                return 0;

              }

              if (local_458 == 0) {

                local_458 = _malloc_base();

              }

              uVar17 = (ulonglong)local_464;

              lVar24 = 0;

              lVar11 = (longlong)(int)local_464;

              do {

                lVar19 = 0;

                if (0 < lVar11) {

                  do {

                    lVar11 = local_458;

                    pbVar16 = (byte *)*plVar2;

                    if (pbVar16 < (byte *)*puVar1) {

LAB_1400e96c9:

                      bVar14 = *pbVar16;

                      uVar21 = (ulonglong)bVar14;

                      pbVar12 = pbVar16 + 1;

                      *plVar2 = (longlong)pbVar12;

                      if (bVar14 < 0x81) {

                        if (bVar14 == 0) goto LAB_1400e9785;

                        puVar18 = (undefined1 *)(lVar24 + lVar19 * 4 + local_458);

                        lVar19 = lVar19 + uVar21;

                        do {

                          puVar5 = (undefined1 *)*plVar2;

                          if (puVar5 < (undefined1 *)*puVar1) {

                            uVar13 = *puVar5;

                            *plVar2 = (longlong)(puVar5 + 1);

                          }

                          else if (*piVar3 == 0) {

                            uVar13 = 0;

                          }

                          else {

                            FUN_1400ed820(param_1);

                            uVar13 = *(undefined1 *)*plVar2;

                            *plVar2 = (longlong)((undefined1 *)*plVar2 + 1);

                          }

                          *puVar18 = uVar13;

                          puVar18 = puVar18 + 4;

                          uVar21 = uVar21 - 1;

                        } while (uVar21 != 0);

                      }

                      else {

                        if (pbVar12 < (byte *)*puVar1) {

                          bVar15 = *pbVar12;

                          *plVar2 = (longlong)(pbVar16 + 2);

                        }

                        else if (*piVar3 == 0) {

                          bVar15 = 0;

                        }

                        else {

                          FUN_1400ed820();

                          bVar15 = *(byte *)*plVar2;

                          *plVar2 = (longlong)((byte *)*plVar2 + 1);

                        }

                        if ((byte)(bVar14 + 0x80) != 0) {

                          uVar17 = (ulonglong)(byte)(bVar14 + 0x80);

                          pbVar16 = (byte *)(lVar24 + lVar19 * 4 + lVar11);

                          lVar19 = lVar19 + uVar17;

                          do {

                            *pbVar16 = bVar15;

                            pbVar16 = pbVar16 + 4;

                            uVar17 = uVar17 - 1;

                          } while (uVar17 != 0);

                        }

                      }

                      uVar17 = (ulonglong)local_464;

                    }

                    else if (*piVar3 != 0) {

                      FUN_1400ed820();

                      pbVar16 = (byte *)*plVar2;

                      uVar17 = (ulonglong)local_464;

                      goto LAB_1400e96c9;

                    }

LAB_1400e9785:

                    lVar11 = (longlong)(int)uVar17;

                  } while (lVar19 < lVar11);

                }

                uVar21 = local_438;

                lVar24 = lVar24 + 1;

              } while (lVar24 < 4);

              if (0 < (int)uVar17) {

                iVar8 = (int)local_438;

                lVar11 = local_450 + (longlong)local_468 * 4;

                lVar24 = local_458;

                do {

                  FUN_1400e90a0(lVar11,lVar24,uVar21 & 0xffffffff);

                  lVar11 = lVar11 + (longlong)iVar8 * 4;

                  lVar24 = lVar24 + 4;

                  uVar17 = uVar17 - 1;

                } while (uVar17 != 0);

              }

              local_448 = local_448 + 1;

              local_468 = local_468 + local_440;

            } while (local_448 < local_444);

          }

          lVar11 = local_450;

          thunk_FUN_1402e9a80(local_458);

          return lVar11;

        }

      }

      _DAT_1403f4c40 = "unsupported data layout";

      return 0;

    }

  }

  _DAT_1403f4c40 = "unsupported format";

  return 0;

}




