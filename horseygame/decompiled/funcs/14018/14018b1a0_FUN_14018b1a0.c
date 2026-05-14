// Address: 0x14018b1a0
// Ghidra name: FUN_14018b1a0
// ============ 0x14018b1a0 FUN_14018b1a0 (size=985) ============


undefined8 FUN_14018b1a0(float *param_1,float *param_2,int param_3,uint param_4,float param_5)



{

  byte bVar1;

  short sVar2;

  float fVar3;

  float fVar4;

  uint uVar5;

  undefined8 uVar6;

  ushort uVar7;

  longlong lVar8;

  undefined1 uVar9;

  undefined2 uVar10;

  int iVar11;

  uint uVar12;

  int iVar13;

  float extraout_XMM0_Da;

  float fVar14;

  float fVar15;

  

  thunk_FUN_1402e1d00(param_5 * DAT_140304c28);

  fVar4 = DAT_14039ca80;

  fVar3 = DAT_14039ca44;

  iVar13 = (int)extraout_XMM0_Da;

  if (iVar13 != 0) {

    if (param_3 < 0x8121) {

      if (param_3 == 0x8120) {

        param_4 = param_4 >> 2;

        while (param_4 != 0) {

          param_4 = param_4 - 1;

          fVar15 = *param_2;

          param_2 = param_2 + 1;

          fVar14 = param_5 * fVar15 + *param_1;

          fVar15 = fVar3;

          if ((fVar14 <= fVar3) && (fVar15 = fVar4, fVar4 <= fVar14)) {

            fVar15 = fVar14;

          }

          *param_1 = fVar15;

          param_1 = param_1 + 1;

        }

      }

      else if (param_3 == 8) {

        for (; param_4 != 0; param_4 = param_4 - 1) {

          bVar1 = *(byte *)param_2;

          param_2 = (float *)((longlong)param_2 + 1);

          iVar11 = (bVar1 - 0x80) * iVar13;

          *(undefined *)param_1 =

               (&DAT_1403399a0)

               [(ulonglong)(byte)((char)((int)(iVar11 + (iVar11 >> 0x1f & 0x7fU)) >> 7) + 0x80) +

                (ulonglong)*(byte *)param_1];

          param_1 = (float *)((longlong)param_1 + 1);

        }

      }

      else if (param_3 == 0x8008) {

        if (param_4 != 0) {

          lVar8 = (longlong)param_2 - (longlong)param_1;

          do {

            param_4 = param_4 - 1;

            iVar11 = *(char *)(lVar8 + (longlong)param_1) * iVar13;

            if (iVar11 < 0) {

              iVar11 = iVar11 + 0x7f;

            }

            iVar11 = (int)(char)(iVar11 >> 7) + (int)*(char *)param_1;

            if (iVar11 < 0x80) {

              uVar9 = (undefined1)iVar11;

              if (iVar11 < -0x80) {

                uVar9 = 0x80;

              }

            }

            else {

              uVar9 = 0x7f;

            }

            *(undefined1 *)param_1 = uVar9;

            param_1 = (float *)((longlong)param_1 + 1);

          } while (param_4 != 0);

        }

      }

      else if (param_3 == 0x8010) {

        param_4 = param_4 >> 1;

        while (param_4 != 0) {

          sVar2 = *(short *)param_2;

          param_2 = (float *)((longlong)param_2 + 2);

          param_4 = param_4 - 1;

          iVar11 = (int)*(short *)param_1 +

                   (int)(short)((int)(sVar2 * iVar13 + (sVar2 * iVar13 >> 0x1f & 0x7fU)) >> 7);

          if (iVar11 < 0x8000) {

            uVar10 = (undefined2)iVar11;

            if (iVar11 < -0x8000) {

              uVar10 = 0x8000;

            }

          }

          else {

            uVar10 = 0x7fff;

          }

          *(undefined2 *)param_1 = uVar10;

          param_1 = (float *)((longlong)param_1 + 2);

        }

      }

      else {

        if (param_3 != 0x8020) goto LAB_14018b400;

        uVar12 = param_4 >> 2;

        if (param_4 >> 2 != 0) {

          do {

            fVar3 = *param_2;

            param_2 = param_2 + 1;

            uVar12 = uVar12 - 1;

            lVar8 = (longlong)iVar13 * (longlong)(int)fVar3;

            if (lVar8 < 0) {

              lVar8 = lVar8 + 0x7f;

            }

            lVar8 = (longlong)(int)*param_1 + (lVar8 >> 7);

            if (lVar8 < 0x80000000) {

              if (lVar8 < -0x80000000) {

                lVar8 = -0x80000000;

              }

            }

            else {

              lVar8 = 0x7fffffff;

            }

            *param_1 = (float)lVar8;

            param_1 = param_1 + 1;

          } while (uVar12 != 0);

        }

      }

    }

    else if (param_3 == 0x9010) {

      param_4 = param_4 >> 1;

      while (param_4 != 0) {

        uVar7 = *(ushort *)param_2;

        param_2 = (float *)((longlong)param_2 + 2);

        param_4 = param_4 - 1;

        iVar11 = (short)(uVar7 >> 8 | uVar7 << 8) * iVar13;

        iVar11 = (int)(short)(*(ushort *)param_1 >> 8 | *(ushort *)param_1 << 8) +

                 (int)(short)((int)(iVar11 + (iVar11 >> 0x1f & 0x7fU)) >> 7);

        if (iVar11 < 0x8000) {

          uVar7 = (ushort)iVar11;

          if (iVar11 < -0x8000) {

            uVar7 = 0x8000;

          }

        }

        else {

          uVar7 = 0x7fff;

        }

        *(ushort *)param_1 = uVar7 >> 8 | uVar7 << 8;

        param_1 = (float *)((longlong)param_1 + 2);

      }

    }

    else if (param_3 == 0x9020) {

      uVar12 = param_4 >> 2;

      if (param_4 >> 2 != 0) {

        do {

          fVar3 = *param_2;

          param_2 = param_2 + 1;

          uVar12 = uVar12 - 1;

          fVar4 = *param_1;

          lVar8 = (longlong)

                  (int)((uint)fVar3 >> 0x18 | ((uint)fVar3 & 0xff0000) >> 8 |

                        ((uint)fVar3 & 0xff00) << 8 | (int)fVar3 << 0x18) * (longlong)iVar13;

          if (lVar8 < 0) {

            lVar8 = lVar8 + 0x7f;

          }

          lVar8 = (longlong)

                  (int)((uint)fVar4 >> 0x18 | ((uint)fVar4 & 0xff0000) >> 8 |

                        ((uint)fVar4 & 0xff00) << 8 | (int)fVar4 << 0x18) + (lVar8 >> 7);

          if (lVar8 < 0x80000000) {

            if (lVar8 < -0x80000000) {

              lVar8 = -0x80000000;

            }

          }

          else {

            lVar8 = 0x7fffffff;

          }

          uVar5 = (uint)lVar8;

          *param_1 = (float)(uVar5 >> 0x18 | (uVar5 & 0xff0000) >> 8 | (uVar5 & 0xff00) << 8 |

                            uVar5 << 0x18);

          param_1 = param_1 + 1;

        } while (uVar12 != 0);

      }

    }

    else {

      if (param_3 != 0x9120) {

LAB_14018b400:

        uVar6 = FUN_14012e850("SDL_MixAudio(): unknown audio format");

        return uVar6;

      }

      param_4 = param_4 >> 2;

      while (param_4 != 0) {

        fVar15 = *param_2;

        param_4 = param_4 - 1;

        param_2 = param_2 + 1;

        fVar14 = *param_1;

        fVar14 = (float)((uint)fVar15 >> 0x18 | ((uint)fVar15 & 0xff0000) >> 8 |

                         ((uint)fVar15 & 0xff00) << 8 | (int)fVar15 << 0x18) * param_5 +

                 (float)((uint)fVar14 >> 0x18 | ((uint)fVar14 & 0xff0000) >> 8 |

                         ((uint)fVar14 & 0xff00) << 8 | (int)fVar14 << 0x18);

        fVar15 = fVar3;

        if ((fVar14 <= fVar3) && (fVar15 = fVar4, fVar4 <= fVar14)) {

          fVar15 = fVar14;

        }

        *param_1 = (float)((uint)fVar15 >> 0x18 | ((uint)fVar15 & 0xff0000) >> 8 |

                           ((uint)fVar15 & 0xff00) << 8 | (int)fVar15 << 0x18);

        param_1 = param_1 + 1;

      }

    }

  }

  return 1;

}




