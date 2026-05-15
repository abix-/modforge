// Address: 0x1402ce494
// Ghidra name: FUN_1402ce494
// ============ 0x1402ce494 FUN_1402ce494 (size=618) ============


ulonglong FUN_1402ce494(undefined1 *param_1,ulonglong param_2,ulonglong param_3,ulonglong param_4,

                       FILE *param_5)



{

  uint *puVar1;

  undefined1 auVar2 [16];

  undefined1 auVar3 [16];

  FILE *_File;

  int iVar4;

  undefined4 *puVar5;

  ulonglong uVar6;

  ulonglong uVar7;

  ulonglong uVar8;

  undefined1 *puVar9;

  uint uVar10;

  ulonglong uVar11;

  

  _File = param_5;

  if (param_3 == 0) {

    return 0;

  }

  if (param_4 == 0) {

    return 0;

  }

  if (param_1 == (undefined1 *)0x0) {

LAB_1402ce4cd:

    puVar5 = (undefined4 *)FUN_1402e68b0();

    *puVar5 = 0x16;

  }

  else {

    if ((param_5 == (FILE *)0x0) ||

       (auVar2._8_8_ = 0, auVar2._0_8_ = param_3,

       SUB168((ZEXT816(0) << 0x40 | ZEXT816(0xffffffffffffffff)) / auVar2,0) < param_4)) {

      if (param_2 != 0xffffffffffffffff) {

        FUN_1402f94c0(param_1,0,param_2);

      }

      if ((param_5 == (FILE *)0x0) ||

         (auVar3._8_8_ = 0, auVar3._0_8_ = param_3,

         SUB168((ZEXT816(0) << 0x40 | ZEXT816(0xffffffffffffffff)) / auVar3,0) < param_4))

      goto LAB_1402ce4cd;

    }

    if (((ulonglong)param_5->_base & 0x4c000000000) == 0) {

      uVar6 = 0x1000;

    }

    else {

      uVar6 = (ulonglong)(uint)param_5->_charbuf;

    }

    param_5._0_4_ = (uint)uVar6;

    uVar8 = param_3 * param_4;

    uVar7 = param_2;

    puVar9 = param_1;

    while( true ) {

      if (uVar8 == 0) {

        return param_4;

      }

      if (((ulonglong)_File->_base & 0x4c000000000) == 0) break;

      uVar10 = *(uint *)&_File->_base;

      if (uVar10 == 0) break;

      if ((int)uVar10 < 0) {

LAB_1402ce6e2:

        LOCK();

        puVar1 = (uint *)((longlong)&_File->_base + 4);

        *puVar1 = *puVar1 | 0x10;

        UNLOCK();

LAB_1402ce6ee:

        return (param_3 * param_4 - uVar8) / param_3;

      }

      if (uVar8 < (ulonglong)(longlong)(int)uVar10) {

        uVar10 = (uint)uVar8;

      }

      if (uVar7 < uVar10) goto LAB_1402ce6bf;

      if (uVar10 != 0) {

        if (puVar9 != (undefined1 *)0x0) {

          if (_File->_ptr != (char *)0x0) {

            FUN_1402f8e20(puVar9);

            goto LAB_1402ce5e4;

          }

          FUN_1402f94c0(puVar9,0,uVar7);

        }

        puVar5 = (undefined4 *)FUN_1402e68b0();

        *puVar5 = 0x16;

        FUN_1402cd454();

      }

LAB_1402ce5e4:

      *(uint *)&_File->_base = *(int *)&_File->_base - uVar10;

      uVar6 = (ulonglong)uVar10;

      _File->_ptr = _File->_ptr + uVar10;

LAB_1402ce5fd:

      uVar8 = uVar8 - uVar6;

      puVar9 = puVar9 + uVar6;

      uVar7 = uVar7 - uVar6;

LAB_1402ce6a4:

      uVar6 = (ulonglong)(uint)param_5;

    }

    if (uVar8 < uVar6) {

      iVar4 = FUN_1402e9de8(_File);

      if (iVar4 == -1) goto LAB_1402ce6ee;

      if (uVar7 != 0) {

        *puVar9 = (char)iVar4;

        uVar8 = uVar8 - 1;

        param_5._0_4_ = _File->_charbuf;

        puVar9 = puVar9 + 1;

        uVar7 = uVar7 - 1;

        goto LAB_1402ce6a4;

      }

    }

    else {

      uVar11 = uVar8 & 0xffffffff;

      if (0x7fffffff < uVar8) {

        uVar11 = 0x7fffffff;

      }

      if ((int)uVar6 != 0) {

        uVar11 = (ulonglong)(uint)((int)uVar11 - (int)(uVar11 % uVar6));

      }

      if (uVar11 <= uVar7) {

        *(undefined4 *)&_File->_base = 0;

        _File->_ptr = *(char **)&_File->_cnt;

        iVar4 = _fileno(_File);

        iVar4 = FUN_1402ea824(iVar4,puVar9,uVar11);

        if (iVar4 == 0) {

          LOCK();

          puVar1 = (uint *)((longlong)&_File->_base + 4);

          *puVar1 = *puVar1 | 8;

          UNLOCK();

          goto LAB_1402ce6ee;

        }

        if (-1 < iVar4) {

          uVar6 = (ulonglong)iVar4;

          goto LAB_1402ce5fd;

        }

        goto LAB_1402ce6e2;

      }

    }

LAB_1402ce6bf:

    if (param_2 != 0xffffffffffffffff) {

      FUN_1402f94c0(param_1,0,param_2);

    }

    puVar5 = (undefined4 *)FUN_1402e68b0();

    *puVar5 = 0x22;

  }

  FUN_1402cd454();

  return 0;

}




