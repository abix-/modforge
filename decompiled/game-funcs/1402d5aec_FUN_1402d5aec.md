# `FUN_1402d5aec` @ 0x1402d5aec

**Size**: 1133 bytes
**Role**: `iterates_logic` - Large loop-containing function  _(evidence: contains a loop)_
**Pattern category**: `iterates_logic`

**Game callers** (3): [`FUN_1402d4650`](1402d4650_FUN_1402d4650.md), [`FUN_1402d50cc`](1402d50cc_FUN_1402d50cc.md), [`FUN_1402d5aec`](1402d5aec_FUN_1402d5aec.md)

**Game callees** (12): [`FUN_1402d285c`](1402d285c_FUN_1402d285c.md), [`FUN_1402d2c6c`](1402d2c6c_FUN_1402d2c6c.md), [`FUN_1402d307c`](1402d307c_FUN_1402d307c.md), [`FUN_1402d5aec`](1402d5aec_FUN_1402d5aec.md), [`FUN_1402d6ad0`](1402d6ad0_FUN_1402d6ad0.md), [`FUN_1402d6bc0`](1402d6bc0_FUN_1402d6bc0.md), [`FUN_1402d7098`](1402d7098_FUN_1402d7098.md), [`FUN_1402d7230`](1402d7230_FUN_1402d7230.md), [`FUN_1402d72e8`](1402d72e8_FUN_1402d72e8.md), [`FUN_1402d74e0`](1402d74e0_FUN_1402d74e0.md)
  ... +2 more

**Vendor callees**: 0 (SDL/CRT/etc, not shown)

## Decompiled

