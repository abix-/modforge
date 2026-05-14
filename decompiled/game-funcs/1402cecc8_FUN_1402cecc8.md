# `FUN_1402cecc8` @ 0x1402cecc8

**Size**: 347 bytes
**Role**: _unclassified - needs manual reading_
**Pattern category**: `unclassified`

**Game callers** (2): [`FUN_1402ceb78`](1402ceb78_FUN_1402ceb78.md), [`FUN_1402cecc8`](1402cecc8_FUN_1402cecc8.md)

**Game callees** (2): [`FUN_1402cecc8`](1402cecc8_FUN_1402cecc8.md), [`FUN_1402cefac`](1402cefac_FUN_1402cefac.md)

**Vendor callees**: 0 (SDL/CRT/etc, not shown)

## Decompiled

```c
longlong FUN_1402cecc8(FILE *param_1,longlong param_2,longlong param_3,undefined8 param_4)

{

  char cVar1;

  uint uVar2;

  longlong lVar3;

  ulonglong uVar4;

  char *pcVar5;

  char *pcVar6;

  longlong lVar7;

  bool bVar8;

  uVar2 = _fileno(param_1);

  uVar4 = (ulonglong)(uVar2 & 0x3f);

  cVar1 = *(char *)((&DAT_1403ff160)[(longlong)(int)uVar2 >> 6] + 0x39 + uVar4 * 0x48);

  lVar7 = (ulonglong)(cVar1 == '\x01') + 1;

  if (*(int *)&param_1->_base != 0) {

    pcVar6 = param_1->_ptr + ((longlong)*(int *)&param_1->_base - *(longlong *)&param_1->_cnt);

    if (*(char *)((&DAT_1403ff160)[(longlong)(int)uVar2 >> 6] + 0x38 + uVar4 * 0x48) < '\0') {

      lVar3 = thunk_FUN_1402eada0(uVar2,0,2,param_4);

      if (lVar3 == param_2) {

        lVar3 = FUN_1402cefac(*(longlong *)&param_1->_cnt,pcVar6 + *(longlong *)&param_1->_cnt,cVar1

                             );

        bVar8 = (*(uint *)((longlong)&param_1->_base + 4) >> 5 & 1) == 0;

        pcVar6 = pcVar6 + lVar3;

      }

      else {

        lVar3 = thunk_FUN_1402eada0(uVar2,param_2,0,param_4);

        if (lVar3 == -1) {

          return -1;

        }

        pcVar5 = (char *)0x200;

        if (((0x200 < (longlong)pcVar6) ||

            ((*(uint *)((longlong)&param_1->_base + 4) >> 6 & 1) == 0)) ||

           ((*(uint *)((longlong)&param_1->_base + 4) >> 8 & 1) != 0)) {

          pcVar5 = (char *)(longlong)param_1->_charbuf;

        }

        bVar8 = (*(byte *)((&DAT_1403ff160)[(longlong)(int)uVar2 >> 6] + 0x38 + uVar4 * 0x48) & 4)

                == 0;

        pcVar6 = pcVar5;

      }

      if (!bVar8) {

        pcVar6 = pcVar6 + (ulonglong)((byte)(cVar1 - 1U) < 2) + 1;

      }

    }

    param_2 = (param_3 / lVar7 - (longlong)pcVar6 / lVar7) + param_2;

  }

  return param_2;

}
```