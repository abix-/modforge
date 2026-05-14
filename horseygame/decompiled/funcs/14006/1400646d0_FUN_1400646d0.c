// Address: 0x1400646d0
// Ghidra name: FUN_1400646d0
// ============ 0x1400646d0 FUN_1400646d0 (size=893) ============


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void FUN_1400646d0(longlong param_1)



{

  ulonglong uVar1;

  ulonglong uVar2;

  longlong lVar3;

  ulonglong uVar4;

  undefined4 uVar5;

  undefined8 uVar6;

  longlong lVar7;

  undefined8 uVar8;

  char *pcVar9;

  size_t sVar10;

  longlong lVar11;

  longlong lVar12;

  ulonglong uVar13;

  longlong *plVar14;

  longlong lVar15;

  int iVar16;

  longlong local_res10;

  char *local_res18;

  longlong local_res20;

  undefined8 in_stack_ffffffffffffff68;

  undefined1 local_88 [8];

  undefined8 local_80;

  undefined8 uStack_78;

  undefined8 local_70;

  ulonglong uStack_68;

  

  FUN_1400d01d0(param_1,"Bubber",0,DAT_1403d6340);

  uVar6 = FUN_1400cf970(param_1,*(undefined8 *)(param_1 + 0x148));

  FUN_1400278e0(param_1 + 600,uVar6);

  uVar4 = _UNK_1403033d8;

  uVar6 = _DAT_1403033d0;

  lVar15 = 0;

  iVar16 = 4;

  do {

    while( true ) {

      uVar5 = (undefined4)((ulonglong)in_stack_ffffffffffffff68 >> 0x20);

      local_res20 = FUN_1402c704c(0x498);

      if (local_res20 == 0) {

        lVar7 = 0;

      }

      else {

        lVar7 = FUN_1400aac60(local_res20);

      }

      uStack_78 = 0;

      local_70 = uVar6;

      uStack_68 = uVar4;

      local_80 = (ulonglong)CONCAT24(s_rabbit_140303b20._4_2_,s_rabbit_140303b20._0_4_);

      local_res10 = lVar7;

      FUN_1400b2ee0(lVar7,&local_80);

      if (0xf < uStack_68) {

        if ((0xfff < uStack_68 + 1) && (0x1f < (local_80 - *(longlong *)(local_80 - 8)) - 8)) {

                    /* WARNING: Subroutine does not return */

          _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

        }

        FUN_1402c7088();

      }

      uVar8 = FUN_1400c57a0(local_88,*(longlong *)(param_1 + 0x78) + 0x30,0);

      FUN_1400b6610(lVar7,uVar8);

      in_stack_ffffffffffffff68 = CONCAT44(uVar5,0xffffffff);

      uVar5 = FUN_1400c7600(1,iVar16,0xffffffff,0xffffffff,in_stack_ffffffffffffff68);

      *(undefined4 *)(lVar7 + 0x1f8) = uVar5;

      plVar14 = *(longlong **)(param_1 + 0x138);

      if (plVar14 == *(longlong **)(param_1 + 0x140)) {

        FUN_140030680(param_1 + 0x130,plVar14,&local_res10);

      }

      else {

        *plVar14 = lVar7;

        *(longlong *)(param_1 + 0x138) = *(longlong *)(param_1 + 0x138) + 8;

      }

      pcVar9 = (char *)FUN_1400cf970(param_1,lVar7);

      lVar12 = lVar15 * 0x20;

      plVar14 = (longlong *)(param_1 + 0x278 + lVar12);

      local_res10 = lVar12;

      local_res18 = pcVar9;

      sVar10 = strlen(pcVar9);

      uVar2 = plVar14[3];

      if (uVar2 < sVar10) {

        if (0x7fffffffffffffff < sVar10) {

                    /* WARNING: Subroutine does not return */

          FUN_140024130();

        }

        uVar13 = sVar10 | 0xf;

        if (uVar13 < 0x8000000000000000) {

          if (0x7fffffffffffffff - (uVar2 >> 1) < uVar2) {

            uVar13 = 0x7fffffffffffffff;

          }

          else {

            uVar1 = (uVar2 >> 1) + uVar2;

            if (uVar13 < uVar1) {

              uVar13 = uVar1;

            }

          }

        }

        else {

          uVar13 = 0x7fffffffffffffff;

        }

        lVar12 = FUN_1400285e0(uVar13 + 1);

        *(size_t *)(local_res10 + 0x288 + param_1) = sVar10;

        plVar14[3] = uVar13;

        FUN_1402f8e20(lVar12,local_res18);

        *(undefined1 *)(lVar12 + sVar10) = 0;

        if (0xf < uVar2) {

          lVar3 = *plVar14;

          lVar11 = lVar3;

          if ((0xfff < uVar2 + 1) &&

             (lVar11 = *(longlong *)(lVar3 + -8), 0x1f < (lVar3 - lVar11) - 8U)) {

                    /* WARNING: Subroutine does not return */

            _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

          }

          FUN_1402c7088(lVar11);

        }

        *plVar14 = lVar12;

      }

      else {

        if (0xf < uVar2) {

          plVar14 = (longlong *)*plVar14;

        }

        *(size_t *)(lVar12 + 0x288 + param_1) = sVar10;

        FUN_1402f8e20(plVar14,pcVar9,sVar10);

        *(undefined1 *)((longlong)plVar14 + sVar10) = 0;

      }

      pcVar9 = (char *)FUN_1400cf9a0(param_1,lVar7);

      sVar10 = strlen(pcVar9);

      FUN_140027810(param_1 + 0x2d8,pcVar9,sVar10);

      if (lVar15 != 0) break;

      uVar8 = 2;

      pcVar9 = ", ";

LAB_1400649bf:

      FUN_140027810(param_1 + 0x2d8,pcVar9,uVar8);

      iVar16 = iVar16 + 1;

      lVar15 = lVar15 + 1;

    }

    if (lVar15 == 1) {

      uVar8 = 5;

      pcVar9 = ", or ";

      goto LAB_1400649bf;

    }

    iVar16 = iVar16 + 1;

    lVar15 = lVar15 + 1;

    if (2 < lVar15) {

      *(undefined1 *)(param_1 + 0x325) = 0;

      return;

    }

  } while( true );

}




