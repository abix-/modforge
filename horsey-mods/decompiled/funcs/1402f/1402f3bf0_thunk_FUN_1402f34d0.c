// Address: 0x1402f3bf0
// Ghidra name: thunk_FUN_1402f34d0
// ============ 0x1402f3bf0 thunk_FUN_1402f34d0 (size=5) ============


int thunk_FUN_1402f34d0(longlong *param_1,longlong *param_2)



{

  undefined4 *puVar1;

  longlong lVar2;

  int iVar3;

  longlong *plVar4;

  longlong *plVar5;

  longlong lVar6;

  longlong *plVar7;

  longlong lVar8;

  longlong lStackX_10;

  longlong lStackX_18;

  longlong lStackX_20;

  longlong *plStack_58;

  longlong *plStack_50;

  undefined8 uStack_48;

  longlong lVar9;

  

  if (param_2 == (longlong *)0x0) {

    puVar1 = (undefined4 *)FUN_1402e68b0();

    iVar3 = 0x16;

    *puVar1 = 0x16;

    FUN_1402cd454();

  }

  else {

    *param_2 = 0;

    lVar6 = *param_1;

    plStack_58 = (longlong *)0x0;

    plStack_50 = (longlong *)0x0;

    uStack_48 = 0;

    while (plVar4 = plStack_50, plVar5 = plStack_58, lVar6 != 0) {

      lStackX_10 = CONCAT53(lStackX_10._3_5_,0x3f2a);

      lVar6 = FUN_1402e1190(lVar6,&lStackX_10);

      if (lVar6 == 0) {

        iVar3 = FUN_1402f370c(*param_1,0,0,&plStack_58);

        plVar5 = plStack_58;

        if (iVar3 != 0) {

          plVar4 = plStack_58;

          if (plStack_58 != plStack_50) {

            do {

              FUN_1402e9a80(*plVar4);

              plVar4 = plVar4 + 1;

            } while (plVar4 != plStack_50);

          }

          goto LAB_1402f361f;

        }

      }

      else {

        iVar3 = FUN_1402f3890(*param_1,lVar6,&plStack_58);

        plVar5 = plStack_58;

        if (iVar3 != 0) {

          plVar4 = plStack_58;

          if (plStack_58 != plStack_50) {

            do {

              FUN_1402e9a80(*plVar4);

              plVar4 = plVar4 + 1;

            } while (plVar4 != plStack_50);

          }

          goto LAB_1402f361f;

        }

      }

      param_1 = param_1 + 1;

      lVar6 = *param_1;

    }

    lVar6 = ((longlong)plStack_50 - (longlong)plStack_58 >> 3) + 1;

    lStackX_18 = 0;

    for (plVar7 = plStack_58; plVar7 != plStack_50; plVar7 = plVar7 + 1) {

      lVar2 = -1;

      do {

        lVar2 = lVar2 + 1;

      } while (*(char *)(*plVar7 + lVar2) != '\0');

      lStackX_18 = lStackX_18 + 1 + lVar2;

    }

    lVar2 = __acrt_allocate_buffer_for_argv(lVar6,lStackX_18,1);

    if (lVar2 == 0) {

      FUN_1402e9a80(0);

      for (plVar7 = plVar5; plVar7 != plVar4; plVar7 = plVar7 + 1) {

        FUN_1402e9a80(*plVar7);

      }

      iVar3 = -1;

LAB_1402f361f:

      FUN_1402e9a80(plVar5);

    }

    else {

      lVar6 = lVar2 + lVar6 * 8;

      lStackX_20 = lVar6;

      if (plVar5 != plVar4) {

        lStackX_10 = lVar2 - (longlong)plVar5;

        plVar7 = plVar5;

        do {

          lVar8 = -1;

          do {

            lVar9 = lVar8;

            lVar8 = lVar9 + 1;

          } while (*(char *)(*plVar7 + lVar8) != '\0');

          iVar3 = FUN_1402f80c0();

          if (iVar3 != 0) {

                    /* WARNING: Subroutine does not return */

            _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

          }

          *(longlong *)(lStackX_10 + (longlong)plVar7) = lVar6;

          lVar6 = lVar6 + lVar9 + 2;

          plVar7 = plVar7 + 1;

        } while (plVar7 != plVar4);

      }

      *param_2 = lVar2;

      FUN_1402e9a80(0);

      for (plVar7 = plVar5; plVar7 != plVar4; plVar7 = plVar7 + 1) {

        FUN_1402e9a80(*plVar7);

      }

      FUN_1402e9a80(plVar5);

      iVar3 = 0;

    }

  }

  return iVar3;

}




