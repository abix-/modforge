# `FUN_1400cfda0` @ 0x1400cfda0

**Size**: 1047 bytes
**Role**: unclassified game logic

**Game callers** (2): `FUN_1400cfda0`, `FUN_140106b90`

**Game callees** (10): `FUN_140024090`, `FUN_1400285e0`, `FUN_14002f0d0`, `FUN_14009c330`, `FUN_1400c6580`, `FUN_1400cfda0`, `FUN_1402c5c1c`, `FUN_1402c7088`, `FUN_1402f8e20`, `FUN_1402f94c0`

**Vendor callees** (0) - SDL/CRT/etc.

## Decompiled

```c
longlong FUN_1400cfda0(longlong param_1,longlong *param_2)

{

  longlong *plVar1;

  code *pcVar2;

  int iVar3;

  int iVar4;

  longlong *plVar5;

  longlong lVar6;

  ulonglong uVar7;

  ulonglong uVar8;

  ulonglong uVar9;

  longlong *plVar10;

  longlong lVar11;

  longlong *plVar12;

  longlong *plVar13;

  longlong *plVar14;

  int local_res8;

  longlong *local_68;

  longlong *plStack_60;

  longlong *local_58;

  local_68 = (longlong *)0x0;

  plStack_60 = (longlong *)0x0;

  iVar4 = 0;

  local_58 = (longlong *)0x0;

  local_res8 = 0;

  plVar14 = *(longlong **)(param_1 + 0x130);

  plVar1 = *(longlong **)(param_1 + 0x138);

  do {

    if (plVar14 == plVar1) {

      lVar6 = 0;

      if (local_68 != plStack_60) {

        iVar4 = FUN_1400c6580((longlong)plStack_60 - (longlong)local_68 >> 3);

        lVar6 = local_68[iVar4];

      }

      if (local_68 != (longlong *)0x0) {

        plVar14 = local_68;

        if ((0xfff < ((longlong)local_58 - (longlong)local_68 & 0xfffffffffffffff8U)) &&

           (plVar14 = (longlong *)local_68[-1],

           0x1f < (ulonglong)((longlong)local_68 + (-8 - (longlong)plVar14)))) {

                    /* WARNING: Subroutine does not return */

          _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

        }

        FUN_1402c7088(plVar14);

        local_68 = (longlong *)0x0;

        plStack_60 = (longlong *)0x0;

        local_58 = (longlong *)0x0;

      }

      plVar14 = (longlong *)param_2[7];

      if (plVar14 != (longlong *)0x0) {

        (**(code **)(*plVar14 + 0x20))(plVar14,plVar14 != param_2);

        param_2[7] = 0;

      }

      return lVar6;

    }

    lVar6 = *plVar14;

    if ((longlong *)param_2[7] == (longlong *)0x0) {

      FUN_1402c5c1c();

      pcVar2 = (code *)swi(3);

      lVar6 = (*pcVar2)();

      return lVar6;

    }

    iVar3 = (**(code **)(*(longlong *)param_2[7] + 0x10))();

    plVar13 = plStack_60;

    if (iVar4 < iVar3) {

      local_res8 = iVar3;

      if ((longlong)local_58 - (longlong)local_68 >> 3 == 0) {

        if (local_68 != (longlong *)0x0) {

          FUN_14009c330(&local_68);

          local_68 = (longlong *)0x0;

          plStack_60 = (longlong *)0x0;

          local_58 = (longlong *)0x0;

        }

        local_68 = (longlong *)FUN_1400285e0(8);

        local_58 = local_68 + 1;

        plStack_60 = local_68;

        if (lVar6 == 0) {

          *local_68 = 0;

        }

        else {

          *local_68 = lVar6;

        }

LAB_1400cfec7:

        plStack_60 = plStack_60 + 1;

        iVar4 = iVar3;

      }

      else {

        iVar4 = iVar3;

        if ((longlong)plStack_60 - (longlong)local_68 >> 3 == 0) {

          if (lVar6 == 0) {

            FUN_1402f94c0(local_68,0);

          }

          else {

            uVar7 = ((longlong)plStack_60 - (longlong)local_68) + 7U >> 3;

            if (plStack_60 < local_68) {

              uVar7 = 0;

            }

            plVar13 = local_68;

            if (uVar7 != 0) {

              for (; uVar7 != 0; uVar7 = uVar7 - 1) {

                *plVar13 = lVar6;

                plVar13 = plVar13 + 1;

              }

            }

          }

          plVar13 = plStack_60;

          lVar11 = 1;

          if (lVar6 == 0) {

            FUN_1402f94c0(plStack_60,0);

          }

          else {

            for (; lVar11 != 0; lVar11 = lVar11 + -1) {

              *plStack_60 = lVar6;

              plStack_60 = plStack_60 + 1;

            }

          }

          plStack_60 = plVar13 + 1;

        }

        else {

          plStack_60 = local_68 + 1;

          if (lVar6 == 0) {

            *local_68 = 0;

          }

          else {

            uVar7 = (ulonglong)(local_68 <= plStack_60);

            plVar13 = local_68;

            if (local_68 <= plStack_60) {

              for (; uVar7 != 0; uVar7 = uVar7 - 1) {

                *plVar13 = lVar6;

                plVar13 = plVar13 + 1;

              }

            }

          }

        }

      }

    }

    else if (iVar3 == iVar4) {

      if (plStack_60 != local_58) {

        *plStack_60 = lVar6;

        iVar3 = iVar4;

        goto LAB_1400cfec7;

      }

      lVar11 = (longlong)plStack_60 - (longlong)local_68 >> 3;

      if (lVar11 == 0x1fffffffffffffff) {

                    /* WARNING: Subroutine does not return */

        FUN_14002f0d0();

      }

      uVar7 = lVar11 + 1;

      uVar8 = (longlong)local_58 - (longlong)local_68 >> 3;

      if (0x1fffffffffffffff - (uVar8 >> 1) < uVar8) {

        uVar9 = 0x1fffffffffffffff;

      }

      else {

        uVar8 = (uVar8 >> 1) + uVar8;

        uVar9 = uVar7;

        if (uVar7 <= uVar8) {

          uVar9 = uVar8;

        }

        if (0x1fffffffffffffff < uVar9) {

                    /* WARNING: Subroutine does not return */

          FUN_140024090();

        }

      }

      plVar5 = (longlong *)FUN_1400285e0(uVar9 * 8);

      plVar5[lVar11] = lVar6;

      plVar10 = plVar5;

      plVar12 = local_68;

      if (plVar13 != plStack_60) {

        FUN_1402f8e20(plVar5,local_68,(longlong)plVar13 - (longlong)local_68);

        plVar10 = plVar5 + lVar11 + 1;

        plVar12 = plVar13;

      }

      FUN_1402f8e20(plVar10,plVar12);

      if (local_68 != (longlong *)0x0) {

        if ((0xfff < ((longlong)local_58 - (longlong)local_68 & 0xfffffffffffffff8U)) &&

           (0x1f < (ulonglong)((longlong)local_68 + (-8 - local_68[-1])))) {

                    /* WARNING: Subroutine does not return */

          _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

        }

        FUN_1402c7088();

      }

      plStack_60 = plVar5 + uVar7;

      local_58 = plVar5 + uVar9;

      local_68 = plVar5;

      iVar4 = local_res8;

    }

    plVar14 = plVar14 + 1;

  } while( true );

}
```