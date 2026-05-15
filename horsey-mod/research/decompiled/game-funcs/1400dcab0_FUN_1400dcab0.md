# `FUN_1400dcab0` @ 0x1400dcab0

**Size**: 4986 bytes
**Role**: `age_too_old_check` (string-anchored)
**Domain**: `aging` - aging / retirement / lifecycle
**Pattern**: `struct_init` - Zero-initializes consecutive struct fields (constructor-like)
**Evidence**: zero-inits 7 fields

**Strings referenced**:
- `'Including the %s'`
- `', and the %s'`
- `'%s = (%d rand + %d nice + %d record) * %d years + %d deco   gdist=%.3f'`
- `'You can have %s for %d bottle%s of Hot Sauce'`
- `'What a nice horse! %s is worth $%d to me!'`
- `'%s is getting old. I can only offer you $%d'`
- `'I have too many horses!! I can only do $%d for %s'`
- `'I lost my horse'`
- `'That horse is too old'`
- `'Why that horse is deceased'`
- `'I don t want your silly horses'`
- `'I m sorry I was ever mean to you'`
- `'You re my best friend now'`
- `'Let me take a closer look at tha'`
- `'I say there partner  that horse l'`
- `'Matter of fact I reckon it s don'`
- `'up to horse heaven  if you catch'`

**Game callers** (1): [`FUN_1400dcab0`](1400dcab0_FUN_1400dcab0.md)

**Game callees** (20): [`FUN_140027810`](140027810_FUN_140027810.md), [`FUN_1400285e0`](1400285e0_FUN_1400285e0.md), [`FUN_14005e230`](14005e230_FUN_14005e230.md), [`FUN_14005e270`](14005e270_FUN_14005e270.md), [`FUN_14008d760`](14008d760_FUN_14008d760.md), [`FUN_1400a3200`](1400a3200_FUN_1400a3200.md), [`FUN_1400b5f80`](1400b5f80_FUN_1400b5f80.md), [`FUN_1400c4320`](1400c4320_FUN_1400c4320.md), [`FUN_1400c5f50`](1400c5f50_FUN_1400c5f50.md), [`FUN_1400c6180`](1400c6180_FUN_1400c6180.md)
  ... +10 more

**Vendor callees**: 0 (SDL/CRT/etc, not shown)

## Decompiled