```c
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 FUN_1402d5aec(longlong param_1)

{

  int *piVar1;

  string_output_adapter<char> *this;

  undefined2 uVar2;

  uint uVar3;

  longlong lVar4;

  bool bVar5;

  char cVar6;

  int iVar7;

  undefined8 uVar8;

  int iVar9;

  undefined1 uVar10;

  longlong lVar11;

  int iVar12;

  undefined2 *puVar13;

  undefined1 auStackY_88 [32];

  undefined4 local_48;

  char local_40 [8];

  ulonglong local_38;

  local_38 = DAT_1403e8b00 ^ (ulonglong)auStackY_88;

  cVar6 = *(char *)(param_1 + 0x39);

  uVar10 = 0x78;

  if (cVar6 < 'e') {

    if (cVar6 == 'd') {

LAB_1402d5bbe:

      *(uint *)(param_1 + 0x28) = *(uint *)(param_1 + 0x28) | 0x10;

LAB_1402d5bc2:

      cVar6 = FUN_1402d2c6c(param_1,0);

    }

    else if (cVar6 < 'T') {

      if (cVar6 == 'S') {

LAB_1402d5c01:

        cVar6 = FUN_1402d72e8();

      }

      else {

        if (cVar6 != 'A') {

          if (cVar6 == 'C') {

LAB_1402d5b81:

            cVar6 = FUN_1402d7098(param_1,0);

            goto LAB_1402d5c1d;

          }

          if (((cVar6 != 'E') && (cVar6 != 'F')) && (cVar6 != 'G')) {

            return 0;

          }

        }

LAB_1402d5b5b:

        cVar6 = FUN_1402d6bc0();

      }

    }

    else {

      if (cVar6 == 'X') goto LAB_1402d5c16;

      if (cVar6 != 'Z') {

        if (cVar6 != 'a') {

          if (cVar6 != 'c') {

            return 0;

          }

          goto LAB_1402d5b81;

        }

        goto LAB_1402d5b5b;

      }

      cVar6 = FUN_1402d6ad0();

    }

  }

  else if (cVar6 < 'p') {

    if (cVar6 == 'o') {

      if ((*(uint *)(param_1 + 0x28) >> 5 & 1) != 0) {

        *(uint *)(param_1 + 0x28) = *(uint *)(param_1 + 0x28) | 0x80;

      }

      cVar6 = FUN_1402d285c(param_1,0);

    }

    else {

      if (((cVar6 == 'e') || (cVar6 == 'f')) || (cVar6 == 'g')) goto LAB_1402d5b5b;

      if (cVar6 == 'i') goto LAB_1402d5bbe;

      if (cVar6 != 'n') {

        return 0;

      }

      cVar6 = FUN_1402d7230();

    }

  }

  else {

    if (cVar6 == 'p') {

      *(undefined4 *)(param_1 + 0x30) = 0x10;

      *(undefined4 *)(param_1 + 0x34) = 0xb;

LAB_1402d5c16:

      uVar8 = CONCAT71((uint7)(uint3)(cVar6 >> 7),1);

    }

    else {

      if (cVar6 == 's') goto LAB_1402d5c01;

      if (cVar6 == 'u') goto LAB_1402d5bc2;

      if (cVar6 != 'x') {

        return 0;

      }

      uVar8 = 0;

    }

    cVar6 = FUN_1402d307c(param_1,uVar8);

  }

LAB_1402d5c1d:

  if (cVar6 == '\0') {

    return 0;

  }

  if (*(char *)(param_1 + 0x38) != '\0') {

    return 1;

  }

  local_48 = (uint)local_48._3_1_ << 0x18;

  lVar11 = 0;

  uVar3 = *(uint *)(param_1 + 0x28);

  if ((uVar3 >> 4 & 1) != 0) {

    if ((uVar3 >> 6 & 1) == 0) {

      if ((*(byte *)(param_1 + 0x28) & 1) == 0) {

        if ((uVar3 >> 1 & 1) == 0) goto LAB_1402d5c77;

        local_48 = CONCAT31(local_48._1_3_,0x20);

      }

      else {

        local_48 = CONCAT31(local_48._1_3_,0x2b);

      }

    }

    else {

      local_48 = CONCAT31(local_48._1_3_,0x2d);

    }

    lVar11 = 1;

  }

LAB_1402d5c77:

  cVar6 = *(char *)(param_1 + 0x39);

  if (((cVar6 + 0xa8U & 0xdf) == 0) && ((uVar3 >> 5 & 1) != 0)) {

    bVar5 = true;

  }

  else {

    bVar5 = false;

  }

  if ((bVar5) || ((cVar6 + 0xbfU & 0xdf) == 0)) {

    *(undefined1 *)((longlong)&local_48 + lVar11) = 0x30;

    if ((cVar6 == 'X') || (cVar6 == 'A')) {

      uVar10 = 0x58;

    }

    *(undefined1 *)((longlong)&local_48 + lVar11 + 1) = uVar10;

    lVar11 = lVar11 + 2;

  }

  iVar9 = (*(int *)(param_1 + 0x2c) - (int)lVar11) - *(int *)(param_1 + 0x48);

  if (((uVar3 & 0xc) == 0) && (iVar12 = 0, 0 < iVar9)) {

    iVar7 = *(int *)(param_1 + 0x20);

    do {

      lVar4 = *(longlong *)(param_1 + 0x460);

      if (*(longlong *)(lVar4 + 0x10) == *(longlong *)(lVar4 + 8)) {

        if (*(char *)(lVar4 + 0x18) == '\0') {

          iVar7 = -1;

        }

        else {

          iVar7 = iVar7 + 1;

        }

        *(int *)(param_1 + 0x20) = iVar7;

      }

      else {

        *(int *)(param_1 + 0x20) = iVar7 + 1;

        *(longlong *)(lVar4 + 0x10) = *(longlong *)(lVar4 + 0x10) + 1;

        *(undefined1 *)**(undefined8 **)(param_1 + 0x460) = 0x20;

        **(longlong **)(param_1 + 0x460) = **(longlong **)(param_1 + 0x460) + 1;

      }

      iVar7 = *(int *)(param_1 + 0x20);

    } while ((iVar7 != -1) && (iVar12 = iVar12 + 1, iVar12 < iVar9));

  }

  this = (string_output_adapter<char> *)(param_1 + 0x460);

  piVar1 = (int *)(param_1 + 0x20);

  __crt_stdio_output::string_output_adapter<char>::write_string

            (this,(char *)&local_48,(int)lVar11,piVar1,*(__crt_deferred_errno_cache **)(param_1 + 8)

            );

  if (((*(uint *)(param_1 + 0x28) >> 3 & 1) != 0) &&

     (((*(uint *)(param_1 + 0x28) >> 2 & 1) == 0 && (iVar12 = 0, 0 < iVar9)))) {

    iVar7 = *piVar1;

    do {

      lVar11 = *(longlong *)this;

      if (*(longlong *)(lVar11 + 0x10) == *(longlong *)(lVar11 + 8)) {

        if (*(char *)(lVar11 + 0x18) == '\0') {

          iVar7 = -1;

        }

        else {

          iVar7 = iVar7 + 1;

        }

        *piVar1 = iVar7;

      }

      else {

        *piVar1 = iVar7 + 1;

        *(longlong *)(lVar11 + 0x10) = *(longlong *)(lVar11 + 0x10) + 1;

        *(undefined1 *)**(undefined8 **)this = 0x30;

        **(longlong **)this = **(longlong **)this + 1;

      }

      iVar7 = *piVar1;

    } while ((iVar7 != -1) && (iVar12 = iVar12 + 1, iVar12 < iVar9));

  }

  if ((*(char *)(param_1 + 0x4c) == '\0') || (*(int *)(param_1 + 0x48) < 1)) {

    __crt_stdio_output::string_output_adapter<char>::write_string

              (this,*(char **)(param_1 + 0x40),*(int *)(param_1 + 0x48),piVar1,

               *(__crt_deferred_errno_cache **)(param_1 + 8));

  }

  else {

    lVar11 = *(longlong *)(param_1 + 8);

    if (*(char *)(lVar11 + 0x28) == '\0') {

      FUN_1402d74e0(lVar11);

    }

    puVar13 = *(undefined2 **)(param_1 + 0x40);

    iVar12 = 0;

    if (*(int *)(*(longlong *)(lVar11 + 0x18) + 0xc) == 0xfde9) {

      local_40[0] = '\0';

      local_40[1] = '\0';

      local_40[2] = '\0';

      local_40[3] = '\0';

      local_40[4] = '\0';

      local_40[5] = '\0';

      local_40[6] = '\0';

      local_40[7] = '\0';

      if (*(int *)(param_1 + 0x48) != 0) {

        do {

          uVar2 = *puVar13;

          puVar13 = puVar13 + 1;

          lVar11 = FUN_1402f0358(&local_48,uVar2,local_40);

          if (lVar11 == -1) goto LAB_1402d5e42;

          __crt_stdio_output::string_output_adapter<char>::write_string

                    (this,(char *)&local_48,(int)lVar11,piVar1,

                     *(__crt_deferred_errno_cache **)(param_1 + 8));

          iVar12 = iVar12 + 1;

        } while (iVar12 != *(int *)(param_1 + 0x48));

      }

    }

    else if (*(int *)(param_1 + 0x48) != 0) {

      do {

        local_48 = 0;

        iVar7 = FUN_1402efd94(&local_48,local_40,6);

        if ((iVar7 != 0) || (local_48 == 0)) goto LAB_1402d5e42;

        __crt_stdio_output::string_output_adapter<char>::write_string

                  (this,local_40,local_48,piVar1,*(__crt_deferred_errno_cache **)(param_1 + 8));

        iVar12 = iVar12 + 1;

      } while (iVar12 != *(int *)(param_1 + 0x48));

    }

  }

LAB_1402d5ec0:

  iVar12 = *(int *)(param_1 + 0x20);

  if ((-1 < iVar12) && ((*(uint *)(param_1 + 0x28) >> 2 & 1) != 0)) {

    piVar1 = (int *)(param_1 + 0x20);

    iVar7 = 0;

    if (0 < iVar9) {

      do {

        lVar11 = *(longlong *)(param_1 + 0x460);

        if (*(longlong *)(lVar11 + 0x10) == *(longlong *)(lVar11 + 8)) {

          if (*(char *)(lVar11 + 0x18) == '\0') {

            iVar12 = -1;

          }

          else {

            iVar12 = iVar12 + 1;

          }

          *piVar1 = iVar12;

        }

        else {

          *piVar1 = iVar12 + 1;

          *(longlong *)(lVar11 + 0x10) = *(longlong *)(lVar11 + 0x10) + 1;

          *(undefined1 *)**(undefined8 **)(param_1 + 0x460) = 0x20;

          **(longlong **)(param_1 + 0x460) = **(longlong **)(param_1 + 0x460) + 1;

        }

        iVar12 = *piVar1;

      } while ((iVar12 != -1) && (iVar7 = iVar7 + 1, iVar7 < iVar9));

    }

  }

  return 1;

LAB_1402d5e42:

  *piVar1 = -1;

  goto LAB_1402d5ec0;

}
```