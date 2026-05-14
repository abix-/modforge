// Address: 0x1400ff790
// Ghidra name: FUN_1400ff790
// ============ 0x1400ff790 FUN_1400ff790 (size=886) ============


void FUN_1400ff790(longlong param_1)



{

  longlong lVar1;

  ulonglong uVar2;

  float fVar3;

  undefined4 uVar4;

  int iVar5;

  undefined8 uVar6;

  int iVar7;

  longlong lVar8;

  int *piVar9;

  ulonglong uVar10;

  int iVar11;

  longlong lVar12;

  longlong *plVar13;

  longlong local_78;

  longlong lStack_70;

  ulonglong local_68;

  ulonglong uStack_60;

  undefined1 local_58 [48];

  

  fVar3 = DAT_140303fb4;

  iVar11 = 0;

  lVar8 = *(longlong *)(param_1 + 0xb8);

  if (*(longlong *)(param_1 + 0xc0) - lVar8 >> 3 != 0) {

    lVar12 = 0;

    do {

      lVar8 = *(longlong *)(lVar8 + lVar12);

      if (*(int *)(lVar8 + 8) == 2) {

        if ((*(int *)(*(longlong *)((longlong)ThreadLocalStoragePointer + (ulonglong)_tls_index * 8)

                     + 4) < DAT_1403fb164) && (FUN_1402c7138(&DAT_1403fb164), DAT_1403fb164 == -1))

        {

          lStack_70 = 0;

          local_68 = 4;

          uStack_60 = 0xf;

          local_78 = 0x73636f6c;

          iVar5 = FUN_14006fe60(&local_78);

          DAT_1403fb160 = iVar5 + 1;

          _Init_thread_footer(&DAT_1403fb164);

        }

        *(int *)(lVar8 + 0x3c) = DAT_1403fb160 + *(int *)(lVar8 + 0xc);

        lVar1 = *(longlong *)(*(longlong *)(param_1 + 0x438) + (longlong)*(int *)(lVar8 + 0xc) * 8);

        if (lVar1 != 0) {

          local_78 = 0;

          lStack_70 = 0;

          local_68 = 0;

          uStack_60 = 0;

          plVar13 = (longlong *)(lVar1 + 0x38);

          if (0xf < *(ulonglong *)(lVar1 + 0x50)) {

            plVar13 = *(longlong **)(lVar1 + 0x38);

          }

          uVar2 = *(ulonglong *)(lVar1 + 0x48);

          if (0x7fffffffffffffff < uVar2) {

                    /* WARNING: Subroutine does not return */

            FUN_140024130();

          }

          if (uVar2 < 0x10) {

            uStack_60 = 0xf;

            local_78 = *plVar13;

            lStack_70 = plVar13[1];

            local_68 = uVar2;

          }

          else {

            uVar10 = uVar2 | 0xf;

            if (uVar10 < 0x8000000000000000) {

              if (uVar10 < 0x16) {

                uVar10 = 0x16;

              }

            }

            else {

              uVar10 = 0x7fffffffffffffff;

            }

            local_78 = FUN_1400285e0(uVar10 + 1);

            local_68 = uVar2;

            uStack_60 = uVar10;

            FUN_1402f8e20(local_78,plVar13,uVar2 + 1);

          }

          uVar6 = FUN_14008d760(local_58,"Loc%s2");

          uVar4 = FUN_14006ffa0(uVar6);

          *(undefined4 *)(lVar8 + 0x40) = uVar4;

          if (0xf < uStack_60) {

            if ((0xfff < uStack_60 + 1) && (0x1f < (local_78 - *(longlong *)(local_78 + -8)) - 8U))

            {

                    /* WARNING: Subroutine does not return */

              _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

            }

            FUN_1402c7088();

          }

        }

      }

      else if (*(int *)(lVar8 + 8) == 4) {

        if ((*(int *)(*(longlong *)((longlong)ThreadLocalStoragePointer + (ulonglong)_tls_index * 8)

                     + 4) < DAT_1403fb16c) && (FUN_1402c7138(&DAT_1403fb16c), DAT_1403fb16c == -1))

        {

          lStack_70 = 0;

          local_68 = 4;

          uStack_60 = 0xf;

          local_78 = 0x656c6f48;

          DAT_1403fb168 = FUN_14006fe60(&local_78);

          _Init_thread_footer(&DAT_1403fb16c);

        }

        *(int *)(lVar8 + 0x3c) = DAT_1403fb168;

        iVar5 = (int)(*(float *)(lVar8 + 0x2c) * fVar3);

        iVar7 = (int)(*(float *)(lVar8 + 0x28) * fVar3);

        if ((((iVar7 < 0) || (*(int *)(param_1 + 0x278) <= iVar7)) || (iVar5 < 0)) ||

           (*(int *)(param_1 + 0x27c) <= iVar5)) {

          piVar9 = &DAT_1403dc390;

        }

        else {

          piVar9 = (int *)(*(longlong *)(param_1 + 0x270) +

                          (longlong)(*(int *)(param_1 + 0x278) * iVar5 + iVar7) * 0x28);

        }

        if (*piVar9 == 4) {

          *(int *)(lVar8 + 0x3c) = DAT_1403fb168 + 1;

        }

      }

      iVar11 = iVar11 + 1;

      lVar12 = lVar12 + 8;

      lVar8 = *(longlong *)(param_1 + 0xb8);

    } while ((ulonglong)(longlong)iVar11 < (ulonglong)(*(longlong *)(param_1 + 0xc0) - lVar8 >> 3));

  }

  return;

}




