# `FUN_1400ccbd0` @ 0x1400ccbd0

**Size**: 551 bytes
**Role**: `float_math_heavy` - Heavy floating-point math (geometry/physics/genetics)  _(evidence: 16 float vars (geometry/physics/genetics?))_
**Pattern category**: `float_math_heavy`

**Game callers** (2): [`FUN_1400ccbd0`](1400ccbd0_FUN_1400ccbd0.md), [`FUN_1400cead0`](1400cead0_FUN_1400cead0.md)

**Game callees** (10): [`FUN_140024090`](140024090_FUN_140024090.md), [`FUN_1400285e0`](1400285e0_FUN_1400285e0.md), [`FUN_14002f0d0`](14002f0d0_FUN_14002f0d0.md), [`FUN_140037380`](140037380_FUN_140037380.md), [`FUN_14005c9b0`](14005c9b0_FUN_14005c9b0.md), [`FUN_1400b4a10`](1400b4a10_FUN_1400b4a10.md), [`FUN_1400b6170`](1400b6170_FUN_1400b6170.md), [`FUN_1400ccbd0`](1400ccbd0_FUN_1400ccbd0.md), [`FUN_1402c704c`](1402c704c_FUN_1402c704c.md), [`FUN_1402f8e20`](1402f8e20_FUN_1402f8e20.md)

**Vendor callees**: 0 (SDL/CRT/etc, not shown)

## Decompiled

```c
void FUN_1400ccbd0(longlong param_1,undefined8 param_2)

{

  longlong *plVar1;

  undefined8 *puVar2;

  float fVar3;

  longlong lVar4;

  longlong lVar5;

  undefined8 uVar6;

  longlong lVar7;

  ulonglong uVar8;

  undefined8 *puVar9;

  int iVar10;

  ulonglong uVar11;

  longlong lVar12;

  int iVar13;

  longlong lVar14;

  float local_res18;

  undefined4 local_res1c;

  ulonglong local_res20;

  iVar10 = (int)(DAT_1403f3128 - DAT_1403f3120 >> 2);

  if (iVar10 != 0) {

    FUN_1400b4a10(param_2,&local_res18);

    local_res1c = FUN_1400b6170(param_2);

    fVar3 = DAT_14039ca34;

    local_res18 = local_res18 - (float)(iVar10 + -1) * DAT_14039ca34 * DAT_14039ca34;

    iVar13 = 0;

    if (0 < iVar10) {

      lVar4 = (longlong)iVar10;

      lVar14 = 0;

      plVar1 = (longlong *)(param_1 + 0xb8);

      do {

        lVar5 = FUN_1402c704c(0x80);

        if (lVar5 == 0) {

          uVar6 = 0;

        }

        else {

          uVar6 = FUN_14005c9b0(lVar5,*(undefined4 *)(DAT_1403f3120 + lVar14 * 4),

                                (float)iVar13 * fVar3 + local_res18,local_res1c,lVar4,lVar5);

        }

        puVar9 = *(undefined8 **)(param_1 + 0xc0);

        if (puVar9 == *(undefined8 **)(param_1 + 200)) {

          lVar5 = (longlong)puVar9 - *plVar1 >> 3;

          if (lVar5 == 0x1fffffffffffffff) {

                    /* WARNING: Subroutine does not return */

            FUN_14002f0d0();

          }

          local_res20 = lVar5 + 1;

          uVar8 = (longlong)*(undefined8 **)(param_1 + 200) - *plVar1 >> 3;

          if (0x1fffffffffffffff - (uVar8 >> 1) < uVar8) {

            uVar11 = 0x1fffffffffffffff;

          }

          else {

            uVar8 = (uVar8 >> 1) + uVar8;

            uVar11 = local_res20;

            if (local_res20 <= uVar8) {

              uVar11 = uVar8;

            }

            if (0x1fffffffffffffff < uVar11) {

                    /* WARNING: Subroutine does not return */

              FUN_140024090();

            }

          }

          lVar7 = FUN_1400285e0(uVar11 * 8);

          *(undefined8 *)(lVar7 + lVar5 * 8) = uVar6;

          puVar2 = (undefined8 *)*plVar1;

          if (puVar9 == *(undefined8 **)(param_1 + 0xc0)) {

            lVar12 = (longlong)*(undefined8 **)(param_1 + 0xc0) - (longlong)puVar2;

            lVar5 = lVar7;

            puVar9 = puVar2;

          }

          else {

            FUN_1402f8e20(lVar7,puVar2,(longlong)puVar9 - (longlong)puVar2);

            lVar12 = *(longlong *)(param_1 + 0xc0) - (longlong)puVar9;

            lVar5 = lVar7 + (lVar5 + 1) * 8;

          }

          FUN_1402f8e20(lVar5,puVar9,lVar12);

          FUN_140037380(plVar1,lVar7,local_res20,uVar11);

        }

        else {

          *puVar9 = uVar6;

          *(longlong *)(param_1 + 0xc0) = *(longlong *)(param_1 + 0xc0) + 8;

        }

        iVar13 = iVar13 + 1;

        lVar14 = lVar14 + 1;

      } while (lVar14 < lVar4);

    }

    if (DAT_1403f3120 != DAT_1403f3128) {

      DAT_1403f3128 = DAT_1403f3120;

    }

  }

  return;

}
```