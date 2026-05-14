# `FUN_1400cacd0` @ 0x1400cacd0

**Size**: 2454 bytes
**Role**: `float_math_heavy` - Heavy floating-point math (geometry/physics/genetics)  _(evidence: 32 float vars (geometry/physics/genetics?))_
**Pattern category**: `float_math_heavy`

**Strings referenced**:
- `'Plinth'`
- `'PrizePresent'`
- `'SleepMoon'`

**Game callers** (2): [`FUN_14007c970`](14007c970_FUN_14007c970.md), [`FUN_1400cacd0`](1400cacd0_FUN_1400cacd0.md)

**Game callees** (15): [`FUN_140040ca0`](140040ca0_FUN_140040ca0.md), [`FUN_14006fe60`](14006fe60_FUN_14006fe60.md), [`FUN_140071000`](140071000_FUN_140071000.md), [`FUN_140071810`](140071810_FUN_140071810.md), [`FUN_140071d20`](140071d20_FUN_140071d20.md), [`FUN_140071ed0`](140071ed0_FUN_140071ed0.md), [`FUN_1400727d0`](1400727d0_FUN_1400727d0.md), [`FUN_140086570`](140086570_FUN_140086570.md), [`FUN_14008d2c0`](14008d2c0_FUN_14008d2c0.md), [`FUN_14009e2c0`](14009e2c0_FUN_14009e2c0.md)
  ... +5 more

**Vendor callees**: 0 (SDL/CRT/etc, not shown)

## Decompiled