```c
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1400dcab0(longlong param_1,int param_2)

{

  longlong lVar1;

  bool bVar2;

  bool bVar3;

  bool bVar4;

  undefined4 uVar5;

  undefined4 uVar6;

  undefined4 uVar7;

  char cVar8;

  int iVar9;

  int iVar10;

  longlong lVar11;

  longlong *plVar12;

  undefined8 *puVar13;

  undefined8 uVar14;

  undefined8 uVar15;

  uint unaff_EDI;

  int *piVar16;

  ulonglong uVar17;

  longlong lVar18;

  char *pcVar19;

  int *piVar20;

  undefined *puVar21;

  int iVar22;

  float fVar23;

  float fVar24;

  undefined4 uVar25;

  int local_res8;

  int local_res20;

  undefined8 in_stack_ffffffffffffff08;

  undefined4 uVar27;

  undefined8 uVar26;

  undefined8 in_stack_ffffffffffffff10;

  char *local_d8;

  undefined8 uStack_d0;

  undefined8 local_c8;

  ulonglong uStack_c0;

  uint local_b8;

  int local_b4;

  int local_b0;

  int local_ac;

  int local_a8;

  longlong local_a0;

  longlong lStack_98;

  longlong local_90;

  ulonglong uStack_88;

  ulonglong local_80;

  char *local_78;

  undefined8 uStack_70;

  undefined8 local_68;

  ulonglong uStack_60;

  lVar1 = *(longlong *)(*(longlong *)(param_1 + 0x130) + (longlong)param_2 * 8);

  iVar22 = 0;

  if (*(int *)(param_1 + 0x250) == 1) {

    if (*(longlong *)(param_1 + 0x440) == lVar1) {

      *(undefined8 *)(param_1 + 0x440) = 0;

    }

    if (*(longlong *)(param_1 + 0x448) == lVar1) {

      *(undefined8 *)(param_1 + 0x448) = 0;

    }

  }

  if (*(int *)(param_1 + 600) == 0) {

    return;

  }

  if (lVar1 == *(longlong *)(param_1 + 0x148)) {

    return;

  }

  cVar8 = FUN_1400d0c50();

  if (cVar8 == '\0') {

    return;

  }

  local_a8 = *(int *)(lVar1 + 0x1fc) + 1;

  if (*(char *)(lVar1 + 0x206) == '\0') {

    local_a8 = *(int *)(lVar1 + 0x1fc);

  }

  local_ac = *(int *)(lVar1 + 0x200);

  local_b4 = FUN_1400c5f50(local_ac - local_a8,0,0xb);

  bVar4 = false;

  local_b8 = unaff_EDI & 0xffffff00;

  uVar17 = *(longlong *)(*(longlong *)(param_1 + 0x148) + 0x2a8) + *(longlong *)(lVar1 + 0x2a8);

  local_80 = (ulonglong)((int)uVar17 + (int)(uVar17 / 0xb) * -0xb + 5);

  local_res20 = 0;

  local_res8 = 0;

  lStack_98 = 0;

  local_90 = 0;

  uStack_88 = 0xf;

  local_a0 = 0;

  fVar23 = (float)FUN_1400a3200(param_1 + 0x25c,lVar1 + 0x2b8);

  if ((fVar23 < DAT_14039ca24) && (*(int *)(param_1 + 600) != 6)) {

    in_stack_ffffffffffffff08 =

         CONCAT44((int)((ulonglong)in_stack_ffffffffffffff08 >> 0x20),DAT_140303754);

    fVar24 = (float)FUN_1400c6180();

    local_res20 = (int)fVar24;

    bVar4 = true;

    local_b8 = (uint)(fVar23 < DAT_14039ca0c);

  }

  lVar11 = FUN_1400c7520(*(undefined4 *)(lVar1 + 0x1f8));

  if (*(char *)(lVar11 + 0x58) == '\0') {

    lVar11 = FUN_1400c7520(*(undefined4 *)(lVar1 + 0x1f8));

    local_b0 = 3;

    if (*(int *)(lVar11 + 0x54) < 3) {

      local_b0 = *(int *)(lVar11 + 0x54);

    }

    local_b0 = local_b0 * 0x32;

  }

  else {

    local_b0 = 0x96;

  }

  lVar11 = 1;

  piVar16 = (int *)(lVar1 + 0xcc);

  do {

    iVar10 = *piVar16;

    if (iVar10 != -1) {

      iVar9 = FUN_14005e230();

      local_res8 = local_res8 + iVar9 / 2;

      if (local_90 == 0) {

        FUN_14005e270(iVar10);

        plVar12 = (longlong *)FUN_14008d760(&local_d8,"Including the %s");

        if (&local_a0 != plVar12) {

          if (0xf < uStack_88) {

            if ((0xfff < uStack_88 + 1) && (0x1f < (local_a0 - *(longlong *)(local_a0 + -8)) - 8U))

            goto LAB_1400ddcfb;

            FUN_1402c7088();

          }

          local_a0 = *plVar12;

          lStack_98 = plVar12[1];

          local_90 = plVar12[2];

          uStack_88 = plVar12[3];

          plVar12[2] = 0;

          plVar12[3] = 0xf;

          *(undefined1 *)plVar12 = 0;

        }

        if (0xf < uStack_c0) {

          if ((0xfff < uStack_c0 + 1) &&

             ((char *)0x1f < local_d8 + (-8 - *(longlong *)(local_d8 + -8)))) {

LAB_1400ddcfb:

                    /* WARNING: Subroutine does not return */

            _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

          }

LAB_1400dceb6:

          FUN_1402c7088();

        }

      }

      else {

        if (lVar11 < 0x15) {

          lVar18 = 0x15 - lVar11;

          piVar20 = piVar16;

          bVar3 = true;

          do {

            piVar20 = piVar20 + 1;

            bVar2 = false;

            if (*piVar20 == -1) {

              bVar2 = bVar3;

            }

            lVar18 = lVar18 + -1;

            bVar3 = bVar2;

          } while (lVar18 != 0);

          if (!bVar2) {

            puVar13 = (undefined8 *)FUN_14005e270(iVar10);

            if (0xf < (ulonglong)puVar13[3]) {

              puVar13 = (undefined8 *)*puVar13;

            }

            puVar13 = (undefined8 *)FUN_14008d760(&local_d8,&DAT_14030f238,puVar13);

            if (0xf < (ulonglong)puVar13[3]) {

              puVar13 = (undefined8 *)*puVar13;

            }

            FUN_140027810(&local_a0,puVar13);

            if (0xf < uStack_c0) {

              if ((0xfff < uStack_c0 + 1) &&

                 ((char *)0x1f < local_d8 + (-8 - *(longlong *)(local_d8 + -8)))) {

                    /* WARNING: Subroutine does not return */

                _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

              }

              goto LAB_1400dceb6;

            }

            goto LAB_1400dcebb;

          }

        }

        puVar13 = (undefined8 *)FUN_14005e270(iVar10);

        if (0xf < (ulonglong)puVar13[3]) {

          puVar13 = (undefined8 *)*puVar13;

        }

        puVar13 = (undefined8 *)FUN_14008d760(&local_78,", and the %s",puVar13);

        if (0xf < (ulonglong)puVar13[3]) {

          puVar13 = (undefined8 *)*puVar13;

        }

        FUN_140027810(&local_a0,puVar13);

        if (0xf < uStack_60) {

          if ((0xfff < uStack_60 + 1) &&

             ((char *)0x1f < local_78 + (-8 - *(longlong *)(local_78 + -8)))) {

                    /* WARNING: Subroutine does not return */

            _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

          }

          goto LAB_1400dceb6;

        }

      }

    }

LAB_1400dcebb:

    iVar10 = local_b0;

    uVar27 = (undefined4)((ulonglong)in_stack_ffffffffffffff08 >> 0x20);

    uVar25 = (undefined4)((ulonglong)in_stack_ffffffffffffff10 >> 0x20);

    iVar22 = iVar22 + 1;

    piVar16 = piVar16 + 1;

    lVar11 = lVar11 + 1;

  } while (iVar22 < 0x15);

  piVar16 = (int *)(param_1 + 0x450);

  iVar22 = local_res8 + 5 + (local_res20 + local_b0 + (int)local_80) * local_b4;

  *piVar16 = iVar22;

  if (*(char *)(lVar1 + 0x205) == '\0') {

    iVar22 = iVar22 + 5;

    *piVar16 = iVar22;

  }

  iVar9 = FUN_1400c6e80(iVar22,2);

  iVar22 = 1;

  if (1 < iVar9) {

    iVar22 = iVar9;

  }

  *piVar16 = iVar22;

  if (DAT_1403d9526 != '\0') {

    uVar14 = FUN_1400c78c0(*(undefined4 *)(lVar1 + 0x1f8));

    uVar15 = CONCAT44(uVar27,iVar10);

    FUN_1400c4320("%s = (%d rand + %d nice + %d record) * %d years + %d deco   gdist=%.3f",uVar14,

                  local_80 & 0xffffffff,local_res20,uVar15,CONCAT44(uVar25,local_b4),local_res8,

                  (double)fVar23);

    uVar27 = (undefined4)((ulonglong)uVar15 >> 0x20);

  }

  piVar20 = (int *)(param_1 + 0x450);

  if (*(char *)(lVar1 + 0x204) == '\0') {

    iVar22 = *piVar16 * 2;

    *piVar16 = iVar22;

    if (*(int *)(*(longlong *)(param_1 + 0x148) + 0x1c) == 2) {

      iVar9 = FUN_1400c6580(((int)((iVar22 >> 0x1f & 3U) + iVar22) >> 2) + 1);

      iVar10 = 1;

      if (1 < iVar22 - iVar9) {

        iVar10 = iVar22 - iVar9;

      }

      *piVar16 = iVar10;

      iVar22 = FUN_1400c6580(0x28);

      if (iVar22 == 0) {

        iVar22 = *piVar20;

        iVar10 = FUN_1400c6580(10000);

        *piVar20 = iVar10 + iVar22;

      }

    }

    uVar25 = DAT_140303758;

    piVar16 = (int *)(param_1 + 0x450);

    iVar22 = *(int *)(param_1 + 600);

    if (iVar22 == 4) {

      if ((*(int *)(*(longlong *)(param_1 + 0x148) + 0x1c) == 2) &&

         (cVar8 = FUN_1400b5f80(lVar1), cVar8 == '\0')) {

        iVar22 = *piVar16;

        uVar14 = *(undefined8 *)(param_1 + 0x148);

        uVar15 = FUN_1400cf9a0(param_1,lVar1);

        uVar26 = CONCAT44(uVar27,iVar22);

        FUN_1400d1c40(param_1,uVar14,"You can have %s for $%d I s\'pose",uVar15,uVar26);

        uVar27 = (undefined4)((ulonglong)uVar26 >> 0x20);

      }

      else {

        uVar14 = *(undefined8 *)(param_1 + 0x148);

        FUN_1400cf9a0(param_1,lVar1);

        FUN_1400d1c40(param_1,uVar14);

        *piVar16 = 0;

      }

      goto LAB_1400ddc58;

    }

    if (((iVar22 == 1) && (*(char *)(*(longlong *)(param_1 + 0x60) + 0x39d) != '\0')) &&

       (*(longlong *)(param_1 + 0x458) != 0)) {

      local_d8 = (char *)0x0;

      uStack_d0 = 0;

      local_c8 = 0;

      uStack_c0 = 0;

      local_d8 = (char *)FUN_1400285e0(0x20);

      uVar14 = s_I_lost_my_horse__14030f2d0._8_8_;

      local_c8 = _DAT_1403040e0;

      uStack_c0 = _UNK_1403040e8;

      *(undefined8 *)local_d8 = s_I_lost_my_horse__14030f2d0._0_8_;

      *(undefined8 *)(local_d8 + 8) = uVar14;

      local_d8[0x10] = '\0';

      uVar14 = CONCAT44(uVar27,uVar25);

      FUN_1400d0c80(param_1,*(undefined8 *)(param_1 + 0x148),&local_d8,0,uVar14);

      uVar27 = (undefined4)((ulonglong)uVar14 >> 0x20);

      if (0xf < uStack_c0) {

        if ((0xfff < uStack_c0 + 1) &&

           ((char *)0x1f < local_d8 + (-8 - *(longlong *)(local_d8 + -8)))) {

                    /* WARNING: Subroutine does not return */

          _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

        }

LAB_1400dd1d5:

        FUN_1402c7088();

      }

    }

    else {

      if (*(int *)(lVar1 + 0x1c) != 6) {

        if (local_a8 < local_ac) {

          if (iVar22 == 6) {

            iVar22 = *piVar16 / 0x50 + 1;

            *(int *)(param_1 + 0x450) = iVar22;

            uVar14 = *(undefined8 *)(param_1 + 0x148);

            puVar21 = &DAT_14030cc60;

            if (iVar22 == 1) {

              puVar21 = &DAT_14039bcb9;

            }

            uVar15 = FUN_1400cf9a0(param_1,lVar1);

            uVar26 = CONCAT44(uVar27,iVar22);

            FUN_1400d1c40(param_1,uVar14,"You can have %s for %d bottle%s of Hot Sauce",uVar15,

                          uVar26,puVar21);

            uVar27 = (undefined4)((ulonglong)uVar26 >> 0x20);

          }

          else if ((char)local_b8 == '\0') {

            if (bVar4) {

              iVar22 = *piVar16;

              uVar14 = *(undefined8 *)(param_1 + 0x148);

              uVar15 = FUN_1400cf9a0(param_1,lVar1);

              uVar26 = CONCAT44(uVar27,iVar22);

              FUN_1400d1c40(param_1,uVar14,"%s is a nice horse! I\'ll only accept $%d",uVar15,uVar26

                           );

              uVar27 = (undefined4)((ulonglong)uVar26 >> 0x20);

            }

            else {

              lVar11 = FUN_1400c7520(*(undefined4 *)(lVar1 + 0x1f8));

              iVar22 = *piVar16;

              uVar14 = *(undefined8 *)(param_1 + 0x148);

              if (*(int *)(lVar11 + 0x54) < 2) {

                uVar15 = FUN_1400cf9a0(param_1,lVar1);

                pcVar19 = "I\'ll sell you %s for $%d";

              }

              else {

                uVar15 = FUN_1400cf9a0(param_1,lVar1);

                pcVar19 = "%s is my star horse! I\'ll only accept $%d";

              }

              uVar26 = CONCAT44(uVar27,iVar22);

              FUN_1400d1c40(param_1,uVar14,pcVar19,uVar15,uVar26);

              uVar27 = (undefined4)((ulonglong)uVar26 >> 0x20);

            }

          }

          else {

            iVar22 = *piVar16;

            uVar14 = *(undefined8 *)(param_1 + 0x148);

            uVar15 = FUN_1400cf9a0(param_1,lVar1);

            uVar26 = CONCAT44(uVar27,iVar22);

            FUN_1400d1c40(param_1,uVar14,"%s is my perfect horse! I\'ll only accept $%d",uVar15,

                          uVar26);

            uVar27 = (undefined4)((ulonglong)uVar26 >> 0x20);

          }

        }

        else {

          local_d8 = (char *)0x0;

          uStack_d0 = 0;

          local_c8 = 0;

          uStack_c0 = 0;

          local_d8 = (char *)FUN_1400285e0(0x20);

          uVar14 = s_That_horse_is_too_old_14030f308._8_8_;

          local_c8 = _DAT_140304110;

          uStack_c0 = _UNK_140304118;

          *(undefined8 *)local_d8 = s_That_horse_is_too_old_14030f308._0_8_;

          *(undefined8 *)(local_d8 + 8) = uVar14;

          *(undefined4 *)(local_d8 + 0x10) = s_That_horse_is_too_old_14030f308._16_4_;

          local_d8[0x14] = s_That_horse_is_too_old_14030f308[0x14];

          local_d8[0x15] = '\0';

          uVar14 = CONCAT44(uVar27,uVar25);

          FUN_1400d0c80(param_1,*(undefined8 *)(param_1 + 0x148),&local_d8,0,uVar14);

          uVar27 = (undefined4)((ulonglong)uVar14 >> 0x20);

          if (0xf < uStack_c0) {

            if ((0xfff < uStack_c0 + 1) &&

               ((char *)0x1f < local_d8 + (-8 - *(longlong *)(local_d8 + -8)))) {

                    /* WARNING: Subroutine does not return */

              _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

            }

            FUN_1402c7088();

          }

          *(undefined4 *)(param_1 + 0x450) = 0;

        }

        goto LAB_1400ddc58;

      }

      local_d8 = (char *)0x0;

      uStack_d0 = 0;

      local_c8 = 0;

      uStack_c0 = 0;

      local_d8 = (char *)FUN_1400285e0(0x20);

      uVar14 = s_Why_that_horse_is_deceased_14030f2e8._8_8_;

      local_c8 = _DAT_140304ce0;

      uStack_c0 = _UNK_140304ce8;

      *(undefined8 *)local_d8 = s_Why_that_horse_is_deceased_14030f2e8._0_8_;

      *(undefined8 *)(local_d8 + 8) = uVar14;

      *(undefined8 *)(local_d8 + 0x10) = s_Why_that_horse_is_deceased_14030f2e8._16_8_;

      *(undefined2 *)(local_d8 + 0x18) = s_Why_that_horse_is_deceased_14030f2e8._24_2_;

      local_d8[0x1a] = '\0';

      uVar14 = CONCAT44(uVar27,uVar25);

      FUN_1400d0c80(param_1,*(undefined8 *)(param_1 + 0x148),&local_d8,0,uVar14);

      uVar27 = (undefined4)((ulonglong)uVar14 >> 0x20);

      if (0xf < uStack_c0) {

        if ((0xfff < uStack_c0 + 1) &&

           ((char *)0x1f < local_d8 + (-8 - *(longlong *)(local_d8 + -8)))) {

                    /* WARNING: Subroutine does not return */

          _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

        }

        goto LAB_1400dd1d5;

      }

    }

    *(undefined4 *)(param_1 + 0x450) = 0;

    goto LAB_1400ddc58;

  }

  if (*(int *)(*(longlong *)(param_1 + 0x148) + 0x1c) == 1) {

    iVar22 = *piVar20;

    iVar10 = FUN_1400c6580(((int)((iVar22 >> 0x1f & 3U) + iVar22) >> 2) + 1);

    *piVar20 = iVar10 + iVar22;

  }

  iVar22 = -1;

  iVar10 = 0;

  plVar12 = *(longlong **)(param_1 + 0x130);

  uVar17 = *(longlong *)(param_1 + 0x138) - (longlong)plVar12 >> 3;

  if (uVar17 != 0) {

    do {

      iVar9 = iVar22 + 1;

      if (*(char *)(*plVar12 + 0x204) != '\0') {

        iVar9 = iVar22;

      }

      iVar22 = iVar9;

      iVar10 = iVar10 + 1;

      plVar12 = plVar12 + 1;

    } while ((ulonglong)(longlong)iVar10 < uVar17);

  }

  piVar16 = (int *)(param_1 + 0x450);

  iVar10 = iVar22 + -5;

  if (iVar22 + -5 < 0) {

    iVar10 = 0;

  }

  iVar22 = (3 - iVar10) * *piVar16;

  iVar9 = iVar22 / 3 + (iVar22 >> 0x1f) +

          (int)(((longlong)iVar22 / 3 + ((longlong)iVar22 >> 0x3f) & 0xffffffffU) >> 0x1f);

  iVar22 = 1;

  if (1 < iVar9) {

    iVar22 = iVar9;

  }

  *piVar16 = iVar22;

  uVar25 = DAT_140303758;

  iVar9 = *(int *)(param_1 + 600);

  if (iVar9 == 4) {

    cVar8 = FUN_1400b5f80(*(undefined8 *)(param_1 + 0x148));

    if ((cVar8 == '\0') || (cVar8 = FUN_1400b5f80(lVar1), cVar8 == '\0')) {

      if (*(int *)(*(longlong *)(param_1 + 0x148) + 0x1c) != 2) {

        local_d8 = (char *)0x0;

        uStack_d0 = 0;

        local_c8 = 0;

        uStack_c0 = 0;

        local_d8 = (char *)FUN_1400285e0(0x20);

        uVar14 = s_I_don_t_want_your_silly_horses__14030f4a0._8_8_;

        local_c8 = _DAT_140304140;

        uStack_c0 = _UNK_140304148;

        *(undefined8 *)local_d8 = s_I_don_t_want_your_silly_horses__14030f4a0._0_8_;

        *(undefined8 *)(local_d8 + 8) = uVar14;

        *(undefined8 *)(local_d8 + 0x10) = s_I_don_t_want_your_silly_horses__14030f4a0._16_8_;

        *(undefined4 *)(local_d8 + 0x18) = s_I_don_t_want_your_silly_horses__14030f4a0._24_4_;

        *(undefined2 *)(local_d8 + 0x1c) = s_I_don_t_want_your_silly_horses__14030f4a0._28_2_;

        local_d8[0x1e] = s_I_don_t_want_your_silly_horses__14030f4a0[0x1e];

        local_d8[0x1f] = '\0';

        uVar14 = CONCAT44(uVar27,uVar25);

        FUN_1400d0c80(param_1,*(undefined8 *)(param_1 + 0x148),&local_d8,0,uVar14);

        uVar27 = (undefined4)((ulonglong)uVar14 >> 0x20);

        if (0xf < uStack_c0) {

          if ((0xfff < uStack_c0 + 1) &&

             ((char *)0x1f < local_d8 + (-8 - *(longlong *)(local_d8 + -8)))) {

                    /* WARNING: Subroutine does not return */

            _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

          }

          FUN_1402c7088();

        }

        *(undefined4 *)(param_1 + 0x450) = 0;

        goto LAB_1400ddc58;

      }

      local_78 = (char *)0x0;

      uStack_70 = 0;

      local_68 = 0;

      uStack_60 = 0;

      local_78 = (char *)FUN_1400285e0(0x30);

      uVar14 = s_I_m_sorry_I_was_ever_mean_to_you_14030f440._8_8_;

      local_68 = _DAT_140304150;

      uStack_60 = _UNK_140304158;

      *(undefined8 *)local_78 = s_I_m_sorry_I_was_ever_mean_to_you_14030f440._0_8_;

      *(undefined8 *)(local_78 + 8) = uVar14;

      uVar7 = s_I_m_sorry_I_was_ever_mean_to_you_14030f440._28_4_;

      uVar6 = s_I_m_sorry_I_was_ever_mean_to_you_14030f440._24_4_;

      uVar5 = s_I_m_sorry_I_was_ever_mean_to_you_14030f440._20_4_;

      *(undefined4 *)(local_78 + 0x10) = s_I_m_sorry_I_was_ever_mean_to_you_14030f440._16_4_;

      *(undefined4 *)(local_78 + 0x14) = uVar5;

      *(undefined4 *)(local_78 + 0x18) = uVar6;

      *(undefined4 *)(local_78 + 0x1c) = uVar7;

      local_78[0x20] = '\0';

      uVar14 = CONCAT44(uVar27,uVar25);

      FUN_1400d0c80(param_1,*(undefined8 *)(param_1 + 0x148),&local_78,0,uVar14);

      uVar27 = (undefined4)((ulonglong)uVar14 >> 0x20);

      if (0xf < uStack_60) {

        if ((0xfff < uStack_60 + 1) &&

           ((char *)0x1f < local_78 + (-8 - *(longlong *)(local_78 + -8)))) {

                    /* WARNING: Subroutine does not return */

          _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

        }

        FUN_1402c7088();

      }

      local_d8 = (char *)0x0;

      uStack_d0 = 0;

      local_c8 = 0;

      uStack_c0 = 0;

      local_d8 = (char *)FUN_1400285e0(0x20);

      uVar14 = s_You_re_my_best_friend_now_14030f468._8_8_;

      local_c8 = _DAT_140303760;

      uStack_c0 = _UNK_140303768;

      *(undefined8 *)local_d8 = s_You_re_my_best_friend_now_14030f468._0_8_;

      *(undefined8 *)(local_d8 + 8) = uVar14;

      *(undefined8 *)(local_d8 + 0x10) = s_You_re_my_best_friend_now_14030f468._16_8_;

      local_d8[0x18] = s_You_re_my_best_friend_now_14030f468[0x18];

      local_d8[0x19] = '\0';

      FUN_1400d0c80(param_1,*(undefined8 *)(param_1 + 0x148),&local_d8,0,CONCAT44(uVar27,uVar25));

      if (0xf < uStack_c0) {

        if ((0xfff < uStack_c0 + 1) &&

           ((char *)0x1f < local_d8 + (-8 - *(longlong *)(local_d8 + -8)))) {

                    /* WARNING: Subroutine does not return */

          _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

        }

        FUN_1402c7088();

      }

      iVar22 = *(int *)(param_1 + 0x450);

      uVar14 = *(undefined8 *)(param_1 + 0x148);

      uVar15 = FUN_1400cf9a0(param_1,lVar1);

      pcVar19 = "I\'ll give ya $%d for %s";

    }

    else {

      iVar22 = *piVar16 * 2;

      *piVar16 = iVar22;

      uVar14 = *(undefined8 *)(param_1 + 0x148);

      uVar15 = FUN_1400cf9a0(param_1,lVar1);

      pcVar19 = "Those eyebrows make me so giddy! I\'ll give you $%d for %s!";

    }

LAB_1400ddc4b:

    FUN_1400d1c40(param_1,uVar14,pcVar19,iVar22,uVar15);

    uVar27 = (undefined4)((ulonglong)uVar15 >> 0x20);

  }

  else {

    if (((iVar9 == 1) && (*(char *)(*(longlong *)(param_1 + 0x60) + 0x39d) != '\0')) &&

       (*(longlong *)(param_1 + 0x458) != 0)) {

      local_d8 = (char *)0x0;

      uStack_d0 = 0;

      local_c8 = 0;

      uStack_c0 = 0;

      local_d8 = (char *)FUN_1400285e0(0x30);

      uVar14 = s_Let_me_take_a_closer_look_at_tha_14030f4c0._8_8_;

      local_c8 = _DAT_140306000;

      uStack_c0 = _UNK_140306008;

      *(undefined8 *)local_d8 = s_Let_me_take_a_closer_look_at_tha_14030f4c0._0_8_;

      *(undefined8 *)(local_d8 + 8) = uVar14;

      uVar7 = s_Let_me_take_a_closer_look_at_tha_14030f4c0._28_4_;

      uVar6 = s_Let_me_take_a_closer_look_at_tha_14030f4c0._24_4_;

      uVar5 = s_Let_me_take_a_closer_look_at_tha_14030f4c0._20_4_;

      *(undefined4 *)(local_d8 + 0x10) = s_Let_me_take_a_closer_look_at_tha_14030f4c0._16_4_;

      *(undefined4 *)(local_d8 + 0x14) = uVar5;

      *(undefined4 *)(local_d8 + 0x18) = uVar6;

      *(undefined4 *)(local_d8 + 0x1c) = uVar7;

      *(undefined4 *)(local_d8 + 0x20) = s_Let_me_take_a_closer_look_at_tha_14030f4c0._32_4_;

      *(undefined2 *)(local_d8 + 0x24) = s_Let_me_take_a_closer_look_at_tha_14030f4c0._36_2_;

      local_d8[0x26] = s_Let_me_take_a_closer_look_at_tha_14030f4c0[0x26];

      local_d8[0x27] = '\0';

      uVar14 = CONCAT44(uVar27,uVar25);

      FUN_1400d0c80(param_1,*(undefined8 *)(param_1 + 0x148),&local_d8,0,uVar14);

      uVar27 = (undefined4)((ulonglong)uVar14 >> 0x20);

      if (0xf < uStack_c0) {

        if ((0xfff < uStack_c0 + 1) &&

           ((char *)0x1f < local_d8 + (-8 - *(longlong *)(local_d8 + -8)))) {

                    /* WARNING: Subroutine does not return */

          _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

        }

        FUN_1402c7088();

      }

      *(undefined4 *)(param_1 + 0x450) = 0;

      goto LAB_1400ddc58;

    }

    if (*(int *)(lVar1 + 0x1c) == 6) {

      local_d8 = (char *)0x0;

      uStack_d0 = 0;

      local_c8 = 0;

      uStack_c0 = 0;

      local_d8 = (char *)FUN_1400285e0(0x40);

      uVar14 = s_I_say_there_partner__that_horse_l_14030f4e8._8_8_;

      local_c8 = _DAT_14030fc40;

      uStack_c0 = _UNK_14030fc48;

      *(undefined8 *)local_d8 = s_I_say_there_partner__that_horse_l_14030f4e8._0_8_;

      *(undefined8 *)(local_d8 + 8) = uVar14;

      uVar7 = s_I_say_there_partner__that_horse_l_14030f4e8._28_4_;

      uVar6 = s_I_say_there_partner__that_horse_l_14030f4e8._24_4_;

      uVar5 = s_I_say_there_partner__that_horse_l_14030f4e8._20_4_;

      *(undefined4 *)(local_d8 + 0x10) = s_I_say_there_partner__that_horse_l_14030f4e8._16_4_;

      *(undefined4 *)(local_d8 + 0x14) = uVar5;

      *(undefined4 *)(local_d8 + 0x18) = uVar6;

      *(undefined4 *)(local_d8 + 0x1c) = uVar7;

      uVar14 = s_I_say_there_partner__that_horse_l_14030f4e8._40_8_;

      *(undefined8 *)(local_d8 + 0x20) = s_I_say_there_partner__that_horse_l_14030f4e8._32_8_;

      *(undefined8 *)(local_d8 + 0x28) = uVar14;

      *(undefined8 *)(local_d8 + 0x30) = s_I_say_there_partner__that_horse_l_14030f4e8._48_8_;

      *(undefined4 *)(local_d8 + 0x38) = s_I_say_there_partner__that_horse_l_14030f4e8._56_4_;

      local_d8[0x3c] = '\0';

      uVar14 = CONCAT44(uVar27,uVar25);

      FUN_1400d0c80(param_1,*(undefined8 *)(param_1 + 0x148),&local_d8,0,uVar14);

      uVar27 = (undefined4)((ulonglong)uVar14 >> 0x20);

      if (0xf < uStack_c0) {

        if ((0xfff < uStack_c0 + 1) &&

           ((char *)0x1f < local_d8 + (-8 - *(longlong *)(local_d8 + -8)))) {

                    /* WARNING: Subroutine does not return */

          _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

        }

        FUN_1402c7088();

      }

      local_d8 = (char *)0x0;

      uStack_d0 = 0;

      local_c8 = 0;

      uStack_c0 = 0;

      local_d8 = (char *)FUN_1400285e0(0x30);

      uVar14 = s_Matter_of_fact_I_reckon_it_s_don_14030f528._8_8_;

      local_c8 = _DAT_140303780;

      uStack_c0 = _UNK_140303788;

      *(undefined8 *)local_d8 = s_Matter_of_fact_I_reckon_it_s_don_14030f528._0_8_;

      *(undefined8 *)(local_d8 + 8) = uVar14;

      uVar7 = s_Matter_of_fact_I_reckon_it_s_don_14030f528._28_4_;

      uVar6 = s_Matter_of_fact_I_reckon_it_s_don_14030f528._24_4_;

      uVar5 = s_Matter_of_fact_I_reckon_it_s_don_14030f528._20_4_;

      *(undefined4 *)(local_d8 + 0x10) = s_Matter_of_fact_I_reckon_it_s_don_14030f528._16_4_;

      *(undefined4 *)(local_d8 + 0x14) = uVar5;

      *(undefined4 *)(local_d8 + 0x18) = uVar6;

      *(undefined4 *)(local_d8 + 0x1c) = uVar7;

      *(undefined8 *)(local_d8 + 0x20) = s_Matter_of_fact_I_reckon_it_s_don_14030f528._32_8_;

      *(undefined2 *)(local_d8 + 0x28) = s_Matter_of_fact_I_reckon_it_s_don_14030f528._40_2_;

      local_d8[0x2a] = '\0';

      uVar14 = CONCAT44(uVar27,uVar25);

      FUN_1400d0c80(param_1,*(undefined8 *)(param_1 + 0x148),&local_d8,0,uVar14);

      uVar27 = (undefined4)((ulonglong)uVar14 >> 0x20);

      if (0xf < uStack_c0) {

        if ((0xfff < uStack_c0 + 1) &&

           ((char *)0x1f < local_d8 + (-8 - *(longlong *)(local_d8 + -8)))) {

                    /* WARNING: Subroutine does not return */

          _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

        }

        FUN_1402c7088();

      }

      local_d8 = (char *)0x0;

      uStack_d0 = 0;

      local_c8 = 0;

      uStack_c0 = 0;

      local_d8 = (char *)FUN_1400285e0(0x30);

      uVar14 = s_up_to_horse_heaven__if_you_catch_14030f558._8_8_;

      local_c8 = _DAT_14030fc30;

      uStack_c0 = _UNK_14030fc38;

      *(undefined8 *)local_d8 = s_up_to_horse_heaven__if_you_catch_14030f558._0_8_;

      *(undefined8 *)(local_d8 + 8) = uVar14;

      uVar7 = s_up_to_horse_heaven__if_you_catch_14030f558._28_4_;

      uVar6 = s_up_to_horse_heaven__if_you_catch_14030f558._24_4_;

      uVar5 = s_up_to_horse_heaven__if_you_catch_14030f558._20_4_;

      *(undefined4 *)(local_d8 + 0x10) = s_up_to_horse_heaven__if_you_catch_14030f558._16_4_;

      *(undefined4 *)(local_d8 + 0x14) = uVar5;

      *(undefined4 *)(local_d8 + 0x18) = uVar6;

      *(undefined4 *)(local_d8 + 0x1c) = uVar7;

      *(undefined8 *)(local_d8 + 0x20) = s_up_to_horse_heaven__if_you_catch_14030f558._32_8_;

      local_d8[0x28] = s_up_to_horse_heaven__if_you_catch_14030f558[0x28];

      local_d8[0x29] = '\0';

      uVar14 = CONCAT44(uVar27,uVar25);

      FUN_1400d0c80(param_1,*(undefined8 *)(param_1 + 0x148),&local_d8,0,uVar14);

      uVar27 = (undefined4)((ulonglong)uVar14 >> 0x20);

      if (0xf < uStack_c0) {

        if ((0xfff < uStack_c0 + 1) &&

           ((char *)0x1f < local_d8 + (-8 - *(longlong *)(local_d8 + -8)))) {

                    /* WARNING: Subroutine does not return */

          _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

        }

LAB_1400ddb08:

        FUN_1402c7088();

      }

    }

    else {

      if (local_a8 < local_ac) {

        if (iVar9 == 6) {

          iVar22 = iVar22 / 0x50 + 1;

          *(int *)(param_1 + 0x450) = iVar22;

          uVar14 = *(undefined8 *)(param_1 + 0x148);

          uVar15 = FUN_1400cf9a0(param_1,lVar1);

          puVar21 = &DAT_14030cc60;

          if (iVar22 == 1) {

            puVar21 = &DAT_14039bcb9;

          }

          FUN_1400d1c40(param_1,uVar14,"I\'ll give you %d bottle%s of Hot Sauce for %s",iVar22,

                        puVar21,uVar15);

          uVar27 = (undefined4)((ulonglong)puVar21 >> 0x20);

          goto LAB_1400ddc58;

        }

        if (iVar10 < 1) {

          if ((char)local_b8 != '\0') {

            uVar14 = *(undefined8 *)(param_1 + 0x148);

            uVar15 = FUN_1400cf9a0(param_1,lVar1);

            uVar26 = CONCAT44(uVar27,iVar22);

            FUN_1400d1c40(param_1,uVar14,"%s is an incredible horse! I\'ll pay $%d!",uVar15,uVar26);

            uVar27 = (undefined4)((ulonglong)uVar26 >> 0x20);

            goto LAB_1400ddc58;

          }

          if (bVar4) {

            uVar14 = *(undefined8 *)(param_1 + 0x148);

            uVar15 = FUN_1400cf9a0(param_1,lVar1);

            uVar26 = CONCAT44(uVar27,iVar22);

            FUN_1400d1c40(param_1,uVar14,"What a nice horse! %s is worth $%d to me!",uVar15,uVar26);

            uVar27 = (undefined4)((ulonglong)uVar26 >> 0x20);

            goto LAB_1400ddc58;

          }

          if (local_b4 < 3) {

            uVar14 = *(undefined8 *)(param_1 + 0x148);

            uVar15 = FUN_1400cf9a0(param_1,lVar1);

            uVar26 = CONCAT44(uVar27,iVar22);

            FUN_1400d1c40(param_1,uVar14,"%s is getting old. I can only offer you $%d",uVar15,uVar26

                         );

            uVar27 = (undefined4)((ulonglong)uVar26 >> 0x20);

            goto LAB_1400ddc58;

          }

          uVar14 = *(undefined8 *)(param_1 + 0x148);

          uVar15 = FUN_1400cf9a0(param_1,lVar1);

          pcVar19 = "I\'ll give you $%d for %s";

        }

        else {

          uVar14 = *(undefined8 *)(param_1 + 0x148);

          uVar15 = FUN_1400cf9a0(param_1,lVar1);

          pcVar19 = "I have too many horses!! I can only do $%d for %s";

        }

        goto LAB_1400ddc4b;

      }

      local_d8 = (char *)0x0;

      uStack_d0 = 0;

      local_c8 = 0;

      uStack_c0 = 0;

      local_d8 = (char *)FUN_1400285e0(0x20);

      uVar14 = s_That_horse_is_too_old__14030f588._8_8_;

      local_c8 = _DAT_140305fd0;

      uStack_c0 = _UNK_140305fd8;

      *(undefined8 *)local_d8 = s_That_horse_is_too_old__14030f588._0_8_;

      *(undefined8 *)(local_d8 + 8) = uVar14;

      *(undefined4 *)(local_d8 + 0x10) = s_That_horse_is_too_old__14030f588._16_4_;

      *(undefined2 *)(local_d8 + 0x14) = s_That_horse_is_too_old__14030f588._20_2_;

      local_d8[0x16] = '\0';

      uVar14 = CONCAT44(uVar27,uVar25);

      FUN_1400d0c80(param_1,*(undefined8 *)(param_1 + 0x148),&local_d8,0,uVar14);

      uVar27 = (undefined4)((ulonglong)uVar14 >> 0x20);

      if (0xf < uStack_c0) {

        if ((0xfff < uStack_c0 + 1) &&

           ((char *)0x1f < local_d8 + (-8 - *(longlong *)(local_d8 + -8)))) {

                    /* WARNING: Subroutine does not return */

          _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

        }

        goto LAB_1400ddb08;

      }

    }

    *(undefined4 *)(param_1 + 0x450) = 0;

  }

LAB_1400ddc58:

  if ((local_90 != 0) && (0 < *(int *)(param_1 + 0x450))) {

    FUN_1400d0c80(param_1,*(undefined8 *)(param_1 + 0x148),&local_a0,0,CONCAT44(uVar27,uVar25));

  }

  DAT_1403f4bb0 = 1;

  if (0xf < uStack_88) {

    if ((0xfff < uStack_88 + 1) && (0x1f < (local_a0 - *(longlong *)(local_a0 + -8)) - 8U)) {

                    /* WARNING: Subroutine does not return */

      _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

    }

    FUN_1402c7088();

  }

  return;

}
```