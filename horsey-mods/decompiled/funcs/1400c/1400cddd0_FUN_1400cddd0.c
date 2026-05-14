// Address: 0x1400cddd0
// Ghidra name: FUN_1400cddd0
// ============ 0x1400cddd0 FUN_1400cddd0 (size=1833) ============


void FUN_1400cddd0(longlong param_1)



{

  longlong **pplVar1;

  char cVar2;

  longlong lVar3;

  longlong *plVar4;

  ulonglong uVar5;

  longlong lVar6;

  longlong *plVar7;

  longlong *plVar8;

  ulonglong uVar9;

  longlong *plVar10;

  longlong lVar11;

  longlong lVar12;

  ulonglong uVar13;

  int local_res10;

  undefined8 local_res18;

  longlong local_res20;

  longlong local_88;

  longlong *local_80;

  longlong *plStack_78;

  longlong *local_70;

  longlong *local_68;

  longlong *plStack_60;

  longlong *local_58;

  

  if (*(char *)(param_1 + 0x234) != '\0') {

    if (*(longlong *)(DAT_1403f4e00 + 0x130) != *(longlong *)(DAT_1403f4e00 + 0x138)) {

      *(longlong *)(DAT_1403f4e00 + 0x138) = *(longlong *)(DAT_1403f4e00 + 0x130);

    }

    local_68 = (longlong *)0x0;

    plStack_60 = (longlong *)0x0;

    local_58 = (longlong *)0x0;

    local_res10 = 0;

    pplVar1 = (longlong **)(param_1 + 0x130);

    plVar7 = *pplVar1;

    if (*(longlong *)(param_1 + 0x138) - (longlong)plVar7 >> 3 != 0) {

      local_88 = 0;

      do {

        lVar6 = *(longlong *)(local_88 + (longlong)plVar7);

        local_res20 = lVar6;

        FUN_1400b4a10(lVar6,&local_res18);

        cVar2 = FUN_1400c56f0((undefined4)local_res18,local_res18._4_4_,

                              *(undefined8 *)(param_1 + 0x78),0);

        plVar7 = plStack_60;

        if (cVar2 == '\0') {

          if ((*(char *)(param_1 + 0x90) == '\0') && (*(char *)(lVar6 + 0x204) != '\0')) {

            FUN_1400b6610(lVar6,lVar6 + 0x1d4);

            goto LAB_1400cdea5;

          }

          if (plStack_60 == local_58) {

            lVar11 = (longlong)plStack_60 - (longlong)local_68 >> 3;

            if (lVar11 == 0x1fffffffffffffff) {

                    /* WARNING: Subroutine does not return */

              FUN_14002f0d0();

            }

            uVar9 = lVar11 + 1;

            uVar5 = (longlong)local_58 - (longlong)local_68 >> 3;

            if (0x1fffffffffffffff - (uVar5 >> 1) < uVar5) {

              uVar13 = 0x1fffffffffffffff;

            }

            else {

              uVar5 = uVar5 + (uVar5 >> 1);

              uVar13 = uVar9;

              if (uVar9 <= uVar5) {

                uVar13 = uVar5;

              }

              if (0x1fffffffffffffff < uVar13) {

                    /* WARNING: Subroutine does not return */

                FUN_140024090();

              }

            }

            plVar4 = (longlong *)FUN_1400285e0(uVar13 * 8);

            plVar4[lVar11] = lVar6;

            plVar10 = plVar4;

            plVar8 = local_68;

            if (plVar7 != plStack_60) {

              FUN_1402f8e20(plVar4,local_68,(longlong)plVar7 - (longlong)local_68);

              plVar10 = plVar4 + lVar11 + 1;

              plVar8 = plVar7;

            }

            FUN_1402f8e20(plVar10,plVar8);

            if (local_68 != (longlong *)0x0) {

              if ((0xfff < ((longlong)local_58 - (longlong)local_68 & 0xfffffffffffffff8U)) &&

                 (0x1f < (ulonglong)((longlong)local_68 + (-8 - local_68[-1])))) {

                    /* WARNING: Subroutine does not return */

                _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

              }

              FUN_1402c7088();

            }

            plStack_60 = plVar4 + uVar9;

            local_58 = plVar4 + uVar13;

            local_68 = plVar4;

          }

          else {

            *plStack_60 = lVar6;

            plStack_60 = plStack_60 + 1;

          }

        }

        else {

          *(undefined1 *)(lVar6 + 0x204) = 1;

          if (lVar6 == *(longlong *)(param_1 + 0x148)) {

            *(undefined8 *)(param_1 + 0x148) = 0;

          }

LAB_1400cdea5:

          lVar11 = DAT_1403f4e00;

          plVar7 = *(longlong **)(DAT_1403f4e00 + 0x138);

          if (plVar7 == *(longlong **)(DAT_1403f4e00 + 0x140)) {

            FUN_140030680(DAT_1403f4e00 + 0x130,plVar7,&local_res20);

          }

          else {

            *plVar7 = lVar6;

            *(longlong *)(lVar11 + 0x138) = *(longlong *)(lVar11 + 0x138) + 8;

          }

        }

        local_res10 = local_res10 + 1;

        local_88 = local_88 + 8;

        plVar7 = *pplVar1;

      } while ((ulonglong)(longlong)local_res10 <

               (ulonglong)(*(longlong *)(param_1 + 0x138) - (longlong)plVar7 >> 3));

    }

    plVar7 = local_68;

    if (*(longlong *)(DAT_1403f4e00 + 0x130) != *(longlong *)(DAT_1403f4e00 + 0x138)) {

      *(undefined1 *)(DAT_1403f4e00 + 0x262) = 1;

    }

    if (pplVar1 != &local_68) {

      uVar9 = (longlong)plStack_60 - (longlong)local_68 >> 3;

      plVar10 = *pplVar1;

      if ((ulonglong)(*(longlong *)(param_1 + 0x140) - (longlong)plVar10 >> 3) < uVar9) {

        FUN_1400d8d00(pplVar1,uVar9);

        plVar10 = *pplVar1;

      }

      else {

        uVar5 = *(longlong *)(param_1 + 0x138) - (longlong)plVar10 >> 3;

        if (uVar5 < uVar9) {

          FUN_1402f8e20(plVar10,local_68,uVar5 * 8);

          plVar10 = *(longlong **)(param_1 + 0x138);

          uVar9 = uVar9 - uVar5;

          plVar7 = plVar7 + uVar5;

        }

      }

      FUN_1402f8e20(plVar10,plVar7);

      *(longlong **)(param_1 + 0x138) = plVar10 + uVar9;

    }

    local_80 = (longlong *)0x0;

    plStack_78 = (longlong *)0x0;

    local_70 = (longlong *)0x0;

    if (*(longlong *)(DAT_1403f4e00 + 0xb8) != *(longlong *)(DAT_1403f4e00 + 0xc0)) {

      *(longlong *)(DAT_1403f4e00 + 0xc0) = *(longlong *)(DAT_1403f4e00 + 0xb8);

    }

    local_res10 = 0;

    lVar6 = *(longlong *)(param_1 + 0xb8);

    if (*(longlong *)(param_1 + 0xc0) - lVar6 >> 3 != 0) {

      local_res18 = 0;

      do {

        lVar6 = *(longlong *)(local_res18 + lVar6);

        cVar2 = FUN_1400c56f0(*(undefined4 *)(lVar6 + 0x28),*(undefined4 *)(lVar6 + 0x2c),

                              *(undefined8 *)(param_1 + 0x78),0);

        plVar7 = plStack_78;

        lVar11 = DAT_1403f4e00;

        if (cVar2 == '\0') {

          if (plStack_78 == local_70) {

            lVar11 = (longlong)plStack_78 - (longlong)local_80 >> 3;

            if (lVar11 == 0x1fffffffffffffff) {

LAB_1400ce4e2:

                    /* WARNING: Subroutine does not return */

              FUN_14002f0d0();

            }

            uVar9 = lVar11 + 1;

            uVar5 = (longlong)local_70 - (longlong)local_80 >> 3;

            if (0x1fffffffffffffff - (uVar5 >> 1) < uVar5) {

              uVar13 = 0x1fffffffffffffff;

            }

            else {

              uVar5 = (uVar5 >> 1) + uVar5;

              uVar13 = uVar9;

              if (uVar9 <= uVar5) {

                uVar13 = uVar5;

              }

              if (0x1fffffffffffffff < uVar13) {

LAB_1400ce4dc:

                    /* WARNING: Subroutine does not return */

                FUN_140024090();

              }

            }

            plVar4 = (longlong *)FUN_1400285e0(uVar13 * 8);

            plVar4[lVar11] = lVar6;

            plVar10 = plVar4;

            plVar8 = local_80;

            if (plVar7 != plStack_78) {

              FUN_1402f8e20(plVar4,local_80,(longlong)plVar7 - (longlong)local_80);

              plVar10 = plVar4 + lVar11 + 1;

              plVar8 = plVar7;

            }

            FUN_1402f8e20(plVar10,plVar8);

            if (local_80 != (longlong *)0x0) {

              if ((0xfff < ((longlong)local_70 - (longlong)local_80 & 0xfffffffffffffff8U)) &&

                 (0x1f < (ulonglong)((longlong)local_80 + (-8 - local_80[-1])))) {

                    /* WARNING: Subroutine does not return */

                _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

              }

              FUN_1402c7088();

            }

            plStack_78 = plVar4 + uVar9;

            local_70 = plVar4 + uVar13;

            local_80 = plVar4;

          }

          else {

            *plStack_78 = lVar6;

            plStack_78 = plStack_78 + 1;

          }

        }

        else if ((*(int *)(lVar6 + 8) == 3) && (*(int *)(lVar6 + 0xc) - 0x17U < 3)) {

          *(undefined1 *)(lVar6 + 0x11) = 1;

          FUN_140104df0(DAT_1403fb0d8);

        }

        else {

          plVar10 = (longlong *)(DAT_1403f4e00 + 0xb8);

          plVar7 = *(longlong **)(DAT_1403f4e00 + 0xc0);

          if (plVar7 == *(longlong **)(DAT_1403f4e00 + 200)) {

            lVar12 = (longlong)plVar7 - *plVar10 >> 3;

            if (lVar12 == 0x1fffffffffffffff) goto LAB_1400ce4e2;

            uVar9 = lVar12 + 1;

            uVar5 = (longlong)*(longlong **)(DAT_1403f4e00 + 200) - *plVar10 >> 3;

            if (0x1fffffffffffffff - (uVar5 >> 1) < uVar5) {

              uVar13 = 0x1fffffffffffffff;

            }

            else {

              uVar5 = (uVar5 >> 1) + uVar5;

              uVar13 = uVar9;

              if (uVar9 <= uVar5) {

                uVar13 = uVar5;

              }

              if (0x1fffffffffffffff < uVar13) goto LAB_1400ce4dc;

            }

            lVar3 = FUN_1400285e0(uVar13 * 8);

            *(longlong *)(lVar3 + lVar12 * 8) = lVar6;

            plVar8 = (longlong *)*plVar10;

            if (plVar7 == *(longlong **)(lVar11 + 0xc0)) {

              lVar11 = (longlong)*(longlong **)(lVar11 + 0xc0) - (longlong)plVar8;

              lVar6 = lVar3;

              plVar7 = plVar8;

            }

            else {

              FUN_1402f8e20(lVar3,plVar8,(longlong)plVar7 - (longlong)plVar8);

              lVar11 = *(longlong *)(lVar11 + 0xc0) - (longlong)plVar7;

              lVar6 = lVar3 + (lVar12 + 1) * 8;

            }

            FUN_1402f8e20(lVar6,plVar7,lVar11);

            FUN_140037380(plVar10,lVar3,uVar9,uVar13);

          }

          else {

            *plVar7 = lVar6;

            *(longlong *)(lVar11 + 0xc0) = *(longlong *)(lVar11 + 0xc0) + 8;

          }

        }

        local_res10 = local_res10 + 1;

        local_res18 = local_res18 + 8;

        lVar6 = *(longlong *)(param_1 + 0xb8);

      } while ((ulonglong)(longlong)local_res10 <

               (ulonglong)(*(longlong *)(param_1 + 0xc0) - lVar6 >> 3));

    }

    FUN_1400d8ab0(param_1 + 0xb8,&local_80);

    *(undefined1 *)(param_1 + 0x234) = 0;

    if (local_80 != (longlong *)0x0) {

      if ((0xfff < ((longlong)local_70 - (longlong)local_80 & 0xfffffffffffffff8U)) &&

         (0x1f < (ulonglong)((longlong)local_80 + (-8 - local_80[-1])))) {

                    /* WARNING: Subroutine does not return */

        _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

      }

      FUN_1402c7088();

      local_80 = (longlong *)0x0;

      plStack_78 = (longlong *)0x0;

      local_70 = (longlong *)0x0;

    }

    if (local_68 != (longlong *)0x0) {

      if ((0xfff < ((longlong)local_58 - (longlong)local_68 & 0xfffffffffffffff8U)) &&

         (0x1f < (ulonglong)((longlong)local_68 + (-8 - local_68[-1])))) {

                    /* WARNING: Subroutine does not return */

        _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

      }

      FUN_1402c7088();

    }

  }

  return;

}