```c
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1400cacd0(longlong *param_1,char param_2,char param_3)

{

  int *piVar1;

  float fVar2;

  uint uVar3;

  float fVar4;

  float fVar5;

  float fVar6;

  float fVar7;

  float fVar8;

  undefined4 uVar9;

  void *pvVar10;

  char cVar11;

  longlong lVar12;

  undefined1 uVar13;

  int iVar14;

  int iVar15;

  undefined *puVar16;

  undefined8 *puVar17;

  longlong lVar18;

  ulonglong uVar19;

  longlong lVar20;

  longlong lVar21;

  float fVar22;

  ulonglong in_stack_fffffffffffffee8;

  undefined8 uVar23;

  undefined4 uVar24;

  undefined8 local_f8;

  ulonglong uStack_f0;

  undefined8 local_e8;

  ulonglong uStack_e0;

  fVar8 = DAT_14039ca34;

  uVar19 = (ulonglong)_tls_index;

  if (0 < (int)param_1[0x36]) {

    lVar21 = *(longlong *)((longlong)ThreadLocalStoragePointer + uVar19 * 8);

    if ((*(int *)(lVar21 + 4) < DAT_1403f35b4) &&

       (FUN_1402c7138(&DAT_1403f35b4), DAT_1403f35b4 == -1)) {

      uStack_f0 = 0;

      local_e8 = 6;

      uStack_e0 = 0xf;

      local_f8 = (ulonglong)CONCAT24(s_Plinth_140305f24._4_2_,s_Plinth_140305f24._0_4_);

      DAT_1403f35b0 = FUN_14006fe60(&local_f8);

      _Init_thread_footer(&DAT_1403f35b4);

    }

    if ((*(int *)(lVar21 + 4) < DAT_1403f35bc) &&

       (FUN_1402c7138(&DAT_1403f35bc), DAT_1403f35bc == -1)) {

      local_e8 = 0xc;

      uStack_e0 = 0xf;

      local_f8._0_1_ = s_PrizePresent_140307a00[0];

      local_f8._1_1_ = s_PrizePresent_140307a00[1];

      local_f8._2_1_ = s_PrizePresent_140307a00[2];

      local_f8._3_1_ = s_PrizePresent_140307a00[3];

      local_f8._4_1_ = s_PrizePresent_140307a00[4];

      local_f8._5_1_ = s_PrizePresent_140307a00[5];

      local_f8._6_1_ = s_PrizePresent_140307a00[6];

      local_f8._7_1_ = s_PrizePresent_140307a00[7];

      uStack_f0 = (ulonglong)(uint)s_PrizePresent_140307a00._8_4_;

      _DAT_1403f35b8 = FUN_14006fe60(&local_f8);

      _Init_thread_footer(&DAT_1403f35bc);

    }

    lVar21 = param_1[0xc];

    FUN_140071d20(DAT_1403f35b0,*(float *)(lVar21 + 0x2ac) * fVar8 + *(float *)(lVar21 + 0x2a4),

                  *(float *)(lVar21 + 0x2b0) + *(float *)(lVar21 + 0x2a8));

    if ((int)param_1[0x36] == 1) {

      if (((int)param_1[0x1b] == 6) || (*(int *)((longlong)param_1 + 0x1b4) % 0x3c < 0x1e)) {

        iVar14 = 1;

      }

      else {

        iVar14 = 0;

      }

      FUN_140071d20(iVar14 + _DAT_1403f35b8,

                    *(float *)(lVar21 + 0x2ac) * fVar8 + *(float *)(lVar21 + 0x2a4),

                    *(float *)(lVar21 + 0x2b0) * fVar8 + *(float *)(lVar21 + 0x2a8));

    }

  }

  pvVar10 = ThreadLocalStoragePointer;

  uVar9 = DAT_14039ca44;

  fVar7 = DAT_14030eb94;

  fVar6 = DAT_140303750;

  fVar5 = DAT_140303390;

  fVar4 = DAT_14030338c;

  iVar14 = 0;

  lVar21 = param_1[0xc];

  if ((param_1[0xd] - lVar21) / 0x68 != 0) {

    lVar20 = 0;

    fVar22 = DAT_14030374c;

    do {

      iVar15 = *(int *)(lVar21 + lVar20);

      if (((iVar15 != -1) && (*(char *)(lVar21 + 0x5d + lVar20) != '\0')) &&

         ((iVar15 != 0 || (DAT_1403d95c4 == '\0')))) {

        piVar1 = (int *)(lVar21 + 0x60 + lVar20);

        *piVar1 = *piVar1 + 1;

        if ((*(byte *)(lVar21 + 0x30 + lVar20) & 1) == 0) {

          if ((((int)param_1[0x1b] == iVar14) && ((int)param_1[0x2d] == -1)) &&

             (*(int *)((longlong)param_1 + 0xd4) == -1)) {

            lVar12 = (longlong)*(int *)(lVar21 + 0x54 + lVar20);

            lVar18 = lVar12 * 4 + 2;

          }

          else {

            lVar12 = (longlong)*(int *)(lVar21 + 0x54 + lVar20);

            lVar18 = lVar12 * 4 + 1;

          }

          uVar23 = CONCAT44((int)(in_stack_fffffffffffffee8 >> 0x20),

                            *(undefined4 *)(&DAT_1403da890 + (lVar18 + lVar12) * 4));

          FUN_140071000(*(undefined4 *)(lVar21 + 0x34 + lVar20),iVar15,&DAT_1403da890,

                        *(undefined4 *)(lVar21 + 0x40 + lVar20),uVar23);

          uVar24 = (undefined4)((ulonglong)uVar23 >> 0x20);

          if ((*(byte *)(lVar21 + 0x30 + lVar20) & 0x40) != 0) {

            FUN_140071810();

            fVar22 = DAT_14030374c;

          }

          if ((*(byte *)(lVar21 + 0x30 + lVar20) & 0x80) != 0) {

            FUN_140071810();

          }

          if (*(int *)(lVar21 + 0x54 + lVar20) == 5) {

            FUN_140071000(*(float *)(lVar21 + 0x34 + lVar20) + fVar6,

                          *(float *)(lVar21 + 0x40 + lVar20) + *(float *)(lVar21 + 0x38 + lVar20));

            FUN_140071000((*(float *)(lVar21 + 0x34 + lVar20) + *(float *)(lVar21 + 0x3c + lVar20))

                          - DAT_1403033a4,

                          *(float *)(lVar21 + 0x40 + lVar20) + *(float *)(lVar21 + 0x38 + lVar20));

          }

          puVar16 = &DAT_1403da89c;

          if (*(int *)((longlong)param_1 + 0xdc) != iVar14) {

            puVar16 = &DAT_1403da8a0;

          }

          in_stack_fffffffffffffee8 =

               CONCAT44(uVar24,*(undefined4 *)

                                (puVar16 + (longlong)*(int *)(lVar21 + 0x54 + lVar20) * 0x14));

          FUN_140071000(*(float *)(lVar21 + 0x34 + lVar20) + fVar22,

                        *(float *)(lVar21 + 0x38 + lVar20) + fVar22,

                        *(float *)(lVar21 + 0x3c + lVar20) - fVar5,

                        *(float *)(lVar21 + 0x40 + lVar20) - fVar5,in_stack_fffffffffffffee8);

          uVar3 = *(uint *)(lVar21 + 0x30 + lVar20);

          if ((uVar3 & 2) == 0) {

            if (*(int *)(lVar21 + 0x2c + lVar20) != -1) {

              FUN_1400727d0();

              if (((*(uint *)(lVar21 + 0x30 + lVar20) & 0x800) == 0) ||

                 (*(int *)((longlong)param_1 + 0xdc) != iVar14)) {

                iVar15 = 0;

              }

              else {

                iVar15 = 1;

              }

              in_stack_fffffffffffffee8 = in_stack_fffffffffffffee8 & 0xffffffff00000000;

              FUN_140071ed0(iVar15 + *(int *)(lVar21 + 0x2c + lVar20),

                            *(float *)(lVar21 + 0x3c + lVar20) * fVar8 +

                            *(float *)(lVar21 + 0x34 + lVar20),

                            *(float *)(lVar21 + 0x40 + lVar20) * fVar8 +

                            *(float *)(lVar21 + 0x38 + lVar20),

                            *(undefined4 *)(lVar21 + 0x50 + lVar20),in_stack_fffffffffffffee8);

            }

          }

          else {

            uVar24 = (undefined4)(in_stack_fffffffffffffee8 >> 0x20);

            if ((uVar3 >> 9 & 1) == 0) {

              puVar16 = &DAT_1403da8a0;

              if (*(int *)((longlong)param_1 + 0xdc) != iVar14) {

                puVar16 = &DAT_1403da89c;

              }

              puVar17 = (undefined8 *)(lVar20 + 8 + lVar21);

              if (0xf < *(ulonglong *)(lVar21 + 0x20 + lVar20)) {

                puVar17 = (undefined8 *)*puVar17;

              }

              in_stack_fffffffffffffee8 = CONCAT44(uVar24,uVar9);

              FUN_140086570(DAT_1403ede18,

                            *(float *)(lVar21 + 0x44 + lVar20) + *(float *)(lVar21 + 0x34 + lVar20),

                            *(float *)(lVar21 + 0x48 + lVar20) + *(float *)(lVar21 + 0x38 + lVar20),

                            0,in_stack_fffffffffffffee8,

                            *(undefined4 *)

                             (puVar16 + (longlong)*(int *)(lVar21 + 0x54 + lVar20) * 0x14),puVar17);

            }

            else {

              fVar2 = *(float *)(lVar21 + 0x50 + lVar20);

              puVar17 = (undefined8 *)(lVar20 + 8 + lVar21);

              if (0xf < *(ulonglong *)(lVar21 + 0x20 + lVar20)) {

                puVar17 = (undefined8 *)*puVar17;

              }

              in_stack_fffffffffffffee8 = CONCAT44(uVar24,fVar2);

              FUN_14009e2c0(DAT_1403ede10,

                            *(float *)(lVar21 + 0x3c + lVar20) * fVar8 +

                            *(float *)(lVar21 + 0x34 + lVar20),

                            (float)(*(int *)(lVar21 + 0x58 + lVar20) * -0x19 + 0x28) * fVar2 +

                            *(float *)(lVar21 + 0x40 + lVar20) * fVar8 +

                            *(float *)(lVar21 + 0x38 + lVar20),2,in_stack_fffffffffffffee8,

                            *(undefined4 *)

                             (&DAT_1403da89c + (longlong)*(int *)(lVar21 + 0x54 + lVar20) * 0x14),

                            puVar17);

            }

          }

          if (iVar14 == 2) {

            if ((*(int *)(*(longlong *)((longlong)pvVar10 + uVar19 * 8) + 4) < DAT_1403f35c4) &&

               (FUN_1402c7138(&DAT_1403f35c4), DAT_1403f35c4 == -1)) {

              local_e8 = 9;

              uStack_e0 = 0xf;

              local_f8._0_1_ = s_SleepMoon_14030e7d0[0];

              local_f8._1_1_ = s_SleepMoon_14030e7d0[1];

              local_f8._2_1_ = s_SleepMoon_14030e7d0[2];

              local_f8._3_1_ = s_SleepMoon_14030e7d0[3];

              local_f8._4_1_ = s_SleepMoon_14030e7d0[4];

              local_f8._5_1_ = s_SleepMoon_14030e7d0[5];

              local_f8._6_1_ = s_SleepMoon_14030e7d0[6];

              local_f8._7_1_ = s_SleepMoon_14030e7d0[7];

              uStack_f0 = (ulonglong)(byte)s_SleepMoon_14030e7d0[8];

              DAT_1403f35c0 = FUN_14006fe60(&local_f8);

              _Init_thread_footer(&DAT_1403f35c4);

            }

            FUN_140071d20(DAT_1403f35c0,*(float *)(lVar21 + 0x34 + lVar20) + fVar7,

                          *(float *)(lVar21 + 0x38 + lVar20) + fVar4);

          }

        }

        else {

          (**(code **)(*param_1 + 0x50))(param_1);

        }

      }

      iVar14 = iVar14 + 1;

      lVar20 = lVar20 + 0x68;

      lVar21 = param_1[0xc];

    } while ((ulonglong)(longlong)iVar14 < (ulonglong)((param_1[0xd] - lVar21) / 0x68));

  }

  FUN_1400727d0();

  if ((param_2 != '\0') && (DAT_1403d95c4 == '\0')) {

    FUN_14010f7e0(DAT_1403fb0d8);

  }

  if (param_3 != '\0') {

    if (((DAT_1403ed732 == '\0') && (DAT_1403ed736 == '\0')) ||

       (cVar11 = FUN_14008d2c0(), cVar11 != '\0')) {

      if (*(int *)((longlong)param_1 + 0x16c) != -1) {

        FUN_1400d52c0(param_1);

      }

    }

    else {

      iVar14 = 0;

      if (param_1[0x27] - param_1[0x26] >> 3 != 0) {

        do {

          FUN_1400d52c0(param_1,iVar14);

          iVar14 = iVar14 + 1;

        } while ((ulonglong)(longlong)iVar14 < (ulonglong)(param_1[0x27] - param_1[0x26] >> 3));

      }

    }

  }

  if ((int)param_1[0x34] != -1) {

    FUN_140071d20();

    if (DAT_14030ad5c < *(float *)(param_1 + 0x35) || DAT_14030ad5c == *(float *)(param_1 + 0x35)) {

      if (((int)param_1[0x36] != 2) || (299 < *(int *)((longlong)param_1 + 0x1b4))) {

        if (*(int *)((longlong)param_1 + 0x1b4) == 0x12d) {

          uStack_f0 = 0;

          local_e8 = _DAT_140304080;

          uStack_e0 = _UNK_140304088;

          local_f8 = (ulonglong)CONCAT14(DAT_1403078f0,DAT_1403078ec);

          FUN_140040ca0(&local_f8,0x32,0,uVar9,in_stack_fffffffffffffee8 & 0xffffffffffffff00);

          if (0xf < uStack_e0) {

            if ((0xfff < uStack_e0 + 1) && (0x1f < (local_f8 - *(longlong *)(local_f8 - 8)) - 8)) {

                    /* WARNING: Subroutine does not return */

              _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

            }

            FUN_1402c7088();

          }

        }

        *(float *)(param_1 + 0x35) = *(float *)(param_1 + 0x35) - fVar5;

      }

    }

    else {

      *(undefined4 *)(param_1 + 0x34) = 0xffffffff;

    }

  }

  *(char *)(param_1[0xc] + 0x1fd) = param_3;

  if ((((param_3 == '\0') || (*(int *)((longlong)param_1 + 0x16c) == -1)) ||

      ((lVar21 = *(longlong *)(param_1[0x26] + (longlong)*(int *)((longlong)param_1 + 0x16c) * 8),

       *(char *)(lVar21 + 0x204) == '\0' && (*(int *)(lVar21 + 0x1c) != 3)))) ||

     (cVar11 = FUN_14008d2c0(), cVar11 != '\0')) {

    uVar13 = 0;

  }

  else {

    uVar13 = 1;

  }

  *(undefined1 *)(param_1[0xc] + 0x265) = uVar13;

  return;

}
```