// Address: 0x1402e64c4
// Ghidra name: FUN_1402e64c4
// ============ 0x1402e64c4 FUN_1402e64c4 (size=450) ============


ulonglong FUN_1402e64c4(ulonglong param_1,ulonglong param_2)



{

  bool bVar1;

  bool bVar2;

  BOOL BVar3;

  DWORD DVar4;

  DWORD *pDVar5;

  _func_void_int **pp_Var6;

  ulonglong uVar7;

  longlong *plVar8;

  longlong lVar9;

  byte bVar10;

  uint uVar11;

  ulonglong *puVar12;

  ulonglong *puVar13;

  ulonglong *puVar14;

  ulonglong uVar15;

  

  uVar11 = (uint)param_1;

  uVar7 = param_1 & 0xffffffff;

  if (1 < param_2 - 3) {

    if ((uVar11 < 0x17) && ((0x608044U >> (uVar11 & 0x1f) & 1) != 0)) {

      bVar2 = false;

      uVar15 = 0;

      __acrt_lock(3);

      if ((uVar11 == 2) || (uVar11 == 0x15)) {

        bVar1 = true;

      }

      else {

        bVar1 = false;

      }

      if ((bVar1) && (DAT_1403fed3c == '\0')) {

        BVar3 = SetConsoleCtrlHandler(FUN_1402e6114,1);

        if (BVar3 == 0) {

          DVar4 = GetLastError();

          pDVar5 = (DWORD *)FUN_1402e688c();

          *pDVar5 = DVar4;

          bVar2 = true;

        }

        else {

          DAT_1403fed3c = '\x01';

        }

      }

      pp_Var6 = get_global_action_nolock(uVar11);

      if (pp_Var6 != (_func_void_int **)0x0) {

        bVar10 = (byte)DAT_1403e8b00 & 0x3f;

        uVar15 = (DAT_1403e8b00 ^ (ulonglong)*pp_Var6) >> bVar10 |

                 (DAT_1403e8b00 ^ (ulonglong)*pp_Var6) << 0x40 - bVar10;

        if (param_2 != 2) {

          bVar10 = 0x40 - bVar10 & 0x3f;

          *pp_Var6 = (_func_void_int *)

                     ((param_2 >> bVar10 | param_2 << 0x40 - bVar10) ^ DAT_1403e8b00);

        }

      }

      __acrt_unlock(3);

      param_1 = uVar7;

      if (!bVar2) {

        return uVar15;

      }

    }

    else if ((uVar11 < 0xc) &&

            (((0x910U >> (uVar11 & 0x1f) & 1) != 0 &&

             (plVar8 = (longlong *)FUN_1402e86c4(), param_1 = uVar7, plVar8 != (longlong *)0x0)))) {

      if ((undefined *)*plVar8 == &DAT_14038cfa0) {

        lVar9 = _malloc_base(DAT_14038d068);

        *plVar8 = lVar9;

        if (lVar9 == 0) goto LAB_1402e65bb;

        FUN_1402f8e20(lVar9,&DAT_14038cfa0,DAT_14038d068);

      }

      puVar12 = (ulonglong *)*plVar8;

      puVar14 = puVar12 + DAT_14038d060 * 2;

      for (; puVar12 != puVar14; puVar12 = puVar12 + 2) {

        if (*(uint *)((longlong)puVar12 + 4) == uVar11) goto LAB_1402e664c;

      }

      puVar12 = (ulonglong *)0x0;

LAB_1402e664c:

      if (puVar12 != (ulonglong *)0x0) {

        puVar13 = puVar12 + 1;

        uVar7 = *puVar13;

        if (param_2 == 2) {

          return uVar7;

        }

        while( true ) {

          if (puVar12 == puVar14) {

            return uVar7;

          }

          if (*(uint *)((longlong)puVar13 + -4) != uVar11) break;

          *puVar13 = param_2;

          puVar12 = puVar13 + 1;

          puVar13 = puVar13 + 2;

        }

        return uVar7;

      }

    }

  }

LAB_1402e65bb:

  uVar7 = FUN_1402e61e4(param_1);

  return uVar7;

}




