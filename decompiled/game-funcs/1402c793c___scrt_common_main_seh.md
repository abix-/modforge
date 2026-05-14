# `__scrt_common_main_seh` @ 0x1402c793c

**Size**: 343 bytes
**Role**: _unclassified - needs manual reading_
**Pattern category**: `unclassified`

**Game callers**: (none - entry point, vendor-called, or only called by vendor)

**Game callees** (3): [`FUN_1400c35b0`](1400c35b0_FUN_1400c35b0.md), [`FUN_1402da20c`](1402da20c_FUN_1402da20c.md), [`FUN_1402da254`](1402da254_FUN_1402da254.md)

**Vendor callees**: 10 (SDL/CRT/etc, not shown)

## Decompiled

```c
/* Library Function - Single Match

    int __cdecl __scrt_common_main_seh(void)

   Library: Visual Studio 2019 Release */

int __cdecl __scrt_common_main_seh(void)

{

  bool bVar1;

  char cVar2;

  undefined1 uVar3;

  undefined2 uVar4;

  int iVar5;

  uint uVar6;

  longlong *plVar7;

  undefined8 uVar8;

  ulonglong unaff_RBX;

  cVar2 = FUN_1402c721c(1);

  if (cVar2 == '\0') {

    FUN_1402c7c38(7);

  }

  else {

    bVar1 = false;

    uVar3 = __scrt_acquire_startup_lock();

    unaff_RBX = CONCAT71((int7)(unaff_RBX >> 8),uVar3);

    if (DAT_1403fe628 != 1) {

      if (DAT_1403fe628 == 0) {

        DAT_1403fe628 = 1;

        iVar5 = FUN_1402e7e80(&DAT_140303080,&DAT_1403030c8);

        if (iVar5 != 0) {

          return 0xff;

        }

        FUN_1402e7e48(&DAT_140302c90,&DAT_140303078);

        DAT_1403fe628 = 2;

      }

      else {

        bVar1 = true;

      }

      __scrt_release_startup_lock(uVar3);

      plVar7 = (longlong *)FUN_1402c7f80();

      if ((*plVar7 != 0) && (cVar2 = FUN_1402c72e4(plVar7), cVar2 != '\0')) {

        (*(code *)PTR__guard_dispatch_icall_140302c68)(0,2);

      }

      plVar7 = (longlong *)FUN_1402c7f88();

      if ((*plVar7 != 0) && (cVar2 = FUN_1402c72e4(plVar7), cVar2 != '\0')) {

        FUN_1402da218(*plVar7);

      }

      uVar4 = __scrt_get_show_window_mode();

      uVar8 = FUN_1402e7dd4();

      uVar6 = FUN_1400c35b0(&IMAGE_DOS_HEADER_140000000,0,uVar8,uVar4);

      unaff_RBX = (ulonglong)uVar6;

      cVar2 = FUN_1402c7dc8();

      if (cVar2 != '\0') {

        if (!bVar1) {

          _cexit();

        }

        __scrt_uninitialize_crt(1,0);

        return uVar6;

      }

      goto LAB_1402c7a9d;

    }

  }

  FUN_1402c7c38(7);

LAB_1402c7a9d:

  FUN_1402da254(unaff_RBX & 0xffffffff);

                    /* WARNING: Subroutine does not return */

  FUN_1402da20c(unaff_RBX & 0xffffffff);

}
```